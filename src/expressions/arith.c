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
 *  All of the permuations of different types makes this code ugly. When a
 *  coersion is made that alters the value of one of the values, a warning is
 *  issued.
 */
static inline expr_val_type_t coerse_type(output_value_t *outv,
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
                MSG("coerse left inum to fnum: %f", outv->left.fnum);
                break;
            case EXPR_VAL_FNUM:
                outv->left.fnum = left->value.fnum;
                break;
            default:
                fatal_error("parser error: unknown left value type: %d", left->vtype);
        }

        switch(right->vtype) {
            case EXPR_VAL_UNUM:
                outv->right.fnum = (double)right->value.unum;
                break;
            case EXPR_VAL_INUM:
                outv->right.fnum = (double)right->value.inum;
                MSG("coerse right inum to fnum: %f", outv->right.fnum);
                break;
            case EXPR_VAL_FNUM:
                outv->right.fnum = right->value.fnum;
                break;
            default:
                fatal_error("parser error: unknown right value type: %d", right->vtype);
        }
        outv->vtype = EXPR_VAL_FNUM;
        retv = EXPR_VAL_FNUM;
    }
    else if(left->vtype == EXPR_VAL_INUM || right->vtype == EXPR_VAL_INUM) {
        switch(left->vtype) {
            case EXPR_VAL_UNUM:
                outv->left.inum = (int64_t)left->value.unum;
                break;
            case EXPR_VAL_INUM:
                outv->left.inum = left->value.inum;
                break;
            default:
                fatal_error("parser error: unknown left value type: %d", left->vtype);
        }

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
        outv->vtype = EXPR_VAL_INUM;
        retv = EXPR_VAL_INUM;
    }
    else {
        outv->right.inum = right->value.unum;
        outv->left.inum = left->value.unum;
        outv->vtype = EXPR_VAL_UNUM;
        retv = EXPR_VAL_UNUM;
    }

    return retv;
}

void perform_arith_add(expression_t expr) {
    MARK();
    expr_value_t left;
    expr_value_t right;
    expr_value_t result;
    output_value_t outv;
    int errors = 0;

    pop_output(expr, &right);
    pop_output(expr, &left);
    coerse_type(&outv, &left, &right);

    switch(outv.vtype) {
        case EXPR_VAL_UNUM:
            result.vtype = EXPR_VAL_UNUM;
            result.value.unum = outv.left.unum + outv.right.unum;
            break;
        case EXPR_VAL_INUM:
            result.vtype = EXPR_VAL_INUM;
            result.value.inum = outv.left.inum + outv.right.inum;
            break;
        case EXPR_VAL_FNUM:
            result.vtype = EXPR_VAL_FNUM;
            result.value.fnum = outv.left.fnum + outv.right.fnum;
            break;
        case EXPR_VAL_BOOL:
            syntax("cannot add boolean values");
            errors++;
            break;
        default:
            fatal_error("parser error: invalid type in perform_arith_add().");
    }
    if(!errors)
        push_output(expr, &result);
}


void perform_arith_sub(expression_t expr) {
    MARK();
    expr_value_t left;
    expr_value_t right;
    expr_value_t result;
    output_value_t outv;
    int errors = 0;

    pop_output(expr, &right);
    pop_output(expr, &left);
    coerse_type(&outv, &left, &right);

    switch(outv.vtype) {
        case EXPR_VAL_UNUM:
            result.vtype = EXPR_VAL_UNUM;
            result.value.unum = outv.left.unum - outv.right.unum;
            break;
        case EXPR_VAL_INUM:
            result.vtype = EXPR_VAL_INUM;
            result.value.inum = outv.left.inum - outv.right.inum;
            break;
        case EXPR_VAL_FNUM:
            result.vtype = EXPR_VAL_FNUM;
            result.value.fnum = outv.left.fnum - outv.right.fnum;
            break;
        case EXPR_VAL_BOOL:
            syntax("cannot subtract boolean values");
            errors++;
            break;
        default:
            fatal_error("parser error: invalid type in perform_arith_sub().");
    }
    if(!errors)
        push_output(expr, &result);
}

void perform_arith_mul(expression_t expr) {
    MARK();
    expr_value_t left;
    expr_value_t right;
    expr_value_t result;
    output_value_t outv;
    int errors = 0;

    pop_output(expr, &right);
    pop_output(expr, &left);
    coerse_type(&outv, &left, &right);

    switch(outv.vtype) {
        case EXPR_VAL_UNUM:
            result.vtype = EXPR_VAL_UNUM;
            result.value.unum = outv.left.unum * outv.right.unum;
            break;
        case EXPR_VAL_INUM:
            result.vtype = EXPR_VAL_INUM;
            result.value.inum = outv.left.inum * outv.right.inum;
            break;
        case EXPR_VAL_FNUM:
            result.vtype = EXPR_VAL_FNUM;
            result.value.fnum = outv.left.fnum * outv.right.fnum;
            break;
        case EXPR_VAL_BOOL:
            syntax("cannot multiply boolean values");
            errors++;
            break;
        default:
            fatal_error("parser error: invalid type in perform_arith_mul().");
    }
    if(!errors)
        push_output(expr, &result);
}

void perform_arith_div(expression_t expr) {
    MARK();
    expr_value_t left;
    expr_value_t right;
    expr_value_t result;
    output_value_t outv;
    int errors = 0;

    pop_output(expr, &right);
    pop_output(expr, &left);
    coerse_type(&outv, &left, &right);

    switch(outv.vtype) {
        case EXPR_VAL_UNUM:
            result.vtype = EXPR_VAL_UNUM;
            result.value.unum = outv.left.unum / outv.right.unum;
            break;
        case EXPR_VAL_INUM:
            result.vtype = EXPR_VAL_INUM;
            result.value.inum = outv.left.inum / outv.right.inum;
            break;
        case EXPR_VAL_FNUM:
            result.vtype = EXPR_VAL_FNUM;
            result.value.fnum = outv.left.fnum / outv.right.fnum;
            break;
        case EXPR_VAL_BOOL:
            syntax("cannot divide boolean values");
            errors++;
            break;
        default:
            fatal_error("parser error: invalid type in perform_arith_div().");
    }
    if(!errors)
        push_output(expr, &result);
}

void perform_arith_mod(expression_t expr) {
    MARK();
    expr_value_t left;
    expr_value_t right;
    expr_value_t result;
    output_value_t outv;
    int errors = 0;

    pop_output(expr, &right);
    pop_output(expr, &left);
    coerse_type(&outv, &left, &right);

    switch(outv.vtype) {
        case EXPR_VAL_UNUM:
            result.vtype = EXPR_VAL_UNUM;
            result.value.unum = outv.left.unum % outv.right.unum;
            break;
        case EXPR_VAL_INUM:
            result.vtype = EXPR_VAL_INUM;
            result.value.inum = outv.left.inum % outv.right.inum;
            break;
        case EXPR_VAL_FNUM:
            syntax("modulo division not allowed on floats");
            break;
        case EXPR_VAL_BOOL:
            syntax("cannot modulo divide boolean values");
            errors++;
            break;
        default:
            fatal_error("parser error: invalid type in perform_arith_mod().");
    }
    if(!errors)
        push_output(expr, &result);
}
