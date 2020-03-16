#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "scanner.h"
#include "utils.h"
#include "expressions.h"

/*
 *  Coerse various types to unsigned and emit a warning when it's unwise to
 *  coerse a particular type. Places the coersed operands in the outv data
 *  structure.
 *
 *  Coersing a float or an unsigned does not produce a warning, but coersing
 *  any negative integer does. Coersing a boolean produces an error.
 */
static inline expr_val_type_t coerse_type(output_value_t *outv,
                                         expr_value_t *left,
                                         expr_value_t *right) {
    switch(left->vtype) {
        case EXPR_VAL_UNUM:
            outv->left.unum = left->value.unum;
            break;
        case EXPR_VAL_INUM:
            if(left->value.inum < 0)
                warning("negative integers in a bitwise expression can produce unexpected results");
            outv->left.unum = (uint64_t)left->value.inum;
            break;
        case EXPR_VAL_FNUM:
            syntax("float values in a bitwise operation are not allowed");
            break;
        case EXPR_VAL_BOOL:
            syntax("boolean values in a bitwise operation are not allowed");
            break;
        default:
            fatal_error("parser error: unknown left value type: %d", left->vtype);
    }

    switch(right->vtype) {
        case EXPR_VAL_UNUM:
            outv->right.unum = (right->value.unum != 0);
            break;
        case EXPR_VAL_INUM:
            if(left->value.inum < 0)
                warning("negative integers in a bitwise expression can produce unexpected results");
            outv->right.unum = (right->value.inum != 0);
            break;
        case EXPR_VAL_FNUM:
            syntax("float values in a bitwise operation are not allowed");
            break;
        case EXPR_VAL_BOOL:
            syntax("boolean values in a bitwise operation are not allowed");
            break;
        default:
            fatal_error("parser error: unknown right value type: %d", right->vtype);
    }
    outv->vtype = EXPR_VAL_UNUM;
    return EXPR_VAL_UNUM;
}

void perform_bitwise_operation(expression_t expr, expr_ops_t oper) {
    MARK();
    expr_value_t left;
    expr_value_t right;
    expr_value_t ovalue;
    output_value_t oval;

    pop_output(expr, &left);
    pop_output(expr, &right);
    coerse_type(&oval, &left, &right);

    switch(oper) {
        case EXPR_OP_BIT_AND:
            MSG("bitwise AND");
            ovalue.value.unum = oval.left.unum & oval.right.unum;
            break;
        case EXPR_OP_BIT_OR:
            MSG("bitwise OR");
            ovalue.value.unum = oval.left.unum | oval.right.unum;
            break;
        case EXPR_OP_BIT_XOR:
            MSG("bitwise XOR");
            ovalue.value.unum = oval.left.unum ^ oval.right.unum;
            break;
        case EXPR_OP_BIT_SHL:
            MSG("bitwise SHIFT LEFT");
            ovalue.value.unum = oval.left.unum << oval.right.unum;
            break;
        case EXPR_OP_BIT_SHR:
            MSG("bitwise SHIFT RIGHT");
            ovalue.value.unum = oval.left.unum >> oval.right.unum;
            break;
        case EXPR_OP_BIT_ROL:
        case EXPR_OP_BIT_ROR:
            MSG("bitwise ROTATE");
            syntax("rotate bitwise operations are not supported yet.");
            break;
        default:
            // should never happen
            fatal_error("parser error: unexpected operator in this context: (%d)", oper);
    }

    // don't push junk on the stack
    if(get_num_errors() == 0) {
        ovalue.vtype = EXPR_VAL_UNUM;
        push_output(expr, &ovalue);
    }
}

