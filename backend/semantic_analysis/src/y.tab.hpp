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

#ifndef YY_YY_Y_TAB_HPP_INCLUDED
# define YY_YY_Y_TAB_HPP_INCLUDED
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
    _PROGRAM = 258,                /* _PROGRAM  */
    _CONST = 259,                  /* _CONST  */
    _VAR = 260,                    /* _VAR  */
    _PROCEDURE = 261,              /* _PROCEDURE  */
    _FUNCTION = 262,               /* _FUNCTION  */
    _BEGIN = 263,                  /* _BEGIN  */
    _END = 264,                    /* _END  */
    _ARRAY = 265,                  /* _ARRAY  */
    _OF = 266,                     /* _OF  */
    _IF = 267,                     /* _IF  */
    _THEN = 268,                   /* _THEN  */
    _FOR = 269,                    /* _FOR  */
    _TO = 270,                     /* _TO  */
    _DO = 271,                     /* _DO  */
    _READ = 272,                   /* _READ  */
    _WRITE = 273,                  /* _WRITE  */
    _WHILE = 274,                  /* _WHILE  */
    _NOT = 275,                    /* _NOT  */
    _ELSE = 276,                   /* _ELSE  */
    _RANGE = 277,                  /* _RANGE  */
    _UMINUS = 278,                 /* _UMINUS  */
    _ID = 279,                     /* _ID  */
    _RELOP = 280,                  /* _RELOP  */
    _DIGITS = 281,                 /* _DIGITS  */
    _NUM = 282,                    /* _NUM  */
    _VARTYPE = 283,                /* _VARTYPE  */
    _ADDOP = 284,                  /* _ADDOP  */
    _MULOP = 285,                  /* _MULOP  */
    _ASSIGNOP = 286,               /* _ASSIGNOP  */
    _SEPARATOR = 287,              /* _SEPARATOR  */
    _CHAR = 288,                   /* _CHAR  */
    _BOOLEAN = 289                 /* _BOOLEAN  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_HPP_INCLUDED  */
