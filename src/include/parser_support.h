#ifndef _PARSER_SUPPORT_H_
#  define _PARSER_SUPPORT_H_

/*
 *  This header has the various includes, macros, and definitions that provide
 *  access to the implementation of the parser support. There are quite a few
 *  files and this header binds them together.
 */

#  include <stdint.h>

typedef struct literal_num {
    int vtype;
    union {
        uint64_t unum;
        int64_t inum;
        double fnum;
    } value;
} literal_num_t;

//#include "module_rules.h"
void module_module_list_end(void);
void module_item_import_definition_end(void);
void module_item_class_definition_end(void);
void module_list_module_item_end(void);

//#include "literal_value_rules.h"
void complex_name_init_symbol(void);
void complex_name_add_symbol(void);
char *get_complex_name(void);
void save_intrinsic_type(int);
int get_intrinsic_type(void);
void intrinsic_type_create_complex_name(void);
char *get_complex_name_intrinsic_type(void);
void save_data_attr(int);
void data_attrs_list_init(void);
void data_attrs_list_add(void);
int *get_data_attrs_list(int *);
void save_literal_num(int type);
literal_num_t *get_literal_num(void);
void formatted_string_param_qstrg(void);
void formatted_string_param_expression(void);
void formatted_string_param_list_init(void);
void formatted_string_param_list_add(void);
void formatted_string_no_format(void);
void formatted_string_with_format(void);
void formatted_string_with_init_parameters_start(void);
void formatted_string_with_init_parameters_finish(void);
void bool_value_create_true(void);
void bool_value_create_false(void);

//#include "import_rules.h"
void import_definition_create(void);
void import_definition_finish(void);
void import_definition_alias_to_symbol(void);

//#include "class_def_rules.h"
void class_parm_add_private(void);
void class_parm_add_public(void);
void class_parm_add_protected(void);
void class_parm_list_create(void);
void class_parm_list_add(void);
void class_parm_list_blank(void);
void class_body_item_data_definition_finish(void);
void class_body_item_method_definition_finish(void);
void class_body_item_constructor_definition_finish(void);
void class_body_item_destructor_definition_finish(void);
void class_body_item_add(void);
void class_definiton_create(void);
void class_definiton_attrs_finish(void);
void class_definiton_add_name(void);
void class_definiton_param_list_start(void);
void class_definiton_param_list_finish(void);
void class_definiton_body_start(void);
void class_definiton_body_finish(void);

//#include "data_def_rules.h"
void class_data_definition_with_data_attrs(void);
void class_data_definition_add_data_attrs(void);
void class_data_definition_name(void);
void class_data_definition_finish(void);
void class_data_definition_no_data_attrs(void);
void function_data_definition_target_nothing(void);
void function_data_definition_target_expression(void);
void function_data_definition_target_cast(void);
void function_data_definition_target_formatted_string(void);
void function_data_definition_symbol(void);
void function_data_definition_const_symbol(void);
void function_data_definition_no_initializer(void);
void function_data_definition_with_initializer(void);
void function_data_definition_with_initializer_finish(void);

//#include "function_def_rules.h"
void method_def_param_intrinsic_type(void);
void method_def_param_symbol(void);
void method_def_param_list_method_def_param_create(void);
void method_def_param_list_method_def_param_add(void);
void method_param_def_finish(void);
void method_param_def_blank(void);
void method_definition_with_attrs_start(void);
void method_definition_attrs_finish(void);
void method_definition_no_attrs_start(void);
void method_definition_symbol(void);
void method_definition_input_params_start(void);
void method_definition_input_params_finish(void);
void method_definition_output_params_start(void);
void method_definition_output_params_finish(void);
void method_definition_method_body_start(void);
void method_definition_method_body_finish(void);
void method_body_element_data_definition_finish(void);
void method_body_element_try_finish(void);
void method_body_element_raise_finish(void);
void method_body_element_function_call_finish(void);
void method_body_element_for_finish(void);
void method_body_element_if_finish(void);
void method_body_element_while_finish(void);
void method_body_element_do_finish(void);
void method_body_element_switch_finish(void);
void method_body_element_inc_finish(void);
void method_body_element_assignment_finish(void);
void method_body_element_list_finish(void);
void method_body_element_start(void);
void method_body_element_finish(void);
void method_body_finish(void);
void method_body_blank(void);
void constructor_definition_start(void);
void constructor_definition_param_start(void);
void constructor_definition_param_finish(void);
void constructor_definition_body_start(void);
void constructor_definition_body_finish(void);
void destructor_definition_body_start(void);
void destructor_definition_body_finish(void);

//#include "expression_def_rules.h"
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

//#include "function_call_rules.h"
void function_call_parameter_formatted_string(void);
void function_call_parameter_expression(void);
void function_call_parameter_list_create(void);
void function_call_parameter_list_add(void);
void function_call_complex_name(void);
void function_call_input_parameter_start(void);
void function_call_input_parameter_finish(void);
void function_call_output_parameter_start(void);
void function_call_output_parameter_finish(void);
void function_call_finish(void);
void function_call_destroy_complex_name(void);
void function_call_destroy_finish(void);

//#include "common_branch_rules.h"
void branch_expression_expression(void);
void branch_expression_bool_value(void);
void jump_clause_continue(void);
void jump_clause_break(void);
void post_inc_complex_name(void);
void post_inc_finish(void);
void post_dec_complex_name(void);
void post_dec_finish(void);
void pre_inc_start(void);
void pre_inc_complex_name(void);
void pre_dec_start(void);
void pre_dec_complex_name(void);
void loop_body_element_method_body_element(void);
void loop_body_element_jump_clause_element(void);
void loop_body_element_list_init(void);
void loop_body_element_list_add(void);
void loop_body_element_empty(void);
void loop_body_element_start(void);
void loop_body_element_finish(void);
void loop_body_finish(void);

//#include "for_loop_rules.h"
void for_initialize_assign_nothing(void);
void for_initialize_assign_expression(void);
void for_initialize_assign_bool_value(void);
void for_initialize_intrinsic_type(void);
void for_initialize_symbol(void);
void for_initialize_data_definition_finish(void);
void for_initialize_assignment(void);
void for_initialize_assignment_finish(void);
void for_test_expression(void);
void for_test_expression_finish(void);
void for_arith_expression_expression(void);
void for_arith_expression_pre_post_inc(void);
void for_arith_expression_assignment(void);
void for_clause_definition_init(void);
void for_clause_definition_finish(void);
void for_clause_loop_body_finish(void);

//#include "if_else_rules.h"
void else_clause_experssion_start(void);
void else_clause_experssion_finish(void);
void else_clause_no_expression(void);
void else_body_else_clause_init(void);
void else_body_else_clause_add(void);
void else_clause_method_body_finish(void);
void if_clause_expression_start(void);
void if_clause_expression_finish(void);
void if_clause_else_body_finish(void);

//#include "while_rules.h"
void while_clause_experssion_start(void);
void while_clause_expression_finish(void);
void while_clause_loop_body_finish(void);
void do_clause_loop_body_start(void);
void do_clause_loop_body_finish(void);
void do_clause_expression_start(void);
void do_clause_expression_finish(void);
void do_clause_finish(void);

//#include "except_rules.h"
void except_parameter_formatted_string(void);
void except_parameter_complex_name(void);
void except_parameter_list_init(void);
void except_parameter_list_add(void);
void except_clause_parameter_list_start(void);
void except_clause_parameter_list_finish(void);
void except_clause_method_body_finish(void);
void except_clause_complex_name(void);
void final_clause_start(void);
void final_clause_finish(void);
void try_clause_intro_start(void);
void try_clause_intro_finish(void);
void try_clause_finish(void);
void raise_clause_parameter_start(void);
void raise_clause_parameter_finish(void);
void raise_clause_finish(void);

//#include "switch_case_rules.h"
void case_clause_unum(void);
void case_clause_inum(void);
void case_clause_fnum(void);
void case_clause_loop_body_finish(void);
void default_case(void);
void case_body_init(void);
void case_body_add(void);
void switch_clause_intro_expression_start(void);
void switch_clause_intro_expression_finish(void);
void switch_clause_intro_case_body_start(void);
void switch_clause_intro_case_body_finish(void);
void switch_clause_after_intro(void);
void switch_clause_after_intro_default(void);
void switch_clause_finish(void);

//#include "assignment_rules.h"
void type_cast_type(void);
void type_cast_type_finish(void);
void assignment_target_expression(void);
void assignment_target_formatted_string(void);
void assignment_target_type_cast_expression(void);
void assignment_target_nothing(void);
void assignment_target_bool_value(void);
void assignment_complex_name(void);
void assignment_target_finish(void);

#endif /* _PARSER_SUPPORT_H_ */
