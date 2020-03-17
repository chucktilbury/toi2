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

#include "utils.h"
#include "scanner.h"
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
#define YYLAST   680

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  87
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  172
/* YYNRULES -- Number of rules.  */
#define YYNRULES  294
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  464

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
       0,    45,    45,    51,    54,    60,    63,    72,    75,    81,
      84,    87,    90,    93,    96,    99,   102,   105,   108,   111,
     114,   117,   120,   123,   126,   132,   135,   138,   141,   144,
     150,   153,   159,   162,   165,   171,   174,   180,   183,   189,
     192,   194,   196,   192,   202,   205,   214,   214,   219,   221,
     219,   232,   235,   238,   241,   247,   250,   253,   259,   262,
     265,   268,   274,   277,   283,   285,   287,   289,   291,   293,
     295,   283,   298,   300,   302,   304,   306,   308,   298,   317,
     319,   321,   317,   326,   328,   326,   336,   339,   342,   342,
     347,   353,   356,   362,   365,   365,   376,   376,   384,   387,
     393,   396,   402,   404,   406,   408,   410,   412,   414,   416,
     402,   421,   423,   425,   427,   429,   431,   433,   421,   441,
     444,   447,   450,   453,   456,   459,   462,   465,   468,   471,
     477,   480,   486,   488,   486,   493,   499,   501,   503,   505,
     499,   513,   513,   524,   526,   524,   529,   531,   529,   537,
     540,   545,   548,   548,   556,   559,   562,   565,   568,   571,
     574,   577,   580,   583,   586,   589,   592,   595,   598,   601,
     604,   607,   610,   613,   616,   619,   622,   625,   628,   631,
     647,   650,   655,   657,   660,   666,   668,   670,   672,   674,
     666,   679,   679,   690,   693,   700,   703,   709,   709,   714,
     714,   719,   719,   724,   724,   732,   735,   741,   744,   750,
     753,   755,   753,   766,   769,   772,   778,   780,   778,   785,
     785,   794,   794,   802,   805,   808,   814,   816,   814,   827,
     829,   827,   834,   834,   842,   845,   848,   854,   856,   854,
     867,   869,   867,   877,   879,   881,   883,   877,   893,   895,
     898,   904,   907,   913,   915,   913,   920,   922,   924,   920,
     932,   932,   940,   940,   948,   949,   955,   957,   955,   968,
     968,   973,   973,   978,   978,   986,   986,   994,   997,  1003,
    1005,  1007,  1003,  1015,  1018,  1018,  1029,  1029,  1037,  1040,
    1043,  1046,  1049,  1055,  1055
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
  "expression", "function_call_parameter", "function_call_parameter_list",
  "function_call", "$@55", "$@56", "$@57", "$@58", "$@59", "$@60",
  "branch_expression", "jump_clause", "pre_post_inc", "$@61", "$@62",
  "$@63", "$@64", "loop_body_element", "loop_body_element_list",
  "loop_body", "$@65", "$@66", "for_initialize_assign", "for_initialize",
  "$@67", "$@68", "$@69", "for_test_expression", "$@70",
  "for_arith_expression", "for_clause", "$@71", "$@72", "else_clause",
  "$@73", "$@74", "$@75", "else_body", "if_clause", "$@76", "$@77",
  "while_clause", "$@78", "$@79", "do_clause", "$@80", "$@81", "$@82",
  "$@83", "except_parameter", "except_parameter_list", "except_clause",
  "$@84", "$@85", "$@86", "$@87", "$@88", "final_clause", "$@89",
  "try_clause_intro", "$@90", "try_clause", "raise_clause", "$@91", "$@92",
  "case_clause", "$@93", "$@94", "$@95", "default_case", "$@96",
  "case_body", "switch_clause_intro", "$@97", "$@98", "$@99",
  "switch_clause", "$@100", "type_cast", "$@101", "assignment_target",
  "assignment", "$@102", YY_NULLPTR
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

#define YYPACT_NINF -323

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-323)))

#define YYTABLE_NINF -294

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      64,    37,    60,    44,  -323,  -323,  -323,  -323,   116,    77,
      62,  -323,  -323,  -323,  -323,  -323,  -323,  -323,  -323,   116,
    -323,    -1,    66,  -323,    84,    13,  -323,    99,  -323,  -323,
    -323,    25,   107,    26,  -323,  -323,   102,   102,   102,    32,
    -323,    42,  -323,   107,    32,    32,    32,   124,   107,    59,
      42,  -323,  -323,    55,    78,  -323,    58,   533,  -323,   138,
    -323,  -323,  -323,  -323,  -323,  -323,  -323,  -323,  -323,  -323,
    -323,  -323,  -323,  -323,  -323,  -323,  -323,    32,   152,  -323,
     533,  -323,  -323,  -323,  -323,   533,   116,   153,    83,    82,
     116,   161,  -323,    86,   533,   116,  -323,  -323,    87,  -323,
     116,  -323,  -323,    89,   169,    96,   252,  -323,   426,   173,
      97,  -323,  -323,  -323,  -323,  -323,   103,  -323,   102,   104,
     106,  -323,  -323,   109,   110,   111,  -323,  -323,   154,    20,
    -323,  -323,   426,  -323,   101,  -323,  -323,  -323,  -323,   127,
    -323,  -323,   -36,  -323,   113,  -323,  -323,   117,   252,   196,
     252,   122,    32,  -323,  -323,   123,    82,  -323,  -323,  -323,
     102,   102,   125,   144,   145,   126,  -323,   205,   -53,  -323,
     129,  -323,  -323,  -323,  -323,  -323,  -323,  -323,   141,  -323,
    -323,  -323,  -323,  -323,   143,    65,    65,   136,  -323,   181,
      57,   252,   142,    32,    32,  -323,  -323,  -323,   357,  -323,
    -323,  -323,  -323,    82,   123,   149,  -323,   252,   147,    82,
    -323,  -323,  -323,  -323,  -323,  -323,   142,   142,   142,   142,
     -33,  -323,  -323,  -323,   546,  -323,  -323,  -323,   487,   186,
      14,  -323,   155,    32,  -323,  -323,   150,   -22,  -323,   142,
    -323,   546,    15,  -323,   -47,  -323,  -323,  -323,   546,   142,
    -323,   392,  -323,  -323,  -323,  -323,   156,  -323,  -323,  -323,
    -323,   519,   151,   142,   142,   142,   142,   142,   142,   142,
     142,   142,   142,   142,   142,   142,   142,   142,   142,   142,
     142,   142,   142,   157,   159,   160,   162,  -323,  -323,  -323,
     487,   165,  -323,    32,   171,    57,   174,   230,   546,    92,
     177,   175,  -323,   546,  -323,   182,   178,   546,  -323,  -323,
     180,   546,  -323,   187,  -323,  -323,   254,  -323,   151,   567,
     567,   607,   607,   239,   239,   179,   179,   179,   179,   588,
     588,   588,   239,   239,    53,    53,  -323,  -323,  -323,   -23,
     123,  -323,  -323,  -323,   183,  -323,    57,   191,   192,  -323,
     207,  -323,   209,   130,   546,  -323,  -323,  -323,  -323,   220,
      15,   211,  -323,  -323,   142,   224,   252,   142,   296,  -323,
     226,  -323,  -323,   268,  -323,  -323,    65,   150,  -323,  -323,
    -323,   233,  -323,   228,  -323,  -323,   235,   546,  -323,  -323,
     546,  -323,  -323,    82,  -323,  -323,   238,    57,   108,    29,
     123,   273,  -323,   252,   241,   236,   237,   142,  -323,   244,
      82,   150,  -323,  -323,   247,   546,  -323,  -323,   546,   246,
    -323,   146,  -323,   273,    15,  -323,  -323,  -323,  -323,   546,
     248,  -323,   250,   108,   251,  -323,  -323,  -323,  -323,  -323,
     182,   253,    82,   256,  -323,    82,  -323,  -323,   123,   123,
     123,   257,  -323,  -323,    82,  -323,  -323,  -323,  -323,   258,
      82,  -323,  -323,  -323
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
       0,   243,   262,     0,     0,     0,   201,   203,    24,     0,
     119,   130,   133,   122,     0,   123,   124,   125,   126,   264,
     120,   121,     0,   127,     0,    81,    85,     0,   101,     0,
       0,     0,   191,   237,   240,     0,     0,   266,   226,   279,
       0,     0,     0,     0,     0,     0,    91,     0,     0,   131,
       0,   128,   260,   265,   275,   283,   284,   129,     0,   105,
     114,    97,    99,   139,     0,     0,     0,   210,   244,     0,
     248,     0,     0,   202,   204,   186,   198,   200,     0,    92,
      93,    94,   134,     0,     0,     0,    82,   101,     0,     0,
     192,    32,    34,    33,    44,    45,     0,     0,     0,     0,
     151,   154,   194,   155,   193,   238,   241,   209,     0,     0,
       0,   263,    39,   250,   249,   251,   267,    24,   216,     0,
     219,   280,   182,   291,   151,   286,   289,   292,   288,     0,
     294,     0,   261,   276,   285,   106,     0,   140,   177,   176,
     178,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   205,   206,   207,
     211,     0,   253,   256,     0,   248,     0,     0,   221,     0,
       0,     0,   180,   181,   183,   187,     0,   290,    86,    90,
       0,    87,    88,     0,   115,   179,   143,   149,   153,   161,
     162,   165,   166,   167,   168,   174,   175,   172,   173,   169,
     170,   171,   163,   164,   156,   157,   159,   158,   160,     0,
       0,   196,   195,   208,     0,   245,   248,     0,     0,   252,
       0,   217,     0,   151,   223,   224,   227,   225,   220,     0,
       0,     0,   287,    95,     0,     0,   101,     0,     0,   150,
     232,   236,   234,   239,   242,   212,     0,   254,   257,    41,
     268,     0,   222,     0,   281,   184,     0,    89,   107,   116,
     144,   147,   229,     0,   235,   246,     0,   248,     0,     0,
       0,     0,   188,   101,     0,     0,     0,     0,   233,     0,
       0,   258,    35,    37,    42,    36,   213,   215,   214,     0,
     228,     0,   277,   282,   182,   108,   117,   145,   148,   230,
       0,   255,     0,     0,     0,   218,   269,   273,   271,   278,
     189,     0,     0,     0,   247,     0,    38,    43,     0,     0,
       0,     0,   109,   118,     0,   259,   270,   274,   272,     0,
       0,   231,   190,   110
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -323,  -323,   328,  -323,   -32,   -49,    -6,    -8,  -323,  -100,
    -323,  -195,  -323,  -323,  -323,  -189,  -323,  -323,  -323,  -323,
     289,   316,   -52,   281,  -323,  -323,  -323,  -323,  -323,  -323,
    -323,  -323,  -323,  -323,  -323,  -323,  -323,  -323,  -323,  -323,
    -323,  -323,  -323,  -323,  -323,  -323,  -323,  -323,  -323,   217,
    -323,  -323,  -141,  -323,  -323,  -323,  -323,  -323,  -323,  -323,
    -323,  -323,  -323,  -323,  -323,  -323,  -323,  -323,  -323,   -82,
    -323,  -154,  -323,  -323,  -323,  -323,  -323,  -323,  -323,  -323,
    -323,    50,  -323,  -323,  -323,  -323,  -323,  -323,  -323,    76,
      10,   -51,  -323,  -323,  -323,  -323,  -323,  -323,  -323,  -176,
    -323,    73,  -323,  -323,  -323,  -323,   112,  -323,  -203,  -323,
    -323,  -323,  -323,  -323,  -323,  -323,  -323,  -323,  -323,  -323,
    -323,  -323,     1,  -323,  -323,  -323,  -323,  -323,  -323,  -323,
    -323,  -323,  -323,  -323,  -323,  -323,  -323,  -323,   105,  -322,
    -323,  -323,  -323,  -323,  -323,  -323,  -323,  -323,  -323,  -323,
    -323,  -323,  -323,  -323,   -44,  -323,  -323,  -323,  -323,  -323,
    -323,  -323,  -323,  -323,  -323,  -323,  -323,   163,  -323,  -323,
    -179,  -323
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,     5,   220,   114,    18,    19,   221,   413,
     414,   234,   294,   398,   434,   222,     6,    21,    22,    33,
      40,    41,    79,    80,     7,     8,    24,    31,    43,    54,
      85,   103,     9,    25,    32,    49,    57,    93,    81,    90,
     109,   178,    91,   110,   310,   364,   168,   130,   251,   115,
     149,   116,   117,    82,    86,   104,   147,   207,   313,   403,
     441,   460,    87,   105,   148,   208,   366,   404,   442,   287,
     132,    99,   108,   170,    83,    88,   106,   151,   209,    84,
      89,   317,   367,   405,   368,   406,   318,   223,   262,   224,
     304,   305,   133,   162,   242,   361,   424,   451,   184,   225,
     288,   134,   163,   164,   160,   161,   289,   290,   188,   228,
     344,   419,   239,   297,   381,   300,   299,   352,   356,   135,
     191,   383,   372,   407,   443,   393,   373,   136,   185,   283,
     137,   186,   284,   138,   155,   229,   376,   409,   235,   236,
     231,   346,   396,   347,   397,   432,   173,   203,   139,   156,
     140,   141,   190,   296,   422,   448,   450,   449,   176,   204,
     423,   142,   192,   301,   401,   143,   205,   249,   306,   250,
     144,   165
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      39,   253,   189,   246,    44,    45,    46,   180,    78,   247,
     226,    39,   240,    23,   370,   174,    39,    35,    35,   211,
     212,   213,   232,   166,   377,    77,   131,   200,    92,    47,
     201,    78,    35,   211,   212,   213,    78,  -152,   167,   -24,
     -72,   416,    92,    47,    11,    78,   175,   302,    77,   252,
     169,  -152,     1,    77,    47,   257,   309,     2,    98,   129,
      35,  -293,    77,    10,   232,   214,   255,   216,    35,   211,
     212,   213,     1,   215,    77,   411,   128,     2,    95,    26,
      20,   216,   100,   129,   -48,   217,   152,    28,    27,    23,
     218,    29,   292,   219,    23,    35,   211,   212,   213,   217,
     128,   214,    30,    34,   218,    35,    42,   219,    47,   215,
      35,    35,   211,   212,   213,   412,    77,   216,    77,    48,
     357,    36,    37,    38,   280,   281,   282,    51,   193,   194,
      13,    14,    15,    16,    17,   217,    55,   374,    53,    58,
     218,  -111,   238,   219,   216,    35,   211,   212,   213,   245,
     436,   437,   438,   126,   127,   -83,    96,    56,   233,   237,
     216,    97,   217,    98,   101,   302,   244,   218,   102,   107,
     219,   111,   112,   391,   113,    77,   145,   146,   217,   129,
     150,   171,   153,   218,   154,   371,   219,   157,   158,   159,
     172,  -197,  -199,   177,   216,   179,   128,   420,   293,   181,
     395,   183,   245,   195,   187,   196,    47,   197,   199,   198,
     417,   202,   217,  -293,  -152,  -197,  -199,   218,   227,   244,
     219,   206,   230,   210,   291,   389,   256,   295,   -40,   302,
      47,   254,  -185,   351,   314,   316,   339,  -293,   340,   408,
     341,   129,   342,   345,   348,   456,   457,   458,   278,   279,
     280,   281,   282,   350,   359,    35,   431,   358,   128,   360,
     363,  -146,   425,   233,   362,   375,   365,   353,   241,   378,
     379,    62,    63,    64,   248,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,   380,   453,   382,
     386,   455,   258,   259,   260,   261,   269,   270,   271,   272,
     461,   384,   388,   232,   392,   370,   463,   400,   278,   279,
     280,   281,   282,   402,   233,   298,   399,   410,   303,   421,
     426,   427,   428,   430,   433,   307,   435,   311,   444,   445,
     447,    12,   452,   446,    77,   454,   459,    52,   462,   319,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,   331,   332,   333,   334,   335,   336,   337,   338,    50,
      35,   211,   212,   213,   232,   233,    94,   182,   369,   243,
     385,    77,   355,   440,   394,   354,    62,    63,    64,   439,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,     0,   214,     0,    35,   211,   212,   213,   232,
     349,   215,   343,     0,   308,     0,     0,     0,     0,   216,
       0,    62,    63,    64,   312,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,   217,     0,    35,
       0,     0,   218,     0,     0,   219,   303,   118,     0,     0,
     387,     0,     0,   390,   216,    62,    63,    64,     0,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,   119,   217,     0,   120,   121,   122,   218,   123,   124,
     219,   125,     0,     0,   415,   418,     0,     0,     0,     0,
       0,     0,     0,   429,     0,     0,     0,   126,   127,     0,
      35,     0,     0,     0,     0,     0,     0,     0,   118,     0,
     303,     0,     0,     0,     0,     0,    62,    63,    64,   415,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,   119,     0,     0,   120,   121,   122,     0,   123,
     124,     0,   125,     0,   285,   286,    35,     0,     0,     0,
       0,     0,    59,    60,    61,     0,     0,     0,   126,   127,
       0,     0,    62,    63,    64,     0,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,   263,   264,
       0,     0,   265,   266,   267,   268,   269,   270,   271,   272,
       0,     0,     0,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,     0,     0,   263,   264,     0,   315,   265,
     266,   267,   268,   269,   270,   271,   272,     0,     0,     0,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     265,   266,   267,   268,   269,   270,   271,   272,     0,     0,
       0,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   265,   266,   267,   268,   269,   270,   271,   272,     0,
       0,     0,     0,     0,     0,   276,   277,   278,   279,   280,
     281,   282,   267,   268,   269,   270,   271,   272,     0,     0,
       0,     0,     0,     0,   276,   277,   278,   279,   280,   281,
     282
};

static const yytype_int16 yycheck[] =
{
      32,   204,   156,   198,    36,    37,    38,   148,    57,   198,
     186,    43,   191,    19,    37,    51,    48,     3,     3,     4,
       5,     6,     7,     3,   346,    57,   108,    80,    80,    76,
      83,    80,     3,     4,     5,     6,    85,    84,    18,    86,
       3,    12,    94,    76,     0,    94,    82,   242,    80,   203,
     132,    84,     8,    85,    76,   209,   251,    13,    81,   108,
       3,    83,    94,     3,     7,    36,   207,    52,     3,     4,
       5,     6,     8,    44,   106,   397,   108,    13,    86,    80,
       3,    52,    90,   132,    22,    70,   118,     3,    22,    95,
      75,    78,    78,    78,   100,     3,     4,     5,     6,    70,
     132,    36,     3,    78,    75,     3,    80,    78,    76,    44,
       3,     3,     4,     5,     6,     7,   148,    52,   150,    77,
     299,    14,    15,    16,    71,    72,    73,     3,   160,   161,
      14,    15,    16,    17,    18,    70,    81,   340,    79,    81,
      75,     3,   191,    78,    52,     3,     4,     5,     6,   198,
       4,     5,     6,    61,    62,     3,     3,    79,   190,   191,
      52,    78,    70,    81,     3,   360,   198,    75,    82,    82,
      78,    82,     3,   368,    78,   207,     3,    80,    70,   228,
      77,    80,    78,    75,    78,   339,    78,    78,    78,    78,
      63,    61,    62,    80,    52,    78,   228,   400,   230,     3,
     376,    79,   251,    78,    81,    61,    76,    62,     3,    83,
     399,    82,    70,    83,    84,    61,    62,    75,    82,   251,
      78,    80,    41,    80,    38,   366,    79,    77,    73,   424,
      76,    82,    78,     3,    78,    84,    79,    83,    79,   393,
      80,   290,    80,    78,    73,   448,   449,   450,    69,    70,
      71,    72,    73,    79,    79,     3,   410,    80,   290,    77,
      80,     7,   403,   295,    86,    82,    79,   299,   192,    78,
      78,    19,    20,    21,   198,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    80,   442,    80,
      79,   445,   216,   217,   218,   219,    57,    58,    59,    60,
     454,    81,    78,     7,    78,    37,   460,    79,    69,    70,
      71,    72,    73,    78,   346,   239,    83,    79,   242,    46,
      79,    85,    85,    79,    77,   249,    80,   251,    80,    79,
      79,     3,    79,   433,   366,    79,    79,    48,    80,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,    43,
       3,     4,     5,     6,     7,   397,    85,   150,   318,    12,
     360,   403,   299,   424,   373,   299,    19,    20,    21,   423,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    -1,    36,    -1,     3,     4,     5,     6,     7,
     295,    44,   290,    -1,    12,    -1,    -1,    -1,    -1,    52,
      -1,    19,    20,    21,   251,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    70,    -1,     3,
      -1,    -1,    75,    -1,    -1,    78,   360,    11,    -1,    -1,
     364,    -1,    -1,   367,    52,    19,    20,    21,    -1,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    70,    -1,    38,    39,    40,    75,    42,    43,
      78,    45,    -1,    -1,   398,   399,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   407,    -1,    -1,    -1,    61,    62,    -1,
       3,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    11,    -1,
     424,    -1,    -1,    -1,    -1,    -1,    19,    20,    21,   433,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    -1,    -1,    38,    39,    40,    -1,    42,
      43,    -1,    45,    -1,    47,    48,     3,    -1,    -1,    -1,
      -1,    -1,     9,    10,    11,    -1,    -1,    -1,    61,    62,
      -1,    -1,    19,    20,    21,    -1,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    49,    50,
      -1,    -1,    53,    54,    55,    56,    57,    58,    59,    60,
      -1,    -1,    -1,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    -1,    -1,    49,    50,    -1,    79,    53,
      54,    55,    56,    57,    58,    59,    60,    -1,    -1,    -1,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      53,    54,    55,    56,    57,    58,    59,    60,    -1,    -1,
      -1,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    53,    54,    55,    56,    57,    58,    59,    60,    -1,
      -1,    -1,    -1,    -1,    -1,    67,    68,    69,    70,    71,
      72,    73,    55,    56,    57,    58,    59,    60,    -1,    -1,
      -1,    -1,    -1,    -1,    67,    68,    69,    70,    71,    72,
      73
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
     134,   156,   157,   179,   188,   206,   214,   217,   220,   235,
     237,   238,   248,   252,   257,     3,    80,   143,   151,   137,
      77,   164,    91,    78,    78,   221,   236,    78,    78,    78,
     191,   192,   180,   189,   190,   258,     3,    18,   133,   156,
     160,    80,    63,   233,    51,    82,   245,    80,   128,    78,
     139,     3,   136,    79,   185,   215,   218,    81,   195,   158,
     239,   207,   249,    91,    91,    78,    61,    62,    83,     3,
      80,    83,    82,   234,   246,   253,    80,   144,   152,   165,
      80,     4,     5,     6,    36,    44,    52,    70,    75,    78,
      91,    95,   102,   174,   176,   186,   186,    82,   196,   222,
      41,   227,     7,    91,    98,   225,   226,    91,    92,   199,
     257,   176,   181,    12,    91,    92,    98,   102,   176,   254,
     256,   135,   158,   195,    82,   139,    79,   158,   176,   176,
     176,   176,   175,    49,    50,    53,    54,    55,    56,    57,
      58,    59,    60,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,   216,   219,    47,    48,   156,   187,   193,
     194,    38,    78,    91,    99,    77,   240,   200,   176,   203,
     202,   250,    98,   176,   177,   178,   255,   176,    12,    98,
     131,   176,   254,   145,    78,    79,    84,   168,   173,   176,
     176,   176,   176,   176,   176,   176,   176,   176,   176,   176,
     176,   176,   176,   176,   176,   176,   176,   176,   176,    79,
      79,    80,    80,   193,   197,    78,   228,   230,    73,   225,
      79,     3,   204,    91,   176,   188,   205,   257,    80,    79,
      77,   182,    86,    80,   132,    79,   153,   169,   171,   168,
      37,   158,   209,   213,   195,    82,   223,   226,    78,    78,
      80,   201,    80,   208,    81,   177,    79,   176,    78,   139,
     176,    98,    78,   212,   209,   186,   229,   231,   100,    83,
      79,   251,    78,   146,   154,   170,   172,   210,   158,   224,
      79,   226,     7,    96,    97,   176,    12,   102,   176,   198,
     195,    46,   241,   247,   183,   139,    79,    85,    85,   176,
      79,   158,   232,    77,   101,    80,     4,     5,     6,   241,
     178,   147,   155,   211,    80,    79,    96,    79,   242,   244,
     243,   184,    79,   158,    79,   158,   195,   195,   195,    79,
     148,   158,    80,   158
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
     176,   176,   176,   176,   176,   176,   176,   176,   176,   176,
     177,   177,   178,   178,   178,   180,   181,   182,   183,   184,
     179,   185,   179,   186,   186,   187,   187,   189,   188,   190,
     188,   191,   188,   192,   188,   193,   193,   194,   194,   195,
     196,   197,   195,   198,   198,   198,   200,   201,   199,   202,
     199,   204,   203,   205,   205,   205,   207,   208,   206,   210,
     211,   209,   212,   209,   213,   213,   213,   215,   216,   214,
     218,   219,   217,   221,   222,   223,   224,   220,   225,   225,
     225,   226,   226,   228,   229,   227,   230,   231,   232,   227,
     234,   233,   236,   235,   237,   237,   239,   240,   238,   242,
     241,   243,   241,   244,   241,   246,   245,   247,   247,   249,
     250,   251,   248,   252,   253,   252,   255,   254,   256,   256,
     256,   256,   256,   258,   257
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
       3,     3,     3,     3,     3,     3,     2,     2,     2,     3,
       1,     1,     0,     1,     3,     0,     0,     0,     0,     0,
      13,     0,     4,     1,     1,     2,     2,     0,     3,     0,
       3,     0,     3,     0,     3,     1,     1,     1,     2,     2,
       0,     0,     5,     1,     1,     1,     0,     0,     7,     0,
       3,     0,     3,     1,     1,     1,     0,     0,     9,     0,
       0,     7,     0,     3,     1,     2,     1,     0,     0,     7,
       0,     0,     7,     0,     0,     0,     0,    11,     0,     1,
       1,     1,     3,     0,     0,     7,     0,     0,     0,     9,
       0,     3,     0,     4,     1,     2,     0,     0,     7,     0,
       4,     0,     4,     0,     4,     0,     3,     1,     2,     0,
       0,     0,     9,     2,     0,     4,     0,     3,     1,     1,
       2,     1,     1,     0,     4
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
    {
        module_module_list_end();
    }
#line 1827 "parser.c" /* yacc.c:1652  */
    break;

  case 3:
#line 51 "parser.y" /* yacc.c:1652  */
    {
        module_item_import_definition_end();
    }
#line 1835 "parser.c" /* yacc.c:1652  */
    break;

  case 4:
#line 54 "parser.y" /* yacc.c:1652  */
    {
        module_item_class_definition_end();
    }
#line 1843 "parser.c" /* yacc.c:1652  */
    break;

  case 5:
#line 60 "parser.y" /* yacc.c:1652  */
    {
        module_list_module_item_end();
    }
#line 1851 "parser.c" /* yacc.c:1652  */
    break;

  case 6:
#line 63 "parser.y" /* yacc.c:1652  */
    {
        module_list_module_item_end();
    }
#line 1859 "parser.c" /* yacc.c:1652  */
    break;

  case 7:
#line 72 "parser.y" /* yacc.c:1652  */
    {
        complex_name_init_symbol();
    }
#line 1867 "parser.c" /* yacc.c:1652  */
    break;

  case 8:
#line 75 "parser.y" /* yacc.c:1652  */
    {
        complex_name_add_symbol();
    }
#line 1875 "parser.c" /* yacc.c:1652  */
    break;

  case 9:
#line 81 "parser.y" /* yacc.c:1652  */
    {
        save_intrinsic_type(DICT);
    }
#line 1883 "parser.c" /* yacc.c:1652  */
    break;

  case 10:
#line 84 "parser.y" /* yacc.c:1652  */
    {
        save_intrinsic_type(ARRAY);
    }
#line 1891 "parser.c" /* yacc.c:1652  */
    break;

  case 11:
#line 87 "parser.y" /* yacc.c:1652  */
    {
        save_intrinsic_type(BOOL);
    }
#line 1899 "parser.c" /* yacc.c:1652  */
    break;

  case 12:
#line 90 "parser.y" /* yacc.c:1652  */
    {
        save_intrinsic_type(STRING);
    }
#line 1907 "parser.c" /* yacc.c:1652  */
    break;

  case 13:
#line 93 "parser.y" /* yacc.c:1652  */
    {
        save_intrinsic_type(FLOAT);
    }
#line 1915 "parser.c" /* yacc.c:1652  */
    break;

  case 14:
#line 96 "parser.y" /* yacc.c:1652  */
    {
        save_intrinsic_type(INT64);
    }
#line 1923 "parser.c" /* yacc.c:1652  */
    break;

  case 15:
#line 99 "parser.y" /* yacc.c:1652  */
    {
        save_intrinsic_type(INT8);
    }
#line 1931 "parser.c" /* yacc.c:1652  */
    break;

  case 16:
#line 102 "parser.y" /* yacc.c:1652  */
    {
        save_intrinsic_type(INT16);
    }
#line 1939 "parser.c" /* yacc.c:1652  */
    break;

  case 17:
#line 105 "parser.y" /* yacc.c:1652  */
    {
        save_intrinsic_type(INT32);
    }
#line 1947 "parser.c" /* yacc.c:1652  */
    break;

  case 18:
#line 108 "parser.y" /* yacc.c:1652  */
    {
        save_intrinsic_type(INT64);
    }
#line 1955 "parser.c" /* yacc.c:1652  */
    break;

  case 19:
#line 111 "parser.y" /* yacc.c:1652  */
    {
        save_intrinsic_type(UINT64);
    }
#line 1963 "parser.c" /* yacc.c:1652  */
    break;

  case 20:
#line 114 "parser.y" /* yacc.c:1652  */
    {
        save_intrinsic_type(UINT8);
    }
#line 1971 "parser.c" /* yacc.c:1652  */
    break;

  case 21:
#line 117 "parser.y" /* yacc.c:1652  */
    {
        save_intrinsic_type(UINT16);
    }
#line 1979 "parser.c" /* yacc.c:1652  */
    break;

  case 22:
#line 120 "parser.y" /* yacc.c:1652  */
    {
        save_intrinsic_type(UINT32);
    }
#line 1987 "parser.c" /* yacc.c:1652  */
    break;

  case 23:
#line 123 "parser.y" /* yacc.c:1652  */
    {
        save_intrinsic_type(UINT64);
    }
#line 1995 "parser.c" /* yacc.c:1652  */
    break;

  case 24:
#line 126 "parser.y" /* yacc.c:1652  */
    {
        intrinsic_type_create_complex_name();
    }
#line 2003 "parser.c" /* yacc.c:1652  */
    break;

  case 25:
#line 132 "parser.y" /* yacc.c:1652  */
    {
        save_data_attr(PRIVATE);
    }
#line 2011 "parser.c" /* yacc.c:1652  */
    break;

  case 26:
#line 135 "parser.y" /* yacc.c:1652  */
    {
        save_data_attr(PUBLIC);
    }
#line 2019 "parser.c" /* yacc.c:1652  */
    break;

  case 27:
#line 138 "parser.y" /* yacc.c:1652  */
    {
        save_data_attr(PROTECTED);
    }
#line 2027 "parser.c" /* yacc.c:1652  */
    break;

  case 28:
#line 141 "parser.y" /* yacc.c:1652  */
    {
        save_data_attr(CONST);
    }
#line 2035 "parser.c" /* yacc.c:1652  */
    break;

  case 29:
#line 144 "parser.y" /* yacc.c:1652  */
    {
        save_data_attr(STATIC);
    }
#line 2043 "parser.c" /* yacc.c:1652  */
    break;

  case 30:
#line 150 "parser.y" /* yacc.c:1652  */
    {
        data_attrs_list_init();
    }
#line 2051 "parser.c" /* yacc.c:1652  */
    break;

  case 31:
#line 153 "parser.y" /* yacc.c:1652  */
    {
        data_attrs_list_add();
    }
#line 2059 "parser.c" /* yacc.c:1652  */
    break;

  case 32:
#line 159 "parser.y" /* yacc.c:1652  */
    {
        save_literal_num(UNUM);
    }
#line 2067 "parser.c" /* yacc.c:1652  */
    break;

  case 33:
#line 162 "parser.y" /* yacc.c:1652  */
    {
        save_literal_num(INUM);
    }
#line 2075 "parser.c" /* yacc.c:1652  */
    break;

  case 34:
#line 165 "parser.y" /* yacc.c:1652  */
    {
        save_literal_num(FNUM);
    }
#line 2083 "parser.c" /* yacc.c:1652  */
    break;

  case 35:
#line 171 "parser.y" /* yacc.c:1652  */
    {
        formatted_string_param_qstrg();
    }
#line 2091 "parser.c" /* yacc.c:1652  */
    break;

  case 36:
#line 174 "parser.y" /* yacc.c:1652  */
    {
        formatted_string_param_expression();
    }
#line 2099 "parser.c" /* yacc.c:1652  */
    break;

  case 37:
#line 180 "parser.y" /* yacc.c:1652  */
    {
        formatted_string_param_list_init();
    }
#line 2107 "parser.c" /* yacc.c:1652  */
    break;

  case 38:
#line 183 "parser.y" /* yacc.c:1652  */
    {
        formatted_string_param_list_add();
    }
#line 2115 "parser.c" /* yacc.c:1652  */
    break;

  case 39:
#line 189 "parser.y" /* yacc.c:1652  */
    {
        formatted_string_no_format();
    }
#line 2123 "parser.c" /* yacc.c:1652  */
    break;

  case 40:
#line 192 "parser.y" /* yacc.c:1652  */
    {
        formatted_string_with_format();
    }
#line 2131 "parser.c" /* yacc.c:1652  */
    break;

  case 41:
#line 194 "parser.y" /* yacc.c:1652  */
    {
        formatted_string_with_init_parameters_start();
    }
#line 2139 "parser.c" /* yacc.c:1652  */
    break;

  case 42:
#line 196 "parser.y" /* yacc.c:1652  */
    {
        formatted_string_with_init_parameters_finish();
    }
#line 2147 "parser.c" /* yacc.c:1652  */
    break;

  case 44:
#line 202 "parser.y" /* yacc.c:1652  */
    {
        bool_value_create_true();
    }
#line 2155 "parser.c" /* yacc.c:1652  */
    break;

  case 45:
#line 205 "parser.y" /* yacc.c:1652  */
    {
        bool_value_create_false();
    }
#line 2163 "parser.c" /* yacc.c:1652  */
    break;

  case 46:
#line 214 "parser.y" /* yacc.c:1652  */
    {
        import_definition_create();
    }
#line 2171 "parser.c" /* yacc.c:1652  */
    break;

  case 47:
#line 216 "parser.y" /* yacc.c:1652  */
    {
        import_definition_finish();
    }
#line 2179 "parser.c" /* yacc.c:1652  */
    break;

  case 48:
#line 219 "parser.y" /* yacc.c:1652  */
    {
        import_definition_create();
    }
#line 2187 "parser.c" /* yacc.c:1652  */
    break;

  case 49:
#line 221 "parser.y" /* yacc.c:1652  */
    {
        import_definition_alias_to_symbol();
    }
#line 2195 "parser.c" /* yacc.c:1652  */
    break;

  case 50:
#line 223 "parser.y" /* yacc.c:1652  */
    {
        import_definition_finish();
    }
#line 2203 "parser.c" /* yacc.c:1652  */
    break;

  case 51:
#line 232 "parser.y" /* yacc.c:1652  */
    {
        class_parm_add_private();
    }
#line 2211 "parser.c" /* yacc.c:1652  */
    break;

  case 52:
#line 235 "parser.y" /* yacc.c:1652  */
    {
        class_parm_add_public();
    }
#line 2219 "parser.c" /* yacc.c:1652  */
    break;

  case 53:
#line 238 "parser.y" /* yacc.c:1652  */
    {
        class_parm_add_protected();
    }
#line 2227 "parser.c" /* yacc.c:1652  */
    break;

  case 54:
#line 241 "parser.y" /* yacc.c:1652  */
    {
        class_parm_add_private();
    }
#line 2235 "parser.c" /* yacc.c:1652  */
    break;

  case 55:
#line 247 "parser.y" /* yacc.c:1652  */
    {
        class_parm_list_create();
    }
#line 2243 "parser.c" /* yacc.c:1652  */
    break;

  case 56:
#line 250 "parser.y" /* yacc.c:1652  */
    {
        class_parm_list_add();
    }
#line 2251 "parser.c" /* yacc.c:1652  */
    break;

  case 57:
#line 253 "parser.y" /* yacc.c:1652  */
    {
        class_parm_list_blank();
    }
#line 2259 "parser.c" /* yacc.c:1652  */
    break;

  case 58:
#line 259 "parser.y" /* yacc.c:1652  */
    {
        class_body_item_data_definition_finish();
    }
#line 2267 "parser.c" /* yacc.c:1652  */
    break;

  case 59:
#line 262 "parser.y" /* yacc.c:1652  */
    {
        class_body_item_method_definition_finish();
    }
#line 2275 "parser.c" /* yacc.c:1652  */
    break;

  case 60:
#line 265 "parser.y" /* yacc.c:1652  */
    {
        class_body_item_constructor_definition_finish();
    }
#line 2283 "parser.c" /* yacc.c:1652  */
    break;

  case 61:
#line 268 "parser.y" /* yacc.c:1652  */
    {
        class_body_item_destructor_definition_finish();
    }
#line 2291 "parser.c" /* yacc.c:1652  */
    break;

  case 62:
#line 274 "parser.y" /* yacc.c:1652  */
    {
        class_body_item_add();
    }
#line 2299 "parser.c" /* yacc.c:1652  */
    break;

  case 63:
#line 277 "parser.y" /* yacc.c:1652  */
    {
        class_body_item_add();
    }
#line 2307 "parser.c" /* yacc.c:1652  */
    break;

  case 64:
#line 283 "parser.y" /* yacc.c:1652  */
    {
        class_definiton_create();
    }
#line 2315 "parser.c" /* yacc.c:1652  */
    break;

  case 65:
#line 285 "parser.y" /* yacc.c:1652  */
    {
        class_definiton_attrs_finish();
    }
#line 2323 "parser.c" /* yacc.c:1652  */
    break;

  case 66:
#line 287 "parser.y" /* yacc.c:1652  */
    {
        class_definiton_add_name();
    }
#line 2331 "parser.c" /* yacc.c:1652  */
    break;

  case 67:
#line 289 "parser.y" /* yacc.c:1652  */
    {
        class_definiton_param_list_start();
    }
#line 2339 "parser.c" /* yacc.c:1652  */
    break;

  case 68:
#line 291 "parser.y" /* yacc.c:1652  */
    {
        class_definiton_param_list_finish();
    }
#line 2347 "parser.c" /* yacc.c:1652  */
    break;

  case 69:
#line 293 "parser.y" /* yacc.c:1652  */
    {
        class_definiton_body_start();
    }
#line 2355 "parser.c" /* yacc.c:1652  */
    break;

  case 70:
#line 295 "parser.y" /* yacc.c:1652  */
    {
        class_definiton_body_finish();
    }
#line 2363 "parser.c" /* yacc.c:1652  */
    break;

  case 72:
#line 298 "parser.y" /* yacc.c:1652  */
    {
        class_definiton_create();
    }
#line 2371 "parser.c" /* yacc.c:1652  */
    break;

  case 73:
#line 300 "parser.y" /* yacc.c:1652  */
    {
        class_definiton_add_name();
    }
#line 2379 "parser.c" /* yacc.c:1652  */
    break;

  case 74:
#line 302 "parser.y" /* yacc.c:1652  */
    {
        class_definiton_param_list_start();
    }
#line 2387 "parser.c" /* yacc.c:1652  */
    break;

  case 75:
#line 304 "parser.y" /* yacc.c:1652  */
    {
        class_definiton_param_list_finish();
    }
#line 2395 "parser.c" /* yacc.c:1652  */
    break;

  case 76:
#line 306 "parser.y" /* yacc.c:1652  */
    {
        class_definiton_body_start();
    }
#line 2403 "parser.c" /* yacc.c:1652  */
    break;

  case 77:
#line 308 "parser.y" /* yacc.c:1652  */
    {
        class_definiton_body_finish();
    }
#line 2411 "parser.c" /* yacc.c:1652  */
    break;

  case 79:
#line 317 "parser.y" /* yacc.c:1652  */
    {
        class_data_definition_with_data_attrs();
    }
#line 2419 "parser.c" /* yacc.c:1652  */
    break;

  case 80:
#line 319 "parser.y" /* yacc.c:1652  */
    {
        class_data_definition_add_data_attrs();
    }
#line 2427 "parser.c" /* yacc.c:1652  */
    break;

  case 81:
#line 321 "parser.y" /* yacc.c:1652  */
    {
        class_data_definition_name();
    }
#line 2435 "parser.c" /* yacc.c:1652  */
    break;

  case 82:
#line 323 "parser.y" /* yacc.c:1652  */
    {
        class_data_definition_finish();
    }
#line 2443 "parser.c" /* yacc.c:1652  */
    break;

  case 83:
#line 326 "parser.y" /* yacc.c:1652  */
    {
        class_data_definition_no_data_attrs();
    }
#line 2451 "parser.c" /* yacc.c:1652  */
    break;

  case 84:
#line 328 "parser.y" /* yacc.c:1652  */
    {
        class_data_definition_name();
    }
#line 2459 "parser.c" /* yacc.c:1652  */
    break;

  case 85:
#line 330 "parser.y" /* yacc.c:1652  */
    {
        class_data_definition_finish();
    }
#line 2467 "parser.c" /* yacc.c:1652  */
    break;

  case 86:
#line 336 "parser.y" /* yacc.c:1652  */
    {
        function_data_definition_target_nothing();
    }
#line 2475 "parser.c" /* yacc.c:1652  */
    break;

  case 87:
#line 339 "parser.y" /* yacc.c:1652  */
    {
        function_data_definition_target_expression();
    }
#line 2483 "parser.c" /* yacc.c:1652  */
    break;

  case 88:
#line 342 "parser.y" /* yacc.c:1652  */
    {
        function_data_definition_target_cast();
    }
#line 2491 "parser.c" /* yacc.c:1652  */
    break;

  case 89:
#line 344 "parser.y" /* yacc.c:1652  */
    {
        function_data_definition_target_expression();
    }
#line 2499 "parser.c" /* yacc.c:1652  */
    break;

  case 90:
#line 347 "parser.y" /* yacc.c:1652  */
    {
        function_data_definition_target_formatted_string();
    }
#line 2507 "parser.c" /* yacc.c:1652  */
    break;

  case 91:
#line 353 "parser.y" /* yacc.c:1652  */
    {
        function_data_definition_symbol();
    }
#line 2515 "parser.c" /* yacc.c:1652  */
    break;

  case 92:
#line 356 "parser.y" /* yacc.c:1652  */
    {
        function_data_definition_const_symbol();
    }
#line 2523 "parser.c" /* yacc.c:1652  */
    break;

  case 93:
#line 362 "parser.y" /* yacc.c:1652  */
    {
        function_data_definition_no_initializer();
    }
#line 2531 "parser.c" /* yacc.c:1652  */
    break;

  case 94:
#line 365 "parser.y" /* yacc.c:1652  */
    {
        function_data_definition_with_initializer();
    }
#line 2539 "parser.c" /* yacc.c:1652  */
    break;

  case 95:
#line 367 "parser.y" /* yacc.c:1652  */
    {
        function_data_definition_with_initializer_finish();
    }
#line 2547 "parser.c" /* yacc.c:1652  */
    break;

  case 96:
#line 376 "parser.y" /* yacc.c:1652  */
    {
        method_def_param_intrinsic_type();
    }
#line 2555 "parser.c" /* yacc.c:1652  */
    break;

  case 97:
#line 378 "parser.y" /* yacc.c:1652  */
    {
        method_def_param_symbol();
    }
#line 2563 "parser.c" /* yacc.c:1652  */
    break;

  case 98:
#line 384 "parser.y" /* yacc.c:1652  */
    {
        method_def_param_list_method_def_param_create();
    }
#line 2571 "parser.c" /* yacc.c:1652  */
    break;

  case 99:
#line 387 "parser.y" /* yacc.c:1652  */
    {
        method_def_param_list_method_def_param_add();
    }
#line 2579 "parser.c" /* yacc.c:1652  */
    break;

  case 100:
#line 393 "parser.y" /* yacc.c:1652  */
    {
        method_param_def_finish();
    }
#line 2587 "parser.c" /* yacc.c:1652  */
    break;

  case 101:
#line 396 "parser.y" /* yacc.c:1652  */
    {
        method_param_def_blank();
    }
#line 2595 "parser.c" /* yacc.c:1652  */
    break;

  case 102:
#line 402 "parser.y" /* yacc.c:1652  */
    {
        method_definition_with_attrs_start();
    }
#line 2603 "parser.c" /* yacc.c:1652  */
    break;

  case 103:
#line 404 "parser.y" /* yacc.c:1652  */
    {
        method_definition_attrs_finish();
    }
#line 2611 "parser.c" /* yacc.c:1652  */
    break;

  case 104:
#line 406 "parser.y" /* yacc.c:1652  */
    {
        method_definition_symbol();
    }
#line 2619 "parser.c" /* yacc.c:1652  */
    break;

  case 105:
#line 408 "parser.y" /* yacc.c:1652  */
    {
        method_definition_input_params_start();
    }
#line 2627 "parser.c" /* yacc.c:1652  */
    break;

  case 106:
#line 410 "parser.y" /* yacc.c:1652  */
    {
        method_definition_input_params_finish();
    }
#line 2635 "parser.c" /* yacc.c:1652  */
    break;

  case 107:
#line 412 "parser.y" /* yacc.c:1652  */
    {
        method_definition_output_params_start();
    }
#line 2643 "parser.c" /* yacc.c:1652  */
    break;

  case 108:
#line 414 "parser.y" /* yacc.c:1652  */
    {
        method_definition_output_params_finish();
    }
#line 2651 "parser.c" /* yacc.c:1652  */
    break;

  case 109:
#line 416 "parser.y" /* yacc.c:1652  */
    {
        method_definition_method_body_start();
    }
#line 2659 "parser.c" /* yacc.c:1652  */
    break;

  case 110:
#line 418 "parser.y" /* yacc.c:1652  */
    {
        method_definition_method_body_finish();
    }
#line 2667 "parser.c" /* yacc.c:1652  */
    break;

  case 111:
#line 421 "parser.y" /* yacc.c:1652  */
    {
        method_definition_no_attrs_start();
    }
#line 2675 "parser.c" /* yacc.c:1652  */
    break;

  case 112:
#line 423 "parser.y" /* yacc.c:1652  */
    {
        method_definition_symbol();
    }
#line 2683 "parser.c" /* yacc.c:1652  */
    break;

  case 113:
#line 425 "parser.y" /* yacc.c:1652  */
    {
        method_definition_input_params_start();
    }
#line 2691 "parser.c" /* yacc.c:1652  */
    break;

  case 114:
#line 427 "parser.y" /* yacc.c:1652  */
    {
        method_definition_input_params_finish();
    }
#line 2699 "parser.c" /* yacc.c:1652  */
    break;

  case 115:
#line 429 "parser.y" /* yacc.c:1652  */
    {
        method_definition_output_params_start();
    }
#line 2707 "parser.c" /* yacc.c:1652  */
    break;

  case 116:
#line 431 "parser.y" /* yacc.c:1652  */
    {
        method_definition_output_params_finish();
    }
#line 2715 "parser.c" /* yacc.c:1652  */
    break;

  case 117:
#line 433 "parser.y" /* yacc.c:1652  */
    {
        method_definition_method_body_start();
    }
#line 2723 "parser.c" /* yacc.c:1652  */
    break;

  case 118:
#line 435 "parser.y" /* yacc.c:1652  */
    {
        method_definition_method_body_finish();
    }
#line 2731 "parser.c" /* yacc.c:1652  */
    break;

  case 119:
#line 441 "parser.y" /* yacc.c:1652  */
    {
        method_body_element_data_definition_finish();
    }
#line 2739 "parser.c" /* yacc.c:1652  */
    break;

  case 120:
#line 444 "parser.y" /* yacc.c:1652  */
    {
        method_body_element_try_finish();
    }
#line 2747 "parser.c" /* yacc.c:1652  */
    break;

  case 121:
#line 447 "parser.y" /* yacc.c:1652  */
    {
        method_body_element_raise_finish();
    }
#line 2755 "parser.c" /* yacc.c:1652  */
    break;

  case 122:
#line 450 "parser.y" /* yacc.c:1652  */
    {
        method_body_element_function_call_finish();
    }
#line 2763 "parser.c" /* yacc.c:1652  */
    break;

  case 123:
#line 453 "parser.y" /* yacc.c:1652  */
    {
        method_body_element_for_finish();
    }
#line 2771 "parser.c" /* yacc.c:1652  */
    break;

  case 124:
#line 456 "parser.y" /* yacc.c:1652  */
    {
        method_body_element_if_finish();
    }
#line 2779 "parser.c" /* yacc.c:1652  */
    break;

  case 125:
#line 459 "parser.y" /* yacc.c:1652  */
    {
        method_body_element_while_finish();
    }
#line 2787 "parser.c" /* yacc.c:1652  */
    break;

  case 126:
#line 462 "parser.y" /* yacc.c:1652  */
    {
        method_body_element_do_finish();
    }
#line 2795 "parser.c" /* yacc.c:1652  */
    break;

  case 127:
#line 465 "parser.y" /* yacc.c:1652  */
    {
        method_body_element_switch_finish();
    }
#line 2803 "parser.c" /* yacc.c:1652  */
    break;

  case 128:
#line 468 "parser.y" /* yacc.c:1652  */
    {
        method_body_element_inc_finish();
    }
#line 2811 "parser.c" /* yacc.c:1652  */
    break;

  case 129:
#line 471 "parser.y" /* yacc.c:1652  */
    {
        method_body_element_assignment_finish();
    }
#line 2819 "parser.c" /* yacc.c:1652  */
    break;

  case 130:
#line 477 "parser.y" /* yacc.c:1652  */
    {
        method_body_element_list_finish();
    }
#line 2827 "parser.c" /* yacc.c:1652  */
    break;

  case 131:
#line 480 "parser.y" /* yacc.c:1652  */
    {
        method_body_element_list_finish();
    }
#line 2835 "parser.c" /* yacc.c:1652  */
    break;

  case 132:
#line 486 "parser.y" /* yacc.c:1652  */
    {
        method_body_element_start();
    }
#line 2843 "parser.c" /* yacc.c:1652  */
    break;

  case 133:
#line 488 "parser.y" /* yacc.c:1652  */
    {
        method_body_element_finish();
    }
#line 2851 "parser.c" /* yacc.c:1652  */
    break;

  case 134:
#line 490 "parser.y" /* yacc.c:1652  */
    {
        method_body_finish();
    }
#line 2859 "parser.c" /* yacc.c:1652  */
    break;

  case 135:
#line 493 "parser.y" /* yacc.c:1652  */
    {
        method_body_blank();
    }
#line 2867 "parser.c" /* yacc.c:1652  */
    break;

  case 136:
#line 499 "parser.y" /* yacc.c:1652  */
    {
        constructor_definition_start();
    }
#line 2875 "parser.c" /* yacc.c:1652  */
    break;

  case 137:
#line 501 "parser.y" /* yacc.c:1652  */
    {
        constructor_definition_param_start();
    }
#line 2883 "parser.c" /* yacc.c:1652  */
    break;

  case 138:
#line 503 "parser.y" /* yacc.c:1652  */
    {
        constructor_definition_param_finish();
    }
#line 2891 "parser.c" /* yacc.c:1652  */
    break;

  case 139:
#line 505 "parser.y" /* yacc.c:1652  */
    {
        constructor_definition_body_start();
    }
#line 2899 "parser.c" /* yacc.c:1652  */
    break;

  case 140:
#line 507 "parser.y" /* yacc.c:1652  */
    {
        constructor_definition_body_finish();
    }
#line 2907 "parser.c" /* yacc.c:1652  */
    break;

  case 141:
#line 513 "parser.y" /* yacc.c:1652  */
    {
        destructor_definition_body_start();
    }
#line 2915 "parser.c" /* yacc.c:1652  */
    break;

  case 142:
#line 515 "parser.y" /* yacc.c:1652  */
    {
        destructor_definition_body_finish();
    }
#line 2923 "parser.c" /* yacc.c:1652  */
    break;

  case 143:
#line 524 "parser.y" /* yacc.c:1652  */
    {
        subscript_item_expression_start();
    }
#line 2931 "parser.c" /* yacc.c:1652  */
    break;

  case 144:
#line 526 "parser.y" /* yacc.c:1652  */
    {
        subscript_item_expression_finish();
    }
#line 2939 "parser.c" /* yacc.c:1652  */
    break;

  case 146:
#line 529 "parser.y" /* yacc.c:1652  */
    {
        subscript_item_formatted_string_start();
    }
#line 2947 "parser.c" /* yacc.c:1652  */
    break;

  case 147:
#line 531 "parser.y" /* yacc.c:1652  */
    {
        subscript_item_formatted_string_finish();
    }
#line 2955 "parser.c" /* yacc.c:1652  */
    break;

  case 149:
#line 537 "parser.y" /* yacc.c:1652  */
    {
        subscript_list_init();
    }
#line 2963 "parser.c" /* yacc.c:1652  */
    break;

  case 150:
#line 540 "parser.y" /* yacc.c:1652  */
    {
        subscript_list_add();
    }
#line 2971 "parser.c" /* yacc.c:1652  */
    break;

  case 151:
#line 545 "parser.y" /* yacc.c:1652  */
    {
        expression_name_complex_name();
    }
#line 2979 "parser.c" /* yacc.c:1652  */
    break;

  case 152:
#line 548 "parser.y" /* yacc.c:1652  */
    {
        expression_name_complex_name_with_subscript();
    }
#line 2987 "parser.c" /* yacc.c:1652  */
    break;

  case 153:
#line 550 "parser.y" /* yacc.c:1652  */
    {
        expression_name_subscript_list_finish();
    }
#line 2995 "parser.c" /* yacc.c:1652  */
    break;

  case 154:
#line 556 "parser.y" /* yacc.c:1652  */
    {
        expression_literal_number();
    }
#line 3003 "parser.c" /* yacc.c:1652  */
    break;

  case 155:
#line 559 "parser.y" /* yacc.c:1652  */
    {
        expression_expression_name();
    }
#line 3011 "parser.c" /* yacc.c:1652  */
    break;

  case 156:
#line 562 "parser.y" /* yacc.c:1652  */
    {
        expression_addition_operation();
    }
#line 3019 "parser.c" /* yacc.c:1652  */
    break;

  case 157:
#line 565 "parser.y" /* yacc.c:1652  */
    {
        expression_subtraction_operation();
    }
#line 3027 "parser.c" /* yacc.c:1652  */
    break;

  case 158:
#line 568 "parser.y" /* yacc.c:1652  */
    {
        expression_division_operation();
    }
#line 3035 "parser.c" /* yacc.c:1652  */
    break;

  case 159:
#line 571 "parser.y" /* yacc.c:1652  */
    {
        expression_multiplication_operation();
    }
#line 3043 "parser.c" /* yacc.c:1652  */
    break;

  case 160:
#line 574 "parser.y" /* yacc.c:1652  */
    {
        expression_modulo_operation();
    }
#line 3051 "parser.c" /* yacc.c:1652  */
    break;

  case 161:
#line 577 "parser.y" /* yacc.c:1652  */
    {
        expression_and_boolean_operation();
    }
#line 3059 "parser.c" /* yacc.c:1652  */
    break;

  case 162:
#line 580 "parser.y" /* yacc.c:1652  */
    {
        expression_or_boolean_operation();
    }
#line 3067 "parser.c" /* yacc.c:1652  */
    break;

  case 163:
#line 583 "parser.y" /* yacc.c:1652  */
    {
        expression_less_boolean_operation();
    }
#line 3075 "parser.c" /* yacc.c:1652  */
    break;

  case 164:
#line 586 "parser.y" /* yacc.c:1652  */
    {
        expression_greater_boolean_operation();
    }
#line 3083 "parser.c" /* yacc.c:1652  */
    break;

  case 165:
#line 589 "parser.y" /* yacc.c:1652  */
    {
        expression_equal_boolean_operation();
    }
#line 3091 "parser.c" /* yacc.c:1652  */
    break;

  case 166:
#line 592 "parser.y" /* yacc.c:1652  */
    {
        expression_not_equal_boolean_operation();
    }
#line 3099 "parser.c" /* yacc.c:1652  */
    break;

  case 167:
#line 595 "parser.y" /* yacc.c:1652  */
    {
        expression_less_or_equal_boolean_operation();
    }
#line 3107 "parser.c" /* yacc.c:1652  */
    break;

  case 168:
#line 598 "parser.y" /* yacc.c:1652  */
    {
        expression_greater_or_equal_boolean_operation();
    }
#line 3115 "parser.c" /* yacc.c:1652  */
    break;

  case 169:
#line 601 "parser.y" /* yacc.c:1652  */
    {
        expression_and_bitwise_operation();
    }
#line 3123 "parser.c" /* yacc.c:1652  */
    break;

  case 170:
#line 604 "parser.y" /* yacc.c:1652  */
    {
        expression_or_bitwise_operation();
    }
#line 3131 "parser.c" /* yacc.c:1652  */
    break;

  case 171:
#line 607 "parser.y" /* yacc.c:1652  */
    {
        expression_xor_bitwise_operation();
    }
#line 3139 "parser.c" /* yacc.c:1652  */
    break;

  case 172:
#line 610 "parser.y" /* yacc.c:1652  */
    {
        expression_rotate_left_bitwise_operation();
    }
#line 3147 "parser.c" /* yacc.c:1652  */
    break;

  case 173:
#line 613 "parser.y" /* yacc.c:1652  */
    {
        expression_rotate_right_bitwise_operation();
    }
#line 3155 "parser.c" /* yacc.c:1652  */
    break;

  case 174:
#line 616 "parser.y" /* yacc.c:1652  */
    {
        expression_shift_left_bitwise_operation();
    }
#line 3163 "parser.c" /* yacc.c:1652  */
    break;

  case 175:
#line 619 "parser.y" /* yacc.c:1652  */
    {
        expression_shift_right_bitwise_operation();
    }
#line 3171 "parser.c" /* yacc.c:1652  */
    break;

  case 176:
#line 622 "parser.y" /* yacc.c:1652  */
    {
        expression_unary_negate_operation();
    }
#line 3179 "parser.c" /* yacc.c:1652  */
    break;

  case 177:
#line 625 "parser.y" /* yacc.c:1652  */
    {
        expression_unary_not_boolean_operation();
    }
#line 3187 "parser.c" /* yacc.c:1652  */
    break;

  case 178:
#line 628 "parser.y" /* yacc.c:1652  */
    {
        expression_not_bitwise_operation();
    }
#line 3195 "parser.c" /* yacc.c:1652  */
    break;

  case 180:
#line 647 "parser.y" /* yacc.c:1652  */
    {
        function_call_parameter_formatted_string();
    }
#line 3203 "parser.c" /* yacc.c:1652  */
    break;

  case 181:
#line 650 "parser.y" /* yacc.c:1652  */
    {
        function_call_parameter_expression();
    }
#line 3211 "parser.c" /* yacc.c:1652  */
    break;

  case 183:
#line 657 "parser.y" /* yacc.c:1652  */
    {
        function_call_parameter_list_create();
    }
#line 3219 "parser.c" /* yacc.c:1652  */
    break;

  case 184:
#line 660 "parser.y" /* yacc.c:1652  */
    {
        function_call_parameter_list_add();
    }
#line 3227 "parser.c" /* yacc.c:1652  */
    break;

  case 185:
#line 666 "parser.y" /* yacc.c:1652  */
    {
        function_call_complex_name();
    }
#line 3235 "parser.c" /* yacc.c:1652  */
    break;

  case 186:
#line 668 "parser.y" /* yacc.c:1652  */
    {
        function_call_input_parameter_start();
    }
#line 3243 "parser.c" /* yacc.c:1652  */
    break;

  case 187:
#line 670 "parser.y" /* yacc.c:1652  */
    {
        function_call_input_parameter_finish();
    }
#line 3251 "parser.c" /* yacc.c:1652  */
    break;

  case 188:
#line 672 "parser.y" /* yacc.c:1652  */
    {
        function_call_output_parameter_start();
    }
#line 3259 "parser.c" /* yacc.c:1652  */
    break;

  case 189:
#line 674 "parser.y" /* yacc.c:1652  */
    {
        function_call_output_parameter_finish();
    }
#line 3267 "parser.c" /* yacc.c:1652  */
    break;

  case 190:
#line 676 "parser.y" /* yacc.c:1652  */
    {
        function_call_finish();
    }
#line 3275 "parser.c" /* yacc.c:1652  */
    break;

  case 191:
#line 679 "parser.y" /* yacc.c:1652  */
    {
        function_call_destroy_complex_name();
    }
#line 3283 "parser.c" /* yacc.c:1652  */
    break;

  case 192:
#line 681 "parser.y" /* yacc.c:1652  */
    {
        function_call_destroy_finish();
    }
#line 3291 "parser.c" /* yacc.c:1652  */
    break;

  case 193:
#line 690 "parser.y" /* yacc.c:1652  */
    {
        branch_expression_expression();
    }
#line 3299 "parser.c" /* yacc.c:1652  */
    break;

  case 194:
#line 693 "parser.y" /* yacc.c:1652  */
    {
        branch_expression_bool_value();
    }
#line 3307 "parser.c" /* yacc.c:1652  */
    break;

  case 195:
#line 700 "parser.y" /* yacc.c:1652  */
    {
        jump_clause_continue();
    }
#line 3315 "parser.c" /* yacc.c:1652  */
    break;

  case 196:
#line 703 "parser.y" /* yacc.c:1652  */
    {
        jump_clause_break();
    }
#line 3323 "parser.c" /* yacc.c:1652  */
    break;

  case 197:
#line 709 "parser.y" /* yacc.c:1652  */
    {
        post_inc_complex_name();
    }
#line 3331 "parser.c" /* yacc.c:1652  */
    break;

  case 198:
#line 711 "parser.y" /* yacc.c:1652  */
    {
        post_inc_finish();
    }
#line 3339 "parser.c" /* yacc.c:1652  */
    break;

  case 199:
#line 714 "parser.y" /* yacc.c:1652  */
    {
        post_dec_complex_name();
    }
#line 3347 "parser.c" /* yacc.c:1652  */
    break;

  case 200:
#line 716 "parser.y" /* yacc.c:1652  */
    {
        post_dec_finish();
    }
#line 3355 "parser.c" /* yacc.c:1652  */
    break;

  case 201:
#line 719 "parser.y" /* yacc.c:1652  */
    {
        pre_inc_start();
    }
#line 3363 "parser.c" /* yacc.c:1652  */
    break;

  case 202:
#line 721 "parser.y" /* yacc.c:1652  */
    {
        pre_inc_complex_name();
    }
#line 3371 "parser.c" /* yacc.c:1652  */
    break;

  case 203:
#line 724 "parser.y" /* yacc.c:1652  */
    {
        pre_dec_start();
    }
#line 3379 "parser.c" /* yacc.c:1652  */
    break;

  case 204:
#line 726 "parser.y" /* yacc.c:1652  */
    {
        pre_dec_complex_name();
    }
#line 3387 "parser.c" /* yacc.c:1652  */
    break;

  case 205:
#line 732 "parser.y" /* yacc.c:1652  */
    {
        loop_body_element_method_body_element();
    }
#line 3395 "parser.c" /* yacc.c:1652  */
    break;

  case 206:
#line 735 "parser.y" /* yacc.c:1652  */
    {
        loop_body_element_jump_clause_element();
    }
#line 3403 "parser.c" /* yacc.c:1652  */
    break;

  case 207:
#line 741 "parser.y" /* yacc.c:1652  */
    {
        loop_body_element_list_init();
    }
#line 3411 "parser.c" /* yacc.c:1652  */
    break;

  case 208:
#line 744 "parser.y" /* yacc.c:1652  */
    {
        loop_body_element_list_add();
    }
#line 3419 "parser.c" /* yacc.c:1652  */
    break;

  case 209:
#line 750 "parser.y" /* yacc.c:1652  */
    {
        loop_body_element_empty();
    }
#line 3427 "parser.c" /* yacc.c:1652  */
    break;

  case 210:
#line 753 "parser.y" /* yacc.c:1652  */
    {
        loop_body_element_start();
    }
#line 3435 "parser.c" /* yacc.c:1652  */
    break;

  case 211:
#line 755 "parser.y" /* yacc.c:1652  */
    {
        loop_body_element_finish();
    }
#line 3443 "parser.c" /* yacc.c:1652  */
    break;

  case 212:
#line 757 "parser.y" /* yacc.c:1652  */
    {
        loop_body_finish();
    }
#line 3451 "parser.c" /* yacc.c:1652  */
    break;

  case 213:
#line 766 "parser.y" /* yacc.c:1652  */
    {
        for_initialize_assign_nothing();
    }
#line 3459 "parser.c" /* yacc.c:1652  */
    break;

  case 214:
#line 769 "parser.y" /* yacc.c:1652  */
    {
        for_initialize_assign_expression();
    }
#line 3467 "parser.c" /* yacc.c:1652  */
    break;

  case 215:
#line 772 "parser.y" /* yacc.c:1652  */
    {
        for_initialize_assign_bool_value();
    }
#line 3475 "parser.c" /* yacc.c:1652  */
    break;

  case 216:
#line 778 "parser.y" /* yacc.c:1652  */
    {
        for_initialize_intrinsic_type();
    }
#line 3483 "parser.c" /* yacc.c:1652  */
    break;

  case 217:
#line 780 "parser.y" /* yacc.c:1652  */
    {
        for_initialize_symbol();
    }
#line 3491 "parser.c" /* yacc.c:1652  */
    break;

  case 218:
#line 782 "parser.y" /* yacc.c:1652  */
    {
        for_initialize_data_definition_finish();
    }
#line 3499 "parser.c" /* yacc.c:1652  */
    break;

  case 219:
#line 785 "parser.y" /* yacc.c:1652  */
    {
        for_initialize_assignment();
    }
#line 3507 "parser.c" /* yacc.c:1652  */
    break;

  case 220:
#line 787 "parser.y" /* yacc.c:1652  */
    {
        for_initialize_assignment_finish();
    }
#line 3515 "parser.c" /* yacc.c:1652  */
    break;

  case 221:
#line 794 "parser.y" /* yacc.c:1652  */
    {
        for_test_expression();
    }
#line 3523 "parser.c" /* yacc.c:1652  */
    break;

  case 222:
#line 796 "parser.y" /* yacc.c:1652  */
    {
        for_test_expression_finish();
    }
#line 3531 "parser.c" /* yacc.c:1652  */
    break;

  case 223:
#line 802 "parser.y" /* yacc.c:1652  */
    {
        for_arith_expression_expression();
    }
#line 3539 "parser.c" /* yacc.c:1652  */
    break;

  case 224:
#line 805 "parser.y" /* yacc.c:1652  */
    {
        for_arith_expression_pre_post_inc();
    }
#line 3547 "parser.c" /* yacc.c:1652  */
    break;

  case 225:
#line 808 "parser.y" /* yacc.c:1652  */
    {
        for_arith_expression_assignment();
    }
#line 3555 "parser.c" /* yacc.c:1652  */
    break;

  case 226:
#line 814 "parser.y" /* yacc.c:1652  */
    {
        for_clause_definition_init();
    }
#line 3563 "parser.c" /* yacc.c:1652  */
    break;

  case 227:
#line 816 "parser.y" /* yacc.c:1652  */
    {
        for_clause_definition_finish();
    }
#line 3571 "parser.c" /* yacc.c:1652  */
    break;

  case 228:
#line 818 "parser.y" /* yacc.c:1652  */
    {
        for_clause_loop_body_finish();
    }
#line 3579 "parser.c" /* yacc.c:1652  */
    break;

  case 229:
#line 827 "parser.y" /* yacc.c:1652  */
    {
        else_clause_experssion_start();
    }
#line 3587 "parser.c" /* yacc.c:1652  */
    break;

  case 230:
#line 829 "parser.y" /* yacc.c:1652  */
    {
        else_clause_experssion_finish();
    }
#line 3595 "parser.c" /* yacc.c:1652  */
    break;

  case 231:
#line 831 "parser.y" /* yacc.c:1652  */
    {
        else_clause_method_body_finish();
    }
#line 3603 "parser.c" /* yacc.c:1652  */
    break;

  case 232:
#line 834 "parser.y" /* yacc.c:1652  */
    {
        else_clause_no_expression();
    }
#line 3611 "parser.c" /* yacc.c:1652  */
    break;

  case 233:
#line 836 "parser.y" /* yacc.c:1652  */
    {
        else_clause_method_body_finish();
    }
#line 3619 "parser.c" /* yacc.c:1652  */
    break;

  case 234:
#line 842 "parser.y" /* yacc.c:1652  */
    {
        else_body_else_clause_init();
    }
#line 3627 "parser.c" /* yacc.c:1652  */
    break;

  case 235:
#line 845 "parser.y" /* yacc.c:1652  */
    {
        else_body_else_clause_add();
    }
#line 3635 "parser.c" /* yacc.c:1652  */
    break;

  case 236:
#line 848 "parser.y" /* yacc.c:1652  */
    {
        else_clause_method_body_finish();
    }
#line 3643 "parser.c" /* yacc.c:1652  */
    break;

  case 237:
#line 854 "parser.y" /* yacc.c:1652  */
    {
        if_clause_expression_start();
    }
#line 3651 "parser.c" /* yacc.c:1652  */
    break;

  case 238:
#line 856 "parser.y" /* yacc.c:1652  */
    {
        if_clause_expression_finish();
    }
#line 3659 "parser.c" /* yacc.c:1652  */
    break;

  case 239:
#line 858 "parser.y" /* yacc.c:1652  */
    {
        if_clause_else_body_finish();
    }
#line 3667 "parser.c" /* yacc.c:1652  */
    break;

  case 240:
#line 867 "parser.y" /* yacc.c:1652  */
    {
        while_clause_experssion_start();
    }
#line 3675 "parser.c" /* yacc.c:1652  */
    break;

  case 241:
#line 869 "parser.y" /* yacc.c:1652  */
    {
        while_clause_expression_finish();
    }
#line 3683 "parser.c" /* yacc.c:1652  */
    break;

  case 242:
#line 871 "parser.y" /* yacc.c:1652  */
    {
        while_clause_loop_body_finish();
    }
#line 3691 "parser.c" /* yacc.c:1652  */
    break;

  case 243:
#line 877 "parser.y" /* yacc.c:1652  */
    {
        do_clause_loop_body_start();
    }
#line 3699 "parser.c" /* yacc.c:1652  */
    break;

  case 244:
#line 879 "parser.y" /* yacc.c:1652  */
    {
        do_clause_loop_body_finish();
    }
#line 3707 "parser.c" /* yacc.c:1652  */
    break;

  case 245:
#line 881 "parser.y" /* yacc.c:1652  */
    {
        do_clause_expression_start();
    }
#line 3715 "parser.c" /* yacc.c:1652  */
    break;

  case 246:
#line 883 "parser.y" /* yacc.c:1652  */
    {
        do_clause_expression_finish();
    }
#line 3723 "parser.c" /* yacc.c:1652  */
    break;

  case 247:
#line 885 "parser.y" /* yacc.c:1652  */
    {
        do_clause_finish();
    }
#line 3731 "parser.c" /* yacc.c:1652  */
    break;

  case 249:
#line 895 "parser.y" /* yacc.c:1652  */
    {
        except_parameter_formatted_string();
    }
#line 3739 "parser.c" /* yacc.c:1652  */
    break;

  case 250:
#line 898 "parser.y" /* yacc.c:1652  */
    {
        except_parameter_complex_name();
    }
#line 3747 "parser.c" /* yacc.c:1652  */
    break;

  case 251:
#line 904 "parser.y" /* yacc.c:1652  */
    {
        except_parameter_list_init();
    }
#line 3755 "parser.c" /* yacc.c:1652  */
    break;

  case 252:
#line 907 "parser.y" /* yacc.c:1652  */
    {
        except_parameter_list_add();
    }
#line 3763 "parser.c" /* yacc.c:1652  */
    break;

  case 253:
#line 913 "parser.y" /* yacc.c:1652  */
    {
        except_clause_parameter_list_start();
    }
#line 3771 "parser.c" /* yacc.c:1652  */
    break;

  case 254:
#line 915 "parser.y" /* yacc.c:1652  */
    {
        except_clause_parameter_list_finish();
    }
#line 3779 "parser.c" /* yacc.c:1652  */
    break;

  case 255:
#line 917 "parser.y" /* yacc.c:1652  */
    {
        except_clause_method_body_finish();
    }
#line 3787 "parser.c" /* yacc.c:1652  */
    break;

  case 256:
#line 920 "parser.y" /* yacc.c:1652  */
    {
        except_clause_complex_name();
    }
#line 3795 "parser.c" /* yacc.c:1652  */
    break;

  case 257:
#line 922 "parser.y" /* yacc.c:1652  */
    {
        except_clause_parameter_list_start();
    }
#line 3803 "parser.c" /* yacc.c:1652  */
    break;

  case 258:
#line 924 "parser.y" /* yacc.c:1652  */
    {
        except_clause_parameter_list_start();
    }
#line 3811 "parser.c" /* yacc.c:1652  */
    break;

  case 259:
#line 926 "parser.y" /* yacc.c:1652  */
    {
        except_clause_method_body_finish();
    }
#line 3819 "parser.c" /* yacc.c:1652  */
    break;

  case 260:
#line 932 "parser.y" /* yacc.c:1652  */
    {
        final_clause_start();
    }
#line 3827 "parser.c" /* yacc.c:1652  */
    break;

  case 261:
#line 934 "parser.y" /* yacc.c:1652  */
    {
        final_clause_finish();
    }
#line 3835 "parser.c" /* yacc.c:1652  */
    break;

  case 262:
#line 940 "parser.y" /* yacc.c:1652  */
    {
        try_clause_intro_start();
    }
#line 3843 "parser.c" /* yacc.c:1652  */
    break;

  case 263:
#line 942 "parser.y" /* yacc.c:1652  */
    {
        try_clause_intro_finish();
    }
#line 3851 "parser.c" /* yacc.c:1652  */
    break;

  case 265:
#line 949 "parser.y" /* yacc.c:1652  */
    {
        try_clause_finish();
    }
#line 3859 "parser.c" /* yacc.c:1652  */
    break;

  case 266:
#line 955 "parser.y" /* yacc.c:1652  */
    {
        raise_clause_parameter_start();
    }
#line 3867 "parser.c" /* yacc.c:1652  */
    break;

  case 267:
#line 957 "parser.y" /* yacc.c:1652  */
    {
        raise_clause_parameter_finish();
    }
#line 3875 "parser.c" /* yacc.c:1652  */
    break;

  case 268:
#line 959 "parser.y" /* yacc.c:1652  */
    {
        raise_clause_finish();
    }
#line 3883 "parser.c" /* yacc.c:1652  */
    break;

  case 269:
#line 968 "parser.y" /* yacc.c:1652  */
    {
        case_clause_unum();
    }
#line 3891 "parser.c" /* yacc.c:1652  */
    break;

  case 270:
#line 970 "parser.y" /* yacc.c:1652  */
    {
        case_clause_loop_body_finish();
    }
#line 3899 "parser.c" /* yacc.c:1652  */
    break;

  case 271:
#line 973 "parser.y" /* yacc.c:1652  */
    {
        case_clause_inum();
    }
#line 3907 "parser.c" /* yacc.c:1652  */
    break;

  case 272:
#line 975 "parser.y" /* yacc.c:1652  */
    {
        case_clause_loop_body_finish();
    }
#line 3915 "parser.c" /* yacc.c:1652  */
    break;

  case 273:
#line 978 "parser.y" /* yacc.c:1652  */
    {
        case_clause_fnum();
    }
#line 3923 "parser.c" /* yacc.c:1652  */
    break;

  case 274:
#line 980 "parser.y" /* yacc.c:1652  */
    {
        case_clause_loop_body_finish();
    }
#line 3931 "parser.c" /* yacc.c:1652  */
    break;

  case 275:
#line 986 "parser.y" /* yacc.c:1652  */
    {
        default_case();
    }
#line 3939 "parser.c" /* yacc.c:1652  */
    break;

  case 276:
#line 988 "parser.y" /* yacc.c:1652  */
    {
        case_clause_loop_body_finish();
    }
#line 3947 "parser.c" /* yacc.c:1652  */
    break;

  case 277:
#line 994 "parser.y" /* yacc.c:1652  */
    {
        case_body_init();
    }
#line 3955 "parser.c" /* yacc.c:1652  */
    break;

  case 278:
#line 997 "parser.y" /* yacc.c:1652  */
    {
        case_body_add();
    }
#line 3963 "parser.c" /* yacc.c:1652  */
    break;

  case 279:
#line 1003 "parser.y" /* yacc.c:1652  */
    {
        switch_clause_intro_expression_start();
    }
#line 3971 "parser.c" /* yacc.c:1652  */
    break;

  case 280:
#line 1005 "parser.y" /* yacc.c:1652  */
    {
        switch_clause_intro_expression_finish();
    }
#line 3979 "parser.c" /* yacc.c:1652  */
    break;

  case 281:
#line 1007 "parser.y" /* yacc.c:1652  */
    {
        switch_clause_intro_case_body_start();
    }
#line 3987 "parser.c" /* yacc.c:1652  */
    break;

  case 282:
#line 1009 "parser.y" /* yacc.c:1652  */
    {
        switch_clause_intro_case_body_finish();
    }
#line 3995 "parser.c" /* yacc.c:1652  */
    break;

  case 283:
#line 1015 "parser.y" /* yacc.c:1652  */
    {
        switch_clause_after_intro();
    }
#line 4003 "parser.c" /* yacc.c:1652  */
    break;

  case 284:
#line 1018 "parser.y" /* yacc.c:1652  */
    {
        switch_clause_after_intro_default();
    }
#line 4011 "parser.c" /* yacc.c:1652  */
    break;

  case 285:
#line 1020 "parser.y" /* yacc.c:1652  */
    {
        switch_clause_finish();
    }
#line 4019 "parser.c" /* yacc.c:1652  */
    break;

  case 286:
#line 1029 "parser.y" /* yacc.c:1652  */
    {
        type_cast_type();
    }
#line 4027 "parser.c" /* yacc.c:1652  */
    break;

  case 287:
#line 1031 "parser.y" /* yacc.c:1652  */
    {
        type_cast_type_finish();
    }
#line 4035 "parser.c" /* yacc.c:1652  */
    break;

  case 288:
#line 1037 "parser.y" /* yacc.c:1652  */
    {
        assignment_target_expression();
    }
#line 4043 "parser.c" /* yacc.c:1652  */
    break;

  case 289:
#line 1040 "parser.y" /* yacc.c:1652  */
    {
        assignment_target_formatted_string();
    }
#line 4051 "parser.c" /* yacc.c:1652  */
    break;

  case 290:
#line 1043 "parser.y" /* yacc.c:1652  */
    {
        assignment_target_type_cast_expression();
    }
#line 4059 "parser.c" /* yacc.c:1652  */
    break;

  case 291:
#line 1046 "parser.y" /* yacc.c:1652  */
    {
        assignment_target_nothing();
    }
#line 4067 "parser.c" /* yacc.c:1652  */
    break;

  case 292:
#line 1049 "parser.y" /* yacc.c:1652  */
    {
        assignment_target_bool_value();
    }
#line 4075 "parser.c" /* yacc.c:1652  */
    break;

  case 293:
#line 1055 "parser.y" /* yacc.c:1652  */
    {
        assignment_complex_name();
    }
#line 4083 "parser.c" /* yacc.c:1652  */
    break;

  case 294:
#line 1057 "parser.y" /* yacc.c:1652  */
    {
        assignment_target_finish();
    }
#line 4091 "parser.c" /* yacc.c:1652  */
    break;


#line 4095 "parser.c" /* yacc.c:1652  */
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
#line 1062 "parser.y" /* yacc.c:1918  */


#include <stdio.h>

extern char yytext[];

void yyerror(const char* s)
{
	fflush(stdout);
	fprintf(stdout, "\n%s: line %d: at %d: %s\n\n", get_file_name(), get_line_number(), get_col_number(), s); //yylloc.first_line, s);
    inc_error_count();
}
