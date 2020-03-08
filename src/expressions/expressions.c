#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../utils/errors.h"
#include "../parser/scanner.h"
#include "expressions.h"

/*
 * This functionality uses 3 stacks to store and evaluate an expression.
 * Expressions are evaluated at run time.
 */
expression_t *create_expression(void) {
    MARK();
    expression_t *expr;

    if(NULL == (expr = (expression_t *)calloc(1, sizeof(expression_t))))
        fatal_error("Cannot allocate memory for an expression.");

    if(NULL == (expr->item = (val_fifo_t *) calloc(1, sizeof(val_fifo_t))))
        fatal_error("Cannot allocate memory for an expression item.");

    expr->context = EXPR_CONTEXT_NONE;
    return expr;
}

void destroy_expression(expression_t *expr) {
    MARK();

    if(expr != NULL) {
        if(expr->item != NULL) {
            if(expr->item->first != NULL) {

                val_fifo_element_t *vtmp, *vnext;

                for(vtmp = expr->item->first; vtmp != NULL; vtmp = vnext) {
                    vnext = vtmp->next;
                    if(vtmp->vtype == EXPR_VAL_REFERENCE)
                        free(vtmp->value.ref);
                    free(vtmp);
                }
                free(expr->item);
            }
        }
        if(expr->out != NULL) {

            out_lifo_t *otmp, *onext;

            for(otmp = expr->out; otmp != NULL; otmp = onext) {
                onext = otmp->next;
                free(otmp);
            }
        }
        free(expr);
    }
}

void store_value(expression_t *expr, expr_val_type_t type, void *value) {
    MARK();
    val_fifo_element_t *nitem;

    if(NULL == (nitem = (val_fifo_element_t *) calloc(1, sizeof(val_fifo_element_t))))
        fatal_error("Cannot allocate memory for a expression value.");

    nitem->vtype = type;
    switch (type) {
        case EXPR_VAL_UNUM:
            nitem->value.unum = *(unsigned long long *)value;
            break;
        case EXPR_VAL_INUM:
            nitem->value.inum = *(long long *)value;
            break;
        case EXPR_VAL_FNUM:
            nitem->value.fnum = *(double *)value;
            break;
        case EXPR_VAL_REFERENCE:
            nitem->value.ref = strdup((char *)value);
            break;
        case EXPR_VAL_OPERATOR:
            nitem->value.oper = *(expr_ops_t *) value;
            break;
        default:
            fatal_error("Unknown expression vtype (1.1).");
    }

    if(expr->item->first != NULL) {
        // add it to the end of the list.
        expr->item->last->next = nitem;
        expr->item->last = nitem;
    }
    else {
        // list is empty.
        expr->item->first = nitem;
        expr->item->last = nitem;
        expr->item->crnt = nitem;
    }
}

val_fifo_element_t *get_value(expression_t *expr) {
    MARK();

    val_fifo_element_t *item = expr->item->crnt;

    expr->item->crnt = item->next;
    return item;
}

void reset_value_fifo(expression_t *expr) {
    MARK();
    expr->item->crnt = expr->item->first;
}

void push_inter(expression_t *expr, expr_val_type_t type, void *value) {
    MARK();
    out_lifo_t *nitem;

    if(NULL == (nitem = (out_lifo_t *) calloc(1, sizeof(out_lifo_t))))
        fatal_error("Cannot allocate memory for an intermediate expression value.");

    nitem->vtype = type;
    switch (type) {
        case EXPR_VAL_UNUM:
            nitem->value.unum = *(unsigned long long *)value;
            break;
        case EXPR_VAL_INUM:
            nitem->value.inum = *(long long *)value;
            break;
        case EXPR_VAL_FNUM:
            nitem->value.fnum = *(double *)value;
            break;
        default:
            fatal_error("Unknown expression vtype (1.2).");
    }

    if(expr->out != NULL) {
        nitem->next = expr->out;
        expr->out = nitem;
    }
    else {
        expr->out = nitem;
    }
}

out_lifo_t *pop_inter(expression_t *expr) {
    MARK();

    out_lifo_t *retv = expr->out;

    expr->out = expr->out->next;

    return retv;
}

out_lifo_t *peek_inter(expression_t *expr) {
    MARK();
    return expr->out;
}
