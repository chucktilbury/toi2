#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "expressions.h"
#include "utils.h"
#include "scanner.h"

/*
 * This data structure contains all of the elements required to evaluate the expression. This is the data structure that is stored in the abstract
 * tree as parsing continues.
 */
typedef struct expression_struct {
    expr_context_t context;
    fifo_t input;
    lifo_t output;
} expression_struct_t;

/*
 * This functionality uses 3 stacks to store and evaluate an expression.
 * Expressions are evaluated at run time.
 */
expression_t create_expression(void) {
    MARK();
    expression_struct_t *expr;

    if(NULL == (expr = (expression_struct_t *)calloc(1, sizeof(expression_struct_t))))
        fatal_error("Cannot allocate memory for an expression.");

    expr->input = fifo_create();
    expr->output = lifo_create();
    expr->context = EXPR_CONTEXT_NONE;

    return (expression_t)expr;
}

void destroy_expression(expression_t e) {
    MARK();
    expression_struct_t *expr = (expression_struct_t *)e;
    expr_value_t val;

    if(expr != NULL) {

        fifo_reset(expr->input);
        while(fifo_get(expr->input, &val, sizeof(expr_value_t)))
            if(val.vtype == EXPR_VAL_REFERENCE)
                free(val.value.ref);

        fifo_destroy(expr->input);
        lifo_destroy(expr->output);
        free(expr);
    }
}

void store_expr_value(expression_t e, expr_value_t *val) {
    MARK() ;
    expression_struct_t *expr = (expression_struct_t *)e;
    fifo_add(expr->input, (void*)val, sizeof(expr_value_t));
}

int get_expr_value(expression_t e, expr_value_t *val) {
    MARK();
    expression_struct_t *expr = (expression_struct_t *)e;
    return fifo_get(expr->input, val, sizeof(expr_value_t));
}

void reset_value_fifo(expression_t e) {
    MARK();
    expression_struct_t *expr = (expression_struct_t *)e;
    fifo_reset(expr->input);
}

void push_output(expression_t e, expr_value_t *val) {
    MARK();
    EXPR_PRINT_VALUE(val);
    expression_struct_t *expr = (expression_struct_t *)e;
    lifo_push(expr->output, val, sizeof(expr_value_t));
}

int pop_output(expression_t e, expr_value_t *val) {
    MARK();
    expression_struct_t *expr = (expression_struct_t *)e;
    int retv = lifo_pop(expr->output, val, sizeof(expr_value_t));
    EXPR_PRINT_VALUE(val);
    return retv;
}

int peek_output(expression_t e, expr_value_t *val) {
    MARK();
    EXPR_PRINT_VALUE(val);
    expression_struct_t *expr = (expression_struct_t *)e;
    return lifo_peek(expr->output, val, sizeof(expr_value_t));
}
