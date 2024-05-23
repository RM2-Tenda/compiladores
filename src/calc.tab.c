/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "src/calc.yacc"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <math.h>
#include <ctype.h>
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif
#include "../utils/headers/variables.h"

int yylex();

void yyerror(char *s);

extern int yylineno;

Variable *get_variables();

extern int num_variables;

extern int line_number;

extern int column_number;

extern char *current_line;

extern char *yytext;

void print_error(const char *error_type, const char *error_msg);
int list_similar_variables(const char *line);
void suggest_syntax_corrections(const char *line);
int levenshtein_distance(const char *s1, const char *s2);
int is_valid_identifier(const char *name);


#line 109 "src/calc.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
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

#include "calc.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_FLOAT = 3,                      /* FLOAT  */
  YYSYMBOL_INTEGER = 4,                    /* INTEGER  */
  YYSYMBOL_ID = 5,                         /* ID  */
  YYSYMBOL_PLUS = 6,                       /* PLUS  */
  YYSYMBOL_MINUS = 7,                      /* MINUS  */
  YYSYMBOL_TIMES = 8,                      /* TIMES  */
  YYSYMBOL_DIVIDE = 9,                     /* DIVIDE  */
  YYSYMBOL_MOD = 10,                       /* MOD  */
  YYSYMBOL_POWER = 11,                     /* POWER  */
  YYSYMBOL_AND = 12,                       /* AND  */
  YYSYMBOL_OR = 13,                        /* OR  */
  YYSYMBOL_XOR = 14,                       /* XOR  */
  YYSYMBOL_RSHIFT = 15,                    /* RSHIFT  */
  YYSYMBOL_LSHIFT = 16,                    /* LSHIFT  */
  YYSYMBOL_NOT = 17,                       /* NOT  */
  YYSYMBOL_INC = 18,                       /* INC  */
  YYSYMBOL_DEC = 19,                       /* DEC  */
  YYSYMBOL_ASSIGN = 20,                    /* ASSIGN  */
  YYSYMBOL_LPAREN = 21,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 22,                    /* RPAREN  */
  YYSYMBOL_CLEAR = 23,                     /* CLEAR  */
  YYSYMBOL_LIST = 24,                      /* LIST  */
  YYSYMBOL_SIN = 25,                       /* SIN  */
  YYSYMBOL_COS = 26,                       /* COS  */
  YYSYMBOL_TAN = 27,                       /* TAN  */
  YYSYMBOL_LOG = 28,                       /* LOG  */
  YYSYMBOL_LN = 29,                        /* LN  */
  YYSYMBOL_PI = 30,                        /* PI  */
  YYSYMBOL_UMINUS = 31,                    /* UMINUS  */
  YYSYMBOL_32_n_ = 32,                     /* '\n'  */
  YYSYMBOL_YYACCEPT = 33,                  /* $accept  */
  YYSYMBOL_program = 34,                   /* program  */
  YYSYMBOL_line = 35,                      /* line  */
  YYSYMBOL_expr = 36,                      /* expr  */
  YYSYMBOL_term = 37,                      /* term  */
  YYSYMBOL_factor = 38,                    /* factor  */
  YYSYMBOL_unary = 39                      /* unary  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   248

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  33
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  7
/* YYNRULES -- Number of rules.  */
#define YYNRULES  47
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  95

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   286


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      32,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    74,    74,    76,    80,    81,    90,   109,   121,   133,
     142,   146,   156,   159,   168,   179,   180,   188,   196,   204,
     215,   226,   234,   242,   250,   258,   266,   277,   278,   286,
     297,   311,   312,   313,   322,   323,   327,   328,   329,   339,
     349,   350,   351,   359,   371,   376,   382,   390
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "FLOAT", "INTEGER",
  "ID", "PLUS", "MINUS", "TIMES", "DIVIDE", "MOD", "POWER", "AND", "OR",
  "XOR", "RSHIFT", "LSHIFT", "NOT", "INC", "DEC", "ASSIGN", "LPAREN",
  "RPAREN", "CLEAR", "LIST", "SIN", "COS", "TAN", "LOG", "LN", "PI",
  "UMINUS", "'\\n'", "$accept", "program", "line", "expr", "term",
  "factor", "unary", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-27)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -27,    37,   -27,   -26,   -27,   -27,   -10,     0,     0,     6,
      18,     0,     7,    11,     3,    10,    24,    25,    26,   -27,
     -27,   -27,    92,     5,   -27,   -27,   -27,    16,    17,     0,
     -27,   -27,   -27,   -27,   -27,   -27,   147,    27,   -27,    41,
     -27,     0,     0,     0,    67,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   -27,     0,     0,
       0,   -27,   -27,   103,   -27,   -27,   -27,   164,   181,   198,
      28,   130,   215,     5,     5,   -27,   -27,   -27,   -27,   -27,
     -27,   -27,   -27,   -27,   -27,   -27,   -27,   -27,   -27,   -27,
     -27,   -27,   -27,   -27,   -27
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     1,     0,    32,    31,    33,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    47,
       4,     3,     0,    15,    27,    35,    14,     0,     0,     0,
       9,    33,    36,    37,    38,    39,     0,     0,    10,     0,
      12,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     5,     0,     0,
       0,     7,     8,     0,    34,    11,    13,     0,     0,     0,
       0,     0,     0,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    28,    29,    30,     6,    40,    41,
      42,    44,    45,    43,    46
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -27,   -27,   -27,    -9,   192,    -7,   -27
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     1,    21,    22,    23,    24,    25
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      32,    33,    36,     4,     5,    31,    26,     7,    27,    28,
      29,    34,    37,    58,    59,    60,    39,     8,     9,    10,
      63,    11,    30,    35,    41,    14,    15,    16,    17,    18,
      19,    42,    67,    68,    69,    71,    72,     2,     3,    38,
       4,     5,     6,    40,     7,    43,    44,    45,    61,    62,
      91,    84,    85,    86,     8,     9,    10,     0,    11,    65,
      12,    13,    14,    15,    16,    17,    18,    19,    70,    20,
       4,     5,    31,    66,     7,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     8,     9,    10,     0,    11,     0,
       0,     0,    14,    15,    16,    17,    18,    19,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
       0,     0,     0,     0,    57,     0,     0,     0,     0,     0,
       0,    92,     0,     0,     0,    87,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,     0,     0,     0,
       0,     0,    93,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,     0,     0,     0,     0,     0,    64,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,     0,     0,     0,     0,     0,    88,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,     0,     0,
       0,     0,     0,    89,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,     0,     0,     0,     0,     0,
      90,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,     0,     0,     0,     0,     0,    94,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83
};

static const yytype_int8 yycheck[] =
{
       7,     8,    11,     3,     4,     5,    32,     7,    18,    19,
      20,     5,     5,     8,     9,    10,     5,    17,    18,    19,
      29,    21,    32,     5,    21,    25,    26,    27,    28,    29,
      30,    21,    41,    42,    43,    44,    45,     0,     1,    32,
       3,     4,     5,    32,     7,    21,    21,    21,    32,    32,
      22,    58,    59,    60,    17,    18,    19,    -1,    21,    32,
      23,    24,    25,    26,    27,    28,    29,    30,     1,    32,
       3,     4,     5,    32,     7,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    17,    18,    19,    -1,    21,    -1,
      -1,    -1,    25,    26,    27,    28,    29,    30,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      -1,    -1,    -1,    -1,    32,    -1,    -1,    -1,    -1,    -1,
      -1,     1,    -1,    -1,    -1,    32,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    -1,    -1,    -1,
      -1,    -1,    22,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    -1,    -1,    -1,    -1,    -1,    22,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    -1,    -1,    -1,    -1,    -1,    22,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    -1,    -1,
      -1,    -1,    -1,    22,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    -1,    -1,    -1,    -1,    -1,
      22,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    -1,    -1,    -1,    -1,    -1,    22,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    34,     0,     1,     3,     4,     5,     7,    17,    18,
      19,    21,    23,    24,    25,    26,    27,    28,    29,    30,
      32,    35,    36,    37,    38,    39,    32,    18,    19,    20,
      32,     5,    38,    38,     5,     5,    36,     5,    32,     5,
      32,    21,    21,    21,    21,    21,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    32,     8,     9,
      10,    32,    32,    36,    22,    32,    32,    36,    36,    36,
       1,    36,    36,    37,    37,    37,    37,    37,    37,    37,
      37,    37,    37,    37,    38,    38,    38,    32,    22,    22,
      22,    22,     1,    22,    22
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    33,    34,    34,    35,    35,    35,    35,    35,    35,
      35,    35,    35,    35,    35,    36,    36,    36,    36,    36,
      36,    36,    36,    36,    36,    36,    36,    37,    37,    37,
      37,    38,    38,    38,    38,    38,    39,    39,    39,    39,
      39,    39,    39,    39,    39,    39,    39,    39
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     1,     2,     4,     3,     3,     2,
       2,     3,     2,     3,     2,     1,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     1,     3,     3,
       3,     1,     1,     1,     3,     1,     2,     2,     2,     2,
       4,     4,     4,     4,     4,     4,     4,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF

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


/* YYLOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

# ifndef YYLOCATION_PRINT

#  if defined YY_LOCATION_PRINT

   /* Temporary convenience wrapper in case some people defined the
      undocumented and private YY_LOCATION_PRINT macros.  */
#   define YYLOCATION_PRINT(File, Loc)  YY_LOCATION_PRINT(File, *(Loc))

#  elif defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

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

#   define YYLOCATION_PRINT  yy_location_print_

    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT(File, Loc)  YYLOCATION_PRINT(File, &(Loc))

#  else

#   define YYLOCATION_PRINT(File, Loc) ((void) 0)
    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT  YYLOCATION_PRINT

#  endif
# endif /* !defined YYLOCATION_PRINT */


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (yylocationp);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  YYLOCATION_PRINT (yyo, yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yykind, yyvaluep, yylocationp);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)],
                       &(yylsp[(yyi + 1) - (yynrhs)]));
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YY_USE (yyvaluep);
  YY_USE (yylocationp);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

    /* The location stack: array, bottom, top.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls = yylsa;
    YYLTYPE *yylsp = yyls;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[3];



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

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
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      yyerror_range[1] = yylloc;
      goto yyerrlab1;
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
  case 5: /* line: expr '\n'  */
#line 81 "src/calc.yacc"
                                  {
                                    if (!yyerrstatus) {
                                        if ((yyvsp[-1].expr_val).type == 0) {
                                            printf("%d\n", (int)(yyvsp[-1].expr_val).value);
                                        } else {
                                            printf("%f\n", (yyvsp[-1].expr_val).value);
                                        }
                                    }
                                  }
#line 1339 "src/calc.tab.c"
    break;

  case 6: /* line: ID ASSIGN expr '\n'  */
#line 90 "src/calc.yacc"
                                  {
                                    if (!is_valid_identifier((yyvsp[-3].id))) {
                                        print_error("Invalid Identifier", "Identifier cannot start with a digit or contain special characters");
                                        YYERROR;
                                    } else {
                                        if ((yyvsp[-1].expr_val).type == -1) {
                                            // An error occurred in the expression
                                            YYERROR;
                                        } else {
                                            assign_variable((yyvsp[-3].id), (yyvsp[-1].expr_val).value, (yyvsp[-1].expr_val).type);
                                            if ((yyvsp[-1].expr_val).type == 0) {
                                                printf("%d\n", (int)(yyvsp[-1].expr_val).value);
                                            } else {
                                                printf("%f\n", (yyvsp[-1].expr_val).value);
                                            }
                                        }
                                        free((yyvsp[-3].id));
                                    }
                                }
#line 1363 "src/calc.tab.c"
    break;

  case 7: /* line: ID INC '\n'  */
#line 109 "src/calc.yacc"
                                  {
                                    if (variable_exists((yyvsp[-2].id))) {
                                        increment_variable((yyvsp[-2].id));
                                        if (!yyerrstatus) {
                                            print_variable((yyvsp[-2].id));
                                        }
                                    } else {
                                        print_error("Undefined Variable", "Variable not found");
                                        YYERROR;
                                    }
                                    free((yyvsp[-2].id));
                                  }
#line 1380 "src/calc.tab.c"
    break;

  case 8: /* line: ID DEC '\n'  */
#line 121 "src/calc.yacc"
                                  {
                                    if (variable_exists((yyvsp[-2].id))) {
                                        decrement_variable((yyvsp[-2].id));
                                        if (!yyerrstatus) {
                                            print_variable((yyvsp[-2].id));
                                        }
                                    } else {
                                        print_error("Undefined Variable", "Variable not found");
                                        YYERROR;
                                    }
                                    free((yyvsp[-2].id));
                                  }
#line 1397 "src/calc.tab.c"
    break;

  case 9: /* line: ID '\n'  */
#line 133 "src/calc.yacc"
                                  {
                                    if (variable_exists((yyvsp[-1].id))) {
                                        print_variable((yyvsp[-1].id));
                                    } else {
                                        print_error("Undefined Variable", "Variable not found");
                                        YYERROR;
                                    }
                                    free((yyvsp[-1].id));
                                  }
#line 1411 "src/calc.tab.c"
    break;

  case 10: /* line: CLEAR '\n'  */
#line 142 "src/calc.yacc"
                                  {
                                    clear_all_variables();
                                    printf("All variables cleared\n");
                                  }
#line 1420 "src/calc.tab.c"
    break;

  case 11: /* line: CLEAR ID '\n'  */
#line 146 "src/calc.yacc"
                                  {
                                    if (variable_exists((yyvsp[-1].id))) {
                                        clear_variable((yyvsp[-1].id));
                                        printf("Variable %s cleared\n", (yyvsp[-1].id));
                                    } else {
                                        print_error("Undefined Variable", "Variable not found");
                                        YYERROR;
                                    }
                                    free((yyvsp[-1].id));
                                  }
#line 1435 "src/calc.tab.c"
    break;

  case 12: /* line: LIST '\n'  */
#line 156 "src/calc.yacc"
                                  {
                                    list_all_variables();
                                  }
#line 1443 "src/calc.tab.c"
    break;

  case 13: /* line: LIST ID '\n'  */
#line 159 "src/calc.yacc"
                                  {
                                    if (variable_exists((yyvsp[-1].id))) {
                                        list_variable((yyvsp[-1].id));
                                    } else {
                                        print_error("Undefined Variable", "Variable not found");
                                        YYERROR;
                                    }
                                    free((yyvsp[-1].id));
                                  }
#line 1457 "src/calc.tab.c"
    break;

  case 14: /* line: error '\n'  */
#line 168 "src/calc.yacc"
                                  {
                                    if (current_line != NULL) {
                                        free(current_line);
                                    }
                                    current_line = strdup(yytext);
                                    yyerrok;
                                    yyclearin;
                                  }
#line 1470 "src/calc.tab.c"
    break;

  case 15: /* expr: term  */
#line 179 "src/calc.yacc"
                                  { (yyval.expr_val) = (yyvsp[0].expr_val); }
#line 1476 "src/calc.tab.c"
    break;

  case 16: /* expr: expr PLUS term  */
#line 180 "src/calc.yacc"
                                  {
                                    if ((yyvsp[-2].expr_val).type == -1 || (yyvsp[0].expr_val).type == -1) {
                                        (yyval.expr_val).type = -1;
                                    } else {
                                        (yyval.expr_val).value = (yyvsp[-2].expr_val).value + (yyvsp[0].expr_val).value;
                                        (yyval.expr_val).type = ((yyvsp[-2].expr_val).type || (yyvsp[0].expr_val).type);
                                    }
                                  }
#line 1489 "src/calc.tab.c"
    break;

  case 17: /* expr: expr MINUS term  */
#line 188 "src/calc.yacc"
                                  {
                                    if ((yyvsp[-2].expr_val).type == -1 || (yyvsp[0].expr_val).type == -1) {
                                        (yyval.expr_val).type = -1;
                                    } else {
                                        (yyval.expr_val).value = (yyvsp[-2].expr_val).value - (yyvsp[0].expr_val).value;
                                        (yyval.expr_val).type = ((yyvsp[-2].expr_val).type || (yyvsp[0].expr_val).type);
                                    }
                                  }
#line 1502 "src/calc.tab.c"
    break;

  case 18: /* expr: expr TIMES term  */
#line 196 "src/calc.yacc"
                                  {
                                    if ((yyvsp[-2].expr_val).type == -1 || (yyvsp[0].expr_val).type == -1) {
                                        (yyval.expr_val).type = -1;
                                    } else {
                                        (yyval.expr_val).value = (yyvsp[-2].expr_val).value * (yyvsp[0].expr_val).value;
                                        (yyval.expr_val).type = ((yyvsp[-2].expr_val).type || (yyvsp[0].expr_val).type);
                                    }
                                  }
#line 1515 "src/calc.tab.c"
    break;

  case 19: /* expr: expr DIVIDE term  */
#line 204 "src/calc.yacc"
                                  {
                                    if ((yyvsp[-2].expr_val).type == -1 || (yyvsp[0].expr_val).type == -1) {
                                        (yyval.expr_val).type = -1;
                                    } else if ((yyvsp[0].expr_val).value == 0) {
                                        print_error("Division Error", "Cannot divide by zero");
                                        (yyval.expr_val).type = -1;
                                    } else {
                                        (yyval.expr_val).value = (yyvsp[-2].expr_val).value / (yyvsp[0].expr_val).value;
                                        (yyval.expr_val).type = ((yyvsp[-2].expr_val).type || (yyvsp[0].expr_val).type);
                                    }
                                  }
#line 1531 "src/calc.tab.c"
    break;

  case 20: /* expr: expr MOD term  */
#line 215 "src/calc.yacc"
                                  {
                                    if ((yyvsp[-2].expr_val).type == -1 || (yyvsp[0].expr_val).type == -1) {
                                        (yyval.expr_val).type = -1;
                                    } else if ((yyvsp[0].expr_val).value == 0) {
                                        print_error("Modulo Error", "Cannot perform modulo operation with zero");
                                        (yyval.expr_val).type = -1;
                                    } else {
                                        (yyval.expr_val).value = fmod((yyvsp[-2].expr_val).value, (yyvsp[0].expr_val).value);
                                        (yyval.expr_val).type = ((yyvsp[-2].expr_val).type || (yyvsp[0].expr_val).type);
                                    }
                                  }
#line 1547 "src/calc.tab.c"
    break;

  case 21: /* expr: expr POWER term  */
#line 226 "src/calc.yacc"
                                  {
                                    if ((yyvsp[-2].expr_val).type == -1 || (yyvsp[0].expr_val).type == -1) {
                                        (yyval.expr_val).type = -1;
                                    } else {
                                        (yyval.expr_val).value = pow((yyvsp[-2].expr_val).value, (yyvsp[0].expr_val).value);
                                        (yyval.expr_val).type = (fmod((yyval.expr_val).value, 1.0) == 0.0 && (yyvsp[-2].expr_val).type == 0 && (yyvsp[0].expr_val).type == 0) ? 0 : 1;
                                    }
                                  }
#line 1560 "src/calc.tab.c"
    break;

  case 22: /* expr: expr AND term  */
#line 234 "src/calc.yacc"
                                  {
                                    if ((yyvsp[-2].expr_val).type == -1 || (yyvsp[0].expr_val).type == -1) {
                                        (yyval.expr_val).type = -1;
                                    } else {
                                        (yyval.expr_val).value = (int)(yyvsp[-2].expr_val).value & (int)(yyvsp[0].expr_val).value;
                                        (yyval.expr_val).type = 0;
                                    }
                                  }
#line 1573 "src/calc.tab.c"
    break;

  case 23: /* expr: expr OR term  */
#line 242 "src/calc.yacc"
                                  {
                                    if ((yyvsp[-2].expr_val).type == -1 || (yyvsp[0].expr_val).type == -1) {
                                        (yyval.expr_val).type = -1;
                                    } else {
                                        (yyval.expr_val).value = (int)(yyvsp[-2].expr_val).value | (int)(yyvsp[0].expr_val).value;
                                        (yyval.expr_val).type = 0;
                                    }
                                  }
#line 1586 "src/calc.tab.c"
    break;

  case 24: /* expr: expr XOR term  */
#line 250 "src/calc.yacc"
                                  {
                                    if ((yyvsp[-2].expr_val).type == -1 || (yyvsp[0].expr_val).type == -1) {
                                        (yyval.expr_val).type = -1;
                                    } else {
                                        (yyval.expr_val).value = (int)(yyvsp[-2].expr_val).value ^ (int)(yyvsp[0].expr_val).value;
                                        (yyval.expr_val).type = 0;
                                    }
                                  }
#line 1599 "src/calc.tab.c"
    break;

  case 25: /* expr: expr RSHIFT term  */
#line 258 "src/calc.yacc"
                                  {
                                    if ((yyvsp[-2].expr_val).type == -1 || (yyvsp[0].expr_val).type == -1) {
                                        (yyval.expr_val).type = -1;
                                    } else {
                                        (yyval.expr_val).value = (int)(yyvsp[-2].expr_val).value >> (int)(yyvsp[0].expr_val).value;
                                        (yyval.expr_val).type = 0;
                                    }
                                  }
#line 1612 "src/calc.tab.c"
    break;

  case 26: /* expr: expr LSHIFT term  */
#line 266 "src/calc.yacc"
                                  {
                                    if ((yyvsp[-2].expr_val).type == -1 || (yyvsp[0].expr_val).type == -1) {
                                        (yyval.expr_val).type = -1;
                                    } else {
                                        (yyval.expr_val).value = (int)(yyvsp[-2].expr_val).value << (int)(yyvsp[0].expr_val).value;
                                        (yyval.expr_val).type = 0;
                                    }
                                  }
#line 1625 "src/calc.tab.c"
    break;

  case 27: /* term: factor  */
#line 277 "src/calc.yacc"
                                  { (yyval.expr_val) = (yyvsp[0].expr_val); }
#line 1631 "src/calc.tab.c"
    break;

  case 28: /* term: term TIMES factor  */
#line 278 "src/calc.yacc"
                                  {
                                    if ((yyvsp[-2].expr_val).type == -1 || (yyvsp[0].expr_val).type == -1) {
                                        (yyval.expr_val).type = -1;
                                    } else {
                                        (yyval.expr_val).value = (yyvsp[-2].expr_val).value * (yyvsp[0].expr_val).value;
                                        (yyval.expr_val).type = ((yyvsp[-2].expr_val).type || (yyvsp[0].expr_val).type);
                                    }
                                  }
#line 1644 "src/calc.tab.c"
    break;

  case 29: /* term: term DIVIDE factor  */
#line 286 "src/calc.yacc"
                                  {
                                    if ((yyvsp[-2].expr_val).type == -1 || (yyvsp[0].expr_val).type == -1) {
                                        (yyval.expr_val).type = -1;
                                    } else if ((yyvsp[0].expr_val).value == 0) {
                                        print_error("Division Error", "Cannot divide by zero");
                                        (yyval.expr_val).type = -1;
                                    } else {
                                        (yyval.expr_val).value = (yyvsp[-2].expr_val).value / (yyvsp[0].expr_val).value;
                                        (yyval.expr_val).type = ((yyvsp[-2].expr_val).type || (yyvsp[0].expr_val).type);
                                    }
                                  }
#line 1660 "src/calc.tab.c"
    break;

  case 30: /* term: term MOD factor  */
#line 297 "src/calc.yacc"
                                  {
                                    if ((yyvsp[-2].expr_val).type == -1 || (yyvsp[0].expr_val).type == -1) {
                                        (yyval.expr_val).type = -1;
                                    } else if ((yyvsp[0].expr_val).value == 0) {
                                        print_error("Modulo Error", "Cannot perform modulo operation with zero");
                                        (yyval.expr_val).type = -1;
                                    } else {
                                        (yyval.expr_val).value = fmod((yyvsp[-2].expr_val).value, (yyvsp[0].expr_val).value);
                                        (yyval.expr_val).type = ((yyvsp[-2].expr_val).type || (yyvsp[0].expr_val).type);
                                    }
                                  }
#line 1676 "src/calc.tab.c"
    break;

  case 31: /* factor: INTEGER  */
#line 311 "src/calc.yacc"
                                  { (yyval.expr_val).value = (yyvsp[0].ival); (yyval.expr_val).type = 0; }
#line 1682 "src/calc.tab.c"
    break;

  case 32: /* factor: FLOAT  */
#line 312 "src/calc.yacc"
                                  { (yyval.expr_val).value = (yyvsp[0].fval); (yyval.expr_val).type = 1; }
#line 1688 "src/calc.tab.c"
    break;

  case 33: /* factor: ID  */
#line 313 "src/calc.yacc"
                                  {
                                    if (variable_exists((yyvsp[0].id))) {
                                        get_variable_value((yyvsp[0].id), &(yyval.expr_val).value, &(yyval.expr_val).type);
                                    } else {
                                        print_error("Undefined Variable", "Variable not found");
                                        (yyval.expr_val).type = -1;
                                    }
                                    free((yyvsp[0].id));
                                  }
#line 1702 "src/calc.tab.c"
    break;

  case 34: /* factor: LPAREN expr RPAREN  */
#line 322 "src/calc.yacc"
                                  { (yyval.expr_val) = (yyvsp[-1].expr_val); }
#line 1708 "src/calc.tab.c"
    break;

  case 35: /* factor: unary  */
#line 323 "src/calc.yacc"
                                  { (yyval.expr_val) = (yyvsp[0].expr_val); }
#line 1714 "src/calc.tab.c"
    break;

  case 36: /* unary: MINUS factor  */
#line 327 "src/calc.yacc"
                                  { (yyval.expr_val).value = -(yyvsp[0].expr_val).value; (yyval.expr_val).type = (yyvsp[0].expr_val).type; }
#line 1720 "src/calc.tab.c"
    break;

  case 37: /* unary: NOT factor  */
#line 328 "src/calc.yacc"
                                  { (yyval.expr_val).value = ~(int)(yyvsp[0].expr_val).value; (yyval.expr_val).type = 0; }
#line 1726 "src/calc.tab.c"
    break;

  case 38: /* unary: INC ID  */
#line 329 "src/calc.yacc"
                                  {
                                    if (variable_exists((yyvsp[0].id))) {
                                        increment_variable((yyvsp[0].id));
                                        get_variable_value((yyvsp[0].id), &(yyval.expr_val).value, &(yyval.expr_val).type);
                                    } else {
                                        print_error("Undefined Variable", "Variable not found");
                                        YYERROR;
                                    }
                                    free((yyvsp[0].id));
                                  }
#line 1741 "src/calc.tab.c"
    break;

  case 39: /* unary: DEC ID  */
#line 339 "src/calc.yacc"
                                  {
                                    if (variable_exists((yyvsp[0].id))) {
                                        decrement_variable((yyvsp[0].id));
                                        get_variable_value((yyvsp[0].id), &(yyval.expr_val).value, &(yyval.expr_val).type);
                                    } else {
                                        print_error("Undefined Variable", "Variable not found");
                                        YYERROR;
                                    }
                                    free((yyvsp[0].id));
                                  }
#line 1756 "src/calc.tab.c"
    break;

  case 40: /* unary: SIN LPAREN expr RPAREN  */
#line 349 "src/calc.yacc"
                                  { (yyval.expr_val).value = sin((yyvsp[-1].expr_val).value); (yyval.expr_val).type = 1; }
#line 1762 "src/calc.tab.c"
    break;

  case 41: /* unary: COS LPAREN expr RPAREN  */
#line 350 "src/calc.yacc"
                                  { (yyval.expr_val).value = cos((yyvsp[-1].expr_val).value); (yyval.expr_val).type = 1; }
#line 1768 "src/calc.tab.c"
    break;

  case 42: /* unary: TAN LPAREN expr RPAREN  */
#line 351 "src/calc.yacc"
                                  {
                                    if (cos((yyvsp[-1].expr_val).value) == 0) {
                                        print_error("Tangent Error", "Tangent is undefined for this input");
                                        // YYERROR;
                                    } else {
                                        (yyval.expr_val).value = tan((yyvsp[-1].expr_val).value); (yyval.expr_val).type = 1;
                                    }
                                  }
#line 1781 "src/calc.tab.c"
    break;

  case 43: /* unary: LOG LPAREN expr RPAREN  */
#line 359 "src/calc.yacc"
                                  {
                                    if ((yyvsp[-1].expr_val).type == -1) {
                                        //YYERROR;
                                    } else {
                                        if ((yyvsp[-1].expr_val).value <= 0) {
                                            print_error("Logarithm Error", "Logarithm is undefined for non-positive input");
                                            //YYERROR;
                                        } else {
                                            (yyval.expr_val).value = log10((yyvsp[-1].expr_val).value); (yyval.expr_val).type = 1;
                                        }
                                    }
                                  }
#line 1798 "src/calc.tab.c"
    break;

  case 44: /* unary: LOG LPAREN error RPAREN  */
#line 371 "src/calc.yacc"
                                  {
                                    print_error("Syntax Error", "Invalid argument for logarithm function");
                                    fprintf(stderr, "Hint: Provide a valid numeric argument for the logarithm function\n");
                                    //YYERROR;
                                  }
#line 1808 "src/calc.tab.c"
    break;

  case 45: /* unary: LOG LPAREN expr error  */
#line 376 "src/calc.yacc"
                                  {
                                    print_error("Syntax Error", "Missing closing parenthesis for logarithm function");
                                    fprintf(stderr, "Hint: Add the missing closing parenthesis\n");
                                    fprintf(stderr, "Suggestion: Add ')' after the argument\n");
                                    //YYERROR;
                                  }
#line 1819 "src/calc.tab.c"
    break;

  case 46: /* unary: LN LPAREN expr RPAREN  */
#line 382 "src/calc.yacc"
                                  {
                                    if ((yyvsp[-1].expr_val).value <= 0) {
                                        print_error("Natural Logarithm Error", "Natural logarithm is undefined for non-positive input");
                                        // YYERROR;
                                    } else {
                                        (yyval.expr_val).value = log((yyvsp[-1].expr_val).value); (yyval.expr_val).type = 1;
                                    }
                                  }
#line 1832 "src/calc.tab.c"
    break;

  case 47: /* unary: PI  */
#line 390 "src/calc.yacc"
                                  { (yyval.expr_val).value = M_PI; (yyval.expr_val).type = 1; }
#line 1838 "src/calc.tab.c"
    break;


#line 1842 "src/calc.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

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
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  ++yylsp;
  YYLLOC_DEFAULT (*yylsp, yyerror_range, 2);

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 393 "src/calc.yacc"


void yyerror(char *s) {
    fprintf(stderr, "Error at line %d, column %d: %s\n", line_number, column_number, s);
    if (current_line) {
        fprintf(stderr, "  --> %s\n", current_line);
        int error_pos = column_number - 1;
        fprintf(stderr, "     ");
        for (int i = 0; i < error_pos; i++) {
            if (current_line[i] == '\t') {
                fprintf(stderr, "\t");
            } else {
                fprintf(stderr, " ");
            }
        }
        fprintf(stderr, "^\n");
        suggest_syntax_corrections(current_line);
    } else {
        fprintf(stderr, "  --> Line not available\n");
    }
    // Set the type to -1 to indicate an error
    yylval.expr_val.type = -1;
}

void print_error(const char *error_type, const char *error_msg) {
    fprintf(stderr, "Error at line %d, column %d: %s\n", line_number, column_number, error_type);
    fprintf(stderr, "%s\n", error_msg);

    if (current_line != NULL) {
        fprintf(stderr, "  --> %s\n", current_line);
        int error_pos = column_number - 1;
        fprintf(stderr, "     ");
        for (int i = 0; i < error_pos; i++) {
            if (current_line[i] == '\t') {
                fprintf(stderr, "\t");
            } else {
                fprintf(stderr, " ");
            }
        }
        fprintf(stderr, "^\n");
    }

    yylval.expr_val.type = -1;

    // Provide suggestions based on error type
    if (strcmp(error_type, "Undefined Variable") == 0) {
        fprintf(stderr, "Hint: Check if the variable is declared or if there is a typo in the variable name.\n");
        if (current_line != NULL) {
            list_similar_variables(current_line);
        }
    } else if (strcmp(error_type, "Division Error") == 0) {
        fprintf(stderr, "Hint: Ensure the divisor is not zero to avoid division by zero errors.\n");
    } else if (strcmp(error_type, "Syntax Error") == 0) {
        fprintf(stderr, "Hint: Check for missing parentheses, operators, or operands.\n");
        if (current_line != NULL) {
            suggest_syntax_corrections(current_line);
        }
    } else if (strcmp(error_type, "Invalid Identifier") == 0) {
        fprintf(stderr, "Hint: Identifiers must start with a letter or underscore and can only contain letters, digits, and underscores.\n");
    }
}

int list_similar_variables(const char *line) {
    if (line == NULL) {
        return 0;
    }

    char *token = strtok(strdup(line), " \t\n");
    Variable *variables = get_variables();
    if (variables == NULL) {
        return 0;
    }

    int min_distance = INT_MAX;
    char *closest_var = NULL;
    while (token != NULL) {
        if (is_valid_identifier(token) && !variable_exists(token)) {
            for (int i = 0; i < num_variables; i++) {
                if (variables[i].name != NULL) {
                    int distance = levenshtein_distance(token, variables[i].name);
                    if (distance < min_distance) {
                        min_distance = distance;
                        if (closest_var != NULL) {
                            free(closest_var);
                        }
                        closest_var = strdup(variables[i].name);
                    }
                }
            }
        }
        token = strtok(NULL, " \t\n");
    }

    if (closest_var != NULL) {
        fprintf(stderr, "Did you mean '%s'?\n", closest_var);
        free(closest_var);
        return 1;
    }
    return 0;
}

void suggest_syntax_corrections(const char *line) {
    if (line == NULL) {
        return;
    }

    // Check for missing parentheses
    int left_paren_count = 0;
    int right_paren_count = 0;
    for (int i = 0; line[i] != '\0'; i++) {
        if (line[i] == '(') {
            left_paren_count++;
        } else if (line[i] == ')') {
            right_paren_count++;
        }
    }
    if (left_paren_count > right_paren_count) {
        fprintf(stderr, "Hint: It seems like you are missing a closing parenthesis ')'\n");
        fprintf(stderr, "Suggestion: %s", line);
        for (int i = 0; i < left_paren_count - right_paren_count; i++) {
            fprintf(stderr, ")");
        }
        fprintf(stderr, "\n");
    } else if (right_paren_count > left_paren_count) {
        fprintf(stderr, "Hint: It seems like you have an extra closing parenthesis ')'\n");
        fprintf(stderr, "Suggestion: Check the parentheses in your expression\n");
    }

    // Check for missing operators
    char *token = strtok(strdup(line), " \t\n");
    while (token != NULL) {
        if (is_valid_identifier(token) || isdigit(token[0])) {
            char *next_token = strtok(NULL, " \t\n");
            if (next_token != NULL && (is_valid_identifier(next_token) || isdigit(next_token[0]))) {
                fprintf(stderr, "Hint: It seems like you are missing an operator between '%s' and '%s'\n", token, next_token);
            }
        }
        token = strtok(NULL, " \t\n");
    }

    // Check for invalid function calls
    if (strstr(line, "log(") != NULL || strstr(line, "ln(") != NULL) {
        if (strstr(line, "log(#") != NULL || strstr(line, "ln(#") != NULL) {
            fprintf(stderr, "Hint: Invalid argument for logarithm function\n");
            fprintf(stderr, "Suggestion: Provide a valid numeric argument for the logarithm function\n");
        }
    }

    // Check for missing semicolons
    if (line[strlen(line) - 1] != ';') {
        fprintf(stderr, "Hint: It seems like you are missing a semicolon ';' at the end of the statement\n");
        fprintf(stderr, "Suggestion: Add a semicolon at the end of the statement\n");
    }

    // Check for missing quotes
    int single_quote_count = 0;
    int double_quote_count = 0;
    for (int i = 0; line[i] != '\0'; i++) {
        if (line[i] == '\'') {
            single_quote_count++;
        } else if (line[i] == '\"') {
            double_quote_count++;
        }
    }
    if (single_quote_count % 2 != 0) {
        fprintf(stderr, "Hint: It seems like you are missing a closing single quote '\n");
        fprintf(stderr, "Suggestion: Add the missing single quote to complete the character literal\n");
    }
    if (double_quote_count % 2 != 0) {
        fprintf(stderr, "Hint: It seems like you are missing a closing double quote \"\n");
        fprintf(stderr, "Suggestion: Add the missing double quote to complete the string literal\n");
    }
}



int levenshtein_distance(const char *s1, const char *s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int matrix[len1 + 1][len2 + 1];

    for (int i = 0; i <= len1; i++) {
        matrix[i][0] = i;
    }
    for (int j = 0; j <= len2; j++) {
        matrix[0][j] = j;
    }

    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                matrix[i][j] = matrix[i - 1][j - 1];
            } else {
                int delete_cost = matrix[i - 1][j] + 1;
                int insert_cost = matrix[i][j - 1] + 1;
                int substitute_cost = matrix[i - 1][j - 1] + 1;
                matrix[i][j] = fmin(fmin(delete_cost, insert_cost), substitute_cost);
            }
        }
    }

    return matrix[len1][len2];
}

int is_valid_identifier(const char *name) {
    if (name == NULL || strlen(name) == 0) {
        return 0;
    }

    // Check if the first character is a letter or underscore
    if (!isalpha(name[0]) && name[0] != '_') {
        return 0;
    }

    // Check if the remaining characters are letters, digits, or underscores
    for (int i = 1; name[i] != '\0'; i++) {
        if (!isalnum(name[i]) && name[i] != '_') {
            return 0;
        }
    }

    return 1;
}
