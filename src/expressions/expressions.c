#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "errors.h"
#include "scanner.h"
#include "expressions.h"

/*
    This functionality uses 3 stacks to store and evaluate an expression.
    Expressions are evaluated at run time.
*/
expression_t *create_expression(void) {
    MARK();
    expression_t *expr;

    if(NULL == (expr = (expression_t *)calloc(1, sizeof(expression_t))))
        fatal_error("Cannot allocate memory for an expression.");

    expr->context = EXPR_CONTEXT_NONE;
    return expr;
}

void destroy_expression(expression_t *expr) {
    MARK();
    val_fifo_element_t *vtmp, *vnext;
    out_lifo_t *otmp, *onext;

    if(expr != NULL) {
        if(expr->item != NULL) {

        }

        if(expr->out != NULL) {
        }
    }
}

