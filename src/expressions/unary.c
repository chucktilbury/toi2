#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "scanner.h"
#include "utils.h"
#include "expressions.h"

void perform_unary_minus(expression_t expr) {
    MARK();
    expr_value_t value;
    expr_value_t ovalue;

    pop_output(expr, &value);

    switch (value.vtype) {
        case EXPR_VAL_UNUM:
            {
                int64_t result;

                warning("converting unsigned integer to unsigned value and sign extending");
                result = -(int64_t) value.value.unum;
                ovalue.value.inum = result;
                ovalue.vtype = EXPR_VAL_INUM;
                push_output(expr, &ovalue);
            }
            break;
        case EXPR_VAL_INUM:
            {
                int64_t result;

                result = -value.value.inum;
                ovalue.value.inum = result;
                ovalue.vtype = EXPR_VAL_INUM;
                push_output(expr, &ovalue);
            }
            break;
        case EXPR_VAL_FNUM:
            {
                double result;

                result = -value.value.fnum;
                ovalue.value.fnum = result;
                ovalue.vtype = EXPR_VAL_FNUM;
                push_output(expr, &ovalue);
                break;
            }
        case EXPR_VAL_BOOL:
            syntax("unary negate not allowed on a boolean result");
            break;

        default:
            syntax("Unknown vtype value in perform_arithmetic().");
    }
}

void perform_unary_neg(expression_t expr) {
    MARK();
    expr_value_t value;
    expr_value_t ovalue;
    uint64_t result;
    int error = 0;

    pop_output(expr, &value);

    switch (value.vtype) {
        case EXPR_VAL_UNUM:
            result = ~value.value.unum;
            break;
        case EXPR_VAL_INUM:
            // integer becomes unsigned
            warning("converting integer to unsigned value");
            result = ~(uint64_t) value.value.inum;
            break;
        case EXPR_VAL_FNUM:
            // float is truncated to unsigned
            syntax("unary bitwise negation not allowed for float");
            error++;
            break;
        case EXPR_VAL_BOOL:
            syntax("binary operations not allowed on a boolean result");
            error++;
            break;
        default:
            syntax("Unknown vtype value in perform_arithmetic().");
            error++;
    }
    if(error == 0) {
        ovalue.value.unum = result;
        ovalue.vtype = EXPR_VAL_UNUM;
        push_output(expr, &ovalue);
    }
}

void perform_unary_not(expression_t expr) {
    MARK();
    expr_value_t value;
    expr_value_t ovalue;
    unsigned char result;
    int error = 0;

    pop_output(expr, &value);

    switch (value.vtype) {
        case EXPR_VAL_UNUM:
            result = (!(value.value.unum == 0));
            break;
        case EXPR_VAL_INUM:
            result = (!(value.value.inum == 0));
            break;
        case EXPR_VAL_FNUM:
            warning("unary boolean \"not\" performed on float");
            result = (!(value.value.fnum == 0.0));
            break;
        case EXPR_VAL_BOOL:
            result = (!(value.value.bval == 0));
            break;
        default:
            syntax("Unknown vtype value in perform_arithmetic().");
            error++;
    }
    if(error == 0) {
        ovalue.value.bval = result;
        ovalue.vtype = EXPR_VAL_BOOL;
        push_output(expr, &ovalue);
    }
}
