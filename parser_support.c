#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include "errors.h"
#include "ast_tree.h"
#include "scanner.h"

/*
 * This file contains mostly stubbs used to sprinkle the parser with code that implements the symantic analysis. 
 */

/*
 * Import a file. The infrastructure behind this first finds the file, then opens a node for it and the parser continues from there until the file
 * has been completely added to the AST. Then the node is closed and parsing continues from where it was interrupted. 
 */
void do_import(void) {
    DEBSTR(get_tok_str());
}

void do_set_import_name(void) {
    DEBSTR(get_tok_str());
}

void do_import_end(void) {
    DEBUG();
}

static char complex_name_buffer[1024 * 64];
void do_init_complex_name(void) {
    memset(complex_name_buffer, 0, sizeof(complex_name_buffer));
    strcpy(complex_name_buffer, get_tok_str());
    DEBSTR(get_tok_str());
}

void do_add_complex_name(void) {
    strcat(complex_name_buffer, ".");
    strcat(complex_name_buffer, get_tok_str());
    DEBSTR(get_tok_str());
}

const char *do_get_complex_name(void) {
    DEBSTR(complex_name_buffer)
        return complex_name_buffer;
}

/*
 * When an intrinsic type is seen, a data definition follows. Set the parser state accordingly. 
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
 * When these functions are entered, a class definition is in progress. The state should have already been set. 
 */
void do_private_class_parm(void) {
    DEBSTR(get_tok_str());
}

void do_public_class_parm(void) {
    DEBSTR(get_tok_str());
}

void do_protected_class_parm(void) {
    DEBSTR(get_tok_str());
}

/*
 * Data attributes. Make a list of attributes so that they can be set when the AST node is created. 
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
 * Class data definitions. When the symbol is read the definition is complete. 
 */
void do_class_data_definition_type(void) {
    DEBUG();
}

void do_class_data_definition_attrs(void) {
    DEBUG();
}

void do_class_data_definition_symbol(void) {
    DEBSTR(get_tok_str());
}

void do_class_data_definition_end(void) {
    DEBUG();
}

/*
 * Method parameters. These could be input parameters or output parameters. 
 */
void do_method_define_param_type(void) {
    DEBUG();
}

void do_method_define_param_symbol(void) {
    DEBUG();
}

/*
 * Read and store a literal number. 
 */
void do_literal_number_unsigned(void) {
    DEBSTR(get_tok_str());
}

void do_literal_number_signed(void) {
    DEBSTR(get_tok_str());
}

void do_literal_number_float(void) {
    DEBSTR(get_tok_str());
}

/*
 * Store the parameters for a formatted string call. 
 */
void do_formatted_string_param_qstrg(void) {
    DEBSTR(get_tok_str());
}

void do_formatted_string_param_expression(void) {
    DEBUG();
}

/*
 * Support Python style formatted strings as a part of the language. 
 */
void do_formatted_string_without_format(void) {
    DEBSTR(get_tok_str());
}

void do_formatted_string_with_format(void) {
    DEBSTR(get_tok_str());
}

void do_formatted_string_parm_begin(void) {
    DEBUG();
}

void do_formatted_string_parm_end(void) {
    DEBUG();
}

/*
 * Read and store a subscript index, for both an array or a dictionary. Multiple subscripts are supported and each one gets its own node. 
 */
void do_subscript_item_start(void) {
    DEBUG();
}

void do_subscript_item_expression(void) {
    DEBUG();
}

void do_subscript_item_formatted_string(void) {
    DEBUG();
}

void do_subscript_item_finish(void) {
    DEBUG();
}

/*
 * Expression names are special in that they are part of an expression. A intermediate value is stored in the node to speed the resolution of an
 * expression at runtime. 
 */

void do_expression_name(void) {
    DEBSTR(get_tok_str());
}

void do_expression_name_with_subscript(void) {
    DEBSTR(get_tok_str());
}

void do_expression_name_subscript_finish(void) {
    DEBUG();
}

void do_expression_number(void) {
    DEBUG();
}

/*
 * Expression operator nodes. 
 */
void do_expression_addition(void) {
    DEBUG();
}

void do_expression_subtraction(void) {
    DEBUG();
}

void do_expression_division(void) {
    DEBUG();
}

void do_expression_multiplication(void) {
    DEBUG();
}

void do_expression_modulo(void) {
    DEBUG();
}

void do_expression_comaprison_and(void) {
    DEBUG();
}

void do_expression_comaprison_or(void) {
    DEBUG();
}

void do_expression_comaprison_less_than(void) {
    DEBUG();
}

void do_expression_comaprison_greater_than(void) {
    DEBUG();
}

void do_expression_comaprison_equal(void) {
    DEBUG();
}

void do_expression_comaprison_not_equal(void) {
    DEBUG();
}

void do_expression_comaprison_less_than_or_equal(void) {
    DEBUG();
}

void do_expression_comaprison_greater_than_or_equal(void) {
    DEBUG();
}

void do_expression_bitwise_and(void) {
    DEBUG();
}

void do_expression_bitwise_or(void) {
    DEBUG();
}

void do_expression_bitwise_exclusive_or(void) {
    DEBUG();
}

void do_expression_bitwise_rotate_left(void) {
    DEBUG();
}

void do_expression_bitwise_rotate_right(void) {
    DEBUG();
}

void do_expression_bitwise_shift_left(void) {
    DEBUG();
}

void do_expression_bitwise_shift_right(void) {
    DEBUG();
}

void do_expression_unary_negate(void) {
    DEBUG();
}

void do_expression_unary_not(void) {
    DEBUG();
}

void do_expression_unary_bitwise_not(void) {
    DEBUG();
}

void do_expression_open_paren(void) {
    DEBUG();
}

void do_expression_close_paren(void) {
    DEBUG();
}

/*
 * Data definition inside a method. 
 */
void do_function_data_definition_target_nothing(void) {
    DEBUG();
}

void do_function_data_definition_target_type_cast(void) {
    DEBUG();
}

void do_function_data_definition_target_expression(void) {
    DEBUG();
}

void do_function_data_definition_target_string(void) {
    DEBUG();
}

/*
 * Data definition with assignment inside a function. 
 */
void do_function_data_definition_type(void) {
    DEBUG();
}

void do_function_data_definition_symbol(void) {
    DEBSTR(get_tok_str());
}

void do_function_data_definition_const_symbol(void) {
    DEBSTR(get_tok_str());
}

void do_function_data_definition_expr_start(void) {
    DEBUG();
}

void do_function_data_definition_expr_finish(void) {
    DEBUG();
}
