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
#line 1 "parser.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"

extern int yylineno;
extern FILE* yyin;
extern int yyparse();
extern int yylex();
extern void yyerror(const char* s);

ASTNode* root = NULL;
int parse_error = 0;


#line 88 "parser.tab.c"

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

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_INTEGER_LITERAL = 3,            /* INTEGER_LITERAL  */
  YYSYMBOL_FLOAT_LITERAL = 4,              /* FLOAT_LITERAL  */
  YYSYMBOL_STRING_LITERAL = 5,             /* STRING_LITERAL  */
  YYSYMBOL_CHAR_LITERAL = 6,               /* CHAR_LITERAL  */
  YYSYMBOL_IDENTIFIER = 7,                 /* IDENTIFIER  */
  YYSYMBOL_AUTO = 8,                       /* AUTO  */
  YYSYMBOL_BREAK = 9,                      /* BREAK  */
  YYSYMBOL_CASE = 10,                      /* CASE  */
  YYSYMBOL_CHAR = 11,                      /* CHAR  */
  YYSYMBOL_CONST = 12,                     /* CONST  */
  YYSYMBOL_CONTINUE = 13,                  /* CONTINUE  */
  YYSYMBOL_DEFAULT = 14,                   /* DEFAULT  */
  YYSYMBOL_DO = 15,                        /* DO  */
  YYSYMBOL_DOUBLE = 16,                    /* DOUBLE  */
  YYSYMBOL_ELSE = 17,                      /* ELSE  */
  YYSYMBOL_ENUM = 18,                      /* ENUM  */
  YYSYMBOL_EXTERN = 19,                    /* EXTERN  */
  YYSYMBOL_FLOAT = 20,                     /* FLOAT  */
  YYSYMBOL_FOR = 21,                       /* FOR  */
  YYSYMBOL_GOTO = 22,                      /* GOTO  */
  YYSYMBOL_IF = 23,                        /* IF  */
  YYSYMBOL_INT = 24,                       /* INT  */
  YYSYMBOL_LONG = 25,                      /* LONG  */
  YYSYMBOL_REGISTER = 26,                  /* REGISTER  */
  YYSYMBOL_RETURN = 27,                    /* RETURN  */
  YYSYMBOL_SHORT = 28,                     /* SHORT  */
  YYSYMBOL_SIGNED = 29,                    /* SIGNED  */
  YYSYMBOL_SIZEOF = 30,                    /* SIZEOF  */
  YYSYMBOL_STATIC = 31,                    /* STATIC  */
  YYSYMBOL_STRUCT = 32,                    /* STRUCT  */
  YYSYMBOL_SWITCH = 33,                    /* SWITCH  */
  YYSYMBOL_TYPEDEF = 34,                   /* TYPEDEF  */
  YYSYMBOL_UNION = 35,                     /* UNION  */
  YYSYMBOL_UNSIGNED = 36,                  /* UNSIGNED  */
  YYSYMBOL_VOID = 37,                      /* VOID  */
  YYSYMBOL_VOLATILE = 38,                  /* VOLATILE  */
  YYSYMBOL_WHILE = 39,                     /* WHILE  */
  YYSYMBOL_PLUS = 40,                      /* PLUS  */
  YYSYMBOL_MINUS = 41,                     /* MINUS  */
  YYSYMBOL_MULTIPLY = 42,                  /* MULTIPLY  */
  YYSYMBOL_DIVIDE = 43,                    /* DIVIDE  */
  YYSYMBOL_MODULO = 44,                    /* MODULO  */
  YYSYMBOL_ASSIGN = 45,                    /* ASSIGN  */
  YYSYMBOL_EQUAL = 46,                     /* EQUAL  */
  YYSYMBOL_NOT_EQUAL = 47,                 /* NOT_EQUAL  */
  YYSYMBOL_LESS = 48,                      /* LESS  */
  YYSYMBOL_LESS_EQUAL = 49,                /* LESS_EQUAL  */
  YYSYMBOL_GREATER = 50,                   /* GREATER  */
  YYSYMBOL_GREATER_EQUAL = 51,             /* GREATER_EQUAL  */
  YYSYMBOL_AND = 52,                       /* AND  */
  YYSYMBOL_OR = 53,                        /* OR  */
  YYSYMBOL_NOT = 54,                       /* NOT  */
  YYSYMBOL_BITWISE_AND = 55,               /* BITWISE_AND  */
  YYSYMBOL_BITWISE_OR = 56,                /* BITWISE_OR  */
  YYSYMBOL_BITWISE_XOR = 57,               /* BITWISE_XOR  */
  YYSYMBOL_BITWISE_NOT = 58,               /* BITWISE_NOT  */
  YYSYMBOL_LEFT_SHIFT = 59,                /* LEFT_SHIFT  */
  YYSYMBOL_RIGHT_SHIFT = 60,               /* RIGHT_SHIFT  */
  YYSYMBOL_INCREMENT = 61,                 /* INCREMENT  */
  YYSYMBOL_DECREMENT = 62,                 /* DECREMENT  */
  YYSYMBOL_PLUS_ASSIGN = 63,               /* PLUS_ASSIGN  */
  YYSYMBOL_MINUS_ASSIGN = 64,              /* MINUS_ASSIGN  */
  YYSYMBOL_MULTIPLY_ASSIGN = 65,           /* MULTIPLY_ASSIGN  */
  YYSYMBOL_DIVIDE_ASSIGN = 66,             /* DIVIDE_ASSIGN  */
  YYSYMBOL_MODULO_ASSIGN = 67,             /* MODULO_ASSIGN  */
  YYSYMBOL_AND_ASSIGN = 68,                /* AND_ASSIGN  */
  YYSYMBOL_OR_ASSIGN = 69,                 /* OR_ASSIGN  */
  YYSYMBOL_XOR_ASSIGN = 70,                /* XOR_ASSIGN  */
  YYSYMBOL_LEFT_SHIFT_ASSIGN = 71,         /* LEFT_SHIFT_ASSIGN  */
  YYSYMBOL_RIGHT_SHIFT_ASSIGN = 72,        /* RIGHT_SHIFT_ASSIGN  */
  YYSYMBOL_LPAREN = 73,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 74,                    /* RPAREN  */
  YYSYMBOL_LBRACE = 75,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 76,                    /* RBRACE  */
  YYSYMBOL_LBRACKET = 77,                  /* LBRACKET  */
  YYSYMBOL_RBRACKET = 78,                  /* RBRACKET  */
  YYSYMBOL_SEMICOLON = 79,                 /* SEMICOLON  */
  YYSYMBOL_COMMA = 80,                     /* COMMA  */
  YYSYMBOL_DOT = 81,                       /* DOT  */
  YYSYMBOL_ARROW = 82,                     /* ARROW  */
  YYSYMBOL_QUESTION = 83,                  /* QUESTION  */
  YYSYMBOL_COLON = 84,                     /* COLON  */
  YYSYMBOL_YYACCEPT = 85,                  /* $accept  */
  YYSYMBOL_program = 86,                   /* program  */
  YYSYMBOL_external_declaration = 87,      /* external_declaration  */
  YYSYMBOL_function_definition = 88,       /* function_definition  */
  YYSYMBOL_declaration = 89,               /* declaration  */
  YYSYMBOL_type_specifier = 90,            /* type_specifier  */
  YYSYMBOL_parameter_list = 91,            /* parameter_list  */
  YYSYMBOL_parameter = 92,                 /* parameter  */
  YYSYMBOL_statement = 93,                 /* statement  */
  YYSYMBOL_statement_list = 94,            /* statement_list  */
  YYSYMBOL_expression = 95,                /* expression  */
  YYSYMBOL_assignment_expression = 96,     /* assignment_expression  */
  YYSYMBOL_logical_or_expression = 97,     /* logical_or_expression  */
  YYSYMBOL_logical_and_expression = 98,    /* logical_and_expression  */
  YYSYMBOL_equality_expression = 99,       /* equality_expression  */
  YYSYMBOL_relational_expression = 100,    /* relational_expression  */
  YYSYMBOL_additive_expression = 101,      /* additive_expression  */
  YYSYMBOL_multiplicative_expression = 102, /* multiplicative_expression  */
  YYSYMBOL_unary_expression = 103,         /* unary_expression  */
  YYSYMBOL_postfix_expression = 104,       /* postfix_expression  */
  YYSYMBOL_primary_expression = 105        /* primary_expression  */
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
typedef yytype_uint8 yy_state_t;

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
#define YYFINAL  11
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   373

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  85
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  21
/* YYNRULES -- Number of rules.  */
#define YYNRULES  76
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  143

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   339


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
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    52,    52,    58,    79,    80,    84,    91,   100,   105,
     114,   118,   122,   126,   130,   137,   138,   158,   166,   171,
     175,   179,   183,   187,   191,   195,   199,   203,   207,   211,
     218,   219,   237,   243,   247,   248,   257,   258,   265,   266,
     273,   274,   278,   285,   286,   290,   294,   298,   305,   306,
     310,   317,   318,   322,   326,   333,   334,   338,   342,   346,
     350,   357,   358,   362,   366,   370,   374,   380,   384,   391,
     395,   399,   403,   410,   414,   418,   422
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
  "\"end of file\"", "error", "\"invalid token\"", "INTEGER_LITERAL",
  "FLOAT_LITERAL", "STRING_LITERAL", "CHAR_LITERAL", "IDENTIFIER", "AUTO",
  "BREAK", "CASE", "CHAR", "CONST", "CONTINUE", "DEFAULT", "DO", "DOUBLE",
  "ELSE", "ENUM", "EXTERN", "FLOAT", "FOR", "GOTO", "IF", "INT", "LONG",
  "REGISTER", "RETURN", "SHORT", "SIGNED", "SIZEOF", "STATIC", "STRUCT",
  "SWITCH", "TYPEDEF", "UNION", "UNSIGNED", "VOID", "VOLATILE", "WHILE",
  "PLUS", "MINUS", "MULTIPLY", "DIVIDE", "MODULO", "ASSIGN", "EQUAL",
  "NOT_EQUAL", "LESS", "LESS_EQUAL", "GREATER", "GREATER_EQUAL", "AND",
  "OR", "NOT", "BITWISE_AND", "BITWISE_OR", "BITWISE_XOR", "BITWISE_NOT",
  "LEFT_SHIFT", "RIGHT_SHIFT", "INCREMENT", "DECREMENT", "PLUS_ASSIGN",
  "MINUS_ASSIGN", "MULTIPLY_ASSIGN", "DIVIDE_ASSIGN", "MODULO_ASSIGN",
  "AND_ASSIGN", "OR_ASSIGN", "XOR_ASSIGN", "LEFT_SHIFT_ASSIGN",
  "RIGHT_SHIFT_ASSIGN", "LPAREN", "RPAREN", "LBRACE", "RBRACE", "LBRACKET",
  "RBRACKET", "SEMICOLON", "COMMA", "DOT", "ARROW", "QUESTION", "COLON",
  "$accept", "program", "external_declaration", "function_definition",
  "declaration", "type_specifier", "parameter_list", "parameter",
  "statement", "statement_list", "expression", "assignment_expression",
  "logical_or_expression", "logical_and_expression", "equality_expression",
  "relational_expression", "additive_expression",
  "multiplicative_expression", "unary_expression", "postfix_expression",
  "primary_expression", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-62)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     151,   -62,   -62,   -62,   -62,   -62,    50,   -62,   -62,   -62,
       4,   -62,   -62,   -28,   295,     9,   -62,   -62,   -62,   -62,
     -62,   -11,   300,   300,   300,   300,   300,   295,   -61,   -62,
     -32,   -16,    26,    79,    40,    25,   -62,    82,   -62,   -17,
      56,   -39,   -62,   295,   212,     2,   -62,   -62,   -62,   -62,
     -62,    19,   -62,   300,   300,   300,   300,   300,   300,   300,
     300,   300,   300,   300,   300,   300,   -62,   -62,   256,   295,
     217,   -62,    29,   151,   -62,   -62,    33,   -62,   -16,    26,
      79,    79,    40,    40,    40,    40,    25,    25,   -62,   -62,
     -62,   -62,    41,    42,    39,    58,    48,    68,    -2,    75,
       3,   -62,   124,   -62,    85,    72,   217,   -62,   -62,   -62,
     -62,   -62,   -62,   295,   295,   -62,    78,   295,   -62,   129,
     -30,   -62,   -62,   -62,   173,    84,    80,   -62,    90,   -62,
     -62,   295,   217,   217,    86,   155,   -62,   295,   217,    99,
     -62,   217,   -62
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    13,    12,    11,    10,    14,     0,     2,     4,     5,
       0,     1,     3,     0,     0,     0,     8,    72,    73,    74,
      75,    69,     0,     0,     0,     0,     0,     0,     0,    33,
      34,    36,    38,    40,    43,    48,    51,    55,    61,     0,
       0,     0,    15,     0,     0,    69,    56,    57,    58,    59,
      60,     0,     9,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    67,    68,     0,     0,
      32,    17,     0,     0,    35,    64,     0,    76,    37,    39,
      41,    42,    44,    46,    45,    47,    49,    50,    52,    53,
      54,    62,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    19,     0,    30,     0,     0,    32,    16,    65,    63,
      66,    28,    29,     0,     0,    27,     0,     0,    21,     0,
       0,     7,    31,    18,     0,     0,     0,    26,     0,    20,
       6,     0,     0,     0,     0,    22,    24,     0,     0,     0,
      23,     0,    25
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -62,   -62,   168,   -62,    47,    22,   -62,   108,   -22,   -52,
     -14,   -12,   -62,   132,   133,    30,   149,    52,   258,   -62,
     -62
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     6,     7,     8,   101,   102,    41,    42,   103,   104,
     105,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      28,    17,    18,    19,    20,    21,    17,    18,    19,    20,
      21,    13,    94,    51,     1,    14,    95,    14,    52,     2,
       1,    53,    10,     3,    96,     2,    97,     4,    10,     3,
      98,    74,    76,     4,    43,    72,    54,    40,    22,    23,
       5,    73,    99,    22,    23,    15,     5,     9,   119,    16,
      11,    16,    24,     9,   124,    93,    92,    24,    70,    25,
      26,     1,    44,    71,    25,    26,     2,    63,    64,    65,
       3,    27,    55,    56,     4,    44,    27,   115,   100,   118,
      61,    62,   122,    39,   116,    80,    81,     5,    17,    18,
      19,    20,    21,    77,    94,    40,     1,   122,    95,   125,
     126,     2,   122,   128,   106,     3,    96,   108,    97,     4,
     135,   136,    98,    86,    87,   109,   140,   134,   111,   142,
     110,   113,     5,   139,    99,    22,    23,    57,    58,    59,
      60,   120,    17,    18,    19,    20,    21,   112,    94,    24,
       1,   114,    95,    66,    67,     2,    25,    26,   117,     3,
      96,   123,    97,     4,   132,    68,    98,   127,    27,    69,
     100,   121,     1,   131,   133,   137,     5,     2,    99,    22,
      23,     3,   138,   141,    12,     4,    17,    18,    19,    20,
      21,   107,    94,    24,     1,    78,    95,    79,     5,     2,
      25,    26,     0,     3,    96,     0,    97,     4,     0,     0,
      98,     0,    27,     0,   100,   129,    82,    83,    84,    85,
       5,     0,    99,    22,    23,    17,    18,    19,    20,    21,
      17,    18,    19,    20,    21,     0,    94,    24,     1,     0,
      95,     0,     0,     2,    25,    26,     0,     3,    96,     0,
      97,     4,     0,     0,    98,     0,    27,     0,   100,   130,
       0,     0,    22,    23,     5,     0,    99,    22,    23,    17,
      18,    19,    20,    21,     0,     0,    24,     0,     0,     0,
       0,    24,     0,    25,    26,     0,     0,     0,    25,    26,
      46,    47,    48,    49,    50,    27,    75,     0,     0,     0,
      27,     0,   100,     0,     0,     0,    22,    23,    17,    18,
      19,    20,    21,    17,    18,    19,    20,    45,     0,     0,
      24,     0,     0,     0,     0,     0,     0,    25,    26,     0,
       0,    88,    89,    90,     0,     0,     0,     0,     0,    27,
      91,     0,     0,     0,     0,    22,    23,     0,     0,     0,
      22,    23,     0,     0,     0,     0,     0,     0,     0,    24,
       0,     0,     0,     0,    24,     0,    25,    26,     0,     0,
       0,    25,    26,     0,     0,     0,     0,     0,    27,     0,
       0,     0,     0,    27
};

static const yytype_int16 yycheck[] =
{
      14,     3,     4,     5,     6,     7,     3,     4,     5,     6,
       7,     7,     9,    27,    11,    45,    13,    45,    79,    16,
      11,    53,     0,    20,    21,    16,    23,    24,     6,    20,
      27,    43,    44,    24,    45,    74,    52,    15,    40,    41,
      37,    80,    39,    40,    41,    73,    37,     0,   100,    79,
       0,    79,    54,     6,   106,    69,    68,    54,    75,    61,
      62,    11,    73,     7,    61,    62,    16,    42,    43,    44,
      20,    73,    46,    47,    24,    73,    73,    79,    75,    76,
      40,    41,   104,    74,    98,    55,    56,    37,     3,     4,
       5,     6,     7,    74,     9,    73,    11,   119,    13,   113,
     114,    16,   124,   117,    75,    20,    21,    74,    23,    24,
     132,   133,    27,    61,    62,    74,   138,   131,    79,   141,
      78,    73,    37,   137,    39,    40,    41,    48,    49,    50,
      51,     7,     3,     4,     5,     6,     7,    79,     9,    54,
      11,    73,    13,    61,    62,    16,    61,    62,    73,    20,
      21,    79,    23,    24,    74,    73,    27,    79,    73,    77,
      75,    76,    11,    79,    74,    79,    37,    16,    39,    40,
      41,    20,    17,    74,     6,    24,     3,     4,     5,     6,
       7,    73,     9,    54,    11,    53,    13,    54,    37,    16,
      61,    62,    -1,    20,    21,    -1,    23,    24,    -1,    -1,
      27,    -1,    73,    -1,    75,    76,    57,    58,    59,    60,
      37,    -1,    39,    40,    41,     3,     4,     5,     6,     7,
       3,     4,     5,     6,     7,    -1,     9,    54,    11,    -1,
      13,    -1,    -1,    16,    61,    62,    -1,    20,    21,    -1,
      23,    24,    -1,    -1,    27,    -1,    73,    -1,    75,    76,
      -1,    -1,    40,    41,    37,    -1,    39,    40,    41,     3,
       4,     5,     6,     7,    -1,    -1,    54,    -1,    -1,    -1,
      -1,    54,    -1,    61,    62,    -1,    -1,    -1,    61,    62,
      22,    23,    24,    25,    26,    73,    74,    -1,    -1,    -1,
      73,    -1,    75,    -1,    -1,    -1,    40,    41,     3,     4,
       5,     6,     7,     3,     4,     5,     6,     7,    -1,    -1,
      54,    -1,    -1,    -1,    -1,    -1,    -1,    61,    62,    -1,
      -1,    63,    64,    65,    -1,    -1,    -1,    -1,    -1,    73,
      74,    -1,    -1,    -1,    -1,    40,    41,    -1,    -1,    -1,
      40,    41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    54,
      -1,    -1,    -1,    -1,    54,    -1,    61,    62,    -1,    -1,
      -1,    61,    62,    -1,    -1,    -1,    -1,    -1,    73,    -1,
      -1,    -1,    -1,    73
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    11,    16,    20,    24,    37,    86,    87,    88,    89,
      90,     0,    87,     7,    45,    73,    79,     3,     4,     5,
       6,     7,    40,    41,    54,    61,    62,    73,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,    74,
      90,    91,    92,    45,    73,     7,   103,   103,   103,   103,
     103,    95,    79,    53,    52,    46,    47,    48,    49,    50,
      51,    40,    41,    42,    43,    44,    61,    62,    73,    77,
      75,     7,    74,    80,    96,    74,    96,    74,    98,    99,
     100,   100,   101,   101,   101,   101,   102,   102,   103,   103,
     103,    74,    96,    95,     9,    13,    21,    23,    27,    39,
      75,    89,    90,    93,    94,    95,    75,    92,    74,    74,
      78,    79,    79,    73,    73,    79,    95,    73,    76,    94,
       7,    76,    93,    79,    94,    95,    95,    79,    95,    76,
      76,    79,    74,    74,    95,    93,    93,    79,    17,    95,
      93,    74,    93
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    85,    86,    86,    87,    87,    88,    88,    89,    89,
      90,    90,    90,    90,    90,    91,    91,    92,    93,    93,
      93,    93,    93,    93,    93,    93,    93,    93,    93,    93,
      94,    94,    94,    95,    96,    96,    97,    97,    98,    98,
      99,    99,    99,   100,   100,   100,   100,   100,   101,   101,
     101,   102,   102,   102,   102,   103,   103,   103,   103,   103,
     103,   104,   104,   104,   104,   104,   104,   104,   104,   105,
     105,   105,   105,   105,   105,   105,   105
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     8,     7,     3,     5,
       1,     1,     1,     1,     1,     1,     3,     2,     2,     1,
       3,     2,     5,     7,     5,     9,     3,     2,     2,     2,
       1,     2,     0,     1,     1,     3,     1,     3,     1,     3,
       1,     3,     3,     1,     3,     3,     3,     3,     1,     3,
       3,     1,     3,     3,     3,     1,     2,     2,     2,     2,
       2,     1,     3,     4,     3,     4,     4,     2,     2,     1,
       3,     4,     1,     1,     1,     1,     3
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
  case 2: /* program: external_declaration  */
#line 53 "parser.y"
    {
        root = (yyvsp[0].ast_node);
        (yyval.ast_node) = create_ast_node(AST_PROGRAM, TYPE_VOID, NULL);
        (yyval.ast_node)->child = (yyvsp[0].ast_node);
    }
#line 1338 "parser.tab.c"
    break;

  case 3: /* program: program external_declaration  */
#line 59 "parser.y"
    {
        if ((yyval.ast_node) == NULL) {
            (yyval.ast_node) = create_ast_node(AST_PROGRAM, TYPE_VOID, NULL);
        }
        if ((yyvsp[0].ast_node) != NULL) {
            if ((yyval.ast_node)->child == NULL) {
                (yyval.ast_node)->child = (yyvsp[0].ast_node);
            } else {
                ASTNode* current = (yyval.ast_node)->child;
                while (current->next != NULL) {
                    current = current->next;
                }
                current->next = (yyvsp[0].ast_node);
            }
        }
        root = (yyval.ast_node);
    }
#line 1360 "parser.tab.c"
    break;

  case 6: /* function_definition: type_specifier IDENTIFIER LPAREN parameter_list RPAREN LBRACE statement_list RBRACE  */
#line 85 "parser.y"
    {
        (yyval.ast_node) = create_ast_node(AST_FUNCTION_DEF, (yyvsp[-7].ast_node)->data_type, (yyvsp[-6].string_val));
        (yyval.ast_node)->child = (yyvsp[-4].ast_node);  // parameters
        (yyval.ast_node)->right = (yyvsp[-1].ast_node);  // body
        free_ast_node((yyvsp[-7].ast_node));
    }
#line 1371 "parser.tab.c"
    break;

  case 7: /* function_definition: type_specifier IDENTIFIER LPAREN RPAREN LBRACE statement_list RBRACE  */
#line 92 "parser.y"
    {
        (yyval.ast_node) = create_ast_node(AST_FUNCTION_DEF, (yyvsp[-6].ast_node)->data_type, (yyvsp[-5].string_val));
        (yyval.ast_node)->right = (yyvsp[-1].ast_node);  // body
        free_ast_node((yyvsp[-6].ast_node));
    }
#line 1381 "parser.tab.c"
    break;

  case 8: /* declaration: type_specifier IDENTIFIER SEMICOLON  */
#line 101 "parser.y"
    {
        (yyval.ast_node) = create_variable_decl((yyvsp[-1].string_val), (yyvsp[-2].ast_node)->data_type);
        free_ast_node((yyvsp[-2].ast_node));
    }
#line 1390 "parser.tab.c"
    break;

  case 9: /* declaration: type_specifier IDENTIFIER ASSIGN expression SEMICOLON  */
#line 106 "parser.y"
    {
        (yyval.ast_node) = create_ast_node(AST_VARIABLE_DEF, (yyvsp[-4].ast_node)->data_type, (yyvsp[-3].string_val));
        (yyval.ast_node)->left = (yyvsp[-1].ast_node);
        free_ast_node((yyvsp[-4].ast_node));
    }
#line 1400 "parser.tab.c"
    break;

  case 10: /* type_specifier: INT  */
#line 115 "parser.y"
    {
        (yyval.ast_node) = create_ast_node(AST_TYPE_SPECIFIER, TYPE_INT, NULL);
    }
#line 1408 "parser.tab.c"
    break;

  case 11: /* type_specifier: FLOAT  */
#line 119 "parser.y"
    {
        (yyval.ast_node) = create_ast_node(AST_TYPE_SPECIFIER, TYPE_FLOAT, NULL);
    }
#line 1416 "parser.tab.c"
    break;

  case 12: /* type_specifier: DOUBLE  */
#line 123 "parser.y"
    {
        (yyval.ast_node) = create_ast_node(AST_TYPE_SPECIFIER, TYPE_DOUBLE, NULL);
    }
#line 1424 "parser.tab.c"
    break;

  case 13: /* type_specifier: CHAR  */
#line 127 "parser.y"
    {
        (yyval.ast_node) = create_ast_node(AST_TYPE_SPECIFIER, TYPE_CHAR, NULL);
    }
#line 1432 "parser.tab.c"
    break;

  case 14: /* type_specifier: VOID  */
#line 131 "parser.y"
    {
        (yyval.ast_node) = create_ast_node(AST_TYPE_SPECIFIER, TYPE_VOID, NULL);
    }
#line 1440 "parser.tab.c"
    break;

  case 16: /* parameter_list: parameter_list COMMA parameter  */
#line 139 "parser.y"
    {
        if ((yyval.ast_node) == NULL) {
            (yyval.ast_node) = create_ast_node(AST_PARAMETER_LIST, TYPE_VOID, NULL);
        }
        if ((yyvsp[0].ast_node) != NULL) {
            if ((yyval.ast_node)->child == NULL) {
                (yyval.ast_node)->child = (yyvsp[0].ast_node);
            } else {
                ASTNode* current = (yyval.ast_node)->child;
                while (current->next != NULL) {
                    current = current->next;
                }
                current->next = (yyvsp[0].ast_node);
            }
        }
    }
#line 1461 "parser.tab.c"
    break;

  case 17: /* parameter: type_specifier IDENTIFIER  */
#line 159 "parser.y"
    {
        (yyval.ast_node) = create_ast_node(AST_PARAMETER, (yyvsp[-1].ast_node)->data_type, (yyvsp[0].string_val));
        free_ast_node((yyvsp[-1].ast_node));
    }
#line 1470 "parser.tab.c"
    break;

  case 18: /* statement: expression SEMICOLON  */
#line 167 "parser.y"
    {
        (yyval.ast_node) = create_ast_node(AST_EXPRESSION_STMT, TYPE_VOID, NULL);
        (yyval.ast_node)->left = (yyvsp[-1].ast_node);
    }
#line 1479 "parser.tab.c"
    break;

  case 19: /* statement: declaration  */
#line 172 "parser.y"
    {
        (yyval.ast_node) = (yyvsp[0].ast_node);
    }
#line 1487 "parser.tab.c"
    break;

  case 20: /* statement: LBRACE statement_list RBRACE  */
#line 176 "parser.y"
    {
        (yyval.ast_node) = create_block_stmt((yyvsp[-1].ast_node));
    }
#line 1495 "parser.tab.c"
    break;

  case 21: /* statement: LBRACE RBRACE  */
#line 180 "parser.y"
    {
        (yyval.ast_node) = create_block_stmt(NULL);
    }
#line 1503 "parser.tab.c"
    break;

  case 22: /* statement: IF LPAREN expression RPAREN statement  */
#line 184 "parser.y"
    {
        (yyval.ast_node) = create_if_stmt((yyvsp[-2].ast_node), (yyvsp[0].ast_node), NULL);
    }
#line 1511 "parser.tab.c"
    break;

  case 23: /* statement: IF LPAREN expression RPAREN statement ELSE statement  */
#line 188 "parser.y"
    {
        (yyval.ast_node) = create_if_stmt((yyvsp[-4].ast_node), (yyvsp[-2].ast_node), (yyvsp[0].ast_node));
    }
#line 1519 "parser.tab.c"
    break;

  case 24: /* statement: WHILE LPAREN expression RPAREN statement  */
#line 192 "parser.y"
    {
        (yyval.ast_node) = create_while_stmt((yyvsp[-2].ast_node), (yyvsp[0].ast_node));
    }
#line 1527 "parser.tab.c"
    break;

  case 25: /* statement: FOR LPAREN expression SEMICOLON expression SEMICOLON expression RPAREN statement  */
#line 196 "parser.y"
    {
        (yyval.ast_node) = create_for_stmt((yyvsp[-6].ast_node), (yyvsp[-4].ast_node), (yyvsp[-2].ast_node), (yyvsp[0].ast_node));
    }
#line 1535 "parser.tab.c"
    break;

  case 26: /* statement: RETURN expression SEMICOLON  */
#line 200 "parser.y"
    {
        (yyval.ast_node) = create_return_stmt((yyvsp[-1].ast_node));
    }
#line 1543 "parser.tab.c"
    break;

  case 27: /* statement: RETURN SEMICOLON  */
#line 204 "parser.y"
    {
        (yyval.ast_node) = create_return_stmt(NULL);
    }
#line 1551 "parser.tab.c"
    break;

  case 28: /* statement: BREAK SEMICOLON  */
#line 208 "parser.y"
    {
        (yyval.ast_node) = create_ast_node(AST_BREAK_STMT, TYPE_VOID, NULL);
    }
#line 1559 "parser.tab.c"
    break;

  case 29: /* statement: CONTINUE SEMICOLON  */
#line 212 "parser.y"
    {
        (yyval.ast_node) = create_ast_node(AST_CONTINUE_STMT, TYPE_VOID, NULL);
    }
#line 1567 "parser.tab.c"
    break;

  case 31: /* statement_list: statement_list statement  */
#line 220 "parser.y"
    {
        if ((yyval.ast_node) == NULL) {
            (yyval.ast_node) = create_ast_node(AST_STATEMENT_LIST, TYPE_VOID, NULL);
        }
        if ((yyvsp[0].ast_node) != NULL) {
            if ((yyval.ast_node)->child == NULL) {
                (yyval.ast_node)->child = (yyvsp[0].ast_node);
            } else {
                ASTNode* current = (yyval.ast_node)->child;
                while (current->next != NULL) {
                    current = current->next;
                }
                current->next = (yyvsp[0].ast_node);
            }
        }
    }
#line 1588 "parser.tab.c"
    break;

  case 32: /* statement_list: %empty  */
#line 237 "parser.y"
    {
        (yyval.ast_node) = NULL;
    }
#line 1596 "parser.tab.c"
    break;

  case 35: /* assignment_expression: IDENTIFIER ASSIGN assignment_expression  */
#line 249 "parser.y"
    {
        (yyval.ast_node) = create_ast_node(AST_ASSIGNMENT, TYPE_VOID, NULL);
        (yyval.ast_node)->left = create_identifier((yyvsp[-2].string_val));
        (yyval.ast_node)->right = (yyvsp[0].ast_node);
    }
#line 1606 "parser.tab.c"
    break;

  case 37: /* logical_or_expression: logical_or_expression OR logical_and_expression  */
#line 259 "parser.y"
    {
        (yyval.ast_node) = create_binary_op(AST_BINARY_OP, (yyvsp[-2].ast_node), (yyvsp[0].ast_node));
    }
#line 1614 "parser.tab.c"
    break;

  case 39: /* logical_and_expression: logical_and_expression AND equality_expression  */
#line 267 "parser.y"
    {
        (yyval.ast_node) = create_binary_op(AST_BINARY_OP, (yyvsp[-2].ast_node), (yyvsp[0].ast_node));
    }
#line 1622 "parser.tab.c"
    break;

  case 41: /* equality_expression: equality_expression EQUAL relational_expression  */
#line 275 "parser.y"
    {
        (yyval.ast_node) = create_binary_op(AST_BINARY_OP, (yyvsp[-2].ast_node), (yyvsp[0].ast_node));
    }
#line 1630 "parser.tab.c"
    break;

  case 42: /* equality_expression: equality_expression NOT_EQUAL relational_expression  */
#line 279 "parser.y"
    {
        (yyval.ast_node) = create_binary_op(AST_BINARY_OP, (yyvsp[-2].ast_node), (yyvsp[0].ast_node));
    }
#line 1638 "parser.tab.c"
    break;

  case 44: /* relational_expression: relational_expression LESS additive_expression  */
#line 287 "parser.y"
    {
        (yyval.ast_node) = create_binary_op(AST_BINARY_OP, (yyvsp[-2].ast_node), (yyvsp[0].ast_node));
    }
#line 1646 "parser.tab.c"
    break;

  case 45: /* relational_expression: relational_expression GREATER additive_expression  */
#line 291 "parser.y"
    {
        (yyval.ast_node) = create_binary_op(AST_BINARY_OP, (yyvsp[-2].ast_node), (yyvsp[0].ast_node));
    }
#line 1654 "parser.tab.c"
    break;

  case 46: /* relational_expression: relational_expression LESS_EQUAL additive_expression  */
#line 295 "parser.y"
    {
        (yyval.ast_node) = create_binary_op(AST_BINARY_OP, (yyvsp[-2].ast_node), (yyvsp[0].ast_node));
    }
#line 1662 "parser.tab.c"
    break;

  case 47: /* relational_expression: relational_expression GREATER_EQUAL additive_expression  */
#line 299 "parser.y"
    {
        (yyval.ast_node) = create_binary_op(AST_BINARY_OP, (yyvsp[-2].ast_node), (yyvsp[0].ast_node));
    }
#line 1670 "parser.tab.c"
    break;

  case 49: /* additive_expression: additive_expression PLUS multiplicative_expression  */
#line 307 "parser.y"
    {
        (yyval.ast_node) = create_binary_op(AST_BINARY_OP, (yyvsp[-2].ast_node), (yyvsp[0].ast_node));
    }
#line 1678 "parser.tab.c"
    break;

  case 50: /* additive_expression: additive_expression MINUS multiplicative_expression  */
#line 311 "parser.y"
    {
        (yyval.ast_node) = create_binary_op(AST_BINARY_OP, (yyvsp[-2].ast_node), (yyvsp[0].ast_node));
    }
#line 1686 "parser.tab.c"
    break;

  case 52: /* multiplicative_expression: multiplicative_expression MULTIPLY unary_expression  */
#line 319 "parser.y"
    {
        (yyval.ast_node) = create_binary_op(AST_BINARY_OP, (yyvsp[-2].ast_node), (yyvsp[0].ast_node));
    }
#line 1694 "parser.tab.c"
    break;

  case 53: /* multiplicative_expression: multiplicative_expression DIVIDE unary_expression  */
#line 323 "parser.y"
    {
        (yyval.ast_node) = create_binary_op(AST_BINARY_OP, (yyvsp[-2].ast_node), (yyvsp[0].ast_node));
    }
#line 1702 "parser.tab.c"
    break;

  case 54: /* multiplicative_expression: multiplicative_expression MODULO unary_expression  */
#line 327 "parser.y"
    {
        (yyval.ast_node) = create_binary_op(AST_BINARY_OP, (yyvsp[-2].ast_node), (yyvsp[0].ast_node));
    }
#line 1710 "parser.tab.c"
    break;

  case 56: /* unary_expression: PLUS unary_expression  */
#line 335 "parser.y"
    {
        (yyval.ast_node) = create_unary_op(AST_UNARY_OP, (yyvsp[0].ast_node));
    }
#line 1718 "parser.tab.c"
    break;

  case 57: /* unary_expression: MINUS unary_expression  */
#line 339 "parser.y"
    {
        (yyval.ast_node) = create_unary_op(AST_UNARY_OP, (yyvsp[0].ast_node));
    }
#line 1726 "parser.tab.c"
    break;

  case 58: /* unary_expression: NOT unary_expression  */
#line 343 "parser.y"
    {
        (yyval.ast_node) = create_unary_op(AST_UNARY_OP, (yyvsp[0].ast_node));
    }
#line 1734 "parser.tab.c"
    break;

  case 59: /* unary_expression: INCREMENT unary_expression  */
#line 347 "parser.y"
    {
        (yyval.ast_node) = create_unary_op(AST_UNARY_OP, (yyvsp[0].ast_node));
    }
#line 1742 "parser.tab.c"
    break;

  case 60: /* unary_expression: DECREMENT unary_expression  */
#line 351 "parser.y"
    {
        (yyval.ast_node) = create_unary_op(AST_UNARY_OP, (yyvsp[0].ast_node));
    }
#line 1750 "parser.tab.c"
    break;

  case 62: /* postfix_expression: postfix_expression LPAREN RPAREN  */
#line 359 "parser.y"
    {
        (yyval.ast_node) = create_function_call((yyvsp[-2].ast_node)->value, NULL);
    }
#line 1758 "parser.tab.c"
    break;

  case 63: /* postfix_expression: postfix_expression LPAREN assignment_expression RPAREN  */
#line 363 "parser.y"
    {
        (yyval.ast_node) = create_function_call((yyvsp[-3].ast_node)->value, (yyvsp[-1].ast_node));
    }
#line 1766 "parser.tab.c"
    break;

  case 64: /* postfix_expression: IDENTIFIER LPAREN RPAREN  */
#line 367 "parser.y"
    {
        (yyval.ast_node) = create_function_call((yyvsp[-2].string_val), NULL);
    }
#line 1774 "parser.tab.c"
    break;

  case 65: /* postfix_expression: IDENTIFIER LPAREN assignment_expression RPAREN  */
#line 371 "parser.y"
    {
        (yyval.ast_node) = create_function_call((yyvsp[-3].string_val), (yyvsp[-1].ast_node));
    }
#line 1782 "parser.tab.c"
    break;

  case 66: /* postfix_expression: postfix_expression LBRACKET expression RBRACKET  */
#line 375 "parser.y"
    {
        (yyval.ast_node) = create_ast_node(AST_ARRAY_ACCESS, TYPE_INT, NULL);
        (yyval.ast_node)->left = (yyvsp[-3].ast_node);
        (yyval.ast_node)->right = (yyvsp[-1].ast_node);
    }
#line 1792 "parser.tab.c"
    break;

  case 67: /* postfix_expression: postfix_expression INCREMENT  */
#line 381 "parser.y"
    {
        (yyval.ast_node) = create_unary_op(AST_UNARY_OP, (yyvsp[-1].ast_node));
    }
#line 1800 "parser.tab.c"
    break;

  case 68: /* postfix_expression: postfix_expression DECREMENT  */
#line 385 "parser.y"
    {
        (yyval.ast_node) = create_unary_op(AST_UNARY_OP, (yyvsp[-1].ast_node));
    }
#line 1808 "parser.tab.c"
    break;

  case 69: /* primary_expression: IDENTIFIER  */
#line 392 "parser.y"
    {
        (yyval.ast_node) = create_identifier((yyvsp[0].string_val));
    }
#line 1816 "parser.tab.c"
    break;

  case 70: /* primary_expression: IDENTIFIER LPAREN RPAREN  */
#line 396 "parser.y"
    {
        (yyval.ast_node) = create_function_call((yyvsp[-2].string_val), NULL);
    }
#line 1824 "parser.tab.c"
    break;

  case 71: /* primary_expression: IDENTIFIER LPAREN assignment_expression RPAREN  */
#line 400 "parser.y"
    {
        (yyval.ast_node) = create_function_call((yyvsp[-3].string_val), (yyvsp[-1].ast_node));
    }
#line 1832 "parser.tab.c"
    break;

  case 72: /* primary_expression: INTEGER_LITERAL  */
#line 404 "parser.y"
    {
        char* value = malloc(32);
        sprintf(value, "%d", (yyvsp[0].int_val));
        (yyval.ast_node) = create_literal(AST_INTEGER_LITERAL, value);
        free(value);
    }
#line 1843 "parser.tab.c"
    break;

  case 73: /* primary_expression: FLOAT_LITERAL  */
#line 411 "parser.y"
    {
        (yyval.ast_node) = create_literal(AST_FLOAT_LITERAL, (yyvsp[0].string_val));
    }
#line 1851 "parser.tab.c"
    break;

  case 74: /* primary_expression: STRING_LITERAL  */
#line 415 "parser.y"
    {
        (yyval.ast_node) = create_literal(AST_STRING_LITERAL, (yyvsp[0].string_val));
    }
#line 1859 "parser.tab.c"
    break;

  case 75: /* primary_expression: CHAR_LITERAL  */
#line 419 "parser.y"
    {
        (yyval.ast_node) = create_literal(AST_CHAR_LITERAL, (yyvsp[0].string_val));
    }
#line 1867 "parser.tab.c"
    break;

  case 76: /* primary_expression: LPAREN expression RPAREN  */
#line 423 "parser.y"
    {
        (yyval.ast_node) = (yyvsp[-1].ast_node);
    }
#line 1875 "parser.tab.c"
    break;


#line 1879 "parser.tab.c"

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

#line 428 "parser.y"


void yyerror(const char* s) {
    printf("Parse error at line %d: %s\n", yylineno, s);
    parse_error = 1;
}

int main(int argc, char* argv[]) {
    if (argc > 1) {
        yyin = fopen(argv[1], "r");
        if (!yyin) {
            printf("Error: Cannot open file %s\n", argv[1]);
            return 1;
        }
    }
    
    int result = yyparse();
    
    if (result == 0 && !parse_error) {
        printf("Parsing successful!\n");
        if (root) {
            printf("\nAST Structure:\n");
            print_ast(root, 0);
            
            // Generate JSON for visualization
            FILE* json_file = fopen("ast.json", "w");
            if (json_file) {
                print_ast_json(root, json_file);
                fclose(json_file);
                printf("\nAST JSON saved to ast.json\n");
            }
            
            // Generate code
            FILE* code_file = fopen("generated.c", "w");
            if (code_file) {
                generate_code(root, code_file);
                fclose(code_file);
                printf("Generated code saved to generated.c\n");
            }
        }
    } else {
        printf("Parsing failed!\n");
    }
    
    if (yyin != stdin) {
        fclose(yyin);
    }
    
    if (root) {
        free_ast_node(root);
    }
    
    return result;
}
