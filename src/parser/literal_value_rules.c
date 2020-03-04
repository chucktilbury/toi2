#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "errors.h"
#include "scanner.h"
#include "parser.h"
#include "parser_support.h"

#define MAX_NAME (1024*64)

static int data_attrs_list[10];
static int data_attrs_list_idx = 0;
static int last_data_attr = 0;
static char complex_name[MAX_NAME];
static char complex_name_as_intrinsic_type[MAX_NAME];
static int last_intrinsic_type;

void complex_name_init_symbol(void) {
    DEBUG();
    memset(complex_name, 0, sizeof(complex_name));
    strcpy(complex_name, get_tok_str());
}

void complex_name_add_symbol(void) {
    DEBUG();
    strcat(complex_name, ".");
    strcat(complex_name, get_tok_str());
}

char *get_complex_name(void) {
    DEBUG();
    return complex_name;
}

void save_intrinsic_type(int type) {
    DEBUG();
    last_intrinsic_type = type;
}

int get_intrinsic_type(void) {
    DEBUG();
    return last_intrinsic_type;
}

void intrinsic_type_create_complex_name(void) {
    DEBUG();
    memset(complex_name, 0, sizeof(complex_name));
    strcpy(complex_name_as_intrinsic_type, complex_name);
}

char *get_complex_name_intrinsic_type(void) {
    DEBUG();
    return complex_name_as_intrinsic_type;
}

void save_data_attr(int attr) {
    DEBUG();
    last_data_attr = attr;
}

int get_data_attr(void) {
    DEBUG();
    return last_data_attr;
}

void data_attrs_list_init(void) {
    DEBUG();
    memset(data_attrs_list, 0, sizeof(data_attrs_list));
    data_attrs_list_idx = 0;
    data_attrs_list[data_attrs_list_idx] = get_data_attr();
    data_attrs_list_idx++;
}

void data_attrs_list_add(void) {
    DEBUG();
    data_attrs_list[data_attrs_list_idx] = get_data_attr();
    data_attrs_list_idx++;
}

int *get_data_attrs_list(int *nattrs) {
    DEBUG();
    *nattrs = data_attrs_list_idx;
    return data_attrs_list;
}

void number_create_literal_unum(void) {
    DEBUG();
}

void number_create_literal_inum(void) {
    DEBUG();
}

void number_create_literal_fnum(void) {
    DEBUG();
}

void formatted_string_param_qstrg(void) {
    DEBUG();
}

void formatted_string_param_expression(void) {
    DEBUG();
}

void formatted_string_param_list_init(void) {
    DEBUG();
}

void formatted_string_param_list_add(void) {
    DEBUG();
}

void formatted_string_no_format(void) {
    DEBUG();
}

void formatted_string_with_format(void) {
    DEBUG();
}

void formatted_string_with_init_parameters_start(void) {
    DEBUG();
}

void formatted_string_with_init_parameters_finish(void) {
    DEBUG();
}

void bool_value_create_true(void) {
    DEBUG();
}

void bool_value_create_false(void) {
    DEBUG();
}

