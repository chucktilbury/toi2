
%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "errors.h"
#include "parser.h"

// string buffer to get token from
static char strbuf[1024*64];

typedef struct _file_name_stack {
    int line_no;
    char *name;
    struct _file_name_stack *next;
} _file_name_stack;

void count(void);
static char buffer[1024*64];
static int bidx = 0;
static _file_name_stack *name_stack;
int num_errors = 0; // global updated by parser

// these funcs support the string scanner
static void append_char(char ch) {
    if((sizeof(buffer)-1) > bidx) {
        buffer[bidx] = ch;
        bidx++;
    }
    else {
        scanner_error("buffer overrun");
    }
}

static void append_str(char *str) {
    if((sizeof(buffer)-1) > (strlen(buffer) + strlen(str))) {
        strcat(buffer, str);
        bidx = strlen(buffer);
    }
    else {
        scanner_error("buffer overrun");
    }
}

#define YY_USER_ACTION yylloc.first_line = yylloc.last_line = yylineno;
%}

    /* state definitions */
%x SQUOTES
%x DQUOTES
%x COMMENT
%option noinput nounput
%option yylineno
%%

    /* overhead */
\n           {name_stack->line_no ++; yylineno++; }
[ \t\r]       {}

    /* keywords */
"nothing"       { return NOTHING; }
"nada"          { return NOTHING; }
"null"          { return NOTHING; }
"import"        { return IMPORT; }
"class"         { return CLASS; }
"method"        { return METHOD; }
"func"          { return METHOD; }
"function"      { return METHOD; }
"create"        { return CREATE; }
"constructor"   { return CREATE; }
"construct"     { return CREATE; }
"destroy"       { return DESTROY; }
"destructor"    { return DESTROY; }
"destruct"      { return DESTROY; }
"public"        { return PUBLIC; }
"private"       { return PRIVATE; }
"protect"       { return PROTECTED; }
"protected"     { return PROTECTED; }
"static"        { return STATIC; }
"const"         { return CONST; }
"constant"      { return CONST; }
"dict"          { return DICT; }
"dictionary"    { return DICT; }
"array"         { return ARRAY; }
"bool"          { return BOOL; }
"boolean"       { return BOOL; }
"true"          { return TRUE; }
"yes"           { return TRUE; }
"false"         { return FALSE; }
"no"            { return FALSE; }
"string"        { return STRING; }
"int8"          { return INT8; }
"int16"         { return INT16; }
"int32"         { return INT32; }
"int64"         { return INT64; }
"int"           { return INT; }
"float"         { return FLOAT; }
"uint8"         { return UINT8; }
"uint16"        { return UINT16; }
"uint32"        { return UINT32; }
"uint64"        { return UINT64; }
"uint"          { return UINT; }
"for"           { return FOR; }
"if"            { return IF; }
"else"          { return ELSE; }
"while"         { return WHILE; }
"do"            { return DO; }
"try"           { return TRY; }
"except"        { return EXCEPT; }
"catch"         { return EXCEPT; }
"raise"         { return RAISE; }
"switch"        { return SWITCH; }
"case"          { return CASE; }
"break"         { return BREAK; }
"continue"      { return CONTINUE; }
"default"       { return DEFAULT; }
"final"         { return FINAL; }

    /* boolean operator tokens composed of special characters */
"&&"            { return AND; }
"and"           { return AND; }
"||"            { return OR; }
"or"            { return OR; }

"not"           { return NOT; }
"=="            { return EQU; }
"equ"           { return EQU; }
"<>"            { return NEQU; }
"neq"           { return NEQU; }
"!="            { return NEQU; }
"<="            { return LTEQU; }
"leq"           { return LTEQU; }
">="            { return GTEQU; }
"geq"           { return GTEQU; }

    /* arithmetic operators */
"<<"            { return BSHL; }
">>"            { return BSHR; }
"<=<"           { return BROL; }
">=>"           { return BROR; }
"++"            { return INC; }
"--"            { return DEC; }

("<"|"lt")      { return '<'; }
(">"|"mt"|"gt") { return '>'; }
"-"             { return '-'; }
"+"             { return '+'; }
"="             { return '='; }
"/"             { return '/'; }
"*"             { return '*'; }
"%"             { return '%'; }
"&"             { return '&'; }
"|"             { return '|'; }
"@"             { return '@'; }
"^"             { return '^'; }
"~"             { return '~'; }
"!"             { return NOT; }

    /* Other operators */
","             { return ','; }
";"             { return ';'; }
":"             { return ':'; }
"["             { return '['; }
"]"             { return ']'; }
"{"             { return '{'; }
"}"             { return '}'; }
"("             { return '('; }
")"             { return ')'; }
"."             { return '.'; }

    /* constructed tokens */
[_A-Za-z][_0-9A-Za-z]*    { strncpy(strbuf, yytext, sizeof(strbuf)); return SYMBOL; }
    /* [_A-Za-z][_0-9A-Za-z\.]*    { strncpy(strbuf, yytext, sizeof(strbuf)); return COMPLEX; } */

    /* recognize and ignore a C comments */
"/*" { BEGIN(COMMENT); }
<COMMENT>"*/" { BEGIN(INITIAL); }
<COMMENT>\n { name_stack->line_no++; yylineno++; }
<COMMENT>.  {}  /* eat everything in between */
"//".* {} /* eat up until the newline */

    /* recognize an integer */
    /* [-+]?[0-9]+    { */
[0-9]+    {
        strncpy(strbuf, yytext, sizeof(strbuf));
        return INUM;
    }

    /* recognize an unsigned number */
0[xX][0-9A-Fa-f]+ {
        strncpy(strbuf, yytext, sizeof(strbuf));
        return UNUM;
    }

    /* recognize a float */
[-+]?[0-9]+\.[0-9]+([eE]*[-+]?[0-9]+)? {
        strncpy(strbuf, yytext, sizeof(strbuf));
        return FNUM;
    }

    /* double quoted strings have escapes managed */
\"  {
        bidx = 0;
        memset(buffer, 0, sizeof(buffer));
        BEGIN(DQUOTES);
    }

<DQUOTES>\" {
        strncpy(strbuf, buffer, sizeof(strbuf));
        BEGIN(INITIAL);
        return QSTRG;
    }

    /* problem is that the short rule matches before the long one does */
    /* <DQUOTES>\"[ \t]*\\[ \t]*\n$ { printf("here2\n"); name_stack->line_no ++; } */
<DQUOTES>\\n    { append_char('\n'); }
<DQUOTES>\\r    { append_char('\r'); }
<DQUOTES>\\t    { append_char('\t'); }
<DQUOTES>\\b    { append_char('\b'); }
<DQUOTES>\\f    { append_char('\f'); }
<DQUOTES>\\v    { append_char('\v'); }
<DQUOTES>\\\\   { append_char('\\'); }
<DQUOTES>\\\"   { append_char('\"'); }
<DQUOTES>\\\'   { append_char('\''); }
<DQUOTES>\\\?   { append_char('\?'); }
<DQUOTES>\\.    { append_char(yytext[1]); }
<DQUOTES>\\[0-7]{1,3} { append_char((char)strtol(yytext+1, 0, 8));  }
<DQUOTES>\\[xX][0-9a-fA-F]{1,3} { append_char((char)strtol(yytext+2, 0, 16));  }
<DQUOTES>[^\\\"\n]*  { append_str(yytext); }


    /* single quoted strings are absolute literals */
\'  {
        bidx = 0;
        memset(buffer, 0, sizeof(buffer));
        BEGIN(SQUOTES);
    }

    /*<SQUOTES>\'[ \t]*\\[ \t]*\n { name_stack->line_no ++; } */
<SQUOTES>[^\\'\n]*  { append_str(yytext); }
<SQUOTES>\\.    { append_str(yytext); }
<SQUOTES>\' {
        strncpy(strbuf, buffer, sizeof(strbuf));
        BEGIN(INITIAL);
        return QSTRG;
    }

<<EOF>> {

        debug(0, "closing file \"%s\"", name_stack->name);
        //fprintf(stderr, "There were %d errors found.\n", num_errors);
        _file_name_stack *name = name_stack->next;
        free(name_stack->name);
        free(name_stack);
        name_stack = name;

        memset(strbuf, 0, sizeof(strbuf));
        yypop_buffer_state();
        if(!YY_CURRENT_BUFFER) {
            yyterminate();
        }

        //return EOF;
    }

%%

void open_file(char *fname) {

    _file_name_stack *name;

    debug(0, "opening file: \"%s\"", fname);
    if(NULL == (name = calloc(1, sizeof(_file_name_stack))))
        scanner_error("cannot allocate memory for file stack");

    if(NULL == (name->name = strdup(fname)))
        scanner_error("cannot allocate memory for file stack name");

    name->next = name_stack;
    name->line_no = 1;
    name_stack = name;

    yyin = fopen(fname, "r");
    if(NULL == yyin) {
        scanner_error("cannot open the input file: \"%s\": %s", fname, strerror(errno));
        exit(1);
    }

    yypush_buffer_state(yy_create_buffer(yyin, YY_BUF_SIZE));
}

// Tracking and global interface
char *get_file_name(void) {
    if(NULL != name_stack)
        return name_stack->name;
    else
        return "no name";
}

int get_line_number(void) {
    if(NULL != name_stack)
        return name_stack->line_no;
    else
        return -1;
}

const char *get_tok_str(void) {
    return strbuf;
}

int get_token(void) {

    memset(strbuf, 0, sizeof(strbuf));
    return yylex();
    //int retv = yylex();
    //if(0 == retv)
    //    memset(strbuf, 0, sizeof(strbuf));
    //
    //return retv;
}

