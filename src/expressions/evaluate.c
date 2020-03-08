#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../abstract_tree/ast_tree.h"
#include "../parser/scanner.h"
#include "../utils/errors.h"
#include "expressions.h"
#include "arith.h"
#include "bitwise.h"
#include "bool1.h"
#include "bool2.h"
#include "unary.h"

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
