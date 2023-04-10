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

#include <stdio.h>
#include "source.hpp"
#include "ast.h"
extern FILE* yyin;
extern char* yytext;
extern int yylineno;
extern int yylex();
int yyerror(const char* s){
    printf("eroare: %s la linia:%d\n",s,yylineno);
    return 1;
}
bool ProgramError() {
    if(haveError) {
        yyerror(errorMessage);
        return true;
    }
    return false;
}
char global_type[200]="";
char global_type_right[200]="";
char global_function[200]="";
char returned_type_by_operation[200]="";
char parameter_types_found[200]="";
char global_params[200]="";
char parameter_function_type[200]="";
char typeofret[200]="";
int testare_parametri=0;
int global_type_ready=1;
int global_statement=0;
int if_while_statement=0;
int nr_params;
bool IsMain;
bool IsFunction;
bool IsGlobal;


#line 109 "y.tab.c"

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

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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

#line 239 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_TYPE = 3,                       /* TYPE  */
  YYSYMBOL_ID = 4,                         /* ID  */
  YYSYMBOL_FUNCTION = 5,                   /* FUNCTION  */
  YYSYMBOL_CLASS = 6,                      /* CLASS  */
  YYSYMBOL_PRIVATE = 7,                    /* PRIVATE  */
  YYSYMBOL_PUBLIC = 8,                     /* PUBLIC  */
  YYSYMBOL_INTEGER = 9,                    /* INTEGER  */
  YYSYMBOL_BOOLEAN = 10,                   /* BOOLEAN  */
  YYSYMBOL_STRING = 11,                    /* STRING  */
  YYSYMBOL_CHAR = 12,                      /* CHAR  */
  YYSYMBOL_FLOAT = 13,                     /* FLOAT  */
  YYSYMBOL_BEGIN_MAIN = 14,                /* BEGIN_MAIN  */
  YYSYMBOL_END_MAIN = 15,                  /* END_MAIN  */
  YYSYMBOL_TYPEOF = 16,                    /* TYPEOF  */
  YYSYMBOL_EVAL = 17,                      /* EVAL  */
  YYSYMBOL_DECLARE = 18,                   /* DECLARE  */
  YYSYMBOL_CONST = 19,                     /* CONST  */
  YYSYMBOL_IF = 20,                        /* IF  */
  YYSYMBOL_ELSE = 21,                      /* ELSE  */
  YYSYMBOL_FOR = 22,                       /* FOR  */
  YYSYMBOL_WHILE = 23,                     /* WHILE  */
  YYSYMBOL_DO = 24,                        /* DO  */
  YYSYMBOL_OR = 25,                        /* OR  */
  YYSYMBOL_AND = 26,                       /* AND  */
  YYSYMBOL_NOT = 27,                       /* NOT  */
  YYSYMBOL_EQ = 28,                        /* EQ  */
  YYSYMBOL_NE = 29,                        /* NE  */
  YYSYMBOL_LR = 30,                        /* LR  */
  YYSYMBOL_LE = 31,                        /* LE  */
  YYSYMBOL_GR = 32,                        /* GR  */
  YYSYMBOL_GE = 33,                        /* GE  */
  YYSYMBOL_34_ = 34,                       /* '+'  */
  YYSYMBOL_35_ = 35,                       /* '@'  */
  YYSYMBOL_36_ = 36,                       /* '/'  */
  YYSYMBOL_37_ = 37,                       /* '%'  */
  YYSYMBOL_38_ = 38,                       /* '*'  */
  YYSYMBOL_ASSIGN = 39,                    /* ASSIGN  */
  YYSYMBOL_ACCESS = 40,                    /* ACCESS  */
  YYSYMBOL_41_ = 41,                       /* ';'  */
  YYSYMBOL_42_ = 42,                       /* '('  */
  YYSYMBOL_43_ = 43,                       /* ')'  */
  YYSYMBOL_44_ = 44,                       /* '-'  */
  YYSYMBOL_45_ = 45,                       /* '['  */
  YYSYMBOL_46_ = 46,                       /* ']'  */
  YYSYMBOL_47_ = 47,                       /* '{'  */
  YYSYMBOL_48_ = 48,                       /* '}'  */
  YYSYMBOL_49_ = 49,                       /* '^'  */
  YYSYMBOL_50_ = 50,                       /* ','  */
  YYSYMBOL_51_ = 51,                       /* ':'  */
  YYSYMBOL_YYACCEPT = 52,                  /* $accept  */
  YYSYMBOL_progr = 53,                     /* progr  */
  YYSYMBOL_main = 54,                      /* main  */
  YYSYMBOL_cod = 55,                       /* cod  */
  YYSYMBOL_statement = 56,                 /* statement  */
  YYSYMBOL_typeof = 57,                    /* typeof  */
  YYSYMBOL_eval = 58,                      /* eval  */
  YYSYMBOL_exp = 59,                       /* exp  */
  YYSYMBOL_declare_class = 60,             /* declare_class  */
  YYSYMBOL_access_class = 61,              /* access_class  */
  YYSYMBOL_assignment = 62,                /* assignment  */
  YYSYMBOL_varop = 63,                     /* varop  */
  YYSYMBOL_control_statement = 64,         /* control_statement  */
  YYSYMBOL_for = 65,                       /* for  */
  YYSYMBOL_while = 66,                     /* while  */
  YYSYMBOL_if = 67,                        /* if  */
  YYSYMBOL_do = 68,                        /* do  */
  YYSYMBOL_global_stuff = 69,              /* global_stuff  */
  YYSYMBOL_global_consts = 70,             /* global_consts  */
  YYSYMBOL_function_consts = 71,           /* function_consts  */
  YYSYMBOL_function_declaratii_consts = 72, /* function_declaratii_consts  */
  YYSYMBOL_function_declaratie_const = 73, /* function_declaratie_const  */
  YYSYMBOL_declaratii_consts = 74,         /* declaratii_consts  */
  YYSYMBOL_declaratie_const = 75,          /* declaratie_const  */
  YYSYMBOL_global_arrays = 76,             /* global_arrays  */
  YYSYMBOL_function_arrays = 77,           /* function_arrays  */
  YYSYMBOL_function_declaratii_arrays = 78, /* function_declaratii_arrays  */
  YYSYMBOL_function_declaratie_array = 79, /* function_declaratie_array  */
  YYSYMBOL_declaratii_arrays = 80,         /* declaratii_arrays  */
  YYSYMBOL_declaratie_array = 81,          /* declaratie_array  */
  YYSYMBOL_global_variables = 82,          /* global_variables  */
  YYSYMBOL_function_variables = 83,        /* function_variables  */
  YYSYMBOL_function_declaratii_variabile = 84, /* function_declaratii_variabile  */
  YYSYMBOL_function_declaratie_variabila = 85, /* function_declaratie_variabila  */
  YYSYMBOL_declaratii_variabile = 86,      /* declaratii_variabile  */
  YYSYMBOL_declaratie_variabila = 87,      /* declaratie_variabila  */
  YYSYMBOL_functions = 88,                 /* functions  */
  YYSYMBOL_declaratii_functii = 89,        /* declaratii_functii  */
  YYSYMBOL_declaratie_functie = 90,        /* declaratie_functie  */
  YYSYMBOL_cod_functie = 91,               /* cod_functie  */
  YYSYMBOL_classes = 92,                   /* classes  */
  YYSYMBOL_declaratii_clase = 93,          /* declaratii_clase  */
  YYSYMBOL_declaratie_clasa = 94,          /* declaratie_clasa  */
  YYSYMBOL_chestii_clasa = 95,             /* chestii_clasa  */
  YYSYMBOL_function_calls = 96,            /* function_calls  */
  YYSYMBOL_list_parametri = 97,            /* list_parametri  */
  YYSYMBOL_parametru = 98                  /* parametru  */
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
#define YYFINAL  17
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   419

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  52
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  47
/* YYNRULES -- Number of rules.  */
#define YYNRULES  129
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  282

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   290


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
       2,     2,     2,     2,     2,     2,     2,    37,     2,     2,
      42,    43,    38,    34,    50,    44,     2,    36,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    51,    41,
       2,     2,     2,     2,    35,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    45,     2,    46,    49,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    47,     2,    48,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    39,
      40
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    68,    68,    70,    72,    73,    74,    75,    76,    77,
      80,    81,    82,    83,    84,    85,    87,    93,   101,   108,
     114,   120,   125,   137,   153,   164,   171,   210,   242,   276,
     280,   317,   321,   360,   396,   432,   468,   513,   532,   551,
     646,   738,   757,   758,   805,   851,   852,   893,   938,   975,
    1013,  1056,  1092,  1129,  1165,  1202,  1203,  1204,  1206,  1207,
    1209,  1210,  1212,  1213,  1214,  1215,  1216,  1218,  1219,  1220,
    1221,  1222,  1223,  1224,  1226,  1228,  1229,  1231,  1232,  1234,
    1240,  1248,  1258,  1265,  1273,  1274,  1276,  1282,  1289,  1298,
    1305,  1312,  1314,  1315,  1317,  1318,  1320,  1328,  1329,  1331,
    1338,  1340,  1341,  1343,  1344,  1346,  1355,  1356,  1358,  1365,
    1367,  1368,  1370,  1373,  1379,  1380,  1382,  1385,  1386,  1388,
    1392,  1399,  1400,  1401,  1402,  1404,  1467,  1531,  1533,  1536
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
  "\"end of file\"", "error", "\"invalid token\"", "TYPE", "ID",
  "FUNCTION", "CLASS", "PRIVATE", "PUBLIC", "INTEGER", "BOOLEAN", "STRING",
  "CHAR", "FLOAT", "BEGIN_MAIN", "END_MAIN", "TYPEOF", "EVAL", "DECLARE",
  "CONST", "IF", "ELSE", "FOR", "WHILE", "DO", "OR", "AND", "NOT", "EQ",
  "NE", "LR", "LE", "GR", "GE", "'+'", "'@'", "'/'", "'%'", "'*'",
  "ASSIGN", "ACCESS", "';'", "'('", "')'", "'-'", "'['", "']'", "'{'",
  "'}'", "'^'", "','", "':'", "$accept", "progr", "main", "cod",
  "statement", "typeof", "eval", "exp", "declare_class", "access_class",
  "assignment", "varop", "control_statement", "for", "while", "if", "do",
  "global_stuff", "global_consts", "function_consts",
  "function_declaratii_consts", "function_declaratie_const",
  "declaratii_consts", "declaratie_const", "global_arrays",
  "function_arrays", "function_declaratii_arrays",
  "function_declaratie_array", "declaratii_arrays", "declaratie_array",
  "global_variables", "function_variables",
  "function_declaratii_variabile", "function_declaratie_variabila",
  "declaratii_variabile", "declaratie_variabila", "functions",
  "declaratii_functii", "declaratie_functie", "cod_functie", "classes",
  "declaratii_clase", "declaratie_clasa", "chestii_clasa",
  "function_calls", "list_parametri", "parametru", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-170)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      19,    -2,    16,    23,    28,    19,  -170,    -4,    19,  -170,
      53,    19,  -170,    55,   -19,    39,    47,  -170,    65,    63,
    -170,    69,  -170,  -170,    52,  -170,  -170,    89,  -170,  -170,
     113,    82,  -170,   106,   104,   152,   156,  -170,    86,  -170,
      28,  -170,   167,  -170,   124,  -170,   130,   232,   141,   137,
     182,  -170,  -170,    63,  -170,  -170,  -170,  -170,  -170,  -170,
    -170,    17,     2,    27,   155,   159,   203,   175,   177,   180,
     194,   182,   169,   171,   184,   -26,   205,   206,  -170,  -170,
    -170,   182,   182,  -170,   211,   216,   229,  -170,    88,   125,
    -170,    43,   275,    21,    43,   286,   290,    43,   321,    43,
    -170,  -170,  -170,  -170,  -170,    43,  -170,  -170,  -170,  -170,
    -170,   357,   182,   363,  -170,   364,   125,   125,   125,   360,
     151,  -170,  -170,  -170,  -170,  -170,    43,    43,   320,   285,
     322,  -170,   324,   326,   223,  -170,   110,   328,   239,   335,
     334,   255,   285,  -170,  -170,   329,   372,   330,  -170,   101,
    -170,  -170,  -170,  -170,   125,   168,   105,   309,   202,  -170,
      43,    43,    43,    43,    43,    43,    43,    43,    43,    43,
      43,    43,    43,  -170,   339,   341,  -170,   286,   286,   286,
    -170,   286,   373,   359,    43,   359,  -170,   336,   365,  -170,
     363,   337,  -170,   285,   343,   338,   345,   346,  -170,   298,
     309,   314,   314,   314,   314,   314,   314,   327,   327,  -170,
    -170,  -170,    43,    43,   170,   349,   349,   123,   348,  -170,
     340,   271,   342,   381,   392,   353,  -170,   132,  -170,  -170,
    -170,    43,  -170,  -170,   285,   285,  -170,    41,   321,    84,
     351,   394,   352,  -170,   365,  -170,   379,   354,   358,  -170,
     355,  -170,   366,   182,  -170,   359,   383,   361,  -170,   344,
     362,   367,   359,    95,  -170,  -170,  -170,  -170,  -170,  -170,
     117,   368,  -170,   369,  -170,   370,   146,  -170,  -170,  -170,
     371,  -170
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,    73,    74,     0,    72,    91,
       0,    71,   100,     0,     0,     0,     0,     1,     0,     0,
     109,     0,    70,    84,     0,    69,    97,     0,    68,   106,
       0,     0,   108,     0,     0,     0,     0,   116,     0,   110,
       0,    85,     0,    98,     0,   107,     0,     0,     0,     0,
       0,     2,   117,     0,   111,    99,    86,    90,    87,    88,
      89,   102,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     9,     0,     0,     0,     0,     0,     0,    56,    57,
      55,     7,     6,   118,     0,     0,     0,   101,     0,   124,
     119,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       3,     8,    14,    15,    12,     0,    13,    11,    10,     5,
       4,     0,   115,    93,   103,     0,   124,   124,   124,     0,
      36,    39,    38,    37,    41,    40,     0,     0,     0,    26,
       0,    25,     0,     0,     0,    22,     0,    23,     0,     0,
       0,     0,    29,   105,   114,     0,     0,     0,    92,     0,
     104,   122,   123,   121,   124,     0,     0,    46,     0,    42,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    45,     0,     0,    16,     0,     0,     0,
      17,     0,     0,     0,     0,     0,   113,     0,    76,    94,
       0,     0,   125,   129,     0,   127,     0,     0,    31,    50,
      47,    53,    54,    49,    48,    51,    52,    30,    32,    33,
      35,    34,     0,     0,    18,    21,    20,    19,     0,    67,
       0,     0,     0,     0,     0,     0,    75,     0,    95,   120,
     126,     0,    44,    43,    28,    27,    24,     0,     0,     0,
       0,     0,     0,    77,     0,   128,    62,     0,     0,    61,
       0,    96,     0,   115,    78,     0,     0,     0,    60,     0,
       0,     0,     0,     0,    79,    82,    80,    81,    83,   112,
       0,     0,    58,     0,    66,     0,     0,    59,    64,    65,
       0,    63
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -170,  -170,  -170,   -47,  -170,  -170,  -170,   181,  -170,   -50,
     -97,   -87,  -170,  -170,  -170,  -170,  -169,   213,  -170,  -170,
     162,  -170,   385,  -170,  -170,  -170,   217,  -170,   147,  -170,
    -170,  -170,   296,  -170,     6,  -170,  -170,     1,  -170,   160,
    -170,   -11,  -170,   -89,  -170,   185,  -170
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     3,    51,   144,    71,    72,    73,   136,    74,   128,
      76,   193,    77,    78,    79,    80,   220,     4,     5,   225,
     226,   227,     6,     7,     8,   147,   148,   149,    81,    10,
      11,    86,    87,    88,    82,    13,    19,   117,    21,   145,
      36,   118,    38,   119,   130,   194,   195
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      75,   140,    14,    70,   129,    20,    12,   134,    37,    89,
     138,    12,   141,   105,    12,   106,   222,    12,   142,    16,
      84,    75,     1,    17,   101,   132,    31,   151,   152,   153,
     133,    75,    75,    18,   109,   110,    45,    23,     2,   157,
     158,    54,    83,    32,     1,    63,    24,   120,   139,    15,
      90,    33,   121,   122,   123,   124,   125,    64,    65,    66,
      85,    67,    75,    68,    69,   191,    91,    92,    34,    35,
     126,     2,    93,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   261,     1,    63,   246,
     127,    46,    42,   271,    26,   116,    29,   221,     1,    63,
      64,    65,    66,    27,    67,    30,    68,    69,    48,   196,
      39,    64,    65,    66,   197,    67,    44,    68,    69,    40,
       1,    63,   116,   116,   116,   234,   235,    52,    44,   114,
      18,    35,   249,    64,    65,    66,    53,    67,   115,    68,
      69,   248,   189,   272,   177,    47,   178,     9,   179,     1,
      63,   190,     9,   180,   181,     9,    49,   177,     9,   178,
     116,   179,    64,    65,    66,   274,    67,   181,    68,    69,
      50,    14,   120,   243,    43,    15,    55,   121,   122,   123,
     124,   125,   244,    61,    62,     1,    63,    75,   139,    75,
     247,    92,   250,   155,   279,   126,   156,    94,    64,    65,
      66,    95,    67,    75,    68,    69,   178,    96,   179,   100,
     102,   192,   103,    75,   181,   127,   273,    97,    22,    98,
      75,    25,    99,   275,    28,   104,    75,   160,   161,   280,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,    56,    57,    58,    59,    60,   107,   108,   160,   161,
     198,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   111,   112,   160,   161,   176,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   113,   131,
     160,   161,   183,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   137,   135,   160,   161,   185,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     160,   161,   238,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   161,    63,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   168,   169,
     170,   171,   172,   264,   265,   266,   267,   268,   214,   215,
     216,   143,   217,   170,   171,   172,   146,    84,   154,   159,
     174,   173,   175,   182,   105,   184,   187,   186,   212,   188,
     213,   223,   218,   219,   224,   229,   230,   237,   231,   239,
     240,   232,   233,   181,   236,   241,   242,   251,   252,   253,
     255,   257,   256,   258,   262,   259,   254,   228,   263,    41,
     269,   150,     0,   260,   270,   276,   245,   277,   278,   281
};

static const yytype_int16 yycheck[] =
{
      50,    98,     4,    50,    91,     4,     0,    94,    19,     7,
      97,     5,    99,    39,     8,    41,   185,    11,   105,     3,
       3,    71,     3,     0,    71,     4,    45,   116,   117,   118,
       9,    81,    82,     5,    81,    82,    30,    41,    19,   126,
     127,    40,    53,     4,     3,     4,    50,     4,    98,    51,
      48,     4,     9,    10,    11,    12,    13,    16,    17,    18,
      43,    20,   112,    22,    23,   154,    39,    40,     3,     6,
      27,    19,    45,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   255,     3,     4,    48,
      47,     9,     3,   262,    41,    89,    41,   184,     3,     4,
      16,    17,    18,    50,    20,    50,    22,    23,     4,     4,
      41,    16,    17,    18,     9,    20,     3,    22,    23,    50,
       3,     4,   116,   117,   118,   212,   213,    41,     3,    41,
       5,     6,    48,    16,    17,    18,    50,    20,    50,    22,
      23,   238,    41,    48,    34,    39,    36,     0,    38,     3,
       4,    50,     5,    43,    44,     8,     4,    34,    11,    36,
     154,    38,    16,    17,    18,    48,    20,    44,    22,    23,
      14,     4,     4,    41,    27,    51,    46,     9,    10,    11,
      12,    13,    50,    42,    47,     3,     4,   237,   238,   239,
     237,    40,   239,    42,    48,    27,    45,    42,    16,    17,
      18,    42,    20,   253,    22,    23,    36,     4,    38,    15,
      41,    43,    41,   263,    44,    47,   263,    42,     5,    42,
     270,     8,    42,   270,    11,    41,   276,    25,    26,   276,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,     9,    10,    11,    12,    13,    41,    41,    25,    26,
      48,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    51,    47,    25,    26,    43,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    49,     4,
      25,    26,    43,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,     4,     9,    25,    26,    43,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      25,    26,    41,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    26,     4,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    34,    35,
      36,    37,    38,     9,    10,    11,    12,    13,   177,   178,
     179,     4,   181,    36,    37,    38,     3,     3,     8,    49,
      46,    49,    46,    45,    39,    41,     4,    48,    39,    49,
      39,    45,     9,    24,    19,    48,    43,    47,    50,    47,
       9,    46,    46,    44,    46,     3,    43,    46,     4,    47,
      21,    43,    48,    48,    21,    39,   244,   190,    47,    24,
      48,   115,    -1,   253,    47,    47,   231,    48,    48,    48
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    19,    53,    69,    70,    74,    75,    76,    80,
      81,    82,    86,    87,     4,    51,     3,     0,     5,    88,
      89,    90,    69,    41,    50,    69,    41,    50,    69,    41,
      50,    45,     4,     4,     3,     6,    92,    93,    94,    41,
      50,    74,     3,    80,     3,    86,     9,    39,     4,     4,
      14,    54,    41,    50,    89,    46,     9,    10,    11,    12,
      13,    42,    47,     4,    16,    17,    18,    20,    22,    23,
      55,    56,    57,    58,    60,    61,    62,    64,    65,    66,
      67,    80,    86,    93,     3,    43,    83,    84,    85,     7,
      48,    39,    40,    45,    42,    42,     4,    42,    42,    42,
      15,    55,    41,    41,    41,    39,    41,    41,    41,    55,
      55,    51,    47,    49,    41,    50,    86,    89,    93,    95,
       4,     9,    10,    11,    12,    13,    27,    47,    61,    63,
      96,     4,     4,     9,    63,     9,    59,     4,    63,    61,
      62,    63,    63,     4,    55,    91,     3,    77,    78,    79,
      84,    95,    95,    95,     8,    42,    45,    63,    63,    49,
      25,    26,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    49,    46,    46,    43,    34,    36,    38,
      43,    44,    45,    43,    41,    43,    48,     4,    49,    41,
      50,    95,    43,    63,    97,    98,     4,     9,    48,    63,
      63,    63,    63,    63,    63,    63,    63,    63,    63,    63,
      63,    63,    39,    39,    59,    59,    59,    59,     9,    24,
      68,    63,    68,    45,    19,    71,    72,    73,    78,    48,
      43,    50,    46,    46,    63,    63,    46,    47,    41,    47,
       9,     3,    43,    41,    50,    97,    48,    55,    62,    48,
      55,    46,     4,    47,    72,    21,    48,    43,    48,    39,
      91,    68,    21,    47,     9,    10,    11,    12,    13,    48,
      47,    68,    48,    55,    48,    55,    47,    48,    48,    48,
      55,    48
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    52,    53,    54,    55,    55,    55,    55,    55,    55,
      56,    56,    56,    56,    56,    56,    57,    58,    59,    59,
      59,    59,    59,    60,    60,    61,    62,    62,    62,    62,
      63,    63,    63,    63,    63,    63,    63,    63,    63,    63,
      63,    63,    63,    63,    63,    63,    63,    63,    63,    63,
      63,    63,    63,    63,    63,    64,    64,    64,    65,    65,
      66,    66,    67,    67,    67,    67,    67,    68,    69,    69,
      69,    69,    69,    69,    70,    71,    71,    72,    72,    73,
      73,    73,    73,    73,    74,    74,    75,    75,    75,    75,
      75,    76,    77,    77,    78,    78,    79,    80,    80,    81,
      82,    83,    83,    84,    84,    85,    86,    86,    87,    88,
      89,    89,    90,    90,    91,    91,    92,    93,    93,    94,
      94,    95,    95,    95,    95,    96,    96,    97,    97,    98
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     4,     3,     2,     2,     1,     1,     2,     1,
       2,     2,     2,     2,     2,     2,     4,     4,     3,     3,
       3,     3,     1,     3,     6,     3,     3,     6,     6,     3,
       3,     3,     3,     3,     3,     3,     1,     1,     1,     1,
       1,     1,     2,     4,     4,     2,     2,     3,     3,     3,
       3,     3,     3,     3,     3,     1,     1,     1,    10,    11,
       8,     7,     7,    13,    12,    12,    11,     1,     2,     2,
       2,     1,     1,     1,     1,     1,     0,     2,     3,     5,
       5,     5,     5,     5,     2,     3,     5,     5,     5,     5,
       5,     1,     1,     0,     2,     3,     5,     2,     3,     5,
       1,     1,     0,     2,     3,     3,     2,     3,     3,     1,
       2,     3,    13,     8,     1,     0,     1,     2,     3,     4,
       8,     2,     2,     2,     0,     3,     4,     1,     3,     1
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
  case 2: /* progr: global_stuff functions classes main  */
#line 68 "yacc.y"
                                            {printf("program corect sintactic si semantic\n");}
#line 1534 "y.tab.c"
    break;

  case 3: /* main: BEGIN_MAIN cod END_MAIN  */
#line 70 "yacc.y"
                              {}
#line 1540 "y.tab.c"
    break;

  case 4: /* cod: declaratii_variabile cod  */
#line 72 "yacc.y"
                              {global_type_ready=1;}
#line 1546 "y.tab.c"
    break;

  case 5: /* cod: declaratii_arrays cod  */
#line 73 "yacc.y"
                            {global_type_ready=1;}
#line 1552 "y.tab.c"
    break;

  case 6: /* cod: declaratii_variabile  */
#line 74 "yacc.y"
                           {global_type_ready=1;}
#line 1558 "y.tab.c"
    break;

  case 7: /* cod: declaratii_arrays  */
#line 75 "yacc.y"
                        {global_type_ready=1;}
#line 1564 "y.tab.c"
    break;

  case 8: /* cod: statement cod  */
#line 76 "yacc.y"
                    {global_type_ready=1;}
#line 1570 "y.tab.c"
    break;

  case 9: /* cod: statement  */
#line 77 "yacc.y"
                {global_type_ready=1;}
#line 1576 "y.tab.c"
    break;

  case 10: /* statement: control_statement ';'  */
#line 80 "yacc.y"
                                 {global_type_ready=1;}
#line 1582 "y.tab.c"
    break;

  case 11: /* statement: assignment ';'  */
#line 81 "yacc.y"
                    {global_type_ready=1;}
#line 1588 "y.tab.c"
    break;

  case 12: /* statement: declare_class ';'  */
#line 82 "yacc.y"
                       {global_type_ready=1;}
#line 1594 "y.tab.c"
    break;

  case 13: /* statement: access_class ';'  */
#line 83 "yacc.y"
                      {global_type_ready=1;}
#line 1600 "y.tab.c"
    break;

  case 14: /* statement: typeof ';'  */
#line 84 "yacc.y"
                {global_type_ready=1;}
#line 1606 "y.tab.c"
    break;

  case 15: /* statement: eval ';'  */
#line 85 "yacc.y"
              {global_type_ready=1;}
#line 1612 "y.tab.c"
    break;

  case 16: /* typeof: TYPEOF '(' varop ')'  */
#line 87 "yacc.y"
                              {
                                global_type_ready=1;
                                printf("\nTipul expresiei de la linia %d este:%s\n",yylineno,typeofret);
                                bzero(typeofret, 200);
                            }
#line 1622 "y.tab.c"
    break;

  case 17: /* eval: EVAL '(' exp ')'  */
#line 93 "yacc.y"
                       {  global_type_ready=1;
                            
                            // printf("\nTipul expresiei de la linia %d este:%s\n",yylineno,typeofret);
                            // bzero(typeofret, 200);
                           // printf("%d\n",evalAst($3));
                            }
#line 1633 "y.tab.c"
    break;

  case 18: /* exp: exp '+' exp  */
#line 101 "yacc.y"
                 {
                    char s[200];
                    strcpy(s, "plus");
                     printf("aici");
                    // buildAst('+', $1, $3, s);
                    printf("aici");
                }
#line 1645 "y.tab.c"
    break;

  case 19: /* exp: exp '-' exp  */
#line 108 "yacc.y"
                 {
                    char s[200];
                    strcpy(s, "minus");
                    // builAst('-', $1, $3, s);

                }
#line 1656 "y.tab.c"
    break;

  case 20: /* exp: exp '*' exp  */
#line 114 "yacc.y"
                 {
           char s[200];
           strcpy(s, "multiply");
           // buildAst('*', $1, $3, s);
                }
#line 1666 "y.tab.c"
    break;

  case 21: /* exp: exp '/' exp  */
#line 120 "yacc.y"
                 {
        char s[200];
        strcpy(s, "devide");
        // buildAst('/', $1, $3, s);
    }
#line 1676 "y.tab.c"
    break;

  case 22: /* exp: INTEGER  */
#line 125 "yacc.y"
             {
                char numar[200]="";
                
                int x=(yyvsp[0].intval);
                

               
                char s[200];
                strcpy(s, "NUMBER");
              
               // buildAst(x, 0, 0,s);
      }
#line 1693 "y.tab.c"
    break;

  case 23: /* declare_class: DECLARE ID ID  */
#line 137 "yacc.y"
                              {
                                    char clasa[200]="";
                                  char nume[200]="";
                                  strcpy(clasa, (yyvsp[-1].strval));
                                  strcpy(nume, (yyvsp[0].strval));
                                  printf("%s\n", nume);
                                  printf("%s\n", clasa);
                                  if(check_if_in_use_class((yyvsp[-1].strval))==1){
                                        printf("sunt aici\n");
                                        AddVarClass(clasa,nume);
                                  }
                                  if(ProgramError()){
                                        return -1;
                                    }

}
#line 1714 "y.tab.c"
    break;

  case 24: /* declare_class: DECLARE ID ID '[' INTEGER ']'  */
#line 153 "yacc.y"
                                            {
                                            if(check_if_in_use_class((yyvsp[-4].strval))==1){
                                                AddArrClass((yyvsp[-4].strval), (yyvsp[-3].strval), (yyvsp[-1].intval));
                                                
                                            }
                                            if(ProgramError()){
                                                return -1;
                                            }

            }
#line 1729 "y.tab.c"
    break;

  case 25: /* access_class: ID ACCESS ID  */
#line 164 "yacc.y"
                           {    //AICI VA TREBUI SA FACI TU CUM TREBUIE PT CLASE
                                // check_if_in_use($1);
                                // if(ProgramError()){
                                //     return -1;
                                // }
                          }
#line 1740 "y.tab.c"
    break;

  case 26: /* assignment: ID ASSIGN varop  */
#line 171 "yacc.y"
                             {
                                global_type_ready=1;
                               
                                char* type1=check_if_in_use_variable((yyvsp[-2].strval));
                                if(ProgramError()){
                                    return -1;
                                }
                                
                                
                                // char* var2=$3;
                                // char type2[200];
                                // int ok=0;
                                // for(int i=0;i<strlen(var2)&&ok==0;i++){
                                //     if(var2[i]==' '){
                                //         ok=1;
                                //         var2[i]='\0';
                                //     }
                                // }
                               
                                //strcpy(global_type_right,type1); //x1:=4-4+3+5%3+4+7+z1+x2[1]%z1+x1<sum(i,sum()^)^; SHOULD NOT WORK
                                 //printf("THIS IS THE ASSIGN %s %s\n",type1,returned_type_by_operation); //IT RETURNS THE LAST OPEERATION
                                strcpy(global_type_right,type1);
                                if(strcmp(type1,returned_type_by_operation)==0){
                                    //booleans=0;
                                    //II SCHIMB BALOAREA LUI ID
                                }
                                else{
                                    haveError = true;
                                    char erroring[200]="";
                                    strcpy(erroring,"Right side of assignment ");
                                    strcat(erroring, type1);
                                    strcat(erroring,"is not the same with the left side in terms of types ");
                                    strcat(erroring,returned_type_by_operation);
                                    printf("%s",erroring);
                                    
                                  if(ProgramError()){
                                   return -1;}
                                }
                            }
#line 1784 "y.tab.c"
    break;

  case 27: /* assignment: ID '[' INTEGER ']' ASSIGN varop  */
#line 210 "yacc.y"
                                         { 
                                global_type_ready=1;
                                
                                char* type1=check_if_in_use_array((yyvsp[-5].strval));
                                
                                if(ProgramError()){
                                    return -1;
                                }
                                // char* var2=$3;
                                // char type2[200];
                                // int ok=0;
                                // for(int i=0;i<strlen(var2)&&ok==0;i++){
                                //     if(var2[i]==' '){
                                //         ok=1;
                                //         var2[i]='\0';
                                //     }
                                // }
                               
                                //strcpy(global_type_right,type1); //x1:=4-4+3+5%3+4+7+z1+x2[1]%z1+x1<sum(i,sum()^)^; SHOULD NOT WORK
                                 //printf("THIS IS THE ASSIGN %s %s\n",type1,returned_type_by_operation); //IT RETURNS THE LAST OPEERATION
                                 strcpy(global_type_right,type1);
                                if(strcmp(type1,returned_type_by_operation)==0){
                                    //booleans=0;
                                    //II SCHIMB BALOAREA LUI ID
                                }
                                else{
                                    haveError = true;
                                    strcpy(errorMessage, "Error: Right side of assignment is not the same with the left side in terms of types!");
                                    if(ProgramError()){
                                    return -1;}
                                }
                                        }
#line 1821 "y.tab.c"
    break;

  case 28: /* assignment: ID '[' ID ']' ASSIGN varop  */
#line 242 "yacc.y"
                                    { 
                                global_type_ready=1;
                               
                                char* type1=check_if_in_use_array((yyvsp[-5].strval));
                                if(ProgramError()){
                                    return -1;
                                }
                                
                                // char* var2=$3;
                                // char type2[200];
                                // int ok=0;
                                // for(int i=0;i<strlen(var2)&&ok==0;i++){
                                //     if(var2[i]==' '){
                                //         ok=1;
                                //         var2[i]='\0';
                                //     }
                                // }
                               
                                //strcpy(global_type_right,type1); //x1:=4-4+3+5%3+4+7+z1+x2[1]%z1+x1<sum(i,sum()^)^; SHOULD NOT WORK
                                // printf("THIS IS THE ASSIGN %s %s\n",type1,returned_type_by_operation); //IT RETURNS THE LAST OPEERATION
                                 strcpy(global_type_right,type1);
                                if(strcmp(type1,returned_type_by_operation)==0){
                                    //booleans=0;
                                    //II SCHIMB BALOAREA LUI ID
                                }
                                else{
                                    haveError = true;
                                    strcpy(errorMessage, "Error: Right side of assignment is not the same with the left side in terms of types!");
                                    if(ProgramError()){
                                    return -1;}
                                }
                                
                              
                                }
#line 1860 "y.tab.c"
    break;

  case 29: /* assignment: access_class ASSIGN varop  */
#line 276 "yacc.y"
                                   {}
#line 1866 "y.tab.c"
    break;

  case 30: /* varop: varop '+' varop  */
#line 280 "yacc.y"
                           { 
                        char* var2=(yyvsp[0].strval);
                        char type1[200];
                        int ok=0;
                         for(int i=0;i<strlen(var2)&&ok==0;i++){
                              if(var2[i]==' '){
                                ok=1;
                                 var2[i]='\0';
                              }
                         }
                         
                         strcpy(type1,var2);
                         strcpy(typeofret,type1);
                        //printf("%s\n", typeofret);
                        strcpy(parameter_function_type,type1);
                        //printf("%s %s\n", global_type, type1);
                        if(strcmp(global_type,"[bool]")==0 || strcmp(global_type,"[char]")==0 || strcmp(global_type,"[string]")==0 ){
                            haveError = true;
                            strcpy(errorMessage, "Error: Operation + is not permitted with these types, only [float] and [int] are admitted!");
                             if(ProgramError()){
                              return -1;}
                        }
                        if(strcmp(global_type,type1)==0){
                            strcpy(returned_type_by_operation,type1);
                            if_while_statement++;
                            //$$=Operation($1,"+",$3); 
                        }
                        else{
                            haveError = true;
                            strcpy(errorMessage, "Error: variables have different data types!");
                             if(ProgramError()){
                              return -1;}
                          }
                       
                        
                        //printf("VARIABILA 1 %s %s \n",global_type,$3);
                        }
#line 1908 "y.tab.c"
    break;

  case 32: /* varop: varop '@' varop  */
#line 321 "yacc.y"
                     {
                        char* var2=(yyvsp[0].strval);
                        char type1[200];
                        int ok=0;
                         for(int i=0;i<strlen(var2)&&ok==0;i++){
                              if(var2[i]==' '){
                                ok=1;
                                 var2[i]='\0';
                              }
                         }
                       
                         strcpy(type1,var2);
                        strcpy(typeofret,type1);
                        //printf("%s\n", typeofret);
                         strcpy(parameter_function_type,type1);
                        // printf("%s %s\n", global_type, type1);
                        if(strcmp(global_type,"[bool]")==0 || strcmp(global_type,"[char]")==0 || strcmp(global_type,"[string]")==0){
                            haveError = true;
                            strcpy(errorMessage, "Error: Operation @ is not permitted with these types, only [float] and [int] are admitted!");
                             if(ProgramError()){
                              return -1;}
                        }
                        if(strcmp(global_type,type1)==0){
                            strcpy(returned_type_by_operation,type1);
                            //$$=Operation($1,"-",$3); 
                        }
                        else{
                            haveError = true;
                            strcpy(errorMessage, "Error: variables have different data types!");
                            strcat(errorMessage, global_type);
                            strcat(errorMessage, "  ");
                            strcat(errorMessage, type1);
                             if(ProgramError()){
                              return -1;}
                          }
                       
                        
                        // printf("VARIABILA 1 %s %s \n",global_type,$3);
     }
#line 1952 "y.tab.c"
    break;

  case 33: /* varop: varop '/' varop  */
#line 360 "yacc.y"
                     {
                        char* var2=(yyvsp[0].strval);
                        char type1[200];
                        int ok=0;
                         for(int i=0;i<strlen(var2)&&ok==0;i++){
                              if(var2[i]==' '){
                                ok=1;
                                 var2[i]='\0';
                              }
                         }
                       
                         strcpy(type1,var2);
                         strcpy(typeofret,type1);
                        // printf("%s\n", typeofret);
                         strcpy(parameter_function_type,type1);
                        // printf("%s %s\n", global_type, type1);
                        if(strcmp(global_type,"[bool]")==0 || strcmp(global_type,"[char]")==0 || strcmp(global_type,"[string]")==0){
                            haveError = true;
                            strcpy(errorMessage, "Error: Operation / is not permitted with these types, only [float] and [int] are admitted!");
                             if(ProgramError()){
                              return -1;}
                        }
                        if(strcmp(global_type,type1)==0){
                             strcpy(returned_type_by_operation,type1);
                           
                            //$$=Operation($1,"/",$3); 
                        }
                        else{
                            haveError = true;
                            strcpy(errorMessage, "Error: variables have different data types!");
                             if(ProgramError()){
                              return -1;}
                          }
                         
                        // printf("VARIABILA 1 %s %s \n",global_type,$3);
     }
#line 1993 "y.tab.c"
    break;

  case 34: /* varop: varop '*' varop  */
#line 396 "yacc.y"
                     { 
                        char* var2=(yyvsp[0].strval);
                        char type1[200];
                        int ok=0;
                        for(int i=0;i<strlen(var2)&&ok==0;i++){
                              if(var2[i]==' '){
                                ok=1;
                                 var2[i]='\0';
                              }
                         }
                         
                         strcpy(type1,var2);
                         strcpy(typeofret, type1);
                        // printf("%s\n", typeofret);
                         strcpy(parameter_function_type,type1);
                         //printf("%s %s\n", global_type, type1);
                         if(strcmp(global_type,"[bool]")==0 || strcmp(global_type,"[char]")==0 || strcmp(global_type,"[string]")==0){
                            haveError = true;
                            strcpy(errorMessage, "Error: Operation * is not permitted with these types, only [float] and [int] are admitted!");
                             if(ProgramError()){
                              return -1;}
                        }
                        if(strcmp(global_type,type1)==0){
                            strcpy(returned_type_by_operation,type1);
                      
                            //$$=Operation($1,"*",$3); 
                        }
                        else{
                            haveError = true;
                            strcpy(errorMessage, "Error: variables have different data types!");
                             if(ProgramError()){
                              return -1;}
                          }
                      
                        // printf("VARIABILA 1 %s %s \n",global_type,$3);
    }
#line 2034 "y.tab.c"
    break;

  case 35: /* varop: varop '%' varop  */
#line 432 "yacc.y"
                     { 
                        char* var2=(yyvsp[0].strval);
                        char type1[200];
                        int ok=0;
                         for(int i=0;i<strlen(var2)&&ok==0;i++){
                              if(var2[i]==' '){
                                ok=1;
                                 var2[i]='\0';
                              }
                         }
                       
                        strcpy(type1,var2);
                        strcpy(typeofret, type1);
                        // printf("%s\n", typeofret);
                        strcpy(parameter_function_type,type1);
                        // printf("%s %s\n", global_type, type1);
                          if(strcmp(global_type,"[bool]")==0 || strcmp(global_type,"[char]")==0 || strcmp(global_type,"[string]")==0){
                            haveError = true;
                            strcpy(errorMessage, "Error: Operation * is not permitted with these types, only [float] and [int] are admitted!");
                             if(ProgramError()){
                              return -1;}
                        }
                        if(strcmp(global_type,type1)==0){
                            strcpy(returned_type_by_operation,type1);
                          
                            //$$=Operation($1,"%",$3); 
                        }
                        else{
                            haveError = true;
                            strcpy(errorMessage, "Error: variables have different data types!");
                             if(ProgramError()){
                              return -1;}
                          }
                         
                        // printf("VARIABILA 1 %s %s \n",global_type,$3);
    }
#line 2075 "y.tab.c"
    break;

  case 36: /* varop: ID  */
#line 468 "yacc.y"
        {    
                char* type=check_if_in_use_variable((yyvsp[0].strval));
                strcpy(typeofret, type);
                //printf("%s\n", typeofret);
                if(ProgramError()){
                    return -1;
                }
                char type_and_value[200];
                strcpy(type_and_value,type);
                strcat(type_and_value," ");
                strcpy(parameter_function_type,type);
                char number[200];  //THIS CONVERTS A NUMBER TO A CHAR*... THIS IS GOING TO BE AN INTEGER
                
                if(GetValue((yyvsp[0].strval))==0){
                    number[0]='0';
                    number[1]='\0';
                    strcat(type_and_value,number);

                }
                else{
                int copy=GetValue((yyvsp[0].strval));
                int i=0;
                while(copy!=0){
                    number[i]= copy%10+'0';
                    copy=copy/10;
                    i++;
                }
                for (int j=0;j<strlen(number)/2;j++)
                    {
                        
                        char aux=number[j];
                        number[j]=number[strlen(number)-j-1];
                        number[strlen(number)-j-1]=aux;
                    }
                    strcat(type_and_value,number);
                }
                (yyval.strval)=type_and_value;
                if(global_type_ready==1){
                   strcpy(global_type,type);
                   global_type_ready=0;
                   strcpy(returned_type_by_operation,type);

                }
            
        }
#line 2125 "y.tab.c"
    break;

  case 37: /* varop: STRING  */
#line 513 "yacc.y"
            {   char type_and_value[200];
                strcpy(type_and_value,"[string]");
                strcat(type_and_value," ");
                strcat(type_and_value,(yyvsp[0].strval));
                strcpy(typeofret, "[string]");
                printf("THIS IS A STRINGGGG \n");
                strcpy(parameter_function_type,"[string]");
                //printf("%s\n",type_and_value);
                
                if(global_type_ready==1){
                    char type[200];
                    strcpy(type,"[string]");
                    strcpy(global_type,type);
                    global_type_ready=0;
                    strcpy(returned_type_by_operation,"[string]");
                }
               strcpy((yyval.strval),"[string]");
                
            }
#line 2149 "y.tab.c"
    break;

  case 38: /* varop: BOOLEAN  */
#line 532 "yacc.y"
              {  
                char type_and_value[200];
                strcpy(type_and_value,"[bool]");
                strcat(type_and_value," ");
                strcat(type_and_value,(yyvsp[0].strval));
                 strcpy(typeofret, "[bool]");
                //printf("%s\n", typeofret);
                //printf("%s\n",type_and_value);
                strcpy(parameter_function_type,"[bool]");
                if(global_type_ready==1){
                    char type[200];
                    strcpy(type,"[bool]");
                    strcpy(global_type,type);
                    global_type_ready=0;
                    strcpy(returned_type_by_operation,"[bool]");
                }
                
                strcpy((yyval.strval),"[bool]");
             }
#line 2173 "y.tab.c"
    break;

  case 39: /* varop: INTEGER  */
#line 551 "yacc.y"
             { 
        
                   /* char number[200]="";  //THIS CONVERTS A NUMBER TO A CHAR*... THIS IS GOING TO BE AN INTEGER
                     int copy=$1;
                     int minus=0;
                     strcpy(typeofret, "[int]");
                     if(copy<0){
                        copy=copy*(-1);
                         minus=1;
                        }
                     int i=0;
                     char type_and_value[200];
                     strcpy(type_and_value,"[int]");
                    strcat(type_and_value," ");
                         if(copy==0){
                            number[0]='0';
                            number[1]='\0';
                            strcat(type_and_value,number);
                            }
                    else{
                        while(copy!=0){
                            number[i]= copy%10+'0';
                            copy=copy/10;
                            i++;
                    }
                        for (int j=0;j<strlen(number)/2;j++)
                         {
                        
                        char aux=number[j];
                        number[j]=number[strlen(number)-j-1];
                        number[strlen(number)-j-1]=aux;
                        }
                    if(minus==1){
                        char number1[200];
                        strcat(number1, "-");
                        strcat(number1, number);
                        strcat(type_and_value,number1);
                    }else{
                            strcat(type_and_value,number);
                        }
                    }
                  strcpy(function_type,"[int]");
                // printf("%s\n", type_and_value);
                 if(global_type_ready==1){
                    char type[200];
                    strcpy(type,"[int]");
                    strcpy(global_type,type);
                    global_type_ready=0;
                    strcpy(returned_type_by_operation,"[int]");
                 }
                
                $$=type_and_value;
                */
                char number[200]="";  //THIS CONVERTS A NUMBER TO A CHAR*... THIS IS GOING TO BE AN INTEGER
                int copy=(yyvsp[0].intval);
                int i=0;
                char type_and_value[200];
                 strcpy(typeofret, "[int]");
                strcpy(type_and_value,"[int]");
                strcat(type_and_value," ");
                if(copy==0){
                    number[0]='0';
                    number[1]='\0';
                    strcat(type_and_value,number);
                }
                else{
                        while(copy!=0){
                        number[i]= copy%10+'0';
                        copy=copy/10;
                        i++;
                    }
        
                    for (int j=0;j<strlen(number)/2;j++)
                    {
                        
                        char aux=number[j];
                        number[j]=number[strlen(number)-j-1];
                        number[strlen(number)-j-1]=aux;
                    }
                    strcat(type_and_value,number);
                }
                 strcpy(parameter_function_type,"[int]");
                 //printf("%s\n", type_and_value);
                 if(global_type_ready==1){
                    char type[200];
                    strcpy(type,"[int]");
                    strcpy(global_type,type);
                    global_type_ready=0;
                    strcpy(returned_type_by_operation,"[int]");
                 }
                 //printf("I entered here %s", type);
               
                (yyval.strval)=type_and_value;
               
                }
#line 2273 "y.tab.c"
    break;

  case 40: /* varop: FLOAT  */
#line 646 "yacc.y"
            {
                //char number[200]="";
                // float copy=$1;
                // float aux=copy;
                // if(copy<0){
                //     copy=copy*(-1);
                // }
                //char type_and_value[200];
                //strcpy(type_and_value,"[float]");
               // strcat(type_and_value," ");
                strcpy(typeofret,"[float]");
                // if(copy==0){
                //     number[0]='0';
                //     number[1]='\0';
                //     strcat(type_and_value,number);
                // }else {
                //     int k=0;
                //     while((int)(copy)%10!=0){
                //         copy*=10;
                //         k++;
                //     }
                //     int pow=k;
                //     copy=copy/10;
                //     int i=0;
                //     // if(aux<0){
                //     //     number[0]='-';
                //     //     i=1;
                //     // }

                //     while(copy!=0){
                //         number[i]=(int)(copy)%10-'0';
                //         i++;
                //     }
                //     if(aux>=0){
                //         for (int j=0;j<strlen(number)/2;j++)
                //             {
                        
                //                 char aux=number[j];
                //                 number[j]=number[strlen(number)-j-1];
                //                 number[strlen(number)-j-1]=aux;
                //              }
                //         char number1[201];
                //         strcpy(number1, number);
                //         for(int i=strlen(number1)-1;i>=pow;i--){
                //             number1[i]=number1[i-1];

                //          }
                //         number[pow]='.';
                //         strcat(type_and_value, number);
                //         printf("%s\n", type_and_value);
                //         if(global_type_ready==1){
                //             char type[200];
                //             strcpy(type,"[float]");
                //             strcpy(global_type,type);
                //             global_type_ready=0;
                //             strcpy(returned_type_by_operation,"[float] ");
                //          }
               
                //     }else {
                //         for (int j=1;j<strlen(number)/2;j++)
                //             {
                        
                //                 char aux=number[j];
                //                 number[j]=number[strlen(number)-j-1];
                //                 number[strlen(number)-j-1]=aux;
                //              }
                //         strcat(type_and_value,"-");
                //         char number2[202];
                //         strcat(number2,"-");
                //         strcat(number2,number);
                //         for(int i=strlen(number2)-1;i>=pow;i--){
                //             number2[i]=number2[i-1];

                //          }
                //         number2[pow]='.';
                //         strcat(type_and_value,number2);
                //         printf("%s\n", type_and_value);
                        strcpy(parameter_function_type,"[float]");
                        if(global_type_ready==1){
                            char type[200];
                            strcpy(type,"[float]");
                            strcpy(global_type,type);
                            global_type_ready=0;
                            strcpy(returned_type_by_operation,"[float]");
                         }
                    printf("%s\n",parameter_function_type);
                    (yyval.strval)=parameter_function_type;
                    // }
                    
                // }

            }
#line 2370 "y.tab.c"
    break;

  case 41: /* varop: CHAR  */
#line 738 "yacc.y"
         {
                char type_and_value[200];
                strcpy(type_and_value,"[char]");
                strcat(type_and_value," ");
                strcpy(typeofret, "[char]");
                strcat(type_and_value,(yyvsp[0].strval));
                //printf("%s\n",type_and_value);
                strcpy(parameter_function_type,"[char]");
                if(global_type_ready==1){
                    char type[200];
                    strcpy(type,"[char]");
                    strcpy(global_type,type);
                    global_type_ready=0;
                    strcpy(returned_type_by_operation,"[char]");
                }
                
                (yyval.strval)=type_and_value;
             }
#line 2393 "y.tab.c"
    break;

  case 42: /* varop: access_class '^'  */
#line 757 "yacc.y"
                      {}
#line 2399 "y.tab.c"
    break;

  case 43: /* varop: ID '[' INTEGER ']'  */
#line 758 "yacc.y"
                        { 
                    char* type=check_if_in_use_array((yyvsp[-3].strval));
                    if(ProgramError()){
                        return -1;
                    }
                strcpy(typeofret, type);
                //printf("%s\n", typeofret);
                strcpy(parameter_function_type,type);
                char type_and_value[200];
                strcpy(type_and_value,type);
                strcat(type_and_value," ");
                
                char number[200];  
                
                if(GetValue((yyvsp[-3].strval))==0){
                    number[0]='0';
                    number[1]='\0';
                    strcat(type_and_value,number);

                }
                else{
                int copy=GetValue((yyvsp[-3].strval));  /*AICI GETVALUE VA TREBUIE MODIFICAT CA SA MEARGA PT VECTOR*/
                int i=0;
                while(copy!=0){
                    number[i]= copy%10+'0';
                    copy=copy/10;
                    i++;
                }
                for (int j=0;j<strlen(number)/2;j++)
                    {
                        
                        char aux=number[j];
                        number[j]=number[strlen(number)-j-1];
                        number[strlen(number)-j-1]=aux;
                    }
                    strcat(type_and_value,number);
                }
               
                (yyval.strval)=type_and_value;
                if(global_type_ready==1){
                   strcpy(global_type,type);
                   global_type_ready=0;
                   strcpy(returned_type_by_operation,type);
                }
                //printf("%s",type);

                }
#line 2451 "y.tab.c"
    break;

  case 44: /* varop: ID '[' ID ']'  */
#line 805 "yacc.y"
                   { 
                char* type=check_if_in_use_array((yyvsp[-3].strval));
                if(ProgramError()){
                    return -1;
                }
                strcpy(typeofret, type);
                //printf("%s\n", typeofret);
                 strcpy(parameter_function_type,type);
                char type_and_value[200];
                strcpy(type_and_value,type);
                strcat(type_and_value," ");
                
                char number[200];  
                
                if(GetValue((yyvsp[-3].strval))==0){
                    number[0]='0';
                    number[1]='\0';
                    strcat(type_and_value,number);

                }
                else{
                int copy=GetValue((yyvsp[-3].strval));  /*AICI GETVALUE VA TREBUIE MODIFICAT CA SA MEARGA PT VECTOR*/
                int i=0;
                while(copy!=0){
                    number[i]= copy%10+'0';
                    copy=copy/10;
                    i++;
                }
                for (int j=0;j<strlen(number)/2;j++)
                    {
                        
                        char aux=number[j];
                        number[j]=number[strlen(number)-j-1];
                        number[strlen(number)-j-1]=aux;
                    }
                    strcat(type_and_value,number);
                }
                if(global_type_ready==1){
                   strcpy(global_type,type);
                   global_type_ready=0;
                   strcpy(returned_type_by_operation,type);
                }
                (yyval.strval)=type_and_value;
                
                //printf("%s",type);
              }
#line 2502 "y.tab.c"
    break;

  case 45: /* varop: function_calls '^'  */
#line 851 "yacc.y"
                         {(yyval.strval)=(yyvsp[-1].strval);}
#line 2508 "y.tab.c"
    break;

  case 46: /* varop: NOT varop  */
#line 852 "yacc.y"
                {
                        char* var2=(yyvsp[0].strval);
                        char type1[200];
                        int j=0;
                        int ok=0;
                        for(int i=0;i<strlen(var2)&&ok==0;i++){
                              if(var2[i]==' '){
                                ok=1;
                                 var2[i]='\0';
                              }
                         }
                         strcpy(type1,var2);
                        strcpy(typeofret, "[bool]");
                       //printf("%s\n", typeofret);
                        //printf("THIS IS A NOT %s\n", var2);
                        // printf("%s %s\n", global_type, type1);
                        strcpy(parameter_function_type,"[bool]");
                        if(global_type_ready==1){
                            char type1[200];
                            strcpy(type1,"[bool]");
                            strcpy(global_type,type1);
                            global_type_ready=0;
                            strcpy(returned_type_by_operation,"[bool]");
                        }
                        if(strcmp(returned_type_by_operation,"[bool]")!=0){
                            haveError = true;
                            strcpy(errorMessage, "Error: Operation NOT is not permitted with these types, only [bool] is admitted!");
                             if(ProgramError()){
                              return -1;}
                        }
                        if(strcmp(global_type,type1)==0){
                            strcpy(returned_type_by_operation ,"[bool]");
                            //$$=Operation($1,"AND",$3); 
                        }
                        else{
                            haveError = true;
                            strcpy(errorMessage, "Error: variables have different data types!");
                             if(ProgramError()){
                              return -1;}
                          }        
                }
#line 2554 "y.tab.c"
    break;

  case 47: /* varop: varop AND varop  */
#line 893 "yacc.y"
                    {   
                        char* var2=(yyvsp[0].strval);
                        // printf("THIS IS AN AND %s\n", var2);
                        char type1[200];
                        int j=0;
                        int ok=0;
                        for(int i=0;i<strlen(var2)&&ok==0;i++){
                              if(var2[i]==' '){
                                ok=1;
                                 var2[i]='\0';
                              }
                         }
                        strcpy(typeofret, "[bool]");
                       //printf("%s\n", typeofret);
                        
                         strcpy(type1,var2);
                        //  printf("THIS IS AN AND %s\n", type1);
                        if(global_type_ready==1){
                            char type1[200];
                            strcpy(type1,"[bool]");
                            strcpy(global_type,type1);
                            global_type_ready=0;
                            strcpy(returned_type_by_operation,"[bool]");
                        }
                         if(strcmp(returned_type_by_operation,"[bool]")!=0){
                            haveError = true;
                            strcpy(errorMessage, "Error: Operation AND is not permitted with these types, only [bool] is admitted!");
                             if(ProgramError()){
                              return -1;}
                        }
                        // printf("%s %s\n", global_type, type1);
                         strcpy(parameter_function_type,"[bool]");
                        if(strcmp(global_type,type1)==0){
                            strcpy(returned_type_by_operation ,"[bool]");
                            //$$=Operation($1,"AND",$3); 
                        }
                        else{
                            haveError = true;
                            strcpy(errorMessage, "Error: variables have different data types!");
                             if(ProgramError()){
                              return -1;}
                          }
                     
                        //printf("VARIABILA 1 %s %s \n",global_type,$3);
                }
#line 2604 "y.tab.c"
    break;

  case 48: /* varop: varop LE varop  */
#line 938 "yacc.y"
                   {
                    char* var2=(yyvsp[0].strval);
                        char type1[200];
                        int ok=0;
                         for(int i=0;i<strlen(var2)&&ok==0;i++){
                              if(var2[i]==' '){
                                ok=1;
                                 var2[i]='\0';
                              }
                         }
                        strcpy(typeofret, "[bool]");
                       //printf("%s\n", typeofret);
                         strcpy(type1,var2);
                        if(global_type_ready==1){
                            char type1[200];
                            strcpy(type1,"[bool]");
                            strcpy(global_type,type1);
                            global_type_ready=0;
                            strcpy(returned_type_by_operation,"[bool]");
                        }
                        
                        // printf("%s %s\n", global_type, type1);
                        strcpy(parameter_function_type,"[bool]");
                        if(strcmp(global_type,type1)==0){
                             strcpy(returned_type_by_operation,"[bool]");
                             
                            //$$=Operation($1,"LE",$3); 
                        }
                        else{
                            haveError = true;
                            strcpy(errorMessage, "Error: variables have different data types!");
                             if(ProgramError()){
                              return -1;}
                          } 
                        
                       // printf("VARIABILA 1 %s %s \n",global_type,$3);
    }
#line 2646 "y.tab.c"
    break;

  case 49: /* varop: varop LR varop  */
#line 975 "yacc.y"
                    {
                        char* var2=(yyvsp[0].strval);
                        char type1[200];
                        int ok=0;
                         for(int i=0;i<strlen(var2)&&ok==0;i++){
                              if(var2[i]==' '){
                                ok=1;
                                 var2[i]='\0';
                              }
                         }
                        strcpy(typeofret, "[bool]");
                       //printf("%s\n", typeofret);
                         strcpy(type1,var2);
                          if(global_type_ready==1){
                            char type1[200];
                            strcpy(type1,"[bool]");
                            strcpy(global_type,type1);
                            global_type_ready=0;
                            strcpy(returned_type_by_operation,"[bool]");
                        }
                       
                        // printf("ACESTA E UN < %s %s\n",global_type_right, type1);
                          strcpy(parameter_function_type,"[bool]");
                        
                        if(strcmp(global_type,type1)==0){
                            strcpy(returned_type_by_operation,"[bool]");
                           
                            //$$=Operation($1,"LR",$3); 
                        }
                        else{
                            haveError = true;
                            strcpy(errorMessage, "Error: variables have different data types");
                             if(ProgramError()){
                              return -1;}
                          }
                        
                        //printf("VARIABILA 1 %s %s \n",global_type,$3);
    }
#line 2689 "y.tab.c"
    break;

  case 50: /* varop: varop OR varop  */
#line 1013 "yacc.y"
                    {
                    char* var2=(yyvsp[0].strval);
                        char type1[200];
                        int ok=0;
                        
                       strcpy(typeofret, "[bool]");
                       //printf("%s\n", typeofret);
                         for(int i=0;i<strlen(var2)&&ok==0;i++){
                              if(var2[i]==' '){
                                ok=1;
                                 var2[i]='\0';
                              }
                         }
                        // printf("THIS IS AN OR %s\n", var2);
                         strcpy(type1,var2);
                        if(global_type_ready==1){
                            char type1[200];
                            strcpy(type1,"[bool]");
                            strcpy(global_type,type1);
                            global_type_ready=0;
                            strcpy(returned_type_by_operation,"[bool]");
                        }
                         if(strcmp(returned_type_by_operation,"[bool]")!=0){
                            haveError = true;
                            strcpy(errorMessage, "Error: Operation OR is not permitted with these types, only [bool] is admitted!");
                             if(ProgramError()){
                              return -1;}
                        }
                        // printf("%s %s\n", global_type, type1);
                        strcpy(parameter_function_type,"[bool]");
                        if(strcmp(global_type,type1)==0){
                            strcpy(returned_type_by_operation ,"[bool]");
                            //$$=Operation($1,"OR",$3); 
                        }
                        else{
                            haveError = true;
                            strcpy(errorMessage, "Error: variables have different data types!");
                             if(ProgramError()){
                              return -1;}
                          }
                       
                       // printf("VARIABILA 1 %s %s \n",global_type,$3);
    }
#line 2737 "y.tab.c"
    break;

  case 51: /* varop: varop GR varop  */
#line 1056 "yacc.y"
                    {
                       char* var2=(yyvsp[0].strval);
                        char type1[200];
                        int ok=0;
                        strcpy(typeofret, "[bool]");
                      // printf("%s\n", typeofret);
                         for(int i=0;i<strlen(var2)&&ok==0;i++){
                              if(var2[i]==' '){
                                ok=1;
                                 var2[i]='\0';
                              }
                         }
                         strcpy(type1,var2);
                        if(global_type_ready==1){
                            char type1[200];
                            strcpy(type1,"[bool]");
                            strcpy(global_type,type1);
                            global_type_ready=0;
                            strcpy(returned_type_by_operation,"[bool]");
                        }
                        // printf("%s %s\n", global_type, type1);
                          strcpy(parameter_function_type,"[bool]");
                        if(strcmp(global_type,type1)==0){
                             strcpy(returned_type_by_operation,"[bool]");
                           
                            //$$=Operation($1,"GR",$3); 
                        }
                        else{
                            haveError = true;
                            strcpy(errorMessage, "Error: variables have different data types!");
                             if(ProgramError()){
                              return -1;}
                          }
                        
                       // printf("VARIABILA 1 %s %s \n",global_type,$3);
    }
#line 2778 "y.tab.c"
    break;

  case 52: /* varop: varop GE varop  */
#line 1092 "yacc.y"
                    {
                        char* var2=(yyvsp[0].strval);
                        char type1[200];
                        int ok=0;
                        strcpy(typeofret, "[bool]");
                      // printf("%s\n", typeofret);
                         for(int i=0;i<strlen(var2)&&ok==0;i++){
                              if(var2[i]==' '){
                                ok=1;
                                 var2[i]='\0';
                              }
                         }
                         strcpy(type1,var2);
                          if(global_type_ready==1){
                            char type1[200];
                            strcpy(type1,"[bool]");
                            strcpy(global_type,type1);
                            global_type_ready=0;
                            strcpy(returned_type_by_operation,"[bool]");
                        }
                        // printf("%s %s\n", global_type, type1);
                          strcpy(parameter_function_type,"[bool]");
                        if(strcmp(global_type,type1)==0){
                             strcpy(returned_type_by_operation,"[bool]");
                          
                            //$$=Operation($1,"GE",$3); 

                        }
                        else{
                            haveError = true;
                            strcpy(errorMessage, "Error: variables have different data types!");
                             if(ProgramError()){
                              return -1;}
                          }
                        
                        //printf("VARIABILA 1 %s %s \n",global_type,$3);
    }
#line 2820 "y.tab.c"
    break;

  case 53: /* varop: varop EQ varop  */
#line 1129 "yacc.y"
                   {
                        char* var2=(yyvsp[0].strval);
                        char type1[200];
                        int ok=0;
                        strcpy(typeofret, "[bool]");
                       //printf("%s\n", typeofret);
                         for(int i=0;i<strlen(var2)&&ok==0;i++){
                              if(var2[i]==' '){
                                ok=1;
                                 var2[i]='\0';
                              }
                         }
                         strcpy(type1,var2);
                          if(global_type_ready==1){
                            char type1[200];
                            strcpy(type1,"[bool]");
                            strcpy(global_type,type1);
                            global_type_ready=0;
                            strcpy(returned_type_by_operation,"[bool]");
                        }
                        // printf("%s %s\n", global_type, type1);
                          strcpy(parameter_function_type,"[bool]");
                        if(strcmp(global_type,type1)==0){
                             strcpy(returned_type_by_operation,"[bool]");
                        
                            //$$=Operation($1,"EQ",$3); 
                        }
                        else{
                            haveError = true;
                            strcpy(errorMessage, "Error: variables have different data types!");
                             if(ProgramError()){
                              return -1;}
                          }
                        
                       // printf("VARIABILA 1 %s %s \n",global_type,$3);
    }
#line 2861 "y.tab.c"
    break;

  case 54: /* varop: varop NE varop  */
#line 1165 "yacc.y"
                    {
                        char* var2=(yyvsp[0].strval);
                        char type1[200];
                        int ok=0;
                        strcpy(typeofret, "[bool]");
                        //printf("%s\n", typeofret);
                         for(int i=0;i<strlen(var2)&&ok==0;i++){
                              if(var2[i]==' '){
                                ok=1;
                                 var2[i]='\0';
                              }
                         }
                         strcpy(type1,var2);
                        if(global_type_ready==1){
                            char type1[200];
                            strcpy(type1,"[bool]");
                            strcpy(global_type,type1);
                            global_type_ready=0;
                            strcpy(returned_type_by_operation,"[bool]");
                        }
                        // printf("%s %s\n", global_type, type1);
                          strcpy(parameter_function_type,"[bool]");
                        if(strcmp(global_type,type1)==0 ){
                             strcpy(returned_type_by_operation,"[bool]");
                
                            //$$=Operation($1,"NE",$3); 
                        }
                        else{
                            haveError = true;
                            strcpy(errorMessage, "Error: variables have different data types!");
                             if(ProgramError()){
                              return -1;}
                          }
                        
                        //printf("VARIABILA 1 %s %s \n",global_type,$3);
    }
#line 2902 "y.tab.c"
    break;

  case 58: /* for: FOR '(' assignment ';' varop ';' assignment ')' '{' '}'  */
#line 1206 "yacc.y"
                                                             {global_type_ready=1;}
#line 2908 "y.tab.c"
    break;

  case 59: /* for: FOR '(' assignment ';' varop ';' assignment ')' '{' cod '}'  */
#line 1207 "yacc.y"
                                                                 {global_type_ready=1;}
#line 2914 "y.tab.c"
    break;

  case 60: /* while: WHILE '(' varop ')' do '{' cod '}'  */
#line 1209 "yacc.y"
                                          {global_type_ready=1;}
#line 2920 "y.tab.c"
    break;

  case 61: /* while: WHILE '(' varop ')' do '{' '}'  */
#line 1210 "yacc.y"
                                   {global_type_ready=1;}
#line 2926 "y.tab.c"
    break;

  case 62: /* if: IF '(' varop ')' do '{' '}'  */
#line 1212 "yacc.y"
                                {global_type_ready=1;}
#line 2932 "y.tab.c"
    break;

  case 63: /* if: IF '(' varop ')' do '{' cod '}' ELSE do '{' cod '}'  */
#line 1213 "yacc.y"
                                                       {global_type_ready=1;}
#line 2938 "y.tab.c"
    break;

  case 64: /* if: IF '(' varop ')' do '{' '}' ELSE do '{' cod '}'  */
#line 1214 "yacc.y"
                                                    {global_type_ready=1;}
#line 2944 "y.tab.c"
    break;

  case 65: /* if: IF '(' varop ')' do '{' cod '}' ELSE do '{' '}'  */
#line 1215 "yacc.y"
                                                   {global_type_ready=1;}
#line 2950 "y.tab.c"
    break;

  case 66: /* if: IF '(' varop ')' do '{' '}' ELSE do '{' '}'  */
#line 1216 "yacc.y"
                                               {global_type_ready=1;}
#line 2956 "y.tab.c"
    break;

  case 67: /* do: DO  */
#line 1218 "yacc.y"
       {global_type_ready=1;}
#line 2962 "y.tab.c"
    break;

  case 79: /* function_declaratie_const: CONST TYPE ID ASSIGN INTEGER  */
#line 1234 "yacc.y"
                                                        {
                                                AddNewConstNat((yyvsp[-3].strval),(yyvsp[-2].strval),(yyvsp[0].intval));
                                                if(ProgramError()){
                                                    return -1;
                                                }
                                                DisplayParamsConst((yyvsp[-3].strval),(yyvsp[-2].strval));}
#line 2973 "y.tab.c"
    break;

  case 80: /* function_declaratie_const: CONST TYPE ID ASSIGN STRING  */
#line 1241 "yacc.y"
                                                {
                                                    AddNewConstString((yyvsp[-3].strval),(yyvsp[-2].strval),(yyvsp[0].strval));
                                                    if(ProgramError()){
                                                        return -1;
                                                    }
                                                    DisplayParamsConst((yyvsp[-3].strval),(yyvsp[-2].strval));
                                                }
#line 2985 "y.tab.c"
    break;

  case 81: /* function_declaratie_const: CONST TYPE ID ASSIGN CHAR  */
#line 1248 "yacc.y"
                                            {
                                char* constanta;
                                strcpy(constanta,(yyvsp[0].strval));
                                char c=constanta[0];
                                  AddNewConstChar((yyvsp[-3].strval),(yyvsp[-2].strval),c);
                                  if(ProgramError()){
                                    return -1;
                                }
                                  DisplayParamsConst((yyvsp[-3].strval),(yyvsp[-2].strval));
                                }
#line 3000 "y.tab.c"
    break;

  case 82: /* function_declaratie_const: CONST TYPE ID ASSIGN BOOLEAN  */
#line 1258 "yacc.y"
                                               {
                                  AddNewConstBoolean((yyvsp[-3].strval),(yyvsp[-2].strval),(yyvsp[0].strval));
                                  if(ProgramError()){
                                    return -1;
                                }
                                  DisplayParamsConst((yyvsp[-3].strval),(yyvsp[-2].strval));
                                }
#line 3012 "y.tab.c"
    break;

  case 83: /* function_declaratie_const: CONST TYPE ID ASSIGN FLOAT  */
#line 1265 "yacc.y"
                                             {
                                  AddNewConstFloat((yyvsp[-3].strval),(yyvsp[-2].strval), (yyvsp[0].floatval));
                                  if(ProgramError()){
                                    return -1;
                                }
                                  DisplayParamsConst((yyvsp[-3].strval),(yyvsp[-2].strval));
                                }
#line 3024 "y.tab.c"
    break;

  case 86: /* declaratie_const: CONST TYPE ID ASSIGN INTEGER  */
#line 1276 "yacc.y"
                                               {
                                                AddNewConstNat((yyvsp[-3].strval),(yyvsp[-2].strval),(yyvsp[0].intval));
                                                if(ProgramError()){
                                                    return -1;
                                                }
                                                }
#line 3035 "y.tab.c"
    break;

  case 87: /* declaratie_const: CONST TYPE ID ASSIGN STRING  */
#line 1283 "yacc.y"
                                                {
                                                    AddNewConstString((yyvsp[-3].strval),(yyvsp[-2].strval),(yyvsp[0].strval));
                                                    if(ProgramError()){
                                                        return -1;
                                                    }
                                                }
#line 3046 "y.tab.c"
    break;

  case 88: /* declaratie_const: CONST TYPE ID ASSIGN CHAR  */
#line 1289 "yacc.y"
                                            {
                                                     char* constanta;
                                                    strcpy(constanta,(yyvsp[0].strval));
                                                    char c=constanta[0];
                                                    AddNewConstChar((yyvsp[-3].strval),(yyvsp[-2].strval),c);
                                                    if(ProgramError()){
                                                        return -1;
                                                    }
                                            }
#line 3060 "y.tab.c"
    break;

  case 89: /* declaratie_const: CONST TYPE ID ASSIGN FLOAT  */
#line 1298 "yacc.y"
                                             {
                                                    AddNewConstFloat((yyvsp[-3].strval),(yyvsp[-2].strval),(yyvsp[0].floatval));
                                                    if(ProgramError()){
                                                        return -1;
                                                    }
                                            }
#line 3071 "y.tab.c"
    break;

  case 90: /* declaratie_const: CONST TYPE ID ASSIGN BOOLEAN  */
#line 1305 "yacc.y"
                                               {
                                                    AddNewConstBoolean((yyvsp[-3].strval),(yyvsp[-2].strval),(yyvsp[0].strval));
                                                    if(ProgramError()){
                                                        return -1;
                                                    }
                                            }
#line 3082 "y.tab.c"
    break;

  case 96: /* function_declaratie_array: TYPE ID '[' INTEGER ']'  */
#line 1320 "yacc.y"
                                                   {
                                            AddNewArray((yyvsp[-4].strval),(yyvsp[-3].strval),(yyvsp[-1].intval));
                                            if(ProgramError()){
                                                return -1;
                                            }
                                            DisplayParamsArray((yyvsp[-4].strval),(yyvsp[-3].strval),(yyvsp[-1].intval));
                                          }
#line 3094 "y.tab.c"
    break;

  case 99: /* declaratie_array: TYPE ID '[' INTEGER ']'  */
#line 1331 "yacc.y"
                                          {
                                            AddNewArray((yyvsp[-4].strval),(yyvsp[-3].strval),(yyvsp[-1].intval));
                                            if(ProgramError()){
                                                return -1;
                                            }
                                          }
#line 3105 "y.tab.c"
    break;

  case 105: /* function_declaratie_variabila: TYPE ':' ID  */
#line 1346 "yacc.y"
                                           {
                                    AddNewVariable((yyvsp[-2].strval),(yyvsp[0].strval));
                                    if(ProgramError()){
                                    return -1;
                                    }
                                    DisplayParams((yyvsp[-2].strval),(yyvsp[0].strval));
                                  }
#line 3117 "y.tab.c"
    break;

  case 108: /* declaratie_variabila: TYPE ':' ID  */
#line 1358 "yacc.y"
                                  {
                                    AddNewVariable((yyvsp[-2].strval),(yyvsp[0].strval));
                                    if(ProgramError()){
                                    return -1;
                                    }
                                  }
#line 3128 "y.tab.c"
    break;

  case 109: /* functions: declaratii_functii  */
#line 1365 "yacc.y"
                              {}
#line 3134 "y.tab.c"
    break;

  case 110: /* declaratii_functii: declaratie_functie ';'  */
#line 1367 "yacc.y"
                                          {}
#line 3140 "y.tab.c"
    break;

  case 111: /* declaratii_functii: declaratie_functie ',' declaratii_functii  */
#line 1368 "yacc.y"
                                                          {}
#line 3146 "y.tab.c"
    break;

  case 112: /* declaratie_functie: FUNCTION TYPE ID '(' function_variables '^' function_arrays '^' function_consts ')' '{' cod_functie '}'  */
#line 1370 "yacc.y"
                                                                                                                             {AddNewFunction((yyvsp[-11].strval),(yyvsp[-10].strval)); if(ProgramError()){
                                                                                                                                    return -1;
                                                                                                                                }}
#line 3154 "y.tab.c"
    break;

  case 113: /* declaratie_functie: FUNCTION TYPE ID '(' ')' '{' cod_functie '}'  */
#line 1373 "yacc.y"
                                                              {AddNewFunction((yyvsp[-6].strval),(yyvsp[-5].strval));
                                if(ProgramError()){
                                    return -1;
                                }
                                }
#line 3164 "y.tab.c"
    break;

  case 116: /* classes: declaratii_clase  */
#line 1382 "yacc.y"
                          {}
#line 3170 "y.tab.c"
    break;

  case 117: /* declaratii_clase: declaratie_clasa ';'  */
#line 1385 "yacc.y"
                                       {}
#line 3176 "y.tab.c"
    break;

  case 118: /* declaratii_clase: declaratie_clasa ',' declaratii_clase  */
#line 1386 "yacc.y"
                                                      {}
#line 3182 "y.tab.c"
    break;

  case 119: /* declaratie_clasa: CLASS ID '{' '}'  */
#line 1388 "yacc.y"
                                   {                              AddNewClass((yyvsp[-2].strval));
                                                                 if(ProgramError()){
                                                                    return -1;
                                                                        }  }
#line 3191 "y.tab.c"
    break;

  case 120: /* declaratie_clasa: CLASS ID '{' PRIVATE chestii_clasa PUBLIC chestii_clasa '}'  */
#line 1392 "yacc.y"
                                                                              {
                                                                                    AddNewClass((yyvsp[-6].strval));
                                                                                    if(ProgramError()){
                                                                                return -1;
                                                                                    } 
                                                                                 }
#line 3202 "y.tab.c"
    break;

  case 125: /* function_calls: ID '(' ')'  */
#line 1404 "yacc.y"
                           {
                         parameter_types_found[0]='\0';
                                nr_params=0;
                                char* type=check_if_in_use_function((yyvsp[-2].strval));
                                (yyval.strval)=type;
                                strcpy(typeofret, global_type);
                               // printf("%s\n", typeofret);
                                 strcpy(parameter_function_type,type);
                                // if(ProgramError()){
                                //     return -1;
                                // }
                                if(global_type_ready==1){
                                strcpy(global_type,type);
                                global_type_ready=0;
                                strcpy(returned_type_by_operation,type);
                                }
                                printf("THIS IS THE FUNCTION NAME %s ",(yyvsp[-2].strval)); //AICI AM FUNCTION NAME-UL CORECT
                                //in global_params voi avea tipurile ce vin din recursie
                                std::string tp;
                                std::ifstream ReadFunctions;
                                ReadFunctions.open("symbol_table_functions.txt");
                               // printf("THIS IS THE FUNCTION NAME %s \n",$1); //AICI AM FUNCTION NAME-UL CORECT
                                std::fflush(stdout);
                                while(getline(ReadFunctions, tp)) {
                                    
                                    char arr[tp.length() + 1]=""; 
	                                strcpy(arr, tp.c_str());
                                    //printf("%s \n", arr);
                                    char functie[200]="";
                                    strcpy(functie,"Function name:");
                                    strcat(functie,(yyvsp[-2].strval));
                                    strcat(functie," ");
                                    if(strstr(arr,functie)!=NULL){
                                        char rezultat[200] = "";
                                        char *p;
                                        char copie[200]="";
                                        strcpy(copie, arr);
                                        p = strtok(copie, "; ");
                                        
                                        while(p)
                                        {
                                            if(p[0] == '[' && (strchr("1234567890", p[1]) == NULL))
                                            strcat(rezultat, p);
                                            p = strtok(NULL, "; ");
                                        }
                                        int d=strlen(global_params);
                                        int d2=strlen(rezultat);
                                        //GLOBAL PARAMS MUST BE NULL HERE
                                        if(strcmp(global_params,rezultat)!=0 && strcmp(global_params,"")!=0){
                                             haveError = true;
                                             printf("Inputted params types: %s, actual types: %s",global_params,rezultat);
                                            strcpy(errorMessage, "Error: The parameters do not match with the function definition!");
                                            if(ProgramError()){
                                            return -1;
                                            }
                                        }    
                                    }
                                }
                                strcpy(parameter_types_found,"");
                                global_function[0]='\0';
                                global_params[0]='\0';
                              
                    }
#line 3270 "y.tab.c"
    break;

  case 126: /* function_calls: ID '(' list_parametri ')'  */
#line 1467 "yacc.y"
                                      {
                                parameter_types_found[0]='\0';
                                nr_params=0;
                                char* type=check_if_in_use_function((yyvsp[-3].strval));
                                (yyval.strval)=type;
                                strcpy(typeofret, global_type);
                               // printf("%s\n", );
                                strcpy(parameter_function_type,type);
                                // if(ProgramError()){
                                //     return -1;
                                // }
                                if(global_type_ready==1){
                                strcpy(global_type,type);
                                global_type_ready=0;
                                strcpy(returned_type_by_operation,type);
                                }
                                printf("THIS IS THE FUNCTION NAME %s ",(yyvsp[-3].strval)); //AICI AM FUNCTION NAME-UL CORECT
                                //in global_params voi avea tipurile ce vin din recursie
                                std::string tp;
                                std::ifstream ReadFunctions;
                                ReadFunctions.open("symbol_table_functions.txt");
                               // printf("THIS IS THE FUNCTION NAME %s \n",$1); //AICI AM FUNCTION NAME-UL CORECT
                                std::fflush(stdout);
                                while(getline(ReadFunctions, tp)) {
                                    
                                    char arr[tp.length() + 1]=""; 
	                                strcpy(arr, tp.c_str());
                                    //printf("%s \n", arr);
                                    char functie[200]="";
                                    strcpy(functie,"Function name:");
                                    strcat(functie,(yyvsp[-3].strval));
                                    strcat(functie," ");
                                    if(strstr(arr,functie)!=NULL){
                                        char rezultat[200] = "";
                                        char *p;
                                        char copie[200]="";
                                        strcpy(copie, arr);
                                        p = strtok(copie, "; ");
                                        
                                        while(p)
                                        {
                                            if(p[0] == '[' && (strchr("1234567890", p[1]) == NULL))
                                            strcat(rezultat, p);
                                            p = strtok(NULL, "; ");
                                        }
                                        int d=strlen(global_params);
                                        int d2=strlen(rezultat);
                                        
                                        if(strcmp(global_params,rezultat)!=0){
                                             haveError = true;
                                             printf("Inputted params types: %s, actual types: %s",global_params,rezultat);
                                            strcpy(errorMessage, "Error: The parameters do not match with the function definition!");
                                            if(ProgramError()){
                                            return -1;
                                            }
                                        }    
                                    }
                                }
                                strcpy(parameter_types_found,"");
                                global_function[0]='\0';
                                global_params[0]='\0';
                                  
                              }
#line 3338 "y.tab.c"
    break;

  case 127: /* list_parametri: parametru  */
#line 1531 "yacc.y"
                          {  strcpy((yyval.strval),global_params);printf(" Parameters %s\n", (yyval.strval));
                          }
#line 3345 "y.tab.c"
    break;

  case 128: /* list_parametri: parametru ',' list_parametri  */
#line 1533 "yacc.y"
                                            { strcpy((yyval.strval),global_params);printf("Parameters %s \n", (yyvsp[-2].strval));
              }
#line 3352 "y.tab.c"
    break;

  case 129: /* parametru: varop  */
#line 1536 "yacc.y"
                  {
            
            strcpy(parameter_types_found,parameter_function_type);
            //printf("THIS IS FUNCTION TYPE %s", parameter_types_found );
            strcat(global_params,parameter_types_found); //ce returneaza operatia
            }
#line 3363 "y.tab.c"
    break;


#line 3367 "y.tab.c"

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

#line 1543 "yacc.y"

int main(int argc, char** argv){
    init();
    yyin=fopen(argv[1], "r");
    yyparse();
}
