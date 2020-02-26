#ifndef _PARSER_SUPPORT_H_
#define _PARSER_SUPPORT_H_

void do_import(const char *);
void do_set_import_name(const char *);
void do_import_definition_finish(void);
void do_class_definition_finish(void);
void do_module_statement_finish(void);

void do_init_complex_name(const char *);
void do_add_complex_name(const char *);
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

void do_method_define_param_type(void);
void do_method_define_param_symbol(void);

void do_literal_number_unsigned(void);
void do_literal_number_signed(void);
void do_literal_number_float(void);

void do_formatted_string_without_format(void);
void do_formatted_string_with_format(void);
void do_formatted_string_parm_begin(void);
void do_formatted_string_parm_end(void);

#endif /* _PARSER_SUPPORT_H_ */