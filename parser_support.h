#ifndef _PARSER_SUPPORT_H_
#  define _PARSER_SUPPORT_H_

void do_import(void);
void do_set_import_name(void);
void do_import_end(void);

void do_init_complex_name(void);
void do_add_complex_name(void);
const char *do_get_complex_name(void);

void do_intrinsic_type_dict(void);
void do_intrinsic_type_array(void);
void do_intrinsic_type_bool(void);
void do_intrinsic_type_string(void);
void do_intrinsic_type_float(void);
void do_intrinsic_type_int8(void);
void do_intrinsic_type_int16(void);
void do_intrinsic_type_int32(void);
void do_intrinsic_type_int64(void);
void do_intrinsic_type_uint8(void);
void do_intrinsic_type_uint16(void);
void do_intrinsic_type_uint32(void);
void do_intrinsic_type_uint64(void);
void do_intrinsic_type_complex_name(void);

void do_private_class_parm(void);
void do_public_class_parm(void);
void do_protected_class_parm(void);

void do_set_private_data_attribute(void);
void do_set_public_data_attribute(void);
void do_set_protected_data_attribute(void);
void do_set_const_data_attribute(void);
void do_set_static_data_attribute(void);

void do_class_data_definition_type(void);
void do_class_data_definition_attrs(void);
void do_class_data_definition_symbol(void);
void do_class_data_definition_end(void);

void do_method_define_param_type(void);
void do_method_define_param_symbol(void);

void do_literal_number_unsigned(void);
void do_literal_number_signed(void);
void do_literal_number_float(void);

void do_formatted_string_param_qstrg(void);
void do_formatted_string_param_expression(void);

void do_formatted_string_without_format(void);
void do_formatted_string_with_format(void);
void do_formatted_string_parm_begin(void);
void do_formatted_string_parm_end(void);

void do_subscript_item_start(void);
void do_subscript_item_expression(void);
void do_subscript_item_formatted_string(void);
void do_subscript_item_finish(void);

void do_expression_name(void);
void do_expression_name_with_subscript(void);
void do_expression_name_subscript_finish(void);
void do_expression_number(void);

void do_expression_addition(void);
void do_expression_subtraction(void);
void do_expression_division(void);
void do_expression_multiplication(void);
void do_expression_modulo(void);
void do_expression_comaprison_and(void);
void do_expression_comaprison_or(void);
void do_expression_comaprison_less_than(void);
void do_expression_comaprison_greater_than(void);
void do_expression_comaprison_equal(void);
void do_expression_comaprison_not_equal(void);
void do_expression_comaprison_less_than_or_equal(void);
void do_expression_comaprison_greater_than_or_equal(void);
void do_expression_bitwise_and(void);
void do_expression_bitwise_or(void);
void do_expression_bitwise_exclusive_or(void);
void do_expression_bitwise_rotate_left(void);
void do_expression_bitwise_rotate_right(void);
void do_expression_bitwise_shift_left(void);
void do_expression_bitwise_shift_right(void);
void do_expression_unary_negate(void);
void do_expression_unary_not(void);
void do_expression_unary_bitwise_not(void);
void do_expression_open_paren(void);
void do_expression_close_paren(void);

void do_function_data_definition_target_nothing(void);
void do_function_data_definition_target_type_cast(void);
void do_function_data_definition_target_expression(void);
void do_function_data_definition_target_string(void);

void do_function_data_definition_type(void);
void do_function_data_definition_symbol(void);
void do_function_data_definition_const_symbol(void);
void do_function_data_definition_expr_start(void);
void do_function_data_definition_expr_finish(void);

#endif /* _PARSER_SUPPORT_H_ */
