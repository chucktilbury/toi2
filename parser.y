%debug
%defines
%locations

%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "scanner.h"
#include "errors.h"
#include "parser_support.h"

#define TOKSTR get_tok_str()

%}
%define parse.error verbose
%locations

%token SYMBOL UNUM FNUM INUM QSTRG CLASS METHOD
%token CREATE DESTROY NOTHING IMPORT PUBLIC PRIVATE
%token PROTECTED STATIC CONST DICT ARRAY BOOL AS
%token STRING FLOAT INT INT8 INT16 INT32 INT64
%token UINT UINT8 UINT16 UINT32 UINT64 IF TRUE
%token ELSE WHILE DO TRY EXCEPT RAISE FOR FALSE
%token SWITCH CASE BREAK CONTINUE AND OR DEFAULT
%token NOT EQU NEQU LTEQU GTEQU BSHL BSHR BROL
%token BROR INC DEC FINAL

%left AND OR
%left '&' '|' '^'
%left EQU NEQU
%left '<' '>'  LTEQU GTEQU
%left BROL BROR BSHL BSHR
%left '+' '-'
%left '*' '/' '%'
%left NEG
%right NOT '~'

%%

module
    : module_list
    ;

module_list
    : module_item
    | module module_item
    ;

module_item
    : import_definition
    | class_definition
    ;

complex_name
    : SYMBOL {
        do_init_complex_name();
    }
    | complex_name '.' SYMBOL {
        do_add_complex_name();
    }
    ;

intrinsic_type
    : DICT {
        do_intrinsic_type_dict();
    }
    | ARRAY {
        do_intrinsic_type_array();
    }
    | BOOL {
        do_intrinsic_type_bool();
    }
    | STRING {
        do_intrinsic_type_string();
    }
    | FLOAT {
        do_intrinsic_type_float();
    }
    | INT {
        do_intrinsic_type_int64();
    }
    | INT8 {
        do_intrinsic_type_int8();
    }
    | INT16 {
        do_intrinsic_type_int16();
    }
    | INT32 {
        do_intrinsic_type_int32();
    }
    | INT64 {
        do_intrinsic_type_int64();
    }
    | UINT {
        do_intrinsic_type_uint64();
    }
    | UINT8 {
        do_intrinsic_type_uint8();
    }
    | UINT16 {
        do_intrinsic_type_uint16();
    }
    | UINT32 {
        do_intrinsic_type_uint32();
    }
    | UINT64 {
        do_intrinsic_type_uint64();
    }
    | complex_name {
        do_intrinsic_type_complex_name();
    }
    ;

import_definition
    : IMPORT SYMBOL {
        do_import();
    } ';' {
        do_import_end();
    }
    | IMPORT SYMBOL {
        do_import();
    } AS SYMBOL {
        do_set_import_name();
    } ';' {
        do_import_end();
    }
    ;

class_parm
    : PRIVATE complex_name {
        do_private_class_parm();
    }
    | PUBLIC complex_name {
        do_public_class_parm();
    }
    | PROTECTED complex_name {
        do_protected_class_parm();
    }
    | complex_name {
        do_private_class_parm();
    }
    ;

class_parm_list
    : class_parm
    | class_parm_list ',' class_parm
    |  /* blank */
    ;

data_attrs
    : PRIVATE {
        do_set_private_data_attribute();
    }
    | PUBLIC {
        do_set_public_data_attribute();
    }
    | PROTECTED {
        do_set_protected_data_attribute();
    }
    | CONST {
        do_set_const_data_attribute();
    }
    | STATIC {
        do_set_static_data_attribute();
    }
    ;

data_attrs_list
    : data_attrs
    | data_attrs_list data_attrs
    ;

class_data_definition
    : intrinsic_type {
        do_class_data_definition_type();
    } data_attrs_list {
        do_class_data_definition_attrs();
    } SYMBOL {
        do_class_data_definition_symbol();
    } ';' {
        do_class_data_definition_end();
    }
    | intrinsic_type {
        do_class_data_definition_type();
    } SYMBOL {
        do_class_data_definition_symbol();
    } ';' {
        do_class_data_definition_end();
    }
    ;

method_def_param
    : intrinsic_type {
        do_method_define_param_type();
    } SYMBOL {
        do_method_define_param_symbol();
    }
    ;

method_def_param_list
    : method_def_param
    | method_def_param_list ',' method_def_param
    ;

number
    : UNUM {
        do_literal_number_unsigned();
    }
    | INUM {
        do_literal_number_signed();
    }
    | FNUM {
        do_literal_number_float();
    }
    ;

formatted_string_param
    : QSTRG {
        do_formatted_string_param_qstrg();
    }
    | expression {
        do_formatted_string_param_expression();
    }
    ;

formatted_string_param_list
    : formatted_string_param
    | formatted_string_param_list ',' formatted_string_param
    ;

formatted_string
    : QSTRG {
        do_formatted_string_without_format();
    }
    | QSTRG {
        do_formatted_string_with_format();
    } '%' '(' {
        do_formatted_string_parm_begin();
    } formatted_string_param_list {
        do_formatted_string_parm_end();
    } ')'
    ;

subscript_item
    : '[' {
        do_subscript_item_start();
    } expression {
        do_subscript_item_expression();
    } ']' {
        do_subscript_item_finish();
    }
    | '[' {
        do_subscript_item_start();
    } formatted_string {
        do_subscript_item_formatted_string();
    } ']' {
        do_subscript_item_finish();
    }
    ;

subscript_list
    : subscript_item
    | subscript_list subscript_item

expression_name
    : complex_name {
        do_expression_name();
    }
    | complex_name {
        do_expression_name_with_subscript();
    } subscript_list {
        do_expression_name_subscript_finish();
    }
    ;

    /*
    * Expressions use the "switching yard" algorithm so they can be stored and
    * then evaluated at run time.
    */
expression
    : number {
        do_expression_number();
    }
    | expression_name {
        do_expression_name();
    }
    | expression '+' expression {
        do_expression_addition();
    }
    | expression '-' expression {
        do_expression_subtraction();
    }
    | expression '/' expression {
        do_expression_division();
    }
    | expression '*' expression {
        do_expression_multiplication();
    }
    | expression '%' expression {
        do_expression_modulo();
    }
    | expression AND expression {
        do_expression_comaprison_and();
    }
    | expression OR expression {
        do_expression_comaprison_or();
    }
    | expression '<' expression {
        do_expression_comaprison_less_than();
    }
    | expression '>' expression {
        do_expression_comaprison_greater_than();
    }
    | expression EQU expression {
        do_expression_comaprison_equal();
    }
    | expression NEQU expression {
        do_expression_comaprison_not_equal();
    }
    | expression LTEQU expression {
        do_expression_comaprison_less_than_or_equal();
    }
    | expression GTEQU expression {
        do_expression_comaprison_greater_than_or_equal();
    }
    | expression '&' expression {
        do_expression_bitwise_and();
    }
    | expression '|' expression {
        do_expression_bitwise_or();
    }
    | expression '^' expression {
        do_expression_bitwise_exclusive_or();
    }
    | expression BROL expression {
        do_expression_bitwise_rotate_left();
    }
    | expression BROR expression {
        do_expression_bitwise_rotate_right();
    }
    | expression BSHL expression {
        do_expression_bitwise_shift_left();
    }
    | expression BSHR expression {
        do_expression_bitwise_shift_right();
    }
    | '-' expression %prec NEG {
        do_expression_unary_negate();
    }
    | NOT expression {
        do_expression_unary_not();
    }
    | '~' expression {
        do_expression_unary_bitwise_not();
    }
    | '(' {
        do_expression_open_paren();
    } expression ')' {
        do_expression_close_paren();
    }
    ;

function_data_definition_target
    : NOTHING {
        do_function_data_definition_target_nothing();
    }
    | expression {
        do_function_data_definition_target_expression();
    }
    | type_cast {
        do_function_data_definition_target_type_cast();
    } expression {
        do_function_data_definition_target_expression();
    }
    | formatted_string {
        do_function_data_definition_target_string();
    }
    ;

function_data_definition_symbol
    : SYMBOL {
        do_function_data_definition_symbol();
    }
    | CONST SYMBOL {
        do_function_data_definition_const_symbol();
    }
    ;

    /*
        Note that due to conflicts, the intrionsic type needs to be determined and
        saved before this construct is called.
    */
function_data_definition
    : intrinsic_type function_data_definition_symbol ';' {
        do_function_data_definition_type();
    }
    | intrinsic_type function_data_definition_symbol '=' {
        do_function_data_definition_type();
        do_function_data_definition_expr_start();
    } function_data_definition_target ';' {
        do_function_data_definition_expr_finish();
    }
    ;

function_call_parameter
    : formatted_string
    | expression
    ;

function_call_parameter_list
    :
    | function_call_parameter
    | function_call_parameter_list ',' function_call_parameter
    ;

function_call
    : complex_name '(' function_call_parameter_list ')' '(' function_call_parameter_list ')' ';'
    | complex_name '.' CREATE '(' function_call_parameter_list ')' ';'
    | complex_name '.' DESTROY ';'
    ;

for_initialize
    : intrinsic_type SYMBOL '=' NOTHING ';'
    | intrinsic_type SYMBOL '=' expression ';'
    | intrinsic_type SYMBOL '=' bool_value ';'
    | assignment ';'
    ;


for_test_expression
    : expression ';'
    ;

for_arith_expression
    : expression
    | pre_post_inc
    | assignment
    ;

for_clause
    : FOR '(' for_initialize for_test_expression  for_arith_expression ')' loop_body
    ;

else_clause
    : ELSE '(' expression ')' method_body
    | ELSE method_body
    ;

else_body
    : else_clause
    | else_body else_clause
    | method_body
    ;

branch_expression
    : expression
    | bool_value
    ;

if_clause
    : IF '(' branch_expression ')' else_body
    ;

while_clause
    : WHILE '(' branch_expression ')' loop_body
    ;

do_clause
    : DO loop_body WHILE '(' branch_expression ')' ';'
    ;

except_parameter
    :
    | formatted_string
    | complex_name
    ;

except_parameter_list
    : except_parameter
    | except_parameter_list ',' except_parameter
    ;

except_clause
    : EXCEPT '(' except_parameter_list ')' method_body
    | EXCEPT complex_name '(' except_parameter_list ')' method_body
    ;

final_clause
    : FINAL method_body
    ;

try_clause
    : TRY method_body except_clause
    | TRY method_body except_clause final_clause
    ;

raise_clause
    : RAISE '(' except_parameter_list ')' ';'
    ;

case_clause
    : CASE UNUM loop_body
    | CASE INUM loop_body
    | CASE FNUM loop_body
    ;

default_case
    : DEFAULT loop_body
    ;

case_body
    : case_clause
    | case_body case_clause
    ;

switch_clause
    : SWITCH '(' expression ')' '{' case_body '}'
    | SWITCH '(' expression ')' '{' case_body default_case '}'
    ;

type_cast
    : intrinsic_type ':'
    ;

bool_value
    : TRUE
    | FALSE
    ;

assignment
    : complex_name '=' expression
    | complex_name '=' formatted_string
    | complex_name '=' type_cast expression
    | complex_name '=' NOTHING
    | complex_name '=' bool_value
    ;

jump_clause
    : CONTINUE ';'
    | BREAK ';'
    ;

pre_post_inc
    : complex_name INC
    | complex_name DEC
    | INC complex_name
    | DEC complex_name
    ;

method_body_element
    : function_data_definition
    | try_clause
    | raise_clause
    | function_call
    | for_clause
    | if_clause
    | while_clause
    | do_clause
    | switch_clause
    | pre_post_inc ';'
    | assignment ';'
    ;

loop_body_element
    : method_body_element
    | jump_clause
    ;

loop_body_element_list
    : loop_body_element
    | loop_body_element_list loop_body_element
    ;

loop_body
    : '{' '}'
    | '{' loop_body_element_list '}'
    ;

method_body_element_list
    : method_body_element
    | method_body_element_list method_body_element
    ;

method_body
    : '{' method_body_element_list '}'
    | '{' '}'
    ;

method_param_def
    :  method_def_param_list
    |  /* blank */
    ;

    /*
        method data_attrs name (parm list) (parm list) {body}
    */
method_definition
    : METHOD data_attrs_list SYMBOL '(' method_param_def ')' '(' method_param_def ')' method_body
    | METHOD SYMBOL '(' method_param_def ')' '(' method_param_def ')' method_body
    ;

constructor_definition
    : CREATE '(' method_param_def ')' method_body
    ;

destructor_definition
    : DESTROY method_body
    ;

class_body_item
    : class_data_definition
    | method_definition
    | constructor_definition
    | destructor_definition
    ;

class_body
    : class_body_item
    | class_body class_body_item
    ;

class_definition
    : CLASS data_attrs_list SYMBOL '(' class_parm_list ')' '{' class_body '}'
    | CLASS SYMBOL '(' class_parm_list ')' '{' class_body '}'
    ;
%%

#include <stdio.h>

extern char yytext[];

void yyerror(const char* s)
{
	fflush(stdout);
	fprintf(stdout, "\n%s: line %d: at %d: %s\n\n", get_file_name(), get_line_number(), get_col_number(), s); //yylloc.first_line, s);
    inc_error_count();
}

