#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include "errors.h"
#include "ast_tree.h"
#include "scanner.h"

/*
    This file contains mostly stubbs used to sprinkle the parser with code
    that implements the symantic analysis.
*/

/*
    Import a file. The infrastructure behind this first finds the file, then
    opens a node for it and the parser continues from there until the file
    has been completely added to the AST. Then the node is closed and parsing
    continues from where it was interrupted.
*/
void do_import(const char *str) {
    DEBSTR(str);
}

void do_set_import_name(const char *str) {
    DEBSTR(str);
}

void do_import_definition_finish(void) {
    DEBUG();
}

void do_class_definition_finish(void) {
    DEBUG();
}

void do_module_statement_finish(void) {
    DEBUG();
}

static char complex_name_buffer[1024*64];
void do_init_complex_name(const char *str) {
    memset(complex_name_buffer, 0, sizeof(complex_name_buffer));
    strcpy(complex_name_buffer, str);
    DEBSTR(str);
}

void do_add_complex_name(const char *str) {
    strcat(complex_name_buffer, ".");
    strcat(complex_name_buffer, str);
    DEBSTR(str);
}

const char *do_get_complex_name(void) {
    DEBSTR(complex_name_buffer)
    return complex_name_buffer;
}

/*
    When an intrinsic type is seen, a data definition follows. Set the
    parser state accordingly.
*/
void do_intrinsic_type_dict(void) {
    DEBUG();
}

void do_intrinsic_type_array(void) {
    DEBUG();
}

void do_intrinsic_type_bool(void) {
    DEBUG();
}

void do_intrinsic_type_string(void) {
    DEBUG();
}

void do_intrinsic_type_float(void) {
    DEBUG();
}

void do_intrinsic_type_int8(void) {
    DEBUG();
}

void do_intrinsic_type_int16(void) {
    DEBUG();
}

void do_intrinsic_type_int32(void) {
    DEBUG();
}

void do_intrinsic_type_int64(void) {
    DEBUG();
}

void do_intrinsic_type_uint8(void) {
    DEBUG();
}

void do_intrinsic_type_uint16(void) {
    DEBUG();
}

void do_intrinsic_type_uint32(void) {
    DEBUG();
}

void do_intrinsic_type_uint64(void) {
    DEBUG();
}

void do_intrinsic_type_complex_name(void) {
    DEBSTR(complex_name_buffer);
}

/*
    When these functions are entered, a class definition is in progress.
    The state should have already been set.
*/
void do_private_class_parm(void) {
    DEBSTR(complex_name_buffer);
}

void do_public_class_parm(void) {
    DEBSTR(complex_name_buffer);
}

void do_protected_class_parm(void) {
    DEBSTR(complex_name_buffer);
}

/*
    Data attributes. Make a list of attributes so that they can be set when
    the AST node is created.
*/
void do_set_private_data_attribute(void) {
    DEBUG();
}

void do_set_public_data_attribute(void) {
    DEBUG();
}

void do_set_protected_data_attribute(void) {
    DEBUG();
}

void do_set_const_data_attribute(void) {
    DEBUG();
}

void do_set_static_data_attribute(void) {
    DEBUG();
}

/*
    Class data definitions. When the symbol is read the definition is complete.
*/
void do_class_data_definition_type(void) {
    DEBUG();
}

void do_class_data_definition_attrs(void) {
    DEBUG();
}

void do_class_data_definition_symbol(void) {
    DEBUG();
}

/*
    Method parameters. These could be input parameters or output parameters.
*/
void do_method_define_param_type(void) {
    DEBUG();
}

void do_method_define_param_symbol(void) {
    DEBUG();
}


/*
    Read and store a literal number.
*/
void do_literal_number_unsigned(void) {
    DEBUG();
}

void do_literal_number_signed(void) {
    DEBUG();
}

void do_literal_number_float(void) {
    DEBUG();
}

/*
    Support Python style formatted strings as a part of the language.
*/
void do_formatted_string_without_format(void) {
    DEBSTR(complex_name_buffer);
}

void do_formatted_string_with_format(void) {
    DEBSTR(complex_name_buffer);
}

void do_formatted_string_parm_begin(void) {
    DEBUG();
}

void do_formatted_string_parm_end(void) {
    DEBUG();
}


