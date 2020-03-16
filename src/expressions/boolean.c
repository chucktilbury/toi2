#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "scanner.h"
#include "utils.h"
#include "expressions.h"

/*
 *  Coerse various types to boolean and emit a warning when it's unwise to
 *  coerse a particular type. Places the coersed operands in the outv data
 *  structure.
 *
 *  Coersing a integer or an unsigned does not produce a warning, but coersing
 *  any float always does.
 */
static inline expr_val_type_t coerse_type(output_value_t *outv,
                                         expr_value_t *left,
                                         expr_value_t *right) {
    switch(left->vtype) {
        case EXPR_VAL_UNUM:
            outv->left.bval = (left->value.unum != 0);
            break;
        case EXPR_VAL_INUM:
            if(left->value.inum < 0)
                warning("negative integers in a boolean expression are TRUE");
            outv->left.bval = (left->value.inum != 0);
            break;
        case EXPR_VAL_FNUM:
            warning("floats in boolean expressions can produce unexpected results");
            outv->left.bval = (left->value.fnum != 0.0);
            break;
        case EXPR_VAL_BOOL:
            outv->left.bval = left->value.bval;
            break;
        default:
            fatal_error("parser error: unknown left value type: %d", left->vtype);
    }

    switch(right->vtype) {
        case EXPR_VAL_UNUM:
            outv->right.bval = (right->value.unum != 0);
            break;
        case EXPR_VAL_INUM:
            if(left->value.inum < 0)
                warning("negative integers in a boolean expression are TRUE");
            outv->right.bval = (right->value.inum != 0);
            break;
        case EXPR_VAL_FNUM:
            warning("floats in boolean expressions can produce unexpected results");
            outv->right.bval = (right->value.fnum > 0.0);
            break;
        case EXPR_VAL_BOOL:
            outv->right.bval = right->value.bval;
            break;
        default:
            fatal_error("parser error: unknown right value type: %d", right->vtype);
    }
    outv->vtype = EXPR_VAL_BOOL;
    return EXPR_VAL_BOOL;
}

void perform_boolean_operation(expression_t expr, expr_ops_t oper) {
    MARK();
    expr_value_t left;
    expr_value_t right;
    expr_value_t outv;
    output_value_t ovalue;

    pop_output(expr, &left);
    pop_output(expr, &right);
    coerse_type(&ovalue, &left, &right);

    switch(oper) {
        case EXPR_OP_BOOL_AND:
            MSG("boolean AND");
            outv.value.bval = ovalue.left.bval && ovalue.right.bval;
            break;
        case EXPR_OP_BOOL_OR:
            MSG("boolean OR");
            outv.value.bval = ovalue.left.bval || ovalue.right.bval;
            break;
        case EXPR_OP_BOOL_EQ:
            MSG("boolean EQUAL");
            outv.value.bval = ovalue.left.bval == ovalue.right.bval;
            break;
        case EXPR_OP_BOOL_NEQ:
            MSG("boolean NOT EQUAL");
            outv.value.bval = ovalue.left.bval != ovalue.right.bval;
            break;
        case EXPR_OP_BOOL_LE:
            MSG("boolean LESS THAN OR EQUAL");
            outv.value.bval = ovalue.left.bval <= ovalue.right.bval;
            break;
        case EXPR_OP_BOOL_GE:
            MSG("boolean GREATER THAN OR EQUAL");
            outv.value.bval = ovalue.left.bval >= ovalue.right.bval;
            break;
        case EXPR_OP_BOOL_LT:
            MSG("boolean LESS THAN");
            outv.value.bval = ovalue.left.bval < ovalue.right.bval;
            break;
        case EXPR_OP_BOOL_GT:
            MSG("boolean GREATER THAN");
            outv.value.bval = ovalue.left.bval > ovalue.right.bval;
            break;
        default:
            // should never happen
            fatal_error("parser error: unexpected operator in this context: (%d)", oper);
    }

    // don't push junk on the stack
    if(get_num_errors() != 0) {
        outv.vtype = EXPR_VAL_BOOL;
        push_output(expr, &outv);
    }
}

