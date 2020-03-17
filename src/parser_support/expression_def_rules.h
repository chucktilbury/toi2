#ifndef _EXPRESSION_DEF_RULES_H_
#  define _EXPRESSION_DEF_RULES_H_

void subscript_item_expression_start(void);
void subscript_item_expression_finish(void);
void subscript_item_formatted_string_start(void);
void subscript_item_formatted_string_finish(void);
void subscript_list_init(void);
void subscript_list_add(void);
void expression_name_complex_name(void);
void expression_name_complex_name_with_subscript(void);
void expression_name_subscript_list_finish(void);
void expression_literal_number(void);
void expression_expression_name(void);
void expression_addition_operation(void);
void expression_subtraction_operation(void);
void expression_division_operation(void);
void expression_multiplication_operation(void);
void expression_modulo_operation(void);
void expression_and_boolean_operation(void);
void expression_or_boolean_operation(void);
void expression_less_boolean_operation(void);
void expression_greater_boolean_operation(void);
void expression_equal_boolean_operation(void);
void expression_not_equal_boolean_operation(void);
void expression_less_or_equal_boolean_operation(void);
void expression_greater_or_equal_boolean_operation(void);
void expression_and_bitwise_operation(void);
void expression_or_bitwise_operation(void);
void expression_xor_bitwise_operation(void);
void expression_rotate_left_bitwise_operation(void);
void expression_rotate_right_bitwise_operation(void);
void expression_shift_left_bitwise_operation(void);
void expression_shift_right_bitwise_operation(void);
void expression_unary_negate_operation(void);
void expression_unary_not_boolean_operation(void);
void expression_not_bitwise_operation(void);
void expression_start(void);
void expression_finish(void);

#endif /* _EXPRESSION_DEF_RULES_H_ */
