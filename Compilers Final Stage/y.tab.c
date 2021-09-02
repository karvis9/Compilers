/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

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
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "final.y" /* yacc.c:339  */
 
	#include <stdio.h> 
	#include<stdlib.h>
	#include "y.tab.h"
	#include "final.c"
	int yylex(void);
	int linecount =0;	
	int vartype;
	int codegen(struct node1 *nd);
	struct Argument *add_to_arg_list(int type,char * name,struct Argument *list);
	void Ginstall(char *name,int type, int size,struct Argument *arglist);
	struct Expression *add_to_exp_linked_list(int type,struct node1 *expression,struct Expression *list);
	void Linstall(char *name, int type, int local_args );
	int checkfunc_decl(int type,char * name, struct Argument * arglist) ;
	struct local_symbol_table *Llookup(char *name);
	struct global_symbol_table *Glookup(char *name);
	int array_def=1;
	int recursion =0;
	int call_func =2;
	int bool_cond=-2;

#line 88 "y.tab.c" /* yacc.c:339  */

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
   by #include "y.tab.h".  */
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
#line 24 "final.y" /* yacc.c:355  */

	int val;
	char *str;
	struct node1 *ptr;
	struct Expression *pointer1;
	struct Argument *pointer2;

#line 198 "y.tab.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 213 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   288

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  49
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  21
/* YYNRULES -- Number of rules.  */
#define YYNRULES  62
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  157

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   286

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    38,    45,     2,
      43,    44,    36,    34,    40,    35,     2,    37,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    39,
      32,    48,    33,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    41,     2,    42,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    46,     2,    47,     2,     2,     2,     2,
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
static const yytype_uint16 yyrline[] =
{
       0,    70,    70,    72,    75,    76,    79,    82,    83,    84,
      85,    86,    89,    93,    94,    95,    96,    97,   101,   102,
     105,   106,   109,   141,   143,   144,   147,   151,   152,   155,
     196,   198,   202,   203,   206,   219,   220,   221,   243,   269,
     270,   271,   274,   275,   276,   279,   283,   287,   291,   295,
     299,   303,   307,   311,   315,   319,   323,   324,   325,   340,
     352,   353,   354
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NUMBER", "ID", "MAIN", "BEGI", "RETURN",
  "WRITE", "READ", "IF", "ENDIF", "THEN", "ELSE", "WHILE", "END",
  "ENDWHILE", "GE", "LE", "NE", "DO", "EQUAL", "AND", "OR", "INT", "BOOL",
  "TRUE", "FALSE", "DECL", "ENDDECL", "START", "STOP", "'<'", "'>'", "'+'",
  "'-'", "'*'", "'/'", "'%'", "';'", "','", "'['", "']'", "'('", "')'",
  "'&'", "'{'", "'}'", "'='", "$accept", "pgm", "Gdefblock", "dclseq",
  "dcl", "intidseq", "arglist", "type", "Fdeflist", "fdef", "LDeclblock",
  "localdeclseq", "ldcl", "locsequence", "Mainblock", "Body", "Retstmt",
  "stmtseq", "stmt", "exprlist", "expr", YY_NULLPTR
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
     285,   286,    60,    62,    43,    45,    42,    47,    37,    59,
      44,    91,    93,    40,    41,    38,   123,   125,    61
};
# endif

#define YYPACT_NINF -124

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-124)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -13,  -124,    56,  -124,    -2,  -124,    -4,  -124,  -124,  -124,
    -124,    66,    68,    70,  -124,  -124,    18,    21,    34,    40,
      66,    73,    19,  -124,    50,    19,  -124,    71,    64,     0,
      88,    72,    95,    96,    98,   148,   130,   111,    66,    66,
      19,   120,    19,   167,   130,  -124,  -124,  -124,    19,   170,
     146,    19,   274,   131,   167,  -124,   136,   138,  -124,  -124,
     -29,   137,   139,   152,   153,   123,  -124,  -124,   132,   170,
    -124,    14,    14,    14,   177,    14,    14,    14,   182,  -124,
    -124,  -124,  -124,   -32,  -124,  -124,    14,   129,   204,    31,
      10,    63,    85,   227,  -124,    14,    14,   107,    14,    14,
      14,    14,    14,    14,    14,    14,    14,    14,    14,   150,
    -124,   160,    14,   161,   189,   183,  -124,   151,   158,   195,
    -124,    55,    55,    55,    55,    55,    55,    49,    49,  -124,
    -124,  -124,    14,  -124,   173,  -124,   274,   274,  -124,  -124,
      14,   235,   174,   101,   271,  -124,  -124,   165,   178,   274,
     180,  -124,  -124,   145,  -124,   181,  -124
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     5,     0,    21,     0,     1,     0,    18,    19,     3,
       4,     0,    18,     0,    20,     2,     9,     0,     0,     0,
       0,     0,    17,     6,     0,    17,     7,     0,     0,     0,
       0,     0,    10,    12,    15,     0,     0,     0,     0,     0,
      17,    16,    25,     0,     0,     8,    11,    13,    17,     0,
       0,    25,     0,     0,     0,    14,    28,     0,    23,    24,
       0,     0,     0,     0,     0,     0,    33,    29,     0,     0,
      26,     0,     0,     0,     0,     0,     0,     0,     0,    32,
      22,    27,    57,    58,    60,    61,     0,     0,     0,     0,
       0,     0,     0,     0,    30,     0,    44,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      37,     0,     0,     0,     0,     0,    31,     0,     0,    43,
      56,    53,    52,    55,    54,    50,    51,    45,    46,    47,
      48,    49,     0,    36,     0,    34,     0,     0,    59,    62,
      44,     0,     0,     0,     0,    42,    38,     0,     0,     0,
       0,    35,    39,     0,    41,     0,    40
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -124,  -124,  -124,  -124,  -124,    33,    -1,     4,  -124,  -124,
     190,   175,  -124,   155,  -124,   193,  -124,  -123,   -65,   109,
     -70
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     3,     4,    10,    17,    28,    29,     6,    14,
      43,    50,    51,    57,    15,    53,    78,    65,    66,   118,
     119
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      79,    87,    88,    89,    34,    91,    92,    93,    11,    95,
      13,    96,    71,   143,   144,     1,    97,    82,    83,    72,
      12,     8,     7,     8,    31,   117,   153,     9,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,    47,
      84,    85,   134,     7,     8,    35,    49,    55,    98,    99,
     100,   112,   101,    26,   113,    49,     5,    86,    20,    21,
      23,    22,   141,   102,   103,   104,   105,   106,   107,   108,
      16,    45,    46,    18,    19,   111,    27,    24,    79,    79,
      98,    99,   100,    25,   101,   106,   107,   108,    79,   104,
     105,   106,   107,   108,    30,   102,   103,   104,   105,   106,
     107,   108,    98,    99,   100,    60,   101,   114,    33,    61,
      62,    63,   148,    32,   149,    64,    37,   102,   103,   104,
     105,   106,   107,   108,    98,    99,   100,    60,   101,   115,
      77,    61,    62,    63,    36,    38,    39,    64,    40,   102,
     103,   104,   105,   106,   107,   108,    98,    99,   100,    60,
     101,   120,    41,    61,    62,    63,   155,    44,    42,    64,
      48,   102,   103,   104,   105,   106,   107,   108,    98,    99,
     100,   109,   101,    52,    56,    58,    69,    70,    67,    80,
      73,    90,    74,   102,   103,   104,   105,   106,   107,   108,
      98,    99,   100,   138,   101,    75,    76,    94,   132,   133,
     135,   136,   139,   137,   151,   102,   103,   104,   105,   106,
     107,   108,    98,    99,   100,   142,   101,   152,   147,   154,
     156,    98,    99,   100,    81,   101,    59,   102,   103,   104,
     105,   106,   107,   108,    54,   140,   102,   103,   104,   105,
     106,   107,   108,   110,    98,    99,   100,    68,   101,   145,
       0,     0,    98,    99,   100,     0,   101,     0,     0,   102,
     103,   104,   105,   106,   107,   108,   116,   102,   103,   104,
     105,   106,   107,   108,   146,    60,     0,     0,    60,    61,
      62,    63,    61,    62,    63,    64,     0,   150,    64
};

static const yytype_int16 yycheck[] =
{
      65,    71,    72,    73,     4,    75,    76,    77,     4,    41,
       6,    43,    41,   136,   137,    28,    86,     3,     4,    48,
      24,    25,    24,    25,    25,    95,   149,    29,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,    40,
      26,    27,   112,    24,    25,    45,    42,    48,    17,    18,
      19,    41,    21,    20,    44,    51,     0,    43,    40,    41,
      39,    43,   132,    32,    33,    34,    35,    36,    37,    38,
       4,    38,    39,     5,     4,    44,     3,    43,   143,   144,
      17,    18,    19,    43,    21,    36,    37,    38,   153,    34,
      35,    36,    37,    38,    44,    32,    33,    34,    35,    36,
      37,    38,    17,    18,    19,     4,    21,    44,    44,     8,
       9,    10,    11,    42,    13,    14,    44,    32,    33,    34,
      35,    36,    37,    38,    17,    18,    19,     4,    21,    44,
       7,     8,     9,    10,    46,    40,    40,    14,    40,    32,
      33,    34,    35,    36,    37,    38,    17,    18,    19,     4,
      21,    44,     4,     8,     9,    10,    11,    46,    28,    14,
      40,    32,    33,    34,    35,    36,    37,    38,    17,    18,
      19,    42,    21,     6,     4,    29,    40,    39,    47,    47,
      43,     4,    43,    32,    33,    34,    35,    36,    37,    38,
      17,    18,    19,    42,    21,    43,    43,    15,    48,    39,
      39,    12,    44,    20,    39,    32,    33,    34,    35,    36,
      37,    38,    17,    18,    19,    42,    21,    39,    44,    39,
      39,    17,    18,    19,    69,    21,    51,    32,    33,    34,
      35,    36,    37,    38,    44,    40,    32,    33,    34,    35,
      36,    37,    38,    39,    17,    18,    19,    54,    21,   140,
      -1,    -1,    17,    18,    19,    -1,    21,    -1,    -1,    32,
      33,    34,    35,    36,    37,    38,    39,    32,    33,    34,
      35,    36,    37,    38,    39,     4,    -1,    -1,     4,     8,
       9,    10,     8,     9,    10,    14,    -1,    16,    14
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    28,    50,    51,    52,     0,    57,    24,    25,    29,
      53,    56,    24,    56,    58,    63,     4,    54,     5,     4,
      40,    41,    43,    39,    43,    43,    54,     3,    55,    56,
      44,    55,    42,    44,     4,    45,    46,    44,    40,    40,
      40,     4,    28,    59,    46,    54,    54,    55,    40,    56,
      60,    61,     6,    64,    59,    55,     4,    62,    29,    60,
       4,     8,     9,    10,    14,    66,    67,    47,    64,    40,
      39,    41,    48,    43,    43,    43,    43,     7,    65,    67,
      47,    62,     3,     4,    26,    27,    43,    69,    69,    69,
       4,    69,    69,    69,    15,    41,    43,    69,    17,    18,
      19,    21,    32,    33,    34,    35,    36,    37,    38,    42,
      39,    44,    41,    44,    44,    44,    39,    69,    68,    69,
      44,    69,    69,    69,    69,    69,    69,    69,    69,    69,
      69,    69,    48,    39,    69,    39,    12,    20,    42,    44,
      40,    69,    42,    66,    66,    68,    39,    44,    11,    13,
      16,    39,    39,    66,    39,    11,    39
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    49,    50,    51,    52,    52,    53,    54,    54,    54,
      54,    54,    54,    55,    55,    55,    55,    55,    56,    56,
      57,    57,    58,    59,    60,    60,    61,    62,    62,    63,
      64,    65,    66,    66,    67,    67,    67,    67,    67,    67,
      67,    67,    68,    68,    68,    69,    69,    69,    69,    69,
      69,    69,    69,    69,    69,    69,    69,    69,    69,    69,
      69,    69,    69
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     3,     2,     0,     3,     3,     6,     1,
       4,     6,     4,     4,     5,     2,     3,     0,     1,     1,
       2,     0,     9,     3,     2,     0,     3,     3,     1,     8,
       4,     3,     2,     1,     5,     8,     5,     4,     7,     8,
      10,     8,     3,     1,     0,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     1,     1,     4,
       1,     1,     4
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
        case 7:
#line 82 "final.y" /* yacc.c:1646  */
    {Ginstall((yyvsp[-2].str), vartype, 1,NULL);}
#line 1415 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 83 "final.y" /* yacc.c:1646  */
    {Ginstall((yyvsp[-5].str),vartype,	(yyvsp[-3].val),NULL);}
#line 1421 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 84 "final.y" /* yacc.c:1646  */
    {Ginstall((yyvsp[0].str), vartype, 1,NULL);}
#line 1427 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 85 "final.y" /* yacc.c:1646  */
    {Ginstall((yyvsp[-3].str),vartype,(yyvsp[-1].val),NULL);}
#line 1433 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 86 "final.y" /* yacc.c:1646  */
    {Ginstall((yyvsp[-5].str),vartype+ 3, 0,(yyvsp[-3].pointer2));local_symbol_table=NULL;argument_binding=-3;local_binding=1;}
#line 1439 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 89 "final.y" /* yacc.c:1646  */
    {Ginstall((yyvsp[-3].str), vartype+3, 0,(yyvsp[-1].pointer2));local_symbol_table=NULL;argument_binding=-3;local_binding=1;}
#line 1445 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 93 "final.y" /* yacc.c:1646  */
    {Linstall((yyvsp[-2].str),vartype,0);(yyval.pointer2)=add_to_arg_list(vartype,(yyvsp[-2].str),(yyvsp[0].pointer2)); }
#line 1451 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 94 "final.y" /* yacc.c:1646  */
    {Linstall((yyvsp[-2].str),vartype+2,0);(yyval.pointer2)=add_to_arg_list(vartype+2,(yyvsp[-2].str),(yyvsp[0].pointer2));}
#line 1457 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 95 "final.y" /* yacc.c:1646  */
    {Linstall((yyvsp[0].str),vartype,0);(yyval.pointer2)=add_to_arg_list(vartype,(yyvsp[0].str),NULL);}
#line 1463 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 96 "final.y" /* yacc.c:1646  */
    {Linstall((yyvsp[0].str),vartype+2,0);(yyval.pointer2)=add_to_arg_list(vartype+2,(yyvsp[0].str),NULL);}
#line 1469 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 97 "final.y" /* yacc.c:1646  */
    {(yyval.pointer2)=NULL;}
#line 1475 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 101 "final.y" /* yacc.c:1646  */
    {vartype=0;}
#line 1481 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 102 "final.y" /* yacc.c:1646  */
    {vartype=1;}
#line 1487 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 109 "final.y" /* yacc.c:1646  */
    {
																													regno=0;
																													int label_no=checkfunc_decl(vartype,(yyvsp[-7].str),(yyvsp[-5].pointer2));
																													printf("VISHAL%d:\n",label_no);
																													printf("PUSH BP\n");
																													printf("MOV BP, SP\n");
																													struct Argument *dummy=Glookup((yyvsp[-7].str))->arglist;
																													int arg_count=0;
																													while(dummy!=NULL) 
																													{
																															arg_count=arg_count+1;
																															dummy=dummy->next;																					
																													}
															
																													struct local_symbol_table *dummy2=local_symbol_table;
																													int total_vars=0;
																													while(dummy2!=NULL) 
																													{
																															total_vars=total_vars+1;
																															dummy2=dummy2->next;
																													}
																													int final=total_vars-arg_count;
															
																													printf("MOV R%d, %d\n",regno,final);
																													printf("MOV R%d, SP\n",regno+1);
																													printf("ADD R%d, R%d\n",regno, regno+1);
																													printf("MOV SP, R%d\n",regno);
																													codegen((yyvsp[-1].ptr));
																													local_symbol_table=NULL;argument_binding=-3;local_binding=1;}
#line 1521 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 151 "final.y" /* yacc.c:1646  */
    {Linstall((yyvsp[-2].str),vartype,1);}
#line 1527 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 152 "final.y" /* yacc.c:1646  */
    {Linstall((yyvsp[0].str),vartype,1);}
#line 1533 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 156 "final.y" /* yacc.c:1646  */
    {
																												regno=0;
																												
																												struct global_symbol_table * temp;
																												temp=symboltable;
																												while(temp!=NULL)
																												{
																												if(temp->type==0 || temp->type==1) {temp=temp->next;continue;}
																								if(temp->is_function==0) {printf("Function %s is declared but not defined\n",temp->var_name);
																								exit(0);}
																																temp=temp->next;
																																}
																													printf("\n\nMAIN:\n");
																													printf("PUSH BP\nMOV BP, SP\n");
															
																													struct local_symbol_table *dummy1=local_symbol_table;
																													int total_vars=0;
																													while(dummy1!=NULL) 
																													{
																														total_vars++;
																														dummy1=dummy1->next;
																													}
															
																													printf("MOV R%d, %d\n",regno,total_vars);
																													printf("MOV R%d, SP\n",regno+1);
																													printf("ADD R%d, R%d\n",regno, regno+1);
																													printf("MOV SP, R%d\n",regno);
																													codegen((yyvsp[-1].ptr));
																													local_symbol_table=NULL;
																													argument_binding=-3;
																													local_binding=1;
	
																													printf("\n\nSTART\n");
																													printf("MOV SP, %d\n",sim_space);
																													printf("CALL MAIN\n");
																													printf("HALT\n");
															
																													exit(0);
													 															}
#line 1577 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 196 "final.y" /* yacc.c:1646  */
    {(yyval.ptr)=make_node(2,recursion,-1,"",NULL,(yyvsp[-2].ptr),(yyvsp[-1].ptr),NULL,NULL,NULL);}
#line 1583 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 198 "final.y" /* yacc.c:1646  */
    {(yyval.ptr)=make_node(2,RETURN,-1,"",(yyvsp[-1].ptr),NULL,NULL,NULL,NULL,NULL);}
#line 1589 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 202 "final.y" /* yacc.c:1646  */
    {(yyval.ptr)=make_node(2,recursion,-1,"",NULL,(yyvsp[-1].ptr),(yyvsp[0].ptr),NULL,NULL,NULL);}
#line 1595 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 203 "final.y" /* yacc.c:1646  */
    {(yyval.ptr)=(yyvsp[0].ptr);}
#line 1601 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 206 "final.y" /* yacc.c:1646  */
    {

																						Ltemp=Llookup((yyvsp[-2].str));
																						if(Ltemp!=NULL)
																			  		{
																			  			(yyval.ptr)=make_node(2,READ,-1,(yyvsp[-2].str),NULL,NULL,NULL,NULL,Ltemp,NULL);
																			  		}
																  					else
																  					{
																  						Gtemp=Glookup((yyvsp[-2].str));
																  						(yyval.ptr)=make_node(2,READ,-1,(yyvsp[-2].str),NULL,NULL,NULL,Gtemp,NULL,NULL);
																  					}
																  	  		}
#line 1619 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 219 "final.y" /* yacc.c:1646  */
    {Gtemp=Glookup((yyvsp[-5].str));(yyval.ptr)=make_node(2,READ,-1,(yyvsp[-5].str),(yyvsp[-3].ptr),NULL,NULL,Gtemp,NULL,NULL);}
#line 1625 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 220 "final.y" /* yacc.c:1646  */
    {(yyval.ptr)=make_node(2,WRITE,-1,"",(yyvsp[-2].ptr),NULL,NULL,NULL,NULL,NULL); }
#line 1631 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 221 "final.y" /* yacc.c:1646  */
    {
														Ltemp=Llookup((yyvsp[-3].str));
														if(Ltemp==NULL)
														{
															Gtemp=Glookup((yyvsp[-3].str));
															if(Gtemp->type != (yyvsp[-1].ptr)->type) 
															{
																printf("Different data types on either side of =\n check line number %d \n",linecount);
																exit(0);
															}
															(yyval.ptr)=make_node(2,3,-1,(yyvsp[-3].str),NULL,(yyvsp[-1].ptr),NULL,Gtemp,NULL,NULL);
														}
														else
														{
															if(Ltemp->type != (yyvsp[-1].ptr)->type && Ltemp->type-2 != (yyvsp[-1].ptr)->type) 
															{
																printf("Different data types on either side of =\n check line number %d \n",linecount);
																exit(0);
															}
															(yyval.ptr)=make_node(2,3,-1,(yyvsp[-3].str),NULL,(yyvsp[-1].ptr),NULL,NULL,Ltemp,NULL);
														}
													}
#line 1658 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 243 "final.y" /* yacc.c:1646  */
    {
														if((yyvsp[-4].ptr)->type!=0) { 
															printf("Array index must be an integer\n");
															exit(0);
														 }
														Ltemp=Llookup((yyvsp[-6].str));
														if(Ltemp==NULL)
														{
															Gtemp=Glookup((yyvsp[-6].str));
															if(Gtemp->type != (yyvsp[-4].ptr)->type) 
															{
																printf("Different data types on either side of =\n check line number %d \n",linecount);
																exit(0);
															}
															(yyval.ptr)=make_node(2,5,-1,(yyvsp[-6].str),NULL,(yyvsp[-4].ptr),(yyvsp[-1].ptr),Gtemp,NULL,NULL);
														}
														else
														{
															if(Ltemp->type != (yyvsp[-4].ptr)->type && Ltemp->type-2 != (yyvsp[-4].ptr)->type) 
															{
																printf("Different data types on either side of =\n check line number %d \n",linecount);
																exit(0);
															}
															(yyval.ptr)=make_node(2,5,-1,(yyvsp[-6].str),NULL,(yyvsp[-4].ptr),(yyvsp[-1].ptr),NULL,Ltemp,NULL);
														}
												   }
#line 1689 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 269 "final.y" /* yacc.c:1646  */
    {if((yyvsp[-5].ptr)->type!=1) { printf("If condition is an Integer and not boolean\ncheck line %d\n",linecount); exit(0);} (yyval.ptr)=make_node(2,IF,-1,"",(yyvsp[-5].ptr),(yyvsp[-2].ptr),NULL,NULL,NULL,NULL);}
#line 1695 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 270 "final.y" /* yacc.c:1646  */
    {if((yyvsp[-7].ptr)->type!=1) { printf("If condition is an Integer and not boolean\ncheck line number %d \n",linecount); exit(0); } (yyval.ptr)=make_node(2,IF,-1,"",(yyvsp[-7].ptr),(yyvsp[-4].ptr),(yyvsp[-2].ptr),NULL,NULL,NULL);}
#line 1701 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 271 "final.y" /* yacc.c:1646  */
    {if((yyvsp[-5].ptr)->type!=1) { printf("If condition is an Integer and not boolean\ncheck line number %d \n",linecount); exit(0); } (yyval.ptr)=make_node(2,WHILE,-1,"",(yyvsp[-5].ptr),(yyvsp[-2].ptr),NULL,NULL,NULL,NULL);}
#line 1707 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 274 "final.y" /* yacc.c:1646  */
    {(yyval.pointer1)=add_to_exp_linked_list((yyvsp[-2].ptr)->type,(yyvsp[-2].ptr),(yyvsp[0].pointer1));}
#line 1713 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 275 "final.y" /* yacc.c:1646  */
    {(yyval.pointer1)=add_to_exp_linked_list((yyvsp[0].ptr)->type,(yyvsp[0].ptr),NULL);}
#line 1719 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 276 "final.y" /* yacc.c:1646  */
    {(yyval.pointer1)=NULL;}
#line 1725 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 279 "final.y" /* yacc.c:1646  */
    {
									if((yyvsp[-2].ptr)->type!=0 || (yyvsp[0].ptr)->type!=0) {printf("e+e error check line number %d \n",linecount); exit(0);}
									(yyval.ptr) = make_node(0,'+',-1,"",(yyvsp[-2].ptr),(yyvsp[0].ptr),NULL,NULL,NULL,NULL);
							    }
#line 1734 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 283 "final.y" /* yacc.c:1646  */
    {
									if((yyvsp[-2].ptr)->type!=0 || (yyvsp[0].ptr)->type!=0) {printf("e-e error check line number %d \n",linecount); exit(0);}
									(yyval.ptr) = make_node(0,'-',-1,"",(yyvsp[-2].ptr),(yyvsp[0].ptr),NULL,NULL,NULL,NULL);
								}
#line 1743 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 287 "final.y" /* yacc.c:1646  */
    {
									if((yyvsp[-2].ptr)->type!=0 || (yyvsp[0].ptr)->type!=0) {printf("e*e error check line number %d \n",linecount); exit(0);}
									(yyval.ptr) = make_node(0,'*',-1,"",(yyvsp[-2].ptr),(yyvsp[0].ptr),NULL,NULL,NULL,NULL);
								}
#line 1752 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 291 "final.y" /* yacc.c:1646  */
    {
									if((yyvsp[-2].ptr)->type!=0 || (yyvsp[0].ptr)->type!=0) {printf("/ error check line number %d \n",linecount); exit(0);}
									(yyval.ptr) = make_node(0,'/',-1,"",(yyvsp[-2].ptr),(yyvsp[0].ptr),NULL,NULL,NULL,NULL);
								}
#line 1761 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 295 "final.y" /* yacc.c:1646  */
    {
									if((yyvsp[-2].ptr)->type!=0 || (yyvsp[0].ptr)->type!=0) {printf("MOD  error check line number %d \n",linecount); exit(0);}
									(yyval.ptr) = make_node(0,'%',-1,"",(yyvsp[-2].ptr),(yyvsp[0].ptr),NULL,NULL,NULL,NULL);
								}
#line 1770 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 299 "final.y" /* yacc.c:1646  */
    {
									if((yyvsp[-2].ptr)->type!=0 || (yyvsp[0].ptr)->type!=0) {printf("< error check line number %d \n",linecount); exit(0);}
			                        (yyval.ptr) = make_node(1,'<',-1,"",(yyvsp[-2].ptr),(yyvsp[0].ptr),NULL,NULL,NULL,NULL);
			                    }
#line 1779 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 303 "final.y" /* yacc.c:1646  */
    {
									if((yyvsp[-2].ptr)->type!=0 || (yyvsp[0].ptr)->type!=0) {printf("> error check line number %d \n",linecount); exit(0);}
			                        (yyval.ptr) = make_node(1,'>',-1,"",(yyvsp[-2].ptr),(yyvsp[0].ptr),NULL,NULL,NULL,NULL);
			                    }
#line 1788 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 307 "final.y" /* yacc.c:1646  */
    {
									if((yyvsp[-2].ptr)->type!=0 || (yyvsp[0].ptr)->type!=0) {printf("LE error check line number %d \n",linecount); exit(0);}
			                        (yyval.ptr) = make_node(1,LE,-1,"",(yyvsp[-2].ptr),(yyvsp[0].ptr),NULL,NULL,NULL,NULL);
			                    }
#line 1797 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 311 "final.y" /* yacc.c:1646  */
    {
									if((yyvsp[-2].ptr)->type!=0 || (yyvsp[0].ptr)->type!=0) {printf("GE error check line number %d \n",linecount); exit(0);}
			                        (yyval.ptr) = make_node(1,GE,-1,"",(yyvsp[-2].ptr),(yyvsp[0].ptr),NULL,NULL,NULL,NULL);
			                    }
#line 1806 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 315 "final.y" /* yacc.c:1646  */
    {
									if((yyvsp[-2].ptr)->type!=0 || (yyvsp[0].ptr)->type!=0) {printf("== error check line number %d \n",linecount); exit(0);}
			                        (yyval.ptr) = make_node(1,EQUAL,-1,"",(yyvsp[-2].ptr),(yyvsp[0].ptr),NULL,NULL,NULL,NULL);
			                    }
#line 1815 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 319 "final.y" /* yacc.c:1646  */
    {
									if((yyvsp[-2].ptr)->type!=0 || (yyvsp[0].ptr)->type!=0) {printf("NE error check line number %d \n",linecount); exit(0);}
			                        (yyval.ptr) = make_node(1,NE,-1,"",(yyvsp[-2].ptr),(yyvsp[0].ptr),NULL,NULL,NULL,NULL);
								}
#line 1824 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 323 "final.y" /* yacc.c:1646  */
    { (yyval.ptr) = (yyvsp[-1].ptr); }
#line 1830 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 324 "final.y" /* yacc.c:1646  */
    { (yyval.ptr) = make_node(0,NUMBER,(yyvsp[0].val),"",NULL,NULL,NULL,NULL,NULL,NULL); }
#line 1836 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 325 "final.y" /* yacc.c:1646  */
    { 
									Ltemp=Llookup((yyvsp[0].str));
									if(Ltemp==NULL)
									{
										Gtemp=Glookup((yyvsp[0].str));
										(yyval.ptr)=make_node(Gtemp->type,ID,-1,(yyvsp[0].str),NULL,NULL,NULL,Gtemp,NULL,NULL);
									}
									else
									{
										int variablefortype;
										variablefortype=Ltemp->type;
										if(variablefortype>1) variablefortype-=2;
										(yyval.ptr)=make_node(variablefortype,ID,-1,(yyvsp[0].str),NULL,NULL,NULL,NULL,Ltemp,NULL);
									}
								}
#line 1856 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 340 "final.y" /* yacc.c:1646  */
    { if((yyvsp[-1].ptr)->type!=0) { printf("Array index must be an integer\n");exit(0); } 
			                      Ltemp=Llookup((yyvsp[-3].str));
    							  if(Ltemp==NULL)
								  {
									Gtemp=Glookup((yyvsp[-3].str));
									(yyval.ptr)=make_node(Gtemp->type,6,-1,(yyvsp[-3].str),(yyvsp[-1].ptr),NULL,NULL,Gtemp,NULL,NULL);
								  }
								  else
								  {
									(yyval.ptr)=make_node(Ltemp->type,6,-1,(yyvsp[-3].str),(yyvsp[-1].ptr),NULL,NULL,NULL,Ltemp,NULL);
								  }
								}
#line 1873 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 352 "final.y" /* yacc.c:1646  */
    { (yyval.ptr) = make_node(1,bool_cond,1,"",NULL,NULL,NULL,NULL,NULL,NULL); }
#line 1879 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 353 "final.y" /* yacc.c:1646  */
    { (yyval.ptr) = make_node(1,bool_cond,0,"",NULL,NULL,NULL,NULL,NULL,NULL); }
#line 1885 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 354 "final.y" /* yacc.c:1646  */
    {
														struct global_symbol_table *glook=Glookup((yyvsp[-3].str));
														int sequencevalue=0;
														struct Expression *list=(yyvsp[-1].pointer1);
														struct Argument *spartan =glook->arglist;
														while(list!=NULL && spartan!=NULL)
														{
															if(spartan->type==list->type){
															printf("%d%d sdada ",spartan->type,list->type);
															list=list->next;
															spartan=spartan->next;
														}
														else{		
														printf("Function %s cadadalled with wrong argument list\n line no %d",(yyvsp[-3].str),linecount);exit(0);}
														}
														list=(yyvsp[-1].pointer1);
														struct Argument *test=glook->arglist;
														while(test!=NULL)
														{
															if(test->type<2) list->isref=0;
															else 
															{
																if(list->expression->node_type!=ID) {printf("Function %s called with expression for referenced variable\n",(yyvsp[-3].str));exit(0);}
																list->isref=1;
															}
															test=test->next;
															list=list->next;
														}
													 	(yyval.ptr)=make_node(glook->type-3,call_func,-1,(yyvsp[-3].str),NULL,NULL,NULL,glook,NULL,(yyvsp[-1].pointer1));
												 }
#line 1920 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1924 "y.tab.c" /* yacc.c:1646  */
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
#line 385 "final.y" /* yacc.c:1906  */
 


struct Argument *add_to_arg_list(int type,char * name,struct Argument *list)
{
	struct Argument *new_decl = malloc(sizeof(struct Argument));
	new_decl->type=type;
	new_decl->name=name;
	new_decl->next=list;
	struct Argument *temp;
	temp=list;
	while(temp!=NULL)
	{
		if(strcmp(new_decl->name,temp->name)==0)
		{
			printf("Same name in arglist see line number %d\n",linecount);
			exit(0);
		} 
		temp=temp->next;
	}
	return new_decl;
}


void Ginstall(char *name,int type, int size,struct Argument *arglist)
{
	
	struct global_symbol_table *temp;
	struct global_symbol_table *new_decl = malloc(sizeof(struct global_symbol_table));	
	new_decl->var_name = name;
	
	new_decl->size = size;
	new_decl->type=type;
	new_decl->arglist=arglist;
	new_decl->is_function=0;
	if (type==0 || type==1)
	{
		new_decl->binding = sim_space;
		sim_space=sim_space+size;
	}
	else
	{
		
		new_decl->binding=funlabel;
		funlabel++;
		new_decl->size=0;
		
	}
	new_decl->next = NULL;
	temp = symboltable;
	if (symboltable == NULL) symboltable = new_decl;
	else 
	{
		while (temp->next != NULL) 
		{	
			if (strcmp(temp->var_name,name) == 0)
			{
				printf("Re-declaration of variable %s in global area see line number %d\n", name,linecount);
				exit(0);
			}
			temp=temp->next;
		}
		if (strcmp(temp->var_name,name) == 0)
		{
			printf("Re-declaration of variable %s in globalarea see line number %d\n", name,linecount);
			exit(0);
		}
		temp->next=new_decl;
	}
}

struct Expression *add_to_exp_linked_list(int type,struct node1 *expression,struct Expression *list)
{
	struct Expression * temp=malloc(sizeof(struct Expression));
	temp->type=type;
	temp->expression=expression;
	temp->next=list;
	return temp;
}

void Linstall(char *name, int type, int local_args )
{
	
	struct local_symbol_table *temp;
	struct local_symbol_table *new_decl  = malloc(sizeof(struct local_symbol_table));	
	new_decl->var_name = name;
	new_decl->type=type;
	if(local_args==0) 
	{
		new_decl->binding=argument_binding;
		argument_binding--;
	}
	else 
        {
        	new_decl->binding=local_binding;
        	local_binding++;
        }
	new_decl->next = NULL;
	temp = local_symbol_table;
	if (local_symbol_table == NULL)
	{ 
		local_symbol_table = new_decl;
	}
	else 
	{
		while (temp->next != NULL)
		{	
			if (strcmp(temp->var_name,name) == 0)
			{
				printf("Re-declaration of variable %s in localarea see line number %d\n", name,linecount);
				exit(0);
			}
			temp=temp->next;
		}
		if (strcmp(temp->var_name,name) == 0)
		{
			printf("Re-declaration of variable %s in localarea see line number %d\n", name,linecount);
			exit(0);
		}
		temp->next=new_decl;
	}	
}


int checkfunc_decl(int type,char * name, struct Argument * arglist)  
{
	struct global_symbol_table *temp;
	temp=symboltable;
	while(temp!=NULL)
	{
		if(strcmp(temp->var_name,name)!=0) {temp=temp->next;continue;}
		if(temp->type!=type+3)
		{
			printf("type diff in func declaration and definition %s area see line number %d\n", name,linecount);
			exit(0);
		}
		struct Argument *tm=temp->arglist;
		struct Argument *ar=arglist;
		while(tm!=NULL)
		{
			if(ar==NULL) 
			{
				printf("Empty arg list passed for function %s area see line number %d\n", name,linecount);
				exit(0);
			}
			if(strcmp(tm->name,ar->name)!=0)
			{
				printf("not same names in definition and declaration for func %s  line number %d\n", name,linecount);
				exit(0);
			}
			if(tm->type!=ar->type)
			{
				printf("not same types of arguments in defninition and declaration for func %s line number %d\n", name,linecount);
				exit(0);
			}
			tm=tm->next;
			ar=ar->next;
		}
		if(ar!=NULL) 
		{
			printf("arg list size is diff for the function in defninition and  declaration %s line number %d\n", name,linecount);
			exit(0);
		}
		temp->is_function=1;
		return temp->binding;
	}
	if(temp==NULL)
	{
		printf("Function %s is not declared\n",name);
	}
}

struct local_symbol_table *Llookup(char *name)
{
	
	struct local_symbol_table *ltemp;
	ltemp = local_symbol_table;
	while(ltemp != NULL)
	{
		if(strcmp(ltemp->var_name, name) == 0)
		{

			return ltemp;
		}

		ltemp = ltemp->next;
	}
	return NULL;
}


struct global_symbol_table *Glookup(char *name)
{
	struct global_symbol_table *temp;
	temp=symboltable;
	while (temp != NULL)
	{
		if (strcmp(temp->var_name,name) == 0)
		{

			return temp;
		}
		temp = temp->next;
	}
	printf("Undeclared variable %s\n",name);
	exit(0);	
}




int codegen(struct node1 *nd)
{
		if(nd->node_type== recursion){                              
				codegen(nd->middle);
				codegen(nd->right);
				}

		else if(nd->node_type== READ){
				if(nd->left!=NULL)      
				{
					codegen(nd->left);
					tmp=nd->gentry->binding;
					printf("MOV R%d,%d\n",regno, tmp);
					printf("ADD R%d,R%d\n",regno-1, regno);
					printf("IN R%d\n",regno);
					printf("MOV [R%d],R%d\n",regno-1,regno);
					regno--;
				}
				else 
				{
					if(nd->lentry==NULL)
					{
						tmp=nd->gentry->binding;
						printf("IN R%d\n",regno);
						printf("MOV [%d], R%d\n",tmp,regno);
					}
					else
					{
						tmp=nd->lentry->binding;
						printf("MOV R%d, BP\n",regno);
						printf("MOV R%d, %d\n",regno+1,tmp);
						printf("ADD R%d, R%d\n",regno,regno+1);
						if(nd->lentry->type>=2) printf("MOV R%d, [R%d]\n",regno,regno);
						printf("IN R%d\n",regno+1);
						printf("MOV [R%d], R%d\n",regno,regno+1);
					}
				}
				}
else if(nd->node_type== WRITE){
				codegen(nd->left);
				printf("OUT R%d\n",regno-1);
				regno--;
				}
else if(nd->node_type== 3){
				codegen(nd->middle);
				if(nd->lentry==NULL)
				{
					tmp=nd->gentry->binding;
					printf("MOV [%d],R%d\n",tmp,regno-1);
					regno--;
				}
				else
				{
					tmp=nd->lentry->binding;
					printf("MOV R%d, BP\n",regno);
					printf("MOV R%d, %d\n",regno+1,tmp);
					printf("ADD R%d, R%d\n",regno,regno+1);
					if(nd->lentry->type>=2) printf("MOV R%d, [R%d]\n",regno,regno);
					printf("MOV [R%d], R%d\n",regno,regno-1);
					regno--;
				}
}
else if(nd->node_type== IF){
				codegen(nd->left);
				int locallabel=label;
				label+=2;
				printf("JZ R%d,LBL%d\n",regno-1,locallabel);
				regno--;
				codegen(nd->middle);
				if(nd->right!=NULL) printf("JMP LBL%d\n",locallabel+1);
				printf("LBL%d:\n",locallabel);
				if(nd->right!=NULL)
				{
					codegen(nd->right);
					printf("LBL%d:\n",locallabel+1);
				}
}
else if(nd->node_type== WHILE){
				;
				int loclabel=label;
				label+=2;
				printf("LBL%d:\n",loclabel);
				codegen(nd->left);
				printf("JZ R%d,LBL%d\n",regno-1,loclabel+1);
				regno--;
				codegen(nd->middle);
				printf("JMP LBL%d\n",loclabel);
				printf("LBL%d:\n",loclabel+1);
}
else if(nd->node_type== '+'){
				codegen(nd->left);
				codegen(nd->middle);
				printf("ADD R%d,R%d\n",regno-2,regno-1);
				regno--;
				return nd->value;
}
else if(nd->node_type== '-'){
				codegen(nd->left);
				codegen(nd->middle);
				printf("SUB R%d,R%d\n",regno-2,regno-1);
				regno--;
}
else if(nd->node_type== '*'){
				codegen(nd->left);
				codegen(nd->middle);
				printf("MUL R%d,R%d\n",regno-2,regno-1);
				regno--;
}
else if(nd->node_type== '/'){
				codegen(nd->left);
				codegen(nd->middle);
				printf("DIV R%d,R%d\n",regno-2,regno-1);
				regno--;
}

else if(nd->node_type== '%'){
				codegen(nd->left);
				codegen(nd->middle);
				printf("MOD R%d,R%d\n",regno-2,regno-1);
				regno--;
}
else if(nd->node_type== '<'){
				codegen(nd->left);
				codegen(nd->middle);
				printf("LT R%d,R%d\n",regno-2,regno-1);
				regno--;
}
else if(nd->node_type== '>'){
				codegen(nd->left);
				codegen(nd->middle);
				printf("GT R%d,R%d\n",regno-2,regno-1);
				regno--;
}
else if(nd->node_type== LE){
				codegen(nd->left);
				codegen(nd->middle);
				printf("LE R%d,R%d\n",regno-2,regno-1);
				regno--;
}
else if(nd->node_type== GE){
				codegen(nd->left);
				codegen(nd->middle);
				printf("GE R%d,R%d\n",regno-2,regno-1);
				regno--;
}
else if(nd->node_type== EQUAL){
				codegen(nd->left);
				codegen(nd->middle);
				printf("EQ R%d,R%d\n",regno-2,regno-1);
				regno--;
}
else if(nd->node_type== NE){
				codegen(nd->left);
				codegen(nd->middle);
				printf("NE R%d,R%d\n",regno-2,regno-1);
				regno--;
}
else if(nd->node_type== NUMBER){
				printf("MOV R%d,%d\n",regno,nd->value);
				regno++;
}
else if(nd->node_type== ID){
				if(nd->lentry==NULL)
				{
					tmp=nd->gentry->binding;
					printf("MOV R%d,[%d]\n", regno, tmp);
					regno++;
				}
				else
				{
					tmp=nd->lentry->binding;
					printf("MOV R%d, BP\n",regno);
					printf("MOV R%d, %d\n",regno+1,tmp);
					printf("ADD R%d, R%d\n",regno+1,regno);
					if(nd->lentry->type>=2) printf("MOV R%d, [R%d]\n",regno+1,regno+1);
					printf("MOV R%d, [R%d]\n",regno, regno+1);
					regno++;
				}	
}
else if(nd->node_type== 6){
				codegen(nd->left);
				tmp = nd->gentry->binding;
				printf("MOV R%d,%d\n", regno, tmp);
				printf("ADD R%d,R%d\n", regno-1, regno);
				printf("MOV R%d,[R%d]\n", regno-1, regno-1);
}
else if(nd->node_type== 5){
				codegen(nd->middle);
				codegen(nd->right);
				tmp=nd->gentry->binding;
				printf("MOV R%d,%d\n", regno, tmp);
				printf("ADD R%d,R%d\n", regno-2, regno);
				printf("MOV [R%d],R%d\n",regno-2,regno-1);
				regno--;
				regno--;
			}
else if(nd->node_type== bool_cond){
		        	printf("MOV R%d,%d\n",regno,nd->value);
				regno++;
}
else if(nd->node_type== call_func){
				
				int i;
				for(i=0;i<regno;i++) printf("PUSH R%d\n",i);
				struct Expression *local_list;
				local_list=nd->exp_linked_list;
				while(local_list!=NULL)
				{
					if(local_list->isref==0)
					{	
						codegen(local_list->expression);
						local_list=local_list->next;
						printf("PUSH R%d\n",regno-1);
						regno--;
					}
					else
					{
						struct local_symbol_table *local_lookup=Llookup(local_list->expression->name);
						struct global_symbol_table *global_lookup=NULL;
						if(local_lookup==NULL) {global_lookup=Glookup(local_list->expression->name);}
						if(local_lookup!=NULL && local_lookup->type>1)
						{
							
							printf("MOV R%d, BP\n",regno);
							printf("MOV R%d, %d\n",regno+1,local_lookup->binding);
							printf("ADD R%d, R%d\n",regno+1,regno);
							printf("MOV R%d, [R%d]\n",regno, regno+1);
					
							local_list=local_list->next;
							printf("PUSH R%d\n",regno);
						}
						else
						{
							
							if(local_lookup==NULL)
							{
								tmp=global_lookup->binding;
								printf("MOV R%d, %d\n", regno, tmp);
								printf("PUSH R%d\n",regno);
							}
							else
							{
								tmp=local_lookup->binding;
								printf("MOV R%d, BP\n",regno);
								printf("MOV R%d, %d\n",regno+1,tmp);
								printf("ADD R%d, R%d\n",regno,regno+1);
								printf("PUSH R%d\n",regno);
							}	
							local_list=local_list->next;
						}
					}
				}
				printf("PUSH R0\n");//for ret address
				printf("CALL VISHAL%d\n",nd->gentry->binding);
				printf("POP R%d\n",regno);
				regno++;
				local_list=nd->exp_linked_list;
				while(local_list!=NULL)
				{
					local_list=local_list->next;
					printf("POP R%d\n",regno);
				}
				
				for(i=regno-2;i>=0;i--) 
				printf("POP R%d\n",i);
}
else if(nd->node_type== RETURN){
				codegen(nd->left);
				printf("MOV R%d, -2\n",regno);
				printf("MOV R%d, BP\n",regno+1);
				printf("ADD R%d, R%d,\n",regno,regno+1);
				printf("MOV [R%d], R%d\n",regno,regno-1);
				printf("MOV SP, BP\n");
				printf("POP BP\nRET\n");
}
}
yywrap()
{
	return 1;
}
yyerror(char *s) 
{ 
	printf("%s %d\n",s,linecount); 
} 

main() 
{
	yyparse(); 
	return 1; 
}
