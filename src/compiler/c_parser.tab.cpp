/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */

#line 67 "src/compiler/c_parser.tab.cpp" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "c_parser.tab.hpp".  */
#ifndef YY_YY_SRC_COMPILER_C_PARSER_TAB_HPP_INCLUDED
# define YY_YY_SRC_COMPILER_C_PARSER_TAB_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 1 "src/compiler/c_parser.y" /* yacc.c:355  */

  #include "ast.hpp"

  #include <cassert>
  #include <string>
  #include <vector>

  extern const ast_top *g_root; // A way of getting the AST out

  //! This is to fix problems when generating C++
  // We are declaring the functions provided by Flex, so
  // that Bison generated code can call them.
  int yylex(void);
  void yyerror(const char *);

#line 113 "src/compiler/c_parser.tab.cpp" /* yacc.c:355  */

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    Continue_KEY = 258,
    String_KEY = 259,
    Default_KEY = 260,
    Short_KEY = 261,
    Goto_KEY = 262,
    If_KEY = 263,
    Extern_KEY = 264,
    Float_KEY = 265,
    Unsigned_KEY = 266,
    Void_KEY = 267,
    Long_KEY = 268,
    Volatile_KEY = 269,
    While_KEY = 270,
    Const_KEY = 271,
    Char_KEY = 272,
    For_KEY = 273,
    Auto_KEY = 274,
    Do_KEY = 275,
    Sizeof_KEY = 276,
    Union_KEY = 277,
    Double_KEY = 278,
    Int_KEY = 279,
    Typedef_KEY = 280,
    Else_KEY = 281,
    Return_KEY = 282,
    Static_KEY = 283,
    Enum_KEY = 284,
    Case_KEY = 285,
    Register_KEY = 286,
    Restrict_KEY = 287,
    Break_KEY = 288,
    Signed_KEY = 289,
    Switch_KEY = 290,
    Struct_KEY = 291,
    Plus_MATH = 292,
    Subtract_MATH = 293,
    Multiply_MATH = 294,
    Divide_MATH = 295,
    Percentage_MATH = 296,
    Increment_MATH = 297,
    Decrement_MATH = 298,
    And_BIT = 299,
    Or_BIT = 300,
    Xor_BIT = 301,
    Tilde_BIT = 302,
    Not_BIT = 303,
    AndAnd_BIT = 304,
    OrOr_BIT = 305,
    LShift_BIT = 306,
    RShift_BIT = 307,
    Question_BIT = 308,
    Less_COMP = 309,
    Greater_COMP = 310,
    Equal_COMP = 311,
    NEqual_COMP = 312,
    GEqual_COMP = 313,
    LEqual_COMP = 314,
    Open_BRACKET = 315,
    Close_BRACKET = 316,
    OSquare_BRACKET = 317,
    CSquare_BRACKET = 318,
    OCurly_BRACKET = 319,
    CCurly_BRACKET = 320,
    Add_CURRENT = 321,
    Sub_CURRENT = 322,
    Mul_CURRENT = 323,
    Div_CURRENT = 324,
    Mod_CURRENT = 325,
    And_CURRENT = 326,
    Xor_CURRENT = 327,
    Or_CURRENT = 328,
    LShift_CURRENT = 329,
    RShift_CURRENT = 330,
    Equal = 331,
    Ellipses = 332,
    Semicolon = 333,
    PTR_Ref = 334,
    Colon = 335,
    Comma = 336,
    Dot_Ref = 337,
    IDENTIFIER = 338,
    String_literal = 339,
    NUMBER = 340,
    Char_literal = 341
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 19 "src/compiler/c_parser.y" /* yacc.c:355  */

  ast_base* base;
  std::string *string;

  ast_base_expression* p_base_expr;
  ast_expression* p_expr;
  ast_compound_statement* p_compound_statement;
  ast_declaration* p_declaration;
  ast_loops* p_loop_statement;
  ast_declarator* p_declarator;

  ast_function_parameters* p_function_params;
  ast_if_else_statement* p_if_else_statement;
  ast_return_statement* p_ast_return_statement;
  ast_base_statement* p_ast_base_statement;
  ast_function* p_functions;
  ast_type* type_ast;
  ast_number* number_ast;
  ast_identifier* identifier_ast;
  ast_string* str_ast;
  ast_char* char_ast;
  ast_binary_operators* p_comparison;
  ast_math_operators* p_maths;
  ast_expression_statement* p_expr_stat;
  ast_statement_list* p_stat_list;
  ast_function_call* p_func_call;
  ast_initialisers_declarator* p_init_dec;

  std::vector<ast_function_parameters*>* func_list;
  std::vector<ast_base_expression*>* arg_list;
  std::vector<ast_base_statement*>* statment_vector;
  std::vector<ast_declaration*>* dec_list;
  std::vector<ast_initialisers_declarator*>* init_dec_list;


  ast_top* top_ast;


#line 251 "src/compiler/c_parser.tab.cpp" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SRC_COMPILER_C_PARSER_TAB_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 268 "src/compiler/c_parser.tab.cpp" /* yacc.c:358  */

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
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
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
#  define YYSIZE_T unsigned int
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

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
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
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  31
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1141

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  87
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  48
/* YYNRULES -- Number of rules.  */
#define YYNRULES  176
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  314

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   341

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    90,    90,    93,    94,    95,    96,    97,    98,   101,
     102,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   121,   122,   125,   126,   129,   130,
     131,   132,   137,   138,   139,   140,   143,   144,   145,   146,
     147,   148,   152,   153,   157,   158,   159,   160,   163,   164,
     167,   168,   171,   172,   175,   176,   177,   180,   181,   182,
     185,   186,   187,   188,   191,   192,   195,   196,   197,   198,
     199,   202,   203,   204,   207,   208,   211,   212,   215,   216,
     219,   220,   223,   224,   227,   228,   229,   230,   231,   232,
     235,   236,   237,   238,   239,   240,   241,   245,   246,   247,
     249,   250,   251,   254,   255,   258,   259,   260,   263,   264,
     265,   266,   267,   268,   269,   274,   275,   278,   279,   282,
     284,   288,   289,   290,   291,   292,   293,   294,   295,   298,
     301,   302,   303,   304,   308,   309,   310,   314,   315,   316,
     317,   322,   323,   324,   325,   329,   330,   334,   335,   339,
     340,   343,   344,   345,   346,   347,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   367,
     368,   369,   370,   371,   372,   375,   376
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "Continue_KEY", "String_KEY",
  "Default_KEY", "Short_KEY", "Goto_KEY", "If_KEY", "Extern_KEY",
  "Float_KEY", "Unsigned_KEY", "Void_KEY", "Long_KEY", "Volatile_KEY",
  "While_KEY", "Const_KEY", "Char_KEY", "For_KEY", "Auto_KEY", "Do_KEY",
  "Sizeof_KEY", "Union_KEY", "Double_KEY", "Int_KEY", "Typedef_KEY",
  "Else_KEY", "Return_KEY", "Static_KEY", "Enum_KEY", "Case_KEY",
  "Register_KEY", "Restrict_KEY", "Break_KEY", "Signed_KEY", "Switch_KEY",
  "Struct_KEY", "Plus_MATH", "Subtract_MATH", "Multiply_MATH",
  "Divide_MATH", "Percentage_MATH", "Increment_MATH", "Decrement_MATH",
  "And_BIT", "Or_BIT", "Xor_BIT", "Tilde_BIT", "Not_BIT", "AndAnd_BIT",
  "OrOr_BIT", "LShift_BIT", "RShift_BIT", "Question_BIT", "Less_COMP",
  "Greater_COMP", "Equal_COMP", "NEqual_COMP", "GEqual_COMP",
  "LEqual_COMP", "Open_BRACKET", "Close_BRACKET", "OSquare_BRACKET",
  "CSquare_BRACKET", "OCurly_BRACKET", "CCurly_BRACKET", "Add_CURRENT",
  "Sub_CURRENT", "Mul_CURRENT", "Div_CURRENT", "Mod_CURRENT",
  "And_CURRENT", "Xor_CURRENT", "Or_CURRENT", "LShift_CURRENT",
  "RShift_CURRENT", "Equal", "Ellipses", "Semicolon", "PTR_Ref", "Colon",
  "Comma", "Dot_Ref", "IDENTIFIER", "String_literal", "NUMBER",
  "Char_literal", "$accept", "root", "top_declaration", "expression",
  "assign_expressions", "constant_expression", "argument_expression_list",
  "function_definition", "all_type_specifiers", "direct_declarator",
  "declarator", "pointer", "declaration", "initialisers_list",
  "initialisers_declarator", "shift_expression", "additive_expression",
  "multiplicative_expression", "cast_expression", "relational_expression",
  "equality_expression", "and_expression", "exclusive_or_expression",
  "inclusive_or_expression", "logical_and_expression",
  "conditional_logical_or", "primary_expression", "postfix_expression",
  "unary_expression", "type_name", "specifier_qualifier_list",
  "abstract_declarator", "parameter_type_list", "parameter_list",
  "parameter_declaration", "statement", "labeled_statement",
  "case_statement_list", "if_else_statement", "for_while_statement",
  "return_statement", "expression_statement", "compound_statement",
  "statement_list", "storage_specifiers", "type_specifier",
  "unary_operator", "type_qualifier", YY_NULLPTR
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
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341
};
# endif

#define YYPACT_NINF -86

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-86)))

#define YYTABLE_NINF -168

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     603,   -86,   -86,   -86,   -86,   -86,   -86,   -86,   -86,   -86,
     -86,   -86,   -86,   -86,   115,   -86,   -86,   -86,   -86,   -86,
     -86,   -49,    22,   632,   -86,   -24,   -86,  1105,  1105,  1105,
     987,   -86,   -86,   -86,   -86,  1074,   -26,   -86,    35,   -86,
     -59,   -51,   -62,   -86,   -86,   -86,   -86,    10,   -26,    82,
     -28,   -86,   -86,   -86,   130,   -86,   300,    39,   110,  1016,
     756,   770,   -86,   -86,   -26,   255,   -86,   -86,    10,   666,
     -86,   -86,  1045,   -86,    10,   119,   850,   -86,    -8,   -86,
     114,   120,   -86,   -86,   -86,   506,   -86,    60,   -86,   -86,
     -86,    55,    99,   121,   126,   -86,    52,   106,   162,   164,
     163,   165,    -2,   129,   150,   -86,   902,   770,   -86,   -86,
     322,   -86,   135,   136,   155,   157,   158,   423,   675,   902,
     141,   166,   255,   -86,   -86,   -35,    31,   -86,     8,   -86,
     -86,   -86,   192,   -86,   -86,   -86,   -86,   -86,   339,   -86,
     -86,   -86,   -86,   168,   -86,    10,   506,   -86,    -8,   770,
     -86,   -86,   -86,   -86,   -43,   169,   108,   -86,   -86,   690,
     -86,   902,   902,   902,   902,   902,   902,   902,   902,   902,
     902,   902,   902,   902,   902,   902,   902,   902,   902,   770,
     142,   770,   -86,   -86,    17,   770,   770,   770,   770,   770,
     770,   770,   770,   770,   770,   770,   -86,   423,   770,   770,
     770,   209,   -86,    63,   156,   -86,   770,   170,   423,   -86,
     770,   520,   -86,   -86,   -86,   -86,   176,   -86,   902,   947,
     822,   177,   -86,   -37,   121,   121,   126,   126,   -86,   -86,
     -86,    99,    99,    99,    99,    52,    52,   106,   162,   164,
     163,   165,    93,   -86,    27,   -86,   770,   -86,   -86,   -86,
     -86,   -86,   -86,   -86,   -86,   -86,   -86,   -86,   -86,   -15,
     -12,    71,   181,   -86,   423,   -11,   -86,   -86,   167,   171,
     -86,   -86,   -86,   116,   183,   -86,   179,   836,   -86,   902,
     -86,   -86,   423,   423,   770,   770,   -86,   423,   423,   423,
     -86,   -86,   -86,   -86,   182,   -86,   220,   -86,    79,     4,
     -86,   -86,   -86,   -86,   423,   741,   172,   -86,   423,    11,
     -86,   -86,   423,   -86
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,   168,   158,   152,   161,   164,   156,   160,   176,   175,
     157,   154,   162,   159,   151,   153,   166,   155,   163,   165,
       7,     0,     0,     2,     8,     0,     6,     0,    33,     0,
       0,     1,     5,     4,     3,    44,     0,    48,    41,    43,
      52,     0,     0,    50,    32,    34,    35,     0,   120,     0,
     115,   118,   167,    46,    45,   105,   107,    41,     0,     0,
       0,     0,    42,    49,     0,     0,    31,   119,     0,     0,
      47,   106,     0,    36,    40,     0,     0,   171,   172,   170,
       0,     0,   169,   173,   174,     0,    38,    87,    89,    84,
      85,     0,    66,    54,    57,    60,    71,    74,    76,    78,
      80,    82,    24,    90,    97,    64,     0,     0,    53,    11,
      64,    51,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   147,   145,    87,     0,     9,     0,   126,
     149,   127,   128,   123,   124,   125,   121,   122,     0,    30,
     116,   117,    40,     0,    29,    39,     0,   101,     0,     0,
      87,    86,    98,    99,     0,     0,   103,    95,    96,     0,
      37,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   100,    26,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   144,     0,     0,     0,
       0,     0,   141,     0,     0,   143,     0,     9,     0,   146,
       0,     0,   148,   150,    39,    28,     0,    88,     0,     0,
       0,   104,    92,     0,    55,    56,    58,    59,    61,    62,
      63,    67,    68,    70,    69,    72,    73,    75,    77,    79,
      81,    83,     0,    94,     0,    23,     0,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    12,   133,     0,
       0,     0,     0,   142,     0,     0,   129,    10,     0,     0,
     102,    65,   113,     0,     0,   109,     0,     0,    93,     0,
      91,    27,     0,     0,     0,     0,   132,     0,     0,     0,
     108,   114,   110,   111,     0,    25,   134,   139,     0,     0,
     136,   131,   130,   112,     0,     0,     0,   135,     0,     0,
     140,   137,     0,   138
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -86,   -86,   -86,   -85,    -3,   -56,    89,   229,    12,   213,
      57,    25,    20,   -86,   191,   -23,    33,    38,   -78,    32,
      88,    81,   101,   104,   109,   -86,   -75,   -86,   -39,   149,
     -25,    77,   -58,   -86,   231,   -55,   -86,   -86,   -86,   -86,
     -86,   -86,   -45,   -86,   -86,   -30,   -86,   -29
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    22,    23,   126,   127,   109,   184,    24,   128,    39,
      40,    41,   129,    42,    43,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   110,   155,
     156,   221,    49,    50,    51,   130,   131,   132,   133,   134,
     135,   136,   137,   138,    27,    28,   106,    29
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     154,    75,    66,   151,    91,    55,    56,   157,   158,    36,
      54,    30,    25,    35,   143,    35,    63,    61,   217,    64,
      26,   105,    31,   139,   278,   159,    55,    56,   182,   144,
     148,    71,    57,   203,    36,    25,    36,   147,   210,    44,
      45,    46,    48,    34,   246,   208,   282,    35,   178,   283,
     287,   179,   149,    69,    37,    55,    56,    57,   108,    38,
      53,   154,   201,   204,   154,   306,   210,   105,    36,   210,
     210,    48,   312,   151,    65,   150,    88,    89,    90,    70,
     105,    48,   245,   213,    48,   210,    37,   228,   229,   230,
     280,    57,   210,    58,   242,    59,   244,    60,   246,    72,
     215,    60,   157,   158,   183,    67,   168,   169,   210,   209,
     170,   171,   210,   259,   260,   261,    55,    56,   160,   207,
     159,   265,   105,   105,   105,   105,   105,   105,   105,   105,
     105,   105,   105,   105,   105,   105,   105,   105,   105,   105,
     271,   263,   258,    68,   210,   231,   232,   233,   234,   284,
     161,   162,   210,   266,  -167,   269,   183,   305,   163,   164,
     210,   274,   172,   173,   276,   165,   166,   167,   219,    35,
     220,    73,   105,   279,   210,  -167,  -167,   290,   277,   105,
     145,   105,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,  -167,   224,   225,  -167,   152,  -167,   298,
     299,   226,   227,   153,   235,   236,   174,   267,   176,   286,
     175,   180,   181,   196,   177,   198,   197,   199,   200,   205,
     309,   294,   211,   295,   262,   243,   206,   296,   297,   214,
     218,    48,   300,   301,   302,   -26,   264,   270,   105,   277,
     105,   285,   292,   281,   291,   303,   304,   288,   223,   307,
     310,   289,    33,   311,    62,   111,   238,   313,   112,     1,
     113,     2,   237,   114,     3,     4,     5,     6,     7,     8,
     115,     9,    10,   116,    11,   117,    76,   239,    12,    13,
      14,   240,   118,    15,    16,   119,    17,   241,   120,    18,
     121,    19,    77,    78,    79,   216,   273,    80,    81,    82,
     141,     0,    83,    84,     1,     0,     2,     0,     0,     0,
       4,     5,     6,     7,     8,    85,     9,    10,     0,   122,
     123,     0,     0,    12,    13,    52,     0,     0,     0,    16,
       0,     0,     0,   124,    18,     0,    19,     0,   125,    88,
      89,    90,   112,     1,   113,     2,     0,   114,     3,     4,
       5,     6,     7,     8,   115,     9,    10,   116,    11,   117,
      76,     0,    12,    13,    14,     0,   118,    15,    16,   119,
      17,     0,   120,    18,   121,    19,    77,    78,    79,     0,
       0,    80,    81,    82,     0,     0,    83,    84,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,    85,
       0,     0,     0,   122,   212,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   124,     0,     0,
       0,     0,   125,    88,    89,    90,   112,     1,   113,     2,
       0,   114,     3,     4,     5,     6,     7,     8,   115,     9,
      10,   116,    11,   117,    76,     0,    12,    13,    14,     0,
     118,    15,    16,   119,    17,     0,   120,    18,   121,    19,
      77,    78,    79,     0,     0,    80,    81,    82,     0,     0,
      83,    84,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    85,     0,     0,     0,   122,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   124,     0,     0,     0,     0,   125,    88,    89,    90,
       1,     0,     2,     0,     0,     0,     4,     5,     6,     7,
       8,     0,     9,    10,     0,   268,     0,    76,     0,    12,
      13,    52,     0,     0,     0,    16,     0,     0,     0,     0,
      18,    76,    19,    77,    78,    79,     0,     0,    80,    81,
      82,     0,     0,    83,    84,     0,     0,    77,    78,    79,
       0,     0,    80,    81,    82,     0,    85,    83,    84,     0,
     107,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      85,     0,     0,     0,     0,     0,     0,     0,     0,    87,
      88,    89,    90,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    87,    88,    89,    90,     1,     0,     2,
       0,     0,     3,     4,     5,     6,     7,     8,     0,     9,
      10,     0,    11,     0,     0,     0,    12,    13,    14,     0,
       0,    15,    16,     0,    17,     0,     1,    18,     2,    19,
       0,     3,     4,     5,     6,     7,     8,     0,     9,    10,
       0,    11,     0,     0,     0,    12,    13,    14,     0,     0,
      15,    16,     0,    17,     0,     0,    18,     0,    19,     0,
       1,     0,     2,     0,     0,     3,     4,     5,     6,     7,
       8,    20,     9,    10,     0,    11,    21,     0,     0,    12,
      13,    14,     0,     0,    15,    16,    76,    17,     0,     0,
      18,     0,    19,     0,     0,     0,     0,     0,     0,     0,
      32,    76,    77,    78,    79,    21,     0,    80,    81,    82,
       0,     0,    83,    84,     0,     0,     0,    77,    78,    79,
       0,     0,    80,    81,    82,    85,     0,    83,    84,   107,
       0,     0,     0,   140,     0,     0,     0,     0,     0,     0,
      85,   222,     0,   202,   107,     0,     0,     0,    87,    88,
      89,    90,    76,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    87,    88,    89,    90,    76,    77,    78,
      79,     0,     0,    80,    81,    82,     0,     0,    83,    84,
       0,    76,     0,    77,    78,    79,     0,     0,    80,    81,
      82,    85,   308,    83,    84,   107,     0,    77,    78,    79,
       0,     0,    80,    81,    82,     0,    85,    83,    84,    86,
       0,     0,     0,     0,    87,    88,    89,    90,     0,     0,
      85,     0,     0,     0,   107,     0,     0,     0,     0,    87,
      88,    89,    90,    76,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    87,    88,    89,    90,    76,     0,    77,
      78,    79,     0,     0,    80,    81,    82,     0,     0,    83,
      84,    76,     0,    77,    78,    79,     0,     0,    80,    81,
      82,     0,    85,    83,    84,   275,     0,    77,    78,    79,
       0,     0,    80,    81,    82,     0,    85,    83,    84,   293,
       0,     0,     0,     0,     0,    87,    88,    89,    90,     0,
     146,     0,     0,     0,     0,     0,     0,     0,     0,    87,
      88,    89,    90,    76,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    87,    88,    89,    90,     0,     0,    77,
      78,    79,     0,     0,    80,    81,    82,     0,     0,    83,
      84,     1,     0,     2,     0,     0,     3,     4,     5,     6,
       7,     8,    85,     9,    10,     0,    11,     0,     0,     0,
      12,    13,    14,     0,     0,    15,    16,     0,    17,     0,
       0,    18,     0,    19,     0,    87,    88,    89,    90,     0,
       0,     1,     0,     2,     0,     0,     3,     4,     5,     6,
       7,     8,     0,     9,    10,     0,    11,   219,   272,   220,
      12,    13,    14,     0,     0,    15,    16,     0,    17,     0,
       1,    18,     2,    19,     0,     3,     4,     5,     6,     7,
       8,     0,     9,    10,     0,    11,     0,     0,     0,    12,
      13,    14,     0,     0,    15,    16,     0,    17,    47,     1,
      18,     2,    19,     0,     3,     4,     5,     6,     7,     8,
       0,     9,    10,     0,    11,     0,     0,     0,    12,    13,
      14,     0,     0,    15,    16,     0,    17,    74,     1,    18,
       2,    19,     0,     0,     4,     5,     6,     7,     8,     0,
       9,    10,     0,     0,     0,     0,     0,    12,    13,    52,
       0,     0,     0,    16,     0,     0,   142,     0,    18,     1,
      19,     2,     0,    35,     3,     4,     5,     6,     7,     8,
       0,     9,    10,     0,    11,     0,     0,     0,    12,    13,
      14,     0,     0,    15,    16,     0,    17,     0,     0,    18,
       0,    19
};

static const yytype_int16 yycheck[] =
{
      85,    59,    47,    78,    60,    35,    35,    42,    43,    60,
      35,    60,     0,    39,    72,    39,    78,    76,    61,    81,
       0,    60,     0,    68,    61,    60,    56,    56,   106,    74,
      38,    56,    83,   118,    60,    23,    60,    76,    81,    27,
      28,    29,    30,    23,    81,    80,    61,    39,    50,    61,
      61,    53,    60,    81,    78,    85,    85,    83,    61,    83,
      35,   146,   117,   119,   149,    61,    81,   106,    60,    81,
      81,    59,    61,   148,    64,    83,    84,    85,    86,    54,
     119,    69,    65,   138,    72,    81,    78,   165,   166,   167,
      63,    83,    81,    36,   179,    60,   181,    62,    81,    60,
     145,    62,    42,    43,   107,    48,    54,    55,    81,    78,
      58,    59,    81,   198,   199,   200,   146,   146,    63,   122,
      60,   206,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     218,    78,   197,    61,    81,   168,   169,   170,   171,    78,
      51,    52,    81,   208,    39,   211,   159,    78,    37,    38,
      81,   219,    56,    57,   220,    39,    40,    41,    60,    39,
      62,    61,   211,    80,    81,    60,    61,    61,    62,   218,
      61,   220,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,    78,   161,   162,    81,    83,    83,   284,
     285,   163,   164,    83,   172,   173,    44,   210,    45,   264,
      46,    82,    62,    78,    49,    60,    80,    60,    60,    78,
     305,   277,    30,   279,    15,    83,    60,   282,   283,    61,
      61,   219,   287,   288,   289,    65,    80,    61,   277,    62,
     279,    60,    63,   246,    61,    63,    26,    80,   159,   304,
      78,    80,    23,   308,    41,    64,   175,   312,     3,     4,
       5,     6,   174,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,   176,    23,    24,
      25,   177,    27,    28,    29,    30,    31,   178,    33,    34,
      35,    36,    37,    38,    39,   146,   219,    42,    43,    44,
      69,    -1,    47,    48,     4,    -1,     6,    -1,    -1,    -1,
      10,    11,    12,    13,    14,    60,    16,    17,    -1,    64,
      65,    -1,    -1,    23,    24,    25,    -1,    -1,    -1,    29,
      -1,    -1,    -1,    78,    34,    -1,    36,    -1,    83,    84,
      85,    86,     3,     4,     5,     6,    -1,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    -1,    23,    24,    25,    -1,    27,    28,    29,    30,
      31,    -1,    33,    34,    35,    36,    37,    38,    39,    -1,
      -1,    42,    43,    44,    -1,    -1,    47,    48,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    60,
      -1,    -1,    -1,    64,    65,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,    -1,    -1,
      -1,    -1,    83,    84,    85,    86,     3,     4,     5,     6,
      -1,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    -1,    23,    24,    25,    -1,
      27,    28,    29,    30,    31,    -1,    33,    34,    35,    36,
      37,    38,    39,    -1,    -1,    42,    43,    44,    -1,    -1,
      47,    48,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    60,    -1,    -1,    -1,    64,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    78,    -1,    -1,    -1,    -1,    83,    84,    85,    86,
       4,    -1,     6,    -1,    -1,    -1,    10,    11,    12,    13,
      14,    -1,    16,    17,    -1,     5,    -1,    21,    -1,    23,
      24,    25,    -1,    -1,    -1,    29,    -1,    -1,    -1,    -1,
      34,    21,    36,    37,    38,    39,    -1,    -1,    42,    43,
      44,    -1,    -1,    47,    48,    -1,    -1,    37,    38,    39,
      -1,    -1,    42,    43,    44,    -1,    60,    47,    48,    -1,
      64,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      60,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    83,
      84,    85,    86,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    83,    84,    85,    86,     4,    -1,     6,
      -1,    -1,     9,    10,    11,    12,    13,    14,    -1,    16,
      17,    -1,    19,    -1,    -1,    -1,    23,    24,    25,    -1,
      -1,    28,    29,    -1,    31,    -1,     4,    34,     6,    36,
      -1,     9,    10,    11,    12,    13,    14,    -1,    16,    17,
      -1,    19,    -1,    -1,    -1,    23,    24,    25,    -1,    -1,
      28,    29,    -1,    31,    -1,    -1,    34,    -1,    36,    -1,
       4,    -1,     6,    -1,    -1,     9,    10,    11,    12,    13,
      14,    78,    16,    17,    -1,    19,    83,    -1,    -1,    23,
      24,    25,    -1,    -1,    28,    29,    21,    31,    -1,    -1,
      34,    -1,    36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      78,    21,    37,    38,    39,    83,    -1,    42,    43,    44,
      -1,    -1,    47,    48,    -1,    -1,    -1,    37,    38,    39,
      -1,    -1,    42,    43,    44,    60,    -1,    47,    48,    64,
      -1,    -1,    -1,    77,    -1,    -1,    -1,    -1,    -1,    -1,
      60,    61,    -1,    78,    64,    -1,    -1,    -1,    83,    84,
      85,    86,    21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    83,    84,    85,    86,    21,    37,    38,
      39,    -1,    -1,    42,    43,    44,    -1,    -1,    47,    48,
      -1,    21,    -1,    37,    38,    39,    -1,    -1,    42,    43,
      44,    60,    61,    47,    48,    64,    -1,    37,    38,    39,
      -1,    -1,    42,    43,    44,    -1,    60,    47,    48,    63,
      -1,    -1,    -1,    -1,    83,    84,    85,    86,    -1,    -1,
      60,    -1,    -1,    -1,    64,    -1,    -1,    -1,    -1,    83,
      84,    85,    86,    21,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    83,    84,    85,    86,    21,    -1,    37,
      38,    39,    -1,    -1,    42,    43,    44,    -1,    -1,    47,
      48,    21,    -1,    37,    38,    39,    -1,    -1,    42,    43,
      44,    -1,    60,    47,    48,    63,    -1,    37,    38,    39,
      -1,    -1,    42,    43,    44,    -1,    60,    47,    48,    63,
      -1,    -1,    -1,    -1,    -1,    83,    84,    85,    86,    -1,
      60,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    83,
      84,    85,    86,    21,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    83,    84,    85,    86,    -1,    -1,    37,
      38,    39,    -1,    -1,    42,    43,    44,    -1,    -1,    47,
      48,     4,    -1,     6,    -1,    -1,     9,    10,    11,    12,
      13,    14,    60,    16,    17,    -1,    19,    -1,    -1,    -1,
      23,    24,    25,    -1,    -1,    28,    29,    -1,    31,    -1,
      -1,    34,    -1,    36,    -1,    83,    84,    85,    86,    -1,
      -1,     4,    -1,     6,    -1,    -1,     9,    10,    11,    12,
      13,    14,    -1,    16,    17,    -1,    19,    60,    61,    62,
      23,    24,    25,    -1,    -1,    28,    29,    -1,    31,    -1,
       4,    34,     6,    36,    -1,     9,    10,    11,    12,    13,
      14,    -1,    16,    17,    -1,    19,    -1,    -1,    -1,    23,
      24,    25,    -1,    -1,    28,    29,    -1,    31,    61,     4,
      34,     6,    36,    -1,     9,    10,    11,    12,    13,    14,
      -1,    16,    17,    -1,    19,    -1,    -1,    -1,    23,    24,
      25,    -1,    -1,    28,    29,    -1,    31,    61,     4,    34,
       6,    36,    -1,    -1,    10,    11,    12,    13,    14,    -1,
      16,    17,    -1,    -1,    -1,    -1,    -1,    23,    24,    25,
      -1,    -1,    -1,    29,    -1,    -1,    61,    -1,    34,     4,
      36,     6,    -1,    39,     9,    10,    11,    12,    13,    14,
      -1,    16,    17,    -1,    19,    -1,    -1,    -1,    23,    24,
      25,    -1,    -1,    28,    29,    -1,    31,    -1,    -1,    34,
      -1,    36
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,     6,     9,    10,    11,    12,    13,    14,    16,
      17,    19,    23,    24,    25,    28,    29,    31,    34,    36,
      78,    83,    88,    89,    94,    95,    99,   131,   132,   134,
      60,     0,    78,    94,    99,    39,    60,    78,    83,    96,
      97,    98,   100,   101,    95,    95,    95,    61,    95,   119,
     120,   121,    25,    98,   117,   132,   134,    83,    97,    60,
      62,    76,    96,    78,    81,    64,   129,    97,    61,    81,
      98,   117,    60,    61,    61,   119,    21,    37,    38,    39,
      42,    43,    44,    47,    48,    60,    63,    83,    84,    85,
      86,    92,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   133,    64,    91,    92,
     115,   101,     3,     5,     8,    15,    18,    20,    27,    30,
      33,    35,    64,    65,    78,    83,    90,    91,    95,    99,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   129,
      77,   121,    61,   119,   129,    61,    60,   115,    38,    60,
      83,   113,    83,    83,    90,   116,   117,    42,    43,    60,
      63,    51,    52,    37,    38,    39,    40,    41,    54,    55,
      58,    59,    56,    57,    44,    46,    45,    49,    50,    53,
      82,    62,   105,    91,    93,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    78,    80,    60,    60,
      60,   122,    78,    90,    92,    78,    60,    91,    80,    78,
      81,    30,    65,   122,    61,   129,   116,    61,    61,    60,
      62,   118,    61,    93,   103,   103,   104,   104,   105,   105,
     105,   102,   102,   102,   102,   106,   106,   107,   108,   109,
     110,   111,    90,    83,    90,    65,    81,    91,    91,    91,
      91,    91,    91,    91,    91,    91,    91,    91,   122,    90,
      90,    90,    15,    78,    80,    90,   122,    91,     5,    92,
      61,   105,    61,   118,   119,    63,    92,    62,    61,    80,
      63,    91,    61,    61,    78,    60,   122,    61,    80,    80,
      61,    61,    63,    63,    92,    92,   122,   122,    90,    90,
     122,   122,   122,    63,    26,    78,    61,   122,    61,    90,
      78,   122,    61,   122
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    87,    88,    89,    89,    89,    89,    89,    89,    90,
      90,    91,    91,    91,    91,    91,    91,    91,    91,    91,
      91,    91,    91,    91,    92,    92,    93,    93,    94,    94,
      94,    94,    95,    95,    95,    95,    96,    96,    96,    96,
      96,    96,    97,    97,    98,    98,    98,    98,    99,    99,
     100,   100,   101,   101,   102,   102,   102,   103,   103,   103,
     104,   104,   104,   104,   105,   105,   106,   106,   106,   106,
     106,   107,   107,   107,   108,   108,   109,   109,   110,   110,
     111,   111,   112,   112,   113,   113,   113,   113,   113,   113,
     114,   114,   114,   114,   114,   114,   114,   115,   115,   115,
     115,   115,   115,   116,   116,   117,   117,   117,   118,   118,
     118,   118,   118,   118,   118,   119,   119,   120,   120,   121,
     121,   122,   122,   122,   122,   122,   122,   122,   122,   123,
     124,   124,   124,   124,   125,   125,   125,   126,   126,   126,
     126,   127,   127,   127,   127,   128,   128,   129,   129,   130,
     130,   131,   131,   131,   131,   131,   132,   132,   132,   132,
     132,   132,   132,   132,   132,   132,   132,   132,   132,   133,
     133,   133,   133,   133,   133,   134,   134
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     2,     2,     1,     1,     1,     1,
       3,     1,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     1,     5,     1,     3,     6,     5,
       5,     4,     2,     1,     2,     2,     3,     4,     3,     4,
       3,     1,     2,     1,     1,     2,     2,     3,     2,     3,
       1,     3,     1,     3,     1,     3,     3,     1,     3,     3,
       1,     3,     3,     3,     1,     4,     1,     3,     3,     3,
       3,     1,     3,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     1,     2,     1,     3,     1,
       1,     4,     3,     4,     3,     2,     2,     1,     2,     2,
       2,     2,     4,     1,     2,     1,     2,     1,     3,     2,
       3,     3,     4,     2,     3,     1,     3,     3,     1,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       5,     5,     4,     3,     5,     7,     5,     8,     9,     5,
       7,     2,     3,     2,     2,     1,     2,     2,     3,     1,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
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
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
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
            /* Fall through.  */
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

  return yystpcpy (yyres, yystr) - yyres;
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
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
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
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
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

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
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
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

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
| yyreduce -- Do a reduction.  |
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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 90 "src/compiler/c_parser.y" /* yacc.c:1646  */
    {g_root = (yyvsp[0].top_ast);                       }
#line 1762 "src/compiler/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 93 "src/compiler/c_parser.y" /* yacc.c:1646  */
    {(yyval.top_ast)->add_new(new ast_global_declaration((yyvsp[0].p_declaration)));               }
#line 1768 "src/compiler/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 94 "src/compiler/c_parser.y" /* yacc.c:1646  */
    {(yyval.top_ast)->add_new((yyvsp[0].p_functions));               }
#line 1774 "src/compiler/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 96 "src/compiler/c_parser.y" /* yacc.c:1646  */
    {(yyval.top_ast) = new ast_top(); (yyval.top_ast)->add_new(new ast_global_declaration((yyvsp[0].p_declaration)));               }
#line 1780 "src/compiler/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 97 "src/compiler/c_parser.y" /* yacc.c:1646  */
    {(yyval.top_ast) = new ast_top();                }
#line 1786 "src/compiler/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 98 "src/compiler/c_parser.y" /* yacc.c:1646  */
    {(yyval.top_ast) = new ast_top(); (yyval.top_ast)->add_new((yyvsp[0].p_functions));               }
#line 1792 "src/compiler/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 101 "src/compiler/c_parser.y" /* yacc.c:1646  */
    { (yyval.p_expr) = new ast_expression(); (yyval.p_expr)->add_new(((yyvsp[0].p_base_expr)));                  }
#line 1798 "src/compiler/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 102 "src/compiler/c_parser.y" /* yacc.c:1646  */
    { (yyval.p_expr)->add_new(((yyvsp[0].p_base_expr)));                                             }
#line 1804 "src/compiler/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 105 "src/compiler/c_parser.y" /* yacc.c:1646  */
    { (yyval.p_base_expr) = (yyvsp[0].p_base_expr); }
#line 1810 "src/compiler/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 106 "src/compiler/c_parser.y" /* yacc.c:1646  */
    { (yyval.p_base_expr) = new ast_assign_equal((yyvsp[-2].p_base_expr), (yyvsp[0].p_base_expr)); }
#line 1816 "src/compiler/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 107 "src/compiler/c_parser.y" /* yacc.c:1646  */
    { (yyval.p_base_expr) = new ast_assign_equal((yyvsp[-2].p_base_expr), new ast_add_operator((yyvsp[-2].p_base_expr), (yyvsp[0].p_base_expr))); }
#line 1822 "src/compiler/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 108 "src/compiler/c_parser.y" /* yacc.c:1646  */
    { (yyval.p_base_expr) = new ast_assign_equal((yyvsp[-2].p_base_expr), new ast_subtract_operator((yyvsp[-2].p_base_expr), (yyvsp[0].p_base_expr)));}
#line 1828 "src/compiler/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 109 "src/compiler/c_parser.y" /* yacc.c:1646  */
    { (yyval.p_base_expr) = new ast_assign_equal((yyvsp[-2].p_base_expr), new ast_multiply_operator((yyvsp[-2].p_base_expr), (yyvsp[0].p_base_expr)));}
#line 1834 "src/compiler/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 110 "src/compiler/c_parser.y" /* yacc.c:1646  */
    { (yyval.p_base_expr) = new ast_assign_equal((yyvsp[-2].p_base_expr), new ast_divide_operator((yyvsp[-2].p_base_expr), (yyvsp[0].p_base_expr)));}
#line 1840 "src/compiler/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 111 "src/compiler/c_parser.y" /* yacc.c:1646  */
    { (yyval.p_base_expr) = new ast_assign_equal((yyvsp[-2].p_base_expr), new ast_bitwise_modulo_operator((yyvsp[-2].p_base_expr), (yyvsp[0].p_base_expr)));}
#line 1846 "src/compiler/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 112 "src/compiler/c_parser.y" /* yacc.c:1646  */
    { (yyval.p_base_expr) = new ast_assign_equal((yyvsp[-2].p_base_expr), new ast_bitwise_and_operator((yyvsp[-2].p_base_expr), (yyvsp[0].p_base_expr)));}
#line 1852 "src/compiler/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 113 "src/compiler/c_parser.y" /* yacc.c:1646  */
    { (yyval.p_base_expr) = new ast_assign_equal((yyvsp[-2].p_base_expr), new ast_bitwise_xor_operator((yyvsp[-2].p_base_expr), (yyvsp[0].p_base_expr)));}
#line 1858 "src/compiler/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 114 "src/compiler/c_parser.y" /* yacc.c:1646  */
    { (yyval.p_base_expr) = new ast_assign_equal((yyvsp[-2].p_base_expr), new ast_bitwise_or_operator((yyvsp[-2].p_base_expr), (yyvsp[0].p_base_expr)));}
#line 1864 "src/compiler/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 115 "src/compiler/c_parser.y" /* yacc.c:1646  */
    { (yyval.p_base_expr) = new ast_assign_equal((yyvsp[-2].p_base_expr), new ast_left_shift_bit((yyvsp[-2].p_base_expr), (yyvsp[0].p_base_expr)));}
#line 1870 "src/compiler/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 116 "src/compiler/c_parser.y" /* yacc.c:1646  */
    { (yyval.p_base_expr) = new ast_assign_equal((yyvsp[-2].p_base_expr), new ast_right_shift_bit((yyvsp[-2].p_base_expr), (yyvsp[0].p_base_expr)));}
#line 1876 "src/compiler/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 117 "src/compiler/c_parser.y" /* yacc.c:1646  */
    { (yyval.p_base_expr) = new ast_array_initialiser( *(yyvsp[-1].arg_list) ); }
#line 1882 "src/compiler/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 121 "src/compiler/c_parser.y" /* yacc.c:1646  */
    { (yyval.p_base_expr) = (yyvsp[0].p_base_expr); }
#line 1888 "src/compiler/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 122 "src/compiler/c_parser.y" /* yacc.c:1646  */
    { (yyval.p_base_expr) = new ast_constant_expression((yyvsp[-4].p_base_expr), (yyvsp[-2].p_expr), (yyvsp[0].p_base_expr));     }
#line 1894 "src/compiler/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 125 "src/compiler/c_parser.y" /* yacc.c:1646  */
    { (yyval.arg_list) = new std::vector<ast_base_expression*>; (yyval.arg_list)->push_back((yyvsp[0].p_base_expr)); }
#line 1900 "src/compiler/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 126 "src/compiler/c_parser.y" /* yacc.c:1646  */
    { (yyval.arg_list)->push_back((yyvsp[0].p_base_expr));                                 }
#line 1906 "src/compiler/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 129 "src/compiler/c_parser.y" /* yacc.c:1646  */
    { (yyval.p_functions) = new ast_function ((yyvsp[-5].type_ast), (yyvsp[-4].identifier_ast), *(yyvsp[-2].func_list), (yyvsp[0].p_compound_statement));         }
#line 1912 "src/compiler/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 130 "src/compiler/c_parser.y" /* yacc.c:1646  */
    { (yyval.p_functions) = new ast_function ((yyvsp[-4].type_ast), (yyvsp[-3].identifier_ast), (yyvsp[0].p_compound_statement));       }
#line 1918 "src/compiler/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 131 "src/compiler/c_parser.y" /* yacc.c:1646  */
    { (yyval.p_functions) = new ast_function (new ast_type("Int"), (yyvsp[-4].identifier_ast), *(yyvsp[-2].func_list), (yyvsp[0].p_compound_statement));             }
#line 1924 "src/compiler/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 132 "src/compiler/c_parser.y" /* yacc.c:1646  */
    { (yyval.p_functions) = new ast_function (new ast_type("Int"),(yyvsp[-3].identifier_ast) ,(yyvsp[0].p_compound_statement));           }
#line 1930 "src/compiler/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 137 "src/compiler/c_parser.y" /* yacc.c:1646  */
    {;        }
#line 1936 "src/compiler/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 138 "src/compiler/c_parser.y" /* yacc.c:1646  */
    { (yyval.type_ast) = ((yyvsp[0].type_ast));        }
#line 1942 "src/compiler/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 139 "src/compiler/c_parser.y" /* yacc.c:1646  */
    { (yyval.type_ast) = ((yyvsp[-1].type_ast));        }
#line 1948 "src/compiler/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 140 "src/compiler/c_parser.y" /* yacc.c:1646  */
    { ;        }
#line 1954 "src/compiler/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 143 "src/compiler/c_parser.y" /* yacc.c:1646  */
    { (yyval.p_declarator) = (yyvsp[-1].p_declarator); }
#line 1960 "src/compiler/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 144 "src/compiler/c_parser.y" /* yacc.c:1646  */
    { (yyval.p_declarator) = new ast_array_declarator((yyvsp[-3].identifier_ast), (yyvsp[-1].p_base_expr));         }
#line 1966 "src/compiler/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 145 "src/compiler/c_parser.y" /* yacc.c:1646  */
    { (yyval.p_declarator) = new ast_array_declarator((yyvsp[-2].identifier_ast), NULL);       }
#line 1972 "src/compiler/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 146 "src/compiler/c_parser.y" /* yacc.c:1646  */
    { (yyval.p_declarator) = new ast_function_declarator((yyvsp[-3].identifier_ast), *(yyvsp[-1].func_list)); }
#line 1978 "src/compiler/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 147 "src/compiler/c_parser.y" /* yacc.c:1646  */
    { (yyval.p_declarator) = new ast_function_declarator((yyvsp[-2].identifier_ast));      }
#line 1984 "src/compiler/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 148 "src/compiler/c_parser.y" /* yacc.c:1646  */
    { (yyval.p_declarator) = new ast_variable_declarator((yyvsp[0].identifier_ast));      }
#line 1990 "src/compiler/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 152 "src/compiler/c_parser.y" /* yacc.c:1646  */
    { (yyval.p_declarator) = (yyvsp[0].p_declarator); }
#line 1996 "src/compiler/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 153 "src/compiler/c_parser.y" /* yacc.c:1646  */
    { (yyval.p_declarator) = (yyvsp[0].p_declarator); }
#line 2002 "src/compiler/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 157 "src/compiler/c_parser.y" /* yacc.c:1646  */
    { ; }
#line 2008 "src/compiler/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 158 "src/compiler/c_parser.y" /* yacc.c:1646  */
    { ; }
#line 2014 "src/compiler/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 159 "src/compiler/c_parser.y" /* yacc.c:1646  */
    { ; }
#line 2020 "src/compiler/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 160 "src/compiler/c_parser.y" /* yacc.c:1646  */
    { ; }
#line 2026 "src/compiler/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 163 "src/compiler/c_parser.y" /* yacc.c:1646  */
    { (yyval.p_declaration) = new ast_declaration((yyvsp[-1].type_ast));       }
#line 2032 "src/compiler/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 164 "src/compiler/c_parser.y" /* yacc.c:1646  */
    { (yyval.p_declaration) = new ast_declaration((yyvsp[-2].type_ast), *(yyvsp[-1].init_dec_list));   }
#line 2038 "src/compiler/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 167 "src/compiler/c_parser.y" /* yacc.c:1646  */
    { (yyval.init_dec_list) = new std::vector<ast_initialisers_declarator*>; (yyval.init_dec_list)->push_back((yyvsp[0].p_init_dec)); }
#line 2044 "src/compiler/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 168 "src/compiler/c_parser.y" /* yacc.c:1646  */
    { (yyval.init_dec_list)->push_back((yyvsp[0].p_init_dec));                                        }
#line 2050 "src/compiler/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 171 "src/compiler/c_parser.y" /* yacc.c:1646  */
    { (yyval.p_init_dec) = new ast_initialisers_declarator((yyvsp[0].p_declarator), new ast_expression_number(new ast_number(0)));    }
#line 2056 "src/compiler/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 172 "src/compiler/c_parser.y" /* yacc.c:1646  */
    { (yyval.p_init_dec) = new ast_initialisers_declarator((yyvsp[-2].p_declarator), (yyvsp[0].p_base_expr));      }
#line 2062 "src/compiler/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 176 "src/compiler/c_parser.y" /* yacc.c:1646  */
    { (yyval.p_base_expr) = new ast_left_shift_bit((yyvsp[-2].p_base_expr), (yyvsp[0].p_base_expr));               }
#line 2068 "src/compiler/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 177 "src/compiler/c_parser.y" /* yacc.c:1646  */
    { (yyval.p_base_expr) = new ast_right_shift_bit((yyvsp[-2].p_base_expr), (yyvsp[0].p_base_expr));              }
#line 2074 "src/compiler/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 181 "src/compiler/c_parser.y" /* yacc.c:1646  */
    { (yyval.p_base_expr) = new ast_add_operator((yyvsp[-2].p_base_expr), (yyvsp[0].p_base_expr));                    }
#line 2080 "src/compiler/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 182 "src/compiler/c_parser.y" /* yacc.c:1646  */
    { (yyval.p_base_expr) = new ast_subtract_operator((yyvsp[-2].p_base_expr), (yyvsp[0].p_base_expr));               }
#line 2086 "src/compiler/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 186 "src/compiler/c_parser.y" /* yacc.c:1646  */
    { (yyval.p_base_expr) = new ast_multiply_operator((yyvsp[-2].p_base_expr), (yyvsp[0].p_base_expr));               }
#line 2092 "src/compiler/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 187 "src/compiler/c_parser.y" /* yacc.c:1646  */
    { (yyval.p_base_expr) = new ast_divide_operator((yyvsp[-2].p_base_expr), (yyvsp[0].p_base_expr));                  }
#line 2098 "src/compiler/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 188 "src/compiler/c_parser.y" /* yacc.c:1646  */
    { (yyval.p_base_expr) = new ast_bitwise_modulo_operator((yyvsp[-2].p_base_expr), (yyvsp[0].p_base_expr));          }
#line 2104 "src/compiler/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 191 "src/compiler/c_parser.y" /* yacc.c:1646  */
    { (yyval.p_base_expr) = (yyvsp[0].p_base_expr); }
#line 2110 "src/compiler/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 192 "src/compiler/c_parser.y" /* yacc.c:1646  */
    { (yyval.p_base_expr) = (yyvsp[0].p_base_expr); }
#line 2116 "src/compiler/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 196 "src/compiler/c_parser.y" /* yacc.c:1646  */
    { (yyval.p_base_expr) = new ast_less_comp((yyvsp[-2].p_base_expr), (yyvsp[0].p_base_expr));                     }
#line 2122 "src/compiler/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 197 "src/compiler/c_parser.y" /* yacc.c:1646  */
    { (yyval.p_base_expr) = new ast_greater_comp((yyvsp[-2].p_base_expr), (yyvsp[0].p_base_expr));                  }
#line 2128 "src/compiler/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 198 "src/compiler/c_parser.y" /* yacc.c:1646  */
    { (yyval.p_base_expr) = new ast_less_equal_comp((yyvsp[-2].p_base_expr), (yyvsp[0].p_base_expr));               }
#line 2134 "src/compiler/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 199 "src/compiler/c_parser.y" /* yacc.c:1646  */
    { (yyval.p_base_expr) = new ast_greater_equal_comp((yyvsp[-2].p_base_expr), (yyvsp[0].p_base_expr));            }
#line 2140 "src/compiler/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 203 "src/compiler/c_parser.y" /* yacc.c:1646  */
    { (yyval.p_base_expr) = new ast_equal_comp((yyvsp[-2].p_base_expr), (yyvsp[0].p_base_expr));              }
#line 2146 "src/compiler/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 204 "src/compiler/c_parser.y" /* yacc.c:1646  */
    { (yyval.p_base_expr) = new ast_not_equal_comp((yyvsp[-2].p_base_expr), (yyvsp[0].p_base_expr));          }
#line 2152 "src/compiler/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 208 "src/compiler/c_parser.y" /* yacc.c:1646  */
    { (yyval.p_base_expr) = new ast_bitwise_and_operator((yyvsp[-2].p_base_expr), (yyvsp[0].p_base_expr));      }
#line 2158 "src/compiler/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 212 "src/compiler/c_parser.y" /* yacc.c:1646  */
    { (yyval.p_base_expr) = new ast_bitwise_xor_operator((yyvsp[-2].p_base_expr), (yyvsp[0].p_base_expr));      }
#line 2164 "src/compiler/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 216 "src/compiler/c_parser.y" /* yacc.c:1646  */
    { (yyval.p_base_expr) = new ast_bitwise_or_operator((yyvsp[-2].p_base_expr), (yyvsp[0].p_base_expr));       }
#line 2170 "src/compiler/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 220 "src/compiler/c_parser.y" /* yacc.c:1646  */
    { (yyval.p_base_expr) = new ast_and_comp((yyvsp[-2].p_base_expr), (yyvsp[0].p_base_expr));                  }
#line 2176 "src/compiler/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 224 "src/compiler/c_parser.y" /* yacc.c:1646  */
    { (yyval.p_base_expr) = new ast_or_comp((yyvsp[-2].p_base_expr), (yyvsp[0].p_base_expr));                   }
#line 2182 "src/compiler/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 227 "src/compiler/c_parser.y" /* yacc.c:1646  */
    { (yyval.p_base_expr) = new ast_expression_number((yyvsp[0].number_ast));        }
#line 2188 "src/compiler/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 228 "src/compiler/c_parser.y" /* yacc.c:1646  */
    { (yyval.p_base_expr) = new ast_expression_char((yyvsp[0].char_ast));          }
#line 2194 "src/compiler/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 229 "src/compiler/c_parser.y" /* yacc.c:1646  */
    { (yyval.p_base_expr) = new ast_subtract_operator(new ast_expression_number(new ast_number(0)), ((yyvsp[0].p_base_expr)));}
#line 2200 "src/compiler/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 230 "src/compiler/c_parser.y" /* yacc.c:1646  */
    { (yyval.p_base_expr) = new ast_expression_identifier((yyvsp[0].identifier_ast));    }
#line 2206 "src/compiler/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 231 "src/compiler/c_parser.y" /* yacc.c:1646  */
    { (yyval.p_base_expr) = (yyvsp[-1].p_expr);                                   }
#line 2212 "src/compiler/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 232 "src/compiler/c_parser.y" /* yacc.c:1646  */
    { (yyval.p_base_expr) = new ast_expression_string((yyvsp[0].str_ast));        }
#line 2218 "src/compiler/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 235 "src/compiler/c_parser.y" /* yacc.c:1646  */
    { (yyval.p_base_expr) = (yyvsp[0].p_base_expr);  }
#line 2224 "src/compiler/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 236 "src/compiler/c_parser.y" /* yacc.c:1646  */
    { (yyval.p_base_expr) = new ast_expression_array((yyvsp[-3].p_base_expr), (yyvsp[-1].p_expr));   }
#line 2230 "src/compiler/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 237 "src/compiler/c_parser.y" /* yacc.c:1646  */
    { (yyval.p_base_expr) = new ast_function_call((yyvsp[-2].identifier_ast));       }
#line 2236 "src/compiler/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 238 "src/compiler/c_parser.y" /* yacc.c:1646  */
    { (yyval.p_base_expr) = new ast_function_call((yyvsp[-3].identifier_ast), *(yyvsp[-1].arg_list));  }
#line 2242 "src/compiler/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 240 "src/compiler/c_parser.y" /* yacc.c:1646  */
    { (yyval.p_base_expr) = new ast_assign_equal(new ast_expression_identifier((yyvsp[-1].identifier_ast)), new ast_add_operator(new ast_expression_identifier((yyvsp[-1].identifier_ast)), new ast_expression_number( new ast_number(1) ))); }
#line 2248 "src/compiler/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 96:
#line 241 "src/compiler/c_parser.y" /* yacc.c:1646  */
    { (yyval.p_base_expr) = new ast_assign_equal(new ast_expression_identifier((yyvsp[-1].identifier_ast)), new ast_subtract_operator(new ast_expression_identifier((yyvsp[-1].identifier_ast)), new ast_expression_number( new ast_number(1) ))); }
#line 2254 "src/compiler/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 97:
#line 245 "src/compiler/c_parser.y" /* yacc.c:1646  */
    { (yyval.p_base_expr) = (yyvsp[0].p_base_expr); }
#line 2260 "src/compiler/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 98:
#line 246 "src/compiler/c_parser.y" /* yacc.c:1646  */
    { (yyval.p_base_expr) = new ast_assign_equal(new ast_expression_identifier((yyvsp[0].identifier_ast)), new ast_add_operator(new ast_expression_identifier((yyvsp[0].identifier_ast)), new ast_expression_number( new ast_number(1) )));  }
#line 2266 "src/compiler/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 99:
#line 247 "src/compiler/c_parser.y" /* yacc.c:1646  */
    { (yyval.p_base_expr) = new ast_assign_equal(new ast_expression_identifier((yyvsp[0].identifier_ast)), new ast_subtract_operator(new ast_expression_identifier((yyvsp[0].identifier_ast)), new ast_expression_number( new ast_number(1) )));  }
#line 2272 "src/compiler/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 100:
#line 249 "src/compiler/c_parser.y" /* yacc.c:1646  */
    { (yyval.p_base_expr) = (yyvsp[0].p_base_expr);  }
#line 2278 "src/compiler/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 101:
#line 250 "src/compiler/c_parser.y" /* yacc.c:1646  */
    { (yyval.p_base_expr) = new ast_size_of_expr((yyvsp[0].p_base_expr)); }
#line 2284 "src/compiler/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 102:
#line 251 "src/compiler/c_parser.y" /* yacc.c:1646  */
    { (yyval.p_base_expr) = new ast_size_of_expr((yyvsp[-1].type_ast)); }
#line 2290 "src/compiler/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 103:
#line 254 "src/compiler/c_parser.y" /* yacc.c:1646  */
    { (yyval.type_ast) = (yyvsp[0].type_ast);}
#line 2296 "src/compiler/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 104:
#line 255 "src/compiler/c_parser.y" /* yacc.c:1646  */
    { (yyval.type_ast) = (yyvsp[-1].type_ast);}
#line 2302 "src/compiler/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 105:
#line 258 "src/compiler/c_parser.y" /* yacc.c:1646  */
    { (yyval.type_ast) = (yyvsp[0].type_ast); }
#line 2308 "src/compiler/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 106:
#line 259 "src/compiler/c_parser.y" /* yacc.c:1646  */
    { (yyval.type_ast) = (yyvsp[0].type_ast); }
#line 2314 "src/compiler/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 107:
#line 260 "src/compiler/c_parser.y" /* yacc.c:1646  */
    { (yyval.type_ast) = new ast_type("Int");}
#line 2320 "src/compiler/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 108:
#line 263 "src/compiler/c_parser.y" /* yacc.c:1646  */
    { (yyval.base) = (yyvsp[-1].base); }
#line 2326 "src/compiler/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 109:
#line 264 "src/compiler/c_parser.y" /* yacc.c:1646  */
    {;}
#line 2332 "src/compiler/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 110:
#line 265 "src/compiler/c_parser.y" /* yacc.c:1646  */
    { (yyval.base) = (yyvsp[-1].p_base_expr); }
#line 2338 "src/compiler/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 111:
#line 266 "src/compiler/c_parser.y" /* yacc.c:1646  */
    { (yyval.base) = (yyvsp[-2].base); }
#line 2344 "src/compiler/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 112:
#line 267 "src/compiler/c_parser.y" /* yacc.c:1646  */
    { (yyval.base) = (yyvsp[-3].base); }
#line 2350 "src/compiler/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 113:
#line 268 "src/compiler/c_parser.y" /* yacc.c:1646  */
    {;}
#line 2356 "src/compiler/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 114:
#line 269 "src/compiler/c_parser.y" /* yacc.c:1646  */
    {;}
#line 2362 "src/compiler/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 115:
#line 274 "src/compiler/c_parser.y" /* yacc.c:1646  */
    {(yyval.func_list) = (yyvsp[0].func_list); }
#line 2368 "src/compiler/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 116:
#line 275 "src/compiler/c_parser.y" /* yacc.c:1646  */
    {(yyval.func_list) = (yyvsp[-2].func_list); }
#line 2374 "src/compiler/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 117:
#line 278 "src/compiler/c_parser.y" /* yacc.c:1646  */
    {(yyval.func_list)->push_back(((yyvsp[0].p_function_params)));         }
#line 2380 "src/compiler/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 118:
#line 279 "src/compiler/c_parser.y" /* yacc.c:1646  */
    {(yyval.func_list) = new std::vector<ast_function_parameters*>; (yyval.func_list)->push_back(((yyvsp[0].p_function_params)));      }
#line 2386 "src/compiler/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 119:
#line 282 "src/compiler/c_parser.y" /* yacc.c:1646  */
    {(yyval.p_function_params) = new ast_function_parameters((yyvsp[-1].type_ast), (yyvsp[0].p_declarator));  }
#line 2392 "src/compiler/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 120:
#line 284 "src/compiler/c_parser.y" /* yacc.c:1646  */
    {(yyval.p_function_params) = new ast_function_parameters((yyvsp[0].type_ast), NULL);      }
#line 2398 "src/compiler/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 121:
#line 288 "src/compiler/c_parser.y" /* yacc.c:1646  */
    { (yyval.p_ast_base_statement) = (yyvsp[0].p_expr_stat); }
#line 2404 "src/compiler/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 122:
#line 289 "src/compiler/c_parser.y" /* yacc.c:1646  */
    { (yyval.p_ast_base_statement) = (yyvsp[0].p_compound_statement); }
#line 2410 "src/compiler/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 123:
#line 290 "src/compiler/c_parser.y" /* yacc.c:1646  */
    { (yyval.p_ast_base_statement) = (yyvsp[0].p_if_else_statement); }
#line 2416 "src/compiler/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 124:
#line 291 "src/compiler/c_parser.y" /* yacc.c:1646  */
    { (yyval.p_ast_base_statement) = (yyvsp[0].p_loop_statement); }
#line 2422 "src/compiler/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 125:
#line 292 "src/compiler/c_parser.y" /* yacc.c:1646  */
    { (yyval.p_ast_base_statement) = (yyvsp[0].p_ast_base_statement); }
#line 2428 "src/compiler/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 126:
#line 293 "src/compiler/c_parser.y" /* yacc.c:1646  */
    { (yyval.p_ast_base_statement) = (yyvsp[0].p_declaration);  }
#line 2434 "src/compiler/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 127:
#line 294 "src/compiler/c_parser.y" /* yacc.c:1646  */
    { ; }
#line 2440 "src/compiler/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 128:
#line 295 "src/compiler/c_parser.y" /* yacc.c:1646  */
    { ; }
#line 2446 "src/compiler/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 129:
#line 298 "src/compiler/c_parser.y" /* yacc.c:1646  */
    { ;}
#line 2452 "src/compiler/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 130:
#line 301 "src/compiler/c_parser.y" /* yacc.c:1646  */
    { ;}
#line 2458 "src/compiler/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 131:
#line 302 "src/compiler/c_parser.y" /* yacc.c:1646  */
    { ;}
#line 2464 "src/compiler/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 132:
#line 303 "src/compiler/c_parser.y" /* yacc.c:1646  */
    { ;}
#line 2470 "src/compiler/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 133:
#line 304 "src/compiler/c_parser.y" /* yacc.c:1646  */
    { ;}
#line 2476 "src/compiler/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 134:
#line 308 "src/compiler/c_parser.y" /* yacc.c:1646  */
    { (yyval.p_if_else_statement) = new ast_if_else_statement((yyvsp[-2].p_expr)); (yyval.p_if_else_statement)->push_back_if((yyvsp[0].p_ast_base_statement)); (yyval.p_if_else_statement)->push_back_else(NULL); }
#line 2482 "src/compiler/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 135:
#line 309 "src/compiler/c_parser.y" /* yacc.c:1646  */
    { (yyval.p_if_else_statement) = new ast_if_else_statement((yyvsp[-4].p_expr)); (yyval.p_if_else_statement)->push_back_if((yyvsp[-2].p_ast_base_statement)); (yyval.p_if_else_statement)->push_back_else((yyvsp[0].p_ast_base_statement));   }
#line 2488 "src/compiler/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 136:
#line 310 "src/compiler/c_parser.y" /* yacc.c:1646  */
    {;}
#line 2494 "src/compiler/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 137:
#line 314 "src/compiler/c_parser.y" /* yacc.c:1646  */
    { (yyval.p_loop_statement) = new ast_for_statement((yyvsp[-5].p_expr), (yyvsp[-3].p_expr), (yyvsp[0].p_ast_base_statement));             }
#line 2500 "src/compiler/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 138:
#line 315 "src/compiler/c_parser.y" /* yacc.c:1646  */
    { (yyval.p_loop_statement) = new ast_for_statement((yyvsp[-6].p_expr), (yyvsp[-4].p_expr), (yyvsp[-2].p_expr), (yyvsp[0].p_ast_base_statement));  }
#line 2506 "src/compiler/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 139:
#line 316 "src/compiler/c_parser.y" /* yacc.c:1646  */
    { (yyval.p_loop_statement) = new ast_while_statement((yyvsp[-2].p_expr), (yyvsp[0].p_ast_base_statement), false);          }
#line 2512 "src/compiler/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 140:
#line 317 "src/compiler/c_parser.y" /* yacc.c:1646  */
    { (yyval.p_loop_statement) = new ast_while_statement((yyvsp[-2].p_expr), (yyvsp[-5].p_ast_base_statement), true);            }
#line 2518 "src/compiler/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 141:
#line 322 "src/compiler/c_parser.y" /* yacc.c:1646  */
    {(yyval.p_ast_base_statement) = new ast_return_statement(new ast_expression_number( new ast_number(0) ));}
#line 2524 "src/compiler/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 142:
#line 323 "src/compiler/c_parser.y" /* yacc.c:1646  */
    {(yyval.p_ast_base_statement) = new ast_return_statement((yyvsp[-1].p_expr)); }
#line 2530 "src/compiler/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 143:
#line 324 "src/compiler/c_parser.y" /* yacc.c:1646  */
    {(yyval.p_ast_base_statement) = new ast_break_statement();  }
#line 2536 "src/compiler/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 144:
#line 325 "src/compiler/c_parser.y" /* yacc.c:1646  */
    {;}
#line 2542 "src/compiler/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 145:
#line 329 "src/compiler/c_parser.y" /* yacc.c:1646  */
    {(yyval.p_expr_stat) = new ast_expression_statement(NULL);  }
#line 2548 "src/compiler/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 146:
#line 330 "src/compiler/c_parser.y" /* yacc.c:1646  */
    {(yyval.p_expr_stat) = new ast_expression_statement((yyvsp[-1].p_expr));  }
#line 2554 "src/compiler/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 147:
#line 334 "src/compiler/c_parser.y" /* yacc.c:1646  */
    {(yyval.p_compound_statement) = new ast_compound_statement(NULL);                       }
#line 2560 "src/compiler/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 148:
#line 335 "src/compiler/c_parser.y" /* yacc.c:1646  */
    {(yyval.p_compound_statement) = new ast_compound_statement((yyvsp[-1].p_stat_list));                         }
#line 2566 "src/compiler/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 149:
#line 339 "src/compiler/c_parser.y" /* yacc.c:1646  */
    {(yyval.p_stat_list) = new ast_statement_list(); (yyval.p_stat_list)->add_new((yyvsp[0].p_ast_base_statement));              }
#line 2572 "src/compiler/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 150:
#line 340 "src/compiler/c_parser.y" /* yacc.c:1646  */
    {(yyval.p_stat_list)->add_new((yyvsp[0].p_ast_base_statement));                                             }
#line 2578 "src/compiler/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 156:
#line 351 "src/compiler/c_parser.y" /* yacc.c:1646  */
    {  (yyval.type_ast) = new ast_type("Void");    }
#line 2584 "src/compiler/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 157:
#line 352 "src/compiler/c_parser.y" /* yacc.c:1646  */
    {  (yyval.type_ast) = new ast_type("Char");    }
#line 2590 "src/compiler/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 158:
#line 353 "src/compiler/c_parser.y" /* yacc.c:1646  */
    {  (yyval.type_ast) = new ast_type("Short");    }
#line 2596 "src/compiler/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 159:
#line 354 "src/compiler/c_parser.y" /* yacc.c:1646  */
    {  (yyval.type_ast) = new ast_type("Int");    }
#line 2602 "src/compiler/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 160:
#line 355 "src/compiler/c_parser.y" /* yacc.c:1646  */
    {  (yyval.type_ast) = new ast_type("Long");    }
#line 2608 "src/compiler/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 161:
#line 356 "src/compiler/c_parser.y" /* yacc.c:1646  */
    {  (yyval.type_ast) = new ast_type("Float");    }
#line 2614 "src/compiler/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 162:
#line 357 "src/compiler/c_parser.y" /* yacc.c:1646  */
    {  (yyval.type_ast) = new ast_type("Double");    }
#line 2620 "src/compiler/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 163:
#line 358 "src/compiler/c_parser.y" /* yacc.c:1646  */
    {  (yyval.type_ast) = new ast_type("Signed");    }
#line 2626 "src/compiler/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 164:
#line 359 "src/compiler/c_parser.y" /* yacc.c:1646  */
    {  (yyval.type_ast) = new ast_type("Unsigned");    }
#line 2632 "src/compiler/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 165:
#line 360 "src/compiler/c_parser.y" /* yacc.c:1646  */
    {  (yyval.type_ast) = new ast_type("Struct");    }
#line 2638 "src/compiler/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 166:
#line 361 "src/compiler/c_parser.y" /* yacc.c:1646  */
    {  (yyval.type_ast) = new ast_type("Enum");    }
#line 2644 "src/compiler/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 167:
#line 362 "src/compiler/c_parser.y" /* yacc.c:1646  */
    {  (yyval.type_ast) = new ast_type("Typedef");    }
#line 2650 "src/compiler/c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 168:
#line 363 "src/compiler/c_parser.y" /* yacc.c:1646  */
    {  (yyval.type_ast) = new ast_type("String");    }
#line 2656 "src/compiler/c_parser.tab.cpp" /* yacc.c:1646  */
    break;


#line 2660 "src/compiler/c_parser.tab.cpp" /* yacc.c:1646  */
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

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

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
                      yytoken, &yylval);
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
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
#line 379 "src/compiler/c_parser.y" /* yacc.c:1906  */


const ast_top *g_root; // Definition of variable (to match declaration earlier)

const ast_top *parseAST()
{
  g_root=0;
  yyparse();
  return g_root;
}
