/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    INTEGER_LITERAL = 258,         /* INTEGER_LITERAL  */
    FLOAT_LITERAL = 259,           /* FLOAT_LITERAL  */
    STRING_LITERAL = 260,          /* STRING_LITERAL  */
    CHAR_LITERAL = 261,            /* CHAR_LITERAL  */
    IDENTIFIER = 262,              /* IDENTIFIER  */
    AUTO = 263,                    /* AUTO  */
    BREAK = 264,                   /* BREAK  */
    CASE = 265,                    /* CASE  */
    CHAR = 266,                    /* CHAR  */
    CONST = 267,                   /* CONST  */
    CONTINUE = 268,                /* CONTINUE  */
    DEFAULT = 269,                 /* DEFAULT  */
    DO = 270,                      /* DO  */
    DOUBLE = 271,                  /* DOUBLE  */
    ELSE = 272,                    /* ELSE  */
    ENUM = 273,                    /* ENUM  */
    EXTERN = 274,                  /* EXTERN  */
    FLOAT = 275,                   /* FLOAT  */
    FOR = 276,                     /* FOR  */
    GOTO = 277,                    /* GOTO  */
    IF = 278,                      /* IF  */
    INT = 279,                     /* INT  */
    LONG = 280,                    /* LONG  */
    REGISTER = 281,                /* REGISTER  */
    RETURN = 282,                  /* RETURN  */
    SHORT = 283,                   /* SHORT  */
    SIGNED = 284,                  /* SIGNED  */
    SIZEOF = 285,                  /* SIZEOF  */
    STATIC = 286,                  /* STATIC  */
    STRUCT = 287,                  /* STRUCT  */
    SWITCH = 288,                  /* SWITCH  */
    TYPEDEF = 289,                 /* TYPEDEF  */
    UNION = 290,                   /* UNION  */
    UNSIGNED = 291,                /* UNSIGNED  */
    VOID = 292,                    /* VOID  */
    VOLATILE = 293,                /* VOLATILE  */
    WHILE = 294,                   /* WHILE  */
    PLUS = 295,                    /* PLUS  */
    MINUS = 296,                   /* MINUS  */
    MULTIPLY = 297,                /* MULTIPLY  */
    DIVIDE = 298,                  /* DIVIDE  */
    MODULO = 299,                  /* MODULO  */
    ASSIGN = 300,                  /* ASSIGN  */
    EQUAL = 301,                   /* EQUAL  */
    NOT_EQUAL = 302,               /* NOT_EQUAL  */
    LESS = 303,                    /* LESS  */
    LESS_EQUAL = 304,              /* LESS_EQUAL  */
    GREATER = 305,                 /* GREATER  */
    GREATER_EQUAL = 306,           /* GREATER_EQUAL  */
    AND = 307,                     /* AND  */
    OR = 308,                      /* OR  */
    NOT = 309,                     /* NOT  */
    BITWISE_AND = 310,             /* BITWISE_AND  */
    BITWISE_OR = 311,              /* BITWISE_OR  */
    BITWISE_XOR = 312,             /* BITWISE_XOR  */
    BITWISE_NOT = 313,             /* BITWISE_NOT  */
    LEFT_SHIFT = 314,              /* LEFT_SHIFT  */
    RIGHT_SHIFT = 315,             /* RIGHT_SHIFT  */
    INCREMENT = 316,               /* INCREMENT  */
    DECREMENT = 317,               /* DECREMENT  */
    PLUS_ASSIGN = 318,             /* PLUS_ASSIGN  */
    MINUS_ASSIGN = 319,            /* MINUS_ASSIGN  */
    MULTIPLY_ASSIGN = 320,         /* MULTIPLY_ASSIGN  */
    DIVIDE_ASSIGN = 321,           /* DIVIDE_ASSIGN  */
    MODULO_ASSIGN = 322,           /* MODULO_ASSIGN  */
    AND_ASSIGN = 323,              /* AND_ASSIGN  */
    OR_ASSIGN = 324,               /* OR_ASSIGN  */
    XOR_ASSIGN = 325,              /* XOR_ASSIGN  */
    LEFT_SHIFT_ASSIGN = 326,       /* LEFT_SHIFT_ASSIGN  */
    RIGHT_SHIFT_ASSIGN = 327,      /* RIGHT_SHIFT_ASSIGN  */
    LPAREN = 328,                  /* LPAREN  */
    RPAREN = 329,                  /* RPAREN  */
    LBRACE = 330,                  /* LBRACE  */
    RBRACE = 331,                  /* RBRACE  */
    LBRACKET = 332,                /* LBRACKET  */
    RBRACKET = 333,                /* RBRACKET  */
    SEMICOLON = 334,               /* SEMICOLON  */
    COMMA = 335,                   /* COMMA  */
    DOT = 336,                     /* DOT  */
    ARROW = 337,                   /* ARROW  */
    QUESTION = 338,                /* QUESTION  */
    COLON = 339                    /* COLON  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 18 "parser.y"

    int int_val;
    char* string_val;
    ASTNode* ast_node;

#line 154 "parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
