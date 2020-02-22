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

%token SYMBOL UNUM FNUM INUM QSTRG CLASS METHOD
%token CREATE DESTROY NOTHING IMPORT PUBLIC PRIVATE
%token PROTECTED STATIC CONST DICT ARRAY BOOL
%token STRING FLOAT INT INT8 INT16 INT32 INT64
%token UINT UINT8 UINT16 UINT32 UINT64 IF ELSEIF
%token ELSE FOR WHILE DO TRY EXCEPT RAISE ALLOC
%token DELETE SWITCH CASE BREAK CONTINUE AND OR
%token NOT EQU NEQU LTEQU GTEQU BSHL BSHR BROL
%token BROR INC DEC

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

expression_list
    : expression
    | expression_list ',' expression
    ;

data_definition
    : intrinsic_type SYMBOL ';'
    | intrinsic_type SYMBOL '=' expression ';'
    | '(' intrinsic_type ')' expression
    | '(' intrinsic_type ')' expression ';'
    ;

function_call
    : complex_name '(' expression_list ')' '(' expression_list ')' ';'
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

if_clause
    : IF '(' expression ')' else_body
    ;

while_clause
    : WHILE '(' expression ')' loop_body
    ;

do_clause
    : DO loop_body WHILE '(' expression ')' ';'
    ;

case_clause
    : CASE UNUM method_body
    | CASE INUM method_body
    | CASE FNUM method_body
    ;

case_body
    : case_clause
    | case_body case_clause
    ;

switch_clause
    : SWITCH '(' expression ')' '{' case_body '}'
    ;

assignment
    : complex_name '=' expression ';'
    ;

jump_clause
    : CONTINUE ';'
    | BREAK ';'
    ;

method_body_element
    : data_definition
    | function_call
    | if_clause
    | while_clause
    | do_clause
    | switch_clause
    | complex_name INC ';'
    | complex_name DEC ';'
    | INC complex_name ';'
    | DEC complex_name ';'
    | assignment
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
    : '{' loop_body_element_list '}'
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
    : METHOD data_attrs_list SYMBOL '(' method_param_def ')' '(' method_param_def ')'method_body
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
	fprintf(stderr, "\n%s: %d: %s\n\n", get_file_name(), get_line_number(), s);
    inc_error_count();
}

