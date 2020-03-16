#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "scanner.h"
#include "parser.h"
#include "parser_support.h"
#include "utils.h"
#include "expressions.h"

#define MAX_NAME (1024*64)

static int data_attrs_list[10];
static int data_attrs_list_idx = 0;
static int last_data_attr = 0;
static char complex_name[MAX_NAME];
static char complex_name_as_intrinsic_type[MAX_NAME];
static int last_intrinsic_type;
static literal_num_t literal_num;

void complex_name_init_symbol(void) {
    MARK();
    memset(complex_name, 0, sizeof(complex_name));
    strcpy(complex_name, get_tok_str());
}

void complex_name_add_symbol(void) {
    MARK();
    strcat(complex_name, ".");
    strcat(complex_name, get_tok_str());
}

char *get_complex_name(void) {
    MARK();
    return complex_name;
}

void save_intrinsic_type(int type) {
    MARK();
    last_intrinsic_type = type;
}

int get_intrinsic_type(void) {
    MARK();
    return last_intrinsic_type;
}

void intrinsic_type_create_complex_name(void) {
    MARK();
    memset(complex_name, 0, sizeof(complex_name));
    strcpy(complex_name_as_intrinsic_type, complex_name);
}

char *get_complex_name_intrinsic_type(void) {
    MARK();
    return complex_name_as_intrinsic_type;
}

void save_data_attr(int attr) {
    MARK();
    last_data_attr = attr;
}

int get_data_attr(void) {
    MARK();
    return last_data_attr;
}

void data_attrs_list_init(void) {
    MARK();
    memset(data_attrs_list, 0, sizeof(data_attrs_list));
    data_attrs_list_idx = 0;
    data_attrs_list[data_attrs_list_idx] = get_data_attr();
    data_attrs_list_idx++;
}

void data_attrs_list_add(void) {
    MARK();
    data_attrs_list[data_attrs_list_idx] = get_data_attr();
    data_attrs_list_idx++;
}

int *get_data_attrs_list(int *nattrs) {
    MARK();
    *nattrs = data_attrs_list_idx;
    return data_attrs_list;
}

extern expression_t *current_expression;
void save_literal_num(int type) {
    MARK();
    literal_num.vtype = type;
    switch (type) {
        case UNUM:
            {
                const char *str = get_tok_str();
                literal_num.value.unum = (uint64_t) strtoul(str, NULL, 16);
                MSG("storing UNUM value %lu (%s)", literal_num.value.unum, str);
                // uint64_t val = (uint64_t)strtoul(get_tok_str(), NULL, 16);
                // store_expr_value(current_expression, EXPR_VAL_UNUM,
                // (void*)&val);
            }
            break;
        case INUM:
            {
                const char *str = get_tok_str();
                literal_num.value.inum = (int64_t) strtol(str, NULL, 10);
                MSG("storing INUM value %ld (%s)", literal_num.value.inum, str);
                // int64_t val = (int64_t)strtol(get_tok_str(), NULL, 10);
                // store_expr_value(current_expression, EXPR_VAL_INUM,
                // (void*)&val);
            }
            break;
        case FNUM:
            {
                literal_num.value.fnum = strtod(get_tok_str(), NULL);
                MSG("storing UNUM value %f", literal_num.value.fnum);
                // double val = strtod(get_tok_str(), NULL);
                // store_expr_value(current_expression, EXPR_VAL_FNUM,
                // (void*)&val);
            }
            break;
        default:
            fatal_error("Save unknown literal number type: %d", type);
    }
}

literal_num_t *get_literal_num(void) {
    MARK();
    // void *retv;

    // *type = literal_num.type;
    // switch (literal_num.type) {
    // case UNUM:
    // retv = (void *)&literal_num.value.unum;
    // break;
    // case INUM:
    // retv = (void *)&literal_num.value.inum;
    // break;
    // case FNUM:
    // retv = (void *)&literal_num.value.fnum;
    // break;
    // default:
    // fatal_error("Get unknown literal number type: %d", literal_num.type);
    // }
    // return retv;
    return &literal_num;
}

void formatted_string_param_qstrg(void) {
    MARK();
}

void formatted_string_param_expression(void) {
    MARK();
}

void formatted_string_param_list_init(void) {
    MARK();
}

void formatted_string_param_list_add(void) {
    MARK();
}

void formatted_string_no_format(void) {
    MARK();
}

void formatted_string_with_format(void) {
    MARK();
}

void formatted_string_with_init_parameters_start(void) {
    MARK();
}

void formatted_string_with_init_parameters_finish(void) {
    MARK();
}

void bool_value_create_true(void) {
    MARK();
}

void bool_value_create_false(void) {
    MARK();
}
