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

BitNode* root;
vector<Error*> errorInfo;
int if_error=0;

void BitNode::insertChild(BitNode* child) {
    children.push_back(child);
	child->father=this;
	cout<<"\t\t"<<this->type<<"\t"<<child->type<<"\t"<<child->data<<"\t"<<endl;
}

BitNode* getBitNode(int yylineno,int yycolumn,string data, string type_val){
	if(type_val.compare("error")==0){
		if_error=1;
		// yyerror(data);
	}
	BitNode* ans=new BitNode(yylineno,yycolumn,data, type_val);
	return ans;
} 


#line 104 "y.tab.cpp"

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

#include "y.tab.hpp"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL__PROGRAM = 3,                   /* _PROGRAM  */
  YYSYMBOL__CONST = 4,                     /* _CONST  */
  YYSYMBOL__VAR = 5,                       /* _VAR  */
  YYSYMBOL__PROCEDURE = 6,                 /* _PROCEDURE  */
  YYSYMBOL__FUNCTION = 7,                  /* _FUNCTION  */
  YYSYMBOL__BEGIN = 8,                     /* _BEGIN  */
  YYSYMBOL__END = 9,                       /* _END  */
  YYSYMBOL__ARRAY = 10,                    /* _ARRAY  */
  YYSYMBOL__OF = 11,                       /* _OF  */
  YYSYMBOL__IF = 12,                       /* _IF  */
  YYSYMBOL__THEN = 13,                     /* _THEN  */
  YYSYMBOL__FOR = 14,                      /* _FOR  */
  YYSYMBOL__TO = 15,                       /* _TO  */
  YYSYMBOL__DO = 16,                       /* _DO  */
  YYSYMBOL__READ = 17,                     /* _READ  */
  YYSYMBOL__WRITE = 18,                    /* _WRITE  */
  YYSYMBOL__WHILE = 19,                    /* _WHILE  */
  YYSYMBOL__NOT = 20,                      /* _NOT  */
  YYSYMBOL__ELSE = 21,                     /* _ELSE  */
  YYSYMBOL__RANGE = 22,                    /* _RANGE  */
  YYSYMBOL__UMINUS = 23,                   /* _UMINUS  */
  YYSYMBOL__ID = 24,                       /* _ID  */
  YYSYMBOL__RELOP = 25,                    /* _RELOP  */
  YYSYMBOL__DIGITS = 26,                   /* _DIGITS  */
  YYSYMBOL__NUM = 27,                      /* _NUM  */
  YYSYMBOL__VARTYPE = 28,                  /* _VARTYPE  */
  YYSYMBOL__ADDOP = 29,                    /* _ADDOP  */
  YYSYMBOL__MULOP = 30,                    /* _MULOP  */
  YYSYMBOL__ASSIGNOP = 31,                 /* _ASSIGNOP  */
  YYSYMBOL__SEPARATOR = 32,                /* _SEPARATOR  */
  YYSYMBOL__CHAR = 33,                     /* _CHAR  */
  YYSYMBOL__BOOLEAN = 34,                  /* _BOOLEAN  */
  YYSYMBOL_35_ = 35,                       /* '.'  */
  YYSYMBOL_36_ = 36,                       /* ';'  */
  YYSYMBOL_37_ = 37,                       /* '('  */
  YYSYMBOL_38_ = 38,                       /* ')'  */
  YYSYMBOL_39_ = 39,                       /* ','  */
  YYSYMBOL_40_ = 40,                       /* ':'  */
  YYSYMBOL_41_ = 41,                       /* '['  */
  YYSYMBOL_42_ = 42,                       /* ']'  */
  YYSYMBOL_YYACCEPT = 43,                  /* $accept  */
  YYSYMBOL_programstruct = 44,             /* programstruct  */
  YYSYMBOL_program_head = 45,              /* program_head  */
  YYSYMBOL_program_body = 46,              /* program_body  */
  YYSYMBOL_idlist = 47,                    /* idlist  */
  YYSYMBOL_const_declarations = 48,        /* const_declarations  */
  YYSYMBOL_const_declaration = 49,         /* const_declaration  */
  YYSYMBOL_const_value = 50,               /* const_value  */
  YYSYMBOL_var_declarations = 51,          /* var_declarations  */
  YYSYMBOL_var_declaration = 52,           /* var_declaration  */
  YYSYMBOL_type = 53,                      /* type  */
  YYSYMBOL_basic_type = 54,                /* basic_type  */
  YYSYMBOL_period = 55,                    /* period  */
  YYSYMBOL_subprogram_declarations = 56,   /* subprogram_declarations  */
  YYSYMBOL_subprogram = 57,                /* subprogram  */
  YYSYMBOL_subprogram_head = 58,           /* subprogram_head  */
  YYSYMBOL_formal_parameter = 59,          /* formal_parameter  */
  YYSYMBOL_parameter_list = 60,            /* parameter_list  */
  YYSYMBOL_parameter = 61,                 /* parameter  */
  YYSYMBOL_var_parameter = 62,             /* var_parameter  */
  YYSYMBOL_value_parameter = 63,           /* value_parameter  */
  YYSYMBOL_subprogram_body = 64,           /* subprogram_body  */
  YYSYMBOL_compound_statement = 65,        /* compound_statement  */
  YYSYMBOL_statement_list = 66,            /* statement_list  */
  YYSYMBOL_statement = 67,                 /* statement  */
  YYSYMBOL_variable_list = 68,             /* variable_list  */
  YYSYMBOL_variable = 69,                  /* variable  */
  YYSYMBOL_id_varpart = 70,                /* id_varpart  */
  YYSYMBOL_procedure_call = 71,            /* procedure_call  */
  YYSYMBOL_else_part = 72,                 /* else_part  */
  YYSYMBOL_expression_list = 73,           /* expression_list  */
  YYSYMBOL_expression = 74,                /* expression  */
  YYSYMBOL_simple_expression = 75,         /* simple_expression  */
  YYSYMBOL_term = 76,                      /* term  */
  YYSYMBOL_factor = 77                     /* factor  */
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
typedef yytype_int16 yy_state_t;

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
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
#define YYFINAL  12
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   2754

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  43
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  35
/* YYNRULES -- Number of rules.  */
#define YYNRULES  247
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  562

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   289


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
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    39,    39,    51,    57,    63,    69,    82,    88,    94,
      99,   118,   124,   130,   137,   143,   150,   156,   167,   173,
     179,   185,   190,   203,   209,   216,   220,   229,   235,   248,
     254,   260,   265,   272,   293,   299,   306,   312,   318,   322,
     340,   346,   352,   357,   376,   389,   394,   399,   410,   421,
     426,   437,   455,   467,   478,   491,   497,   503,   508,   515,
     531,   537,   544,   550,   557,   561,   573,   579,   586,   591,
     600,   604,   623,   629,   636,   642,   649,   655,   660,   670,
     675,   692,   705,   710,   717,   723,   729,   732,   738,   745,
     750,   762,   767,   773,   779,   785,   798,   810,   816,   822,
     826,   841,   847,   853,   859,   866,   872,   884,   891,   897,
     902,   909,   920,   926,   933,   937,   945,   950,   959,   967,
     972,   982,   989,   994,  1005,  1011,  1018,  1023,  1033,  1039,
    1045,  1050,  1063,  1070,  1076,  1082,  1093,  1099,  1106,  1110,
    1117,  1122,  1133,  1139,  1145,  1149,  1157,  1164,  1168,  1182,
    1189,  1195,  1202,  1208,  1212,  1232,  1239,  1245,  1251,  1257,
    1264,  1270,  1277,  1281,  1296,  1302,  1309,  1315,  1321,  1328,
    1335,  1341,  1346,  1361,  1367,  1380,  1387,  1393,  1400,  1405,
    1417,  1423,  1430,  1434,  1443,  1448,  1460,  1466,  1471,  1484,
    1491,  1497,  1502,  1509,  1520,  1526,  1532,  1539,  1545,  1550,
    1566,  1579,  1586,  1590,  1597,  1611,  1617,  1624,  1628,  1637,
    1642,  1654,  1664,  1670,  1676,  1682,  1687,  1698,  1710,  1720,
    1726,  1732,  1738,  1743,  1755,  1761,  1767,  1771,  1780,  1786,
    1796,  1805,  1815,  1824,  1828,  1832,  1839,  1845,  1850,  1867,
    1880,  1892,  1899,  1905,  1912,  1918,  1922,  1932
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
  "\"end of file\"", "error", "\"invalid token\"", "_PROGRAM", "_CONST",
  "_VAR", "_PROCEDURE", "_FUNCTION", "_BEGIN", "_END", "_ARRAY", "_OF",
  "_IF", "_THEN", "_FOR", "_TO", "_DO", "_READ", "_WRITE", "_WHILE",
  "_NOT", "_ELSE", "_RANGE", "_UMINUS", "_ID", "_RELOP", "_DIGITS", "_NUM",
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
  "simple_expression", "term", "factor", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-244)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-245)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
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

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
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

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -244,  -244,  -244,   923,     4,   791,   930,    28,    -1,   922,
     -53,  -220,   991,  1123,  1070,  -244,  1276,  -181,   759,  -244,
    -213,  -244,   -43,   870,     1,  1013,   -93,  -146,  -244,   798,
     193,  -126,   -69,  -243,   287
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     3,     4,     8,   252,     9,    18,    72,    19,    40,
     114,   115,   241,    48,    91,    92,   184,   253,   254,   255,
     256,   193,   151,   152,   153,   288,   215,   207,   155,   496,
     272,   306,   209,   210,   211
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
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

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
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

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
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

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
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
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
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
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
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

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

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

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
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
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* programstruct: program_head program_body '.'  */
#line 39 "yacc.y"
                                             {
	BitNode *Node3 = getBitNode(yylineno,yycolumn,".", "SEPARATOR");

	root = getBitNode(yylineno,yycolumn,"","programstruct");
	root->insertChild((yyvsp[-2].BITNODE));
        root->insertChild((yyvsp[-1].BITNODE));
        root->insertChild(Node3);

	cout << "programstruct -> program_head program_body . [OK]" << endl;
	cout << "Parse OK!" << endl;
        (yyval.BITNODE) = root;
}
#line 1977 "y.tab.cpp"
    break;

  case 3: /* programstruct: error program_body '.'  */
#line 51 "yacc.y"
                         { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
#line 1986 "y.tab.cpp"
    break;

  case 4: /* programstruct: program_head error '.'  */
#line 57 "yacc.y"
                          { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
#line 1995 "y.tab.cpp"
    break;

  case 5: /* programstruct: program_head program_body error  */
#line 63 "yacc.y"
                                   { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	yyerror("missing '.'");
	(yyval.BITNODE) = newNode; 
}
#line 2005 "y.tab.cpp"
    break;

  case 6: /* program_head: _PROGRAM _ID ';'  */
#line 69 "yacc.y"
                               {
	BitNode *newNode, *Node1, *Node2, *Node3;
       	Node1 = getBitNode(yylineno,yycolumn,(yyvsp[-2].TYPE)->token, "PROGRAM");
       	Node2 = getBitNode(yylineno,yycolumn,(yyvsp[-1].TYPE)->token, "ID");
       	Node3 = getBitNode(yylineno,yycolumn,";", "SEPARATOR");
       	newNode = getBitNode(yylineno,yycolumn,"", "program_head");

       	newNode->insertChild(Node1);
       	newNode->insertChild(Node2);
       	newNode->insertChild(Node3);

       	cout<<"program_head -> program id ; [OK]"<<endl;
       	(yyval.BITNODE) = newNode;
}
#line 2024 "y.tab.cpp"
    break;

  case 7: /* program_head: error _ID ';'  */
#line 82 "yacc.y"
                 { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
#line 2033 "y.tab.cpp"
    break;

  case 8: /* program_head: _PROGRAM error ';'  */
#line 88 "yacc.y"
                      { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
#line 2042 "y.tab.cpp"
    break;

  case 9: /* program_head: _PROGRAM _ID error  */
#line 94 "yacc.y"
                      { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	yyerror("missing ';'");
	(yyval.BITNODE) = newNode; 
}
#line 2052 "y.tab.cpp"
    break;

  case 10: /* program_head: _PROGRAM _ID '(' idlist ')' ';'  */
#line 99 "yacc.y"
                                         {
        BitNode *newNode, *Node1, *Node2, *Node3, *Node5, *Node6;
        newNode = getBitNode(yylineno,yycolumn,"", "program_head");
        Node1 = getBitNode(yylineno,yycolumn,(yyvsp[-5].TYPE)->token, "PROGRAM");
        Node2 = getBitNode(yylineno,yycolumn,(yyvsp[-4].TYPE)->token, "ID");
        Node3 = getBitNode(yylineno,yycolumn,"(", "SEPARATOR");
        Node5 = getBitNode(yylineno,yycolumn,")", "SEPARATOR");
        Node6 = getBitNode(yylineno,yycolumn,";", "SEPARATOR");

	newNode->insertChild(Node1);
	newNode->insertChild(Node2);
	newNode->insertChild(Node3);
	newNode->insertChild((yyvsp[-2].BITNODE));
        newNode->insertChild(Node5);
        newNode->insertChild(Node6);

        cout<<"program_head -> program id ( idlist ) ; [OK]"<<endl;
	(yyval.BITNODE) = newNode;
}
#line 2076 "y.tab.cpp"
    break;

  case 11: /* program_head: error _ID '(' idlist ')' ';'  */
#line 118 "yacc.y"
                               { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
#line 2085 "y.tab.cpp"
    break;

  case 12: /* program_head: _PROGRAM error '(' idlist ')' ';'  */
#line 124 "yacc.y"
                                     { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
#line 2094 "y.tab.cpp"
    break;

  case 13: /* program_head: _PROGRAM _ID error idlist ')' ';'  */
#line 130 "yacc.y"
                                     { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	yyerror("missing '('");
	(yyval.BITNODE) = newNode; 
}
#line 2104 "y.tab.cpp"
    break;

  case 14: /* program_head: _PROGRAM _ID '(' error ')' ';'  */
#line 137 "yacc.y"
                                  { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
#line 2113 "y.tab.cpp"
    break;

  case 15: /* program_head: _PROGRAM _ID '(' idlist error ';'  */
#line 143 "yacc.y"
                                     { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	yyerror("missing ')'");
	(yyval.BITNODE) = newNode; 
}
#line 2123 "y.tab.cpp"
    break;

  case 16: /* program_head: _PROGRAM _ID '(' idlist ')' error  */
#line 150 "yacc.y"
                                     { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	yyerror("missing ';'");
	(yyval.BITNODE) = newNode; 
}
#line 2133 "y.tab.cpp"
    break;

  case 17: /* program_body: const_declarations var_declarations subprogram_declarations compound_statement  */
#line 156 "yacc.y"
                                                                                             {
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "program_body");

	newNode->insertChild((yyvsp[-3].BITNODE));
	newNode->insertChild((yyvsp[-2].BITNODE));
	newNode->insertChild((yyvsp[-1].BITNODE));
	newNode->insertChild((yyvsp[0].BITNODE));

	cout<<"program_body -> const_declarations var_declarationssubprogram_declarations compound_statement [OK]"<<endl;
	(yyval.BITNODE) = newNode;
}
#line 2149 "y.tab.cpp"
    break;

  case 18: /* program_body: error var_declarations subprogram_declarations compound_statement  */
#line 167 "yacc.y"
                                                                     { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
#line 2158 "y.tab.cpp"
    break;

  case 19: /* program_body: const_declarations error subprogram_declarations compound_statement  */
#line 173 "yacc.y"
                                                                       { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
#line 2167 "y.tab.cpp"
    break;

  case 20: /* program_body: const_declarations var_declarations error compound_statement  */
#line 179 "yacc.y"
                                                                { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
#line 2176 "y.tab.cpp"
    break;

  case 21: /* program_body: const_declarations var_declarations subprogram_declarations error  */
#line 185 "yacc.y"
                                                                     { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
#line 2185 "y.tab.cpp"
    break;

  case 22: /* idlist: idlist ',' _ID  */
#line 190 "yacc.y"
                       {
	BitNode *newNode, *Node2, *Node3;
	newNode = getBitNode(yylineno,yycolumn,"", "idlist");
	Node2 = getBitNode(yylineno,yycolumn,",", "SEPARATOR");
	Node3 = getBitNode(yylineno,yycolumn,(yyvsp[0].TYPE)->token, "ID");

	newNode->insertChild((yyvsp[-2].BITNODE));
	newNode->insertChild(Node2);
	newNode->insertChild(Node3);

	cout<<"idlist -> idlist , id [OK]"<<endl;
	(yyval.BITNODE) = newNode;
}
#line 2203 "y.tab.cpp"
    break;

  case 23: /* idlist: error ',' _ID  */
#line 203 "yacc.y"
                { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
#line 2212 "y.tab.cpp"
    break;

  case 24: /* idlist: idlist error _ID  */
#line 209 "yacc.y"
                    { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	yyerror("missing ','");
	(yyval.BITNODE) = newNode; 
}
#line 2222 "y.tab.cpp"
    break;

  case 25: /* idlist: idlist ',' error  */
#line 216 "yacc.y"
                    { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
#line 2231 "y.tab.cpp"
    break;

  case 26: /* idlist: _ID  */
#line 220 "yacc.y"
              {
	BitNode *newNode, *Node1;
	newNode = getBitNode(yylineno,yycolumn,"", "idlist");
	Node1 = getBitNode(yylineno,yycolumn,(yyvsp[0].TYPE)->token, "ID");
	newNode->insertChild(Node1);

	cout<<"idlist -> id [OK]"<<endl;
	(yyval.BITNODE) = newNode;
}
#line 2245 "y.tab.cpp"
    break;

  case 27: /* idlist: error  */
#line 229 "yacc.y"
        { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	yyerror("missing id");
	(yyval.BITNODE) = newNode; 
}
#line 2255 "y.tab.cpp"
    break;

  case 28: /* const_declarations: _CONST const_declaration ';'  */
#line 235 "yacc.y"
                                                 {
	BitNode *newNode, *Node1, *Node3;
	newNode = getBitNode(yylineno,yycolumn,"", "const_declarations");
	Node1 = getBitNode(yylineno,yycolumn,(yyvsp[-2].TYPE)->token, "CONST");
	Node3 = getBitNode(yylineno,yycolumn,";", "SEPARATOR");

	newNode->insertChild(Node1);
	newNode->insertChild((yyvsp[-1].BITNODE));
	newNode->insertChild(Node3);

	cout<<"const_declarations -> const const_declaration ; [OK]"<<endl;
	(yyval.BITNODE) = newNode;
}
#line 2273 "y.tab.cpp"
    break;

  case 29: /* const_declarations: error const_declaration ';'  */
#line 248 "yacc.y"
                              { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
#line 2282 "y.tab.cpp"
    break;

  case 30: /* const_declarations: _CONST error ';'  */
#line 254 "yacc.y"
                    { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
#line 2291 "y.tab.cpp"
    break;

  case 31: /* const_declarations: _CONST const_declaration error  */
#line 260 "yacc.y"
                                  { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	yyerror("missing ';'");
	(yyval.BITNODE) = newNode; 
}
#line 2301 "y.tab.cpp"
    break;

  case 32: /* const_declarations: %empty  */
#line 265 "yacc.y"
          {
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "const_declarations");

	cout<<"const_declarations -> empty [OK]"<<endl;
	(yyval.BITNODE) = newNode;
}
#line 2312 "y.tab.cpp"
    break;

  case 33: /* const_declaration: const_declaration ';' _ID _RELOP const_value  */
#line 272 "yacc.y"
                                                                {
	if((yyvsp[-1].TYPE)->token.compare("=") != 0){
			cout<<(yyvsp[-1].TYPE)->token<<"     not   ="<<endl;
        	yyerror("");
	}

	BitNode *newNode, *Node2, *Node3, *Node4;
	newNode = getBitNode(yylineno,yycolumn,"", "const_declaration");
	Node2 = getBitNode(yylineno,yycolumn,";", "SEPARATOR");
	Node3 = getBitNode(yylineno,yycolumn,(yyvsp[-2].TYPE)->token, "ID");
	Node4 = getBitNode(yylineno,yycolumn,(yyvsp[-1].TYPE)->token, "RELOP");

	newNode->insertChild((yyvsp[-4].BITNODE));
	newNode->insertChild(Node2);
	newNode->insertChild(Node3);
	newNode->insertChild(Node4);
	newNode->insertChild((yyvsp[0].BITNODE));

	cout<<"const_declaration -> const_declaration ; id = const_value [OK]"<<endl;
	(yyval.BITNODE) = newNode;
}
#line 2338 "y.tab.cpp"
    break;

  case 34: /* const_declaration: error ';' _ID _RELOP const_value  */
#line 293 "yacc.y"
                                   { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
#line 2347 "y.tab.cpp"
    break;

  case 35: /* const_declaration: const_declaration error _ID _RELOP const_value  */
#line 299 "yacc.y"
                                                  { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	yyerror("missing ';'");
	(yyval.BITNODE) = newNode; 
}
#line 2357 "y.tab.cpp"
    break;

  case 36: /* const_declaration: const_declaration ';' error _RELOP const_value  */
#line 306 "yacc.y"
                                                  { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
#line 2366 "y.tab.cpp"
    break;

  case 37: /* const_declaration: const_declaration ';' _ID error const_value  */
#line 312 "yacc.y"
                                               { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
#line 2375 "y.tab.cpp"
    break;

  case 38: /* const_declaration: const_declaration ';' _ID _RELOP error  */
#line 318 "yacc.y"
                                          { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
#line 2384 "y.tab.cpp"
    break;

  case 39: /* const_declaration: _ID _RELOP const_value  */
#line 322 "yacc.y"
                                 {
 	if((yyvsp[-1].TYPE)->token.compare("=")!=0){
			cout<<(yyvsp[-1].TYPE)->token<<"     not   ="<<endl;
        	yyerror("");
	}

	BitNode *newNode, *Node1, *Node2;
	newNode = getBitNode(yylineno,yycolumn,"", "const_declaration");
	Node1 = getBitNode(yylineno,yycolumn,(yyvsp[-2].TYPE)->token, "ID");
	Node2 = getBitNode(yylineno,yycolumn,(yyvsp[-1].TYPE)->token, "RELOP");

	newNode->insertChild(Node1);
	newNode->insertChild(Node2);
	newNode->insertChild((yyvsp[0].BITNODE));

	cout<<"const_declaration -> id = const_value [OK]"<<endl;
	(yyval.BITNODE) = newNode;
}
#line 2407 "y.tab.cpp"
    break;

  case 40: /* const_declaration: error _RELOP const_value  */
#line 340 "yacc.y"
                            { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
#line 2416 "y.tab.cpp"
    break;

  case 41: /* const_declaration: _ID error const_value  */
#line 346 "yacc.y"
                         { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
#line 2425 "y.tab.cpp"
    break;

  case 42: /* const_declaration: _ID _RELOP error  */
#line 352 "yacc.y"
                    { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
#line 2434 "y.tab.cpp"
    break;

  case 43: /* const_value: _ADDOP _NUM  */
#line 357 "yacc.y"
                         {
	if((yyvsp[-1].TYPE)->token.compare("+") != 0){
		// 修改终结符判断逻辑，因为对终结符 ADDOP的内容为 + or
		cout<<(yyvsp[-1].TYPE)->token<<"     not   +"<<endl; 
		yyerror("");
	}

	BitNode *newNode, *Node1, *Node2;
	newNode = getBitNode(yylineno,yycolumn, "", "const_value");
	Node1 = getBitNode(yylineno,yycolumn, (yyvsp[-1].TYPE)->token, "ADDOP");
	Node2 = getBitNode(yylineno,yycolumn, (yyvsp[0].TYPE)->token, "NUM");

	newNode->insertChild(Node1);
	newNode->insertChild(Node2);

	cout<<"const_value -> + num [OK]"<<endl;
	(yyval.BITNODE) = newNode;
}
#line 2457 "y.tab.cpp"
    break;

  case 44: /* const_value: _UMINUS _NUM  */
#line 376 "yacc.y"
                       { // 增加 UMINUS 的关联生成式
	BitNode *newNode, *Node1, *Node2;
	newNode = getBitNode(yylineno,yycolumn, "", "const_value");
	Node1 = getBitNode(yylineno,yycolumn, (yyvsp[-1].TYPE)->token, "UMINUS");
	Node2 = getBitNode(yylineno,yycolumn, (yyvsp[0].TYPE)->token, "NUM");

	newNode->insertChild(Node1);
	newNode->insertChild(Node2);

	cout<<"const_value -> - num [OK]"<<endl;
	(yyval.BITNODE) = newNode;
}
#line 2474 "y.tab.cpp"
    break;

  case 45: /* const_value: error _NUM  */
#line 389 "yacc.y"
                     {
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
#line 2483 "y.tab.cpp"
    break;

  case 46: /* const_value: _ADDOP error  */
#line 394 "yacc.y"
                       {
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
#line 2492 "y.tab.cpp"
    break;

  case 47: /* const_value: _NUM  */
#line 399 "yacc.y"
               {
	BitNode *newNode, *Node1;
	newNode = getBitNode(yylineno,yycolumn,"", "const_value");
	Node1 = getBitNode(yylineno,yycolumn,(yyvsp[0].TYPE)->token, "NUM");

	newNode->insertChild(Node1);

	cout<<"const_value -> num [OK]"<<endl;
	(yyval.BITNODE) = newNode;
}
#line 2507 "y.tab.cpp"
    break;

  case 48: /* const_value: _CHAR  */
#line 410 "yacc.y"
                  { // 处理单个字符
	BitNode *newNode, *Node1;
	newNode = getBitNode(yylineno,yycolumn,"", "const_value");
	Node1 = getBitNode(yylineno,yycolumn,(yyvsp[0].TYPE)->token, "CHAR");

	newNode->insertChild(Node1);

	cout<<"const_value -> char [OK]"<<endl;
	(yyval.BITNODE) = newNode;
}
#line 2522 "y.tab.cpp"
    break;

  case 49: /* const_value: error  */
#line 421 "yacc.y"
                {
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
#line 2531 "y.tab.cpp"
    break;

  case 50: /* const_value: _DIGITS  */
#line 426 "yacc.y"
                  { // 增加处理 digits 的生成式
	BitNode *newNode, *Node1;
	newNode = getBitNode(yylineno,yycolumn, "", "const_value");
	Node1 = getBitNode(yylineno,yycolumn, (yyvsp[0].TYPE)->token, "DIGITS");

	newNode->insertChild(Node1);

	cout<<"const_value -> digits [OK]"<<endl;
        (yyval.BITNODE) = newNode;
}
#line 2546 "y.tab.cpp"
    break;

  case 51: /* const_value: _ADDOP _DIGITS  */
#line 437 "yacc.y"
                         { // 增加处理 digits 关联的生成式
	if((yyvsp[-1].TYPE)->token.compare("+") != 0) {
		// ADDOP包括两种运算：+ or
		cout<<(yyvsp[-1].TYPE)->token<<"     not    +"<<endl;
		yyerror("");
	}

	BitNode *newNode, *Node1, *Node2;
	newNode = getBitNode(yylineno,yycolumn,"", "const_value");
	Node1 = getBitNode(yylineno,yycolumn, (yyvsp[-1].TYPE)->token, "ADDOP");
	Node2 = getBitNode(yylineno,yycolumn, (yyvsp[0].TYPE)->token, "DIGITS");

	newNode->insertChild(Node1);
	newNode->insertChild(Node2);

	cout<<"const_value -> + digits [OK]"<<endl;
	(yyval.BITNODE) = newNode;
}
#line 2569 "y.tab.cpp"
    break;

  case 52: /* const_value: _UMINUS _DIGITS  */
#line 455 "yacc.y"
                          { // 增加处理 digits 关联的生成式
	BitNode *newNode, *Node1, *Node2;
	newNode = getBitNode(yylineno,yycolumn,"", "const_value");
	Node1 = getBitNode(yylineno,yycolumn, (yyvsp[-1].TYPE)->token, "UMINUS");
	Node2 = getBitNode(yylineno,yycolumn, (yyvsp[0].TYPE)->token, "DIGITS");

	newNode->insertChild(Node1);
	newNode->insertChild(Node2);

	cout<<"const_value -> - digits [OK]"<<endl;
	(yyval.BITNODE) = newNode;
}
#line 2586 "y.tab.cpp"
    break;

  case 53: /* const_value: _BOOLEAN  */
#line 467 "yacc.y"
                  { // 增加处理 boolean 的生成式
	BitNode *newNode, *Node1;
	newNode = getBitNode(yylineno,yycolumn, "", "const_value");
	Node1 = getBitNode(yylineno,yycolumn, (yyvsp[0].TYPE)->token, "BOOLEAN");

	newNode->insertChild(Node1);

	cout<<"const_value -> boolean [OK]"<<endl;
        (yyval.BITNODE) = newNode;
}
#line 2601 "y.tab.cpp"
    break;

  case 54: /* var_declarations: _VAR var_declaration ';'  */
#line 478 "yacc.y"
                                           {
	BitNode *newNode, *Node1, *Node3;
	newNode = getBitNode(yylineno,yycolumn,"", "var_declarations");
	Node1 = getBitNode(yylineno,yycolumn,(yyvsp[-2].TYPE)->token, "VAR");
	Node3 = getBitNode(yylineno,yycolumn,";", "SEPARATOR");

	newNode->insertChild(Node1);
	newNode->insertChild((yyvsp[-1].BITNODE));
	newNode->insertChild(Node3);

	cout<<"var_declarations -> var var_declaration ; [OK]"<<endl;
	(yyval.BITNODE) = newNode;
}
#line 2619 "y.tab.cpp"
    break;

  case 55: /* var_declarations: error var_declaration ';'  */
#line 491 "yacc.y"
                            { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
#line 2628 "y.tab.cpp"
    break;

  case 56: /* var_declarations: _VAR error ';'  */
#line 497 "yacc.y"
                  { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
#line 2637 "y.tab.cpp"
    break;

  case 57: /* var_declarations: _VAR var_declaration error  */
#line 503 "yacc.y"
                              { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	yyerror("missing ';'");
	(yyval.BITNODE) = newNode; 
}
#line 2647 "y.tab.cpp"
    break;

  case 58: /* var_declarations: %empty  */
#line 508 "yacc.y"
          {
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "var_declarations");

	cout<<"var_declarations -> empty [OK]"<<endl;
	(yyval.BITNODE) = newNode;
}
#line 2658 "y.tab.cpp"
    break;

  case 59: /* var_declaration: var_declaration ';' idlist ':' type  */
#line 515 "yacc.y"
                                                     {
	BitNode *newNode, *Node2, *Node4;
	newNode = getBitNode(yylineno,yycolumn,"", "var_declaration");
	Node2 = getBitNode(yylineno,yycolumn,";", "SEPARATOR");
	Node4 = getBitNode(yylineno,yycolumn,":", "SEPARATOR");

	newNode->insertChild((yyvsp[-4].BITNODE));
	newNode->insertChild(Node2);
	newNode->insertChild((yyvsp[-2].BITNODE));
	newNode->insertChild(Node4);
	newNode->insertChild((yyvsp[0].BITNODE));

	cout<<"var_declaration -> var_declaration ; idlist : type [OK]"<<endl;
	(yyval.BITNODE) = newNode;
}
#line 2678 "y.tab.cpp"
    break;

  case 60: /* var_declaration: error ';' idlist ':' type  */
#line 531 "yacc.y"
                             { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
#line 2687 "y.tab.cpp"
    break;

  case 61: /* var_declaration: var_declaration error idlist ':' type  */
#line 537 "yacc.y"
                                         { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	yyerror("missing ';'");
	(yyval.BITNODE) = newNode; 
}
#line 2697 "y.tab.cpp"
    break;

  case 62: /* var_declaration: var_declaration ';' error ':' type  */
#line 544 "yacc.y"
                                      { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
#line 2706 "y.tab.cpp"
    break;

  case 63: /* var_declaration: var_declaration ';' idlist error type  */
#line 550 "yacc.y"
                                         { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	yyerror("missing ':'");
	(yyval.BITNODE) = newNode; 
}
#line 2716 "y.tab.cpp"
    break;

  case 64: /* var_declaration: var_declaration ';' idlist ':' error  */
#line 557 "yacc.y"
                                        { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
#line 2725 "y.tab.cpp"
    break;

  case 65: /* var_declaration: idlist ':' type  */
#line 561 "yacc.y"
                          {
	BitNode *newNode, *Node2;
	newNode = getBitNode(yylineno,yycolumn,"", "var_declaration");
	Node2 = getBitNode(yylineno,yycolumn,":", "SEPARATOR");

	newNode->insertChild((yyvsp[-2].BITNODE));
	newNode->insertChild(Node2);
	newNode->insertChild((yyvsp[0].BITNODE));

	cout<<"var_declaration -> idlist : type [OK]"<<endl;
	(yyval.BITNODE) = newNode;
}
#line 2742 "y.tab.cpp"
    break;

  case 66: /* var_declaration: error ':' type  */
#line 573 "yacc.y"
                 { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
#line 2751 "y.tab.cpp"
    break;

  case 67: /* var_declaration: idlist error type  */
#line 579 "yacc.y"
                     { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	yyerror("missing ':'");
	(yyval.BITNODE) = newNode; 
}
#line 2761 "y.tab.cpp"
    break;

  case 68: /* var_declaration: idlist ':' error  */
#line 586 "yacc.y"
                    { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
#line 2770 "y.tab.cpp"
    break;

  case 69: /* type: basic_type  */
#line 591 "yacc.y"
                 {
	BitNode *newNode;
	newNode = getBitNode(yylineno,yycolumn,"", "type");

	newNode->insertChild((yyvsp[0].BITNODE));

	cout<<"type -> basic_type [OK]"<<endl;
	(yyval.BITNODE) = newNode;
}
#line 2784 "y.tab.cpp"
    break;

  case 70: /* type: error  */
#line 600 "yacc.y"
        { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
#line 2793 "y.tab.cpp"
    break;

  case 71: /* type: _ARRAY '[' period ']' _OF basic_type  */
#line 604 "yacc.y"
                                               {
	BitNode *newNode, *Node1, *Node2, *Node4, *Node5;
	newNode = getBitNode(yylineno,yycolumn,"", "type");
	Node1 = getBitNode(yylineno,yycolumn,(yyvsp[-5].TYPE)->token, "ARRAY");
	Node2 = getBitNode(yylineno,yycolumn,"[", "SEPARATOR");
	Node4 = getBitNode(yylineno,yycolumn,"]", "SEPARATOR");
	Node5 = getBitNode(yylineno,yycolumn,(yyvsp[-1].TYPE)->token, "OF");

	newNode->insertChild(Node1);
	newNode->insertChild(Node2);
	newNode->insertChild((yyvsp[-3].BITNODE));
	newNode->insertChild(Node4);
	newNode->insertChild(Node5);
	newNode->insertChild((yyvsp[0].BITNODE));

	cout<<"type -> array [ period ] of basic_type [OK]"<<endl;
	(yyval.BITNODE) = newNode;
}
#line 2816 "y.tab.cpp"
    break;

  case 72: /* type: error '[' period ']' _OF basic_type  */
#line 623 "yacc.y"
                                       { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
#line 2825 "y.tab.cpp"
    break;

  case 73: /* type: _ARRAY error period ']' _OF basic_type  */
#line 629 "yacc.y"
                                          { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	yyerror("missing '['");
	(yyval.BITNODE) = newNode; 
}
#line 2835 "y.tab.cpp"
    break;

  case 74: /* type: _ARRAY '[' error ']' _OF basic_type  */
#line 636 "yacc.y"
                                       { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
#line 2844 "y.tab.cpp"
    break;

  case 75: /* type: _ARRAY '[' period error _OF basic_type  */
#line 642 "yacc.y"
                                          { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	yyerror("missing ']'");
	(yyval.BITNODE) = newNode; 
}
#line 2854 "y.tab.cpp"
    break;

  case 76: /* type: _ARRAY '[' period ']' error basic_type  */
#line 649 "yacc.y"
                                          { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
#line 2863 "y.tab.cpp"
    break;

  case 77: /* type: _ARRAY '[' period ']' _OF error  */
#line 655 "yacc.y"
                                   { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
#line 2872 "y.tab.cpp"
    break;

  case 78: /* basic_type: _VARTYPE  */
#line 660 "yacc.y"
                     {
	BitNode *newNode, *Node1;
	newNode = getBitNode(yylineno,yycolumn,"", "basic_type");
	Node1 = getBitNode(yylineno,yycolumn,(yyvsp[0].TYPE)->token, "VARTYPE");

	newNode->insertChild(Node1);

	cout<<"type -> basic_type [OK]"<<endl;
	(yyval.BITNODE) = newNode;
}
#line 2887 "y.tab.cpp"
    break;

  case 79: /* basic_type: error  */
#line 670 "yacc.y"
        { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
#line 2896 "y.tab.cpp"
    break;

  case 80: /* period: period ',' _DIGITS _RANGE _DIGITS  */
#line 675 "yacc.y"
                                         {
	BitNode *newNode, *Node2, *Node3, *Node4, *Node5;
	newNode = getBitNode(yylineno,yycolumn,"", "period");
	Node2 = getBitNode(yylineno,yycolumn,",", "SEPARATOR");
	Node3 = getBitNode(yylineno,yycolumn,(yyvsp[-2].TYPE)->token, "DIGITS");
	Node4 = getBitNode(yylineno,yycolumn,(yyvsp[-1].TYPE)->token, "RANGE");
	Node5 = getBitNode(yylineno,yycolumn,(yyvsp[0].TYPE)->token, "DIGITS");

	newNode->insertChild((yyvsp[-4].BITNODE));
	newNode->insertChild(Node2);
	newNode->insertChild(Node3);
	newNode->insertChild(Node4);
	newNode->insertChild(Node5);

	cout<<"period -> period , digits .. digits [OK]"<<endl;
	(yyval.BITNODE) = newNode;
}
#line 2918 "y.tab.cpp"
    break;

  case 81: /* period: _DIGITS _RANGE _DIGITS  */
#line 692 "yacc.y"
                                 {
	BitNode *newNode, *Node1, *Node2, *Node3;
	newNode = getBitNode(yylineno,yycolumn,"", "period");
	Node1 = getBitNode(yylineno,yycolumn,(yyvsp[-2].TYPE)->token, "DIGITS");
	Node2 = getBitNode(yylineno,yycolumn,(yyvsp[-1].TYPE)->token, "RANGE");
	Node3 = getBitNode(yylineno,yycolumn,(yyvsp[0].TYPE)->token, "DIGITS");

	newNode->insertChild(Node1);
	newNode->insertChild(Node2);
	newNode->insertChild(Node3);

	cout<<"period -> digits .. digits [OK]"<<endl;
	(yyval.BITNODE) = newNode;
}
#line 2937 "y.tab.cpp"
    break;

  case 82: /* period: error ',' _DIGITS _RANGE _DIGITS  */
#line 705 "yacc.y"
                                     { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
#line 2946 "y.tab.cpp"
    break;

  case 83: /* period: period error _DIGITS _RANGE _DIGITS  */
#line 710 "yacc.y"
                                       { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	yyerror("missing ','");
	(yyval.BITNODE) = newNode; 
}
#line 2956 "y.tab.cpp"
    break;

  case 84: /* period: period ',' error _RANGE _DIGITS  */
#line 717 "yacc.y"
                                   { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
#line 2965 "y.tab.cpp"
    break;

  case 85: /* period: period ',' _DIGITS error _DIGITS  */
#line 723 "yacc.y"
                                    { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
#line 2974 "y.tab.cpp"
    break;

  case 86: /* period: period ',' _DIGITS _RANGE error  */
#line 729 "yacc.y"
                                   { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
#line 2983 "y.tab.cpp"
    break;

  case 87: /* period: error _RANGE _DIGITS  */
#line 732 "yacc.y"
                         { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
#line 2992 "y.tab.cpp"
    break;

  case 88: /* period: _DIGITS error _DIGITS  */
#line 738 "yacc.y"
                         { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	yyerror("missing '..'");
	(yyval.BITNODE) = newNode; 
}
#line 3002 "y.tab.cpp"
    break;

  case 89: /* period: _DIGITS _RANGE error  */
#line 745 "yacc.y"
                        { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
#line 3011 "y.tab.cpp"
    break;

  case 90: /* subprogram_declarations: subprogram_declarations subprogram ';'  */
#line 750 "yacc.y"
                                                                {
	BitNode *newNode, *Node3;
	newNode = getBitNode(yylineno,yycolumn,"", "subprogram_declarations");
	Node3 = getBitNode(yylineno,yycolumn,";", "SEPARATOR");

	newNode->insertChild((yyvsp[-2].BITNODE));
	newNode->insertChild((yyvsp[-1].BITNODE));
	newNode->insertChild(Node3);

	cout<<"subprogram_declarations -> subprogram_declarations subprogram ; [OK]"<<endl;
	(yyval.BITNODE) = newNode;
}
#line 3028 "y.tab.cpp"
    break;

  case 91: /* subprogram_declarations: %empty  */
#line 762 "yacc.y"
          {
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "subprogram_declarations");

	cout<<"subprogram_declarations -> empty [OK]"<<endl;
	(yyval.BITNODE) = newNode;
}
#line 3039 "y.tab.cpp"
    break;

  case 92: /* subprogram_declarations: error subprogram ';'  */
#line 767 "yacc.y"
                        { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
#line 3048 "y.tab.cpp"
    break;

  case 93: /* subprogram_declarations: subprogram_declarations error ';'  */
#line 773 "yacc.y"
                                     { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
#line 3057 "y.tab.cpp"
    break;

  case 94: /* subprogram_declarations: subprogram_declarations subprogram error  */
#line 779 "yacc.y"
                                            { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	yyerror("missing ';'");
	(yyval.BITNODE) = newNode; 
}
#line 3067 "y.tab.cpp"
    break;

  case 95: /* subprogram: subprogram_head ';' subprogram_body  */
#line 785 "yacc.y"
                                                {
	BitNode *newNode, *Node2;
	newNode = getBitNode(yylineno,yycolumn,"", "subprogram");
	Node2 = getBitNode(yylineno,yycolumn,";", "SEPARATOR");

	newNode->insertChild((yyvsp[-2].BITNODE));
	newNode->insertChild(Node2);
	newNode->insertChild((yyvsp[0].BITNODE));

	cout<<"subprogram -> subprogram_head _SEPARATOR subprogram_body [OK]"<<endl;
	(yyval.BITNODE) = newNode;
}
#line 3084 "y.tab.cpp"
    break;

  case 96: /* subprogram_head: _PROCEDURE _ID formal_parameter  */
#line 798 "yacc.y"
                                                 {
	BitNode *newNode, *Node1, *Node2;
	newNode = getBitNode(yylineno,yycolumn,"", "subprogram_head");
	Node1 = getBitNode(yylineno,yycolumn,(yyvsp[-2].TYPE)->token, "PROCEDURE");
	Node2 = getBitNode(yylineno,yycolumn,(yyvsp[-1].TYPE)->token, "ID");

	newNode->insertChild(Node1);
	newNode->insertChild(Node2);
	newNode->insertChild((yyvsp[0].BITNODE));

	cout<<"subprogram_head -> procedure id formal_parameter [OK]"<<endl;
	(yyval.BITNODE) = newNode;
}
#line 3102 "y.tab.cpp"
    break;

  case 97: /* subprogram_head: error _ID formal_parameter  */
#line 810 "yacc.y"
                               { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
#line 3111 "y.tab.cpp"
    break;

  case 98: /* subprogram_head: _PROCEDURE error formal_parameter  */
#line 816 "yacc.y"
                                     { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
#line 3120 "y.tab.cpp"
    break;

  case 99: /* subprogram_head: _PROCEDURE _ID error  */
#line 822 "yacc.y"
                        { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
#line 3129 "y.tab.cpp"
    break;

  case 100: /* subprogram_head: _FUNCTION _ID formal_parameter ':' basic_type  */
#line 826 "yacc.y"
                                                        {
	BitNode *newNode,*Node1, *Node2, *Node4;
	newNode = getBitNode(yylineno,yycolumn,"", "subprogram_head");
	Node1 = getBitNode(yylineno,yycolumn,(yyvsp[-4].TYPE)->token, "FUNCTION");
	Node2 = getBitNode(yylineno,yycolumn,(yyvsp[-3].TYPE)->token, "ID");
	Node4 = getBitNode(yylineno,yycolumn,":", "SEPARATOR");

	newNode->insertChild(Node1);
	newNode->insertChild(Node2);
	newNode->insertChild((yyvsp[-2].BITNODE));
	newNode->insertChild(Node4);
	newNode->insertChild((yyvsp[0].BITNODE));

	cout<<"subprogram_head -> function id formal_parameter : basic_type [OK]"<<endl;
	(yyval.BITNODE) = newNode;
}
#line 3150 "y.tab.cpp"
    break;

  case 101: /* subprogram_head: error _ID formal_parameter ':' basic_type  */
#line 841 "yacc.y"
                                             { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
#line 3159 "y.tab.cpp"
    break;

  case 102: /* subprogram_head: _FUNCTION error formal_parameter ':' basic_type  */
#line 847 "yacc.y"
                                                   { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
#line 3168 "y.tab.cpp"
    break;

  case 103: /* subprogram_head: _FUNCTION _ID error ':' basic_type  */
#line 853 "yacc.y"
                                      { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
#line 3177 "y.tab.cpp"
    break;

  case 104: /* subprogram_head: _FUNCTION _ID formal_parameter error basic_type  */
#line 859 "yacc.y"
                                                   { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	yyerror("missing ':'");
	(yyval.BITNODE) = newNode; 
}
#line 3187 "y.tab.cpp"
    break;

  case 105: /* subprogram_head: _FUNCTION _ID formal_parameter ':' error  */
#line 866 "yacc.y"
                                            { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
#line 3196 "y.tab.cpp"
    break;

  case 106: /* formal_parameter: '(' parameter_list ')'  */
#line 872 "yacc.y"
                                         {
	BitNode *newNode, *Node1, *Node3;
	newNode = getBitNode(yylineno,yycolumn,"", "formal_parameter");
	Node1 = getBitNode(yylineno,yycolumn,"(", "SEPARATOR");
	Node3 = getBitNode(yylineno,yycolumn,")", "SEPARATOR");

	newNode->insertChild(Node1);
	newNode->insertChild((yyvsp[-1].BITNODE));
	newNode->insertChild(Node3);

	cout<<" formal_parameter -> ( parameter_list ) [OK]"<<endl;
	(yyval.BITNODE) = newNode;
}
#line 3214 "y.tab.cpp"
    break;

  case 107: /* formal_parameter: error parameter_list ')'  */
#line 884 "yacc.y"
                             { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	yyerror("missing '('");
	(yyval.BITNODE) = newNode; 
}
#line 3224 "y.tab.cpp"
    break;

  case 108: /* formal_parameter: '(' error ')'  */
#line 891 "yacc.y"
                 { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
#line 3233 "y.tab.cpp"
    break;

  case 109: /* formal_parameter: '(' parameter_list error  */
#line 897 "yacc.y"
                            { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	yyerror("missing ')'");
	(yyval.BITNODE) = newNode; 
}
#line 3243 "y.tab.cpp"
    break;

  case 110: /* formal_parameter: %empty  */
#line 902 "yacc.y"
         {
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "formal_parameter");

	cout<<"formal_parameter -> empty [OK]"<<endl;
	(yyval.BITNODE) = newNode;
}
#line 3254 "y.tab.cpp"
    break;

  case 111: /* parameter_list: parameter_list ';' parameter  */
#line 909 "yacc.y"
                                             {
	BitNode *newNode, *Node2;
	newNode = getBitNode(yylineno,yycolumn,"", "parameter_list");
	Node2 = getBitNode(yylineno,yycolumn,";", "SEPARATOR");

	newNode->insertChild((yyvsp[-2].BITNODE));
	newNode->insertChild(Node2);
	newNode->insertChild((yyvsp[0].BITNODE));

	cout<<"parameter_list -> parameter_list _SEPARATOR parameter [OK]"<<endl;
	(yyval.BITNODE) = newNode;
}
#line 3271 "y.tab.cpp"
    break;

  case 112: /* parameter_list: error ';' parameter  */
#line 920 "yacc.y"
                        { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
#line 3280 "y.tab.cpp"
    break;

  case 113: /* parameter_list: parameter_list error parameter  */
#line 926 "yacc.y"
                                  { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	yyerror("missing ';'");
	(yyval.BITNODE) = newNode; 
}
#line 3290 "y.tab.cpp"
    break;

  case 114: /* parameter_list: parameter_list ';' error  */
#line 933 "yacc.y"
                            { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
#line 3299 "y.tab.cpp"
    break;

  case 115: /* parameter_list: parameter  */
#line 937 "yacc.y"
                    {
	BitNode * newNode;
	newNode = getBitNode(yylineno,yycolumn,"", "parameter_list");

	newNode->insertChild((yyvsp[0].BITNODE));

	cout<<"parameter_list -> parameter [OK]"<<endl;
	(yyval.BITNODE) = newNode;
}
#line 3313 "y.tab.cpp"
    break;

  case 116: /* parameter_list: error  */
#line 945 "yacc.y"
          { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
#line 3322 "y.tab.cpp"
    break;

  case 117: /* parameter: var_parameter  */
#line 950 "yacc.y"
                         {
	BitNode *newNode;
	newNode = getBitNode(yylineno,yycolumn,"", "parameter");

	newNode->insertChild((yyvsp[0].BITNODE));

	cout<<"parameter -> var_parameter [OK]"<<endl;
	(yyval.BITNODE) = newNode;
}
#line 3336 "y.tab.cpp"
    break;

  case 118: /* parameter: value_parameter  */
#line 959 "yacc.y"
                          {
	BitNode *newNode;
        newNode = getBitNode(yylineno,yycolumn,"", "parameter");

        newNode->insertChild((yyvsp[0].BITNODE));

        cout<<"parameter -> value_parameter [OK]"<<endl;
        (yyval.BITNODE) = newNode;
}
#line 3350 "y.tab.cpp"
    break;

  case 119: /* parameter: error  */
#line 967 "yacc.y"
          { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
#line 3359 "y.tab.cpp"
    break;

  case 120: /* var_parameter: _VAR value_parameter  */
#line 972 "yacc.y"
                                   {
	BitNode *newNode, *Node1;
	newNode = getBitNode(yylineno,yycolumn,"", "var_parameter");
	Node1 = getBitNode(yylineno,yycolumn,(yyvsp[-1].TYPE)->token, "VAR");

	newNode->insertChild(Node1);
	newNode->insertChild((yyvsp[0].BITNODE));

	cout<<"var_parameter -> var value_parameter [OK]"<<endl;
	(yyval.BITNODE) = newNode;
}
#line 3375 "y.tab.cpp"
    break;

  case 121: /* var_parameter: error value_parameter  */
#line 982 "yacc.y"
                          { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	yyerror("missing var");
	(yyval.BITNODE) = newNode; 
}
#line 3385 "y.tab.cpp"
    break;

  case 122: /* var_parameter: _VAR error  */
#line 989 "yacc.y"
              { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
#line 3394 "y.tab.cpp"
    break;

  case 123: /* value_parameter: idlist ':' basic_type  */
#line 994 "yacc.y"
                                       {
	BitNode *newNode, *Node2;
	newNode = getBitNode(yylineno,yycolumn,"", "value_parameter");
	Node2 = getBitNode(yylineno,yycolumn,":", "SEPARATOR");

	newNode->insertChild((yyvsp[-2].BITNODE));
	newNode->insertChild(Node2);
	newNode->insertChild((yyvsp[0].BITNODE));

	cout<<"value_parameter -> idlist : simple_type [OK]"<<endl;
	(yyval.BITNODE) = newNode;
}
#line 3411 "y.tab.cpp"
    break;

  case 124: /* value_parameter: error ':' basic_type  */
#line 1005 "yacc.y"
                         { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
#line 3420 "y.tab.cpp"
    break;

  case 125: /* value_parameter: idlist error basic_type  */
#line 1011 "yacc.y"
                            { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	yyerror("missing ':'");
	(yyval.BITNODE) = newNode; 
}
#line 3430 "y.tab.cpp"
    break;

  case 126: /* value_parameter: idlist ':' error  */
#line 1018 "yacc.y"
                     { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
#line 3439 "y.tab.cpp"
    break;

  case 127: /* subprogram_body: const_declarations var_declarations compound_statement  */
#line 1023 "yacc.y"
                                                                        {
	BitNode *newNode;
	newNode = getBitNode(yylineno,yycolumn,"", "subprogram_body");

	newNode->insertChild((yyvsp[-2].BITNODE));
	newNode->insertChild((yyvsp[-1].BITNODE));
	newNode->insertChild((yyvsp[0].BITNODE));

	cout<<"subprogram_body -> const_declarations var_declarations compound_statement [OK]"<<endl;
	(yyval.BITNODE) = newNode;
}
#line 3455 "y.tab.cpp"
    break;

  case 128: /* subprogram_body: error var_declarations compound_statement  */
#line 1033 "yacc.y"
                                              { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
#line 3464 "y.tab.cpp"
    break;

  case 129: /* subprogram_body: const_declarations error compound_statement  */
#line 1039 "yacc.y"
                                                { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
#line 3473 "y.tab.cpp"
    break;

  case 130: /* subprogram_body: const_declarations var_declarations error  */
#line 1045 "yacc.y"
                                              { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
#line 3482 "y.tab.cpp"
    break;

  case 131: /* compound_statement: _BEGIN statement_list _END  */
#line 1050 "yacc.y"
                                               {
	BitNode *newNode, *Node1, *Node3;
	newNode = getBitNode(yylineno,yycolumn,"", "compound_statement");
	Node1 = getBitNode(yylineno,yycolumn,(yyvsp[-2].TYPE)->token, "BEGIN");
	Node3 = getBitNode(yylineno,yycolumn,(yyvsp[0].TYPE)->token, "END");

	newNode->insertChild(Node1);
	newNode->insertChild((yyvsp[-1].BITNODE));
	newNode->insertChild(Node3);

	cout<<"compound_statement -> begin statement_list end [OK]"<<endl;
	(yyval.BITNODE) = newNode;
}
#line 3500 "y.tab.cpp"
    break;

  case 132: /* compound_statement: error statement_list _END  */
#line 1063 "yacc.y"
                              { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	yyerror("missing begin");
	(yyval.BITNODE) = newNode; 
}
#line 3510 "y.tab.cpp"
    break;

  case 133: /* compound_statement: _BEGIN error _END  */
#line 1070 "yacc.y"
                      { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
#line 3519 "y.tab.cpp"
    break;

  case 134: /* compound_statement: _BEGIN statement_list error  */
#line 1076 "yacc.y"
                                { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	yyerror("missing end");
	(yyval.BITNODE) = newNode; 
}
#line 3529 "y.tab.cpp"
    break;

  case 135: /* statement_list: statement_list ';' statement  */
#line 1082 "yacc.y"
                                             {
	BitNode *newNode, *Node2;
	newNode = getBitNode(yylineno,yycolumn,"", "statement_list");
	Node2 = getBitNode(yylineno,yycolumn,";", "SEPARATOR");

	newNode->insertChild((yyvsp[-2].BITNODE));
	newNode->insertChild(Node2);
	newNode->insertChild((yyvsp[0].BITNODE));

	cout<<"statement_list -> statement_list ; statement [OK]"<<endl;
	(yyval.BITNODE) = newNode;
}
#line 3546 "y.tab.cpp"
    break;

  case 136: /* statement_list: error ';' statement  */
#line 1093 "yacc.y"
                        { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
#line 3555 "y.tab.cpp"
    break;

  case 137: /* statement_list: statement_list error statement  */
#line 1099 "yacc.y"
                                   { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	yyerror("missing ';'");
	(yyval.BITNODE) = newNode; 
}
#line 3565 "y.tab.cpp"
    break;

  case 138: /* statement_list: statement_list ';' error  */
#line 1106 "yacc.y"
                             { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
#line 3574 "y.tab.cpp"
    break;

  case 139: /* statement_list: statement  */
#line 1110 "yacc.y"
                    {
	BitNode *newNode;
	newNode = getBitNode(yylineno,yycolumn,"", "statement_list");
	newNode->insertChild((yyvsp[0].BITNODE));

	cout<<"statement_list -> statement [OK]"<<endl;
	(yyval.BITNODE) = newNode;
}
#line 3587 "y.tab.cpp"
    break;

  case 140: /* statement_list: error  */
#line 1117 "yacc.y"
           { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
#line 3596 "y.tab.cpp"
    break;

  case 141: /* statement: variable _ASSIGNOP expression  */
#line 1122 "yacc.y"
                                         {
	BitNode *newNode, *Node2;
	newNode = getBitNode(yylineno,yycolumn,"", "statement");
	Node2 = getBitNode(yylineno,yycolumn,(yyvsp[-1].TYPE)->token, "ASSIGNOP");

	newNode->insertChild((yyvsp[-2].BITNODE));
	newNode->insertChild(Node2);
	newNode->insertChild((yyvsp[0].BITNODE));

	cout<<"statement -> variable _ASSIGNOP expression [OK]"<<endl;
	(yyval.BITNODE) = newNode;
}
#line 3613 "y.tab.cpp"
    break;

  case 142: /* statement: error _ASSIGNOP expression  */
#line 1133 "yacc.y"
                               { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
#line 3622 "y.tab.cpp"
    break;

  case 143: /* statement: variable error expression  */
#line 1139 "yacc.y"
                              { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
#line 3631 "y.tab.cpp"
    break;

  case 144: /* statement: variable _ASSIGNOP error  */
#line 1145 "yacc.y"
                             { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
#line 3640 "y.tab.cpp"
    break;

  case 145: /* statement: procedure_call  */
#line 1149 "yacc.y"
                         {
	BitNode *newNode;
	newNode = getBitNode(yylineno,yycolumn,"", "statement");
	newNode->insertChild((yyvsp[0].BITNODE));

	cout<<"statement -> procedure_call [OK]"<<endl;
	(yyval.BITNODE) = newNode;
}
#line 3653 "y.tab.cpp"
    break;

  case 146: /* statement: compound_statement  */
#line 1157 "yacc.y"
                             {
	BitNode *newNode;
        newNode = getBitNode(yylineno,yycolumn,"", "statement");
        newNode->insertChild((yyvsp[0].BITNODE));

        cout<<"statement -> compound_statement [OK]"<<endl;
        (yyval.BITNODE) = newNode;
}
#line 3666 "y.tab.cpp"
    break;

  case 147: /* statement: error  */
#line 1164 "yacc.y"
            { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
#line 3675 "y.tab.cpp"
    break;

  case 148: /* statement: _IF expression _THEN statement else_part  */
#line 1168 "yacc.y"
                                                   {
	BitNode *newNode, *Node1, *Node3;
	newNode = getBitNode(yylineno,yycolumn,"", "statement");
	Node1 = getBitNode(yylineno,yycolumn,(yyvsp[-4].TYPE)->token, "IF");
	Node3 = getBitNode(yylineno,yycolumn,(yyvsp[-2].TYPE)->token, "THEN");

	newNode->insertChild(Node1);
	newNode->insertChild((yyvsp[-3].BITNODE));
	newNode->insertChild(Node3);
	newNode->insertChild((yyvsp[-1].BITNODE));
	newNode->insertChild((yyvsp[0].BITNODE));

	cout<<"statement -> if expression then statement else_part [OK]"<<endl;
	(yyval.BITNODE) = newNode;
}
#line 3695 "y.tab.cpp"
    break;

  case 149: /* statement: error expression _THEN statement else_part  */
#line 1182 "yacc.y"
                                               { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	yyerror("missing if");
	(yyval.BITNODE) = newNode; 
}
#line 3705 "y.tab.cpp"
    break;

  case 150: /* statement: _IF error _THEN statement else_part  */
#line 1189 "yacc.y"
                                        { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
#line 3714 "y.tab.cpp"
    break;

  case 151: /* statement: _IF expression error statement else_part  */
#line 1195 "yacc.y"
                                             { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	yyerror("missing then");
	(yyval.BITNODE) = newNode; 
}
#line 3724 "y.tab.cpp"
    break;

  case 152: /* statement: _IF expression _THEN error else_part  */
#line 1202 "yacc.y"
                                         { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
#line 3733 "y.tab.cpp"
    break;

  case 153: /* statement: _IF expression _THEN statement error  */
#line 1208 "yacc.y"
                                                { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
#line 3742 "y.tab.cpp"
    break;

  case 154: /* statement: _FOR _ID _ASSIGNOP expression _TO expression _DO statement  */
#line 1212 "yacc.y"
                                                                     {
	BitNode *newNode, *Node1, *Node2, *Node3, *Node5, *Node7;
	newNode = getBitNode(yylineno,yycolumn,"", "statement");
	Node1 = getBitNode(yylineno,yycolumn,(yyvsp[-7].TYPE)->token, "FOR");
	Node2 = getBitNode(yylineno,yycolumn,(yyvsp[-6].TYPE)->token, "ID");
	Node3 = getBitNode(yylineno,yycolumn,(yyvsp[-5].TYPE)->token, "ASSIGNOP");
	Node5 = getBitNode(yylineno,yycolumn,(yyvsp[-3].TYPE)->token, "TO");
	Node7 = getBitNode(yylineno,yycolumn,(yyvsp[-1].TYPE)->token, "DO");

	newNode->insertChild(Node1);
	newNode->insertChild(Node2);
	newNode->insertChild(Node3);
	newNode->insertChild((yyvsp[-4].BITNODE));
	newNode->insertChild(Node5);
	newNode->insertChild((yyvsp[-2].BITNODE));
	newNode->insertChild(Node7);
	newNode->insertChild((yyvsp[0].BITNODE));

	cout<<"statement -> for id assignop expression to expression do statement [OK]"<<endl;
	(yyval.BITNODE) = newNode;
}
#line 3768 "y.tab.cpp"
    break;

  case 155: /* statement: error _ID _ASSIGNOP expression _TO expression _DO statement  */
#line 1232 "yacc.y"
                                                                 { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	yyerror("missing for");
	(yyval.BITNODE) = newNode; 
}
#line 3778 "y.tab.cpp"
    break;

  case 156: /* statement: _FOR error _ASSIGNOP expression _TO expression _DO statement  */
#line 1239 "yacc.y"
                                                                 { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
#line 3787 "y.tab.cpp"
    break;

  case 157: /* statement: _FOR _ID error expression _TO expression _DO statement  */
#line 1245 "yacc.y"
                                                           { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
#line 3796 "y.tab.cpp"
    break;

  case 158: /* statement: _FOR _ID _ASSIGNOP error _TO expression _DO statement  */
#line 1251 "yacc.y"
                                                          { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
#line 3805 "y.tab.cpp"
    break;

  case 159: /* statement: _FOR _ID _ASSIGNOP expression error expression _DO statement  */
#line 1257 "yacc.y"
                                                                 { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	yyerror("missing to");
	(yyval.BITNODE) = newNode; 
}
#line 3815 "y.tab.cpp"
    break;

  case 160: /* statement: _FOR _ID _ASSIGNOP expression _TO error _DO statement  */
#line 1264 "yacc.y"
                                                          { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
#line 3824 "y.tab.cpp"
    break;

  case 161: /* statement: _FOR _ID _ASSIGNOP expression _TO expression error statement  */
#line 1270 "yacc.y"
                                                                 { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	yyerror("missing do");
	(yyval.BITNODE) = newNode; 
}
#line 3834 "y.tab.cpp"
    break;

  case 162: /* statement: _FOR _ID _ASSIGNOP expression _TO expression _DO error  */
#line 1277 "yacc.y"
                                                           { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
#line 3843 "y.tab.cpp"
    break;

  case 163: /* statement: _READ '(' variable_list ')'  */
#line 1281 "yacc.y"
                                      {
	BitNode *newNode, *Node1, *Node2, *Node4;
	newNode = getBitNode(yylineno,yycolumn,"", "statement");
	Node1 = getBitNode(yylineno,yycolumn,(yyvsp[-3].TYPE)->token, "READ");
	Node2 = getBitNode(yylineno,yycolumn,"(", "SEPARATOR");
	Node4 = getBitNode(yylineno,yycolumn,")", "SEPARATOR");

	newNode->insertChild(Node1);
	newNode->insertChild(Node2);
	newNode->insertChild((yyvsp[-1].BITNODE));
	newNode->insertChild(Node4);

	cout<<"statement -> read ( variable_list ) [OK]"<<endl;
	(yyval.BITNODE) = newNode;
}
#line 3863 "y.tab.cpp"
    break;

  case 164: /* statement: error '(' variable_list ')'  */
#line 1296 "yacc.y"
                                { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
#line 3872 "y.tab.cpp"
    break;

  case 165: /* statement: _READ error variable_list ')'  */
#line 1302 "yacc.y"
                                  { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	yyerror("missing '('");
	(yyval.BITNODE) = newNode; 
}
#line 3882 "y.tab.cpp"
    break;

  case 166: /* statement: _READ '(' error ')'  */
#line 1309 "yacc.y"
                        { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
#line 3891 "y.tab.cpp"
    break;

  case 167: /* statement: _READ '(' variable_list error  */
#line 1315 "yacc.y"
                                  { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	yyerror("missing ')'");
	(yyval.BITNODE) = newNode; 
}
#line 3901 "y.tab.cpp"
    break;

  case 168: /* statement: error '(' expression_list ')'  */
#line 1321 "yacc.y"
                                  { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	yyerror("missing write");
	(yyval.BITNODE) = newNode; 
}
#line 3911 "y.tab.cpp"
    break;

  case 169: /* statement: _WRITE error expression_list ')'  */
#line 1328 "yacc.y"
                                     { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	yyerror("missing '('");
	(yyval.BITNODE) = newNode; 
}
#line 3921 "y.tab.cpp"
    break;

  case 170: /* statement: _WRITE '(' error ')'  */
#line 1335 "yacc.y"
                         { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
#line 3930 "y.tab.cpp"
    break;

  case 171: /* statement: _WRITE '(' expression_list error  */
#line 1341 "yacc.y"
                                     { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	yyerror("missing ')'");
	(yyval.BITNODE) = newNode;
}
#line 3940 "y.tab.cpp"
    break;

  case 172: /* statement: _WRITE '(' expression_list ')'  */
#line 1346 "yacc.y"
                                         {
        BitNode *newNode, *Node1, *Node2, *Node4;
        newNode = getBitNode(yylineno,yycolumn,"", "statement");
        Node1 = getBitNode(yylineno,yycolumn,(yyvsp[-3].TYPE)->token, "WRITE");
        Node2 = getBitNode(yylineno,yycolumn,"(", "SEPARATOR");
        Node4 = getBitNode(yylineno,yycolumn,")", "SEPARATOR");

        newNode->insertChild(Node1);
        newNode->insertChild(Node2);
        newNode->insertChild((yyvsp[-1].BITNODE));
        newNode->insertChild(Node4);

        cout<<"statement -> write ( variable_list ) [OK]"<<endl;
        (yyval.BITNODE) = newNode;
}
#line 3960 "y.tab.cpp"
    break;

  case 173: /* statement: %empty  */
#line 1361 "yacc.y"
          {
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "statement");

	cout<<"statement -> empty [OK]"<<endl;
	(yyval.BITNODE) = newNode;
}
#line 3971 "y.tab.cpp"
    break;

  case 174: /* statement: _WHILE expression _DO statement  */
#line 1367 "yacc.y"
                                  { // 增加while循环
	BitNode *newNode, *Node1, *Node3;
        newNode = getBitNode(yylineno,yycolumn,"", "statement");
        Node1 = getBitNode(yylineno,yycolumn,(yyvsp[-3].TYPE)->token, "WHILE");
        Node3 = getBitNode(yylineno,yycolumn,(yyvsp[-1].TYPE)->token, "DO");

        newNode->insertChild(Node1);
        newNode->insertChild((yyvsp[-2].BITNODE));
        newNode->insertChild(Node3);
        newNode->insertChild((yyvsp[0].BITNODE));

        cout<<"statement -> _WHILE expression _DO statement [OK]"<<endl;
        (yyval.BITNODE) = newNode;
}
#line 3990 "y.tab.cpp"
    break;

  case 175: /* statement: error expression _DO statement  */
#line 1380 "yacc.y"
                                    { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	yyerror("missing while");
	(yyval.BITNODE) = newNode; 
}
#line 4000 "y.tab.cpp"
    break;

  case 176: /* statement: _WHILE error _DO statement  */
#line 1387 "yacc.y"
                               { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
#line 4009 "y.tab.cpp"
    break;

  case 177: /* statement: _WHILE expression error statement  */
#line 1393 "yacc.y"
                                      { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	yyerror("missing do");
	(yyval.BITNODE) = newNode; 
}
#line 4019 "y.tab.cpp"
    break;

  case 178: /* statement: _WHILE expression _DO error  */
#line 1400 "yacc.y"
                                { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
#line 4028 "y.tab.cpp"
    break;

  case 179: /* variable_list: variable_list ',' variable  */
#line 1405 "yacc.y"
                                         {
	BitNode *newNode, *Node2;
	newNode = getBitNode(yylineno,yycolumn,"", "variable_list");
	Node2 = getBitNode(yylineno,yycolumn,",", "SEPARATOR");

	newNode->insertChild((yyvsp[-2].BITNODE));
	newNode->insertChild(Node2);
	newNode->insertChild((yyvsp[0].BITNODE));

	cout<<"variable_list -> variable_list _SEPARATOR variable [OK]"<<endl;
	(yyval.BITNODE) = newNode;
}
#line 4045 "y.tab.cpp"
    break;

  case 180: /* variable_list: error ',' variable  */
#line 1417 "yacc.y"
                     { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
#line 4054 "y.tab.cpp"
    break;

  case 181: /* variable_list: variable_list error variable  */
#line 1423 "yacc.y"
                                { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	yyerror("missing ','");
	(yyval.BITNODE) = newNode; 
}
#line 4064 "y.tab.cpp"
    break;

  case 182: /* variable_list: variable_list ',' error  */
#line 1430 "yacc.y"
                           { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
#line 4073 "y.tab.cpp"
    break;

  case 183: /* variable_list: variable  */
#line 1434 "yacc.y"
                   {
	BitNode *newNode;
	newNode = getBitNode(yylineno,yycolumn,"", "variable_list");

	newNode->insertChild((yyvsp[0].BITNODE));

	cout<<"statement -> variable [OK]"<<endl;
	(yyval.BITNODE) = newNode;
}
#line 4087 "y.tab.cpp"
    break;

  case 184: /* variable_list: error  */
#line 1443 "yacc.y"
        { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
#line 4096 "y.tab.cpp"
    break;

  case 185: /* variable: _ID id_varpart  */
#line 1448 "yacc.y"
                         {
	BitNode *newNode, *Node1;
	newNode = getBitNode(yylineno,yycolumn,"", "variable");
	Node1 = getBitNode(yylineno,yycolumn,(yyvsp[-1].TYPE)->token, "ID");

	newNode->insertChild(Node1);
	newNode->insertChild((yyvsp[0].BITNODE));

	cout<<"variable -> id id_varpart [OK]"<<endl;
	(yyval.BITNODE) = newNode;
}
#line 4112 "y.tab.cpp"
    break;

  case 186: /* variable: error id_varpart  */
#line 1460 "yacc.y"
                    { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
#line 4121 "y.tab.cpp"
    break;

  case 187: /* variable: _ID error  */
#line 1466 "yacc.y"
             { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
#line 4130 "y.tab.cpp"
    break;

  case 188: /* id_varpart: '[' expression_list ']'  */
#line 1471 "yacc.y"
                                    {
	BitNode *newNode, *Node1, *Node3;
	newNode = getBitNode(yylineno,yycolumn,"", "id_varpart");
	Node1 = getBitNode(yylineno,yycolumn,"[", "SEPARATOR");
	Node3 = getBitNode(yylineno,yycolumn,"]", "SEPARATOR");

	newNode->insertChild(Node1);
	newNode->insertChild((yyvsp[-1].BITNODE));
	newNode->insertChild(Node3);

	cout<<"id_varpart -> [ expression_list ] [OK]"<<endl;
	(yyval.BITNODE) = newNode;
}
#line 4148 "y.tab.cpp"
    break;

  case 189: /* id_varpart: error expression_list ']'  */
#line 1484 "yacc.y"
                            { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	yyerror("missing '['");
	(yyval.BITNODE) = newNode; 
}
#line 4158 "y.tab.cpp"
    break;

  case 190: /* id_varpart: '[' error ']'  */
#line 1491 "yacc.y"
                 { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
#line 4167 "y.tab.cpp"
    break;

  case 191: /* id_varpart: '[' expression_list error  */
#line 1497 "yacc.y"
                             { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	yyerror("missing ']'");
	(yyval.BITNODE) = newNode; 
}
#line 4177 "y.tab.cpp"
    break;

  case 192: /* id_varpart: %empty  */
#line 1502 "yacc.y"
          {
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "id_varpart");

	cout<<"id_varpart -> empty [OK]"<<endl;
	(yyval.BITNODE) = newNode;
}
#line 4188 "y.tab.cpp"
    break;

  case 193: /* procedure_call: _ID  */
#line 1509 "yacc.y"
                    {
	BitNode *newNode, *Node1;
	newNode = getBitNode(yylineno,yycolumn,"", "procedure_call");
	Node1 = getBitNode(yylineno,yycolumn,(yyvsp[0].TYPE)->token, "ID");

	newNode->insertChild(Node1);

	cout<<"procedure_call -> id [OK]"<<endl;
	(yyval.BITNODE) = newNode;
}
#line 4203 "y.tab.cpp"
    break;

  case 194: /* procedure_call: error  */
#line 1520 "yacc.y"
         { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
#line 4212 "y.tab.cpp"
    break;

  case 195: /* procedure_call: error '(' expression_list ')'  */
#line 1526 "yacc.y"
                                 { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
#line 4221 "y.tab.cpp"
    break;

  case 196: /* procedure_call: _ID error expression_list ')'  */
#line 1532 "yacc.y"
                                 { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	yyerror("missing '('");
	(yyval.BITNODE) = newNode; 
}
#line 4231 "y.tab.cpp"
    break;

  case 197: /* procedure_call: _ID '(' error ')'  */
#line 1539 "yacc.y"
                     { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
#line 4240 "y.tab.cpp"
    break;

  case 198: /* procedure_call: _ID '(' expression_list error  */
#line 1545 "yacc.y"
                                 { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	yyerror("missing ')'");
	(yyval.BITNODE) = newNode; 
}
#line 4250 "y.tab.cpp"
    break;

  case 199: /* procedure_call: _ID '(' expression_list ')'  */
#line 1550 "yacc.y"
                                      {
	BitNode *newNode, *Node1, *Node2, *Node4;
	newNode = getBitNode(yylineno,yycolumn,"", "procedure_call");
	Node1 = getBitNode(yylineno,yycolumn,(yyvsp[-3].TYPE)->token, "ID");
	Node2 = getBitNode(yylineno,yycolumn,"(", "SEPARATOR");
	Node4 = getBitNode(yylineno,yycolumn,")", "SEPARATOR");

	newNode->insertChild(Node1);
	newNode->insertChild(Node2);
	newNode->insertChild((yyvsp[-1].BITNODE));
	newNode->insertChild(Node4);

	cout<<"procedure_call -> id ( expression_list ) [OK]"<<endl;
	(yyval.BITNODE) = newNode;
}
#line 4270 "y.tab.cpp"
    break;

  case 200: /* else_part: _ELSE statement  */
#line 1566 "yacc.y"
                           {
	BitNode *newNode, *Node1;
	newNode=getBitNode(yylineno,yycolumn,"", "else_part");
	Node1 = getBitNode(yylineno,yycolumn,(yyvsp[-1].TYPE)->token, "ELSE");

	newNode->insertChild(Node1);
	newNode->insertChild((yyvsp[0].BITNODE));

	cout<<"else_part -> else statement [OK]"<<endl;
	(yyval.BITNODE) = newNode;
}
#line 4286 "y.tab.cpp"
    break;

  case 201: /* else_part: error statement  */
#line 1579 "yacc.y"
                   { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	yyerror("missing else");
	(yyval.BITNODE) = newNode; 
}
#line 4296 "y.tab.cpp"
    break;

  case 202: /* else_part: _ELSE error  */
#line 1586 "yacc.y"
               { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
#line 4305 "y.tab.cpp"
    break;

  case 203: /* else_part: %empty  */
#line 1590 "yacc.y"
          {
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "else_part");

	cout<<"else_part -> empty [OK]"<<endl;
	(yyval.BITNODE) = newNode;
}
#line 4316 "y.tab.cpp"
    break;

  case 204: /* expression_list: expression_list ',' expression  */
#line 1597 "yacc.y"
                                                {

	BitNode *newNode, *Node2;
	newNode = getBitNode(yylineno,yycolumn,"", "expression_list");
	Node2 = getBitNode(yylineno,yycolumn,",", "SEPARATOR");

	newNode->insertChild((yyvsp[-2].BITNODE));
	newNode->insertChild(Node2);
	newNode->insertChild((yyvsp[0].BITNODE));

	cout<<"expression_list -> expression_list , expression [OK]"<<endl;
	(yyval.BITNODE) = newNode;
}
#line 4334 "y.tab.cpp"
    break;

  case 205: /* expression_list: error ',' expression  */
#line 1611 "yacc.y"
                        { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
#line 4343 "y.tab.cpp"
    break;

  case 206: /* expression_list: expression_list error expression  */
#line 1617 "yacc.y"
                                    { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	yyerror("missing ','");
	(yyval.BITNODE) = newNode; 
}
#line 4353 "y.tab.cpp"
    break;

  case 207: /* expression_list: expression_list ',' error  */
#line 1624 "yacc.y"
                             { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
#line 4362 "y.tab.cpp"
    break;

  case 208: /* expression_list: expression  */
#line 1628 "yacc.y"
                     {
	BitNode *newNode;
	newNode = getBitNode(yylineno,yycolumn,"", "expression_list");

	newNode->insertChild((yyvsp[0].BITNODE));

	cout<<"expression_list -> expression [OK]"<<endl;
	(yyval.BITNODE) = newNode;
}
#line 4376 "y.tab.cpp"
    break;

  case 209: /* expression_list: error  */
#line 1637 "yacc.y"
        { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
#line 4385 "y.tab.cpp"
    break;

  case 210: /* expression: simple_expression _RELOP simple_expression  */
#line 1642 "yacc.y"
                                                       {
	BitNode *newNode, *Node2;
	newNode = getBitNode(yylineno,yycolumn,"", "expression");
	Node2 = getBitNode(yylineno,yycolumn,(yyvsp[-1].TYPE)->token, "RELOP");

	newNode->insertChild((yyvsp[-2].BITNODE));
	newNode->insertChild(Node2);
	newNode->insertChild((yyvsp[0].BITNODE));

	cout<<"expression -> simple_expression relop simple_expression [OK]"<<endl;
	(yyval.BITNODE) = newNode;
}
#line 4402 "y.tab.cpp"
    break;

  case 211: /* expression: simple_expression  */
#line 1654 "yacc.y"
                            {
	BitNode *newNode;
	newNode = getBitNode(yylineno,yycolumn,"", "expression");

	newNode->insertChild((yyvsp[0].BITNODE));

	cout<<"expression -> simple_expression [OK]"<<endl;
	(yyval.BITNODE) = newNode;
}
#line 4416 "y.tab.cpp"
    break;

  case 212: /* expression: error _RELOP simple_expression  */
#line 1664 "yacc.y"
                                  { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
#line 4425 "y.tab.cpp"
    break;

  case 213: /* expression: simple_expression error simple_expression  */
#line 1670 "yacc.y"
                                             { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
#line 4434 "y.tab.cpp"
    break;

  case 214: /* expression: simple_expression _RELOP error  */
#line 1676 "yacc.y"
                                  { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
#line 4443 "y.tab.cpp"
    break;

  case 215: /* expression: error  */
#line 1682 "yacc.y"
         { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
#line 4452 "y.tab.cpp"
    break;

  case 216: /* simple_expression: simple_expression _ADDOP term  */
#line 1687 "yacc.y"
                                                 {
	BitNode *newNode, *Node2;
	newNode = getBitNode(yylineno,yycolumn,"", "simple_expression");
	Node2 = getBitNode(yylineno,yycolumn,(yyvsp[-1].TYPE)->token, "ADDOP");

	newNode->insertChild((yyvsp[-2].BITNODE));
	newNode->insertChild(Node2);
	newNode->insertChild((yyvsp[0].BITNODE));

	cout<<"simple_expression -> simple_expression addop term [OK]"<<endl;
	(yyval.BITNODE) = newNode;
}
#line 4469 "y.tab.cpp"
    break;

  case 217: /* simple_expression: simple_expression _UMINUS term  */
#line 1698 "yacc.y"
                                 { // 增加 uminus 关联生成式
	BitNode *newNode, *Node2;
	newNode = getBitNode(yylineno,yycolumn, "", "simple_expression");
	Node2 = getBitNode(yylineno,yycolumn, (yyvsp[-1].TYPE)->token, "UMINUS");

	newNode->insertChild((yyvsp[-2].BITNODE));
	newNode->insertChild(Node2);
	newNode->insertChild((yyvsp[0].BITNODE));

	cout<<"simple_expression -> simple_expression uminus term [OK]"<<endl;
	(yyval.BITNODE) = newNode;
}
#line 4486 "y.tab.cpp"
    break;

  case 218: /* simple_expression: term  */
#line 1710 "yacc.y"
               {
	BitNode *newNode;
	newNode = getBitNode(yylineno,yycolumn,"", "simple_expression");

	newNode->insertChild((yyvsp[0].BITNODE));

	cout<<"simple_expression -> term [OK]"<<endl;
	(yyval.BITNODE) = newNode;
}
#line 4500 "y.tab.cpp"
    break;

  case 219: /* simple_expression: error _ADDOP term  */
#line 1720 "yacc.y"
                     { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
#line 4509 "y.tab.cpp"
    break;

  case 220: /* simple_expression: simple_expression error term  */
#line 1726 "yacc.y"
                                { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
#line 4518 "y.tab.cpp"
    break;

  case 221: /* simple_expression: simple_expression _ADDOP error  */
#line 1732 "yacc.y"
                                  { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
#line 4527 "y.tab.cpp"
    break;

  case 222: /* simple_expression: error  */
#line 1738 "yacc.y"
         { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
#line 4536 "y.tab.cpp"
    break;

  case 223: /* term: term _MULOP factor  */
#line 1743 "yacc.y"
                         {
	BitNode *newNode, *Node2;
	newNode = getBitNode(yylineno,yycolumn,"", "term");
	Node2 = getBitNode(yylineno,yycolumn,(yyvsp[-1].TYPE)->token, "MULOP");

	newNode->insertChild((yyvsp[-2].BITNODE));
	newNode->insertChild(Node2);
	newNode->insertChild((yyvsp[0].BITNODE));

	cout<<"term -> term mulop factor [OK]"<<endl;
	(yyval.BITNODE) = newNode;
}
#line 4553 "y.tab.cpp"
    break;

  case 224: /* term: error _MULOP factor  */
#line 1755 "yacc.y"
                       { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
#line 4562 "y.tab.cpp"
    break;

  case 225: /* term: term error factor  */
#line 1761 "yacc.y"
                     { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
#line 4571 "y.tab.cpp"
    break;

  case 226: /* term: term _MULOP error  */
#line 1767 "yacc.y"
                     { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
#line 4580 "y.tab.cpp"
    break;

  case 227: /* term: factor  */
#line 1771 "yacc.y"
                 {
	BitNode *newNode;
	newNode = getBitNode(yylineno,yycolumn,"", "term");

	newNode->insertChild((yyvsp[0].BITNODE));

	cout<<"term -> factor [OK]"<<endl;
	(yyval.BITNODE) = newNode;
}
#line 4594 "y.tab.cpp"
    break;

  case 228: /* term: error  */
#line 1780 "yacc.y"
        { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
#line 4603 "y.tab.cpp"
    break;

  case 229: /* factor: _NUM  */
#line 1786 "yacc.y"
             {
        BitNode *newNode, *Node1;
        newNode = getBitNode(yylineno,yycolumn,"", "factor");
        Node1 = getBitNode(yylineno,yycolumn,(yyvsp[0].TYPE)->token, "NUM");

        newNode->insertChild(Node1);

        cout<<" factor -> num [OK]"<<endl;
        (yyval.BITNODE) = newNode;
}
#line 4618 "y.tab.cpp"
    break;

  case 230: /* factor: _DIGITS  */
#line 1796 "yacc.y"
          { // 增加整型
        BitNode *newNode, *Node1;
        newNode = getBitNode(yylineno,yycolumn, "", "factor");
        Node1 = getBitNode(yylineno,yycolumn, (yyvsp[0].TYPE)->token, "DIGITS");

        newNode->insertChild(Node1);

        cout<<" factor -> num [OK]"<<endl;
        (yyval.BITNODE) = newNode;
}
#line 4633 "y.tab.cpp"
    break;

  case 231: /* factor: _BOOLEAN  */
#line 1805 "yacc.y"
            { // 增加布尔型
 	BitNode *newNode, *Node1;
        newNode = getBitNode(yylineno,yycolumn, "", "factor");
        Node1 = getBitNode(yylineno,yycolumn, (yyvsp[0].TYPE)->token, "BOOLEAN");

        newNode->insertChild(Node1);

        cout<<" factor -> boolean [OK]"<<endl;
        (yyval.BITNODE) = newNode;
}
#line 4648 "y.tab.cpp"
    break;

  case 232: /* factor: variable  */
#line 1815 "yacc.y"
                   {
        BitNode *newNode;
        newNode = getBitNode(yylineno,yycolumn,"", "factor");

        newNode->insertChild((yyvsp[0].BITNODE));

        cout<<" factor -> variable [OK]"<<endl;
        (yyval.BITNODE) = newNode;
}
#line 4662 "y.tab.cpp"
    break;

  case 233: /* factor: error  */
#line 1824 "yacc.y"
        { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
#line 4671 "y.tab.cpp"
    break;

  case 234: /* factor: error '(' expression_list ')'  */
#line 1828 "yacc.y"
                                 { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
#line 4680 "y.tab.cpp"
    break;

  case 235: /* factor: _ID error expression_list ')'  */
#line 1832 "yacc.y"
                                 { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	yyerror("missing '('");
	(yyval.BITNODE) = newNode; 
}
#line 4690 "y.tab.cpp"
    break;

  case 236: /* factor: _ID '(' error ')'  */
#line 1839 "yacc.y"
                     { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
#line 4699 "y.tab.cpp"
    break;

  case 237: /* factor: _ID '(' expression_list error  */
#line 1845 "yacc.y"
                                 { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	yyerror("missing ')'");
	(yyval.BITNODE) = newNode; 
}
#line 4709 "y.tab.cpp"
    break;

  case 238: /* factor: _ID '(' expression_list ')'  */
#line 1850 "yacc.y"
                                      {

	BitNode *newNode, *Node1, *Node2, *Node4;
	newNode =  getBitNode(yylineno,yycolumn,"", "factor");
	Node1 = getBitNode(yylineno,yycolumn,(yyvsp[-3].TYPE)->token, "ID");
	Node2 = getBitNode(yylineno,yycolumn,"(", "SEPARATOR");
	Node4 = getBitNode(yylineno,yycolumn,")", "SEPARATOR");

	newNode->insertChild(Node1);
	newNode->insertChild(Node2);
	newNode->insertChild((yyvsp[-1].BITNODE));
	newNode->insertChild(Node4);

	cout<<"factor -> id ( expression_list ) [OK]"<<endl;
	(yyval.BITNODE) = newNode;
}
#line 4730 "y.tab.cpp"
    break;

  case 239: /* factor: '(' expression ')'  */
#line 1867 "yacc.y"
                             {
	BitNode *newNode, *Node1, *Node3;
	newNode = getBitNode(yylineno,yycolumn,"", "factor");
	Node1 = getBitNode(yylineno,yycolumn,"(", "SEPARATOR");
	Node3 = getBitNode(yylineno,yycolumn,")", "SEPARATOR");

	newNode->insertChild(Node1);
	newNode->insertChild((yyvsp[-1].BITNODE));
	newNode->insertChild(Node3);

	cout<<"factor -> ( expression ) [OK]"<<endl;
	(yyval.BITNODE) = newNode;
}
#line 4748 "y.tab.cpp"
    break;

  case 240: /* factor: _NOT factor  */
#line 1880 "yacc.y"
                      {
	BitNode *newNode, *Node1;
	newNode = getBitNode(yylineno,yycolumn,"", "factor");
	Node1 = getBitNode(yylineno,yycolumn,(yyvsp[-1].TYPE)->token, "NOT");

	newNode->insertChild(Node1);
	newNode->insertChild((yyvsp[0].BITNODE));

	cout<<"factor -> not factor [OK]"<<endl;
	(yyval.BITNODE) = newNode;
}
#line 4764 "y.tab.cpp"
    break;

  case 241: /* factor: error expression ')'  */
#line 1892 "yacc.y"
                         { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	yyerror("missing '('");
	(yyval.BITNODE) = newNode; 
}
#line 4774 "y.tab.cpp"
    break;

  case 242: /* factor: '(' error ')'  */
#line 1899 "yacc.y"
                 { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
#line 4783 "y.tab.cpp"
    break;

  case 243: /* factor: '(' expression error  */
#line 1905 "yacc.y"
                        { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	yyerror("missing ')'");
	(yyval.BITNODE) = newNode; 
}
#line 4793 "y.tab.cpp"
    break;

  case 244: /* factor: error factor  */
#line 1912 "yacc.y"
                { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
#line 4802 "y.tab.cpp"
    break;

  case 245: /* factor: _NOT error  */
#line 1918 "yacc.y"
              { 
	BitNode *newNode = getBitNode(yylineno,yycolumn,"", "error"); 
	(yyval.BITNODE) = newNode; 
}
#line 4811 "y.tab.cpp"
    break;

  case 246: /* factor: _ADDOP factor  */
#line 1922 "yacc.y"
                        {
	BitNode *newNode, *Node1;
        newNode = getBitNode(yylineno,yycolumn,"", "factor");
        Node1 = getBitNode(yylineno,yycolumn,(yyvsp[-1].TYPE)->token, "ADDOP");

        newNode->insertChild(Node1);
        newNode->insertChild((yyvsp[0].BITNODE));

        cout<<"factor -> add factor [OK]"<<endl;
        (yyval.BITNODE) = newNode;
}
#line 4827 "y.tab.cpp"
    break;

  case 247: /* factor: _UMINUS factor  */
#line 1932 "yacc.y"
                   {
	BitNode *newNode, *Node1;
        newNode = getBitNode(yylineno,yycolumn,"", "factor");
        Node1 = getBitNode(yylineno,yycolumn,(yyvsp[-1].TYPE)->token, "UMINUS");

        newNode->insertChild(Node1);
        newNode->insertChild((yyvsp[0].BITNODE));

        cout<<"factor -> uminus factor [OK]"<<endl;
        (yyval.BITNODE) = newNode;
}
#line 4843 "y.tab.cpp"
    break;


#line 4847 "y.tab.cpp"

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


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 1944 "yacc.y"


void yyerror(const char *s)
{
	extern char *yytext;
	extern YYSTYPE yylval;
	string error_type(s);
	Error* cur=new Error(error_type,yylineno,yycolumn);
	errorInfo.push_back(cur);
    	if_error=1;
	cout<<error_type<<"\tat line: "<<yylineno<<"\tcol: "<<yycolumn<<endl;
}

