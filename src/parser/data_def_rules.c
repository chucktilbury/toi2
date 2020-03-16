#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "scanner.h"
#include "parser_support.h"
#include "utils.h"
#include "expressions.h"

expression_t *current_expression;

void class_data_definition_with_data_attrs(void) {
    MARK();
}

void class_data_definition_add_data_attrs(void) {
    MARK();
}

void class_data_definition_name(void) {
    MARK();
}

void class_data_definition_finish(void) {
    MARK();
}

void class_data_definition_no_data_attrs(void) {
    MARK();
}

void function_data_definition_target_nothing(void) {
    MARK();
}

void function_data_definition_target_expression(void) {
    MARK();
}

void function_data_definition_target_cast(void) {
    MARK();
}

void function_data_definition_target_formatted_string(void) {
    MARK();
}

void function_data_definition_symbol(void) {
    MARK();
}

void function_data_definition_const_symbol(void) {
    MARK();
}

void function_data_definition_no_initializer(void) {
    MARK();
}

void function_data_definition_with_initializer(void) {
    MARK();
    current_expression = create_expression();
}

void function_data_definition_with_initializer_finish(void) {
    MARK();
    //expr_val_type_t type;
    //void *result = evaluate_expression(current_expression, (void *)&type);
    //
    //switch (type) {
    //    case EXPR_VAL_UNUM:
    //        MSG("result of unsigned integer expression: %lu", *(uint64_t *) result);
    //        break;
    //    case EXPR_VAL_INUM:
    //        MSG("result of signed integer expression: %ld", *(int64_t *) result);
    //        break;
    //    case EXPR_VAL_FNUM:
    //        MSG("result of float expression: %f", *(double *)result);
    //        break;
    //    case EXPR_VAL_BOOL:
    //        MSG("result of boolean expression: %s", *(unsigned char *)result ? "True" : "False");
    //        break;
    //}
    //destroy_expression(current_expression);
    expr_value_t val;
    evaluate_expression(current_expression);
    pop_output(current_expression, &val);

    EXPR_PRINT_VALUE(&val);
    MSG("EVALUATING EXPRESSION ENDED");
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
