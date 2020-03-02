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
    : SYMBOL {}
    | complex_name '.' SYMBOL {}
    ;

intrinsic_type
    : DICT {}
    | ARRAY {}
    | BOOL {}
    | STRING {}
    | FLOAT {}
    | INT {}
    | INT8 {}
    | INT16 {}
    | INT32 {}
    | INT64 {}
    | UINT {}
    | UINT8 {}
    | UINT16 {}
    | UINT32 {}
    | UINT64 {}
    | complex_name {}
    ;

data_attrs
    : PRIVATE {}
    | PUBLIC {}
    | PROTECTED {}
    | CONST {}
    | STATIC {}
    ;

data_attrs_list
    : data_attrs {}
    | data_attrs_list data_attrs {}
    ;

number
    : UNUM {}
    | INUM {}
    | FNUM {}
    ;

formatted_string_param
    : QSTRG {}
    | expression {}
    ;

formatted_string_param_list
    : formatted_string_param {}
    | formatted_string_param_list ',' formatted_string_param {}
    ;

formatted_string
    : QSTRG {}
    | QSTRG {} '%' '(' {} formatted_string_param_list {} ')'
    ;

bool_value
    : TRUE {}
    | FALSE {}
    ;

    /*
        Imports rules
    */
import_definition
    : IMPORT SYMBOL {} ';' {}
    | IMPORT SYMBOL {} AS SYMBOL {} ';' {}
    ;

    /*
        Class definition related rules.
    */
class_parm
    : PRIVATE complex_name {}
    | PUBLIC complex_name {}
    | PROTECTED complex_name {}
    | complex_name {}
    ;

class_parm_list
    : class_parm {}
    | class_parm_list ',' class_parm {}
    |  /* blank */
    ;

class_body_item
    : class_data_definition {}
    | method_definition {}
    | constructor_definition {}
    | destructor_definition {}
    ;

class_body
    : class_body_item {}
    | class_body class_body_item {}
    ;

class_definition
    : CLASS {} data_attrs_list {} SYMBOL {} '(' {} class_parm_list{}  ')' '{' {} class_body {} '}'
    | CLASS {} SYMBOL {} '(' {} class_parm_list {} ')' '{' {} class_body {} '}'
    ;

    /*
        Data definition rules.
    */
class_data_definition
    : intrinsic_type {} data_attrs_list {} SYMBOL {} ';' {}
    | intrinsic_type {} SYMBOL {} ';' {}
    ;

function_data_definition_target
    : NOTHING {}
    | expression {}
    | type_cast {} expression {}
    | formatted_string {}
    ;

function_data_definition_symbol
    : SYMBOL {}
    | CONST SYMBOL {}
    ;

function_data_definition
    : intrinsic_type function_data_definition_symbol ';' {}
    | intrinsic_type function_data_definition_symbol '=' {} function_data_definition_target ';' {}
    ;

    /*
        Method definition related rules
    */
method_def_param
    : intrinsic_type {} SYMBOL {}
    ;

method_def_param_list
    : method_def_param {}
    | method_def_param_list ',' method_def_param {}
    ;

method_param_def
    :  method_def_param_list {}
    |  /* blank */
    ;

method_definition
    : METHOD {} data_attrs_list {} SYMBOL {} '(' {} method_param_def {} ')' '(' {} method_param_def {} ')' {} method_body {}
    | METHOD {} SYMBOL {} '(' {} method_param_def {} ')' '(' {} method_param_def {} ')' {} method_body {}
    ;

method_body_element
    : function_data_definition {}
    | try_clause {}
    | raise_clause {}
    | function_call {}
    | for_clause {}
    | if_clause {}
    | while_clause {}
    | do_clause {}
    | switch_clause {}
    | pre_post_inc ';' {}
    | assignment ';' {}
    ;

method_body_element_list
    : method_body_element {}
    | method_body_element_list method_body_element {}
    ;

method_body
    : '{' {} method_body_element_list {} '}' {}
    | '{' '}' {}
    ;

constructor_definition
    : CREATE {} '(' {} method_param_def {} ')' {} method_body {}
    ;

destructor_definition
    : DESTROY {} method_body {}
    ;

    /*
        Expression related rules.

        Expressions use the "switching yard" algorithm so they can be stored
        and then evaluated at run time.
    */
subscript_item
    : '[' {} expression {} ']'
    | '[' {} formatted_string {} ']'
    ;

subscript_list
    : subscript_item {}
    | subscript_list subscript_item {}

expression_name
    : complex_name {}
    | complex_name {} subscript_list {}
    ;

expression
    : number {}
    | expression_name {}
    | expression '+' expression {}
    | expression '-' expression {}
    | expression '/' expression {}
    | expression '*' expression {}
    | expression '%' expression {}
    | expression AND expression {}
    | expression OR expression {}
    | expression '<' expression {}
    | expression '>' expression {}
    | expression EQU expression {}
    | expression NEQU expression {}
    | expression LTEQU expression {}
    | expression GTEQU expression {}
    | expression '&' expression {}
    | expression '|' expression {}
    | expression '^' expression {}
    | expression BROL expression {}
    | expression BROR expression {}
    | expression BSHL expression {}
    | expression BSHR expression {}
    | '-' expression %prec NEG {}
    | NOT expression {}
    | '~' expression {}
    | '(' {} expression ')' {}
    ;

    /*************************************
        Method/function contents rules
    */

    /*
        Function call related rules
    */
function_call_parameter
    : formatted_string {}
    | expression {}
    ;

function_call_parameter_list
    :
    | function_call_parameter {}
    | function_call_parameter_list ',' function_call_parameter {}
    ;

function_call
    : complex_name {} '(' {} function_call_parameter_list {} ')' '(' {} function_call_parameter_list {} ')' ';' {}
    | DESTROY complex_name {} ';' {}
    ;

    /*
        Common rules for branching and defining loop bodies
    */
branch_expression
    : expression {}
    | bool_value {}
    ;


jump_clause
    : CONTINUE ';' {}
    | BREAK ';' {}
    ;

pre_post_inc
    : complex_name {} INC {}
    | complex_name {} DEC {}
    | INC {} complex_name {}
    | DEC {} complex_name {}
    ;

loop_body_element
    : method_body_element {}
    | jump_clause {}
    ;

loop_body_element_list
    : loop_body_element {}
    | loop_body_element_list loop_body_element {}
    ;

loop_body
    : '{' '}' {}
    | '{' {} loop_body_element_list {} '}' {}
    ;

    /*
        For loop related rules
    */
for_initialize_assign
    : NOTHING {}
    | expression {}
    | bool_value {}
    ;

for_initialize
    : intrinsic_type {} SYMBOL {} '=' for_initialize_assign ';' {}
    | assignment {} ';' {}
    ;


for_test_expression
    : expression {} ';' {}
    ;

for_arith_expression
    : expression {}
    | pre_post_inc {}
    | assignment {}
    ;

for_clause
    : FOR '(' {} for_initialize for_test_expression  for_arith_expression {} ')' loop_body {}
    ;

    /*
        If/else clause related rules
    */
else_clause
    : ELSE '(' {} expression {} ')' method_body {}
    | ELSE {} method_body {}
    ;

else_body
    : else_clause {}
    | else_body else_clause {}
    | method_body {}
    ;

if_clause
    : IF '(' {} branch_expression {} ')' else_body {}
    ;

    /*
        While clause rules.
    */
while_clause
    : WHILE '(' {} branch_expression {} ')' loop_body {}
    ;

do_clause
    : DO {} loop_body {} WHILE '(' {} branch_expression {} ')' ';' {}
    ;

    /*
        Exception related rules.
    */
except_parameter
    :
    | formatted_string {}
    | complex_name {}
    ;

except_parameter_list
    : except_parameter {}
    | except_parameter_list ',' except_parameter {}
    ;

except_clause
    : EXCEPT '(' {} except_parameter_list {} ')' method_body {}
    | EXCEPT complex_name {} '(' {} except_parameter_list {} ')' method_body {}
    ;

final_clause
    : FINAL {} method_body {}
    ;

try_clause_intro
    : TRY {} method_body except_clause {}
    ;

try_clause
    : try_clause_intro
    | try_clause_intro final_clause {}
    ;

raise_clause
    : RAISE '(' {} except_parameter_list {} ')' ';' {}
    ;

    /*
        Switch/case related rules
    */
case_clause
    : CASE UNUM {} loop_body {}
    | CASE INUM {} loop_body {}
    | CASE FNUM {} loop_body {}
    ;

default_case
    : DEFAULT {} loop_body {}
    ;

case_body
    : case_clause {}
    | case_body case_clause {}
    ;

switch_clause_intro
    : SWITCH '(' {} expression {} ')' '{' {} case_body {}
    ;

switch_clause
    : switch_clause_intro '}' {}
    | switch_clause_intro default_case {} '}' {}
    ;

    /*
        Assignment related rules
    */
type_cast
    : intrinsic_type {} ':' {}
    ;

assignment_target
    : expression {}
    | formatted_string {}
    | type_cast expression {}
    | NOTHING {}
    | bool_value {}
    ;

assignment
    : complex_name {} '=' assignment_target {}
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

