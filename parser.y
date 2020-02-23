%debug
%defines
%locations

%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "scanner.h"
#include "errors.h"

#define TOKSTR get_tok_str()

%}
%define parse.error verbose
%locations

%token SYMBOL UNUM FNUM INUM QSTRG CLASS METHOD
%token CREATE DESTROY NOTHING IMPORT PUBLIC PRIVATE
%token PROTECTED STATIC CONST DICT ARRAY BOOL
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
    : module_item
    | module module_item
    ;

module_item
    : import_definition
    | class_definition
    ;


complex_name
    : SYMBOL
    | complex_name '.' SYMBOL
    ;

intrinsic_type
    : DICT
    | ARRAY
    | BOOL
    | STRING
    | FLOAT
    | INT
    | INT8
    | INT16
    | INT32
    | INT64
    | UINT
    | UINT8
    | UINT16
    | UINT32
    | UINT64
    | complex_name
    ;

import_definition
    : IMPORT qstring_list ';'
    ;

qstring_list
    : QSTRG
    | qstring_list ',' QSTRG
    ;

class_parm
    : PRIVATE complex_name
    | PUBLIC complex_name
    | PROTECTED complex_name
    | complex_name
    ;

class_parm_list
    : class_parm
    | class_parm_list ',' class_parm
    |  /* blank */
    ;

data_attrs
    : PRIVATE
    | PUBLIC
    | PROTECTED
    | CONST
    | STATIC
    ;

data_attrs_list
    : data_attrs
    | data_attrs_list data_attrs
    ;

class_data_definition
    : intrinsic_type data_attrs_list SYMBOL ';'
    | intrinsic_type SYMBOL ';'
    ;

method_def_param
    : intrinsic_type SYMBOL
    ;

method_def_param_list
    : method_def_param
    | method_def_param_list ',' method_def_param
    ;

number
    : UNUM
    | INUM
    | FNUM
    ;

formatted_string
    : QSTRG
    | QSTRG '%' '(' parameter_list ')'
    ;

subscript
    : complex_name '[' expression ']'
    | complex_name '[' formatted_string ']'
    ;

    /*
    * Expressions use the "switching yard" algorithm so they can be stored and
    * evaluated at run time.
    */
expression
    : number
    | complex_name
    | expression '+' expression
    | expression '-' expression
    | expression '/' expression
    | expression '*' expression
    | expression '%' expression
    | expression AND expression
    | expression OR expression
    | expression '<' expression
    | expression '>' expression
    | expression EQU expression
    | expression NEQU expression
    | expression LTEQU expression
    | expression GTEQU expression
    | expression '&' expression
    | expression '|' expression
    | expression '^' expression
    | expression BROL expression
    | expression BROR expression
    | expression BSHL expression
    | expression BSHR expression
    | expression NOT expression
    | '-' expression %prec NEG
    | NOT expression
    | '~' expression
    | '(' expression ')'
    ;


parameter
    : formatted_string
    | subscript
    | expression
    ;

parameter_list
    :
    | parameter
    | parameter_list ',' parameter
    ;

data_definition_target
    : NOTHING
    | expression
    | type_cast expression
    | formatted_string
    ;

data_definition_assignment
    : intrinsic_type SYMBOL '=' data_definition_target ';'
    | intrinsic_type CONST SYMBOL '=' data_definition_target ';'
    ;

data_definition
    : intrinsic_type SYMBOL ';'
    | data_definition_assignment
    ;

function_call
    : complex_name '(' parameter_list ')' '(' parameter_list ')' ';'
    | complex_name '.' CREATE '(' parameter_list ')' ';'
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
    : data_definition
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
	fprintf(stderr, "\n%s: line %d: at %d: %s\n\n", get_file_name(), get_line_number(), yylloc.first_line, s);
    inc_error_count();
}

