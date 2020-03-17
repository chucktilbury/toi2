/* A Bison parser, made by GNU Bison 3.3.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2019 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_PARSER_H_INCLUDED
# define YY_YY_PARSER_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    SYMBOL = 258,
    UNUM = 259,
    FNUM = 260,
    INUM = 261,
    QSTRG = 262,
    CLASS = 263,
    METHOD = 264,
    CREATE = 265,
    DESTROY = 266,
    NOTHING = 267,
    IMPORT = 268,
    PUBLIC = 269,
    PRIVATE = 270,
    PROTECTED = 271,
    STATIC = 272,
    CONST = 273,
    DICT = 274,
    ARRAY = 275,
    BOOL = 276,
    AS = 277,
    STRING = 278,
    FLOAT = 279,
    INT = 280,
    INT8 = 281,
    INT16 = 282,
    INT32 = 283,
    INT64 = 284,
    UINT = 285,
    UINT8 = 286,
    UINT16 = 287,
    UINT32 = 288,
    UINT64 = 289,
    IF = 290,
    TRUE = 291,
    ELSE = 292,
    WHILE = 293,
    DO = 294,
    TRY = 295,
    EXCEPT = 296,
    RAISE = 297,
    FOR = 298,
    FALSE = 299,
    SWITCH = 300,
    CASE = 301,
    BREAK = 302,
    CONTINUE = 303,
    AND = 304,
    OR = 305,
    DEFAULT = 306,
    NOT = 307,
    EQU = 308,
    NEQU = 309,
    LTEQU = 310,
    GTEQU = 311,
    BSHL = 312,
    BSHR = 313,
    BROL = 314,
    BROR = 315,
    INC = 316,
    DEC = 317,
    FINAL = 318,
    NEG = 319
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);

#endif /* !YY_YY_PARSER_H_INCLUDED  */
