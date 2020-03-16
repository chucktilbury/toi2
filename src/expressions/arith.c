#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "scanner.h"
#include "utils.h"
#include "expressions.h"

/*
 *  The order of promotion is used to cast the values in the expression such
 *  that the highest promotion is used. Here is the order from highest to
 *  lowest:
 *
 *  boolean
 *  float
 *  signed int
 *  unsigned int
 *
 *  An arithmetic operation is always performed on values of the same type and
 *  that type is the one used to push back on the stack.
 */

/*
 *  The actual operaton is performed using this data structure.
 */
typedef struct arith_value {
    expr_val_type_t vtype;
    union __attribute__((packed)) {
        uint64_t unum;
        int64_t inum;
        double fnum;
        unsigned char bval;
    } left;
    union __attribute__((packed)) {
        uint64_t unum;
        int64_t inum;
        double fnum;
        unsigned char bval;
    } right;
} arith_value_t;

/*
 *  All of the permuations of different types makes this code ugly. When a
 *  coersion is made that alters the value of one of the values, a warning is
 *  issued.
 */
static inline expr_val_type_t coerse_type(arith_value_t *outv,
                                         expr_value_t *left,
                                         expr_value_t *right) {
    expr_val_type_t retv;

    if(left->vtype == EXPR_VAL_BOOL || right->vtype == EXPR_VAL_BOOL) {
        switch(left->vtype) {
            case EXPR_VAL_UNUM:
                outv->left.bval = (left->value.unum > 0);
                break;
            case EXPR_VAL_INUM:
                outv->left.bval = (left->value.inum > 0);
                break;
            case EXPR_VAL_FNUM:
                warning("converting left float to bool");
                outv->left.bval = (left->value.fnum > 0);
                break;
            case EXPR_VAL_BOOL:
                outv->left.bval = left->value.bval;
                break;
            default:
                fatal_error("parser error: unknown left value type: %d", left->vtype);
        }
        break;

        switch(right->vtype) {
            case EXPR_VAL_UNUM:
                outv->right.bval = (right->value.unum > 0);
                break;
            case EXPR_VAL_INUM:
                outv->right.bval = (right->value.inum > 0);
                break;
            case EXPR_VAL_FNUM:
                warning("converting right float to bool");
                outv->right.bval = (right->value.fnum > 0);
                break;
            case EXPR_VAL_BOOL:
                outv->right.bval = right->value.bval;
                break;
            default:
                fatal_error("parser error: unknown right value type: %d", right->vtype);
        }
        break;
        outv->vtype = EXPR_VAL_BOOL;
        retv = EXPR_VAL_BOOL;
    }
    else if(left->vtype == EXPR_VAL_FNUM || right->vtype == EXPR_VAL_FNUM) {
        switch(left->vtype) {
            case EXPR_VAL_UNUM:
                outv->left.fnum = (double)left->value.unum;
                break;
            case EXPR_VAL_INUM:
                outv->left.fnum = (double)left->value.inum;
                break;
            case EXPR_VAL_FNUM:
                outv->left.fnum = left->value.fnum;
                break;
            default:
                fatal_error("parser error: unknown left value type: %d", left->vtype);
        }
        break;

        switch(right->vtype) {
            case EXPR_VAL_UNUM:
                outv->right.fnum = (double)right->value.unum;
                break;
            case EXPR_VAL_INUM:
                outv->right.fnum = (double)right->value.inum;
                break;
            case EXPR_VAL_FNUM:
                outv->right.fnum = right->value.fnum;
                break;
            default:
                fatal_error("parser error: unknown right value type: %d", right->vtype);
        }
        break;
        outv->vtype = EXPR_VAL_FNUM;
        retv = EXPR_VAL_FNUM;
    }
    else if(left->vtype == EXPR_VAL_INUM || right->vtype == EXPR_VAL_INUM) {
        switch(left->vtype) {
            case EXPR_VAL_UNUM:
                outv->left.inum = (int64_t)left->value.unum;
                break;
            case EXPR_VAL_INUM:
                outv->left.inum = eft->value.inum;
                break;
            default:
                fatal_error("parser error: unknown left value type: %d", left->vtype);
        }
        break;

        switch(right->vtype) {
            case EXPR_VAL_UNUM:
                outv->right.inum = (int64_t)right->value.unum;
                break;
            case EXPR_VAL_INUM:
                outv->right.inum = right->value.inum;
                break;
            default:
                fatal_error("parser error: unknown right value type: %d", right->vtype);
        }
        break;
        outv->vtype = EXPR_VAL_INUM;
        retv = EXPR_VAL_INUM;
    }
    else {
        outv->right.inum = right->value.unum;
        outv->left.inum = left->value.unum;
        outv->vtype = EXPR_VAL_UNUM;
        retv = EXPR_VAL_UNUM;
    }

    return retv
}

void perform_arith_operation(expression_t expr,
                             arith_value_t *outv,
                             expr_ops_t oper) {

}

void perform_arith_add(expression_t expr) {
    MARK();
    expr_value_t left;
    expr_value_t right;

    pop_output(expr, &right);
    pop_output(expr, &left);

    switch (left.vtype) {
        case EXPR_VAL_UNUM:
            {
                uint64_t le = left.value.unum;
                uint64_t result;
                expr_value_t ovalue;

                switch (right.vtype) {
                    case EXPR_VAL_UNUM:
                        result = le + right.value.unum;
                        break;
                    case EXPR_VAL_INUM:
                        // integer becomes unsigned
                        warning("converting integer to unsigned value");
                        result = le + (uint64_t) right.value.inum;
                        break;
                    case EXPR_VAL_FNUM:
                        // float is truncated to unsigned
                        warning("truncate a float to unsigned value");
                        result = le + (uint64_t) right.value.fnum;
                        break;
                    case EXPR_VAL_BOOL:
                        warning("using boolean result in arithmetic operation");
                        result = le + (uint64_t) right.value.bval;
                        break;
                    default:
                        syntax("Unknown vtype right in perform_arithmetic().");
                }
                ovalue.value.unum = result;
                ovalue.vtype = EXPR_VAL_UNUM;
                push_output(expr, &ovalue);
            }
            break;

        case EXPR_VAL_INUM:
            {
                int64_t le = left.value.inum;
                int64_t result;
                expr_value_t ovalue;

                switch (right.vtype) {
                    case EXPR_VAL_UNUM:
                        // unsigned is sign extended to integer
                        warning("converting unsigned value to sign extended integer");
                        result = le + (int64_t) right.value.unum;
                        break;
                    case EXPR_VAL_INUM:
                        result = le + right.value.inum;
                        break;
                    case EXPR_VAL_FNUM:
                        // float is truncated to integer
                        warning("truncate a float to unsigned value");
                        result = le + (int64_t) right.value.fnum;
                        break;
                    case EXPR_VAL_BOOL:
                        warning("using boolean result in arithmetic operation");
                        result = le + (int64_t) right.value.bval;
                        break;
                    default:
                        syntax("Unknown vtype right in perform_arithmetic().");
                }
                ovalue.value.inum = result;
                ovalue.vtype = EXPR_VAL_INUM;
                push_output(expr, &ovalue);
            }
            break;

        case EXPR_VAL_FNUM:
            {
                double le = left.value.fnum;
                double result;
                expr_value_t ovalue;

                // right side is simply case to double
                switch (right.vtype) {
                    case EXPR_VAL_UNUM:
                        result = le + (double)right.value.unum;
                        break;
                    case EXPR_VAL_INUM:
                        result = le + (double)right.value.inum;
                        break;
                    case EXPR_VAL_FNUM:
                        result = le + right.value.fnum;
                        break;
                    case EXPR_VAL_BOOL:
                        warning("using boolean result in arithmetic operation");
                        result = le + (double)right.value.bval;
                        break;
                    default:
                        syntax("Unknown vtype right in perform_arithmetic().");
                }
                ovalue.value.fnum = result;
                ovalue.vtype = EXPR_VAL_FNUM;
                push_output(expr, &ovalue);
            }
            break;

        case EXPR_VAL_BOOL:
            syntax("addition on boolean result is invalid");
            break;

        default:
            syntax("Unknown vtype left in perform_arithmetic().");
    }

}

void perform_arith_sub(expression_t expr) {
    MARK();
    expr_value_t left;
    expr_value_t right;

    pop_output(expr, &right);
    pop_output(expr, &left);

    switch (left.vtype) {
        case EXPR_VAL_UNUM:
            {
                uint64_t le = left.value.unum;
                uint64_t result;
                expr_value_t ovalue;

                switch (right.vtype) {
                    case EXPR_VAL_UNUM:
                        result = le - right.value.unum;
                        break;
                    case EXPR_VAL_INUM:
                        // integer becomes unsigned
                        warning("converting integer to unsigned value");
                        result = le - (uint64_t) right.value.inum;
                        break;
                    case EXPR_VAL_FNUM:
                        // float is truncated to unsigned
                        warning("truncate a float to unsigned value");
                        result = le - (uint64_t) right.value.fnum;
                        break;
                    case EXPR_VAL_BOOL:
                        warning("using boolean result in arithmetic operation");
                        result = le - (uint64_t) right.value.bval;
                        break;
                    default:
                        syntax("Unknown vtype right in perform_arithmetic().");
                }
                ovalue.value.unum = result;
                ovalue.vtype = EXPR_VAL_UNUM;
                push_output(expr, &ovalue);
            }
            break;

        case EXPR_VAL_INUM:
            {
                int64_t le = left.value.inum;
                int64_t result;
                expr_value_t ovalue;

                switch (right.vtype) {
                    case EXPR_VAL_UNUM:
                        // unsigned is sign extended to integer
                        warning("converting unsigned value to sign extended integer");
                        result = le - (int64_t) right.value.unum;
                        break;
                    case EXPR_VAL_INUM:
                        result = le - right.value.inum;
                        break;
                    case EXPR_VAL_FNUM:
                        // float is truncated to integer
                        warning("truncate a float to unsigned value");
                        result = le - (int64_t) right.value.fnum;
                        break;
                    case EXPR_VAL_BOOL:
                        warning("using boolean result in arithmetic operation");
                        result = le - (int64_t) right.value.bval;
                        break;
                    default:
                        syntax("Unknown vtype right in perform_arithmetic().");
                }
                ovalue.value.inum = result;
                ovalue.vtype = EXPR_VAL_INUM;
                push_output(expr, &ovalue);
            }
            break;

        case EXPR_VAL_FNUM:
            {
                double le = left.value.fnum;
                double result;
                expr_value_t ovalue;

                // right side is simply case to double
                switch (right.vtype) {
                    case EXPR_VAL_UNUM:
                        result = le - (double)right.value.unum;
                        break;
                    case EXPR_VAL_INUM:
                        result = le - (double)right.value.inum;
                        break;
                    case EXPR_VAL_FNUM:
                        result = le - right.value.fnum;
                        break;
                    case EXPR_VAL_BOOL:
                        warning("using boolean result in arithmetic operation");
                        result = le - (double)right.value.bval;
                        break;
                    default:
                        syntax("Unknown vtype right in perform_arithmetic().");
                }
                ovalue.value.fnum = result;
                ovalue.vtype = EXPR_VAL_FNUM;
                push_output(expr, &ovalue);
            }
            break;

        case EXPR_VAL_BOOL:
            syntax("subtraction on boolean result is invalid");
            break;

        default:
            syntax("Unknown vtype left in perform_arithmetic().");
    }
}

void perform_arith_mul(expression_t expr) {
    MARK();
    expr_value_t left;
    expr_value_t right;

    pop_output(expr, &right);
    pop_output(expr, &left);

    switch (left.vtype) {
        case EXPR_VAL_UNUM:
            {
                uint64_t le = left.value.unum;
                uint64_t result;
                expr_value_t ovalue;

                switch (right.vtype) {
                    case EXPR_VAL_UNUM:
                        result = le * right.value.unum;
                        break;
                    case EXPR_VAL_INUM:
                        // integer becomes unsigned
                        warning("converting integer to unsigned value");
                        result = le * (uint64_t) right.value.inum;
                        break;
                    case EXPR_VAL_FNUM:
                        // float is truncated to unsigned
                        warning("truncate a float to unsigned value");
                        result = le * (uint64_t) right.value.fnum;
                        break;
                    case EXPR_VAL_BOOL:
                        warning("using boolean result in arithmetic operation");
                        result = le * (uint64_t) right.value.bval;
                        break;
                    default:
                        syntax("Unknown vtype right in perform_arithmetic().");
                }
                ovalue.value.unum = result;
                ovalue.vtype = EXPR_VAL_UNUM;
                push_output(expr, &ovalue);
            }
            break;

        case EXPR_VAL_INUM:
            {
                int64_t le = left.value.inum;
                int64_t result;
                expr_value_t ovalue;

                switch (right.vtype) {
                    case EXPR_VAL_UNUM:
                        // unsigned is sign extended to integer
                        warning("converting unsigned value to sign extended integer");
                        result = le * (int64_t) right.value.unum;
                        break;
                    case EXPR_VAL_INUM:
                        result = le * right.value.inum;
                        break;
                    case EXPR_VAL_FNUM:
                        // float is truncated to integer
                        warning("truncate a float to unsigned value");
                        result = le * (int64_t) right.value.fnum;
                        break;
                    case EXPR_VAL_BOOL:
                        warning("using boolean result in arithmetic operation");
                        result = le * (int64_t) right.value.bval;
                        break;
                    default:
                        syntax("Unknown vtype right in perform_arithmetic().");
                }
                ovalue.value.inum = result;
                ovalue.vtype = EXPR_VAL_INUM;
                push_output(expr, &ovalue);
            }
            break;

        case EXPR_VAL_FNUM:
            {
                double le = left.value.fnum;
                double result;
                expr_value_t ovalue;

                // right side is simply case to double
                switch (right.vtype) {
                    case EXPR_VAL_UNUM:
                        result = le * (double)right.value.unum;
                        break;
                    case EXPR_VAL_INUM:
                        result = le * (double)right.value.inum;
                        break;
                    case EXPR_VAL_FNUM:
                        result = le * right.value.fnum;
                        break;
                    case EXPR_VAL_BOOL:
                        warning("using boolean result in arithmetic operation");
                        result = le * (double)right.value.bval;
                        break;
                    default:
                        syntax("Unknown vtype right in perform_arithmetic().");
                }
                ovalue.value.fnum = result;
                ovalue.vtype = EXPR_VAL_FNUM;
                push_output(expr, &ovalue);
            }
            break;

        case EXPR_VAL_BOOL:
            syntax("multiplication on boolean result is invalid");
            break;

        default:
            syntax("Unknown vtype left in perform_arithmetic().");
    }
}

void perform_arith_div(expression_t expr) {
    MARK();
    expr_value_t left;
    expr_value_t right;

    pop_output(expr, &right);
    pop_output(expr, &left);

    // check for divide by zero
    switch (right.vtype) {
        case EXPR_VAL_UNUM:
            if(right.value.unum == 0)
                syntax("Attempt to divide by zero detected.");
            break;
        case EXPR_VAL_INUM:
            if(right.value.inum == 0)
                syntax("Attempt to divide by zero detected.");
            break;
        case EXPR_VAL_FNUM:
            if(right.value.fnum == 0.0)
                syntax("Attempt to divide by zero detected.");
            break;
        case EXPR_VAL_BOOL:
            syntax("using boolean result in division operation is illegal");
            break;
        default:
            syntax("Unknown vtype right in perform_arithmetic().");
    }

    switch (left.vtype) {
        case EXPR_VAL_UNUM:
            {
                uint64_t le = left.value.unum;
                uint64_t result;
                expr_value_t ovalue;

                switch (right.vtype) {
                    case EXPR_VAL_UNUM:
                        result = le / right.value.unum;
                        break;
                    case EXPR_VAL_INUM:
                        // integer becomes unsigned
                        warning("converting integer to unsigned value");
                        result = le / (uint64_t) right.value.inum;
                        break;
                    case EXPR_VAL_FNUM:
                        // float is truncated to unsigned
                        warning("truncate a float to unsigned value");
                        result = le / (uint64_t) right.value.fnum;
                        break;
                    default:
                        syntax("Unknown vtype right in perform_arithmetic().");
                }
                ovalue.value.unum = result;
                ovalue.vtype = EXPR_VAL_UNUM;
                push_output(expr, &ovalue);
            }
            break;

        case EXPR_VAL_INUM:
            {
                int64_t le = left.value.inum;
                int64_t result;
                expr_value_t ovalue;

                switch (right.vtype) {
                    case EXPR_VAL_UNUM:
                        // unsigned is sign extended to integer
                        warning("converting unsigned value to sign extended integer");
                        result = le / (int64_t) right.value.unum;
                        break;
                    case EXPR_VAL_INUM:
                        result = le / right.value.inum;
                        break;
                    case EXPR_VAL_FNUM:
                        // float is truncated to integer
                        warning("truncate a float to unsigned value");
                        result = le / (int64_t) right.value.fnum;
                        break;
                    default:
                        syntax("Unknown vtype right in perform_arithmetic().");
                }
                ovalue.value.inum = result;
                ovalue.vtype = EXPR_VAL_INUM;
                push_output(expr, &ovalue);
            }
            break;

        case EXPR_VAL_FNUM:
            {
                double le = left.value.fnum;
                double result;
                expr_value_t ovalue;

                // right side is simply case to double
                switch (right.vtype) {
                    case EXPR_VAL_UNUM:
                        result = le / (double)right.value.unum;
                        break;
                    case EXPR_VAL_INUM:
                        result = le / (double)right.value.inum;
                        break;
                    case EXPR_VAL_FNUM:
                        result = le / right.value.fnum;
                        break;
                    default:
                        syntax("Unknown vtype right in perform_arithmetic().");
                }
                ovalue.value.fnum = result;
                ovalue.vtype = EXPR_VAL_FNUM;
                push_output(expr, &ovalue);
            }
            break;

        case EXPR_VAL_BOOL:
            syntax("using boolean result in division operation is illegal");
            break;

        default:
            syntax("Unknown vtype left in perform_arithmetic().");
    }
}

void perform_arith_mod(expression_t expr) {
    MARK();
    expr_value_t left;
    expr_value_t right;

    pop_output(expr, &right);
    pop_output(expr, &left);

    // check for divide by zero
    switch (right.vtype) {
        case EXPR_VAL_UNUM:
            if(right.value.unum == 0)
                syntax("Attempt to modulo divide by zero detected.");
            break;
        case EXPR_VAL_INUM:
            if(right.value.inum == 0)
                syntax("Attempt to modulo divide by zero detected.");
            break;
        case EXPR_VAL_FNUM:
            syntax("Modulo operatons only allowed on integer and unsigned.");
            break;
        case EXPR_VAL_BOOL:
            syntax("modulo operations not allowed on a boolean result");
            break;
        default:
            syntax("Unknown vtype right in perform_arithmetic().");
    }

    switch (left.vtype) {
        case EXPR_VAL_UNUM:
            {
                uint64_t le = left.value.unum;
                uint64_t result;
                expr_value_t ovalue;

                switch (right.vtype) {
                    case EXPR_VAL_UNUM:
                        result = le % right.value.unum;
                        break;
                    case EXPR_VAL_INUM:
                        // integer becomes unsigned
                        warning("converting integer to unsigned value");
                        result = le % (uint64_t) right.value.inum;
                        break;
                    default:
                        syntax("Unknown vtype right in perform_arithmetic().");
                }
                ovalue.value.unum = result;
                ovalue.vtype = EXPR_VAL_UNUM;
                push_output(expr, &ovalue);
            }
            break;

        case EXPR_VAL_INUM:
            {
                int64_t le = left.value.inum;
                int64_t result;
                expr_value_t ovalue;

                switch (right.vtype) {
                    case EXPR_VAL_UNUM:
                        // unsigned is sign extended to integer
                        warning("converting unsigned value to sign extended integer");
                        result = le / (int64_t) right.value.unum;
                        break;
                    case EXPR_VAL_INUM:
                        result = le / right.value.inum;
                        break;
                    default:
                        syntax("Unknown vtype right in perform_arithmetic().");
                }
                ovalue.value.inum = result;
                ovalue.vtype = EXPR_VAL_INUM;
                push_output(expr, &ovalue);
            }
            break;

        case EXPR_VAL_FNUM:
            syntax("Modulo operatons only allowed on integer and unsigned.");
            break;

        case EXPR_VAL_BOOL:
            syntax("Modulo operatons not allowed on boolean result.");
            break;

        default:
            syntax("Unknown vtype left in perform_arithmetic().");
    }
}
