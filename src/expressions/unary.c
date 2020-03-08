#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../parser/scanner.h"
#include "../utils/errors.h"
#include "unary.h"

void perform_unary_minus(expression_t *expr) {
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

void perform_unary_neg(expression_t *expr) {
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

void perform_unary_not(expression_t *expr) {
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
