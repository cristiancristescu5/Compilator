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

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    TYPE = 258,                    /* TYPE  */
    ID = 259,                      /* ID  */
    FUNCTION = 260,                /* FUNCTION  */
    CLASS = 261,                   /* CLASS  */
    PRIVATE = 262,                 /* PRIVATE  */
    PUBLIC = 263,                  /* PUBLIC  */
    INTEGER = 264,                 /* INTEGER  */
    BOOLEAN = 265,                 /* BOOLEAN  */
    STRING = 266,                  /* STRING  */
    CHAR = 267,                    /* CHAR  */
    FLOAT = 268,                   /* FLOAT  */
    BEGIN_MAIN = 269,              /* BEGIN_MAIN  */
    END_MAIN = 270,                /* END_MAIN  */
    TYPEOF = 271,                  /* TYPEOF  */
    EVAL = 272,                    /* EVAL  */
    DECLARE = 273,                 /* DECLARE  */
    CONST = 274,                   /* CONST  */
    IF = 275,                      /* IF  */
    ELSE = 276,                    /* ELSE  */
    FOR = 277,                     /* FOR  */
    WHILE = 278,                   /* WHILE  */
    DO = 279,                      /* DO  */
    OR = 280,                      /* OR  */
    AND = 281,                     /* AND  */
    NOT = 282,                     /* NOT  */
    EQ = 283,                      /* EQ  */
    NE = 284,                      /* NE  */
    LR = 285,                      /* LR  */
    LE = 286,                      /* LE  */
    GR = 287,                      /* GR  */
    GE = 288,                      /* GE  */
    ASSIGN = 289,                  /* ASSIGN  */
    ACCESS = 290                   /* ACCESS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define TYPE 258
#define ID 259
#define FUNCTION 260
#define CLASS 261
#define PRIVATE 262
#define PUBLIC 263
#define INTEGER 264
#define BOOLEAN 265
#define STRING 266
#define CHAR 267
#define FLOAT 268
#define BEGIN_MAIN 269
#define END_MAIN 270
#define TYPEOF 271
#define EVAL 272
#define DECLARE 273
#define CONST 274
#define IF 275
#define ELSE 276
#define FOR 277
#define WHILE 278
#define DO 279
#define OR 280
#define AND 281
#define NOT 282
#define EQ 283
#define NE 284
#define LR 285
#define LE 286
#define GR 287
#define GE 288
#define ASSIGN 289
#define ACCESS 290

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 38 "yacc.y"

    int intval;
    char* strval;
    float floatval;
    struct ast* ast_node;

#line 144 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
