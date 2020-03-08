#ifndef _LITERAL_VALUES_RULES_H_
#  define _LITERAL_VALUES_RULES_H_

typedef struct literal_num {
    int type;
    union {
        unsigned long long unum;
        long long inum;
        double fnum;
    } value;
} literal_num_t;

/*
 * These are stub functions that are called from the parser. 
 */
void complex_name_init_symbol(void);
void complex_name_add_symbol(void);
char *get_complex_name(void);

void save_intrinsic_type(int);
int get_intrinsic_type(void);

void intrinsic_type_create_complex_name(void);
char *get_complex_name_intrinsic_type(void);

void save_data_attr(int);

// int get_data_attr(void);
void data_attrs_list_init(void);
void data_attrs_list_add(void);
int *get_data_attrs_list(int *);

// void data_attrs_add_private(void);
// void data_attrs_add_public(void);
// void data_attrs_add_protected(void);
// void data_attrs_add_const(void);
// void data_attrs_add_static(void);

// void number_create_literal_unum(void);
// void number_create_literal_inum(void);
// void number_create_literal_fnum(void);

void save_literal_num(int type);
void *get_literal_num(int *type);

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

/*
 * These functions are not in the parser. They are called by other parts of the parser support. 
 */

#endif /* _LITERAL_VALUES_RULES_H_ */
