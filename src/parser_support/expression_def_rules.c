#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "scanner.h"
#include "parser.h"
#include "parser_support.h"
#include "utils.h"
#include "expressions.h"

extern expression_t *current_expression;

void subscript_item_expression_start(void) {
    MARK();
}

void subscript_item_expression_finish(void) {
    MARK();
}

void subscript_item_formatted_string_start(void) {
    MARK();
}

void subscript_item_formatted_string_finish(void) {
    MARK();
}

void subscript_list_init(void) {
    MARK();
}

void subscript_list_add(void) {
    MARK();
}

void expression_name_complex_name(void) {
    MARK();
    expr_value_t val;

    val.value.ref = strdup(get_complex_name());
    val.vtype = EXPR_VAL_REFERENCE;
    store_expr_value(current_expression, &val);
}

void expression_name_complex_name_with_subscript(void) {
    MARK();
}

void expression_name_subscript_list_finish(void) {
    MARK();
}

void expression_literal_number(void) {
    MARK();
    literal_num_t *lval = get_literal_num();
    expr_value_t val;

    switch (lval->vtype) {
        case UNUM:
            {
                //uint64_t val = lval->value.unum;
                val.value.unum = lval->value.unum;
                val.vtype = EXPR_VAL_UNUM;
                store_expr_value(current_expression, &val);
                MSG("storing expr UNUM value %lu", val.value.unum);
                //store_expr_value(current_expression, EXPR_VAL_UNUM, (void *)&val);
            }
            break;
        case INUM:
            {
                //uint64_t val = lval->value.inum;
                //store_expr_value(current_expression, EXPR_VAL_INUM, (void *)&val);
                val.value.inum = lval->value.inum;
                val.vtype = EXPR_VAL_INUM;
                store_expr_value(current_expression, &val);
                MSG("storing expr INUM value %ld", val.value.inum);
            }
            break;
        case FNUM:
            {
                //double val = lval->value.fnum;
                //store_expr_value(current_expression, EXPR_VAL_FNUM, (void *)&val);
                val.value.fnum = lval->value.fnum;
                val.vtype = EXPR_VAL_FNUM;
                store_expr_value(current_expression, &val);
                MSG("storing expr FNUM value %f", val.value.fnum);
            }
            break;
        default:
            fatal_error("unknown number type in expression_literal_number() %d", lval->vtype);
    }
    //uint64_t val = lval->value.unum;

    //store_expr_value(current_expression, EXPR_VAL_UNUM, (void *)&val);

}

void expression_expression_name(void) {
    MARK();
}

/*
 * List of expression operations
 *
 * EXPR_OP_ADD, EXPR_OP_SUB, EXPR_OP_MUL, EXPR_OP_DIV, EXPR_OP_MOD,
 * EXPR_OP_UNARY_MINUS, EXPR_OP_BOOL_AND, EXPR_OP_BOOL_OR,
 * EXPR_OP_BOOL_UNARY_NOT, EXPR_OP_BOOL_EQ, EXPR_OP_BOOL_NEQ, EXPR_OP_BOOL_LE,
 * EXPR_OP_BOOL_GE, EXPR_OP_BOOL_LT, EXPR_OP_BOOL_GT, EXPR_OP_BIT_AND,
 * EXPR_OP_BIT_OR, EXPR_OP_BIT_XOR, EXPR_OP_BIT_UNARY_NEG, EXPR_OP_BIT_SHL,
 * EXPR_OP_BIT_SHR, EXPR_OP_BIT_ROL, EXPR_OP_BIT_ROR,
 */
void expression_addition_operation(void) {
    MARK();
    expr_value_t val;
    val.vtype = EXPR_VAL_OPERATOR;
    val.value.oper = EXPR_OP_ADD;
    EXPR_PRINT_VALUE(&val);
    store_expr_value(current_expression, &val);
}

void expression_subtraction_operation(void) {
    MARK();
    expr_value_t val;
    val.vtype = EXPR_VAL_OPERATOR;
    val.value.oper = EXPR_OP_SUB;
    EXPR_PRINT_VALUE(&val);
    store_expr_value(current_expression, &val);
}

void expression_division_operation(void) {
    MARK();
    expr_value_t val;
    val.vtype = EXPR_VAL_OPERATOR;
    val.value.oper = EXPR_OP_DIV;
    EXPR_PRINT_VALUE(&val);
    store_expr_value(current_expression, &val);
}

void expression_multiplication_operation(void) {
    MARK();
    expr_value_t val;
    val.vtype = EXPR_VAL_OPERATOR;
    val.value.oper = EXPR_OP_MUL;
    EXPR_PRINT_VALUE(&val);
    store_expr_value(current_expression, &val);
}

void expression_modulo_operation(void) {
    MARK();
    expr_value_t val;
    val.vtype = EXPR_VAL_OPERATOR;
    val.value.oper = EXPR_OP_MOD;
    EXPR_PRINT_VALUE(&val);
    store_expr_value(current_expression, &val);
}

void expression_and_boolean_operation(void) {
    MARK();
    expr_value_t val;
    val.vtype = EXPR_VAL_OPERATOR;
    val.value.oper = EXPR_OP_BOOL_AND;
    EXPR_PRINT_VALUE(&val);
    store_expr_value(current_expression, &val);
}

void expression_or_boolean_operation(void) {
    MARK();
    expr_value_t val;
    val.vtype = EXPR_VAL_OPERATOR;
    val.value.oper = EXPR_OP_BOOL_OR;
    EXPR_PRINT_VALUE(&val);
    store_expr_value(current_expression, &val);
}

void expression_less_boolean_operation(void) {
    MARK();
    expr_value_t val;
    val.vtype = EXPR_VAL_OPERATOR;
    val.value.oper = EXPR_OP_BOOL_LT;
    EXPR_PRINT_VALUE(&val);
    store_expr_value(current_expression, &val);
}

void expression_greater_boolean_operation(void) {
    MARK();
    expr_value_t val;
    val.vtype = EXPR_VAL_OPERATOR;
    val.value.oper = EXPR_OP_BOOL_GT;
    EXPR_PRINT_VALUE(&val);
    store_expr_value(current_expression, &val);
}

void expression_equal_boolean_operation(void) {
    MARK();
    expr_value_t val;
    val.vtype = EXPR_VAL_OPERATOR;
    val.value.oper = EXPR_OP_BOOL_EQ;
    EXPR_PRINT_VALUE(&val);
    store_expr_value(current_expression, &val);
}

void expression_not_equal_boolean_operation(void) {
    MARK();
    expr_value_t val;
    val.vtype = EXPR_VAL_OPERATOR;
    val.value.oper = EXPR_OP_BOOL_NEQ;
    EXPR_PRINT_VALUE(&val);
    store_expr_value(current_expression, &val);
}

void expression_less_or_equal_boolean_operation(void) {
    MARK();
    expr_value_t val;
    val.vtype = EXPR_VAL_OPERATOR;
    val.value.oper = EXPR_OP_BOOL_LE;
    EXPR_PRINT_VALUE(&val);
    store_expr_value(current_expression, &val);
}

void expression_greater_or_equal_boolean_operation(void) {
    MARK();
    expr_value_t val;
    val.vtype = EXPR_VAL_OPERATOR;
    val.value.oper = EXPR_OP_BOOL_GE;
    EXPR_PRINT_VALUE(&val);
    store_expr_value(current_expression, &val);
}

void expression_and_bitwise_operation(void) {
    MARK();
    expr_value_t val;
    val.vtype = EXPR_VAL_OPERATOR;
    val.value.oper = EXPR_OP_BIT_AND;
    EXPR_PRINT_VALUE(&val);
    store_expr_value(current_expression, &val);
}

void expression_or_bitwise_operation(void) {
    MARK();
    expr_value_t val;
    val.vtype = EXPR_VAL_OPERATOR;
    val.value.oper = EXPR_OP_BIT_OR;
    EXPR_PRINT_VALUE(&val);
    store_expr_value(current_expression, &val);
}

void expression_xor_bitwise_operation(void) {
    MARK();
    expr_value_t val;
    val.vtype = EXPR_VAL_OPERATOR;
    val.value.oper = EXPR_OP_BIT_XOR;
    EXPR_PRINT_VALUE(&val);
    store_expr_value(current_expression, &val);
}

void expression_rotate_left_bitwise_operation(void) {
    MARK();
    expr_value_t val;
    val.vtype = EXPR_VAL_OPERATOR;
    val.value.oper = EXPR_OP_BIT_ROL;
    EXPR_PRINT_VALUE(&val);
    store_expr_value(current_expression, &val);
}

void expression_rotate_right_bitwise_operation(void) {
    MARK();
    expr_value_t val;
    val.vtype = EXPR_VAL_OPERATOR;
    val.value.oper = EXPR_OP_BIT_ROR;
    EXPR_PRINT_VALUE(&val);
    store_expr_value(current_expression, &val);
}

void expression_shift_left_bitwise_operation(void) {
    MARK();
    expr_value_t val;
    val.vtype = EXPR_VAL_OPERATOR;
    val.value.oper = EXPR_OP_BIT_SHL;
    EXPR_PRINT_VALUE(&val);
    store_expr_value(current_expression, &val);
}

void expression_shift_right_bitwise_operation(void) {
    MARK();
    expr_value_t val;
    val.vtype = EXPR_VAL_OPERATOR;
    val.value.oper = EXPR_OP_BIT_SHR;
    EXPR_PRINT_VALUE(&val);
    store_expr_value(current_expression, &val);
}

void expression_unary_negate_operation(void) {
    MARK();
    expr_value_t val;
    val.vtype = EXPR_VAL_OPERATOR;
    val.value.oper = EXPR_OP_UNARY_MINUS;
    EXPR_PRINT_VALUE(&val);
    store_expr_value(current_expression, &val);
}

void expression_unary_not_boolean_operation(void) {
    MARK();
    expr_value_t val;
    val.vtype = EXPR_VAL_OPERATOR;
    val.value.oper = EXPR_OP_BOOL_UNARY_NOT;
    EXPR_PRINT_VALUE(&val);
    store_expr_value(current_expression, &val);
}

void expression_not_bitwise_operation(void) {
    MARK();
    expr_value_t val;
    val.vtype = EXPR_VAL_OPERATOR;
    val.value.oper = EXPR_OP_BIT_UNARY_NEG;
    EXPR_PRINT_VALUE(&val);
    store_expr_value(current_expression, &val);
}

void expression_start(void) {
    MARK();
    current_expression = create_expression();
}

void expression_finish(void) {
    MARK();
    // temp code to test expressions
    //expr_val_type_t type;
    //void *result = evaluate_expression(current_expression, (void *)&type);
    expr_value_t val;
    pop_output(current_expression, &val);
    EXPR_PRINT_VALUE(&val);

    switch (val.vtype) {
        case EXPR_VAL_UNUM:
            MSG("result of unsigned integer expression: %lu", val.value.unum);
            break;
        case EXPR_VAL_INUM:
            MSG("result of signed integer expression: %ld", val.value.inum);
            break;
        case EXPR_VAL_FNUM:
            MSG("result of float expression: %f", val.value.fnum);
            break;
        case EXPR_VAL_BOOL:
            MSG("result of boolean expression: %s", val.value.bval? "True" : "False");
            break;
        case EXPR_VAL_REFERENCE:
        case EXPR_VAL_OPERATOR:
            syntax("unexpected reference or operator in evalate expression.");
    }
    destroy_expression(current_expression);
}
