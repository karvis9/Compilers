/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    NUMBER = 258,
    ID = 259,
    MAIN = 260,
    BEGI = 261,
    RETURN = 262,
    WRITE = 263,
    READ = 264,
    IF = 265,
    ENDIF = 266,
    THEN = 267,
    ELSE = 268,
    WHILE = 269,
    END = 270,
    ENDWHILE = 271,
    GE = 272,
    LE = 273,
    NE = 274,
    DO = 275,
    EQUAL = 276,
    AND = 277,
    OR = 278,
    INT = 279,
    BOOL = 280,
    TRUE = 281,
    FALSE = 282,
    DECL = 283,
    ENDDECL = 284,
    START = 285,
    STOP = 286
  };
#endif
/* Tokens.  */
#define NUMBER 258
#define ID 259
#define MAIN 260
#define BEGI 261
#define RETURN 262
#define WRITE 263
#define READ 264
#define IF 265
#define ENDIF 266
#define THEN 267
#define ELSE 268
#define WHILE 269
#define END 270
#define ENDWHILE 271
#define GE 272
#define LE 273
#define NE 274
#define DO 275
#define EQUAL 276
#define AND 277
#define OR 278
#define INT 279
#define BOOL 280
#define TRUE 281
#define FALSE 282
#define DECL 283
#define ENDDECL 284
#define START 285
#define STOP 286

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 24 "final.y" /* yacc.c:1909  */

	int val;
	char *str;
	struct node1 *ptr;
	struct Expression *pointer1;
	struct Argument *pointer2;

#line 124 "y.tab.h" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
