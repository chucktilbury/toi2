/* A Bison parser, made by GNU Bison 3.3.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.3.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 5 "parser.y" /* yacc.c:337  */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "scanner.h"
#include "errors.h"
#include "parser_support.h"

#define TOKSTR get_tok_str()


#line 83 "parser.c" /* yacc.c:337  */
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser.h".  */
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



#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  11
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   681

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  87
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  173
/* YYNRULES -- Number of rules.  */
#define YYNRULES  295
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  465

#define YYUNDEFTOK  2
#define YYMAXUTOK   319

/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  ((unsigned) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    73,    64,     2,
      78,    79,    71,    69,    77,    70,    76,    72,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    86,    80,
      67,    83,    68,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    84,     2,    85,    66,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    81,    65,    82,    75,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    74
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    45,    45,    49,    50,    54,    55,    62,    63,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    86,    87,    88,    89,    90,
      94,    95,    99,   100,   101,   105,   106,   110,   111,   115,
     116,   116,   116,   116,   120,   121,   128,   128,   129,   129,
     129,   136,   137,   138,   139,   143,   144,   145,   149,   150,
     151,   152,   156,   157,   161,   161,   161,   161,   161,   161,
     161,   161,   162,   162,   162,   162,   162,   162,   162,   169,
     169,   169,   169,   170,   170,   170,   174,   175,   176,   176,
     177,   181,   182,   186,   187,   187,   194,   194,   198,   199,
     203,   204,   208,   208,   208,   208,   208,   208,   208,   208,
     208,   209,   209,   209,   209,   209,   209,   209,   209,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     227,   228,   232,   232,   232,   233,   237,   237,   237,   237,
     237,   241,   241,   251,   251,   251,   252,   252,   252,   256,
     257,   260,   261,   261,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     290,   301,   302,   305,   307,   308,   312,   312,   312,   312,
     312,   312,   313,   313,   320,   321,   326,   327,   331,   331,
     332,   332,   333,   333,   334,   334,   338,   339,   343,   344,
     348,   349,   349,   349,   356,   357,   358,   362,   362,   362,
     363,   363,   368,   368,   372,   373,   374,   378,   378,   378,
     385,   385,   385,   386,   386,   390,   391,   392,   396,   396,
     396,   403,   403,   403,   407,   407,   407,   407,   407,   413,
     415,   416,   420,   421,   425,   425,   425,   426,   426,   426,
     426,   430,   430,   434,   434,   438,   439,   443,   443,   443,
     450,   450,   451,   451,   452,   452,   456,   456,   460,   461,
     465,   465,   465,   465,   469,   470,   470,   477,   477,   481,
     482,   483,   484,   485,   489,   489
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "SYMBOL", "UNUM", "FNUM", "INUM",
  "QSTRG", "CLASS", "METHOD", "CREATE", "DESTROY", "NOTHING", "IMPORT",
  "PUBLIC", "PRIVATE", "PROTECTED", "STATIC", "CONST", "DICT", "ARRAY",
  "BOOL", "AS", "STRING", "FLOAT", "INT", "INT8", "INT16", "INT32",
  "INT64", "UINT", "UINT8", "UINT16", "UINT32", "UINT64", "IF", "TRUE",
  "ELSE", "WHILE", "DO", "TRY", "EXCEPT", "RAISE", "FOR", "FALSE",
  "SWITCH", "CASE", "BREAK", "CONTINUE", "AND", "OR", "DEFAULT", "NOT",
  "EQU", "NEQU", "LTEQU", "GTEQU", "BSHL", "BSHR", "BROL", "BROR", "INC",
  "DEC", "FINAL", "'&'", "'|'", "'^'", "'<'", "'>'", "'+'", "'-'", "'*'",
  "'/'", "'%'", "NEG", "'~'", "'.'", "','", "'('", "')'", "';'", "'{'",
  "'}'", "'='", "'['", "']'", "':'", "$accept", "module", "module_item",
  "module_list", "complex_name", "intrinsic_type", "data_attrs",
  "data_attrs_list", "number", "formatted_string_param",
  "formatted_string_param_list", "formatted_string", "$@1", "$@2", "$@3",
  "bool_value", "import_definition", "$@4", "$@5", "$@6", "class_parm",
  "class_parm_list", "class_body_item", "class_body", "class_definition",
  "$@7", "$@8", "$@9", "$@10", "$@11", "$@12", "$@13", "$@14", "$@15",
  "$@16", "$@17", "$@18", "$@19", "class_data_definition", "$@20", "$@21",
  "$@22", "$@23", "$@24", "function_data_definition_target", "$@25",
  "function_data_definition_symbol", "function_data_definition", "$@26",
  "method_def_param", "$@27", "method_def_param_list", "method_param_def",
  "method_definition", "$@28", "$@29", "$@30", "$@31", "$@32", "$@33",
  "$@34", "$@35", "$@36", "$@37", "$@38", "$@39", "$@40", "$@41", "$@42",
  "method_body_element", "method_body_element_list", "method_body", "$@43",
  "$@44", "constructor_definition", "$@45", "$@46", "$@47", "$@48",
  "destructor_definition", "$@49", "subscript_item", "$@50", "$@51",
  "$@52", "$@53", "subscript_list", "expression_name", "$@54",
  "expression", "$@55", "function_call_parameter",
  "function_call_parameter_list", "function_call", "$@56", "$@57", "$@58",
  "$@59", "$@60", "$@61", "branch_expression", "jump_clause",
  "pre_post_inc", "$@62", "$@63", "$@64", "$@65", "loop_body_element",
  "loop_body_element_list", "loop_body", "$@66", "$@67",
  "for_initialize_assign", "for_initialize", "$@68", "$@69", "$@70",
  "for_test_expression", "$@71", "for_arith_expression", "for_clause",
  "$@72", "$@73", "else_clause", "$@74", "$@75", "$@76", "else_body",
  "if_clause", "$@77", "$@78", "while_clause", "$@79", "$@80", "do_clause",
  "$@81", "$@82", "$@83", "$@84", "except_parameter",
  "except_parameter_list", "except_clause", "$@85", "$@86", "$@87", "$@88",
  "$@89", "final_clause", "$@90", "try_clause_intro", "$@91", "try_clause",
  "raise_clause", "$@92", "$@93", "case_clause", "$@94", "$@95", "$@96",
  "default_case", "$@97", "case_body", "switch_clause_intro", "$@98",
  "$@99", "$@100", "switch_clause", "$@101", "type_cast", "$@102",
  "assignment_target", "assignment", "$@103", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,    38,   124,    94,    60,    62,    43,
      45,    42,    47,    37,   319,   126,    46,    44,    40,    41,
      59,   123,   125,    61,    91,    93,    58
};
# endif

#define YYPACT_NINF -334

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-334)))

#define YYTABLE_NINF -295

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     118,    31,    36,    27,  -334,  -334,  -334,  -334,   132,    48,
      47,  -334,  -334,  -334,  -334,  -334,  -334,  -334,  -334,   132,
    -334,   -21,    55,  -334,    95,    21,  -334,   121,  -334,  -334,
    -334,    49,    91,    45,  -334,  -334,   138,   138,   138,    81,
    -334,    66,  -334,    91,    81,    81,    81,   157,    91,    85,
      66,  -334,  -334,    84,    94,  -334,    93,   515,  -334,   159,
    -334,  -334,  -334,  -334,  -334,  -334,  -334,  -334,  -334,  -334,
    -334,  -334,  -334,  -334,  -334,  -334,  -334,    81,   173,  -334,
     515,  -334,  -334,  -334,  -334,   515,   132,   174,   100,    99,
     132,   179,  -334,   101,   515,   132,  -334,  -334,   104,  -334,
     132,  -334,  -334,   106,   186,   112,   534,  -334,   471,   188,
     113,  -334,  -334,  -334,  -334,  -334,   115,  -334,   138,   116,
     117,  -334,  -334,   123,   124,   128,  -334,  -334,    19,    25,
    -334,  -334,   471,  -334,   119,  -334,  -334,  -334,  -334,   144,
    -334,  -334,   -30,  -334,   130,  -334,  -334,   133,   534,   205,
     534,   134,    81,  -334,  -334,   131,    99,  -334,  -334,  -334,
     138,   138,   136,   154,   155,   135,  -334,   213,   -23,  -334,
     142,  -334,  -334,  -334,  -334,  -334,  -334,  -334,   140,  -334,
    -334,  -334,  -334,  -334,   145,    67,    67,   147,  -334,   189,
      76,   534,    26,    81,    81,  -334,  -334,  -334,   312,  -334,
    -334,  -334,  -334,    99,   131,   149,  -334,   534,   148,    99,
    -334,  -334,  -334,  -334,  -334,  -334,    26,    26,    26,  -334,
     -40,  -334,  -334,  -334,   547,  -334,  -334,  -334,   425,   194,
      12,  -334,   160,    81,  -334,  -334,   158,    -1,  -334,    26,
    -334,   547,   305,  -334,    54,  -334,  -334,  -334,   547,    26,
    -334,   391,  -334,  -334,  -334,  -334,   156,  -334,  -334,  -334,
    -334,    26,   152,    26,    26,    26,    26,    26,    26,    26,
      26,    26,    26,    26,    26,    26,    26,    26,    26,    26,
      26,    26,    26,   162,   166,   171,   172,  -334,  -334,  -334,
     425,   161,  -334,    81,   164,    76,   167,   235,   547,   109,
     175,   180,  -334,   547,  -334,   165,   176,   547,  -334,  -334,
     181,   547,  -334,   209,  -334,   520,   246,  -334,   152,   568,
     568,   608,   608,    63,    63,    83,    83,    83,    83,   589,
     589,   589,    63,    63,    37,    37,  -334,  -334,  -334,   -13,
     131,  -334,  -334,  -334,   178,  -334,    76,   187,   212,  -334,
     211,  -334,   214,   -20,   547,  -334,  -334,  -334,  -334,   215,
     305,   216,  -334,  -334,    26,   219,   534,  -334,    26,   286,
    -334,   220,  -334,  -334,   262,  -334,  -334,    67,   158,  -334,
    -334,  -334,   217,  -334,   223,  -334,  -334,   225,   547,  -334,
    -334,   547,  -334,  -334,    99,  -334,  -334,   226,    76,   356,
      14,   131,   260,  -334,   534,   234,   236,   237,    26,  -334,
     241,    99,   158,  -334,  -334,   248,   547,  -334,  -334,   547,
     243,  -334,   163,  -334,   260,   305,  -334,  -334,  -334,  -334,
     547,   247,  -334,   249,   356,   250,  -334,  -334,  -334,  -334,
    -334,   165,   251,    99,   268,  -334,    99,  -334,  -334,   131,
     131,   131,   270,  -334,  -334,    99,  -334,  -334,  -334,  -334,
     271,    99,  -334,  -334,  -334
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,    64,     0,     0,     5,     2,     3,     4,     0,     0,
      46,     1,     6,    26,    25,    27,    29,    28,    30,    65,
      73,     0,     0,    31,     0,     0,    47,     0,    66,    74,
      49,     0,    57,     0,    67,     7,     0,     0,     0,    54,
      55,    75,    50,    57,    52,    51,    53,     0,     0,     0,
      68,     8,    56,     0,     0,    76,     0,     0,    69,   102,
     136,   141,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    79,    62,
      77,    58,    59,    60,    61,     0,     0,     0,     0,     0,
       0,     0,    63,     0,    70,   103,   112,   137,   132,   142,
      80,    84,    78,     0,     0,     0,   101,   135,     0,     0,
       0,    71,   104,   113,    96,    98,   100,   138,     0,     0,
       0,   244,   263,     0,     0,     0,   202,   204,    24,     0,
     119,   130,   133,   122,     0,   123,   124,   125,   126,   265,
     120,   121,     0,   127,     0,    81,    85,     0,   101,     0,
       0,     0,   192,   238,   241,     0,     0,   267,   227,   280,
       0,     0,     0,     0,     0,     0,    91,     0,     0,   131,
       0,   128,   261,   266,   276,   284,   285,   129,     0,   105,
     114,    97,    99,   139,     0,     0,     0,   211,   245,     0,
     249,     0,     0,   203,   205,   187,   199,   201,     0,    92,
      93,    94,   134,     0,     0,     0,    82,   101,     0,     0,
     193,    32,    34,    33,    44,    45,     0,     0,     0,   179,
     151,   154,   195,   155,   194,   239,   242,   210,     0,     0,
       0,   264,    39,   251,   250,   252,   268,    24,   217,     0,
     220,   281,   183,   292,   151,   287,   290,   293,   289,     0,
     295,     0,   262,   277,   286,   106,     0,   140,   177,   176,
     178,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   206,   207,   208,
     212,     0,   254,   257,     0,   249,     0,     0,   222,     0,
       0,     0,   181,   182,   184,   188,     0,   291,    86,    90,
       0,    87,    88,     0,   115,     0,   143,   149,   153,   161,
     162,   165,   166,   167,   168,   174,   175,   172,   173,   169,
     170,   171,   163,   164,   156,   157,   159,   158,   160,     0,
       0,   197,   196,   209,     0,   246,   249,     0,     0,   253,
       0,   218,     0,   151,   224,   225,   228,   226,   221,     0,
       0,     0,   288,    95,     0,     0,   101,   180,     0,     0,
     150,   233,   237,   235,   240,   243,   213,     0,   255,   258,
      41,   269,     0,   223,     0,   282,   185,     0,    89,   107,
     116,   144,   147,   230,     0,   236,   247,     0,   249,     0,
       0,     0,     0,   189,   101,     0,     0,     0,     0,   234,
       0,     0,   259,    35,    37,    42,    36,   214,   216,   215,
       0,   229,     0,   278,   283,   183,   108,   117,   145,   148,
     231,     0,   256,     0,     0,     0,   219,   270,   274,   272,
     279,   190,     0,     0,     0,   248,     0,    38,    43,     0,
       0,     0,     0,   109,   118,     0,   260,   271,   275,   273,
       0,     0,   232,   191,   110
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -334,  -334,   323,  -334,   -32,   -47,    -7,     1,  -334,   -84,
    -334,  -197,  -334,  -334,  -334,  -191,  -334,  -334,  -334,  -334,
     304,   310,   -57,   269,  -334,  -334,  -334,  -334,  -334,  -334,
    -334,  -334,  -334,  -334,  -334,  -334,  -334,  -334,  -334,  -334,
    -334,  -334,  -334,  -334,  -334,  -334,  -334,  -334,  -334,   208,
    -334,  -334,  -140,  -334,  -334,  -334,  -334,  -334,  -334,  -334,
    -334,  -334,  -334,  -334,  -334,  -334,  -334,  -334,  -334,   -86,
    -334,  -154,  -334,  -334,  -334,  -334,  -334,  -334,  -334,  -334,
    -334,    50,  -334,  -334,  -334,  -334,  -334,  -334,  -334,     5,
    -334,    -5,   -58,  -334,  -334,  -334,  -334,  -334,  -334,  -334,
    -172,  -334,    71,  -334,  -334,  -334,  -334,    86,  -334,  -201,
    -334,  -334,  -334,  -334,  -334,  -334,  -334,  -334,  -334,  -334,
    -334,  -334,  -334,    -3,  -334,  -334,  -334,  -334,  -334,  -334,
    -334,  -334,  -334,  -334,  -334,  -334,  -334,  -334,  -334,    79,
    -333,  -334,  -334,  -334,  -334,  -334,  -334,  -334,  -334,  -334,
    -334,  -334,  -334,  -334,  -334,   -46,  -334,  -334,  -334,  -334,
    -334,  -334,  -334,  -334,  -334,  -334,  -334,  -334,   126,  -334,
    -334,  -182,  -334
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,     5,   220,   114,    18,    19,   221,   414,
     415,   234,   294,   399,   435,   222,     6,    21,    22,    33,
      40,    41,    79,    80,     7,     8,    24,    31,    43,    54,
      85,   103,     9,    25,    32,    49,    57,    93,    81,    90,
     109,   178,    91,   110,   310,   364,   168,   130,   251,   115,
     149,   116,   117,    82,    86,   104,   147,   207,   313,   404,
     442,   461,    87,   105,   148,   208,   366,   405,   443,   287,
     132,    99,   108,   170,    83,    88,   106,   151,   209,    84,
      89,   317,   368,   406,   369,   407,   318,   223,   262,   224,
     261,   304,   305,   133,   162,   242,   361,   425,   452,   184,
     225,   288,   134,   163,   164,   160,   161,   289,   290,   188,
     228,   344,   420,   239,   297,   382,   300,   299,   352,   356,
     135,   191,   384,   373,   408,   444,   394,   374,   136,   185,
     283,   137,   186,   284,   138,   155,   229,   377,   410,   235,
     236,   231,   346,   397,   347,   398,   433,   173,   203,   139,
     156,   140,   141,   190,   296,   423,   449,   451,   450,   176,
     204,   424,   142,   192,   301,   402,   143,   205,   249,   306,
     250,   144,   165
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      39,   246,   189,   253,    44,    45,    46,   247,   180,   240,
      78,    39,    23,   378,   226,    35,    39,    35,   211,   212,
     213,   174,   131,    92,   371,    77,   417,    11,   166,    35,
     211,   212,   213,    78,   -72,     1,    47,    92,    78,    10,
       2,  -198,  -200,   167,  -152,   302,   169,    78,    77,   252,
     214,    20,   175,    77,   309,   257,    47,   200,   215,    26,
     201,   129,    77,  -294,  -152,   412,   216,   255,    98,   -48,
      35,   211,   212,   213,    77,    47,   128,    27,   216,    35,
    -198,  -200,  -294,   232,   217,   129,   152,    95,    23,   218,
     292,   100,   219,    23,    35,    47,   217,  -186,    28,    29,
     128,   218,  -294,   214,   219,    36,    37,    38,   280,   281,
     282,   215,    35,   211,   212,   213,    77,   357,    77,   216,
     269,   270,   271,   272,    30,    42,     1,    34,   193,   194,
      47,     2,   278,   279,   280,   281,   282,   217,  -152,   375,
     -24,    35,   218,    48,   238,   219,    13,    14,    15,    16,
      17,   245,   278,   279,   280,   281,   282,    47,   233,   237,
      51,   216,  -111,   302,    53,    55,   244,   437,   438,   439,
     126,   127,   392,    56,    58,    77,   -83,    96,    97,   217,
      98,   129,   101,   102,   218,   372,   107,   219,   111,   112,
     113,   145,   150,   146,   153,   154,   128,   241,   293,   171,
     421,   157,   158,   248,   245,   396,   159,   172,   181,   418,
     177,   179,   187,   183,   195,   196,   199,   197,   198,   244,
     206,   258,   259,   260,   202,   210,   390,   256,   302,   227,
     230,   254,   291,   -40,   314,   295,   316,   348,   351,   345,
     409,   339,   360,   129,   298,   340,   350,   303,   457,   458,
     459,   341,   342,  -146,   307,   358,   311,   432,   128,   359,
     376,   363,   362,   233,   426,   379,   315,   353,   319,   320,
     321,   322,   323,   324,   325,   326,   327,   328,   329,   330,
     331,   332,   333,   334,   335,   336,   337,   338,   365,   454,
     380,   381,   456,   232,   383,   387,   385,   389,   393,   371,
     400,   462,   401,   403,   354,   411,   422,   464,    35,   211,
     212,   213,   232,   427,   233,    35,   211,   212,   213,   232,
     431,   428,   429,   436,   243,   434,    12,   445,   446,   448,
     453,    62,    63,    64,    77,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,   455,   214,   460,
     447,   463,    52,    50,    94,   386,   215,   216,   182,    35,
     211,   212,   213,   413,   216,   303,   233,   441,   370,   388,
     355,   395,    77,   391,   349,   217,   343,   312,   440,     0,
     218,     0,   217,   219,     0,     0,     0,   218,     0,     0,
     219,     0,     0,     0,    35,   211,   212,   213,   232,     0,
       0,     0,     0,   308,   416,   419,     0,     0,   216,     0,
      62,    63,    64,   430,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,   217,     0,    35,     0,
     303,   218,     0,     0,   219,     0,   118,     0,     0,   416,
       0,     0,     0,   216,    62,    63,    64,     0,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
     119,   217,     0,   120,   121,   122,   218,   123,   124,   219,
     125,     0,   285,   286,    35,     0,     0,     0,     0,     0,
       0,     0,   118,     0,     0,     0,   126,   127,     0,     0,
      62,    63,    64,     0,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,   119,     0,     0,   120,
     121,   122,     0,   123,   124,     0,   125,     0,    35,     0,
       0,     0,     0,     0,    59,    60,    61,     0,     0,     0,
       0,     0,   126,   127,    62,    63,    64,    35,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
       0,     0,     0,    62,    63,    64,     0,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,   263,
     264,     0,     0,   265,   266,   267,   268,   269,   270,   271,
     272,     0,     0,     0,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,     0,     0,   263,   264,     0,   367,
     265,   266,   267,   268,   269,   270,   271,   272,     0,     0,
       0,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   265,   266,   267,   268,   269,   270,   271,   272,     0,
       0,     0,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   265,   266,   267,   268,   269,   270,   271,   272,
       0,     0,     0,     0,     0,     0,   276,   277,   278,   279,
     280,   281,   282,   267,   268,   269,   270,   271,   272,     0,
       0,     0,     0,     0,     0,   276,   277,   278,   279,   280,
     281,   282
};

static const yytype_int16 yycheck[] =
{
      32,   198,   156,   204,    36,    37,    38,   198,   148,   191,
      57,    43,    19,   346,   186,     3,    48,     3,     4,     5,
       6,    51,   108,    80,    37,    57,    12,     0,     3,     3,
       4,     5,     6,    80,     3,     8,    76,    94,    85,     3,
      13,    61,    62,    18,    84,   242,   132,    94,    80,   203,
      36,     3,    82,    85,   251,   209,    76,    80,    44,    80,
      83,   108,    94,    83,    84,   398,    52,   207,    81,    22,
       3,     4,     5,     6,   106,    76,   108,    22,    52,     3,
      61,    62,    83,     7,    70,   132,   118,    86,    95,    75,
      78,    90,    78,   100,     3,    76,    70,    78,     3,    78,
     132,    75,    83,    36,    78,    14,    15,    16,    71,    72,
      73,    44,     3,     4,     5,     6,   148,   299,   150,    52,
      57,    58,    59,    60,     3,    80,     8,    78,   160,   161,
      76,    13,    69,    70,    71,    72,    73,    70,    84,   340,
      86,     3,    75,    77,   191,    78,    14,    15,    16,    17,
      18,   198,    69,    70,    71,    72,    73,    76,   190,   191,
       3,    52,     3,   360,    79,    81,   198,     4,     5,     6,
      61,    62,   369,    79,    81,   207,     3,     3,    78,    70,
      81,   228,     3,    82,    75,   339,    82,    78,    82,     3,
      78,     3,    77,    80,    78,    78,   228,   192,   230,    80,
     401,    78,    78,   198,   251,   377,    78,    63,     3,   400,
      80,    78,    81,    79,    78,    61,     3,    62,    83,   251,
      80,   216,   217,   218,    82,    80,   366,    79,   425,    82,
      41,    82,    38,    73,    78,    77,    84,    73,     3,    78,
     394,    79,    77,   290,   239,    79,    79,   242,   449,   450,
     451,    80,    80,     7,   249,    80,   251,   411,   290,    79,
      82,    80,    86,   295,   404,    78,   261,   299,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,    79,   443,
      78,    80,   446,     7,    80,    79,    81,    78,    78,    37,
      83,   455,    79,    78,   299,    79,    46,   461,     3,     4,
       5,     6,     7,    79,   346,     3,     4,     5,     6,     7,
      79,    85,    85,    80,    12,    77,     3,    80,    79,    79,
      79,    19,    20,    21,   366,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    79,    36,    79,
     434,    80,    48,    43,    85,   360,    44,    52,   150,     3,
       4,     5,     6,     7,    52,   360,   398,   425,   318,   364,
     299,   374,   404,   368,   295,    70,   290,   251,   424,    -1,
      75,    -1,    70,    78,    -1,    -1,    -1,    75,    -1,    -1,
      78,    -1,    -1,    -1,     3,     4,     5,     6,     7,    -1,
      -1,    -1,    -1,    12,   399,   400,    -1,    -1,    52,    -1,
      19,    20,    21,   408,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    70,    -1,     3,    -1,
     425,    75,    -1,    -1,    78,    -1,    11,    -1,    -1,   434,
      -1,    -1,    -1,    52,    19,    20,    21,    -1,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    70,    -1,    38,    39,    40,    75,    42,    43,    78,
      45,    -1,    47,    48,     3,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    11,    -1,    -1,    -1,    61,    62,    -1,    -1,
      19,    20,    21,    -1,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    -1,    -1,    38,
      39,    40,    -1,    42,    43,    -1,    45,    -1,     3,    -1,
      -1,    -1,    -1,    -1,     9,    10,    11,    -1,    -1,    -1,
      -1,    -1,    61,    62,    19,    20,    21,     3,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      -1,    -1,    -1,    19,    20,    21,    -1,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    49,
      50,    -1,    -1,    53,    54,    55,    56,    57,    58,    59,
      60,    -1,    -1,    -1,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    -1,    -1,    49,    50,    -1,    79,
      53,    54,    55,    56,    57,    58,    59,    60,    -1,    -1,
      -1,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    53,    54,    55,    56,    57,    58,    59,    60,    -1,
      -1,    -1,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    53,    54,    55,    56,    57,    58,    59,    60,
      -1,    -1,    -1,    -1,    -1,    -1,    67,    68,    69,    70,
      71,    72,    73,    55,    56,    57,    58,    59,    60,    -1,
      -1,    -1,    -1,    -1,    -1,    67,    68,    69,    70,    71,
      72,    73
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     8,    13,    88,    89,    90,   103,   111,   112,   119,
       3,     0,    89,    14,    15,    16,    17,    18,    93,    94,
       3,   104,   105,    93,   113,   120,    80,    22,     3,    78,
       3,   114,   121,   106,    78,     3,    14,    15,    16,    91,
     107,   108,    80,   115,    91,    91,    91,    76,    77,   122,
     108,     3,   107,    79,   116,    81,    79,   123,    81,     9,
      10,    11,    19,    20,    21,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    91,    92,   109,
     110,   125,   140,   161,   166,   117,   141,   149,   162,   167,
     126,   129,   109,   124,   110,    94,     3,    78,    81,   158,
      94,     3,    82,   118,   142,   150,   163,    82,   159,   127,
     130,    82,     3,    78,    92,   136,   138,   139,    11,    35,
      38,    39,    40,    42,    43,    45,    61,    62,    91,    92,
     134,   156,   157,   180,   189,   207,   215,   218,   221,   236,
     238,   239,   249,   253,   258,     3,    80,   143,   151,   137,
      77,   164,    91,    78,    78,   222,   237,    78,    78,    78,
     192,   193,   181,   190,   191,   259,     3,    18,   133,   156,
     160,    80,    63,   234,    51,    82,   246,    80,   128,    78,
     139,     3,   136,    79,   186,   216,   219,    81,   196,   158,
     240,   208,   250,    91,    91,    78,    61,    62,    83,     3,
      80,    83,    82,   235,   247,   254,    80,   144,   152,   165,
      80,     4,     5,     6,    36,    44,    52,    70,    75,    78,
      91,    95,   102,   174,   176,   187,   187,    82,   197,   223,
      41,   228,     7,    91,    98,   226,   227,    91,    92,   200,
     258,   176,   182,    12,    91,    92,    98,   102,   176,   255,
     257,   135,   158,   196,    82,   139,    79,   158,   176,   176,
     176,   177,   175,    49,    50,    53,    54,    55,    56,    57,
      58,    59,    60,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,   217,   220,    47,    48,   156,   188,   194,
     195,    38,    78,    91,    99,    77,   241,   201,   176,   204,
     203,   251,    98,   176,   178,   179,   256,   176,    12,    98,
     131,   176,   255,   145,    78,   176,    84,   168,   173,   176,
     176,   176,   176,   176,   176,   176,   176,   176,   176,   176,
     176,   176,   176,   176,   176,   176,   176,   176,   176,    79,
      79,    80,    80,   194,   198,    78,   229,   231,    73,   226,
      79,     3,   205,    91,   176,   189,   206,   258,    80,    79,
      77,   183,    86,    80,   132,    79,   153,    79,   169,   171,
     168,    37,   158,   210,   214,   196,    82,   224,   227,    78,
      78,    80,   202,    80,   209,    81,   178,    79,   176,    78,
     139,   176,    98,    78,   213,   210,   187,   230,   232,   100,
      83,    79,   252,    78,   146,   154,   170,   172,   211,   158,
     225,    79,   227,     7,    96,    97,   176,    12,   102,   176,
     199,   196,    46,   242,   248,   184,   139,    79,    85,    85,
     176,    79,   158,   233,    77,   101,    80,     4,     5,     6,
     242,   179,   147,   155,   212,    80,    79,    96,    79,   243,
     245,   244,   185,    79,   158,    79,   158,   196,   196,   196,
      79,   148,   158,    80,   158
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,    87,    88,    89,    89,    90,    90,    91,    91,    92,
      92,    92,    92,    92,    92,    92,    92,    92,    92,    92,
      92,    92,    92,    92,    92,    93,    93,    93,    93,    93,
      94,    94,    95,    95,    95,    96,    96,    97,    97,    98,
      99,   100,   101,    98,   102,   102,   104,   103,   105,   106,
     103,   107,   107,   107,   107,   108,   108,   108,   109,   109,
     109,   109,   110,   110,   112,   113,   114,   115,   116,   117,
     118,   111,   119,   120,   121,   122,   123,   124,   111,   126,
     127,   128,   125,   129,   130,   125,   131,   131,   132,   131,
     131,   133,   133,   134,   135,   134,   137,   136,   138,   138,
     139,   139,   141,   142,   143,   144,   145,   146,   147,   148,
     140,   149,   150,   151,   152,   153,   154,   155,   140,   156,
     156,   156,   156,   156,   156,   156,   156,   156,   156,   156,
     157,   157,   159,   160,   158,   158,   162,   163,   164,   165,
     161,   167,   166,   169,   170,   168,   171,   172,   168,   173,
     173,   174,   175,   174,   176,   176,   176,   176,   176,   176,
     176,   176,   176,   176,   176,   176,   176,   176,   176,   176,
     176,   176,   176,   176,   176,   176,   176,   176,   176,   177,
     176,   178,   178,   179,   179,   179,   181,   182,   183,   184,
     185,   180,   186,   180,   187,   187,   188,   188,   190,   189,
     191,   189,   192,   189,   193,   189,   194,   194,   195,   195,
     196,   197,   198,   196,   199,   199,   199,   201,   202,   200,
     203,   200,   205,   204,   206,   206,   206,   208,   209,   207,
     211,   212,   210,   213,   210,   214,   214,   214,   216,   217,
     215,   219,   220,   218,   222,   223,   224,   225,   221,   226,
     226,   226,   227,   227,   229,   230,   228,   231,   232,   233,
     228,   235,   234,   237,   236,   238,   238,   240,   241,   239,
     243,   242,   244,   242,   245,   242,   247,   246,   248,   248,
     250,   251,   252,   249,   253,   254,   253,   256,   255,   257,
     257,   257,   257,   257,   259,   258
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     2,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     1,     1,     1,     1,     1,     1,     3,     1,
       0,     0,     0,     8,     1,     1,     0,     4,     0,     0,
       7,     2,     2,     2,     1,     1,     3,     0,     1,     1,
       1,     1,     1,     2,     0,     0,     0,     0,     0,     0,
       0,    16,     0,     0,     0,     0,     0,     0,    14,     0,
       0,     0,     7,     0,     0,     5,     1,     1,     0,     3,
       1,     1,     2,     3,     0,     6,     0,     3,     1,     3,
       1,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      18,     0,     0,     0,     0,     0,     0,     0,    16,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     2,
       1,     2,     0,     0,     5,     2,     0,     0,     0,     0,
       9,     0,     3,     0,     0,     5,     0,     0,     5,     1,
       2,     1,     0,     3,     1,     1,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     2,     2,     2,     0,
       4,     1,     1,     0,     1,     3,     0,     0,     0,     0,
       0,    13,     0,     4,     1,     1,     2,     2,     0,     3,
       0,     3,     0,     3,     0,     3,     1,     1,     1,     2,
       2,     0,     0,     5,     1,     1,     1,     0,     0,     7,
       0,     3,     0,     3,     1,     1,     1,     0,     0,     9,
       0,     0,     7,     0,     3,     1,     2,     1,     0,     0,
       7,     0,     0,     7,     0,     0,     0,     0,    11,     0,
       1,     1,     1,     3,     0,     0,     7,     0,     0,     0,
       9,     0,     3,     0,     4,     1,     2,     0,     0,     7,
       0,     4,     0,     4,     0,     4,     0,     3,     1,     2,
       0,     0,     0,     9,     2,     0,     4,     0,     3,     1,
       1,     2,     1,     1,     0,     4
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  YYUSE (yylocationp);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyo, *yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
{
  unsigned long yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return (YYSIZE_T) (yystpcpy (yyres, yystr) - yyres);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.
       'yyls': related to locations.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yynewstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  *yyssp = (yytype_int16) yystate;

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = (YYSIZE_T) (yyssp - yyss + 1);

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yyls1, yysize * sizeof (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 45 "parser.y" /* yacc.c:1652  */
    {}
#line 1825 "parser.c" /* yacc.c:1652  */
    break;

  case 3:
#line 49 "parser.y" /* yacc.c:1652  */
    {}
#line 1831 "parser.c" /* yacc.c:1652  */
    break;

  case 4:
#line 50 "parser.y" /* yacc.c:1652  */
    {}
#line 1837 "parser.c" /* yacc.c:1652  */
    break;

  case 5:
#line 54 "parser.y" /* yacc.c:1652  */
    {}
#line 1843 "parser.c" /* yacc.c:1652  */
    break;

  case 6:
#line 55 "parser.y" /* yacc.c:1652  */
    {}
#line 1849 "parser.c" /* yacc.c:1652  */
    break;

  case 7:
#line 62 "parser.y" /* yacc.c:1652  */
    {}
#line 1855 "parser.c" /* yacc.c:1652  */
    break;

  case 8:
#line 63 "parser.y" /* yacc.c:1652  */
    {}
#line 1861 "parser.c" /* yacc.c:1652  */
    break;

  case 9:
#line 67 "parser.y" /* yacc.c:1652  */
    {}
#line 1867 "parser.c" /* yacc.c:1652  */
    break;

  case 10:
#line 68 "parser.y" /* yacc.c:1652  */
    {}
#line 1873 "parser.c" /* yacc.c:1652  */
    break;

  case 11:
#line 69 "parser.y" /* yacc.c:1652  */
    {}
#line 1879 "parser.c" /* yacc.c:1652  */
    break;

  case 12:
#line 70 "parser.y" /* yacc.c:1652  */
    {}
#line 1885 "parser.c" /* yacc.c:1652  */
    break;

  case 13:
#line 71 "parser.y" /* yacc.c:1652  */
    {}
#line 1891 "parser.c" /* yacc.c:1652  */
    break;

  case 14:
#line 72 "parser.y" /* yacc.c:1652  */
    {}
#line 1897 "parser.c" /* yacc.c:1652  */
    break;

  case 15:
#line 73 "parser.y" /* yacc.c:1652  */
    {}
#line 1903 "parser.c" /* yacc.c:1652  */
    break;

  case 16:
#line 74 "parser.y" /* yacc.c:1652  */
    {}
#line 1909 "parser.c" /* yacc.c:1652  */
    break;

  case 17:
#line 75 "parser.y" /* yacc.c:1652  */
    {}
#line 1915 "parser.c" /* yacc.c:1652  */
    break;

  case 18:
#line 76 "parser.y" /* yacc.c:1652  */
    {}
#line 1921 "parser.c" /* yacc.c:1652  */
    break;

  case 19:
#line 77 "parser.y" /* yacc.c:1652  */
    {}
#line 1927 "parser.c" /* yacc.c:1652  */
    break;

  case 20:
#line 78 "parser.y" /* yacc.c:1652  */
    {}
#line 1933 "parser.c" /* yacc.c:1652  */
    break;

  case 21:
#line 79 "parser.y" /* yacc.c:1652  */
    {}
#line 1939 "parser.c" /* yacc.c:1652  */
    break;

  case 22:
#line 80 "parser.y" /* yacc.c:1652  */
    {}
#line 1945 "parser.c" /* yacc.c:1652  */
    break;

  case 23:
#line 81 "parser.y" /* yacc.c:1652  */
    {}
#line 1951 "parser.c" /* yacc.c:1652  */
    break;

  case 24:
#line 82 "parser.y" /* yacc.c:1652  */
    {}
#line 1957 "parser.c" /* yacc.c:1652  */
    break;

  case 25:
#line 86 "parser.y" /* yacc.c:1652  */
    {}
#line 1963 "parser.c" /* yacc.c:1652  */
    break;

  case 26:
#line 87 "parser.y" /* yacc.c:1652  */
    {}
#line 1969 "parser.c" /* yacc.c:1652  */
    break;

  case 27:
#line 88 "parser.y" /* yacc.c:1652  */
    {}
#line 1975 "parser.c" /* yacc.c:1652  */
    break;

  case 28:
#line 89 "parser.y" /* yacc.c:1652  */
    {}
#line 1981 "parser.c" /* yacc.c:1652  */
    break;

  case 29:
#line 90 "parser.y" /* yacc.c:1652  */
    {}
#line 1987 "parser.c" /* yacc.c:1652  */
    break;

  case 30:
#line 94 "parser.y" /* yacc.c:1652  */
    {}
#line 1993 "parser.c" /* yacc.c:1652  */
    break;

  case 31:
#line 95 "parser.y" /* yacc.c:1652  */
    {}
#line 1999 "parser.c" /* yacc.c:1652  */
    break;

  case 32:
#line 99 "parser.y" /* yacc.c:1652  */
    {}
#line 2005 "parser.c" /* yacc.c:1652  */
    break;

  case 33:
#line 100 "parser.y" /* yacc.c:1652  */
    {}
#line 2011 "parser.c" /* yacc.c:1652  */
    break;

  case 34:
#line 101 "parser.y" /* yacc.c:1652  */
    {}
#line 2017 "parser.c" /* yacc.c:1652  */
    break;

  case 35:
#line 105 "parser.y" /* yacc.c:1652  */
    {}
#line 2023 "parser.c" /* yacc.c:1652  */
    break;

  case 36:
#line 106 "parser.y" /* yacc.c:1652  */
    {}
#line 2029 "parser.c" /* yacc.c:1652  */
    break;

  case 37:
#line 110 "parser.y" /* yacc.c:1652  */
    {}
#line 2035 "parser.c" /* yacc.c:1652  */
    break;

  case 38:
#line 111 "parser.y" /* yacc.c:1652  */
    {}
#line 2041 "parser.c" /* yacc.c:1652  */
    break;

  case 39:
#line 115 "parser.y" /* yacc.c:1652  */
    {}
#line 2047 "parser.c" /* yacc.c:1652  */
    break;

  case 40:
#line 116 "parser.y" /* yacc.c:1652  */
    {}
#line 2053 "parser.c" /* yacc.c:1652  */
    break;

  case 41:
#line 116 "parser.y" /* yacc.c:1652  */
    {}
#line 2059 "parser.c" /* yacc.c:1652  */
    break;

  case 42:
#line 116 "parser.y" /* yacc.c:1652  */
    {}
#line 2065 "parser.c" /* yacc.c:1652  */
    break;

  case 44:
#line 120 "parser.y" /* yacc.c:1652  */
    {}
#line 2071 "parser.c" /* yacc.c:1652  */
    break;

  case 45:
#line 121 "parser.y" /* yacc.c:1652  */
    {}
#line 2077 "parser.c" /* yacc.c:1652  */
    break;

  case 46:
#line 128 "parser.y" /* yacc.c:1652  */
    {}
#line 2083 "parser.c" /* yacc.c:1652  */
    break;

  case 47:
#line 128 "parser.y" /* yacc.c:1652  */
    {}
#line 2089 "parser.c" /* yacc.c:1652  */
    break;

  case 48:
#line 129 "parser.y" /* yacc.c:1652  */
    {}
#line 2095 "parser.c" /* yacc.c:1652  */
    break;

  case 49:
#line 129 "parser.y" /* yacc.c:1652  */
    {}
#line 2101 "parser.c" /* yacc.c:1652  */
    break;

  case 50:
#line 129 "parser.y" /* yacc.c:1652  */
    {}
#line 2107 "parser.c" /* yacc.c:1652  */
    break;

  case 51:
#line 136 "parser.y" /* yacc.c:1652  */
    {}
#line 2113 "parser.c" /* yacc.c:1652  */
    break;

  case 52:
#line 137 "parser.y" /* yacc.c:1652  */
    {}
#line 2119 "parser.c" /* yacc.c:1652  */
    break;

  case 53:
#line 138 "parser.y" /* yacc.c:1652  */
    {}
#line 2125 "parser.c" /* yacc.c:1652  */
    break;

  case 54:
#line 139 "parser.y" /* yacc.c:1652  */
    {}
#line 2131 "parser.c" /* yacc.c:1652  */
    break;

  case 55:
#line 143 "parser.y" /* yacc.c:1652  */
    {}
#line 2137 "parser.c" /* yacc.c:1652  */
    break;

  case 56:
#line 144 "parser.y" /* yacc.c:1652  */
    {}
#line 2143 "parser.c" /* yacc.c:1652  */
    break;

  case 58:
#line 149 "parser.y" /* yacc.c:1652  */
    {}
#line 2149 "parser.c" /* yacc.c:1652  */
    break;

  case 59:
#line 150 "parser.y" /* yacc.c:1652  */
    {}
#line 2155 "parser.c" /* yacc.c:1652  */
    break;

  case 60:
#line 151 "parser.y" /* yacc.c:1652  */
    {}
#line 2161 "parser.c" /* yacc.c:1652  */
    break;

  case 61:
#line 152 "parser.y" /* yacc.c:1652  */
    {}
#line 2167 "parser.c" /* yacc.c:1652  */
    break;

  case 62:
#line 156 "parser.y" /* yacc.c:1652  */
    {}
#line 2173 "parser.c" /* yacc.c:1652  */
    break;

  case 63:
#line 157 "parser.y" /* yacc.c:1652  */
    {}
#line 2179 "parser.c" /* yacc.c:1652  */
    break;

  case 64:
#line 161 "parser.y" /* yacc.c:1652  */
    {}
#line 2185 "parser.c" /* yacc.c:1652  */
    break;

  case 65:
#line 161 "parser.y" /* yacc.c:1652  */
    {}
#line 2191 "parser.c" /* yacc.c:1652  */
    break;

  case 66:
#line 161 "parser.y" /* yacc.c:1652  */
    {}
#line 2197 "parser.c" /* yacc.c:1652  */
    break;

  case 67:
#line 161 "parser.y" /* yacc.c:1652  */
    {}
#line 2203 "parser.c" /* yacc.c:1652  */
    break;

  case 68:
#line 161 "parser.y" /* yacc.c:1652  */
    {}
#line 2209 "parser.c" /* yacc.c:1652  */
    break;

  case 69:
#line 161 "parser.y" /* yacc.c:1652  */
    {}
#line 2215 "parser.c" /* yacc.c:1652  */
    break;

  case 70:
#line 161 "parser.y" /* yacc.c:1652  */
    {}
#line 2221 "parser.c" /* yacc.c:1652  */
    break;

  case 72:
#line 162 "parser.y" /* yacc.c:1652  */
    {}
#line 2227 "parser.c" /* yacc.c:1652  */
    break;

  case 73:
#line 162 "parser.y" /* yacc.c:1652  */
    {}
#line 2233 "parser.c" /* yacc.c:1652  */
    break;

  case 74:
#line 162 "parser.y" /* yacc.c:1652  */
    {}
#line 2239 "parser.c" /* yacc.c:1652  */
    break;

  case 75:
#line 162 "parser.y" /* yacc.c:1652  */
    {}
#line 2245 "parser.c" /* yacc.c:1652  */
    break;

  case 76:
#line 162 "parser.y" /* yacc.c:1652  */
    {}
#line 2251 "parser.c" /* yacc.c:1652  */
    break;

  case 77:
#line 162 "parser.y" /* yacc.c:1652  */
    {}
#line 2257 "parser.c" /* yacc.c:1652  */
    break;

  case 79:
#line 169 "parser.y" /* yacc.c:1652  */
    {}
#line 2263 "parser.c" /* yacc.c:1652  */
    break;

  case 80:
#line 169 "parser.y" /* yacc.c:1652  */
    {}
#line 2269 "parser.c" /* yacc.c:1652  */
    break;

  case 81:
#line 169 "parser.y" /* yacc.c:1652  */
    {}
#line 2275 "parser.c" /* yacc.c:1652  */
    break;

  case 82:
#line 169 "parser.y" /* yacc.c:1652  */
    {}
#line 2281 "parser.c" /* yacc.c:1652  */
    break;

  case 83:
#line 170 "parser.y" /* yacc.c:1652  */
    {}
#line 2287 "parser.c" /* yacc.c:1652  */
    break;

  case 84:
#line 170 "parser.y" /* yacc.c:1652  */
    {}
#line 2293 "parser.c" /* yacc.c:1652  */
    break;

  case 85:
#line 170 "parser.y" /* yacc.c:1652  */
    {}
#line 2299 "parser.c" /* yacc.c:1652  */
    break;

  case 86:
#line 174 "parser.y" /* yacc.c:1652  */
    {}
#line 2305 "parser.c" /* yacc.c:1652  */
    break;

  case 87:
#line 175 "parser.y" /* yacc.c:1652  */
    {}
#line 2311 "parser.c" /* yacc.c:1652  */
    break;

  case 88:
#line 176 "parser.y" /* yacc.c:1652  */
    {}
#line 2317 "parser.c" /* yacc.c:1652  */
    break;

  case 89:
#line 176 "parser.y" /* yacc.c:1652  */
    {}
#line 2323 "parser.c" /* yacc.c:1652  */
    break;

  case 90:
#line 177 "parser.y" /* yacc.c:1652  */
    {}
#line 2329 "parser.c" /* yacc.c:1652  */
    break;

  case 91:
#line 181 "parser.y" /* yacc.c:1652  */
    {}
#line 2335 "parser.c" /* yacc.c:1652  */
    break;

  case 92:
#line 182 "parser.y" /* yacc.c:1652  */
    {}
#line 2341 "parser.c" /* yacc.c:1652  */
    break;

  case 93:
#line 186 "parser.y" /* yacc.c:1652  */
    {}
#line 2347 "parser.c" /* yacc.c:1652  */
    break;

  case 94:
#line 187 "parser.y" /* yacc.c:1652  */
    {}
#line 2353 "parser.c" /* yacc.c:1652  */
    break;

  case 95:
#line 187 "parser.y" /* yacc.c:1652  */
    {}
#line 2359 "parser.c" /* yacc.c:1652  */
    break;

  case 96:
#line 194 "parser.y" /* yacc.c:1652  */
    {}
#line 2365 "parser.c" /* yacc.c:1652  */
    break;

  case 97:
#line 194 "parser.y" /* yacc.c:1652  */
    {}
#line 2371 "parser.c" /* yacc.c:1652  */
    break;

  case 98:
#line 198 "parser.y" /* yacc.c:1652  */
    {}
#line 2377 "parser.c" /* yacc.c:1652  */
    break;

  case 99:
#line 199 "parser.y" /* yacc.c:1652  */
    {}
#line 2383 "parser.c" /* yacc.c:1652  */
    break;

  case 100:
#line 203 "parser.y" /* yacc.c:1652  */
    {}
#line 2389 "parser.c" /* yacc.c:1652  */
    break;

  case 102:
#line 208 "parser.y" /* yacc.c:1652  */
    {}
#line 2395 "parser.c" /* yacc.c:1652  */
    break;

  case 103:
#line 208 "parser.y" /* yacc.c:1652  */
    {}
#line 2401 "parser.c" /* yacc.c:1652  */
    break;

  case 104:
#line 208 "parser.y" /* yacc.c:1652  */
    {}
#line 2407 "parser.c" /* yacc.c:1652  */
    break;

  case 105:
#line 208 "parser.y" /* yacc.c:1652  */
    {}
#line 2413 "parser.c" /* yacc.c:1652  */
    break;

  case 106:
#line 208 "parser.y" /* yacc.c:1652  */
    {}
#line 2419 "parser.c" /* yacc.c:1652  */
    break;

  case 107:
#line 208 "parser.y" /* yacc.c:1652  */
    {}
#line 2425 "parser.c" /* yacc.c:1652  */
    break;

  case 108:
#line 208 "parser.y" /* yacc.c:1652  */
    {}
#line 2431 "parser.c" /* yacc.c:1652  */
    break;

  case 109:
#line 208 "parser.y" /* yacc.c:1652  */
    {}
#line 2437 "parser.c" /* yacc.c:1652  */
    break;

  case 110:
#line 208 "parser.y" /* yacc.c:1652  */
    {}
#line 2443 "parser.c" /* yacc.c:1652  */
    break;

  case 111:
#line 209 "parser.y" /* yacc.c:1652  */
    {}
#line 2449 "parser.c" /* yacc.c:1652  */
    break;

  case 112:
#line 209 "parser.y" /* yacc.c:1652  */
    {}
#line 2455 "parser.c" /* yacc.c:1652  */
    break;

  case 113:
#line 209 "parser.y" /* yacc.c:1652  */
    {}
#line 2461 "parser.c" /* yacc.c:1652  */
    break;

  case 114:
#line 209 "parser.y" /* yacc.c:1652  */
    {}
#line 2467 "parser.c" /* yacc.c:1652  */
    break;

  case 115:
#line 209 "parser.y" /* yacc.c:1652  */
    {}
#line 2473 "parser.c" /* yacc.c:1652  */
    break;

  case 116:
#line 209 "parser.y" /* yacc.c:1652  */
    {}
#line 2479 "parser.c" /* yacc.c:1652  */
    break;

  case 117:
#line 209 "parser.y" /* yacc.c:1652  */
    {}
#line 2485 "parser.c" /* yacc.c:1652  */
    break;

  case 118:
#line 209 "parser.y" /* yacc.c:1652  */
    {}
#line 2491 "parser.c" /* yacc.c:1652  */
    break;

  case 119:
#line 213 "parser.y" /* yacc.c:1652  */
    {}
#line 2497 "parser.c" /* yacc.c:1652  */
    break;

  case 120:
#line 214 "parser.y" /* yacc.c:1652  */
    {}
#line 2503 "parser.c" /* yacc.c:1652  */
    break;

  case 121:
#line 215 "parser.y" /* yacc.c:1652  */
    {}
#line 2509 "parser.c" /* yacc.c:1652  */
    break;

  case 122:
#line 216 "parser.y" /* yacc.c:1652  */
    {}
#line 2515 "parser.c" /* yacc.c:1652  */
    break;

  case 123:
#line 217 "parser.y" /* yacc.c:1652  */
    {}
#line 2521 "parser.c" /* yacc.c:1652  */
    break;

  case 124:
#line 218 "parser.y" /* yacc.c:1652  */
    {}
#line 2527 "parser.c" /* yacc.c:1652  */
    break;

  case 125:
#line 219 "parser.y" /* yacc.c:1652  */
    {}
#line 2533 "parser.c" /* yacc.c:1652  */
    break;

  case 126:
#line 220 "parser.y" /* yacc.c:1652  */
    {}
#line 2539 "parser.c" /* yacc.c:1652  */
    break;

  case 127:
#line 221 "parser.y" /* yacc.c:1652  */
    {}
#line 2545 "parser.c" /* yacc.c:1652  */
    break;

  case 128:
#line 222 "parser.y" /* yacc.c:1652  */
    {}
#line 2551 "parser.c" /* yacc.c:1652  */
    break;

  case 129:
#line 223 "parser.y" /* yacc.c:1652  */
    {}
#line 2557 "parser.c" /* yacc.c:1652  */
    break;

  case 130:
#line 227 "parser.y" /* yacc.c:1652  */
    {}
#line 2563 "parser.c" /* yacc.c:1652  */
    break;

  case 131:
#line 228 "parser.y" /* yacc.c:1652  */
    {}
#line 2569 "parser.c" /* yacc.c:1652  */
    break;

  case 132:
#line 232 "parser.y" /* yacc.c:1652  */
    {}
#line 2575 "parser.c" /* yacc.c:1652  */
    break;

  case 133:
#line 232 "parser.y" /* yacc.c:1652  */
    {}
#line 2581 "parser.c" /* yacc.c:1652  */
    break;

  case 134:
#line 232 "parser.y" /* yacc.c:1652  */
    {}
#line 2587 "parser.c" /* yacc.c:1652  */
    break;

  case 135:
#line 233 "parser.y" /* yacc.c:1652  */
    {}
#line 2593 "parser.c" /* yacc.c:1652  */
    break;

  case 136:
#line 237 "parser.y" /* yacc.c:1652  */
    {}
#line 2599 "parser.c" /* yacc.c:1652  */
    break;

  case 137:
#line 237 "parser.y" /* yacc.c:1652  */
    {}
#line 2605 "parser.c" /* yacc.c:1652  */
    break;

  case 138:
#line 237 "parser.y" /* yacc.c:1652  */
    {}
#line 2611 "parser.c" /* yacc.c:1652  */
    break;

  case 139:
#line 237 "parser.y" /* yacc.c:1652  */
    {}
#line 2617 "parser.c" /* yacc.c:1652  */
    break;

  case 140:
#line 237 "parser.y" /* yacc.c:1652  */
    {}
#line 2623 "parser.c" /* yacc.c:1652  */
    break;

  case 141:
#line 241 "parser.y" /* yacc.c:1652  */
    {}
#line 2629 "parser.c" /* yacc.c:1652  */
    break;

  case 142:
#line 241 "parser.y" /* yacc.c:1652  */
    {}
#line 2635 "parser.c" /* yacc.c:1652  */
    break;

  case 143:
#line 251 "parser.y" /* yacc.c:1652  */
    {}
#line 2641 "parser.c" /* yacc.c:1652  */
    break;

  case 144:
#line 251 "parser.y" /* yacc.c:1652  */
    {}
#line 2647 "parser.c" /* yacc.c:1652  */
    break;

  case 146:
#line 252 "parser.y" /* yacc.c:1652  */
    {}
#line 2653 "parser.c" /* yacc.c:1652  */
    break;

  case 147:
#line 252 "parser.y" /* yacc.c:1652  */
    {}
#line 2659 "parser.c" /* yacc.c:1652  */
    break;

  case 149:
#line 256 "parser.y" /* yacc.c:1652  */
    {}
#line 2665 "parser.c" /* yacc.c:1652  */
    break;

  case 150:
#line 257 "parser.y" /* yacc.c:1652  */
    {}
#line 2671 "parser.c" /* yacc.c:1652  */
    break;

  case 151:
#line 260 "parser.y" /* yacc.c:1652  */
    {}
#line 2677 "parser.c" /* yacc.c:1652  */
    break;

  case 152:
#line 261 "parser.y" /* yacc.c:1652  */
    {}
#line 2683 "parser.c" /* yacc.c:1652  */
    break;

  case 153:
#line 261 "parser.y" /* yacc.c:1652  */
    {}
#line 2689 "parser.c" /* yacc.c:1652  */
    break;

  case 154:
#line 265 "parser.y" /* yacc.c:1652  */
    {}
#line 2695 "parser.c" /* yacc.c:1652  */
    break;

  case 155:
#line 266 "parser.y" /* yacc.c:1652  */
    {}
#line 2701 "parser.c" /* yacc.c:1652  */
    break;

  case 156:
#line 267 "parser.y" /* yacc.c:1652  */
    {}
#line 2707 "parser.c" /* yacc.c:1652  */
    break;

  case 157:
#line 268 "parser.y" /* yacc.c:1652  */
    {}
#line 2713 "parser.c" /* yacc.c:1652  */
    break;

  case 158:
#line 269 "parser.y" /* yacc.c:1652  */
    {}
#line 2719 "parser.c" /* yacc.c:1652  */
    break;

  case 159:
#line 270 "parser.y" /* yacc.c:1652  */
    {}
#line 2725 "parser.c" /* yacc.c:1652  */
    break;

  case 160:
#line 271 "parser.y" /* yacc.c:1652  */
    {}
#line 2731 "parser.c" /* yacc.c:1652  */
    break;

  case 161:
#line 272 "parser.y" /* yacc.c:1652  */
    {}
#line 2737 "parser.c" /* yacc.c:1652  */
    break;

  case 162:
#line 273 "parser.y" /* yacc.c:1652  */
    {}
#line 2743 "parser.c" /* yacc.c:1652  */
    break;

  case 163:
#line 274 "parser.y" /* yacc.c:1652  */
    {}
#line 2749 "parser.c" /* yacc.c:1652  */
    break;

  case 164:
#line 275 "parser.y" /* yacc.c:1652  */
    {}
#line 2755 "parser.c" /* yacc.c:1652  */
    break;

  case 165:
#line 276 "parser.y" /* yacc.c:1652  */
    {}
#line 2761 "parser.c" /* yacc.c:1652  */
    break;

  case 166:
#line 277 "parser.y" /* yacc.c:1652  */
    {}
#line 2767 "parser.c" /* yacc.c:1652  */
    break;

  case 167:
#line 278 "parser.y" /* yacc.c:1652  */
    {}
#line 2773 "parser.c" /* yacc.c:1652  */
    break;

  case 168:
#line 279 "parser.y" /* yacc.c:1652  */
    {}
#line 2779 "parser.c" /* yacc.c:1652  */
    break;

  case 169:
#line 280 "parser.y" /* yacc.c:1652  */
    {}
#line 2785 "parser.c" /* yacc.c:1652  */
    break;

  case 170:
#line 281 "parser.y" /* yacc.c:1652  */
    {}
#line 2791 "parser.c" /* yacc.c:1652  */
    break;

  case 171:
#line 282 "parser.y" /* yacc.c:1652  */
    {}
#line 2797 "parser.c" /* yacc.c:1652  */
    break;

  case 172:
#line 283 "parser.y" /* yacc.c:1652  */
    {}
#line 2803 "parser.c" /* yacc.c:1652  */
    break;

  case 173:
#line 284 "parser.y" /* yacc.c:1652  */
    {}
#line 2809 "parser.c" /* yacc.c:1652  */
    break;

  case 174:
#line 285 "parser.y" /* yacc.c:1652  */
    {}
#line 2815 "parser.c" /* yacc.c:1652  */
    break;

  case 175:
#line 286 "parser.y" /* yacc.c:1652  */
    {}
#line 2821 "parser.c" /* yacc.c:1652  */
    break;

  case 176:
#line 287 "parser.y" /* yacc.c:1652  */
    {}
#line 2827 "parser.c" /* yacc.c:1652  */
    break;

  case 177:
#line 288 "parser.y" /* yacc.c:1652  */
    {}
#line 2833 "parser.c" /* yacc.c:1652  */
    break;

  case 178:
#line 289 "parser.y" /* yacc.c:1652  */
    {}
#line 2839 "parser.c" /* yacc.c:1652  */
    break;

  case 179:
#line 290 "parser.y" /* yacc.c:1652  */
    {}
#line 2845 "parser.c" /* yacc.c:1652  */
    break;

  case 180:
#line 290 "parser.y" /* yacc.c:1652  */
    {}
#line 2851 "parser.c" /* yacc.c:1652  */
    break;

  case 181:
#line 301 "parser.y" /* yacc.c:1652  */
    {}
#line 2857 "parser.c" /* yacc.c:1652  */
    break;

  case 182:
#line 302 "parser.y" /* yacc.c:1652  */
    {}
#line 2863 "parser.c" /* yacc.c:1652  */
    break;

  case 184:
#line 307 "parser.y" /* yacc.c:1652  */
    {}
#line 2869 "parser.c" /* yacc.c:1652  */
    break;

  case 185:
#line 308 "parser.y" /* yacc.c:1652  */
    {}
#line 2875 "parser.c" /* yacc.c:1652  */
    break;

  case 186:
#line 312 "parser.y" /* yacc.c:1652  */
    {}
#line 2881 "parser.c" /* yacc.c:1652  */
    break;

  case 187:
#line 312 "parser.y" /* yacc.c:1652  */
    {}
#line 2887 "parser.c" /* yacc.c:1652  */
    break;

  case 188:
#line 312 "parser.y" /* yacc.c:1652  */
    {}
#line 2893 "parser.c" /* yacc.c:1652  */
    break;

  case 189:
#line 312 "parser.y" /* yacc.c:1652  */
    {}
#line 2899 "parser.c" /* yacc.c:1652  */
    break;

  case 190:
#line 312 "parser.y" /* yacc.c:1652  */
    {}
#line 2905 "parser.c" /* yacc.c:1652  */
    break;

  case 191:
#line 312 "parser.y" /* yacc.c:1652  */
    {}
#line 2911 "parser.c" /* yacc.c:1652  */
    break;

  case 192:
#line 313 "parser.y" /* yacc.c:1652  */
    {}
#line 2917 "parser.c" /* yacc.c:1652  */
    break;

  case 193:
#line 313 "parser.y" /* yacc.c:1652  */
    {}
#line 2923 "parser.c" /* yacc.c:1652  */
    break;

  case 194:
#line 320 "parser.y" /* yacc.c:1652  */
    {}
#line 2929 "parser.c" /* yacc.c:1652  */
    break;

  case 195:
#line 321 "parser.y" /* yacc.c:1652  */
    {}
#line 2935 "parser.c" /* yacc.c:1652  */
    break;

  case 196:
#line 326 "parser.y" /* yacc.c:1652  */
    {}
#line 2941 "parser.c" /* yacc.c:1652  */
    break;

  case 197:
#line 327 "parser.y" /* yacc.c:1652  */
    {}
#line 2947 "parser.c" /* yacc.c:1652  */
    break;

  case 198:
#line 331 "parser.y" /* yacc.c:1652  */
    {}
#line 2953 "parser.c" /* yacc.c:1652  */
    break;

  case 199:
#line 331 "parser.y" /* yacc.c:1652  */
    {}
#line 2959 "parser.c" /* yacc.c:1652  */
    break;

  case 200:
#line 332 "parser.y" /* yacc.c:1652  */
    {}
#line 2965 "parser.c" /* yacc.c:1652  */
    break;

  case 201:
#line 332 "parser.y" /* yacc.c:1652  */
    {}
#line 2971 "parser.c" /* yacc.c:1652  */
    break;

  case 202:
#line 333 "parser.y" /* yacc.c:1652  */
    {}
#line 2977 "parser.c" /* yacc.c:1652  */
    break;

  case 203:
#line 333 "parser.y" /* yacc.c:1652  */
    {}
#line 2983 "parser.c" /* yacc.c:1652  */
    break;

  case 204:
#line 334 "parser.y" /* yacc.c:1652  */
    {}
#line 2989 "parser.c" /* yacc.c:1652  */
    break;

  case 205:
#line 334 "parser.y" /* yacc.c:1652  */
    {}
#line 2995 "parser.c" /* yacc.c:1652  */
    break;

  case 206:
#line 338 "parser.y" /* yacc.c:1652  */
    {}
#line 3001 "parser.c" /* yacc.c:1652  */
    break;

  case 207:
#line 339 "parser.y" /* yacc.c:1652  */
    {}
#line 3007 "parser.c" /* yacc.c:1652  */
    break;

  case 208:
#line 343 "parser.y" /* yacc.c:1652  */
    {}
#line 3013 "parser.c" /* yacc.c:1652  */
    break;

  case 209:
#line 344 "parser.y" /* yacc.c:1652  */
    {}
#line 3019 "parser.c" /* yacc.c:1652  */
    break;

  case 210:
#line 348 "parser.y" /* yacc.c:1652  */
    {}
#line 3025 "parser.c" /* yacc.c:1652  */
    break;

  case 211:
#line 349 "parser.y" /* yacc.c:1652  */
    {}
#line 3031 "parser.c" /* yacc.c:1652  */
    break;

  case 212:
#line 349 "parser.y" /* yacc.c:1652  */
    {}
#line 3037 "parser.c" /* yacc.c:1652  */
    break;

  case 213:
#line 349 "parser.y" /* yacc.c:1652  */
    {}
#line 3043 "parser.c" /* yacc.c:1652  */
    break;

  case 214:
#line 356 "parser.y" /* yacc.c:1652  */
    {}
#line 3049 "parser.c" /* yacc.c:1652  */
    break;

  case 215:
#line 357 "parser.y" /* yacc.c:1652  */
    {}
#line 3055 "parser.c" /* yacc.c:1652  */
    break;

  case 216:
#line 358 "parser.y" /* yacc.c:1652  */
    {}
#line 3061 "parser.c" /* yacc.c:1652  */
    break;

  case 217:
#line 362 "parser.y" /* yacc.c:1652  */
    {}
#line 3067 "parser.c" /* yacc.c:1652  */
    break;

  case 218:
#line 362 "parser.y" /* yacc.c:1652  */
    {}
#line 3073 "parser.c" /* yacc.c:1652  */
    break;

  case 219:
#line 362 "parser.y" /* yacc.c:1652  */
    {}
#line 3079 "parser.c" /* yacc.c:1652  */
    break;

  case 220:
#line 363 "parser.y" /* yacc.c:1652  */
    {}
#line 3085 "parser.c" /* yacc.c:1652  */
    break;

  case 221:
#line 363 "parser.y" /* yacc.c:1652  */
    {}
#line 3091 "parser.c" /* yacc.c:1652  */
    break;

  case 222:
#line 368 "parser.y" /* yacc.c:1652  */
    {}
#line 3097 "parser.c" /* yacc.c:1652  */
    break;

  case 223:
#line 368 "parser.y" /* yacc.c:1652  */
    {}
#line 3103 "parser.c" /* yacc.c:1652  */
    break;

  case 224:
#line 372 "parser.y" /* yacc.c:1652  */
    {}
#line 3109 "parser.c" /* yacc.c:1652  */
    break;

  case 225:
#line 373 "parser.y" /* yacc.c:1652  */
    {}
#line 3115 "parser.c" /* yacc.c:1652  */
    break;

  case 226:
#line 374 "parser.y" /* yacc.c:1652  */
    {}
#line 3121 "parser.c" /* yacc.c:1652  */
    break;

  case 227:
#line 378 "parser.y" /* yacc.c:1652  */
    {}
#line 3127 "parser.c" /* yacc.c:1652  */
    break;

  case 228:
#line 378 "parser.y" /* yacc.c:1652  */
    {}
#line 3133 "parser.c" /* yacc.c:1652  */
    break;

  case 229:
#line 378 "parser.y" /* yacc.c:1652  */
    {}
#line 3139 "parser.c" /* yacc.c:1652  */
    break;

  case 230:
#line 385 "parser.y" /* yacc.c:1652  */
    {}
#line 3145 "parser.c" /* yacc.c:1652  */
    break;

  case 231:
#line 385 "parser.y" /* yacc.c:1652  */
    {}
#line 3151 "parser.c" /* yacc.c:1652  */
    break;

  case 232:
#line 385 "parser.y" /* yacc.c:1652  */
    {}
#line 3157 "parser.c" /* yacc.c:1652  */
    break;

  case 233:
#line 386 "parser.y" /* yacc.c:1652  */
    {}
#line 3163 "parser.c" /* yacc.c:1652  */
    break;

  case 234:
#line 386 "parser.y" /* yacc.c:1652  */
    {}
#line 3169 "parser.c" /* yacc.c:1652  */
    break;

  case 235:
#line 390 "parser.y" /* yacc.c:1652  */
    {}
#line 3175 "parser.c" /* yacc.c:1652  */
    break;

  case 236:
#line 391 "parser.y" /* yacc.c:1652  */
    {}
#line 3181 "parser.c" /* yacc.c:1652  */
    break;

  case 237:
#line 392 "parser.y" /* yacc.c:1652  */
    {}
#line 3187 "parser.c" /* yacc.c:1652  */
    break;

  case 238:
#line 396 "parser.y" /* yacc.c:1652  */
    {}
#line 3193 "parser.c" /* yacc.c:1652  */
    break;

  case 239:
#line 396 "parser.y" /* yacc.c:1652  */
    {}
#line 3199 "parser.c" /* yacc.c:1652  */
    break;

  case 240:
#line 396 "parser.y" /* yacc.c:1652  */
    {}
#line 3205 "parser.c" /* yacc.c:1652  */
    break;

  case 241:
#line 403 "parser.y" /* yacc.c:1652  */
    {}
#line 3211 "parser.c" /* yacc.c:1652  */
    break;

  case 242:
#line 403 "parser.y" /* yacc.c:1652  */
    {}
#line 3217 "parser.c" /* yacc.c:1652  */
    break;

  case 243:
#line 403 "parser.y" /* yacc.c:1652  */
    {}
#line 3223 "parser.c" /* yacc.c:1652  */
    break;

  case 244:
#line 407 "parser.y" /* yacc.c:1652  */
    {}
#line 3229 "parser.c" /* yacc.c:1652  */
    break;

  case 245:
#line 407 "parser.y" /* yacc.c:1652  */
    {}
#line 3235 "parser.c" /* yacc.c:1652  */
    break;

  case 246:
#line 407 "parser.y" /* yacc.c:1652  */
    {}
#line 3241 "parser.c" /* yacc.c:1652  */
    break;

  case 247:
#line 407 "parser.y" /* yacc.c:1652  */
    {}
#line 3247 "parser.c" /* yacc.c:1652  */
    break;

  case 248:
#line 407 "parser.y" /* yacc.c:1652  */
    {}
#line 3253 "parser.c" /* yacc.c:1652  */
    break;

  case 250:
#line 415 "parser.y" /* yacc.c:1652  */
    {}
#line 3259 "parser.c" /* yacc.c:1652  */
    break;

  case 251:
#line 416 "parser.y" /* yacc.c:1652  */
    {}
#line 3265 "parser.c" /* yacc.c:1652  */
    break;

  case 252:
#line 420 "parser.y" /* yacc.c:1652  */
    {}
#line 3271 "parser.c" /* yacc.c:1652  */
    break;

  case 253:
#line 421 "parser.y" /* yacc.c:1652  */
    {}
#line 3277 "parser.c" /* yacc.c:1652  */
    break;

  case 254:
#line 425 "parser.y" /* yacc.c:1652  */
    {}
#line 3283 "parser.c" /* yacc.c:1652  */
    break;

  case 255:
#line 425 "parser.y" /* yacc.c:1652  */
    {}
#line 3289 "parser.c" /* yacc.c:1652  */
    break;

  case 256:
#line 425 "parser.y" /* yacc.c:1652  */
    {}
#line 3295 "parser.c" /* yacc.c:1652  */
    break;

  case 257:
#line 426 "parser.y" /* yacc.c:1652  */
    {}
#line 3301 "parser.c" /* yacc.c:1652  */
    break;

  case 258:
#line 426 "parser.y" /* yacc.c:1652  */
    {}
#line 3307 "parser.c" /* yacc.c:1652  */
    break;

  case 259:
#line 426 "parser.y" /* yacc.c:1652  */
    {}
#line 3313 "parser.c" /* yacc.c:1652  */
    break;

  case 260:
#line 426 "parser.y" /* yacc.c:1652  */
    {}
#line 3319 "parser.c" /* yacc.c:1652  */
    break;

  case 261:
#line 430 "parser.y" /* yacc.c:1652  */
    {}
#line 3325 "parser.c" /* yacc.c:1652  */
    break;

  case 262:
#line 430 "parser.y" /* yacc.c:1652  */
    {}
#line 3331 "parser.c" /* yacc.c:1652  */
    break;

  case 263:
#line 434 "parser.y" /* yacc.c:1652  */
    {}
#line 3337 "parser.c" /* yacc.c:1652  */
    break;

  case 264:
#line 434 "parser.y" /* yacc.c:1652  */
    {}
#line 3343 "parser.c" /* yacc.c:1652  */
    break;

  case 266:
#line 439 "parser.y" /* yacc.c:1652  */
    {}
#line 3349 "parser.c" /* yacc.c:1652  */
    break;

  case 267:
#line 443 "parser.y" /* yacc.c:1652  */
    {}
#line 3355 "parser.c" /* yacc.c:1652  */
    break;

  case 268:
#line 443 "parser.y" /* yacc.c:1652  */
    {}
#line 3361 "parser.c" /* yacc.c:1652  */
    break;

  case 269:
#line 443 "parser.y" /* yacc.c:1652  */
    {}
#line 3367 "parser.c" /* yacc.c:1652  */
    break;

  case 270:
#line 450 "parser.y" /* yacc.c:1652  */
    {}
#line 3373 "parser.c" /* yacc.c:1652  */
    break;

  case 271:
#line 450 "parser.y" /* yacc.c:1652  */
    {}
#line 3379 "parser.c" /* yacc.c:1652  */
    break;

  case 272:
#line 451 "parser.y" /* yacc.c:1652  */
    {}
#line 3385 "parser.c" /* yacc.c:1652  */
    break;

  case 273:
#line 451 "parser.y" /* yacc.c:1652  */
    {}
#line 3391 "parser.c" /* yacc.c:1652  */
    break;

  case 274:
#line 452 "parser.y" /* yacc.c:1652  */
    {}
#line 3397 "parser.c" /* yacc.c:1652  */
    break;

  case 275:
#line 452 "parser.y" /* yacc.c:1652  */
    {}
#line 3403 "parser.c" /* yacc.c:1652  */
    break;

  case 276:
#line 456 "parser.y" /* yacc.c:1652  */
    {}
#line 3409 "parser.c" /* yacc.c:1652  */
    break;

  case 277:
#line 456 "parser.y" /* yacc.c:1652  */
    {}
#line 3415 "parser.c" /* yacc.c:1652  */
    break;

  case 278:
#line 460 "parser.y" /* yacc.c:1652  */
    {}
#line 3421 "parser.c" /* yacc.c:1652  */
    break;

  case 279:
#line 461 "parser.y" /* yacc.c:1652  */
    {}
#line 3427 "parser.c" /* yacc.c:1652  */
    break;

  case 280:
#line 465 "parser.y" /* yacc.c:1652  */
    {}
#line 3433 "parser.c" /* yacc.c:1652  */
    break;

  case 281:
#line 465 "parser.y" /* yacc.c:1652  */
    {}
#line 3439 "parser.c" /* yacc.c:1652  */
    break;

  case 282:
#line 465 "parser.y" /* yacc.c:1652  */
    {}
#line 3445 "parser.c" /* yacc.c:1652  */
    break;

  case 283:
#line 465 "parser.y" /* yacc.c:1652  */
    {}
#line 3451 "parser.c" /* yacc.c:1652  */
    break;

  case 284:
#line 469 "parser.y" /* yacc.c:1652  */
    {}
#line 3457 "parser.c" /* yacc.c:1652  */
    break;

  case 285:
#line 470 "parser.y" /* yacc.c:1652  */
    {}
#line 3463 "parser.c" /* yacc.c:1652  */
    break;

  case 286:
#line 470 "parser.y" /* yacc.c:1652  */
    {}
#line 3469 "parser.c" /* yacc.c:1652  */
    break;

  case 287:
#line 477 "parser.y" /* yacc.c:1652  */
    {}
#line 3475 "parser.c" /* yacc.c:1652  */
    break;

  case 288:
#line 477 "parser.y" /* yacc.c:1652  */
    {}
#line 3481 "parser.c" /* yacc.c:1652  */
    break;

  case 289:
#line 481 "parser.y" /* yacc.c:1652  */
    {}
#line 3487 "parser.c" /* yacc.c:1652  */
    break;

  case 290:
#line 482 "parser.y" /* yacc.c:1652  */
    {}
#line 3493 "parser.c" /* yacc.c:1652  */
    break;

  case 291:
#line 483 "parser.y" /* yacc.c:1652  */
    {}
#line 3499 "parser.c" /* yacc.c:1652  */
    break;

  case 292:
#line 484 "parser.y" /* yacc.c:1652  */
    {}
#line 3505 "parser.c" /* yacc.c:1652  */
    break;

  case 293:
#line 485 "parser.y" /* yacc.c:1652  */
    {}
#line 3511 "parser.c" /* yacc.c:1652  */
    break;

  case 294:
#line 489 "parser.y" /* yacc.c:1652  */
    {}
#line 3517 "parser.c" /* yacc.c:1652  */
    break;

  case 295:
#line 489 "parser.y" /* yacc.c:1652  */
    {}
#line 3523 "parser.c" /* yacc.c:1652  */
    break;


#line 3527 "parser.c" /* yacc.c:1652  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }

  yyerror_range[1] = yylloc;

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, &yylloc);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 492 "parser.y" /* yacc.c:1918  */


#include <stdio.h>

extern char yytext[];

void yyerror(const char* s)
{
	fflush(stdout);
	fprintf(stdout, "\n%s: line %d: at %d: %s\n\n", get_file_name(), get_line_number(), get_col_number(), s); //yylloc.first_line, s);
    inc_error_count();
}

