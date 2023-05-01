/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.7"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 1 "yacc.y"

#include "main.h"
#include "y.tab.hpp"

extern "C"{
	// int yyparse(void);
	void yyerror(const char *s);
	void yyerror_2(const char *s, int line_val, int col_val);
	extern int yylex(void);
}
extern int yylineno,yycolumn;

void BitNode::insertChild(BitNode* child) {
    children.push_back(child);
	child->father=this;
	cout<<"\t\t"<<this->type<<"\t"<<child->type<<"\t"<<child->data<<"\t"<<endl;
}

BitNode* root;
vector<Error*> errorInfo;
int if_error=0;


/* Line 371 of yacc.c  */
#line 92 "y.tab.cpp"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
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
   by #include "y.tab.hpp".  */
#ifndef YY_YY_Y_TAB_HPP_INCLUDED
# define YY_YY_Y_TAB_HPP_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     _PROGRAM = 258,
     _CONST = 259,
     _VAR = 260,
     _PROCEDURE = 261,
     _FUNCTION = 262,
     _BEGIN = 263,
     _END = 264,
     _ARRAY = 265,
     _OF = 266,
     _IF = 267,
     _THEN = 268,
     _FOR = 269,
     _TO = 270,
     _DO = 271,
     _READ = 272,
     _WRITE = 273,
     _WHILE = 274,
     _NOT = 275,
     _ELSE = 276,
     _RANGE = 277,
     _UMINUS = 278,
     _ID = 279,
     _RELOP = 280,
     _DIGITS = 281,
     _NUM = 282,
     _VARTYPE = 283,
     _ADDOP = 284,
     _MULOP = 285,
     _ASSIGNOP = 286,
     _SEPARATOR = 287,
     _CHAR = 288,
     _BOOLEAN = 289
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_YY_Y_TAB_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 191 "y.tab.cpp"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

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
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  12
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   2754

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  43
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  35
/* YYNRULES -- Number of rules.  */
#define YYNRULES  247
/* YYNRULES -- Number of states.  */
#define YYNSTATES  562

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   289

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      37,    38,     2,     2,    39,     2,    35,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    40,    36,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    41,     2,    42,     2,     2,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     7,    11,    15,    19,    23,    27,    31,
      35,    42,    49,    56,    63,    70,    77,    84,    89,    94,
      99,   104,   109,   113,   117,   121,   125,   127,   129,   133,
     137,   141,   145,   146,   152,   158,   164,   170,   176,   182,
     186,   190,   194,   198,   201,   204,   207,   210,   212,   214,
     216,   218,   221,   224,   226,   230,   234,   238,   242,   243,
     249,   255,   261,   267,   273,   279,   283,   287,   291,   295,
     297,   299,   306,   313,   320,   327,   334,   341,   348,   350,
     352,   358,   362,   368,   374,   380,   386,   392,   396,   400,
     404,   408,   409,   413,   417,   421,   425,   429,   433,   437,
     441,   447,   453,   459,   465,   471,   477,   481,   485,   489,
     493,   494,   498,   502,   506,   510,   512,   514,   516,   518,
     520,   523,   526,   529,   533,   537,   541,   545,   549,   553,
     557,   561,   565,   569,   573,   577,   581,   585,   589,   593,
     595,   597,   601,   605,   609,   613,   615,   617,   619,   625,
     631,   637,   643,   649,   655,   664,   673,   682,   691,   700,
     709,   718,   727,   736,   741,   746,   751,   756,   761,   766,
     771,   776,   781,   786,   787,   792,   797,   802,   807,   812,
     816,   820,   824,   828,   830,   832,   835,   838,   841,   845,
     849,   853,   857,   858,   860,   862,   867,   872,   877,   882,
     887,   890,   893,   896,   897,   901,   905,   909,   913,   915,
     917,   921,   923,   927,   931,   935,   937,   941,   945,   947,
     951,   955,   959,   961,   965,   969,   973,   977,   979,   981,
     983,   985,   987,   989,   991,   996,  1001,  1006,  1011,  1016,
    1020,  1023,  1027,  1031,  1035,  1038,  1041,  1044
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      44,     0,    -1,    45,    46,    35,    -1,     1,    46,    35,
      -1,    45,     1,    35,    -1,    45,    46,     1,    -1,     3,
      24,    36,    -1,     1,    24,    36,    -1,     3,     1,    36,
      -1,     3,    24,     1,    -1,     3,    24,    37,    47,    38,
      36,    -1,     1,    24,    37,    47,    38,    36,    -1,     3,
       1,    37,    47,    38,    36,    -1,     3,    24,     1,    47,
      38,    36,    -1,     3,    24,    37,     1,    38,    36,    -1,
       3,    24,    37,    47,     1,    36,    -1,     3,    24,    37,
      47,    38,     1,    -1,    48,    51,    56,    65,    -1,     1,
      51,    56,    65,    -1,    48,     1,    56,    65,    -1,    48,
      51,     1,    65,    -1,    48,    51,    56,     1,    -1,    47,
      39,    24,    -1,     1,    39,    24,    -1,    47,     1,    24,
      -1,    47,    39,     1,    -1,    24,    -1,     1,    -1,     4,
      49,    36,    -1,     1,    49,    36,    -1,     4,     1,    36,
      -1,     4,    49,     1,    -1,    -1,    49,    36,    24,    25,
      50,    -1,     1,    36,    24,    25,    50,    -1,    49,     1,
      24,    25,    50,    -1,    49,    36,     1,    25,    50,    -1,
      49,    36,    24,     1,    50,    -1,    49,    36,    24,    25,
       1,    -1,    24,    25,    50,    -1,     1,    25,    50,    -1,
      24,     1,    50,    -1,    24,    25,     1,    -1,    29,    27,
      -1,    23,    27,    -1,     1,    27,    -1,    29,     1,    -1,
      27,    -1,    33,    -1,     1,    -1,    26,    -1,    29,    26,
      -1,    23,    26,    -1,    34,    -1,     5,    52,    36,    -1,
       1,    52,    36,    -1,     5,     1,    36,    -1,     5,    52,
       1,    -1,    -1,    52,    36,    47,    40,    53,    -1,     1,
      36,    47,    40,    53,    -1,    52,     1,    47,    40,    53,
      -1,    52,    36,     1,    40,    53,    -1,    52,    36,    47,
       1,    53,    -1,    52,    36,    47,    40,     1,    -1,    47,
      40,    53,    -1,     1,    40,    53,    -1,    47,     1,    53,
      -1,    47,    40,     1,    -1,    54,    -1,     1,    -1,    10,
      41,    55,    42,    11,    54,    -1,     1,    41,    55,    42,
      11,    54,    -1,    10,     1,    55,    42,    11,    54,    -1,
      10,    41,     1,    42,    11,    54,    -1,    10,    41,    55,
       1,    11,    54,    -1,    10,    41,    55,    42,     1,    54,
      -1,    10,    41,    55,    42,    11,     1,    -1,    28,    -1,
       1,    -1,    55,    39,    26,    22,    26,    -1,    26,    22,
      26,    -1,     1,    39,    26,    22,    26,    -1,    55,     1,
      26,    22,    26,    -1,    55,    39,     1,    22,    26,    -1,
      55,    39,    26,     1,    26,    -1,    55,    39,    26,    22,
       1,    -1,     1,    22,    26,    -1,    26,     1,    26,    -1,
      26,    22,     1,    -1,    56,    57,    36,    -1,    -1,     1,
      57,    36,    -1,    56,     1,    36,    -1,    56,    57,     1,
      -1,    58,    36,    64,    -1,     6,    24,    59,    -1,     1,
      24,    59,    -1,     6,     1,    59,    -1,     6,    24,     1,
      -1,     7,    24,    59,    40,    54,    -1,     1,    24,    59,
      40,    54,    -1,     7,     1,    59,    40,    54,    -1,     7,
      24,     1,    40,    54,    -1,     7,    24,    59,     1,    54,
      -1,     7,    24,    59,    40,     1,    -1,    37,    60,    38,
      -1,     1,    60,    38,    -1,    37,     1,    38,    -1,    37,
      60,     1,    -1,    -1,    60,    36,    61,    -1,     1,    36,
      61,    -1,    60,     1,    61,    -1,    60,    36,     1,    -1,
      61,    -1,     1,    -1,    62,    -1,    63,    -1,     1,    -1,
       5,    63,    -1,     1,    63,    -1,     5,     1,    -1,    47,
      40,    54,    -1,     1,    40,    54,    -1,    47,     1,    54,
      -1,    47,    40,     1,    -1,    48,    51,    65,    -1,     1,
      51,    65,    -1,    48,     1,    65,    -1,    48,    51,     1,
      -1,     8,    66,     9,    -1,     1,    66,     9,    -1,     8,
       1,     9,    -1,     8,    66,     1,    -1,    66,    36,    67,
      -1,     1,    36,    67,    -1,    66,     1,    67,    -1,    66,
      36,     1,    -1,    67,    -1,     1,    -1,    69,    31,    74,
      -1,     1,    31,    74,    -1,    69,     1,    74,    -1,    69,
      31,     1,    -1,    71,    -1,    65,    -1,     1,    -1,    12,
      74,    13,    67,    72,    -1,     1,    74,    13,    67,    72,
      -1,    12,     1,    13,    67,    72,    -1,    12,    74,     1,
      67,    72,    -1,    12,    74,    13,     1,    72,    -1,    12,
      74,    13,    67,     1,    -1,    14,    24,    31,    74,    15,
      74,    16,    67,    -1,     1,    24,    31,    74,    15,    74,
      16,    67,    -1,    14,     1,    31,    74,    15,    74,    16,
      67,    -1,    14,    24,     1,    74,    15,    74,    16,    67,
      -1,    14,    24,    31,     1,    15,    74,    16,    67,    -1,
      14,    24,    31,    74,     1,    74,    16,    67,    -1,    14,
      24,    31,    74,    15,     1,    16,    67,    -1,    14,    24,
      31,    74,    15,    74,     1,    67,    -1,    14,    24,    31,
      74,    15,    74,    16,     1,    -1,    17,    37,    68,    38,
      -1,     1,    37,    68,    38,    -1,    17,     1,    68,    38,
      -1,    17,    37,     1,    38,    -1,    17,    37,    68,     1,
      -1,     1,    37,    73,    38,    -1,    18,     1,    73,    38,
      -1,    18,    37,     1,    38,    -1,    18,    37,    73,     1,
      -1,    18,    37,    73,    38,    -1,    -1,    19,    74,    16,
      67,    -1,     1,    74,    16,    67,    -1,    19,     1,    16,
      67,    -1,    19,    74,     1,    67,    -1,    19,    74,    16,
       1,    -1,    68,    39,    69,    -1,     1,    39,    69,    -1,
      68,     1,    69,    -1,    68,    39,     1,    -1,    69,    -1,
       1,    -1,    24,    70,    -1,     1,    70,    -1,    24,     1,
      -1,    41,    73,    42,    -1,     1,    73,    42,    -1,    41,
       1,    42,    -1,    41,    73,     1,    -1,    -1,    24,    -1,
       1,    -1,     1,    37,    73,    38,    -1,    24,     1,    73,
      38,    -1,    24,    37,     1,    38,    -1,    24,    37,    73,
       1,    -1,    24,    37,    73,    38,    -1,    21,    67,    -1,
       1,    67,    -1,    21,     1,    -1,    -1,    73,    39,    74,
      -1,     1,    39,    74,    -1,    73,     1,    74,    -1,    73,
      39,     1,    -1,    74,    -1,     1,    -1,    75,    25,    75,
      -1,    75,    -1,     1,    25,    75,    -1,    75,     1,    75,
      -1,    75,    25,     1,    -1,     1,    -1,    75,    29,    76,
      -1,    75,    23,    76,    -1,    76,    -1,     1,    29,    76,
      -1,    75,     1,    76,    -1,    75,    29,     1,    -1,     1,
      -1,    76,    30,    77,    -1,     1,    30,    77,    -1,    76,
       1,    77,    -1,    76,    30,     1,    -1,    77,    -1,     1,
      -1,    27,    -1,    26,    -1,    34,    -1,    69,    -1,     1,
      -1,     1,    37,    73,    38,    -1,    24,     1,    73,    38,
      -1,    24,    37,     1,    38,    -1,    24,    37,    73,     1,
      -1,    24,    37,    73,    38,    -1,    37,    74,    38,    -1,
      20,    77,    -1,     1,    74,    38,    -1,    37,     1,    38,
      -1,    37,    74,     1,    -1,     1,    77,    -1,    20,     1,
      -1,    29,    77,    -1,    23,    77,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    30,    30,    42,    48,    54,    59,    72,    78,    84,
      88,   107,   113,   119,   125,   131,   137,   142,   153,   159,
     165,   171,   176,   189,   195,   201,   205,   214,   219,   232,
     238,   244,   248,   255,   274,   280,   286,   292,   298,   302,
     318,   324,   330,   335,   351,   364,   369,   374,   385,   396,
     401,   412,   427,   439,   450,   463,   469,   475,   479,   486,
     502,   508,   514,   520,   526,   530,   542,   548,   554,   559,
     568,   572,   591,   597,   603,   609,   615,   621,   626,   636,
     641,   658,   671,   676,   682,   688,   694,   697,   703,   709,
     714,   726,   731,   737,   743,   748,   761,   773,   779,   785,
     789,   804,   810,   816,   822,   828,   834,   846,   852,   858,
     862,   869,   880,   886,   892,   896,   904,   909,   918,   926,
     931,   941,   947,   952,   966,   972,   978,   983,   993,   999,
    1005,  1010,  1023,  1029,  1035,  1040,  1051,  1057,  1063,  1067,
    1074,  1079,  1090,  1096,  1102,  1106,  1114,  1121,  1125,  1139,
    1145,  1151,  1157,  1163,  1167,  1187,  1193,  1199,  1205,  1211,
    1217,  1223,  1229,  1233,  1248,  1254,  1260,  1266,  1271,  1277,
    1283,  1289,  1293,  1308,  1314,  1327,  1333,  1339,  1345,  1350,
    1362,  1368,  1374,  1378,  1387,  1392,  1404,  1410,  1415,  1428,
    1434,  1440,  1444,  1451,  1462,  1468,  1474,  1480,  1486,  1490,
    1506,  1519,  1525,  1529,  1536,  1550,  1556,  1562,  1566,  1575,
    1580,  1592,  1602,  1608,  1614,  1620,  1625,  1636,  1648,  1658,
    1664,  1670,  1676,  1681,  1693,  1699,  1705,  1709,  1718,  1724,
    1734,  1743,  1753,  1762,  1766,  1770,  1776,  1782,  1786,  1803,
    1819,  1831,  1837,  1843,  1849,  1855,  1859,  1869
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "_PROGRAM", "_CONST", "_VAR",
  "_PROCEDURE", "_FUNCTION", "_BEGIN", "_END", "_ARRAY", "_OF", "_IF",
  "_THEN", "_FOR", "_TO", "_DO", "_READ", "_WRITE", "_WHILE", "_NOT",
  "_ELSE", "_RANGE", "_UMINUS", "_ID", "_RELOP", "_DIGITS", "_NUM",
  "_VARTYPE", "_ADDOP", "_MULOP", "_ASSIGNOP", "_SEPARATOR", "_CHAR",
  "_BOOLEAN", "'.'", "';'", "'('", "')'", "','", "':'", "'['", "']'",
  "$accept", "programstruct", "program_head", "program_body", "idlist",
  "const_declarations", "const_declaration", "const_value",
  "var_declarations", "var_declaration", "type", "basic_type", "period",
  "subprogram_declarations", "subprogram", "subprogram_head",
  "formal_parameter", "parameter_list", "parameter", "var_parameter",
  "value_parameter", "subprogram_body", "compound_statement",
  "statement_list", "statement", "variable_list", "variable", "id_varpart",
  "procedure_call", "else_part", "expression_list", "expression",
  "simple_expression", "term", "factor", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,    46,    59,    40,    41,    44,
      58,    91,    93
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    43,    44,    44,    44,    44,    45,    45,    45,    45,
      45,    45,    45,    45,    45,    45,    45,    46,    46,    46,
      46,    46,    47,    47,    47,    47,    47,    47,    48,    48,
      48,    48,    48,    49,    49,    49,    49,    49,    49,    49,
      49,    49,    49,    50,    50,    50,    50,    50,    50,    50,
      50,    50,    50,    50,    51,    51,    51,    51,    51,    52,
      52,    52,    52,    52,    52,    52,    52,    52,    52,    53,
      53,    53,    53,    53,    53,    53,    53,    53,    54,    54,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      56,    56,    56,    56,    56,    57,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    58,    59,    59,    59,    59,
      59,    60,    60,    60,    60,    60,    60,    61,    61,    61,
      62,    62,    62,    63,    63,    63,    63,    64,    64,    64,
      64,    65,    65,    65,    65,    66,    66,    66,    66,    66,
      66,    67,    67,    67,    67,    67,    67,    67,    67,    67,
      67,    67,    67,    67,    67,    67,    67,    67,    67,    67,
      67,    67,    67,    67,    67,    67,    67,    67,    67,    67,
      67,    67,    67,    67,    67,    67,    67,    67,    67,    68,
      68,    68,    68,    68,    68,    69,    69,    69,    70,    70,
      70,    70,    70,    71,    71,    71,    71,    71,    71,    71,
      72,    72,    72,    72,    73,    73,    73,    73,    73,    73,
      74,    74,    74,    74,    74,    74,    75,    75,    75,    75,
      75,    75,    75,    76,    76,    76,    76,    76,    76,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    77
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     3,     3,     3,     3,     3,     3,     3,
       6,     6,     6,     6,     6,     6,     6,     4,     4,     4,
       4,     4,     3,     3,     3,     3,     1,     1,     3,     3,
       3,     3,     0,     5,     5,     5,     5,     5,     5,     3,
       3,     3,     3,     2,     2,     2,     2,     1,     1,     1,
       1,     2,     2,     1,     3,     3,     3,     3,     0,     5,
       5,     5,     5,     5,     5,     3,     3,     3,     3,     1,
       1,     6,     6,     6,     6,     6,     6,     6,     1,     1,
       5,     3,     5,     5,     5,     5,     5,     3,     3,     3,
       3,     0,     3,     3,     3,     3,     3,     3,     3,     3,
       5,     5,     5,     5,     5,     5,     3,     3,     3,     3,
       0,     3,     3,     3,     3,     1,     1,     1,     1,     1,
       2,     2,     2,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     1,
       1,     3,     3,     3,     3,     1,     1,     1,     5,     5,
       5,     5,     5,     5,     8,     8,     8,     8,     8,     8,
       8,     8,     8,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     0,     4,     4,     4,     4,     4,     3,
       3,     3,     3,     1,     1,     2,     2,     2,     3,     3,
       3,     3,     0,     1,     1,     4,     4,     4,     4,     4,
       2,     2,     2,     0,     3,     3,     3,     3,     1,     1,
       3,     1,     3,     3,     3,     1,     3,     3,     1,     3,
       3,     3,     1,     3,     3,     3,     3,     1,     1,     1,
       1,     1,     1,     1,     4,     4,     4,     4,     4,     3,
       2,     3,     3,     3,     2,     2,     2,     2
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     1,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     7,     0,     3,     0,     0,     8,     0,     0,
       6,     0,     4,     5,     2,    27,    26,     0,     0,     0,
       0,    27,     0,     0,     0,     0,     0,     0,     0,    30,
      31,     0,    27,     0,     0,     0,     0,     0,     0,     0,
      27,     0,     0,     0,     0,    49,     0,    50,    47,     0,
      48,    53,    40,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    41,    42,    39,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    18,     0,     0,    19,
       0,    20,     0,    17,     0,     0,     0,     0,     0,     0,
      23,    70,     0,    78,    66,    69,    45,    52,    44,    46,
      51,    43,     0,    24,    67,    25,    22,    68,    65,     0,
      27,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    92,     0,     0,     0,     0,     0,     0,     0,     0,
      93,   146,     0,   139,     0,   145,     0,     0,     0,    94,
      90,    11,    12,    13,    14,    15,    16,    10,     0,     0,
       0,     0,    34,     0,     0,     0,     0,    35,    36,    37,
      38,    33,     0,     0,    97,    98,     0,    96,     0,     0,
       0,     0,     0,    95,     0,     0,     0,     0,   230,   229,
       0,     0,   231,     0,     0,     0,     0,   186,     0,     0,
       0,   227,     0,     0,     0,   232,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   185,     0,   132,
       0,     0,     0,   133,     0,     0,     0,   131,    60,     0,
       0,     0,     0,     0,     0,    61,    62,    63,    64,    59,
       0,     0,     0,     0,   115,   117,   118,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   208,   227,     0,   240,     0,   247,     0,
       0,     0,   246,     0,   142,     0,   136,     0,     0,   232,
       0,     0,     0,     0,   208,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   183,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   137,     0,   135,   143,     0,   141,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    27,     0,     0,   121,   122,   120,     0,     0,
       0,     0,   107,   108,     0,   106,    79,   101,   102,   103,
     104,    79,   100,     0,   128,     0,   129,     0,   127,     0,
       0,     0,     0,     0,   227,   224,     0,     0,     0,   189,
     241,     0,     0,     0,     0,   242,     0,     0,   164,     0,
     168,   243,   239,   190,     0,   188,     0,   175,     0,     0,
       0,     0,     0,     0,     0,   225,     0,   223,     0,   208,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   165,   166,     0,   163,
     169,   170,     0,   172,   176,   177,     0,   174,     0,     0,
     196,   108,     0,   199,   197,    87,     0,    88,    89,    81,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     112,   124,   125,    79,   123,   113,     0,   111,   205,     0,
     234,   206,     0,   204,   235,     0,   236,     0,   238,   232,
       0,   181,     0,   179,     0,     0,   149,   150,   234,   235,
     236,     0,   238,   151,     0,   152,     0,   148,     0,     0,
       0,     0,     0,   180,     0,     0,     0,     0,     0,     0,
      72,    73,    74,    75,    76,    77,    71,     0,     0,   201,
       0,   200,   139,     0,     0,     0,     0,     0,     0,    82,
      83,    84,    85,    86,    80,     0,     0,     0,     0,     0,
       0,     0,     0,   155,   156,   157,   158,   159,   160,   161,
       0,   154
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,     8,   252,     9,    18,    72,    19,    40,
     114,   115,   241,    48,    91,    92,   184,   253,   254,   255,
     256,   193,   151,   152,   153,   288,   215,   207,   155,   496,
     272,   306,   209,   210,   211
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -244
static const yytype_int16 yypact[] =
{
     366,  2722,   156,    80,  1902,  1427,   399,   763,    83,  1371,
     962,   282,  -244,  1683,   123,   489,   467,   215,    24,  1233,
     721,   106,  -244,   664,  -244,   854,  1248,  -244,   664,  2730,
    -244,   682,  -244,  -244,  -244,  1246,  -244,  1972,   152,    30,
     259,  1288,   272,  1972,  2678,   196,  1714,  1334,  1264,   152,
     196,  2574,   213,   130,   356,  1264,  1686,  1943,   299,   301,
    1008,   316,   664,   261,   393,   308,  1033,  -244,  -244,   171,
    -244,  -244,  -244,   385,   248,   716,   662,   664,   885,   916,
     947,   978,  -244,   308,  -244,   461,   481,   324,   367,   730,
     774,   448,   482,  2577,  2591,   380,  -244,   514,   548,  -244,
    2611,  -244,  2435,  -244,   566,   574,   582,    -8,   605,    63,
    -244,   525,     5,  -244,  -244,  -244,  -244,  -244,  -244,  -244,
    -244,  -244,  1972,  -244,  -244,  -244,  -244,   525,  -244,   112,
    1057,   185,  1972,  1972,  1972,  2691,    57,   310,   369,   231,
     237,  -244,  1350,  1560,  2097,   802,   103,   127,  2109,   250,
    -244,  -244,   558,  -244,     3,  -244,  1591,   164,   612,  -244,
    -244,  -244,  -244,  -244,  -244,  -244,  -244,  -244,   393,   298,
     298,   398,  -244,   393,   393,   248,   676,  -244,  -244,  -244,
     308,  -244,   727,   829,   580,  -244,   581,  -244,   584,   143,
      58,  1021,   607,  -244,  1467,  2121,  2136,   335,  -244,  -244,
    2136,  2148,  -244,  2625,  2160,  2175,  1370,  -244,   734,  1268,
    1092,  -244,  1844,   562,  2187,  -244,   479,   681,   135,   864,
     895,  2199,  2214,  1864,   314,  2058,  2070,  -244,  2625,  -244,
    2645,  2148,  2226,  -244,  2082,  2238,  2421,  -244,  -244,   680,
     124,    47,    48,   770,    75,  -244,  -244,  -244,   525,  -244,
     437,   988,   249,   111,  -244,  -244,  -244,   622,   559,   238,
     238,   238,   238,   293,   557,  1049,   665,   503,  2253,  2265,
    2136,  2160,    90,   619,  1120,   613,  -244,   613,  -244,   994,
    2148,  2277,  -244,   874,  -244,  1498,  -244,  1703,   341,   349,
     351,   411,  1113,    91,  -244,  2460,  2460,  2253,  2265,  2292,
    2304,  2136,  2316,   700,  2460,  2331,   615,   905,  2343,  1891,
       9,  2460,  2474,  2148,  2148,  2355,   155,   169,   424,  -244,
     174,   440,  1041,   450,  1723,   464,  2460,  2460,  2499,   406,
    1381,    14,  1642,   470,  -244,  1622,  -244,  -244,  1676,  -244,
    1750,   707,   717,   723,   459,   729,   468,   748,   750,   776,
     648,   332,  1071,   945,   238,  -244,   292,  -244,   469,   392,
     945,   976,  -244,  -244,   274,  -244,  -244,  -244,  -244,  -244,
    -244,  -244,  -244,  2659,  -244,  1968,  -244,  2679,  -244,  2148,
     747,  1310,   781,  1144,  -244,  -244,   530,  2148,  2370,  -244,
    -244,    23,   780,  1770,   534,  -244,  2148,  1034,  -244,  1048,
    -244,  -244,  -244,  -244,   812,  -244,   205,  -244,  1321,  1175,
    1206,   655,  1352,   781,  1237,  -244,   613,  -244,   843,   615,
     205,  1797,   542,    35,  1817,   592,   205,  1529,   743,   799,
     801,  1911,   407,  2199,  1034,  1989,  -244,  -244,   686,  -244,
    -244,  -244,  2010,  -244,  -244,  -244,  1498,  -244,  1014,  2382,
    -244,   408,  2031,  -244,  -244,  -244,   807,  -244,  -244,  -244,
     809,   818,   554,   238,   238,   238,   238,   238,   438,  1163,
    -244,  -244,  -244,  -244,  -244,  -244,  1170,  -244,  -244,  2265,
     744,  -244,  1061,  -244,   757,  2148,  1068,   967,  1157,   606,
     216,  -244,   226,  -244,  2460,  2513,  -244,  -244,  -244,  -244,
    -244,   936,  -244,  -244,  1436,  -244,  2538,  -244,  2148,  2148,
    2148,  2148,  2394,  -244,  1401,   819,   821,   831,   845,   535,
    -244,  -244,  -244,  -244,  -244,  -244,  -244,  1279,   858,  -244,
    1498,  -244,   855,   871,   886,   889,   891,  1938,   698,  -244,
    -244,  -244,  -244,  -244,  -244,  2460,  2460,  2460,  2460,  2460,
    2460,  2460,  2552,  -244,  -244,  -244,  -244,  -244,  -244,  -244,
    1498,  -244
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -244,  -244,  -244,   923,     4,   791,   930,    28,    -1,   922,
     -53,  -220,   991,  1123,  1070,  -244,  1276,  -181,   759,  -244,
    -213,  -244,   -43,   870,     1,  1013,   -93,  -146,  -244,   798,
     193,  -126,   -69,  -243,   287
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -245
static const yytype_int16 yytable[] =
{
     154,   154,   258,   227,   231,    96,   170,   154,    26,   154,
     401,   227,    99,   101,   103,   387,   123,   208,   216,    39,
      39,   124,   224,   128,   387,    45,   383,    53,   165,    39,
     208,    74,    58,    59,   232,    61,   387,   355,   357,   367,
     368,   369,   370,   372,   355,   258,   171,   402,   345,   345,
     206,   227,   450,   388,   409,   410,   389,   414,   182,   262,
      46,   484,   388,   206,    97,   389,   109,   227,   273,    75,
      76,    82,    84,   499,   388,   284,   350,   389,   291,   294,
      12,   129,   131,   109,   129,   131,   346,   346,   310,   347,
     348,   387,   404,  -110,   183,   294,   294,  -110,   263,   294,
     294,   206,    75,   168,   219,   337,   339,    50,   294,   294,
     154,   289,   360,    97,   346,   238,   355,   351,    24,   355,
     245,   246,   247,   249,    33,   343,   319,   319,   221,   388,
     388,    97,   389,   405,   471,   154,   314,   154,   472,   474,
     220,   273,    51,   154,   250,   291,   344,   361,   251,   362,
     172,    75,   173,   294,   392,   294,   433,    10,    34,   208,
     177,   178,   179,   181,   222,   234,   315,    36,    98,    75,
     435,   227,   119,  -193,   206,   433,    73,   419,   289,   291,
      11,   294,   294,   261,   227,  -193,   175,   429,   430,   432,
     264,   266,   206,  -184,   434,  -192,   205,   120,   121,   381,
    -193,   235,   154,   154,   286,   205,   494,  -192,  -192,   208,
     205,   154,   437,   434,  -203,   205,    43,   433,   154,   154,
      85,   374,   376,   378,    75,   176,   495,   433,   408,   334,
     412,   336,   182,   154,   154,   154,   527,   334,   189,   366,
      44,  -203,   206,   520,   521,   522,   523,   524,   526,   111,
     358,   225,    63,   478,  -192,  -192,   355,   205,   112,  -193,
      77,   481,   483,   355,  -182,  -182,   113,   205,   183,    39,
     478,  -110,   123,    80,   183,   469,   113,  -110,   481,   251,
     154,  -192,   154,    29,   154,   110,  -110,   226,    75,   359,
    -110,   205,   419,   -27,   371,    78,   406,   407,    36,   239,
      97,   208,    97,   489,   491,   420,   493,   294,    81,   294,
    -109,   182,   426,   428,  -109,   327,   481,   107,    30,    31,
     208,   113,   419,   478,   240,   134,   481,   444,   445,   447,
     328,    63,   354,   467,   206,   116,   279,   104,    75,   105,
      75,   513,   397,   468,  -193,   491,  -110,   183,  -192,   135,
    -183,  -192,   387,   206,   108,    75,  -193,    88,  -192,   528,
    -192,   481,    89,    90,  -192,  -192,   280,     1,   227,     2,
     186,  -193,   281,  -192,  -192,   481,   205,  -192,   273,   398,
     399,   159,   533,   534,   535,   536,   538,  -183,  -183,   400,
     388,   136,    62,   473,   111,    63,    64,   290,   293,   243,
      20,   154,   154,   112,   208,  -110,   183,   448,   511,  -197,
     122,   206,   401,   154,   323,   325,   160,  -197,   331,   333,
     113,   113,   512,    17,   240,   397,   195,   331,   333,   196,
     330,   268,   198,   199,   208,   269,   270,   206,   352,   525,
     202,   438,   353,   305,  -116,   449,   354,   205,  -192,   402,
    -208,   387,   154,   154,   154,   154,   154,   154,   154,   154,
     458,    36,   436,   399,   386,   442,   113,   206,    41,   461,
     366,   452,   391,   353,   394,  -116,    63,   354,   439,   399,
     311,   274,   276,   278,   141,   459,   132,   282,   440,   388,
      35,    36,   312,   123,   462,   529,   531,   113,   422,   274,
     423,   425,   443,   388,   267,   532,   133,   529,   453,   388,
     274,    94,  -140,    36,    37,   144,  -192,   145,   142,  -192,
     146,   147,   148,   195,  -147,    38,   196,   197,   268,   198,
     199,   387,   269,   270,   201,   487,   543,   202,   123,   203,
     271,  -192,   379,   387,   205,  -192,   553,   554,   555,   556,
     557,   558,   559,   561,   274,   518,   384,   385,   373,   228,
     364,   544,   274,   307,   274,    94,   169,   229,   480,   388,
     274,  -192,   488,   388,   274,  -192,   519,  -192,  -192,   274,
     498,   388,   250,  -192,   161,  -192,   251,  -192,   415,   417,
     274,  -192,  -192,   501,   230,   361,   274,   365,  -192,   308,
    -192,  -192,   162,   205,  -192,    36,   166,  -180,   265,   274,
     163,   274,    16,   236,   303,   -58,   274,   -99,   164,   274,
     259,   237,  -192,   352,   260,   274,  -192,   274,  -192,  -192,
     502,   388,   295,   195,  -192,   296,   196,   213,  -192,   198,
     199,   167,   200,  -192,  -180,  -180,    36,   202,   230,  -192,
     305,  -192,  -192,   390,   205,  -192,   303,   390,   353,   466,
     363,    63,   354,   127,  -192,    52,   377,   274,  -192,   274,
    -192,  -192,   112,    94,   460,   195,  -192,   248,   196,   213,
     274,   198,   199,    60,   269,   270,   112,   490,    36,   202,
     113,  -192,   305,  -192,  -192,  -167,   205,  -192,   274,   551,
     274,   418,   341,   274,   113,   274,    36,  -167,   274,  -192,
     317,   274,   313,  -192,   552,  -192,  -192,   125,   274,   342,
     195,  -192,  -167,   196,   213,   268,   198,   199,   250,   269,
     270,   137,   251,   455,   202,   274,  -192,   305,  -192,  -192,
     126,   205,  -192,   456,   506,  -168,    37,   295,   303,   457,
     296,    36,  -203,  -168,   138,   460,  -192,    49,  -196,   463,
    -192,   464,  -192,  -192,   495,  -168,  -196,   195,  -192,   274,
     196,   213,  -192,   198,   199,   139,   269,   270,  -196,  -203,
    -168,   202,   303,  -192,   305,  -192,  -192,   465,   205,  -192,
    -192,   274,   341,  -196,  -192,   485,  -192,  -192,   140,    22,
      23,   195,  -192,   217,   196,   213,  -192,   198,   199,   342,
     200,   270,   349,   283,   508,   202,   509,  -192,   305,  -192,
    -192,  -191,   205,  -192,   274,  -191,   218,  -191,  -191,   515,
     257,   516,   195,  -191,   251,   196,   213,  -191,   198,   199,
     517,   200,  -191,  -191,   418,   539,   202,   540,  -191,   214,
    -191,  -191,  -192,    36,  -191,    54,  -192,   541,  -192,  -192,
     -91,   -91,   -91,   195,  -192,   316,   196,   213,   268,   198,
     199,   542,   269,   270,   545,   303,  -201,   202,    36,  -192,
     305,  -192,   379,  -192,   205,  -192,   130,   546,   317,  -192,
    -192,   -55,   -55,   -55,   195,  -192,   320,   196,   213,   268,
     198,   199,   547,   269,   270,   548,   322,   549,   202,    36,
    -192,   305,  -192,  -192,  -187,   205,  -192,    52,  -187,   317,
    -187,  -187,   -56,   -56,   -56,   195,  -187,    14,   196,   213,
    -187,   198,   199,   192,   200,  -187,    21,   283,    42,   202,
      36,  -187,   214,  -187,  -187,  -237,   469,  -187,    52,  -237,
     251,  -237,  -237,   -57,   -57,   -57,   195,  -237,     0,   196,
     213,  -237,   198,   199,   158,   200,  -237,     0,   283,    36,
     202,    36,  -237,   214,  -237,  -237,  -198,   476,  -237,   130,
    -237,   251,     0,  -237,   -54,   -54,   -54,   195,  -198,   356,
     196,   213,  -237,   198,   199,   322,   200,  -237,    27,    28,
      36,   202,    36,  -198,   214,  -237,  -237,  -187,     0,  -237,
    -187,     0,    36,     0,   195,   418,     0,   196,   213,  -187,
     198,   199,    15,   200,  -187,  -187,    16,     0,   202,   -58,
       0,   214,  -187,  -187,   195,   490,  -187,   196,   213,   268,
     198,   199,   303,   269,   270,    17,   106,    63,   202,   492,
     375,   305,  -192,    63,   354,   205,  -192,    94,   317,   117,
     118,   195,   303,     0,   196,   213,   268,   198,   199,  -197,
     269,   270,   317,    36,     0,   202,     0,  -197,   305,  -192,
     379,   195,   205,  -192,   196,   213,   268,   198,   199,  -197,
     269,   270,     0,   301,     0,   202,    63,   174,   305,  -192,
    -192,  -218,   205,  -192,  -197,  -218,     0,  -218,  -218,     0,
      63,   354,   470,  -218,   303,  -218,     0,  -218,    95,   475,
     477,  -218,   302,   475,     0,    95,     0,    95,  -218,  -244,
    -218,  -218,     0,   195,  -218,  -244,   196,   213,   268,   198,
     199,  -244,   269,   270,     0,   301,     0,   202,    55,    57,
     305,     0,   379,  -219,   205,   403,  -244,  -219,  -199,  -219,
    -219,   242,   244,     0,   352,  -219,  -199,  -219,     0,  -219,
       0,   352,     0,  -219,   302,     0,   301,     0,  -199,     0,
    -219,     0,  -219,  -219,  -218,     0,  -219,    36,  -218,     0,
    -218,  -218,     0,  -199,    36,     0,  -218,     0,  -218,  -119,
    -220,  -119,    63,   354,  -218,   302,  -114,   301,  -114,    63,
     354,  -218,     0,  -218,  -218,  -217,     0,  -218,   497,  -217,
       0,  -217,  -217,     0,   503,   505,   507,  -217,     0,  -217,
       0,  -217,   318,   321,    47,  -217,   302,     0,   301,   -91,
     -91,   -91,  -217,     0,  -217,  -217,  -216,     0,  -217,    56,
    -216,     0,  -216,  -216,   -91,   -91,   -91,     0,  -216,     0,
    -216,     0,  -216,     0,     0,    93,  -216,   302,     0,   297,
      89,    90,    94,  -216,     0,  -216,  -216,  -211,     0,  -216,
     301,  -211,    62,  -211,  -211,    63,    64,     0,  -220,  -211,
       0,   298,  -220,   299,  -220,  -220,     0,   300,     0,     0,
    -220,     0,  -220,     0,  -211,     0,  -211,  -211,  -220,   302,
    -211,   479,     0,     0,     0,  -220,     0,  -220,  -220,  -212,
       0,  -220,   479,  -212,    79,  -212,  -212,    63,    64,     0,
    -213,  -212,     0,   298,  -213,    88,  -213,  -213,     0,   300,
      89,    90,  -213,     0,   298,     0,  -212,     0,  -212,  -212,
     300,   191,  -212,   479,     6,   -32,     0,  -213,   -32,  -213,
    -213,  -210,     0,  -213,     0,  -210,     0,  -210,  -210,     0,
       0,   231,    25,  -210,     0,   298,    16,   -58,   -58,   -58,
       0,   300,   307,  -232,     0,     0,  -232,     0,  -210,     0,
    -210,  -210,     0,  -232,  -210,  -232,     0,     0,     0,  -232,
    -232,   232,   307,     0,  -192,     0,  -192,     0,  -232,  -232,
    -192,  -192,  -232,   185,   187,   188,   190,     0,   308,  -192,
     -26,   -26,   205,  -192,  -192,     0,  -192,     0,    15,     0,
    -192,  -192,    16,   -58,   -58,   -58,     0,   267,   308,  -192,
     -23,   -23,   205,  -192,    94,  -140,     0,     0,   144,  -192,
     145,    17,  -192,   146,   147,   148,   195,  -173,     0,   196,
     197,   268,   198,   199,     0,   269,   270,   201,   267,     0,
     202,     0,   203,   271,     0,    94,  -140,   205,     0,   144,
    -192,   145,     0,  -192,   146,   147,   148,   195,     0,     0,
     196,   197,   268,   198,   199,     0,   269,   270,   201,   194,
       0,   202,     0,   203,   271,     0,    94,  -147,   205,     0,
     144,     0,   145,     0,     0,   146,   147,   148,   195,  -147,
       0,   196,   197,     0,   198,   199,     0,   200,     0,   201,
     504,     0,   202,     0,  -147,   204,     0,    94,  -147,   205,
       0,   144,     0,   145,     0,     0,   146,   147,   148,   195,
     495,     0,   196,   197,     0,   198,   199,     0,   200,     0,
     201,   194,     0,   202,     0,  -147,   204,     0,    94,  -140,
     205,     0,   144,     0,   145,     0,     0,   146,   147,   148,
     195,     0,     0,   196,   197,     0,   198,   199,     0,   200,
       0,   201,   194,     0,   202,     0,   203,   204,     0,    94,
     233,   205,     0,   144,     0,   145,     0,     0,   146,   147,
     148,   195,     0,     0,   196,   197,     0,   198,   199,     0,
     200,     0,   201,   194,     0,   202,     0,   203,   204,     0,
      94,  -138,   205,     0,   144,     0,   145,     0,     0,   146,
     147,   148,   195,   448,     0,   196,   197,     0,   198,   199,
       0,   200,     0,   201,     0,     0,   202,     0,  -138,   204,
       0,     0,   195,   205,     0,   196,   330,   268,   198,   199,
       0,   269,   270,     0,     0,     0,   202,   303,   353,   305,
     451,   449,   354,   205,    15,  -144,     0,   100,    16,   -58,
     -58,   -58,    89,    90,    94,     0,   195,  -144,     0,   196,
     213,   268,   198,   199,   303,   269,   270,    17,     0,     0,
     202,     0,  -144,   305,     0,    86,     0,   205,    32,   -29,
     -29,   -29,   -29,   195,   303,     0,   196,   213,   268,   198,
     199,     0,   269,   270,     0,     0,     0,   202,    87,     0,
     305,   395,   396,   195,   205,     0,   196,   213,   268,   198,
     199,   303,   269,   270,     0,     0,     0,   202,     0,     0,
     305,   441,   379,     0,   205,     0,     0,     0,     0,     0,
     195,   303,     0,   196,   213,   268,   198,   199,     0,   269,
     270,     0,     0,     0,   202,     0,     0,   305,   454,   379,
     195,   205,     0,   196,   213,   268,   198,   199,   303,   269,
     270,     0,     0,     0,   202,     0,     0,   305,   486,   379,
       0,   205,     0,     0,     0,     0,     0,   195,   303,     0,
     196,   213,   268,   198,   199,     0,   269,   270,     0,     0,
       0,   202,     0,     0,   305,   395,   379,   195,   205,     0,
     196,   213,   268,   198,   199,   303,   269,   270,     0,     0,
       0,   202,     0,     0,   305,   500,   379,   304,   205,     0,
       0,     0,     0,     0,   195,   303,     0,   196,   213,   268,
     198,   199,     0,   269,   270,     0,     0,     0,   202,     0,
     326,   305,     0,     0,   195,   205,     0,   196,   213,   268,
     198,   199,   303,   269,   270,     0,     0,     0,   202,     0,
       0,   305,     0,    13,     0,   205,     6,   -32,   -32,   -32,
     -32,   195,   303,     0,   196,   213,   268,   198,   199,     0,
     269,   270,     0,     0,     0,   202,   510,     0,   305,   395,
       0,   195,   205,     0,   196,   213,   268,   198,   199,   303,
     269,   270,     0,     0,   102,   202,     0,     0,   305,    89,
      90,    94,   205,     0,   550,     0,     0,     0,   195,     0,
       0,   196,   213,   268,   198,   199,     0,   269,   270,   143,
       0,     0,   202,    65,     0,   305,    94,  -173,     0,   205,
     144,     0,   145,     0,     0,   146,   147,   148,     0,     0,
     322,     0,   157,     0,     0,    66,     0,     0,    67,    68,
       0,    69,     0,     0,    62,    70,    71,    63,    64,   195,
       0,   283,   196,   213,     0,   198,   199,     0,   200,  -171,
       0,     0,     0,   202,     0,     0,   214,  -187,  -187,     0,
     195,  -171,   283,   196,   213,     0,   198,   199,     0,   200,
    -198,     0,     0,     0,   202,     0,  -171,   214,     0,     0,
       0,   195,  -198,     0,   196,   213,     0,   198,   199,   329,
     200,     0,     0,   251,     0,   202,     0,  -198,   214,     0,
       0,   332,     0,     0,     0,   251,     0,     0,   195,     0,
       0,   196,   330,   322,   198,   199,     0,   200,     0,  -187,
     195,     0,   202,   196,   330,   214,   198,   199,   212,   200,
       0,     0,   195,     0,   202,   196,   213,   214,   198,   199,
     223,   200,     0,  -187,     0,     0,   202,   195,     0,   214,
     196,   213,   275,   198,   199,     0,   200,     0,     0,   195,
       0,   202,   196,   213,   214,   198,   199,   277,   200,     0,
       0,   195,     0,   202,   196,   213,   214,   198,   199,   283,
     200,     0,     0,     0,     0,   202,   195,     0,   214,   196,
     213,   287,   198,   199,     0,   200,     0,     0,   195,     0,
     202,   196,   213,   214,   198,   199,   292,   200,     0,     0,
     195,     0,   202,   196,   213,   214,   198,   199,   309,   200,
       0,     0,     0,     0,   202,   195,     0,   214,   196,   213,
     322,   198,   199,     0,   200,     0,     0,   195,     0,   202,
     196,   213,   214,   198,   199,   324,   200,     0,     0,   195,
       0,   202,   196,   213,   214,   198,   199,   338,   200,     0,
       0,     0,     0,   202,   195,     0,   214,   196,   213,   340,
     198,   199,     0,   200,     0,     0,   195,     0,   202,   196,
     213,   214,   198,   199,   380,   200,     0,     0,   195,     0,
     202,   196,   213,   214,   198,   199,   382,   200,     0,     0,
       0,     0,   202,   195,     0,   214,   196,   213,   393,   198,
     199,     0,   200,     0,     0,   195,     0,   202,   196,   213,
     214,   198,   199,   411,   200,     0,     0,   195,     0,   202,
     196,   213,   214,   198,   199,   413,   200,     0,     0,     0,
       0,   202,   195,     0,   214,   196,   213,   416,   198,   199,
       0,   200,     0,     0,   195,     0,   202,   196,   213,   214,
     198,   199,   421,   200,     0,     0,   195,     0,   202,   196,
     213,   214,   198,   199,   424,   200,     0,     0,     0,     0,
     202,   195,     0,   214,   196,   213,   431,   198,   199,     0,
     200,     0,     0,   195,     0,   202,   196,   213,   214,   198,
     199,   482,   200,     0,     0,   195,     0,   202,   196,   213,
     214,   198,   199,   283,   200,     0,     0,     0,     0,   202,
     195,     0,   214,   196,   213,   537,   198,   199,     0,   200,
       0,     0,   195,     0,   202,   196,   514,   214,   198,   199,
       0,   200,     0,     0,   195,     0,   202,   196,   213,   214,
     198,   199,   285,   200,     0,     0,     0,     0,   202,    94,
    -134,   214,     0,   144,     0,   145,   143,     0,   146,   147,
     148,     0,  -134,    94,  -173,   157,     0,   144,     0,   145,
       0,     0,   146,   147,   148,     0,  -134,  -134,     0,   149,
       0,   285,     0,     0,     0,     0,     0,     0,    94,  -173,
     -21,   150,   144,     0,   145,   427,     0,   146,   147,   148,
       0,  -173,    94,  -173,   157,     0,   144,     0,   145,     0,
       0,   146,   147,   148,     0,  -173,  -173,     0,   157,     0,
     446,     0,     0,     0,     0,     0,     0,    94,  -173,     0,
    -173,   144,     0,   145,   530,     0,   146,   147,   148,     0,
    -173,    94,  -173,   157,     0,   144,     0,   145,     0,     0,
     146,   147,   148,     0,  -173,  -173,     0,   157,     0,   285,
       0,     0,     0,     0,     0,     0,    94,  -153,     0,  -173,
     144,     0,   145,   560,     0,   146,   147,   148,     0,  -153,
      94,  -173,   157,     0,   144,     0,   145,     0,     0,   146,
     147,   148,     0,  -173,  -153,    86,   157,     0,   143,   -28,
     -28,   -28,   -28,     0,     0,    94,  -173,     0,  -173,   144,
       0,   145,   156,     0,   146,   147,   148,     0,    87,    94,
    -173,   149,     0,   144,     0,   145,     0,     0,   146,   147,
     148,     0,   143,   150,     0,   157,     0,     0,     0,    94,
    -173,     0,     0,   144,     0,   145,   285,  -173,   146,   147,
     148,     0,     0,    94,  -173,   149,     0,   144,     0,   145,
       0,     0,   146,   147,   148,     0,   335,  -173,     0,   157,
       0,     0,     0,    94,  -173,     0,     0,   144,     0,   145,
     143,  -173,   146,   147,   148,     0,     0,    94,  -173,   157,
       0,   144,     0,   145,     0,     0,   146,   147,   148,    83,
     143,  -173,     0,   157,     0,     0,     0,    94,  -173,     0,
       0,   144,   180,   145,     0,  -173,   146,   147,   148,     0,
       0,    66,     0,   157,    67,    68,     0,    69,     0,     0,
       0,    70,    71,     0,    66,  -130,     0,    67,    68,     0,
      69,     0,     0,     5,    70,    71,     6,   -32,   -32,   -32,
     -32,    52,     0,     0,    -9,    -9,    -9,    -9,    -9,     0,
       0,     0,     0,     0,     0,     0,     7,     0,     0,     0,
       0,     0,     0,     0,    36
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-244)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      93,    94,   183,   149,     1,    48,     1,   100,     9,   102,
       1,   157,    55,    56,    57,     1,    24,   143,   144,    15,
      16,    74,   148,    76,     1,     1,   269,    23,    36,    25,
     156,     1,    28,    29,    31,    31,     1,   250,   251,   259,
     260,   261,   262,   263,   257,   226,    41,    38,     1,     1,
     143,   197,    38,    39,   297,   298,    42,   300,     1,     1,
      36,    38,    39,   156,     1,    42,    62,   213,   194,    39,
      40,    43,    44,    38,    39,   201,     1,    42,   204,   205,
       0,    77,    78,    79,    80,    81,    39,    39,   214,    42,
      42,     1,     1,    36,    37,   221,   222,    40,    40,   225,
     226,   194,    39,    40,     1,   231,   232,     1,   234,   235,
     203,   204,     1,     1,    39,   168,   329,    42,    35,   332,
     173,   174,   175,   176,     1,     1,   219,   220,     1,    39,
      39,     1,    42,    42,   354,   228,     1,   230,   358,   359,
      37,   267,    36,   236,     1,   271,    22,    36,     5,    38,
     122,    39,    40,   279,   280,   281,     1,     1,    35,   285,
     132,   133,   134,   135,    37,     1,    31,    24,    38,    39,
       1,   317,     1,     9,   267,     1,    24,   303,   271,   305,
      24,   307,   308,    40,   330,    21,     1,   313,   314,   315,
     191,   192,   285,    38,    39,    31,    41,    26,    27,   268,
      36,    37,   295,   296,   203,    41,     1,    38,    39,   335,
      41,   304,    38,    39,     9,    41,     1,     1,   311,   312,
      24,   264,   265,   266,    39,    40,    21,     1,   297,   228,
     299,   230,     1,   326,   327,   328,   479,   236,     1,     1,
      25,    36,   335,   463,   464,   465,   466,   467,   468,     1,
       1,     1,    39,   379,    38,    39,   469,    41,    10,     9,
       1,   387,   388,   476,    38,    39,    28,    41,    37,   265,
     396,    40,    24,     1,    37,     1,    28,    40,   404,     5,
     373,    31,   375,     1,   377,    24,    36,    37,    39,    40,
      40,    41,   418,     1,     1,    36,   295,   296,    24,     1,
       1,   427,     1,   396,   397,   304,   399,   433,    36,   435,
      36,     1,   311,   312,    40,     1,   442,     1,    36,    37,
     446,    28,   448,   449,    26,     1,   452,   326,   327,   328,
      16,    39,    40,     1,   427,    27,     1,    38,    39,    38,
      39,   434,     1,    11,     9,   438,    36,    37,    13,    25,
       1,    16,     1,   446,    38,    39,    21,     1,    23,   485,
      25,   487,     6,     7,    29,    30,    31,     1,   514,     3,
       1,    36,    37,    38,    39,   501,    41,    42,   504,    38,
      39,     1,   508,   509,   510,   511,   512,    38,    39,    38,
      39,    24,    36,     1,     1,    39,    40,   204,   205,     1,
       1,   494,   495,    10,   530,    36,    37,     1,     1,     1,
      25,   504,     1,   506,   221,   222,    36,     9,   225,   226,
      28,    28,    15,    24,    26,     1,    20,   234,   235,    23,
      24,    25,    26,    27,   560,    29,    30,   530,     1,     1,
      34,     1,    36,    37,    38,    39,    40,    41,    42,    38,
      39,     1,   545,   546,   547,   548,   549,   550,   551,   552,
       1,    24,    38,    39,   271,     1,    28,   560,     1,     1,
       1,     1,   279,    36,   281,    38,    39,    40,    38,    39,
       1,   194,   195,   196,    36,    26,    25,   200,    38,    39,
       1,    24,    13,    24,    26,   494,   495,    28,   305,   212,
     307,   308,    38,    39,     1,   504,    25,   506,    38,    39,
     223,     8,     9,    24,    25,    12,    13,    14,    36,    16,
      17,    18,    19,    20,    21,    36,    23,    24,    25,    26,
      27,     1,    29,    30,    31,     1,     1,    34,    24,    36,
      37,    38,    39,     1,    41,    42,   545,   546,   547,   548,
     549,   550,   551,   552,   267,     1,   269,   270,     1,     1,
       1,    26,   275,     1,   277,     8,    41,     9,    38,    39,
     283,     9,    38,    39,   287,    13,    22,    15,    16,   292,
      38,    39,     1,    21,    36,    23,     5,    25,   301,   302,
     303,    29,    30,     1,    36,    36,   309,    38,    36,    37,
      38,    39,    36,    41,    42,    24,     1,     1,     1,   322,
      36,   324,     5,     1,     1,     8,   329,    36,    36,   332,
      40,     9,     9,     1,    40,   338,    13,   340,    15,    16,
      38,    39,    13,    20,    21,    16,    23,    24,    25,    26,
      27,    36,    29,    30,    38,    39,    24,    34,    36,    36,
      37,    38,    39,    38,    41,    42,     1,    38,    36,    11,
      38,    39,    40,     1,     9,     1,     1,   380,    13,   382,
      15,    16,    10,     8,    26,    20,    21,     1,    23,    24,
     393,    26,    27,     1,    29,    30,    10,     1,    24,    34,
      28,    36,    37,    38,    39,     9,    41,    42,   411,     1,
     413,     1,    22,   416,    28,   418,    24,    21,   421,     9,
      24,   424,    31,    13,    16,    15,    16,     1,   431,    39,
      20,    21,    36,    23,    24,    25,    26,    27,     1,    29,
      30,     1,     5,    26,    34,   448,    36,    37,    38,    39,
      24,    41,    42,    26,     1,     1,    25,    13,     1,    26,
      16,    24,     9,     9,    24,    26,     9,    36,     1,    11,
      13,    11,    15,    16,    21,    21,     9,    20,    21,   482,
      23,    24,    25,    26,    27,     1,    29,    30,    21,    36,
      36,    34,     1,    36,    37,    38,    39,    11,    41,    42,
       9,   504,    22,    36,    13,    15,    15,    16,    24,    36,
      37,    20,    21,     1,    23,    24,    25,    26,    27,    39,
      29,    30,    42,     1,    15,    34,    15,    36,    37,    38,
      39,     9,    41,    42,   537,    13,    24,    15,    16,    22,
       1,    22,    20,    21,     5,    23,    24,    25,    26,    27,
      22,    29,    30,    31,     1,    26,    34,    26,    36,    37,
      38,    39,     9,    24,    42,     1,    13,    26,    15,    16,
       6,     7,     8,    20,    21,     1,    23,    24,    25,    26,
      27,    26,    29,    30,    16,     1,    21,    34,    24,    36,
      37,    38,    39,     9,    41,    42,     1,    16,    24,    15,
      16,     6,     7,     8,    20,    21,     1,    23,    24,    25,
      26,    27,    16,    29,    30,    16,     1,    16,    34,    24,
      36,    37,    38,    39,     9,    41,    42,     1,    13,    24,
      15,    16,     6,     7,     8,    20,    21,     4,    23,    24,
      25,    26,    27,   142,    29,    30,     6,     1,    16,    34,
      24,    36,    37,    38,    39,     9,     1,    42,     1,    13,
       5,    15,    16,     6,     7,     8,    20,    21,    -1,    23,
      24,    25,    26,    27,    94,    29,    30,    -1,     1,    24,
      34,    24,    36,    37,    38,    39,     9,     1,    42,     1,
      13,     5,    -1,    16,     6,     7,     8,    20,    21,     1,
      23,    24,    25,    26,    27,     1,    29,    30,    36,    37,
      24,    34,    24,    36,    37,    38,    39,    13,    -1,    42,
      16,    -1,    24,    -1,    20,     1,    -1,    23,    24,    25,
      26,    27,     1,    29,    30,    31,     5,    -1,    34,     8,
      -1,    37,    38,    39,    20,     1,    42,    23,    24,    25,
      26,    27,     1,    29,    30,    24,    38,    39,    34,     1,
       1,    37,    38,    39,    40,    41,    42,     8,    24,    26,
      27,    20,     1,    -1,    23,    24,    25,    26,    27,     1,
      29,    30,    24,    24,    -1,    34,    -1,     9,    37,    38,
      39,    20,    41,    42,    23,    24,    25,    26,    27,    21,
      29,    30,    -1,     1,    -1,    34,    39,    40,    37,    38,
      39,     9,    41,    42,    36,    13,    -1,    15,    16,    -1,
      39,    40,   353,    21,     1,    23,    -1,    25,    48,   360,
     361,    29,    30,   364,    -1,    55,    -1,    57,    36,     9,
      38,    39,    -1,    20,    42,    15,    23,    24,    25,    26,
      27,    21,    29,    30,    -1,     1,    -1,    34,    25,    26,
      37,    -1,    39,     9,    41,    42,    36,    13,     1,    15,
      16,   170,   171,    -1,     1,    21,     9,    23,    -1,    25,
      -1,     1,    -1,    29,    30,    -1,     1,    -1,    21,    -1,
      36,    -1,    38,    39,     9,    -1,    42,    24,    13,    -1,
      15,    16,    -1,    36,    24,    -1,    21,    -1,    23,    36,
      25,    38,    39,    40,    29,    30,    36,     1,    38,    39,
      40,    36,    -1,    38,    39,     9,    -1,    42,   420,    13,
      -1,    15,    16,    -1,   426,   427,   428,    21,    -1,    23,
      -1,    25,   219,   220,     1,    29,    30,    -1,     1,     6,
       7,     8,    36,    -1,    38,    39,     9,    -1,    42,     1,
      13,    -1,    15,    16,     6,     7,     8,    -1,    21,    -1,
      23,    -1,    25,    -1,    -1,     1,    29,    30,    -1,     1,
       6,     7,     8,    36,    -1,    38,    39,     9,    -1,    42,
       1,    13,    36,    15,    16,    39,    40,    -1,     9,    21,
      -1,    23,    13,    25,    15,    16,    -1,    29,    -1,    -1,
      21,    -1,    23,    -1,    36,    -1,    38,    39,    29,    30,
      42,     1,    -1,    -1,    -1,    36,    -1,    38,    39,     9,
      -1,    42,     1,    13,    36,    15,    16,    39,    40,    -1,
       9,    21,    -1,    23,    13,     1,    15,    16,    -1,    29,
       6,     7,    21,    -1,    23,    -1,    36,    -1,    38,    39,
      29,     1,    42,     1,     4,     5,    -1,    36,     8,    38,
      39,     9,    -1,    42,    -1,    13,    -1,    15,    16,    -1,
      -1,     1,     1,    21,    -1,    23,     5,     6,     7,     8,
      -1,    29,     1,    13,    -1,    -1,    16,    -1,    36,    -1,
      38,    39,    -1,    23,    42,    25,    -1,    -1,    -1,    29,
      30,    31,     1,    -1,    23,    -1,    25,    -1,    38,    39,
      29,    30,    42,   137,   138,   139,   140,    -1,    37,    38,
      39,    40,    41,    42,    23,    -1,    25,    -1,     1,    -1,
      29,    30,     5,     6,     7,     8,    -1,     1,    37,    38,
      39,    40,    41,    42,     8,     9,    -1,    -1,    12,    13,
      14,    24,    16,    17,    18,    19,    20,    21,    -1,    23,
      24,    25,    26,    27,    -1,    29,    30,    31,     1,    -1,
      34,    -1,    36,    37,    -1,     8,     9,    41,    -1,    12,
      13,    14,    -1,    16,    17,    18,    19,    20,    -1,    -1,
      23,    24,    25,    26,    27,    -1,    29,    30,    31,     1,
      -1,    34,    -1,    36,    37,    -1,     8,     9,    41,    -1,
      12,    -1,    14,    -1,    -1,    17,    18,    19,    20,    21,
      -1,    23,    24,    -1,    26,    27,    -1,    29,    -1,    31,
       1,    -1,    34,    -1,    36,    37,    -1,     8,     9,    41,
      -1,    12,    -1,    14,    -1,    -1,    17,    18,    19,    20,
      21,    -1,    23,    24,    -1,    26,    27,    -1,    29,    -1,
      31,     1,    -1,    34,    -1,    36,    37,    -1,     8,     9,
      41,    -1,    12,    -1,    14,    -1,    -1,    17,    18,    19,
      20,    -1,    -1,    23,    24,    -1,    26,    27,    -1,    29,
      -1,    31,     1,    -1,    34,    -1,    36,    37,    -1,     8,
       9,    41,    -1,    12,    -1,    14,    -1,    -1,    17,    18,
      19,    20,    -1,    -1,    23,    24,    -1,    26,    27,    -1,
      29,    -1,    31,     1,    -1,    34,    -1,    36,    37,    -1,
       8,     9,    41,    -1,    12,    -1,    14,    -1,    -1,    17,
      18,    19,    20,     1,    -1,    23,    24,    -1,    26,    27,
      -1,    29,    -1,    31,    -1,    -1,    34,    -1,    36,    37,
      -1,    -1,    20,    41,    -1,    23,    24,    25,    26,    27,
      -1,    29,    30,    -1,    -1,    -1,    34,     1,    36,    37,
      38,    39,    40,    41,     1,     9,    -1,     1,     5,     6,
       7,     8,     6,     7,     8,    -1,    20,    21,    -1,    23,
      24,    25,    26,    27,     1,    29,    30,    24,    -1,    -1,
      34,    -1,    36,    37,    -1,     1,    -1,    41,    35,     5,
       6,     7,     8,    20,     1,    -1,    23,    24,    25,    26,
      27,    -1,    29,    30,    -1,    -1,    -1,    34,    24,    -1,
      37,    38,    39,    20,    41,    -1,    23,    24,    25,    26,
      27,     1,    29,    30,    -1,    -1,    -1,    34,    -1,    -1,
      37,    38,    39,    -1,    41,    -1,    -1,    -1,    -1,    -1,
      20,     1,    -1,    23,    24,    25,    26,    27,    -1,    29,
      30,    -1,    -1,    -1,    34,    -1,    -1,    37,    38,    39,
      20,    41,    -1,    23,    24,    25,    26,    27,     1,    29,
      30,    -1,    -1,    -1,    34,    -1,    -1,    37,    38,    39,
      -1,    41,    -1,    -1,    -1,    -1,    -1,    20,     1,    -1,
      23,    24,    25,    26,    27,    -1,    29,    30,    -1,    -1,
      -1,    34,    -1,    -1,    37,    38,    39,    20,    41,    -1,
      23,    24,    25,    26,    27,     1,    29,    30,    -1,    -1,
      -1,    34,    -1,    -1,    37,    38,    39,    13,    41,    -1,
      -1,    -1,    -1,    -1,    20,     1,    -1,    23,    24,    25,
      26,    27,    -1,    29,    30,    -1,    -1,    -1,    34,    -1,
      16,    37,    -1,    -1,    20,    41,    -1,    23,    24,    25,
      26,    27,     1,    29,    30,    -1,    -1,    -1,    34,    -1,
      -1,    37,    -1,     1,    -1,    41,     4,     5,     6,     7,
       8,    20,     1,    -1,    23,    24,    25,    26,    27,    -1,
      29,    30,    -1,    -1,    -1,    34,    15,    -1,    37,    38,
      -1,    20,    41,    -1,    23,    24,    25,    26,    27,     1,
      29,    30,    -1,    -1,     1,    34,    -1,    -1,    37,     6,
       7,     8,    41,    -1,    16,    -1,    -1,    -1,    20,    -1,
      -1,    23,    24,    25,    26,    27,    -1,    29,    30,     1,
      -1,    -1,    34,     1,    -1,    37,     8,     9,    -1,    41,
      12,    -1,    14,    -1,    -1,    17,    18,    19,    -1,    -1,
       1,    -1,    24,    -1,    -1,    23,    -1,    -1,    26,    27,
      -1,    29,    -1,    -1,    36,    33,    34,    39,    40,    20,
      -1,     1,    23,    24,    -1,    26,    27,    -1,    29,     9,
      -1,    -1,    -1,    34,    -1,    -1,    37,    38,    39,    -1,
      20,    21,     1,    23,    24,    -1,    26,    27,    -1,    29,
       9,    -1,    -1,    -1,    34,    -1,    36,    37,    -1,    -1,
      -1,    20,    21,    -1,    23,    24,    -1,    26,    27,     1,
      29,    -1,    -1,     5,    -1,    34,    -1,    36,    37,    -1,
      -1,     1,    -1,    -1,    -1,     5,    -1,    -1,    20,    -1,
      -1,    23,    24,     1,    26,    27,    -1,    29,    -1,    31,
      20,    -1,    34,    23,    24,    37,    26,    27,     1,    29,
      -1,    -1,    20,    -1,    34,    23,    24,    37,    26,    27,
       1,    29,    -1,    31,    -1,    -1,    34,    20,    -1,    37,
      23,    24,     1,    26,    27,    -1,    29,    -1,    -1,    20,
      -1,    34,    23,    24,    37,    26,    27,     1,    29,    -1,
      -1,    20,    -1,    34,    23,    24,    37,    26,    27,     1,
      29,    -1,    -1,    -1,    -1,    34,    20,    -1,    37,    23,
      24,     1,    26,    27,    -1,    29,    -1,    -1,    20,    -1,
      34,    23,    24,    37,    26,    27,     1,    29,    -1,    -1,
      20,    -1,    34,    23,    24,    37,    26,    27,     1,    29,
      -1,    -1,    -1,    -1,    34,    20,    -1,    37,    23,    24,
       1,    26,    27,    -1,    29,    -1,    -1,    20,    -1,    34,
      23,    24,    37,    26,    27,     1,    29,    -1,    -1,    20,
      -1,    34,    23,    24,    37,    26,    27,     1,    29,    -1,
      -1,    -1,    -1,    34,    20,    -1,    37,    23,    24,     1,
      26,    27,    -1,    29,    -1,    -1,    20,    -1,    34,    23,
      24,    37,    26,    27,     1,    29,    -1,    -1,    20,    -1,
      34,    23,    24,    37,    26,    27,     1,    29,    -1,    -1,
      -1,    -1,    34,    20,    -1,    37,    23,    24,     1,    26,
      27,    -1,    29,    -1,    -1,    20,    -1,    34,    23,    24,
      37,    26,    27,     1,    29,    -1,    -1,    20,    -1,    34,
      23,    24,    37,    26,    27,     1,    29,    -1,    -1,    -1,
      -1,    34,    20,    -1,    37,    23,    24,     1,    26,    27,
      -1,    29,    -1,    -1,    20,    -1,    34,    23,    24,    37,
      26,    27,     1,    29,    -1,    -1,    20,    -1,    34,    23,
      24,    37,    26,    27,     1,    29,    -1,    -1,    -1,    -1,
      34,    20,    -1,    37,    23,    24,     1,    26,    27,    -1,
      29,    -1,    -1,    20,    -1,    34,    23,    24,    37,    26,
      27,     1,    29,    -1,    -1,    20,    -1,    34,    23,    24,
      37,    26,    27,     1,    29,    -1,    -1,    -1,    -1,    34,
      20,    -1,    37,    23,    24,     1,    26,    27,    -1,    29,
      -1,    -1,    20,    -1,    34,    23,    24,    37,    26,    27,
      -1,    29,    -1,    -1,    20,    -1,    34,    23,    24,    37,
      26,    27,     1,    29,    -1,    -1,    -1,    -1,    34,     8,
       9,    37,    -1,    12,    -1,    14,     1,    -1,    17,    18,
      19,    -1,    21,     8,     9,    24,    -1,    12,    -1,    14,
      -1,    -1,    17,    18,    19,    -1,    35,    36,    -1,    24,
      -1,     1,    -1,    -1,    -1,    -1,    -1,    -1,     8,     9,
      35,    36,    12,    -1,    14,     1,    -1,    17,    18,    19,
      -1,    21,     8,     9,    24,    -1,    12,    -1,    14,    -1,
      -1,    17,    18,    19,    -1,    21,    36,    -1,    24,    -1,
       1,    -1,    -1,    -1,    -1,    -1,    -1,     8,     9,    -1,
      36,    12,    -1,    14,     1,    -1,    17,    18,    19,    -1,
      21,     8,     9,    24,    -1,    12,    -1,    14,    -1,    -1,
      17,    18,    19,    -1,    21,    36,    -1,    24,    -1,     1,
      -1,    -1,    -1,    -1,    -1,    -1,     8,     9,    -1,    36,
      12,    -1,    14,     1,    -1,    17,    18,    19,    -1,    21,
       8,     9,    24,    -1,    12,    -1,    14,    -1,    -1,    17,
      18,    19,    -1,    21,    36,     1,    24,    -1,     1,     5,
       6,     7,     8,    -1,    -1,     8,     9,    -1,    36,    12,
      -1,    14,     1,    -1,    17,    18,    19,    -1,    24,     8,
       9,    24,    -1,    12,    -1,    14,    -1,    -1,    17,    18,
      19,    -1,     1,    36,    -1,    24,    -1,    -1,    -1,     8,
       9,    -1,    -1,    12,    -1,    14,     1,    36,    17,    18,
      19,    -1,    -1,     8,     9,    24,    -1,    12,    -1,    14,
      -1,    -1,    17,    18,    19,    -1,     1,    36,    -1,    24,
      -1,    -1,    -1,     8,     9,    -1,    -1,    12,    -1,    14,
       1,    36,    17,    18,    19,    -1,    -1,     8,     9,    24,
      -1,    12,    -1,    14,    -1,    -1,    17,    18,    19,     1,
       1,    36,    -1,    24,    -1,    -1,    -1,     8,     9,    -1,
      -1,    12,     1,    14,    -1,    36,    17,    18,    19,    -1,
      -1,    23,    -1,    24,    26,    27,    -1,    29,    -1,    -1,
      -1,    33,    34,    -1,    23,    36,    -1,    26,    27,    -1,
      29,    -1,    -1,     1,    33,    34,     4,     5,     6,     7,
       8,     1,    -1,    -1,     4,     5,     6,     7,     8,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    24,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    24
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     3,    44,    45,     1,     4,    24,    46,    48,
       1,    24,     0,     1,    46,     1,     5,    24,    49,    51,
       1,    49,    36,    37,    35,     1,    51,    36,    37,     1,
      36,    37,    35,     1,    35,     1,    24,    25,    36,    47,
      52,     1,    52,     1,    25,     1,    36,     1,    56,    36,
       1,    36,     1,    47,     1,    56,     1,    56,    47,    47,
       1,    47,    36,    39,    40,     1,    23,    26,    27,    29,
      33,    34,    50,    24,     1,    39,    40,     1,    36,    36,
       1,    36,    50,     1,    50,    24,     1,    24,     1,     6,
       7,    57,    58,     1,     8,    57,    65,     1,    38,    65,
       1,    65,     1,    65,    38,    38,    38,     1,    38,    47,
      24,     1,    10,    28,    53,    54,    27,    26,    27,     1,
      26,    27,    25,    24,    53,     1,    24,     1,    53,    47,
       1,    47,    25,    25,     1,    25,    24,     1,    24,     1,
      24,    36,    36,     1,    12,    14,    17,    18,    19,    24,
      36,    65,    66,    67,    69,    71,     1,    24,    66,     1,
      36,    36,    36,    36,    36,    36,     1,    36,    40,    41,
       1,    41,    50,    40,    40,     1,    40,    50,    50,    50,
       1,    50,     1,    37,    59,    59,     1,    59,    59,     1,
      59,     1,    48,    64,     1,    20,    23,    24,    26,    27,
      29,    31,    34,    36,    37,    41,    69,    70,    74,    75,
      76,    77,     1,    24,    37,    69,    74,     1,    24,     1,
      37,     1,    37,     1,    74,     1,    37,    70,     1,     9,
      36,     1,    31,     9,     1,    37,     1,     9,    53,     1,
      26,    55,    55,     1,    55,    53,    53,    53,     1,    53,
       1,     5,    47,    60,    61,    62,    63,     1,    60,    40,
      40,    40,     1,    40,    51,     1,    51,     1,    25,    29,
      30,    37,    73,    74,    77,     1,    77,     1,    77,     1,
      31,    37,    77,     1,    74,     1,    67,     1,    68,    69,
      73,    74,     1,    73,    74,    13,    16,     1,    23,    25,
      29,     1,    30,     1,    13,    37,    74,     1,    37,     1,
      74,     1,    13,    31,     1,    31,     1,    24,    68,    69,
       1,    68,     1,    73,     1,    73,    16,     1,    16,     1,
      24,    73,     1,    73,    67,     1,    67,    74,     1,    74,
       1,    22,    39,     1,    22,     1,    39,    42,    42,    42,
       1,    42,     1,    36,    40,    63,     1,    63,     1,    40,
       1,    36,    38,    38,     1,    38,     1,    54,    54,    54,
      54,     1,    54,     1,    65,     1,    65,     1,    65,    39,
       1,    75,     1,    76,    77,    77,    73,     1,    39,    42,
      38,    73,    74,     1,    73,    38,    39,     1,    38,    39,
      38,     1,    38,    42,     1,    42,    67,    67,    75,    76,
      76,     1,    75,     1,    76,    77,     1,    77,     1,    74,
      67,     1,    73,    73,     1,    73,    67,     1,    67,    74,
      74,     1,    74,     1,    39,     1,    38,    38,     1,    38,
      38,    38,     1,    38,    67,    67,     1,    67,     1,    39,
      38,    38,     1,    38,    38,    26,    26,    26,     1,    26,
      26,     1,    26,    11,    11,    11,    11,     1,    11,     1,
      61,    54,    54,     1,    54,    61,     1,    61,    74,     1,
      38,    74,     1,    74,    38,    15,    38,     1,    38,    69,
       1,    69,     1,    69,     1,    21,    72,    72,    38,    38,
      38,     1,    38,    72,     1,    72,     1,    72,    15,    15,
      15,     1,    15,    69,    24,    22,    22,    22,     1,    22,
      54,    54,    54,    54,    54,     1,    54,    76,    74,    67,
       1,    67,    67,    74,    74,    74,    74,     1,    74,    26,
      26,    26,    26,     1,    26,    16,    16,    16,    16,    16,
      16,     1,    16,    67,    67,    67,    67,    67,    67,    67,
       1,    67
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

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
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */
#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
        break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
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

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
        break;
    }
}




/* The lookahead symbol.  */
int yychar;


#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

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
      yychar = YYLEX;
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
     `$$ = $1'.

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
/* Line 1792 of yacc.c  */
#line 30 "yacc.y"
    {
	BitNode *Node3 = new BitNode(yycolumn,yylineno,".", "SEPARATOR");

	root = new BitNode(yycolumn,yylineno,"","programstruct");
	root->insertChild((yyvsp[(1) - (3)].BITNODE));
        root->insertChild((yyvsp[(2) - (3)].BITNODE));
        root->insertChild(Node3);

	cout << "programstruct -> program_head program_body . [OK]" << endl;
	cout << "Parse OK!" << endl;
        (yyval.BITNODE) = root;
}
    break;

  case 3:
/* Line 1792 of yacc.c  */
#line 42 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 4:
/* Line 1792 of yacc.c  */
#line 48 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 5:
/* Line 1792 of yacc.c  */
#line 54 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 6:
/* Line 1792 of yacc.c  */
#line 59 "yacc.y"
    {
	BitNode *newNode, *Node1, *Node2, *Node3;
       	Node1 = new BitNode(yycolumn,yylineno,(yyvsp[(1) - (3)].TYPE)->token, "PROGRAM");
       	Node2 = new BitNode(yycolumn,yylineno,(yyvsp[(2) - (3)].TYPE)->token, "ID");
       	Node3 = new BitNode(yycolumn,yylineno,";", "SEPARATOR");
       	newNode = new BitNode(yycolumn,yylineno,"", "program_head");

       	newNode->insertChild(Node1);
       	newNode->insertChild(Node2);
       	newNode->insertChild(Node3);

       	cout<<"program_head -> program id ; [OK]"<<endl;
       	(yyval.BITNODE) = newNode;
}
    break;

  case 7:
/* Line 1792 of yacc.c  */
#line 72 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 8:
/* Line 1792 of yacc.c  */
#line 78 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 9:
/* Line 1792 of yacc.c  */
#line 84 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 10:
/* Line 1792 of yacc.c  */
#line 88 "yacc.y"
    {
        BitNode *newNode, *Node1, *Node2, *Node3, *Node5, *Node6;
        newNode = new BitNode(yycolumn,yylineno,"", "program_head");
        Node1 = new BitNode(yycolumn,yylineno,(yyvsp[(1) - (6)].TYPE)->token, "PROGRAM");
        Node2 = new BitNode(yycolumn,yylineno,(yyvsp[(2) - (6)].TYPE)->token, "ID");
        Node3 = new BitNode(yycolumn,yylineno,"(", "SEPARATOR");
        Node5 = new BitNode(yycolumn,yylineno,")", "SEPARATOR");
        Node6 = new BitNode(yycolumn,yylineno,";", "SEPARATOR");

	newNode->insertChild(Node1);
	newNode->insertChild(Node2);
	newNode->insertChild(Node3);
	newNode->insertChild((yyvsp[(4) - (6)].BITNODE));
        newNode->insertChild(Node5);
        newNode->insertChild(Node6);

        cout<<"program_head -> program id ( idlist ) ; [OK]"<<endl;
	(yyval.BITNODE) = newNode;
}
    break;

  case 11:
/* Line 1792 of yacc.c  */
#line 107 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 12:
/* Line 1792 of yacc.c  */
#line 113 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 13:
/* Line 1792 of yacc.c  */
#line 119 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 14:
/* Line 1792 of yacc.c  */
#line 125 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 15:
/* Line 1792 of yacc.c  */
#line 131 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 16:
/* Line 1792 of yacc.c  */
#line 137 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 17:
/* Line 1792 of yacc.c  */
#line 142 "yacc.y"
    {
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "program_body");

	newNode->insertChild((yyvsp[(1) - (4)].BITNODE));
	newNode->insertChild((yyvsp[(2) - (4)].BITNODE));
	newNode->insertChild((yyvsp[(3) - (4)].BITNODE));
	newNode->insertChild((yyvsp[(4) - (4)].BITNODE));

	cout<<"program_body -> const_declarations var_declarationssubprogram_declarations compound_statement [OK]"<<endl;
	(yyval.BITNODE) = newNode;
}
    break;

  case 18:
/* Line 1792 of yacc.c  */
#line 153 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 19:
/* Line 1792 of yacc.c  */
#line 159 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 20:
/* Line 1792 of yacc.c  */
#line 165 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 21:
/* Line 1792 of yacc.c  */
#line 171 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 22:
/* Line 1792 of yacc.c  */
#line 176 "yacc.y"
    {
	BitNode *newNode, *Node2, *Node3;
	newNode = new BitNode(yycolumn,yylineno,"", "idlist");
	Node2 = new BitNode(yycolumn,yylineno,",", "SEPARATOR");
	Node3 = new BitNode(yycolumn,yylineno,(yyvsp[(3) - (3)].TYPE)->token, "ID");

	newNode->insertChild((yyvsp[(1) - (3)].BITNODE));
	newNode->insertChild(Node2);
	newNode->insertChild(Node3);

	cout<<"idlist -> idlist , id [OK]"<<endl;
	(yyval.BITNODE) = newNode;
}
    break;

  case 23:
/* Line 1792 of yacc.c  */
#line 189 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 24:
/* Line 1792 of yacc.c  */
#line 195 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 25:
/* Line 1792 of yacc.c  */
#line 201 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 26:
/* Line 1792 of yacc.c  */
#line 205 "yacc.y"
    {
	BitNode *newNode, *Node1;
	newNode = new BitNode(yycolumn,yylineno,"", "idlist");
	Node1 = new BitNode(yycolumn,yylineno,(yyvsp[(1) - (1)].TYPE)->token, "ID");
	newNode->insertChild(Node1);

	cout<<"idlist -> id [OK]"<<endl;
	(yyval.BITNODE) = newNode;
}
    break;

  case 27:
/* Line 1792 of yacc.c  */
#line 214 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 28:
/* Line 1792 of yacc.c  */
#line 219 "yacc.y"
    {
	BitNode *newNode, *Node1, *Node3;
	newNode = new BitNode(yycolumn,yylineno,"", "const_declarations");
	Node1 = new BitNode(yycolumn,yylineno,(yyvsp[(1) - (3)].TYPE)->token, "CONST");
	Node3 = new BitNode(yycolumn,yylineno,";", "SEPARATOR");

	newNode->insertChild(Node1);
	newNode->insertChild((yyvsp[(2) - (3)].BITNODE));
	newNode->insertChild(Node3);

	cout<<"const_declarations -> const const_declaration ; [OK]"<<endl;
	(yyval.BITNODE) = newNode;
}
    break;

  case 29:
/* Line 1792 of yacc.c  */
#line 232 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 30:
/* Line 1792 of yacc.c  */
#line 238 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 31:
/* Line 1792 of yacc.c  */
#line 244 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 32:
/* Line 1792 of yacc.c  */
#line 248 "yacc.y"
    {
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "const_declarations");

	cout<<"const_declarations -> empty [OK]"<<endl;
	(yyval.BITNODE) = newNode;
}
    break;

  case 33:
/* Line 1792 of yacc.c  */
#line 255 "yacc.y"
    {
	if((yyvsp[(3) - (5)].TYPE)->token.compare("=") != 0)
        	yyerror("");

	BitNode *newNode, *Node2, *Node3, *Node4;
	newNode = new BitNode(yycolumn,yylineno,"", "const_declaration");
	Node2 = new BitNode(yycolumn,yylineno,";", "SEPARATOR");
	Node3 = new BitNode(yycolumn,yylineno,(yyvsp[(3) - (5)].TYPE)->token, "ID");
	Node4 = new BitNode(yycolumn,yylineno,(yyvsp[(4) - (5)].TYPE)->token, "RELOP");

	newNode->insertChild((yyvsp[(1) - (5)].BITNODE));
	newNode->insertChild(Node2);
	newNode->insertChild(Node3);
	newNode->insertChild(Node4);
	newNode->insertChild((yyvsp[(5) - (5)].BITNODE));

	cout<<"const_declaration -> const_declaration ; id = const_value [OK]"<<endl;
	(yyval.BITNODE) = newNode;
}
    break;

  case 34:
/* Line 1792 of yacc.c  */
#line 274 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 35:
/* Line 1792 of yacc.c  */
#line 280 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 36:
/* Line 1792 of yacc.c  */
#line 286 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 37:
/* Line 1792 of yacc.c  */
#line 292 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 38:
/* Line 1792 of yacc.c  */
#line 298 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 39:
/* Line 1792 of yacc.c  */
#line 302 "yacc.y"
    {
 	if((yyvsp[(2) - (3)].TYPE)->token.compare("=")!=0)
        	yyerror("");

	BitNode *newNode, *Node1, *Node2;
	newNode = new BitNode(yycolumn,yylineno,"", "const_declaration");
	Node1 = new BitNode(yycolumn,yylineno,(yyvsp[(1) - (3)].TYPE)->token, "ID");
	Node2 = new BitNode(yycolumn,yylineno,(yyvsp[(2) - (3)].TYPE)->token, "RELOP");

	newNode->insertChild(Node1);
	newNode->insertChild(Node2);
	newNode->insertChild((yyvsp[(3) - (3)].BITNODE));

	cout<<"const_declaration -> id = const_value [OK]"<<endl;
	(yyval.BITNODE) = newNode;
}
    break;

  case 40:
/* Line 1792 of yacc.c  */
#line 318 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 41:
/* Line 1792 of yacc.c  */
#line 324 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 42:
/* Line 1792 of yacc.c  */
#line 330 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 43:
/* Line 1792 of yacc.c  */
#line 335 "yacc.y"
    {
	if((yyvsp[(1) - (2)].TYPE)->token.compare("+") != 0) // 修改终结符判断逻辑，因为对终结符 ADDOP的内容为 + or
		yyerror("");

	BitNode *newNode, *Node1, *Node2;
	newNode = new BitNode(yycolumn, yylineno, "", "const_value");
	Node1 = new BitNode(yycolumn, yylineno, (yyvsp[(1) - (2)].TYPE)->token, "ADDOP");
	Node2 = new BitNode(yycolumn, yylineno, (yyvsp[(2) - (2)].TYPE)->token, "NUM");

	newNode->insertChild(Node1);
	newNode->insertChild(Node2);

	cout<<"const_value -> + num [OK]"<<endl;
	(yyval.BITNODE) = newNode;
}
    break;

  case 44:
/* Line 1792 of yacc.c  */
#line 351 "yacc.y"
    { // 增加 UMINUS 的关联生成式
	BitNode *newNode, *Node1, *Node2;
	newNode = new BitNode(yycolumn, yylineno, "", "const_value");
	Node1 = new BitNode(yycolumn, yylineno, (yyvsp[(1) - (2)].TYPE)->token, "UMINUS");
	Node2 = new BitNode(yycolumn, yylineno, (yyvsp[(2) - (2)].TYPE)->token, "NUM");

	newNode->insertChild(Node1);
	newNode->insertChild(Node2);

	cout<<"const_value -> - num [OK]"<<endl;
	(yyval.BITNODE) = newNode;
}
    break;

  case 45:
/* Line 1792 of yacc.c  */
#line 364 "yacc.y"
    {
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 46:
/* Line 1792 of yacc.c  */
#line 369 "yacc.y"
    {
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 47:
/* Line 1792 of yacc.c  */
#line 374 "yacc.y"
    {
	BitNode *newNode, *Node1;
	newNode = new BitNode(yycolumn,yylineno,"", "const_value");
	Node1 = new BitNode(yycolumn,yylineno,(yyvsp[(1) - (1)].TYPE)->token, "NUM");

	newNode->insertChild(Node1);

	cout<<"const_value -> num [OK]"<<endl;
	(yyval.BITNODE) = newNode;
}
    break;

  case 48:
/* Line 1792 of yacc.c  */
#line 385 "yacc.y"
    { // 处理单个字符
	BitNode *newNode, *Node1;
	newNode = new BitNode(yycolumn,yylineno,"", "const_value");
	Node1 = new BitNode(yycolumn,yylineno,(yyvsp[(1) - (1)].TYPE)->token, "CHAR");

	newNode->insertChild(Node1);

	cout<<"const_value -> char [OK]"<<endl;
	(yyval.BITNODE) = newNode;
}
    break;

  case 49:
/* Line 1792 of yacc.c  */
#line 396 "yacc.y"
    {
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 50:
/* Line 1792 of yacc.c  */
#line 401 "yacc.y"
    { // 增加处理 digits 的生成式
	BitNode *newNode, *Node1;
	newNode = new BitNode(yycolumn, yylineno, "", "const_value");
	Node1 = new BitNode(yycolumn, yylineno, (yyvsp[(1) - (1)].TYPE)->token, "DIGITS");

	newNode->insertChild(Node1);

	cout<<"const_value -> digits [OK]"<<endl;
        (yyval.BITNODE) = newNode;
}
    break;

  case 51:
/* Line 1792 of yacc.c  */
#line 412 "yacc.y"
    { // 增加处理 digits 关联的生成式
	if((yyvsp[(1) - (2)].TYPE)->token.compare("+") != 0) // ADDOP包括两种运算：+ or
		yyerror("");

	BitNode *newNode, *Node1, *Node2;
	newNode = new BitNode(yycolumn, yylineno,"", "const_value");
	Node1 = new BitNode(yycolumn, yylineno, (yyvsp[(1) - (2)].TYPE)->token, "ADDOP");
	Node2 = new BitNode(yycolumn, yylineno, (yyvsp[(2) - (2)].TYPE)->token, "DIGITS");

	newNode->insertChild(Node1);
	newNode->insertChild(Node2);

	cout<<"const_value -> + digits [OK]"<<endl;
	(yyval.BITNODE) = newNode;
}
    break;

  case 52:
/* Line 1792 of yacc.c  */
#line 427 "yacc.y"
    { // 增加处理 digits 关联的生成式
	BitNode *newNode, *Node1, *Node2;
	newNode = new BitNode(yycolumn, yylineno,"", "const_value");
	Node1 = new BitNode(yycolumn, yylineno, (yyvsp[(1) - (2)].TYPE)->token, "UMINUS");
	Node2 = new BitNode(yycolumn, yylineno, (yyvsp[(2) - (2)].TYPE)->token, "DIGITS");

	newNode->insertChild(Node1);
	newNode->insertChild(Node2);

	cout<<"const_value -> - digits [OK]"<<endl;
	(yyval.BITNODE) = newNode;
}
    break;

  case 53:
/* Line 1792 of yacc.c  */
#line 439 "yacc.y"
    { // 增加处理 boolean 的生成式
	BitNode *newNode, *Node1;
	newNode = new BitNode(yycolumn, yylineno, "", "const_value");
	Node1 = new BitNode(yycolumn, yylineno, (yyvsp[(1) - (1)].TYPE)->token, "BOOLEAN");

	newNode->insertChild(Node1);

	cout<<"const_value -> boolean [OK]"<<endl;
        (yyval.BITNODE) = newNode;
}
    break;

  case 54:
/* Line 1792 of yacc.c  */
#line 450 "yacc.y"
    {
	BitNode *newNode, *Node1, *Node3;
	newNode = new BitNode(yycolumn,yylineno,"", "var_declarations");
	Node1 = new BitNode(yycolumn,yylineno,(yyvsp[(1) - (3)].TYPE)->token, "VAR");
	Node3 = new BitNode(yycolumn,yylineno,";", "SEPARATOR");

	newNode->insertChild(Node1);
	newNode->insertChild((yyvsp[(2) - (3)].BITNODE));
	newNode->insertChild(Node3);

	cout<<"var_declarations -> var var_declaration ; [OK]"<<endl;
	(yyval.BITNODE) = newNode;
}
    break;

  case 55:
/* Line 1792 of yacc.c  */
#line 463 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 56:
/* Line 1792 of yacc.c  */
#line 469 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 57:
/* Line 1792 of yacc.c  */
#line 475 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 58:
/* Line 1792 of yacc.c  */
#line 479 "yacc.y"
    {
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "var_declarations");

	cout<<"var_declarations -> empty [OK]"<<endl;
	(yyval.BITNODE) = newNode;
}
    break;

  case 59:
/* Line 1792 of yacc.c  */
#line 486 "yacc.y"
    {
	BitNode *newNode, *Node2, *Node4;
	newNode = new BitNode(yycolumn,yylineno,"", "var_declaration");
	Node2 = new BitNode(yycolumn,yylineno,";", "SEPARATOR");
	Node4 = new BitNode(yycolumn,yylineno,":", "SEPARATOR");

	newNode->insertChild((yyvsp[(1) - (5)].BITNODE));
	newNode->insertChild(Node2);
	newNode->insertChild((yyvsp[(3) - (5)].BITNODE));
	newNode->insertChild(Node4);
	newNode->insertChild((yyvsp[(5) - (5)].BITNODE));

	cout<<"var_declaration -> var_declaration ; idlist : type [OK]"<<endl;
	(yyval.BITNODE) = newNode;
}
    break;

  case 60:
/* Line 1792 of yacc.c  */
#line 502 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 61:
/* Line 1792 of yacc.c  */
#line 508 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 62:
/* Line 1792 of yacc.c  */
#line 514 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 63:
/* Line 1792 of yacc.c  */
#line 520 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 64:
/* Line 1792 of yacc.c  */
#line 526 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 65:
/* Line 1792 of yacc.c  */
#line 530 "yacc.y"
    {
	BitNode *newNode, *Node2;
	newNode = new BitNode(yycolumn,yylineno,"", "var_declaration");
	Node2 = new BitNode(yycolumn,yylineno,":", "SEPARATOR");

	newNode->insertChild((yyvsp[(1) - (3)].BITNODE));
	newNode->insertChild(Node2);
	newNode->insertChild((yyvsp[(3) - (3)].BITNODE));

	cout<<"var_declaration -> idlist : type [OK]"<<endl;
	(yyval.BITNODE) = newNode;
}
    break;

  case 66:
/* Line 1792 of yacc.c  */
#line 542 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 67:
/* Line 1792 of yacc.c  */
#line 548 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 68:
/* Line 1792 of yacc.c  */
#line 554 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 69:
/* Line 1792 of yacc.c  */
#line 559 "yacc.y"
    {
	BitNode *newNode;
	newNode = new BitNode(yycolumn,yylineno,"", "type");

	newNode->insertChild((yyvsp[(1) - (1)].BITNODE));

	cout<<"type -> basic_type [OK]"<<endl;
	(yyval.BITNODE) = newNode;
}
    break;

  case 70:
/* Line 1792 of yacc.c  */
#line 568 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 71:
/* Line 1792 of yacc.c  */
#line 572 "yacc.y"
    {
	BitNode *newNode, *Node1, *Node2, *Node4, *Node5;
	newNode = new BitNode(yycolumn,yylineno,"", "type");
	Node1 = new BitNode(yycolumn,yylineno,(yyvsp[(1) - (6)].TYPE)->token, "ARRAY");
	Node2 = new BitNode(yycolumn,yylineno,"[", "SEPARATOR");
	Node4 = new BitNode(yycolumn,yylineno,"]", "SEPARATOR");
	Node5 = new BitNode(yycolumn,yylineno,(yyvsp[(5) - (6)].TYPE)->token, "OF");

	newNode->insertChild(Node1);
	newNode->insertChild(Node2);
	newNode->insertChild((yyvsp[(3) - (6)].BITNODE));
	newNode->insertChild(Node4);
	newNode->insertChild(Node5);
	newNode->insertChild((yyvsp[(6) - (6)].BITNODE));

	cout<<"type -> array [ period ] of basic_type [OK]"<<endl;
	(yyval.BITNODE) = newNode;
}
    break;

  case 72:
/* Line 1792 of yacc.c  */
#line 591 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 73:
/* Line 1792 of yacc.c  */
#line 597 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 74:
/* Line 1792 of yacc.c  */
#line 603 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 75:
/* Line 1792 of yacc.c  */
#line 609 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 76:
/* Line 1792 of yacc.c  */
#line 615 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 77:
/* Line 1792 of yacc.c  */
#line 621 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 78:
/* Line 1792 of yacc.c  */
#line 626 "yacc.y"
    {
	BitNode *newNode, *Node1;
	newNode = new BitNode(yycolumn,yylineno,"", "basic_type");
	Node1 = new BitNode(yycolumn,yylineno,(yyvsp[(1) - (1)].TYPE)->token, "VARTYPE");

	newNode->insertChild(Node1);

	cout<<"type -> basic_type [OK]"<<endl;
	(yyval.BITNODE) = newNode;
}
    break;

  case 79:
/* Line 1792 of yacc.c  */
#line 636 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 80:
/* Line 1792 of yacc.c  */
#line 641 "yacc.y"
    {
	BitNode *newNode, *Node2, *Node3, *Node4, *Node5;
	newNode = new BitNode(yycolumn,yylineno,"", "period");
	Node2 = new BitNode(yycolumn,yylineno,",", "SEPARATOR");
	Node3 = new BitNode(yycolumn,yylineno,(yyvsp[(3) - (5)].TYPE)->token, "DIGITS");
	Node4 = new BitNode(yycolumn,yylineno,(yyvsp[(4) - (5)].TYPE)->token, "RANGE");
	Node5 = new BitNode(yycolumn,yylineno,(yyvsp[(5) - (5)].TYPE)->token, "DIGITS");

	newNode->insertChild((yyvsp[(1) - (5)].BITNODE));
	newNode->insertChild(Node2);
	newNode->insertChild(Node3);
	newNode->insertChild(Node4);
	newNode->insertChild(Node5);

	cout<<"period -> period , digits .. digits [OK]"<<endl;
	(yyval.BITNODE) = newNode;
}
    break;

  case 81:
/* Line 1792 of yacc.c  */
#line 658 "yacc.y"
    {
	BitNode *newNode, *Node1, *Node2, *Node3;
	newNode = new BitNode(yycolumn,yylineno,"", "period");
	Node1 = new BitNode(yycolumn,yylineno,(yyvsp[(1) - (3)].TYPE)->token, "DIGITS");
	Node2 = new BitNode(yycolumn,yylineno,(yyvsp[(2) - (3)].TYPE)->token, "RANGE");
	Node3 = new BitNode(yycolumn,yylineno,(yyvsp[(3) - (3)].TYPE)->token, "DIGITS");

	newNode->insertChild(Node1);
	newNode->insertChild(Node2);
	newNode->insertChild(Node3);

	cout<<"period -> digits .. digits [OK]"<<endl;
	(yyval.BITNODE) = newNode;
}
    break;

  case 82:
/* Line 1792 of yacc.c  */
#line 671 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 83:
/* Line 1792 of yacc.c  */
#line 676 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 84:
/* Line 1792 of yacc.c  */
#line 682 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 85:
/* Line 1792 of yacc.c  */
#line 688 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 86:
/* Line 1792 of yacc.c  */
#line 694 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 87:
/* Line 1792 of yacc.c  */
#line 697 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 88:
/* Line 1792 of yacc.c  */
#line 703 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 89:
/* Line 1792 of yacc.c  */
#line 709 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 90:
/* Line 1792 of yacc.c  */
#line 714 "yacc.y"
    {
	BitNode *newNode, *Node3;
	newNode = new BitNode(yycolumn,yylineno,"", "subprogram_declarations");
	Node3 = new BitNode(yycolumn,yylineno,";", "SEPARATOR");

	newNode->insertChild((yyvsp[(1) - (3)].BITNODE));
	newNode->insertChild((yyvsp[(2) - (3)].BITNODE));
	newNode->insertChild(Node3);

	cout<<"subprogram_declarations -> subprogram_declarations subprogram ; [OK]"<<endl;
	(yyval.BITNODE) = newNode;
}
    break;

  case 91:
/* Line 1792 of yacc.c  */
#line 726 "yacc.y"
    {
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "subprogram_declarations");

	cout<<"subprogram_declarations -> empty [OK]"<<endl;
	(yyval.BITNODE) = newNode;
}
    break;

  case 92:
/* Line 1792 of yacc.c  */
#line 731 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 93:
/* Line 1792 of yacc.c  */
#line 737 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 94:
/* Line 1792 of yacc.c  */
#line 743 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 95:
/* Line 1792 of yacc.c  */
#line 748 "yacc.y"
    {
	BitNode *newNode, *Node2;
	newNode = new BitNode(yycolumn,yylineno,"", "subprogram");
	Node2 = new BitNode(yycolumn,yylineno,";", "SEPARATOR");

	newNode->insertChild((yyvsp[(1) - (3)].BITNODE));
	newNode->insertChild(Node2);
	newNode->insertChild((yyvsp[(3) - (3)].BITNODE));

	cout<<"subprogram -> subprogram_head _SEPARATOR subprogram_body [OK]"<<endl;
	(yyval.BITNODE) = newNode;
}
    break;

  case 96:
/* Line 1792 of yacc.c  */
#line 761 "yacc.y"
    {
	BitNode *newNode, *Node1, *Node2;
	newNode = new BitNode(yycolumn,yylineno,"", "subprogram_head");
	Node1 = new BitNode(yycolumn,yylineno,(yyvsp[(1) - (3)].TYPE)->token, "PROCEDURE");
	Node2 = new BitNode(yycolumn,yylineno,(yyvsp[(2) - (3)].TYPE)->token, "ID");

	newNode->insertChild(Node1);
	newNode->insertChild(Node2);
	newNode->insertChild((yyvsp[(3) - (3)].BITNODE));

	cout<<"subprogram_head -> procedure id formal_parameter [OK]"<<endl;
	(yyval.BITNODE) = newNode;
}
    break;

  case 97:
/* Line 1792 of yacc.c  */
#line 773 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 98:
/* Line 1792 of yacc.c  */
#line 779 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 99:
/* Line 1792 of yacc.c  */
#line 785 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 100:
/* Line 1792 of yacc.c  */
#line 789 "yacc.y"
    {
	BitNode *newNode,*Node1, *Node2, *Node4;
	newNode = new BitNode(yycolumn,yylineno,"", "subprogram_head");
	Node1 = new BitNode(yycolumn,yylineno,(yyvsp[(1) - (5)].TYPE)->token, "FUNCTION");
	Node2 = new BitNode(yycolumn,yylineno,(yyvsp[(2) - (5)].TYPE)->token, "ID");
	Node4 = new BitNode(yycolumn,yylineno,":", "SEPARATOR");

	newNode->insertChild(Node1);
	newNode->insertChild(Node2);
	newNode->insertChild((yyvsp[(3) - (5)].BITNODE));
	newNode->insertChild(Node4);
	newNode->insertChild((yyvsp[(5) - (5)].BITNODE));

	cout<<"subprogram_head -> function id formal_parameter : basic_type [OK]"<<endl;
	(yyval.BITNODE) = newNode;
}
    break;

  case 101:
/* Line 1792 of yacc.c  */
#line 804 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 102:
/* Line 1792 of yacc.c  */
#line 810 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 103:
/* Line 1792 of yacc.c  */
#line 816 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 104:
/* Line 1792 of yacc.c  */
#line 822 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 105:
/* Line 1792 of yacc.c  */
#line 828 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 106:
/* Line 1792 of yacc.c  */
#line 834 "yacc.y"
    {
	BitNode *newNode, *Node1, *Node3;
	newNode = new BitNode(yycolumn,yylineno,"", "formal_parameter");
	Node1 = new BitNode(yycolumn,yylineno,"(", "SEPARATOR");
	Node3 = new BitNode(yycolumn,yylineno,")", "SEPARATOR");

	newNode->insertChild(Node1);
	newNode->insertChild((yyvsp[(2) - (3)].BITNODE));
	newNode->insertChild(Node3);

	cout<<" formal_parameter -> ( parameter_list ) [OK]"<<endl;
	(yyval.BITNODE) = newNode;
}
    break;

  case 107:
/* Line 1792 of yacc.c  */
#line 846 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 108:
/* Line 1792 of yacc.c  */
#line 852 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 109:
/* Line 1792 of yacc.c  */
#line 858 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 110:
/* Line 1792 of yacc.c  */
#line 862 "yacc.y"
    {
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "formal_parameter");

	cout<<"formal_parameter -> empty [OK]"<<endl;
	(yyval.BITNODE) = newNode;
}
    break;

  case 111:
/* Line 1792 of yacc.c  */
#line 869 "yacc.y"
    {
	BitNode *newNode, *Node2;
	newNode = new BitNode(yycolumn,yylineno,"", "parameter_list");
	Node2 = new BitNode(yycolumn,yylineno,";", "SEPARATOR");

	newNode->insertChild((yyvsp[(1) - (3)].BITNODE));
	newNode->insertChild(Node2);
	newNode->insertChild((yyvsp[(3) - (3)].BITNODE));

	cout<<"parameter_list -> parameter_list _SEPARATOR parameter [OK]"<<endl;
	(yyval.BITNODE) = newNode;
}
    break;

  case 112:
/* Line 1792 of yacc.c  */
#line 880 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 113:
/* Line 1792 of yacc.c  */
#line 886 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 114:
/* Line 1792 of yacc.c  */
#line 892 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 115:
/* Line 1792 of yacc.c  */
#line 896 "yacc.y"
    {
	BitNode * newNode;
	newNode = new BitNode(yycolumn,yylineno,"", "parameter_list");

	newNode->insertChild((yyvsp[(1) - (1)].BITNODE));

	cout<<"parameter_list -> parameter [OK]"<<endl;
	(yyval.BITNODE) = newNode;
}
    break;

  case 116:
/* Line 1792 of yacc.c  */
#line 904 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 117:
/* Line 1792 of yacc.c  */
#line 909 "yacc.y"
    {
	BitNode *newNode;
	newNode = new BitNode(yycolumn,yylineno,"", "parameter");

	newNode->insertChild((yyvsp[(1) - (1)].BITNODE));

	cout<<"parameter -> var_parameter [OK]"<<endl;
	(yyval.BITNODE) = newNode;
}
    break;

  case 118:
/* Line 1792 of yacc.c  */
#line 918 "yacc.y"
    {
	BitNode *newNode;
        newNode = new BitNode(yycolumn,yylineno,"", "parameter");

        newNode->insertChild((yyvsp[(1) - (1)].BITNODE));

        cout<<"parameter -> value_parameter [OK]"<<endl;
        (yyval.BITNODE) = newNode;
}
    break;

  case 119:
/* Line 1792 of yacc.c  */
#line 926 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 120:
/* Line 1792 of yacc.c  */
#line 931 "yacc.y"
    {
	BitNode *newNode, *Node1;
	newNode = new BitNode(yycolumn,yylineno,"", "var_parameter");
	Node1 = new BitNode(yycolumn,yylineno,(yyvsp[(1) - (2)].TYPE)->token, "VAR");

	newNode->insertChild(Node1);
	newNode->insertChild((yyvsp[(2) - (2)].BITNODE));

	cout<<"var_parameter -> var value_parameter [OK]"<<endl;
	(yyval.BITNODE) = newNode;
}
    break;

  case 121:
/* Line 1792 of yacc.c  */
#line 941 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 122:
/* Line 1792 of yacc.c  */
#line 947 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 123:
/* Line 1792 of yacc.c  */
#line 952 "yacc.y"
    {
	// if($2->token.compare(":") != 0)
	//	yyerror("");

	BitNode *newNode, *Node2;
	newNode = new BitNode(yycolumn,yylineno,"", "value_parameter");
	Node2 = new BitNode(yycolumn,yylineno,":", "SEPARATOR");

	newNode->insertChild((yyvsp[(1) - (3)].BITNODE));
	newNode->insertChild(Node2);
	newNode->insertChild((yyvsp[(3) - (3)].BITNODE));

	cout<<"value_parameter -> idlist : simple_type [OK]"<<endl;
	(yyval.BITNODE) = newNode;
}
    break;

  case 124:
/* Line 1792 of yacc.c  */
#line 966 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 125:
/* Line 1792 of yacc.c  */
#line 972 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 126:
/* Line 1792 of yacc.c  */
#line 978 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 127:
/* Line 1792 of yacc.c  */
#line 983 "yacc.y"
    {
	BitNode *newNode;
	newNode = new BitNode(yycolumn,yylineno,"", "subprogram_body");

	newNode->insertChild((yyvsp[(1) - (3)].BITNODE));
	newNode->insertChild((yyvsp[(2) - (3)].BITNODE));
	newNode->insertChild((yyvsp[(3) - (3)].BITNODE));

	cout<<"subprogram_body -> const_declarations var_declarations compound_statement [OK]"<<endl;
	(yyval.BITNODE) = newNode;
}
    break;

  case 128:
/* Line 1792 of yacc.c  */
#line 993 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 129:
/* Line 1792 of yacc.c  */
#line 999 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 130:
/* Line 1792 of yacc.c  */
#line 1005 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 131:
/* Line 1792 of yacc.c  */
#line 1010 "yacc.y"
    {
	BitNode *newNode, *Node1, *Node3;
	newNode = new BitNode(yycolumn,yylineno,"", "compound_statement");
	Node1 = new BitNode(yycolumn,yylineno,(yyvsp[(1) - (3)].TYPE)->token, "BEGIN");
	Node3 = new BitNode(yycolumn,yylineno,(yyvsp[(3) - (3)].TYPE)->token, "END");

	newNode->insertChild(Node1);
	newNode->insertChild((yyvsp[(2) - (3)].BITNODE));
	newNode->insertChild(Node3);

	cout<<"compound_statement -> begin statement_list end [OK]"<<endl;
	(yyval.BITNODE) = newNode;
}
    break;

  case 132:
/* Line 1792 of yacc.c  */
#line 1023 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 133:
/* Line 1792 of yacc.c  */
#line 1029 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 134:
/* Line 1792 of yacc.c  */
#line 1035 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 135:
/* Line 1792 of yacc.c  */
#line 1040 "yacc.y"
    {
	BitNode *newNode, *Node2;
	newNode = new BitNode(yycolumn,yylineno,"", "statement_list");
	Node2 = new BitNode(yycolumn,yylineno,";", "SEPARATOR");

	newNode->insertChild((yyvsp[(1) - (3)].BITNODE));
	newNode->insertChild(Node2);
	newNode->insertChild((yyvsp[(3) - (3)].BITNODE));

	cout<<"statement_list -> statement_list ; statement [OK]"<<endl;
	(yyval.BITNODE) = newNode;
}
    break;

  case 136:
/* Line 1792 of yacc.c  */
#line 1051 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 137:
/* Line 1792 of yacc.c  */
#line 1057 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 138:
/* Line 1792 of yacc.c  */
#line 1063 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 139:
/* Line 1792 of yacc.c  */
#line 1067 "yacc.y"
    {
	BitNode *newNode;
	newNode = new BitNode(yycolumn,yylineno,"", "statement_list");
	newNode->insertChild((yyvsp[(1) - (1)].BITNODE));

	cout<<"statement_list -> statement [OK]"<<endl;
	(yyval.BITNODE) = newNode;
}
    break;

  case 140:
/* Line 1792 of yacc.c  */
#line 1074 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 141:
/* Line 1792 of yacc.c  */
#line 1079 "yacc.y"
    {
	BitNode *newNode, *Node2;
	newNode = new BitNode(yycolumn,yylineno,"", "statement");
	Node2 = new BitNode(yycolumn,yylineno,(yyvsp[(2) - (3)].TYPE)->token, "ASSIGNOP");

	newNode->insertChild((yyvsp[(1) - (3)].BITNODE));
	newNode->insertChild(Node2);
	newNode->insertChild((yyvsp[(3) - (3)].BITNODE));

	cout<<"statement -> variable _ASSIGNOP expression [OK]"<<endl;
	(yyval.BITNODE) = newNode;
}
    break;

  case 142:
/* Line 1792 of yacc.c  */
#line 1090 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 143:
/* Line 1792 of yacc.c  */
#line 1096 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 144:
/* Line 1792 of yacc.c  */
#line 1102 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 145:
/* Line 1792 of yacc.c  */
#line 1106 "yacc.y"
    {
	BitNode *newNode;
	newNode = new BitNode(yycolumn,yylineno,"", "statement");
	newNode->insertChild((yyvsp[(1) - (1)].BITNODE));

	cout<<"statement -> procedure_call [OK]"<<endl;
	(yyval.BITNODE) = newNode;
}
    break;

  case 146:
/* Line 1792 of yacc.c  */
#line 1114 "yacc.y"
    {
	BitNode *newNode;
        newNode = new BitNode(yycolumn,yylineno,"", "statement");
        newNode->insertChild((yyvsp[(1) - (1)].BITNODE));

        cout<<"statement -> compound_statement [OK]"<<endl;
        (yyval.BITNODE) = newNode;
}
    break;

  case 147:
/* Line 1792 of yacc.c  */
#line 1121 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 148:
/* Line 1792 of yacc.c  */
#line 1125 "yacc.y"
    {
	BitNode *newNode, *Node1, *Node3;
	newNode = new BitNode(yycolumn,yylineno,"", "statement");
	Node1 = new BitNode(yycolumn,yylineno,(yyvsp[(1) - (5)].TYPE)->token, "IF");
	Node3 = new BitNode(yycolumn,yylineno,(yyvsp[(3) - (5)].TYPE)->token, "THEN");

	newNode->insertChild(Node1);
	newNode->insertChild((yyvsp[(2) - (5)].BITNODE));
	newNode->insertChild(Node3);
	newNode->insertChild((yyvsp[(4) - (5)].BITNODE));
	newNode->insertChild((yyvsp[(5) - (5)].BITNODE));

	cout<<"statement -> if expression then statement else_part [OK]"<<endl;
	(yyval.BITNODE) = newNode;
}
    break;

  case 149:
/* Line 1792 of yacc.c  */
#line 1139 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 150:
/* Line 1792 of yacc.c  */
#line 1145 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 151:
/* Line 1792 of yacc.c  */
#line 1151 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 152:
/* Line 1792 of yacc.c  */
#line 1157 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 153:
/* Line 1792 of yacc.c  */
#line 1163 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 154:
/* Line 1792 of yacc.c  */
#line 1167 "yacc.y"
    {
	BitNode *newNode, *Node1, *Node2, *Node3, *Node5, *Node7;
	newNode = new BitNode(yycolumn,yylineno,"", "statement");
	Node1 = new BitNode(yycolumn,yylineno,(yyvsp[(1) - (8)].TYPE)->token, "FOR");
	Node2 = new BitNode(yycolumn,yylineno,(yyvsp[(2) - (8)].TYPE)->token, "ID");
	Node3 = new BitNode(yycolumn,yylineno,(yyvsp[(3) - (8)].TYPE)->token, "ASSIGNOP");
	Node5 = new BitNode(yycolumn,yylineno,(yyvsp[(5) - (8)].TYPE)->token, "TO");
	Node7 = new BitNode(yycolumn,yylineno,(yyvsp[(7) - (8)].TYPE)->token, "DO");

	newNode->insertChild(Node1);
	newNode->insertChild(Node2);
	newNode->insertChild(Node3);
	newNode->insertChild((yyvsp[(4) - (8)].BITNODE));
	newNode->insertChild(Node5);
	newNode->insertChild((yyvsp[(6) - (8)].BITNODE));
	newNode->insertChild(Node7);
	newNode->insertChild((yyvsp[(8) - (8)].BITNODE));

	cout<<"statement -> for id assignop expression to expression do statement [OK]"<<endl;
	(yyval.BITNODE) = newNode;
}
    break;

  case 155:
/* Line 1792 of yacc.c  */
#line 1187 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 156:
/* Line 1792 of yacc.c  */
#line 1193 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 157:
/* Line 1792 of yacc.c  */
#line 1199 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 158:
/* Line 1792 of yacc.c  */
#line 1205 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 159:
/* Line 1792 of yacc.c  */
#line 1211 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 160:
/* Line 1792 of yacc.c  */
#line 1217 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 161:
/* Line 1792 of yacc.c  */
#line 1223 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 162:
/* Line 1792 of yacc.c  */
#line 1229 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 163:
/* Line 1792 of yacc.c  */
#line 1233 "yacc.y"
    {
	BitNode *newNode, *Node1, *Node2, *Node4;
	newNode = new BitNode(yycolumn,yylineno,"", "statement");
	Node1 = new BitNode(yycolumn,yylineno,(yyvsp[(1) - (4)].TYPE)->token, "READ");
	Node2 = new BitNode(yycolumn,yylineno,"(", "SEPARATOR");
	Node4 = new BitNode(yycolumn,yylineno,")", "SEPARATOR");

	newNode->insertChild(Node1);
	newNode->insertChild(Node2);
	newNode->insertChild((yyvsp[(3) - (4)].BITNODE));
	newNode->insertChild(Node4);

	cout<<"statement -> read ( variable_list ) [OK]"<<endl;
	(yyval.BITNODE) = newNode;
}
    break;

  case 164:
/* Line 1792 of yacc.c  */
#line 1248 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 165:
/* Line 1792 of yacc.c  */
#line 1254 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 166:
/* Line 1792 of yacc.c  */
#line 1260 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 167:
/* Line 1792 of yacc.c  */
#line 1266 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 168:
/* Line 1792 of yacc.c  */
#line 1271 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 169:
/* Line 1792 of yacc.c  */
#line 1277 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 170:
/* Line 1792 of yacc.c  */
#line 1283 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 171:
/* Line 1792 of yacc.c  */
#line 1289 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode;
}
    break;

  case 172:
/* Line 1792 of yacc.c  */
#line 1293 "yacc.y"
    {
        BitNode *newNode, *Node1, *Node2, *Node4;
        newNode = new BitNode(yycolumn,yylineno,"", "statement");
        Node1 = new BitNode(yycolumn,yylineno,(yyvsp[(1) - (4)].TYPE)->token, "WRITE");
        Node2 = new BitNode(yycolumn,yylineno,"(", "SEPARATOR");
        Node4 = new BitNode(yycolumn,yylineno,")", "SEPARATOR");

        newNode->insertChild(Node1);
        newNode->insertChild(Node2);
        newNode->insertChild((yyvsp[(3) - (4)].BITNODE));
        newNode->insertChild(Node4);

        cout<<"statement -> write ( variable_list ) [OK]"<<endl;
        (yyval.BITNODE) = newNode;
}
    break;

  case 173:
/* Line 1792 of yacc.c  */
#line 1308 "yacc.y"
    {
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "statement");

	cout<<"statement -> empty [OK]"<<endl;
	(yyval.BITNODE) = newNode;
}
    break;

  case 174:
/* Line 1792 of yacc.c  */
#line 1314 "yacc.y"
    { // 增加while循环
	BitNode *newNode, *Node1, *Node3;
        newNode = new BitNode(yycolumn,yylineno,"", "statement");
        Node1 = new BitNode(yycolumn,yylineno,(yyvsp[(1) - (4)].TYPE)->token, "WHILE");
        Node3 = new BitNode(yycolumn,yylineno,(yyvsp[(3) - (4)].TYPE)->token, "DO");

        newNode->insertChild(Node1);
        newNode->insertChild((yyvsp[(2) - (4)].BITNODE));
        newNode->insertChild(Node3);
        newNode->insertChild((yyvsp[(4) - (4)].BITNODE));

        cout<<"statement -> _WHILE expression _DO statement [OK]"<<endl;
        (yyval.BITNODE) = newNode;
}
    break;

  case 175:
/* Line 1792 of yacc.c  */
#line 1327 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 176:
/* Line 1792 of yacc.c  */
#line 1333 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 177:
/* Line 1792 of yacc.c  */
#line 1339 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 178:
/* Line 1792 of yacc.c  */
#line 1345 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 179:
/* Line 1792 of yacc.c  */
#line 1350 "yacc.y"
    {
	BitNode *newNode, *Node2;
	newNode = new BitNode(yycolumn,yylineno,"", "variable_list");
	Node2 = new BitNode(yycolumn,yylineno,",", "SEPARATOR");

	newNode->insertChild((yyvsp[(1) - (3)].BITNODE));
	newNode->insertChild(Node2);
	newNode->insertChild((yyvsp[(3) - (3)].BITNODE));

	cout<<"variable_list -> variable_list _SEPARATOR variable [OK]"<<endl;
	(yyval.BITNODE) = newNode;
}
    break;

  case 180:
/* Line 1792 of yacc.c  */
#line 1362 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 181:
/* Line 1792 of yacc.c  */
#line 1368 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 182:
/* Line 1792 of yacc.c  */
#line 1374 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 183:
/* Line 1792 of yacc.c  */
#line 1378 "yacc.y"
    {
	BitNode *newNode;
	newNode = new BitNode(yycolumn,yylineno,"", "variable_list");

	newNode->insertChild((yyvsp[(1) - (1)].BITNODE));

	cout<<"statement -> variable [OK]"<<endl;
	(yyval.BITNODE) = newNode;
}
    break;

  case 184:
/* Line 1792 of yacc.c  */
#line 1387 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 185:
/* Line 1792 of yacc.c  */
#line 1392 "yacc.y"
    {
	BitNode *newNode, *Node1;
	newNode = new BitNode(yycolumn,yylineno,"", "variable");
	Node1 = new BitNode(yycolumn,yylineno,(yyvsp[(1) - (2)].TYPE)->token, "ID");

	newNode->insertChild(Node1);
	newNode->insertChild((yyvsp[(2) - (2)].BITNODE));

	cout<<"variable -> id id_varpart [OK]"<<endl;
	(yyval.BITNODE) = newNode;
}
    break;

  case 186:
/* Line 1792 of yacc.c  */
#line 1404 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 187:
/* Line 1792 of yacc.c  */
#line 1410 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 188:
/* Line 1792 of yacc.c  */
#line 1415 "yacc.y"
    {
	BitNode *newNode, *Node1, *Node3;
	newNode = new BitNode(yycolumn,yylineno,"", "id_varpart");
	Node1 = new BitNode(yycolumn,yylineno,"[", "SEPARATOR");
	Node3 = new BitNode(yycolumn,yylineno,"]", "SEPARATOR");

	newNode->insertChild(Node1);
	newNode->insertChild((yyvsp[(2) - (3)].BITNODE));
	newNode->insertChild(Node3);

	cout<<"id_varpart -> [ expression_list ] [OK]"<<endl;
	(yyval.BITNODE) = newNode;
}
    break;

  case 189:
/* Line 1792 of yacc.c  */
#line 1428 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 190:
/* Line 1792 of yacc.c  */
#line 1434 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 191:
/* Line 1792 of yacc.c  */
#line 1440 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 192:
/* Line 1792 of yacc.c  */
#line 1444 "yacc.y"
    {
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "id_varpart");

	cout<<"id_varpart -> empty [OK]"<<endl;
	(yyval.BITNODE) = newNode;
}
    break;

  case 193:
/* Line 1792 of yacc.c  */
#line 1451 "yacc.y"
    {
	BitNode *newNode, *Node1;
	newNode = new BitNode(yycolumn,yylineno,"", "procedure_call");
	Node1 = new BitNode(yycolumn,yylineno,(yyvsp[(1) - (1)].TYPE)->token, "ID");

	newNode->insertChild(Node1);

	cout<<"procedure_call -> id [OK]"<<endl;
	(yyval.BITNODE) = newNode;
}
    break;

  case 194:
/* Line 1792 of yacc.c  */
#line 1462 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 195:
/* Line 1792 of yacc.c  */
#line 1468 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 196:
/* Line 1792 of yacc.c  */
#line 1474 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 197:
/* Line 1792 of yacc.c  */
#line 1480 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 198:
/* Line 1792 of yacc.c  */
#line 1486 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 199:
/* Line 1792 of yacc.c  */
#line 1490 "yacc.y"
    {
	BitNode *newNode, *Node1, *Node2, *Node4;
	newNode = new BitNode(yycolumn,yylineno,"", "procedure_call");
	Node1 = new BitNode(yycolumn,yylineno,(yyvsp[(1) - (4)].TYPE)->token, "ID");
	Node2 = new BitNode(yycolumn,yylineno,"(", "SEPARATOR");
	Node4 = new BitNode(yycolumn,yylineno,")", "SEPARATOR");

	newNode->insertChild(Node1);
	newNode->insertChild(Node2);
	newNode->insertChild((yyvsp[(3) - (4)].BITNODE));
	newNode->insertChild(Node4);

	cout<<"procedure_call -> id ( expression_list ) [OK]"<<endl;
	(yyval.BITNODE) = newNode;
}
    break;

  case 200:
/* Line 1792 of yacc.c  */
#line 1506 "yacc.y"
    {
	BitNode *newNode, *Node1;
	newNode=new BitNode(yycolumn,yylineno,"", "else_part");
	Node1 = new BitNode(yycolumn,yylineno,(yyvsp[(1) - (2)].TYPE)->token, "ELSE");

	newNode->insertChild(Node1);
	newNode->insertChild((yyvsp[(2) - (2)].BITNODE));

	cout<<"else_part -> else statement [OK]"<<endl;
	(yyval.BITNODE) = newNode;
}
    break;

  case 201:
/* Line 1792 of yacc.c  */
#line 1519 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 202:
/* Line 1792 of yacc.c  */
#line 1525 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 203:
/* Line 1792 of yacc.c  */
#line 1529 "yacc.y"
    {
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "else_part");

	cout<<"else_part -> empty [OK]"<<endl;
	(yyval.BITNODE) = newNode;
}
    break;

  case 204:
/* Line 1792 of yacc.c  */
#line 1536 "yacc.y"
    {

	BitNode *newNode, *Node2;
	newNode = new BitNode(yycolumn,yylineno,"", "expression_list");
	Node2 = new BitNode(yycolumn,yylineno,",", "SEPARATOR");

	newNode->insertChild((yyvsp[(1) - (3)].BITNODE));
	newNode->insertChild(Node2);
	newNode->insertChild((yyvsp[(3) - (3)].BITNODE));

	cout<<"expression_list -> expression_list , expression [OK]"<<endl;
	(yyval.BITNODE) = newNode;
}
    break;

  case 205:
/* Line 1792 of yacc.c  */
#line 1550 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 206:
/* Line 1792 of yacc.c  */
#line 1556 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 207:
/* Line 1792 of yacc.c  */
#line 1562 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 208:
/* Line 1792 of yacc.c  */
#line 1566 "yacc.y"
    {
	BitNode *newNode;
	newNode = new BitNode(yycolumn,yylineno,"", "expression_list");

	newNode->insertChild((yyvsp[(1) - (1)].BITNODE));

	cout<<"expression_list -> expression [OK]"<<endl;
	(yyval.BITNODE) = newNode;
}
    break;

  case 209:
/* Line 1792 of yacc.c  */
#line 1575 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 210:
/* Line 1792 of yacc.c  */
#line 1580 "yacc.y"
    {
	BitNode *newNode, *Node2;
	newNode = new BitNode(yycolumn,yylineno,"", "expression");
	Node2 = new BitNode(yycolumn,yylineno,(yyvsp[(2) - (3)].TYPE)->token, "RELOP");

	newNode->insertChild((yyvsp[(1) - (3)].BITNODE));
	newNode->insertChild(Node2);
	newNode->insertChild((yyvsp[(3) - (3)].BITNODE));

	cout<<"expression -> simple_expression relop simple_expression [OK]"<<endl;
	(yyval.BITNODE) = newNode;
}
    break;

  case 211:
/* Line 1792 of yacc.c  */
#line 1592 "yacc.y"
    {
	BitNode *newNode;
	newNode = new BitNode(yycolumn,yylineno,"", "expression");

	newNode->insertChild((yyvsp[(1) - (1)].BITNODE));

	cout<<"expression -> simple_expression [OK]"<<endl;
	(yyval.BITNODE) = newNode;
}
    break;

  case 212:
/* Line 1792 of yacc.c  */
#line 1602 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 213:
/* Line 1792 of yacc.c  */
#line 1608 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 214:
/* Line 1792 of yacc.c  */
#line 1614 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 215:
/* Line 1792 of yacc.c  */
#line 1620 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 216:
/* Line 1792 of yacc.c  */
#line 1625 "yacc.y"
    {
	BitNode *newNode, *Node2;
	newNode = new BitNode(yycolumn,yylineno,"", "simple_expression");
	Node2 = new BitNode(yycolumn,yylineno,(yyvsp[(2) - (3)].TYPE)->token, "ADDOP");

	newNode->insertChild((yyvsp[(1) - (3)].BITNODE));
	newNode->insertChild(Node2);
	newNode->insertChild((yyvsp[(3) - (3)].BITNODE));

	cout<<"simple_expression -> simple_expression addop term [OK]"<<endl;
	(yyval.BITNODE) = newNode;
}
    break;

  case 217:
/* Line 1792 of yacc.c  */
#line 1636 "yacc.y"
    { // 增加 uminus 关联生成式
	BitNode *newNode, *Node2;
	newNode = new BitNode(yycolumn, yylineno, "", "simple_expression");
	Node2 = new BitNode(yycolumn, yylineno, (yyvsp[(2) - (3)].TYPE)->token, "UMINUS");

	newNode->insertChild((yyvsp[(1) - (3)].BITNODE));
	newNode->insertChild(Node2);
	newNode->insertChild((yyvsp[(3) - (3)].BITNODE));

	cout<<"simple_expression -> simple_expression uminus term [OK]"<<endl;
	(yyval.BITNODE) = newNode;
}
    break;

  case 218:
/* Line 1792 of yacc.c  */
#line 1648 "yacc.y"
    {
	BitNode *newNode;
	newNode = new BitNode(yycolumn,yylineno,"", "simple_expression");

	newNode->insertChild((yyvsp[(1) - (1)].BITNODE));

	cout<<"simple_expression -> term [OK]"<<endl;
	(yyval.BITNODE) = newNode;
}
    break;

  case 219:
/* Line 1792 of yacc.c  */
#line 1658 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 220:
/* Line 1792 of yacc.c  */
#line 1664 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 221:
/* Line 1792 of yacc.c  */
#line 1670 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 222:
/* Line 1792 of yacc.c  */
#line 1676 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 223:
/* Line 1792 of yacc.c  */
#line 1681 "yacc.y"
    {
	BitNode *newNode, *Node2;
	newNode = new BitNode(yycolumn,yylineno,"", "term");
	Node2 = new BitNode(yycolumn,yylineno,(yyvsp[(2) - (3)].TYPE)->token, "MULOP");

	newNode->insertChild((yyvsp[(1) - (3)].BITNODE));
	newNode->insertChild(Node2);
	newNode->insertChild((yyvsp[(3) - (3)].BITNODE));

	cout<<"term -> term mulop factor [OK]"<<endl;
	(yyval.BITNODE) = newNode;
}
    break;

  case 224:
/* Line 1792 of yacc.c  */
#line 1693 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 225:
/* Line 1792 of yacc.c  */
#line 1699 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 226:
/* Line 1792 of yacc.c  */
#line 1705 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 227:
/* Line 1792 of yacc.c  */
#line 1709 "yacc.y"
    {
	BitNode *newNode;
	newNode = new BitNode(yycolumn,yylineno,"", "term");

	newNode->insertChild((yyvsp[(1) - (1)].BITNODE));

	cout<<"term -> factor [OK]"<<endl;
	(yyval.BITNODE) = newNode;
}
    break;

  case 228:
/* Line 1792 of yacc.c  */
#line 1718 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 229:
/* Line 1792 of yacc.c  */
#line 1724 "yacc.y"
    {
        BitNode *newNode, *Node1;
        newNode = new BitNode(yycolumn,yylineno,"", "factor");
        Node1 = new BitNode(yycolumn,yylineno,(yyvsp[(1) - (1)].TYPE)->token, "NUM");

        newNode->insertChild(Node1);

        cout<<" factor -> num [OK]"<<endl;
        (yyval.BITNODE) = newNode;
}
    break;

  case 230:
/* Line 1792 of yacc.c  */
#line 1734 "yacc.y"
    { // 增加整型
        BitNode *newNode, *Node1;
        newNode = new BitNode(yycolumn, yylineno, "", "factor");
        Node1 = new BitNode(yycolumn, yylineno, (yyvsp[(1) - (1)].TYPE)->token, "DIGITS");

        newNode->insertChild(Node1);

        cout<<" factor -> num [OK]"<<endl;
        (yyval.BITNODE) = newNode;
}
    break;

  case 231:
/* Line 1792 of yacc.c  */
#line 1743 "yacc.y"
    { // 增加布尔型
 	BitNode *newNode, *Node1;
        newNode = new BitNode(yycolumn, yylineno, "", "factor");
        Node1 = new BitNode(yycolumn, yylineno, (yyvsp[(1) - (1)].TYPE)->token, "BOOLEAN");

        newNode->insertChild(Node1);

        cout<<" factor -> boolean [OK]"<<endl;
        (yyval.BITNODE) = newNode;
}
    break;

  case 232:
/* Line 1792 of yacc.c  */
#line 1753 "yacc.y"
    {
        BitNode *newNode;
        newNode = new BitNode(yycolumn,yylineno,"", "factor");

        newNode->insertChild((yyvsp[(1) - (1)].BITNODE));

        cout<<" factor -> variable [OK]"<<endl;
        (yyval.BITNODE) = newNode;
}
    break;

  case 233:
/* Line 1792 of yacc.c  */
#line 1762 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 234:
/* Line 1792 of yacc.c  */
#line 1766 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 235:
/* Line 1792 of yacc.c  */
#line 1770 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 236:
/* Line 1792 of yacc.c  */
#line 1776 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 237:
/* Line 1792 of yacc.c  */
#line 1782 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 238:
/* Line 1792 of yacc.c  */
#line 1786 "yacc.y"
    {

	BitNode *newNode, *Node1, *Node2, *Node4;
	newNode =  new BitNode(yycolumn,yylineno,"", "factor");
	Node1 = new BitNode(yycolumn,yylineno,(yyvsp[(1) - (4)].TYPE)->token, "ID");
	Node2 = new BitNode(yycolumn,yylineno,"(", "SEPARATOR");
	Node4 = new BitNode(yycolumn,yylineno,")", "SEPARATOR");

	newNode->insertChild(Node1);
	newNode->insertChild(Node2);
	newNode->insertChild((yyvsp[(3) - (4)].BITNODE));
	newNode->insertChild(Node4);

	cout<<"factor -> id ( expression_list ) [OK]"<<endl;
	(yyval.BITNODE) = newNode;
}
    break;

  case 239:
/* Line 1792 of yacc.c  */
#line 1803 "yacc.y"
    {
	// if($1->token.compare("(") != 0 || $3->token.compare(")") != 0)
	//	yyerror("");

	BitNode *newNode, *Node1, *Node3;
	newNode = new BitNode(yycolumn,yylineno,"", "factor");
	Node1 = new BitNode(yycolumn,yylineno,"(", "SEPARATOR");
	Node3 = new BitNode(yycolumn,yylineno,")", "SEPARATOR");

	newNode->insertChild(Node1);
	newNode->insertChild((yyvsp[(2) - (3)].BITNODE));
	newNode->insertChild(Node3);

	cout<<"factor -> ( expression ) [OK]"<<endl;
	(yyval.BITNODE) = newNode;
}
    break;

  case 240:
/* Line 1792 of yacc.c  */
#line 1819 "yacc.y"
    {
	BitNode *newNode, *Node1;
	newNode = new BitNode(yycolumn,yylineno,"", "factor");
	Node1 = new BitNode(yycolumn,yylineno,(yyvsp[(1) - (2)].TYPE)->token, "NOT");

	newNode->insertChild(Node1);
	newNode->insertChild((yyvsp[(2) - (2)].BITNODE));

	cout<<"factor -> not factor [OK]"<<endl;
	(yyval.BITNODE) = newNode;
}
    break;

  case 241:
/* Line 1792 of yacc.c  */
#line 1831 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 242:
/* Line 1792 of yacc.c  */
#line 1837 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 243:
/* Line 1792 of yacc.c  */
#line 1843 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 244:
/* Line 1792 of yacc.c  */
#line 1849 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 245:
/* Line 1792 of yacc.c  */
#line 1855 "yacc.y"
    { 
	BitNode *newNode = new BitNode(yycolumn,yylineno,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
    break;

  case 246:
/* Line 1792 of yacc.c  */
#line 1859 "yacc.y"
    {
	BitNode *newNode, *Node1;
        newNode = new BitNode(yycolumn,yylineno,"", "factor");
        Node1 = new BitNode(yycolumn,yylineno,(yyvsp[(1) - (2)].TYPE)->token, "ADDOP");

        newNode->insertChild(Node1);
        newNode->insertChild((yyvsp[(2) - (2)].BITNODE));

        cout<<"factor -> add factor [OK]"<<endl;
        (yyval.BITNODE) = newNode;
}
    break;

  case 247:
/* Line 1792 of yacc.c  */
#line 1869 "yacc.y"
    {
	BitNode *newNode, *Node1;
        newNode = new BitNode(yycolumn,yylineno,"", "factor");
        Node1 = new BitNode(yycolumn,yylineno,(yyvsp[(1) - (2)].TYPE)->token, "_UMINUS");

        newNode->insertChild(Node1);
        newNode->insertChild((yyvsp[(2) - (2)].BITNODE));

        cout<<"factor -> uminus factor [OK]"<<endl;
        (yyval.BITNODE) = newNode;
}
    break;


/* Line 1792 of yacc.c  */
#line 5139 "y.tab.cpp"
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

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

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
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


/* Line 2055 of yacc.c  */
#line 1881 "yacc.y"


void yyerror(const char *s)
{
	extern char *yytext;
	extern YYSTYPE yylval;
	string error_type(s);
	Error* cur=new Error(error_type,yycolumn,yylineno);
	errorInfo.push_back(cur);
    if_error=1;
	cout<<error_type<<"\tat line:"<<yycolumn<<"\tat:"<<yylineno<<endl;
}

//int main(int argc,char *argv[])
//{
//    extern FILE* yyin;
//    FILE* fin = NULL;
//    fin = fopen(argv[1], "r");
//    if(fin == NULL)
//    {
//       	cout << "Fail to open file. Please try again..." << endl;
//        return -1;
//    }
//    yyin=fin;
//    yyparse();
//    fclose(fin);
//    return 0;
//}