%debug
%defines
%locations

%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utils.h"
#include "scanner.h"
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
    /*
        Module rules.
    */
module
    : module_list {
        module_module_list_end();
    }
    ;

module_item
    : import_definition {
        module_item_import_definition_end();
    }
    | class_definition {
        module_item_class_definition_end();
    }
    ;

module_list
    : module_item {
        module_list_module_item_end();
    }
    | module module_item {
        module_list_module_item_end();
    }
    ;

    /*
        Literal values rules.
    */
complex_name
    : SYMBOL {
        complex_name_init_symbol();
    }
    | complex_name '.' SYMBOL {
        complex_name_add_symbol();
    }
    ;

intrinsic_type
    : DICT {
        save_intrinsic_type(DICT);
    }
    | ARRAY {
        save_intrinsic_type(ARRAY);
    }
    | BOOL {
        save_intrinsic_type(BOOL);
    }
    | STRING {
        save_intrinsic_type(STRING);
    }
    | FLOAT {
        save_intrinsic_type(FLOAT);
    }
    | INT {
        save_intrinsic_type(INT64);
    }
    | INT8 {
        save_intrinsic_type(INT8);
    }
    | INT16 {
        save_intrinsic_type(INT16);
    }
    | INT32 {
        save_intrinsic_type(INT32);
    }
    | INT64 {
        save_intrinsic_type(INT64);
    }
    | UINT {
        save_intrinsic_type(UINT64);
    }
    | UINT8 {
        save_intrinsic_type(UINT8);
    }
    | UINT16 {
        save_intrinsic_type(UINT16);
    }
    | UINT32 {
        save_intrinsic_type(UINT32);
    }
    | UINT64 {
        save_intrinsic_type(UINT64);
    }
    | complex_name {
        intrinsic_type_create_complex_name();
    }
    ;

data_attrs
    : PRIVATE {
        save_data_attr(PRIVATE);
    }
    | PUBLIC {
        save_data_attr(PUBLIC);
    }
    | PROTECTED {
        save_data_attr(PROTECTED);
    }
    | CONST {
        save_data_attr(CONST);
    }
    | STATIC {
        save_data_attr(STATIC);
    }
    ;

data_attrs_list
    : data_attrs {
        data_attrs_list_init();
    }
    | data_attrs_list data_attrs {
        data_attrs_list_add();
    }
    ;

number
    : UNUM {
        save_literal_num(UNUM);
    }
    | INUM {
        save_literal_num(INUM);
    }
    | FNUM {
        save_literal_num(FNUM);
    }
    ;

formatted_string_param
    : QSTRG {
        formatted_string_param_qstrg();
    }
    | expression {
        formatted_string_param_expression();
    }
    ;

formatted_string_param_list
    : formatted_string_param {
        formatted_string_param_list_init();
    }
    | formatted_string_param_list ',' formatted_string_param {
        formatted_string_param_list_add();
    }
    ;

formatted_string
    : QSTRG {
        formatted_string_no_format();
    }
    | QSTRG {
        formatted_string_with_format();
    } '%' '(' {
        formatted_string_with_init_parameters_start();
    } formatted_string_param_list {
        formatted_string_with_init_parameters_finish();
    } ')'
    ;

bool_value
    : TRUE {
        bool_value_create_true();
    }
    | FALSE {
        bool_value_create_false();
    }
    ;

    /*
        Imports rules
    */
import_definition
    : IMPORT SYMBOL {
        import_definition_create();
    } ';' {
        import_definition_finish();
    }
    | IMPORT SYMBOL {
        import_definition_create();
    } AS SYMBOL {
        import_definition_alias_to_symbol();
    } ';' {
        import_definition_finish();
    }
    ;

    /*
        Class definition related rules.
    */
class_parm
    : PRIVATE complex_name {
        class_parm_add_private();
    }
    | PUBLIC complex_name {
        class_parm_add_public();
    }
    | PROTECTED complex_name {
        class_parm_add_protected();
    }
    | complex_name {
        class_parm_add_private();
    }
    ;

class_parm_list
    : class_parm {
        class_parm_list_create();
    }
    | class_parm_list ',' class_parm {
        class_parm_list_add();
    }
    |  /* blank */ {
        class_parm_list_blank();
    }
    ;

class_body_item
    : class_data_definition {
        class_body_item_data_definition_finish();
    }
    | method_definition {
        class_body_item_method_definition_finish();
    }
    | constructor_definition {
        class_body_item_constructor_definition_finish();
    }
    | destructor_definition {
        class_body_item_destructor_definition_finish();
    }
    ;

class_body
    : class_body_item {
        class_body_item_add();
    }
    | class_body class_body_item {
        class_body_item_add();
    }
    ;

class_definition
    : CLASS {
        class_definiton_create();
    } data_attrs_list {
        class_definiton_attrs_finish();
    } SYMBOL {
        class_definiton_add_name();
    } '(' {
        class_definiton_param_list_start();
    } class_parm_list {
        class_definiton_param_list_finish();
    }  ')' '{' {
        class_definiton_body_start();
    } class_body {
        class_definiton_body_finish();
    } '}'
    | CLASS {
        class_definiton_create();
    } SYMBOL {
        class_definiton_add_name();
    } '(' {
        class_definiton_param_list_start();
    } class_parm_list {
        class_definiton_param_list_finish();
    } ')' '{' {
        class_definiton_body_start();
    } class_body {
        class_definiton_body_finish();
    } '}'
    ;

    /*
        Data definition rules.
    */
class_data_definition
    : intrinsic_type {
        class_data_definition_with_data_attrs();
    } data_attrs_list {
        class_data_definition_add_data_attrs();
    } SYMBOL {
        class_data_definition_name();
    } ';' {
        class_data_definition_finish();
    }
    | intrinsic_type {
        class_data_definition_no_data_attrs();
    } SYMBOL {
        class_data_definition_name();
    } ';' {
        class_data_definition_finish();
    }
    ;

function_data_definition_target
    : NOTHING {
        function_data_definition_target_nothing();
    }
    | expression {
        function_data_definition_target_expression();
    }
    | type_cast {
        function_data_definition_target_cast();
    } expression {
        function_data_definition_target_expression();
    }
    | formatted_string {
        function_data_definition_target_formatted_string();
    }
    ;

function_data_definition_symbol
    : SYMBOL {
        function_data_definition_symbol();
    }
    | CONST SYMBOL {
        function_data_definition_const_symbol();
    }
    ;

function_data_definition
    : intrinsic_type function_data_definition_symbol ';' {
        function_data_definition_no_initializer();
    }
    | intrinsic_type function_data_definition_symbol '=' {
        function_data_definition_with_initializer();
    } function_data_definition_target ';' {
        function_data_definition_with_initializer_finish();
    }
    ;

    /*
        Method definition related rules
    */
method_def_param
    : intrinsic_type {
        method_def_param_intrinsic_type();
    } SYMBOL {
        method_def_param_symbol();
    }
    ;

method_def_param_list
    : method_def_param {
        method_def_param_list_method_def_param_create();
    }
    | method_def_param_list ',' method_def_param {
        method_def_param_list_method_def_param_add();
    }
    ;

method_param_def
    :  method_def_param_list {
        method_param_def_finish();
    }
    |  /* blank */ {
        method_param_def_blank();
    }
    ;

method_definition
    : METHOD {
        method_definition_with_attrs_start();
    } data_attrs_list {
        method_definition_attrs_finish();
    } SYMBOL {
        method_definition_symbol();
    } '(' {
        method_definition_input_params_start();
    } method_param_def {
        method_definition_input_params_finish();
    } ')' '(' {
        method_definition_output_params_start();
    } method_param_def {
        method_definition_output_params_finish();
    } ')' {
        method_definition_method_body_start();
    } method_body {
        method_definition_method_body_finish();
    }
    | METHOD {
        method_definition_no_attrs_start();
    } SYMBOL {
        method_definition_symbol();
    } '(' {
        method_definition_input_params_start();
    } method_param_def {
        method_definition_input_params_finish();
    } ')' '(' {
        method_definition_output_params_start();
    } method_param_def {
        method_definition_output_params_finish();
    } ')' {
        method_definition_method_body_start();
    } method_body {
        method_definition_method_body_finish();
    }
    ;

method_body_element
    : function_data_definition {
        method_body_element_data_definition_finish();
    }
    | try_clause {
        method_body_element_try_finish();
    }
    | raise_clause {
        method_body_element_raise_finish();
    }
    | function_call {
        method_body_element_function_call_finish();
    }
    | for_clause {
        method_body_element_for_finish();
    }
    | if_clause {
        method_body_element_if_finish();
    }
    | while_clause {
        method_body_element_while_finish();
    }
    | do_clause {
        method_body_element_do_finish();
    }
    | switch_clause {
        method_body_element_switch_finish();
    }
    | pre_post_inc ';' {
        method_body_element_inc_finish();
    }
    | assignment ';' {
        method_body_element_assignment_finish();
    }
    ;

method_body_element_list
    : method_body_element {
        method_body_element_list_finish();
    }
    | method_body_element_list method_body_element {
        method_body_element_list_finish();
    }
    ;

method_body
    : '{' {
        method_body_element_start();
    } method_body_element_list {
        method_body_element_finish();
    } '}' {
        method_body_finish();
    }
    | '{' '}' {
        method_body_blank();
    }
    ;

constructor_definition
    : CREATE {
        constructor_definition_start();
    } '(' {
        constructor_definition_param_start();
    } method_param_def {
        constructor_definition_param_finish();
    } ')' {
        constructor_definition_body_start();
    } method_body {
        constructor_definition_body_finish();
    }
    ;

destructor_definition
    : DESTROY {
        destructor_definition_body_start();
    } method_body {
        destructor_definition_body_finish();
    }
    ;

    /*
        Expression related rules.
    */
subscript_item
    : '[' {
        subscript_item_expression_start();
    } expression {
        subscript_item_expression_finish();
    } ']'
    | '[' {
        subscript_item_formatted_string_start();
    } formatted_string {
        subscript_item_formatted_string_finish();
    } ']'
    ;

subscript_list
    : subscript_item {
        subscript_list_init();
    }
    | subscript_list subscript_item {
        subscript_list_add();
    }

expression_name
    : complex_name {
        expression_name_complex_name();
    }
    | complex_name {
        expression_name_complex_name_with_subscript();
    } subscript_list {
        expression_name_subscript_list_finish();
    }
    ;

expression
    : number {
        expression_literal_number();
    }
    | expression_name {
        expression_expression_name();
    }
    | expression '+' expression {
        expression_addition_operation();
    }
    | expression '-' expression {
        expression_subtraction_operation();
    }
    | expression '/' expression {
        expression_division_operation();
    }
    | expression '*' expression {
        expression_multiplication_operation();
    }
    | expression '%' expression {
        expression_modulo_operation();
    }
    | expression AND expression {
        expression_and_boolean_operation();
    }
    | expression OR expression {
        expression_or_boolean_operation();
    }
    | expression '<' expression {
        expression_less_boolean_operation();
    }
    | expression '>' expression {
        expression_greater_boolean_operation();
    }
    | expression EQU expression {
        expression_equal_boolean_operation();
    }
    | expression NEQU expression {
        expression_not_equal_boolean_operation();
    }
    | expression LTEQU expression {
        expression_less_or_equal_boolean_operation();
    }
    | expression GTEQU expression {
        expression_greater_or_equal_boolean_operation();
    }
    | expression '&' expression {
        expression_and_bitwise_operation();
    }
    | expression '|' expression {
        expression_or_bitwise_operation();
    }
    | expression '^' expression {
        expression_xor_bitwise_operation();
    }
    | expression BROL expression {
        expression_rotate_left_bitwise_operation();
    }
    | expression BROR expression {
        expression_rotate_right_bitwise_operation();
    }
    | expression BSHL expression {
        expression_shift_left_bitwise_operation();
    }
    | expression BSHR expression {
        expression_shift_right_bitwise_operation();
    }
    | '-' expression %prec NEG {
        expression_unary_negate_operation();
    }
    | NOT expression {
        expression_unary_not_boolean_operation();
    }
    | '~' expression {
        expression_not_bitwise_operation();
    }
    | '(' expression ')'
    // | '(' {
    //     expression_start();
    // } expression ')' {
    //     expression_finish();
    // }
    ;

    /*************************************
        Method/function contents rules
    */

    /*
        Function call related rules
    */
function_call_parameter
    : formatted_string {
        function_call_parameter_formatted_string();
    }
    | expression {
        function_call_parameter_expression();
    }
    ;

function_call_parameter_list
    :
    | function_call_parameter {
        function_call_parameter_list_create();
    }
    | function_call_parameter_list ',' function_call_parameter {
        function_call_parameter_list_add();
    }
    ;

function_call
    : complex_name {
        function_call_complex_name();
    } '(' {
        function_call_input_parameter_start();
    } function_call_parameter_list {
        function_call_input_parameter_finish();
    } ')' '(' {
        function_call_output_parameter_start();
    } function_call_parameter_list {
        function_call_output_parameter_finish();
    } ')' ';' {
        function_call_finish();
    }
    | DESTROY complex_name {
        function_call_destroy_complex_name();
    } ';' {
        function_call_destroy_finish();
    }
    ;

    /*
        Common rules for branching and defining loop bodies
    */
branch_expression
    : expression {
        branch_expression_expression();
    }
    | bool_value {
        branch_expression_bool_value();
    }
    ;


jump_clause
    : CONTINUE ';' {
        jump_clause_continue();
    }
    | BREAK ';' {
        jump_clause_break();
    }
    ;

pre_post_inc
    : complex_name {
        post_inc_complex_name();
    } INC {
        post_inc_finish();
    }
    | complex_name {
        post_dec_complex_name();
    } DEC {
        post_dec_finish();
    }
    | INC {
        pre_inc_start();
    } complex_name {
        pre_inc_complex_name();
    }
    | DEC {
        pre_dec_start();
    } complex_name {
        pre_dec_complex_name();
    }
    ;

loop_body_element
    : method_body_element {
        loop_body_element_method_body_element();
    }
    | jump_clause {
        loop_body_element_jump_clause_element();
    }
    ;

loop_body_element_list
    : loop_body_element {
        loop_body_element_list_init();
    }
    | loop_body_element_list loop_body_element {
        loop_body_element_list_add();
    }
    ;

loop_body
    : '{' '}' {
        loop_body_element_empty();
    }
    | '{' {
        loop_body_element_start();
    } loop_body_element_list {
        loop_body_element_finish();
    } '}' {
        loop_body_finish();
    }
    ;

    /*
        For loop related rules
    */
for_initialize_assign
    : NOTHING {
        for_initialize_assign_nothing();
    }
    | expression {
        for_initialize_assign_expression();
    }
    | bool_value {
        for_initialize_assign_bool_value();
    }
    ;

for_initialize
    : intrinsic_type {
        for_initialize_intrinsic_type();
    } SYMBOL {
        for_initialize_symbol();
    } '=' for_initialize_assign ';' {
        for_initialize_data_definition_finish();
    }
    | assignment {
        for_initialize_assignment();
    } ';' {
        for_initialize_assignment_finish();
    }
    ;


for_test_expression
    : expression {
        for_test_expression();
    } ';' {
        for_test_expression_finish();
    }
    ;

for_arith_expression
    : expression {
        for_arith_expression_expression();
    }
    | pre_post_inc {
        for_arith_expression_pre_post_inc();
    }
    | assignment {
        for_arith_expression_assignment();
    }
    ;

for_clause
    : FOR '(' {
        for_clause_definition_init();
    } for_initialize for_test_expression  for_arith_expression {
        for_clause_definition_finish();
    } ')' loop_body {
        for_clause_loop_body_finish();
    }
    ;

    /*
        If/else clause related rules
    */
else_clause
    : ELSE '(' {
        else_clause_experssion_start();
    } expression {
        else_clause_experssion_finish();
    } ')' method_body {
        else_clause_method_body_finish();
    }
    | ELSE {
        else_clause_no_expression();
    } method_body {
        else_clause_method_body_finish();
    }
    ;

else_body
    : else_clause {
        else_body_else_clause_init();
    }
    | else_body else_clause {
        else_body_else_clause_add();
    }
    | method_body {
        else_clause_method_body_finish();
    }
    ;

if_clause
    : IF '(' {
        if_clause_expression_start();
    } branch_expression {
        if_clause_expression_finish();
    } ')' else_body {
        if_clause_else_body_finish();
    }
    ;

    /*
        While clause rules.
    */
while_clause
    : WHILE '(' {
        while_clause_experssion_start();
    } branch_expression {
        while_clause_expression_finish();
    } ')' loop_body {
        while_clause_loop_body_finish();
    }
    ;

do_clause
    : DO {
        do_clause_loop_body_start();
    } loop_body {
        do_clause_loop_body_finish();
    } WHILE '(' {
        do_clause_expression_start();
    } branch_expression {
        do_clause_expression_finish();
    } ')' ';' {
        do_clause_finish();
    }
    ;

    /*
        Exception related rules.
    */
except_parameter
    :
    | formatted_string {
        except_parameter_formatted_string();
    }
    | complex_name {
        except_parameter_complex_name();
    }
    ;

except_parameter_list
    : except_parameter {
        except_parameter_list_init();
    }
    | except_parameter_list ',' except_parameter {
        except_parameter_list_add();
    }
    ;

except_clause
    : EXCEPT '(' {
        except_clause_parameter_list_start();
    } except_parameter_list {
        except_clause_parameter_list_finish();
    } ')' method_body {
        except_clause_method_body_finish();
    }
    | EXCEPT complex_name {
        except_clause_complex_name();
    } '(' {
        except_clause_parameter_list_start();
    } except_parameter_list {
        except_clause_parameter_list_start();
    } ')' method_body {
        except_clause_method_body_finish();
    }
    ;

final_clause
    : FINAL {
        final_clause_start();
    } method_body {
        final_clause_finish();
    }
    ;

try_clause_intro
    : TRY {
        try_clause_intro_start();
    } method_body except_clause {
        try_clause_intro_finish();
    }
    ;

try_clause
    : try_clause_intro
    | try_clause_intro final_clause {
        try_clause_finish();
    }
    ;

raise_clause
    : RAISE '(' {
        raise_clause_parameter_start();
    } except_parameter_list {
        raise_clause_parameter_finish();
    } ')' ';' {
        raise_clause_finish();
    }
    ;

    /*
        Switch/case related rules
    */
case_clause
    : CASE UNUM {
        case_clause_unum();
    } loop_body {
        case_clause_loop_body_finish();
    }
    | CASE INUM {
        case_clause_inum();
    } loop_body {
        case_clause_loop_body_finish();
    }
    | CASE FNUM {
        case_clause_fnum();
    } loop_body {
        case_clause_loop_body_finish();
    }
    ;

default_case
    : DEFAULT {
        default_case();
    } loop_body {
        case_clause_loop_body_finish();
    }
    ;

case_body
    : case_clause {
        case_body_init();
    }
    | case_body case_clause {
        case_body_add();
    }
    ;

switch_clause_intro
    : SWITCH '(' {
        switch_clause_intro_expression_start();
    } expression {
        switch_clause_intro_expression_finish();
    } ')' '{' {
        switch_clause_intro_case_body_start();
    } case_body {
        switch_clause_intro_case_body_finish();
    }
    ;

switch_clause
    : switch_clause_intro '}' {
        switch_clause_after_intro();
    }
    | switch_clause_intro default_case {
        switch_clause_after_intro_default();
    } '}' {
        switch_clause_finish();
    }
    ;

    /*
        Assignment related rules
    */
type_cast
    : intrinsic_type {
        type_cast_type();
    } ':' {
        type_cast_type_finish();
    }
    ;

assignment_target
    : expression {
        assignment_target_expression();
    }
    | formatted_string {
        assignment_target_formatted_string();
    }
    | type_cast expression {
        assignment_target_type_cast_expression();
    }
    | NOTHING {
        assignment_target_nothing();
    }
    | bool_value {
        assignment_target_bool_value();
    }
    ;

assignment
    : complex_name {
        assignment_complex_name();
    } '=' assignment_target {
        assignment_target_finish();
    }
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
