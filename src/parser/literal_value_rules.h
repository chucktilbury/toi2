#ifndef _LITERAL_VALUES_RULES_H_
#  define _LITERAL_VALUES_RULES_H_

void complex_name_init_symbol(void);
void complex_name_add_symbol(void);
void intrinsic_type_create_dict(void);
void intrinsic_type_create_array(void);
void intrinsic_type_create_bool(void);
void intrinsic_type_create_string(void);
void intrinsic_type_create_float(void);
void intrinsic_type_create_int64(void);
void intrinsic_type_create_int8(void);
void intrinsic_type_create_int16(void);
void intrinsic_type_create_int32(void);
void intrinsic_type_create_uint64(void);
void intrinsic_type_create_uint8(void);
void intrinsic_type_create_uint16(void);
void intrinsic_type_create_uint32(void);
void intrinsic_type_create_complex_name(void);
void data_attrs_add_private(void);
void data_attrs_add_public(void);
void data_attrs_add_protected(void);
void data_attrs_add_const(void);
void data_attrs_add_static(void);
void data_attrs_list_init(void);
void data_attrs_list_add(void);
void number_create_literal_unum(void);
void number_create_literal_inum(void);
void number_create_literal_fnum(void);
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

#endif /* _LITERAL_VALUES_RULES_H_ */
