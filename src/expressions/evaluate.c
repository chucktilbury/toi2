#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#include "scanner.h"
#include "errors.h"
#include "ast_tree.h"
#include "expressions.h"

/*
 * This exists to allow the parser to store an expression in such a way as to
 * allow it to be evaluated multiple times without re-parsing it, such as the
 * case would be if a function were called multiple times.
 *
 * The parser already organizes the order of values for us. Instead of having
 * to use a different algorithm to convert the order of evaluation to something
 * like RPN, we can simply store items in the order we find them, i.e. in a
 * FIFO queue. As we evaluate the expression, we also use a stack (LIFO) to
 * keep track. See the data structures in expressions.h.
 *
 * while there are items in the FIFO get an item from the FIFO if it's not an
 * operator, then push it on to the LIFO. else if it's a unary operator, pop
 * one from the LIFO apply the operator push the result back on the LIFO else
 * if it's an operator and not unary pop two from the LIFO apply the operator
 * push the result back on the LIFO The value on top of the LIFO is the result
 * of the expression.
 *
 * These functions also evaluate the symantics of the expression. For example,
 * trying to use a float to calculate a bool or mixing signed and unsigned
 * types in an expression.
 *
 * The individual operations take on the type of the left operand. Most
 * demotions produce warnings, most promotions do not. Whether the actual value
 * fits into the actual size that has been specified, such as in an assignment,
 * is left to other code to determine. This code is concerned to evaluating
 * an expression that has already been parsed.
 */

static void perform_arith_add(expression_t *expr);
static void perform_arith_sub(expression_t *expr);
static void perform_arith_mul(expression_t *expr);
static void perform_arith_div(expression_t *expr);
static void perform_arith_mod(expression_t *expr);
static void perform_unary_minus(expression_t *expr);
static void perform_unary_neg(expression_t *expr);
static void perform_unary_not(expression_t *expr);
static void perform_bool_and(expression_t *expr);
static void perform_bool_or(expression_t *expr);
static void perform_bool_eq(expression_t *expr);
static void perform_bool_nqe(expression_t *expr);
static void perform_bool_le(expression_t *expr);
static void perform_bool_ge(expression_t *expr);
static void perform_bool_lt(expression_t *expr);
static void perform_bool_gt(expression_t *expr);
static void perform_bitwise_and(expression_t *expr);
static void perform_bitwise_or(expression_t *expr);
static void perform_bitwise_xor(expression_t *expr);
static void perform_bitwise_shl(expression_t *expr);
static void perform_bitwise_shr(expression_t *expr);
static void perform_bitwise_rol(expression_t *expr);
static void perform_bitwise_ror(expression_t *expr);
static void push_inter_value(expression_t *expr, val_fifo_element_t * val);

/*
 * Returns a pointer to the value of the expression. The type parameter
 * indicates the type that the return value points to.
 */
void *evaluate_expression(expression_t *expr, expr_val_type_t * type) {
    MARK();
    val_fifo_element_t *value;
    int finished = 0;

    reset_value_fifo(expr);

    while(!finished) {
        value = get_value(expr);
        if(value->vtype == EXPR_VAL_OPERATOR) {
            // apply the operation to the out stack
            expr_ops_t oper = value->value.oper;

            switch (oper) {
                    // Arithmetic operations
                case EXPR_OP_ADD:
                    perform_arith_add(expr);
                    break;
                case EXPR_OP_SUB:
                    perform_arith_sub(expr);
                    break;
                case EXPR_OP_MUL:
                    perform_arith_mul(expr);
                    break;
                case EXPR_OP_DIV:
                    perform_arith_div(expr);
                    break;
                case EXPR_OP_MOD:
                    perform_arith_mod(expr);
                    break;

                    // Unary operations
                case EXPR_OP_UNARY_MINUS:
                    perform_unary_minus(expr);
                    break;
                case EXPR_OP_BIT_UNARY_NEG:
                    perform_unary_neg(expr);
                    break;
                case EXPR_OP_BOOL_UNARY_NOT:
                    perform_unary_not(expr);
                    break;

                    // Boolean operations
                case EXPR_OP_BOOL_AND:
                    perform_bool_and(expr);
                    break;
                case EXPR_OP_BOOL_OR:
                    perform_bool_or(expr);
                    break;
                case EXPR_OP_BOOL_EQ:
                    perform_bool_eq(expr);
                    break;
                case EXPR_OP_BOOL_NEQ:
                    perform_bool_nqe(expr);
                    break;
                case EXPR_OP_BOOL_LE:
                    perform_bool_le(expr);
                    break;
                case EXPR_OP_BOOL_GE:
                    perform_bool_ge(expr);
                    break;
                case EXPR_OP_BOOL_LT:
                    perform_bool_lt(expr);
                    break;
                case EXPR_OP_BOOL_GT:
                    perform_bool_gt(expr);
                    break;

                    // Bitwise operations
                case EXPR_OP_BIT_AND:
                    perform_bitwise_and(expr);
                    break;
                case EXPR_OP_BIT_OR:
                    perform_bitwise_or(expr);
                    break;
                case EXPR_OP_BIT_XOR:
                    perform_bitwise_xor(expr);
                    break;
                case EXPR_OP_BIT_SHL:
                    perform_bitwise_shl(expr);
                    break;
                case EXPR_OP_BIT_SHR:
                    perform_bitwise_shr(expr);
                    break;
                case EXPR_OP_BIT_ROL:
                    perform_bitwise_rol(expr);
                    break;
                case EXPR_OP_BIT_ROR:
                    perform_bitwise_ror(expr);
                    break;

                default:
                    fatal_error("Unknown operator type in evaluate_expression().");
            }
        }
        else if(value->vtype == EXPR_VAL_REFERENCE) {
            // find the value of the reference and push it on the out stack
            syntax("References are not supported (yet)");
        }
        else {
            // push the value on the out stack
            push_inter_value(expr, (void *)&value->value);
        }
    }
    return get_value(expr);
}

static void perform_arith_add(expression_t *expr) {
    MARK();
    out_lifo_t *right = pop_inter(expr);
    out_lifo_t *left = pop_inter(expr);

    switch (left->vtype) {
        case EXPR_VAL_UNUM:
            {
                uint64_t le = left->value.unum;
                uint64_t result;

                switch (right->vtype) {
                    case EXPR_VAL_UNUM:
                        result = le + right->value.unum;
                        break;
                    case EXPR_VAL_INUM:
                        // integer becomes unsigned
                        warning("converting integer to unsigned value");
                        result = le + (uint64_t) right->value.inum;
                        break;
                    case EXPR_VAL_FNUM:
                        // float is truncated to unsigned
                        warning("truncate a float to unsigned value");
                        result = le + (uint64_t) right->value.fnum;
                        break;
                    case EXPR_VAL_BOOL:
                        warning("using boolean result in arithmetic operation");
                        result = le + (uint64_t) right->value.bnum;
                        break;
                    default:
                        fatal_error("Unknown vtype right in perform_arithmetic().");
                }
                push_inter(expr, EXPR_VAL_UNUM, (void *)&result);
            }
            break;

        case EXPR_VAL_INUM:
            {
                int64_t le = left->value.inum;
                int64_t result;

                switch (right->vtype) {
                    case EXPR_VAL_UNUM:
                        // unsigned is sign extended to integer
                        warning("converting unsigned value to sign extended integer");
                        result = le + (int64_t) right->value.unum;
                        break;
                    case EXPR_VAL_INUM:
                        result = le + right->value.inum;
                        break;
                    case EXPR_VAL_FNUM:
                        // float is truncated to integer
                        warning("truncate a float to unsigned value");
                        result = le + (int64_t) right->value.fnum;
                        break;
                    case EXPR_VAL_BOOL:
                        warning("using boolean result in arithmetic operation");
                        result = le + (int64_t) right->value.bnum;
                        break;
                    default:
                        fatal_error("Unknown vtype right in perform_arithmetic().");
                }
                push_inter(expr, EXPR_VAL_INUM, (void *)&result);
            }
            break;

        case EXPR_VAL_FNUM:
            {
                double le = left->value.fnum;
                double result;

                // right side is simply case to double
                switch (right->vtype) {
                    case EXPR_VAL_UNUM:
                        result = le + (double)right->value.unum;
                        break;
                    case EXPR_VAL_INUM:
                        result = le + (double)right->value.inum;
                        break;
                    case EXPR_VAL_FNUM:
                        result = le + right->value.fnum;
                        break;
                    case EXPR_VAL_BOOL:
                        warning("using boolean result in arithmetic operation");
                        result = le + (double)right->value.bnum;
                        break;
                    default:
                        fatal_error("Unknown vtype right in perform_arithmetic().");
                }
                push_inter(expr, EXPR_VAL_FNUM, (void *)&result);
            }
            break;

        case EXPR_VAL_BOOL:
            fatal_error("addition on boolean result is invalid");
            break;

        default:
            fatal_error("Unknown vtype left in perform_arithmetic().");
    }

    free(right);
    free(left);
}

static void perform_arith_sub(expression_t *expr) {
    MARK();
    out_lifo_t *right = pop_inter(expr);
    out_lifo_t *left = pop_inter(expr);

    switch (left->vtype) {
        case EXPR_VAL_UNUM:
            {
                uint64_t le = left->value.unum;
                uint64_t result;

                switch (right->vtype) {
                    case EXPR_VAL_UNUM:
                        result = le - right->value.unum;
                        break;
                    case EXPR_VAL_INUM:
                        // integer becomes unsigned
                        warning("converting integer to unsigned value");
                        result = le - (uint64_t) right->value.inum;
                        break;
                    case EXPR_VAL_FNUM:
                        // float is truncated to unsigned
                        warning("truncate a float to unsigned value");
                        result = le - (uint64_t) right->value.fnum;
                        break;
                    case EXPR_VAL_BOOL:
                        warning("using boolean result in arithmetic operation");
                        result = le - (uint64_t) right->value.bnum;
                        break;
                    default:
                        fatal_error("Unknown vtype right in perform_arithmetic().");
                }
                push_inter(expr, EXPR_VAL_UNUM, (void *)&result);
            }
            break;

        case EXPR_VAL_INUM:
            {
                int64_t le = left->value.inum;
                int64_t result;

                switch (right->vtype) {
                    case EXPR_VAL_UNUM:
                        // unsigned is sign extended to integer
                        warning("converting unsigned value to sign extended integer");
                        result = le - (int64_t) right->value.unum;
                        break;
                    case EXPR_VAL_INUM:
                        result = le - right->value.inum;
                        break;
                    case EXPR_VAL_FNUM:
                        // float is truncated to integer
                        warning("truncate a float to unsigned value");
                        result = le - (int64_t) right->value.fnum;
                        break;
                    case EXPR_VAL_BOOL:
                        warning("using boolean result in arithmetic operation");
                        result = le - (int64_t) right->value.bnum;
                        break;
                    default:
                        fatal_error("Unknown vtype right in perform_arithmetic().");
                }
                push_inter(expr, EXPR_VAL_INUM, (void *)&result);
            }
            break;

        case EXPR_VAL_FNUM:
            {
                double le = left->value.fnum;
                double result;

                // right side is simply case to double
                switch (right->vtype) {
                    case EXPR_VAL_UNUM:
                        result = le - (double)right->value.unum;
                        break;
                    case EXPR_VAL_INUM:
                        result = le - (double)right->value.inum;
                        break;
                    case EXPR_VAL_FNUM:
                        result = le - right->value.fnum;
                        break;
                    case EXPR_VAL_BOOL:
                        warning("using boolean result in arithmetic operation");
                        result = le - (double)right->value.bnum;
                        break;
                    default:
                        fatal_error("Unknown vtype right in perform_arithmetic().");
                }
                push_inter(expr, EXPR_VAL_FNUM, (void *)&result);
            }
            break;

        case EXPR_VAL_BOOL:
            fatal_error("subtraction on boolean result is invalid");
            break;

        default:
            fatal_error("Unknown vtype left in perform_arithmetic().");
    }

    free(right);
    free(left);
}

static void perform_arith_mul(expression_t *expr) {
    MARK();
    out_lifo_t *right = pop_inter(expr);
    out_lifo_t *left = pop_inter(expr);

    switch (left->vtype) {
        case EXPR_VAL_UNUM:
            {
                uint64_t le = left->value.unum;
                uint64_t result;

                switch (right->vtype) {
                    case EXPR_VAL_UNUM:
                        result = le * right->value.unum;
                        break;
                    case EXPR_VAL_INUM:
                        // integer becomes unsigned
                        warning("converting integer to unsigned value");
                        result = le * (uint64_t) right->value.inum;
                        break;
                    case EXPR_VAL_FNUM:
                        // float is truncated to unsigned
                        warning("truncate a float to unsigned value");
                        result = le * (uint64_t) right->value.fnum;
                        break;
                    case EXPR_VAL_BOOL:
                        warning("using boolean result in arithmetic operation");
                        result = le * (uint64_t) right->value.bnum;
                        break;
                    default:
                        fatal_error("Unknown vtype right in perform_arithmetic().");
                }
                push_inter(expr, EXPR_VAL_UNUM, (void *)&result);
            }
            break;

        case EXPR_VAL_INUM:
            {
                int64_t le = left->value.inum;
                int64_t result;

                switch (right->vtype) {
                    case EXPR_VAL_UNUM:
                        // unsigned is sign extended to integer
                        warning("converting unsigned value to sign extended integer");
                        result = le * (int64_t) right->value.unum;
                        break;
                    case EXPR_VAL_INUM:
                        result = le * right->value.inum;
                        break;
                    case EXPR_VAL_FNUM:
                        // float is truncated to integer
                        warning("truncate a float to unsigned value");
                        result = le * (int64_t) right->value.fnum;
                        break;
                    case EXPR_VAL_BOOL:
                        warning("using boolean result in arithmetic operation");
                        result = le * (int64_t) right->value.bnum;
                        break;
                    default:
                        fatal_error("Unknown vtype right in perform_arithmetic().");
                }
                push_inter(expr, EXPR_VAL_INUM, (void *)&result);
            }
            break;

        case EXPR_VAL_FNUM:
            {
                double le = left->value.fnum;
                double result;

                // right side is simply case to double
                switch (right->vtype) {
                    case EXPR_VAL_UNUM:
                        result = le * (double)right->value.unum;
                        break;
                    case EXPR_VAL_INUM:
                        result = le * (double)right->value.inum;
                        break;
                    case EXPR_VAL_FNUM:
                        result = le * right->value.fnum;
                        break;
                    case EXPR_VAL_BOOL:
                        warning("using boolean result in arithmetic operation");
                        result = le * (double)right->value.bnum;
                        break;
                    default:
                        fatal_error("Unknown vtype right in perform_arithmetic().");
                }
                push_inter(expr, EXPR_VAL_FNUM, (void *)&result);
            }
            break;

        case EXPR_VAL_BOOL:
            fatal_error("multiplication on boolean result is invalid");
            break;

        default:
            fatal_error("Unknown vtype left in perform_arithmetic().");
    }

    free(right);
    free(left);
}

static void perform_arith_div(expression_t *expr) {
    MARK();
    out_lifo_t *right = pop_inter(expr);
    out_lifo_t *left = pop_inter(expr);

    // check for divide by zero
    switch (right->vtype) {
        case EXPR_VAL_UNUM:
            if(right->value.unum == 0)
                fatal_error("Attempt to divide by zero detected.");
            break;
        case EXPR_VAL_INUM:
            if(right->value.inum == 0)
                fatal_error("Attempt to divide by zero detected.");
            break;
        case EXPR_VAL_FNUM:
            if(right->value.fnum == 0.0)
                fatal_error("Attempt to divide by zero detected.");
            break;
        case EXPR_VAL_BOOL:
            fatal_error("using boolean result in division operation is illegal");
            break;
        default:
            fatal_error("Unknown vtype right in perform_arithmetic().");
    }

    switch (left->vtype) {
        case EXPR_VAL_UNUM:
            {
                uint64_t le = left->value.unum;
                uint64_t result;

                switch (right->vtype) {
                    case EXPR_VAL_UNUM:
                        result = le / right->value.unum;
                        break;
                    case EXPR_VAL_INUM:
                        // integer becomes unsigned
                        warning("converting integer to unsigned value");
                        result = le / (uint64_t) right->value.inum;
                        break;
                    case EXPR_VAL_FNUM:
                        // float is truncated to unsigned
                        warning("truncate a float to unsigned value");
                        result = le / (uint64_t) right->value.fnum;
                        break;
                    default:
                        fatal_error("Unknown vtype right in perform_arithmetic().");
                }
                push_inter(expr, EXPR_VAL_UNUM, (void *)&result);
            }
            break;

        case EXPR_VAL_INUM:
            {
                int64_t le = left->value.inum;
                int64_t result;

                switch (right->vtype) {
                    case EXPR_VAL_UNUM:
                        // unsigned is sign extended to integer
                        warning("converting unsigned value to sign extended integer");
                        result = le / (int64_t) right->value.unum;
                        break;
                    case EXPR_VAL_INUM:
                        result = le / right->value.inum;
                        break;
                    case EXPR_VAL_FNUM:
                        // float is truncated to integer
                        warning("truncate a float to unsigned value");
                        result = le / (int64_t) right->value.fnum;
                        break;
                    default:
                        fatal_error("Unknown vtype right in perform_arithmetic().");
                }
                push_inter(expr, EXPR_VAL_INUM, (void *)&result);
            }
            break;

        case EXPR_VAL_FNUM:
            {
                double le = left->value.fnum;
                double result;

                // right side is simply case to double
                switch (right->vtype) {
                    case EXPR_VAL_UNUM:
                        result = le / (double)right->value.unum;
                        break;
                    case EXPR_VAL_INUM:
                        result = le / (double)right->value.inum;
                        break;
                    case EXPR_VAL_FNUM:
                        result = le / right->value.fnum;
                        break;
                    default:
                        fatal_error("Unknown vtype right in perform_arithmetic().");
                }
                push_inter(expr, EXPR_VAL_FNUM, (void *)&result);
            }
            break;

        case EXPR_VAL_BOOL:
            fatal_error("using boolean result in division operation is illegal");
            break;

        default:
            fatal_error("Unknown vtype left in perform_arithmetic().");
    }

    free(right);
    free(left);
}

static void perform_arith_mod(expression_t *expr) {
    MARK();
    out_lifo_t *right = pop_inter(expr);
    out_lifo_t *left = pop_inter(expr);

    // check for divide by zero
    switch (right->vtype) {
        case EXPR_VAL_UNUM:
            if(right->value.unum == 0)
                fatal_error("Attempt to modulo divide by zero detected.");
            break;
        case EXPR_VAL_INUM:
            if(right->value.inum == 0)
                fatal_error("Attempt to modulo divide by zero detected.");
            break;
        case EXPR_VAL_FNUM:
            fatal_error("Modulo operatons only allowed on integer and unsigned.");
            break;
        case EXPR_VAL_BOOL:
            fatal_error("modulo operations not allowed on a boolean result");
            break;
        default:
            fatal_error("Unknown vtype right in perform_arithmetic().");
    }

    switch (left->vtype) {
        case EXPR_VAL_UNUM:
            {
                uint64_t le = left->value.unum;
                uint64_t result;

                switch (right->vtype) {
                    case EXPR_VAL_UNUM:
                        result = le % right->value.unum;
                        break;
                    case EXPR_VAL_INUM:
                        // integer becomes unsigned
                        warning("converting integer to unsigned value");
                        result = le % (uint64_t) right->value.inum;
                        break;
                    default:
                        fatal_error("Unknown vtype right in perform_arithmetic().");
                }
                push_inter(expr, EXPR_VAL_UNUM, (void *)&result);
            }
            break;

        case EXPR_VAL_INUM:
            {
                int64_t le = left->value.inum;
                int64_t result;

                switch (right->vtype) {
                    case EXPR_VAL_UNUM:
                        // unsigned is sign extended to integer
                        warning("converting unsigned value to sign extended integer");
                        result = le / (int64_t) right->value.unum;
                        break;
                    case EXPR_VAL_INUM:
                        result = le / right->value.inum;
                        break;
                    default:
                        fatal_error("Unknown vtype right in perform_arithmetic().");
                }
                push_inter(expr, EXPR_VAL_INUM, (void *)&result);
            }
            break;

        case EXPR_VAL_FNUM:
            fatal_error("Modulo operatons only allowed on integer and unsigned.");
            break;

        case EXPR_VAL_BOOL:
            fatal_error("Modulo operatons not allowed on boolean result.");
            break;

        default:
            fatal_error("Unknown vtype left in perform_arithmetic().");
    }

    free(right);
    free(left);
}

static void perform_unary_minus(expression_t *expr) {
    MARK();
    out_lifo_t *value = pop_inter(expr);

    switch (value->vtype) {
        case EXPR_VAL_UNUM:
            {
                int64_t result;

                warning("converting unsigned integer to unsigned value and sign extending");
                result = -(int64_t) value->value.unum;
                push_inter(expr, EXPR_VAL_INUM, (void *)&result);
            }
            break;
        case EXPR_VAL_INUM:
            {
                int64_t result;

                result = -value->value.inum;
                push_inter(expr, EXPR_VAL_UNUM, (void *)&result);
            }
            break;
        case EXPR_VAL_FNUM:
            {
                double result;

                result = -value->value.fnum;
                push_inter(expr, EXPR_VAL_FNUM, (void *)&result);
                break;
            }
        case EXPR_VAL_BOOL:
            fatal_error("unary negate not allowed on a boolean result");
            break;

        default:
            fatal_error("Unknown vtype value in perform_arithmetic().");
    }

    free(value);
}

static void perform_unary_neg(expression_t *expr) {
    MARK();
    out_lifo_t *value = pop_inter(expr);
    uint64_t result;

    switch (value->vtype) {
        case EXPR_VAL_UNUM:
            result = ~value->value.unum;
            break;
        case EXPR_VAL_INUM:
            // integer becomes unsigned
            warning("converting integer to unsigned value");
            result = ~(uint64_t) value->value.inum;
            break;
        case EXPR_VAL_FNUM:
            // float is truncated to unsigned
            fatal_error("unary bitwise negation not allowed for float");
            break;
        case EXPR_VAL_BOOL:
            fatal_error("binary operations not allowed on a boolean result");
            break;
        default:
            fatal_error("Unknown vtype value in perform_arithmetic().");
    }
    push_inter(expr, EXPR_VAL_UNUM, (void *)&result);
    free(value);
}

static void perform_unary_not(expression_t *expr) {
    MARK();
    out_lifo_t *value = pop_inter(expr);
    unsigned char result;

    switch (value->vtype) {
        case EXPR_VAL_UNUM:
            warning("unary boolean \"not\" performed on unsigned integer");
            result = (!(value->value.unum == 0));
            break;
        case EXPR_VAL_INUM:
            warning("unary boolean \"not\" performed on unsigned integer");
            result = (!(value->value.inum == 0));
            break;
        case EXPR_VAL_FNUM:
            warning("unary boolean \"not\" performed on float");
            result = (!(value->value.fnum == 0.0));
            break;
        case EXPR_VAL_BOOL:
            result = (!(value->value.bnum == 0));
            break;
        default:
            fatal_error("Unknown vtype value in perform_arithmetic().");
    }
    push_inter(expr, EXPR_VAL_BOOL, (void *)&result);
    free(value);
}

static void perform_bool_and(expression_t *expr) {
    MARK();
    out_lifo_t *right = pop_inter(expr);
    out_lifo_t *left = pop_inter(expr);
    unsigned char result;

    switch (left->vtype) {
        case EXPR_VAL_INUM:
            {
                int64_t le = left->value.inum;

                switch (right->vtype) {
                    case EXPR_VAL_UNUM:
                        result = ((le != 0) && (right->value.unum != 0));
                        break;
                    case EXPR_VAL_INUM:
                        result = ((le != 0) && (right->value.inum != 0));
                        break;
                    case EXPR_VAL_FNUM:
                        warning("integer \"and\" comparison to float");
                        result = ((le != 0) && (right->value.fnum != 0.0));
                        break;
                    case EXPR_VAL_BOOL:
                        result = ((le != 0) && (right->value.bnum != 0));
                        break;
                    default:
                        fatal_error("Unknown vtype right in perform_arithmetic().");
                }
            }
            break;

        case EXPR_VAL_UNUM:
            {
                uint64_t le = left->value.unum;

                switch (right->vtype) {
                    case EXPR_VAL_UNUM:
                        result = ((le != 0) && (right->value.unum != 0));
                        break;
                    case EXPR_VAL_INUM:
                        result = ((le != 0) && (right->value.inum != 0));
                        break;
                    case EXPR_VAL_FNUM:
                        warning("unsigned integer \"and\" comparison to float");
                        result = ((le != 0) && (right->value.fnum != 0.0));
                        break;
                    case EXPR_VAL_BOOL:
                        result = ((le != 0) && (right->value.bnum != 0));
                        break;
                    default:
                        fatal_error("Unknown vtype right in perform_arithmetic().");
                }
            }
            break;

        case EXPR_VAL_FNUM:
            {
                double le = left->value.fnum;

                // right side is simply case to double
                switch (right->vtype) {
                    case EXPR_VAL_UNUM:
                        warning("unsigned integer \"and\" comparison to float");
                        result = ((le != 0) && (right->value.unum != 0));
                        break;
                    case EXPR_VAL_INUM:
                        warning("integer \"and\" comparison to float");
                        result = ((le != 0) && (right->value.inum != 0));
                        break;
                    case EXPR_VAL_FNUM:
                        warning("float \"and\" comparison to float");
                        result = ((le != 0) && (right->value.fnum != 0));
                        break;
                    case EXPR_VAL_BOOL:
                        warning("boolean result \"and\" comparison to float");
                        result = ((le != 0) && (right->value.bnum != 0));
                        break;
                    default:
                        fatal_error("Unknown vtype right in perform_arithmetic().");
                }
                push_inter(expr, EXPR_VAL_FNUM, (void *)&result);
            }
            break;

        case EXPR_VAL_BOOL:
            {
                unsigned char le = left->value.bnum;

                switch (right->vtype) {
                    case EXPR_VAL_UNUM:
                        result = ((le != 0) && (right->value.unum != 0));
                        break;
                    case EXPR_VAL_INUM:
                        result = ((le != 0) && (right->value.inum != 0));
                        break;
                    case EXPR_VAL_FNUM:
                        warning("boolean \"and\" comparison to float");
                        result = ((le != 0) && (right->value.fnum != 0.0));
                        break;
                    case EXPR_VAL_BOOL:
                        result = ((le != 0) && (right->value.bnum != 0));
                        break;
                    default:
                        fatal_error("Unknown vtype right in perform_arithmetic().");
                }
            }
            break;

        default:
            fatal_error("Unknown vtype left in perform_arithmetic().");
    }

    push_inter(expr, EXPR_VAL_BOOL, (void *)&result);
    free(right);
    free(left);
}

static void perform_bool_or(expression_t *expr) {
    MARK();
    out_lifo_t *right = pop_inter(expr);
    out_lifo_t *left = pop_inter(expr);
    unsigned char result;

    switch (left->vtype) {
        case EXPR_VAL_INUM:
            {
                int64_t le = left->value.inum;

                switch (right->vtype) {
                    case EXPR_VAL_UNUM:
                        result = ((le != 0) || (right->value.unum != 0));
                        break;
                    case EXPR_VAL_INUM:
                        result = ((le != 0) || (right->value.inum != 0));
                        break;
                    case EXPR_VAL_FNUM:
                        warning("integer \"or\" comparison to float");
                        result = ((le != 0) || (right->value.fnum != 0.0));
                        break;
                    case EXPR_VAL_BOOL:
                        result = ((le != 0) || (right->value.bnum != 0));
                        break;
                    default:
                        fatal_error("Unknown vtype right in perform_arithmetic().");
                }
            }

        case EXPR_VAL_UNUM:
            {
                uint64_t le = left->value.unum;

                switch (right->vtype) {
                    case EXPR_VAL_UNUM:
                        result = ((le != 0) || (right->value.unum != 0));
                        break;
                    case EXPR_VAL_INUM:
                        result = ((le != 0) || (right->value.inum != 0));
                        break;
                    case EXPR_VAL_FNUM:
                        warning("unsigned integer \"or\" comparison to float");
                        result = ((le != 0) || (right->value.fnum != 0.0));
                        break;
                    case EXPR_VAL_BOOL:
                        result = ((le != 0) || (right->value.bnum != 0));
                        break;
                    default:
                        fatal_error("Unknown vtype right in perform_arithmetic().");
                }
            }
            break;

        case EXPR_VAL_FNUM:
            {
                double le = left->value.fnum;

                // right side is simply case to double
                switch (right->vtype) {
                    case EXPR_VAL_UNUM:
                        warning("unsigned integer \"or\" comparison to float");
                        result = ((le != 0) || (right->value.unum != 0));
                        break;
                    case EXPR_VAL_INUM:
                        warning("integer \"or\" comparison to float");
                        result = ((le != 0) || (right->value.inum != 0));
                        break;
                    case EXPR_VAL_FNUM:
                        warning("float \"or\" comparison to float");
                        result = ((le != 0) || (right->value.fnum != 0));
                        break;
                    case EXPR_VAL_BOOL:
                        warning("boolean result \"or\" comparison to float");
                        result = ((le != 0) || (right->value.bnum != 0));
                        break;
                    default:
                        fatal_error("Unknown vtype right in perform_arithmetic().");
                }
                push_inter(expr, EXPR_VAL_FNUM, (void *)&result);
            }
            break;

        case EXPR_VAL_BOOL:
            {
                unsigned char le = left->value.bnum;

                switch (right->vtype) {
                    case EXPR_VAL_UNUM:
                        result = ((le != 0) || (right->value.unum != 0));
                        break;
                    case EXPR_VAL_INUM:
                        result = ((le != 0) || (right->value.inum != 0));
                        break;
                    case EXPR_VAL_FNUM:
                        warning("boolean result \"or\" comparison to float");
                        result = ((le != 0) || (right->value.fnum != 0.0));
                        break;
                    case EXPR_VAL_BOOL:
                        result = ((le != 0) || (right->value.bnum != 0));
                        break;
                    default:
                        fatal_error("Unknown vtype right in perform_arithmetic().");
                }
            }

        default:
            fatal_error("Unknown vtype left in perform_arithmetic().");
    }

    push_inter(expr, EXPR_VAL_BOOL, (void *)&result);
    free(right);
    free(left);
}

static void perform_bool_eq(expression_t *expr) {
    MARK();
    out_lifo_t *right = pop_inter(expr);
    out_lifo_t *left = pop_inter(expr);
    unsigned char result;

    switch (left->vtype) {
        case EXPR_VAL_INUM:
            {
                int64_t le = left->value.inum;

                switch (right->vtype) {
                    case EXPR_VAL_UNUM:
                        warning("comparing equality of signed and unsigned integers");
                        result = (le == right->value.unum);
                        break;
                    case EXPR_VAL_INUM:
                        result = (le == right->value.inum);
                        break;
                    case EXPR_VAL_FNUM:
                        warning("comparing equality of signed integer and float");
                        result = (le == right->value.fnum);
                        break;
                    case EXPR_VAL_BOOL:
                        warning("comparing equality of boolean result and integer");
                        result = (le == right->value.bnum);
                        break;
                    default:
                        fatal_error("Unknown vtype right in perform_arithmetic().");
                }
            }

        case EXPR_VAL_UNUM:
            {
                uint64_t le = left->value.unum;

                switch (right->vtype) {
                    case EXPR_VAL_UNUM:
                        result = (le == right->value.unum);
                        break;
                    case EXPR_VAL_INUM:
                        warning("comparing equality of signed and unsigned integers");
                        result = (le == right->value.inum);
                        break;
                    case EXPR_VAL_FNUM:
                        warning("comparing equality of unsigned integer and float");
                        result = (le == right->value.fnum);
                        break;
                    case EXPR_VAL_BOOL:
                        warning("comparing equality of boolean result and unsigned integer");
                        result = (le == right->value.bnum);
                        break;
                    default:
                        fatal_error("Unknown vtype right in perform_arithmetic().");
                }
            }
            break;

        case EXPR_VAL_FNUM:
            {
                double le = left->value.fnum;

                // right side is simply case to double
                switch (right->vtype) {
                    case EXPR_VAL_UNUM:
                        warning("comparing equality of unsigned integer and float");
                        result = (le == right->value.unum);
                        break;
                    case EXPR_VAL_INUM:
                        warning("comparing equality of signed integer and float");
                        result = (le == right->value.inum);
                        break;
                    case EXPR_VAL_FNUM:
                        warning("comparing equality of two floats");
                        result = (le == right->value.fnum);
                        break;
                    case EXPR_VAL_BOOL:
                        warning("comparing equality of boolean result and float");
                        result = (le == right->value.bnum);
                        break;
                    default:
                        fatal_error("Unknown vtype right in perform_arithmetic().");
                }
                push_inter(expr, EXPR_VAL_FNUM, (void *)&result);
            }
            break;

        case EXPR_VAL_BOOL:
            {
                unsigned char le = left->value.bnum;

                switch (right->vtype) {
                    case EXPR_VAL_UNUM:
                        warning("comparing equality of boolean result and unsigned integer");
                        result = (le == right->value.unum);
                        break;
                    case EXPR_VAL_INUM:
                        warning("comparing equality of boolean result and integer");
                        result = (le == right->value.inum);
                        break;
                    case EXPR_VAL_FNUM:
                        warning("comparing equality of boolean result and float");
                        result = (le == right->value.fnum);
                        break;
                    case EXPR_VAL_BOOL:
                        result = (le == right->value.bnum);
                        break;
                    default:
                        fatal_error("Unknown vtype right in perform_arithmetic().");
                }
            }

        default:
            fatal_error("Unknown vtype left in perform_arithmetic().");
    }

    push_inter(expr, EXPR_VAL_BOOL, (void *)&result);
    free(right);
    free(left);
}

static void perform_bool_nqe(expression_t *expr) {
    MARK();
    out_lifo_t *right = pop_inter(expr);
    out_lifo_t *left = pop_inter(expr);
    unsigned char result;

    switch (left->vtype) {
        case EXPR_VAL_INUM:
            {
                int64_t le = left->value.inum;

                switch (right->vtype) {
                    case EXPR_VAL_UNUM:
                        warning("comparing equality of signed and unsigned integers");
                        result = (le != right->value.unum);
                        break;
                    case EXPR_VAL_INUM:
                        result = (le != right->value.inum);
                        break;
                    case EXPR_VAL_FNUM:
                        warning("comparing equality of signed integer and float");
                        result = (le != right->value.fnum);
                        break;
                    case EXPR_VAL_BOOL:
                        warning("comparing equality of boolean result and integer");
                        result = (le != right->value.bnum);
                        break;
                    default:
                        fatal_error("Unknown vtype right in perform_arithmetic().");
                }
            }

        case EXPR_VAL_UNUM:
            {
                uint64_t le = left->value.unum;

                switch (right->vtype) {
                    case EXPR_VAL_UNUM:
                        result = (le != right->value.unum);
                        break;
                    case EXPR_VAL_INUM:
                        warning("comparing equality of signed and unsigned integers");
                        result = (le != right->value.inum);
                        break;
                    case EXPR_VAL_FNUM:
                        warning("comparing equality of unsigned integer and float");
                        result = (le != right->value.fnum);
                        break;
                    case EXPR_VAL_BOOL:
                        warning("comparing equality of boolean result and unsigned integer");
                        result = (le != right->value.bnum);
                        break;
                    default:
                        fatal_error("Unknown vtype right in perform_arithmetic().");
                }
            }
            break;

        case EXPR_VAL_FNUM:
            {
                double le = left->value.fnum;

                // right side is simply case to double
                switch (right->vtype) {
                    case EXPR_VAL_UNUM:
                        warning("comparing equality of unsigned integer and float");
                        result = (le != right->value.unum);
                        break;
                    case EXPR_VAL_INUM:
                        warning("comparing equality of signed integer and float");
                        result = (le != right->value.inum);
                        break;
                    case EXPR_VAL_FNUM:
                        warning("comparing equality of two floats");
                        result = (le != right->value.fnum);
                        break;
                    case EXPR_VAL_BOOL:
                        warning("comparing equality of boolean result and float");
                        result = (le != right->value.bnum);
                        break;
                    default:
                        fatal_error("Unknown vtype right in perform_arithmetic().");
                }
                push_inter(expr, EXPR_VAL_FNUM, (void *)&result);
            }
            break;

        case EXPR_VAL_BOOL:
            {
                unsigned char le = left->value.bnum;

                switch (right->vtype) {
                    case EXPR_VAL_UNUM:
                        warning("comparing equality of boolean result and unsigned integer");
                        result = (le != right->value.unum);
                        break;
                    case EXPR_VAL_INUM:
                        warning("comparing equality of boolean result and integer");
                        result = (le != right->value.inum);
                        break;
                    case EXPR_VAL_FNUM:
                        warning("comparing equality of boolean result and float");
                        result = (le != right->value.fnum);
                        break;
                    case EXPR_VAL_BOOL:
                        result = (le != right->value.bnum);
                        break;
                    default:
                        fatal_error("Unknown vtype right in perform_arithmetic().");
                }
            }

        default:
            fatal_error("Unknown vtype left in perform_arithmetic().");
    }

    push_inter(expr, EXPR_VAL_BOOL, (void *)&result);
    free(right);
    free(left);
}

static void perform_bool_le(expression_t *expr) {
    MARK();
    out_lifo_t *right = pop_inter(expr);
    out_lifo_t *left = pop_inter(expr);
    unsigned char result;

    switch (left->vtype) {
        case EXPR_VAL_INUM:
            {
                int64_t le = left->value.inum;

                switch (right->vtype) {
                    case EXPR_VAL_UNUM:
                        warning("comparing equality of signed and unsigned integers");
                        result = (le <= right->value.unum);
                        break;
                    case EXPR_VAL_INUM:
                        result = (le <= right->value.inum);
                        break;
                    case EXPR_VAL_FNUM:
                        warning("comparing equality of signed integer and float");
                        result = (le <= right->value.fnum);
                        break;
                    case EXPR_VAL_BOOL:
                        warning("comparing equality of boolean result and integer");
                        result = (le <= right->value.bnum);
                        break;
                    default:
                        fatal_error("Unknown vtype right in perform_arithmetic().");
                }
            }

        case EXPR_VAL_UNUM:
            {
                uint64_t le = left->value.unum;

                switch (right->vtype) {
                    case EXPR_VAL_UNUM:
                        result = (le <= right->value.unum);
                        break;
                    case EXPR_VAL_INUM:
                        warning("comparing equality of signed and unsigned integers");
                        result = (le <= right->value.inum);
                        break;
                    case EXPR_VAL_FNUM:
                        warning("comparing equality of unsigned integer and float");
                        result = (le <= right->value.fnum);
                        break;
                    case EXPR_VAL_BOOL:
                        warning("comparing equality of boolean result and unsigned integer");
                        result = (le <= right->value.bnum);
                        break;
                    default:
                        fatal_error("Unknown vtype right in perform_arithmetic().");
                }
            }
            break;

        case EXPR_VAL_FNUM:
            {
                double le = left->value.fnum;

                // right side is simply case to double
                switch (right->vtype) {
                    case EXPR_VAL_UNUM:
                        warning("comparing equality of unsigned integer and float");
                        result = (le <= right->value.unum);
                        break;
                    case EXPR_VAL_INUM:
                        warning("comparing equality of signed integer and float");
                        result = (le <= right->value.inum);
                        break;
                    case EXPR_VAL_FNUM:
                        warning("comparing equality of two floats");
                        result = (le <= right->value.fnum);
                        break;
                    case EXPR_VAL_BOOL:
                        warning("comparing equality of boolean result and float");
                        result = (le <= right->value.bnum);
                        break;
                    default:
                        fatal_error("Unknown vtype right in perform_arithmetic().");
                }
                push_inter(expr, EXPR_VAL_FNUM, (void *)&result);
            }
            break;

        case EXPR_VAL_BOOL:
            {
                unsigned char le = left->value.bnum;

                switch (right->vtype) {
                    case EXPR_VAL_UNUM:
                        warning("comparing equality of boolean result and unsigned integer");
                        result = (le <= right->value.unum);
                        break;
                    case EXPR_VAL_INUM:
                        warning("comparing equality of boolean result and integer");
                        result = (le <= right->value.inum);
                        break;
                    case EXPR_VAL_FNUM:
                        warning("comparing equality of boolean result and float");
                        result = (le <= right->value.fnum);
                        break;
                    case EXPR_VAL_BOOL:
                        result = (le <= right->value.bnum);
                        break;
                    default:
                        fatal_error("Unknown vtype right in perform_arithmetic().");
                }
            }

        default:
            fatal_error("Unknown vtype left in perform_arithmetic().");
    }

    push_inter(expr, EXPR_VAL_BOOL, (void *)&result);
    free(right);
    free(left);
}

static void perform_bool_ge(expression_t *expr) {
    MARK();
    out_lifo_t *right = pop_inter(expr);
    out_lifo_t *left = pop_inter(expr);
    unsigned char result;

    switch (left->vtype) {
        case EXPR_VAL_INUM:
            {
                int64_t le = left->value.inum;

                switch (right->vtype) {
                    case EXPR_VAL_UNUM:
                        warning("comparing equality of signed and unsigned integers");
                        result = (le >= right->value.unum);
                        break;
                    case EXPR_VAL_INUM:
                        result = (le >= right->value.inum);
                        break;
                    case EXPR_VAL_FNUM:
                        warning("comparing equality of signed integer and float");
                        result = (le >= right->value.fnum);
                        break;
                    case EXPR_VAL_BOOL:
                        warning("comparing equality of boolean result and integer");
                        result = (le >= right->value.bnum);
                        break;
                    default:
                        fatal_error("Unknown vtype right in perform_arithmetic().");
                }
            }

        case EXPR_VAL_UNUM:
            {
                uint64_t le = left->value.unum;

                switch (right->vtype) {
                    case EXPR_VAL_UNUM:
                        result = (le >= right->value.unum);
                        break;
                    case EXPR_VAL_INUM:
                        warning("comparing equality of signed and unsigned integers");
                        result = (le >= right->value.inum);
                        break;
                    case EXPR_VAL_FNUM:
                        warning("comparing equality of unsigned integer and float");
                        result = (le >= right->value.fnum);
                        break;
                    case EXPR_VAL_BOOL:
                        warning("comparing equality of boolean result and unsigned integer");
                        result = (le >= right->value.bnum);
                        break;
                    default:
                        fatal_error("Unknown vtype right in perform_arithmetic().");
                }
            }
            break;

        case EXPR_VAL_FNUM:
            {
                double le = left->value.fnum;

                // right side is simply case to double
                switch (right->vtype) {
                    case EXPR_VAL_UNUM:
                        warning("comparing equality of unsigned integer and float");
                        result = (le >= right->value.unum);
                        break;
                    case EXPR_VAL_INUM:
                        warning("comparing equality of signed integer and float");
                        result = (le >= right->value.inum);
                        break;
                    case EXPR_VAL_FNUM:
                        warning("comparing equality of two floats");
                        result = (le >= right->value.fnum);
                        break;
                    case EXPR_VAL_BOOL:
                        warning("comparing equality of boolean result and float");
                        result = (le >= right->value.bnum);
                        break;
                    default:
                        fatal_error("Unknown vtype right in perform_arithmetic().");
                }
                push_inter(expr, EXPR_VAL_FNUM, (void *)&result);
            }
            break;

        case EXPR_VAL_BOOL:
            {
                unsigned char le = left->value.bnum;

                switch (right->vtype) {
                    case EXPR_VAL_UNUM:
                        warning("comparing equality of boolean result and unsigned integer");
                        result = (le >= right->value.unum);
                        break;
                    case EXPR_VAL_INUM:
                        warning("comparing equality of boolean result and integer");
                        result = (le >= right->value.inum);
                        break;
                    case EXPR_VAL_FNUM:
                        warning("comparing equality of boolean result and float");
                        result = (le >= right->value.fnum);
                        break;
                    case EXPR_VAL_BOOL:
                        result = (le >= right->value.bnum);
                        break;
                    default:
                        fatal_error("Unknown vtype right in perform_arithmetic().");
                }
            }

        default:
            fatal_error("Unknown vtype left in perform_arithmetic().");
    }

    push_inter(expr, EXPR_VAL_BOOL, (void *)&result);
    free(right);
    free(left);
}

static void perform_bool_lt(expression_t *expr) {
    MARK();
    out_lifo_t *right = pop_inter(expr);
    out_lifo_t *left = pop_inter(expr);
    unsigned char result;

    switch (left->vtype) {
        case EXPR_VAL_INUM:
            {
                int64_t le = left->value.inum;

                switch (right->vtype) {
                    case EXPR_VAL_UNUM:
                        warning("comparing equality of signed and unsigned integers");
                        result = (le < right->value.unum);
                        break;
                    case EXPR_VAL_INUM:
                        result = (le < right->value.inum);
                        break;
                    case EXPR_VAL_FNUM:
                        warning("comparing equality of signed integer and float");
                        result = (le < right->value.fnum);
                        break;
                    case EXPR_VAL_BOOL:
                        warning("comparing equality of boolean result and integer");
                        result = (le < right->value.bnum);
                        break;
                    default:
                        fatal_error("Unknown vtype right in perform_arithmetic().");
                }
            }

        case EXPR_VAL_UNUM:
            {
                uint64_t le = left->value.unum;

                switch (right->vtype) {
                    case EXPR_VAL_UNUM:
                        result = (le < right->value.unum);
                        break;
                    case EXPR_VAL_INUM:
                        warning("comparing equality of signed and unsigned integers");
                        result = (le < right->value.inum);
                        break;
                    case EXPR_VAL_FNUM:
                        warning("comparing equality of unsigned integer and float");
                        result = (le < right->value.fnum);
                        break;
                    case EXPR_VAL_BOOL:
                        warning("comparing equality of boolean result and unsigned integer");
                        result = (le < right->value.bnum);
                        break;
                    default:
                        fatal_error("Unknown vtype right in perform_arithmetic().");
                }
            }
            break;

        case EXPR_VAL_FNUM:
            {
                double le = left->value.fnum;

                // right side is simply case to double
                switch (right->vtype) {
                    case EXPR_VAL_UNUM:
                        warning("comparing equality of unsigned integer and float");
                        result = (le < right->value.unum);
                        break;
                    case EXPR_VAL_INUM:
                        warning("comparing equality of signed integer and float");
                        result = (le < right->value.inum);
                        break;
                    case EXPR_VAL_FNUM:
                        warning("comparing equality of two floats");
                        result = (le < right->value.fnum);
                        break;
                    case EXPR_VAL_BOOL:
                        warning("comparing equality of boolean result and float");
                        result = (le < right->value.bnum);
                        break;
                    default:
                        fatal_error("Unknown vtype right in perform_arithmetic().");
                }
                push_inter(expr, EXPR_VAL_FNUM, (void *)&result);
            }
            break;

        case EXPR_VAL_BOOL:
            {
                unsigned char le = left->value.bnum;

                switch (right->vtype) {
                    case EXPR_VAL_UNUM:
                        warning("comparing equality of boolean result and unsigned integer");
                        result = (le < right->value.unum);
                        break;
                    case EXPR_VAL_INUM:
                        warning("comparing equality of boolean result and integer");
                        result = (le < right->value.inum);
                        break;
                    case EXPR_VAL_FNUM:
                        warning("comparing equality of boolean result and float");
                        result = (le < right->value.fnum);
                        break;
                    case EXPR_VAL_BOOL:
                        result = (le < right->value.bnum);
                        break;
                    default:
                        fatal_error("Unknown vtype right in perform_arithmetic().");
                }
            }

        default:
            fatal_error("Unknown vtype left in perform_arithmetic().");
    }

    push_inter(expr, EXPR_VAL_BOOL, (void *)&result);
    free(right);
    free(left);
}

static void perform_bool_gt(expression_t *expr) {
    MARK();
    out_lifo_t *right = pop_inter(expr);
    out_lifo_t *left = pop_inter(expr);
    unsigned char result;

    switch (left->vtype) {
        case EXPR_VAL_INUM:
            {
                int64_t le = left->value.inum;

                switch (right->vtype) {
                    case EXPR_VAL_UNUM:
                        warning("comparing equality of signed and unsigned integers");
                        result = (le > right->value.unum);
                        break;
                    case EXPR_VAL_INUM:
                        result = (le > right->value.inum);
                        break;
                    case EXPR_VAL_FNUM:
                        warning("comparing equality of signed integer and float");
                        result = (le > right->value.fnum);
                        break;
                    case EXPR_VAL_BOOL:
                        warning("comparing equality of boolean result and integer");
                        result = (le > right->value.bnum);
                        break;
                    default:
                        fatal_error("Unknown vtype right in perform_arithmetic().");
                }
            }

        case EXPR_VAL_UNUM:
            {
                uint64_t le = left->value.unum;

                switch (right->vtype) {
                    case EXPR_VAL_UNUM:
                        result = (le > right->value.unum);
                        break;
                    case EXPR_VAL_INUM:
                        warning("comparing equality of signed and unsigned integers");
                        result = (le > right->value.inum);
                        break;
                    case EXPR_VAL_FNUM:
                        warning("comparing equality of unsigned integer and float");
                        result = (le > right->value.fnum);
                        break;
                    case EXPR_VAL_BOOL:
                        warning("comparing equality of boolean result and unsigned integer");
                        result = (le > right->value.bnum);
                        break;
                    default:
                        fatal_error("Unknown vtype right in perform_arithmetic().");
                }
            }
            break;

        case EXPR_VAL_FNUM:
            {
                double le = left->value.fnum;

                // right side is simply case to double
                switch (right->vtype) {
                    case EXPR_VAL_UNUM:
                        warning("comparing equality of unsigned integer and float");
                        result = (le > right->value.unum);
                        break;
                    case EXPR_VAL_INUM:
                        warning("comparing equality of signed integer and float");
                        result = (le > right->value.inum);
                        break;
                    case EXPR_VAL_FNUM:
                        warning("comparing equality of two floats");
                        result = (le > right->value.fnum);
                        break;
                    case EXPR_VAL_BOOL:
                        warning("comparing equality of boolean result and float");
                        result = (le > right->value.bnum);
                        break;
                    default:
                        fatal_error("Unknown vtype right in perform_arithmetic().");
                }
                push_inter(expr, EXPR_VAL_FNUM, (void *)&result);
            }
            break;

        case EXPR_VAL_BOOL:
            {
                unsigned char le = left->value.bnum;

                switch (right->vtype) {
                    case EXPR_VAL_UNUM:
                        warning("comparing equality of boolean result and unsigned integer");
                        result = (le > right->value.unum);
                        break;
                    case EXPR_VAL_INUM:
                        warning("comparing equality of boolean result and integer");
                        result = (le > right->value.inum);
                        break;
                    case EXPR_VAL_FNUM:
                        warning("comparing equality of boolean result and float");
                        result = (le > right->value.fnum);
                        break;
                    case EXPR_VAL_BOOL:
                        result = (le > right->value.bnum);
                        break;
                    default:
                        fatal_error("Unknown vtype right in perform_arithmetic().");
                }
            }

        default:
            fatal_error("Unknown vtype left in perform_arithmetic().");
    }

    push_inter(expr, EXPR_VAL_BOOL, (void *)&result);
    free(right);
    free(left);
}

static void perform_bitwise_and(expression_t *expr) {
    MARK();
    out_lifo_t *right = pop_inter(expr);
    out_lifo_t *left = pop_inter(expr);
    uint64_t result;

    if(left->vtype == EXPR_VAL_FNUM || left->vtype == EXPR_VAL_BOOL)
        fatal_error("cannot perform bitwise operations of float or boolean");

    if(right->vtype == EXPR_VAL_FNUM || right->vtype == EXPR_VAL_BOOL)
        fatal_error("cannot perform bitwise operations of float or boolean");

    switch (left->vtype) {
        case EXPR_VAL_INUM:
            {
                int64_t le = left->value.inum;

                warning("bitwise operations on signed integer");
                switch (right->vtype) {
                    case EXPR_VAL_UNUM:
                        result = (le & right->value.unum);
                        break;
                    case EXPR_VAL_INUM:
                        result = (le & right->value.inum);
                        break;
                    default:
                        fatal_error("Unknown vtype right in perform_arithmetic().");
                }
            }

        case EXPR_VAL_UNUM:
            {
                uint64_t le = left->value.unum;

                switch (right->vtype) {
                    case EXPR_VAL_UNUM:
                        result = (le & right->value.unum);
                        break;
                    case EXPR_VAL_INUM:
                        warning("bitwise operations on signed integer");
                        result = (le & right->value.inum);
                        break;
                    default:
                        fatal_error("Unknown vtype right in perform_arithmetic().");
                }
            }
            break;

        default:
            fatal_error("Unknown vtype left in perform_arithmetic().");
    }

    push_inter(expr, EXPR_VAL_UNUM, (void *)&result);
    free(right);
    free(left);
}

static void perform_bitwise_or(expression_t *expr) {
    MARK();
    out_lifo_t *right = pop_inter(expr);
    out_lifo_t *left = pop_inter(expr);
    uint64_t result;

    if(left->vtype == EXPR_VAL_FNUM || left->vtype == EXPR_VAL_BOOL)
        fatal_error("cannot perform bitwise operations of float or boolean");

    if(right->vtype == EXPR_VAL_FNUM || right->vtype == EXPR_VAL_BOOL)
        fatal_error("cannot perform bitwise operations of float or boolean");

    switch (left->vtype) {
        case EXPR_VAL_INUM:
            {
                int64_t le = left->value.inum;

                warning("bitwise operations on signed integer");
                switch (right->vtype) {
                    case EXPR_VAL_UNUM:
                        result = (le | right->value.unum);
                        break;
                    case EXPR_VAL_INUM:
                        result = (le | right->value.inum);
                        break;
                    default:
                        fatal_error("Unknown vtype right in perform_arithmetic().");
                }
            }

        case EXPR_VAL_UNUM:
            {
                uint64_t le = left->value.unum;

                switch (right->vtype) {
                    case EXPR_VAL_UNUM:
                        result = (le | right->value.unum);
                        break;
                    case EXPR_VAL_INUM:
                        warning("bitwise operations on signed integer");
                        result = (le | right->value.inum);
                        break;
                    default:
                        fatal_error("Unknown vtype right in perform_arithmetic().");
                }
            }
            break;

        default:
            fatal_error("Unknown vtype left in perform_arithmetic().");
    }

    push_inter(expr, EXPR_VAL_UNUM, (void *)&result);
    free(right);
    free(left);
}

static void perform_bitwise_xor(expression_t *expr) {
    MARK();
    out_lifo_t *right = pop_inter(expr);
    out_lifo_t *left = pop_inter(expr);
    uint64_t result;

    if(left->vtype == EXPR_VAL_FNUM || left->vtype == EXPR_VAL_BOOL)
        fatal_error("cannot perform bitwise operations of float or boolean");

    if(right->vtype == EXPR_VAL_FNUM || right->vtype == EXPR_VAL_BOOL)
        fatal_error("cannot perform bitwise operations of float or boolean");

    switch (left->vtype) {
        case EXPR_VAL_INUM:
            {
                int64_t le = left->value.inum;

                warning("bitwise operations on signed integer");
                switch (right->vtype) {
                    case EXPR_VAL_UNUM:
                        result = (le ^ right->value.unum);
                        break;
                    case EXPR_VAL_INUM:
                        result = (le ^ right->value.inum);
                        break;
                    default:
                        fatal_error("Unknown vtype right in perform_arithmetic().");
                }
            }

        case EXPR_VAL_UNUM:
            {
                uint64_t le = left->value.unum;

                switch (right->vtype) {
                    case EXPR_VAL_UNUM:
                        result = (le ^ right->value.unum);
                        break;
                    case EXPR_VAL_INUM:
                        warning("bitwise operations on signed integer");
                        result = (le ^ right->value.inum);
                        break;
                    default:
                        fatal_error("Unknown vtype right in perform_arithmetic().");
                }
            }
            break;

        default:
            fatal_error("Unknown vtype left in perform_arithmetic().");
    }

    push_inter(expr, EXPR_VAL_UNUM, (void *)&result);
    free(right);
    free(left);
}

static void perform_bitwise_shl(expression_t *expr) {
    MARK();
    out_lifo_t *right = pop_inter(expr);
    out_lifo_t *left = pop_inter(expr);
    uint64_t result;

    if(left->vtype == EXPR_VAL_FNUM || left->vtype == EXPR_VAL_BOOL)
        fatal_error("cannot perform bitwise operations of float or boolean");

    if(right->vtype == EXPR_VAL_FNUM || right->vtype == EXPR_VAL_BOOL)
        fatal_error("cannot perform bitwise operations of float or boolean");

    switch (left->vtype) {
        case EXPR_VAL_INUM:
            {
                int64_t le = left->value.inum;

                warning("bitwise operations on signed integer");
                switch (right->vtype) {
                    case EXPR_VAL_UNUM:
                        result = (le << right->value.unum);
                        break;
                    case EXPR_VAL_INUM:
                        result = (le << right->value.inum);
                        break;
                    default:
                        fatal_error("Unknown vtype right in perform_arithmetic().");
                }
            }

        case EXPR_VAL_UNUM:
            {
                uint64_t le = left->value.unum;

                switch (right->vtype) {
                    case EXPR_VAL_UNUM:
                        result = (le << right->value.unum);
                        break;
                    case EXPR_VAL_INUM:
                        warning("bitwise operations on signed integer");
                        result = (le << right->value.inum);
                        break;
                    default:
                        fatal_error("Unknown vtype right in perform_arithmetic().");
                }
            }
            break;

        default:
            fatal_error("Unknown vtype left in perform_arithmetic().");
    }

    push_inter(expr, EXPR_VAL_UNUM, (void *)&result);
    free(right);
    free(left);
}

static void perform_bitwise_shr(expression_t *expr) {
    MARK();
    out_lifo_t *right = pop_inter(expr);
    out_lifo_t *left = pop_inter(expr);
    uint64_t result;

    if(left->vtype == EXPR_VAL_FNUM || left->vtype == EXPR_VAL_BOOL)
        fatal_error("cannot perform bitwise operations of float or boolean");

    if(right->vtype == EXPR_VAL_FNUM || right->vtype == EXPR_VAL_BOOL)
        fatal_error("cannot perform bitwise operations of float or boolean");

    switch (left->vtype) {
        case EXPR_VAL_INUM:
            {
                int64_t le = left->value.inum;

                warning("bitwise operations on signed integer");
                switch (right->vtype) {
                    case EXPR_VAL_UNUM:
                        result = (le >> right->value.unum);
                        break;
                    case EXPR_VAL_INUM:
                        result = (le >> right->value.inum);
                        break;
                    default:
                        fatal_error("Unknown vtype right in perform_arithmetic().");
                }
            }

        case EXPR_VAL_UNUM:
            {
                uint64_t le = left->value.unum;

                switch (right->vtype) {
                    case EXPR_VAL_UNUM:
                        result = (le >> right->value.unum);
                        break;
                    case EXPR_VAL_INUM:
                        warning("bitwise operations on signed integer");
                        result = (le >> right->value.inum);
                        break;
                    default:
                        fatal_error("Unknown vtype right in perform_arithmetic().");
                }
            }
            break;

        default:
            fatal_error("Unknown vtype left in perform_arithmetic().");
    }

    push_inter(expr, EXPR_VAL_UNUM, (void *)&result);
    free(right);
    free(left);
}

static void perform_bitwise_rol(expression_t *expr) {
    MARK();
    fatal_error("Bitwise rotate is not supported (yet)");
}

static void perform_bitwise_ror(expression_t *expr) {
    MARK();
    fatal_error("Bitwise rotate is not supported (yet)");
}

static void push_inter_value(expression_t *expr, val_fifo_element_t * val) {
    MARK();

    switch (val->vtype) {
        case EXPR_VAL_UNUM:
            {
                uint64_t result = val->value.unum;

                push_inter(expr, EXPR_VAL_UNUM, (void *)&result);
            }
            break;
        case EXPR_VAL_INUM:
            {
                int64_t result = val->value.inum;

                push_inter(expr, EXPR_VAL_INUM, (void *)&result);
            }
            break;
        case EXPR_VAL_FNUM:
            {
                double result = val->value.fnum;

                push_inter(expr, EXPR_VAL_FNUM, (void *)&result);
            }
            break;
        case EXPR_VAL_BOOL:
            {
                unsigned char result = val->value.unum;

                push_inter(expr, EXPR_VAL_BOOL, (void *)&result);
            }
            break;
        default:
            fatal_error("Unknown vtype in push_inter_value().");
    }
}
