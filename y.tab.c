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
#line 1 "src/scanparse/parser.y"



#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "palm/memory.h"
#include "palm/ctinfo.h"
#include "palm/dbug.h"
#include "palm/str.h"
#include "ccngen/ast.h"
#include "ccngen/enum.h"
#include "global/globals.h"

static node_st *parseresult = NULL;
extern int yylex();
static int yyerror( char *errname);
extern FILE *yyin;
void AddLocToNode(node_st *node, void *begin_loc, void *end_loc);



#line 94 "y.tab.c"

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
    BRACKET_L = 258,               /* BRACKET_L  */
    BRACKET_R = 259,               /* BRACKET_R  */
    COMMA = 260,                   /* COMMA  */
    SEMICOLON = 261,               /* SEMICOLON  */
    CURLY_BRACKET_L = 262,         /* CURLY_BRACKET_L  */
    CURLY_BRACKET_R = 263,         /* CURLY_BRACKET_R  */
    MINUS = 264,                   /* MINUS  */
    PLUS = 265,                    /* PLUS  */
    STAR = 266,                    /* STAR  */
    SLASH = 267,                   /* SLASH  */
    PERCENT = 268,                 /* PERCENT  */
    LE = 269,                      /* LE  */
    LT = 270,                      /* LT  */
    GE = 271,                      /* GE  */
    GT = 272,                      /* GT  */
    EQ = 273,                      /* EQ  */
    NE = 274,                      /* NE  */
    OR = 275,                      /* OR  */
    AND = 276,                     /* AND  */
    TRUEVAL = 277,                 /* TRUEVAL  */
    FALSEVAL = 278,                /* FALSEVAL  */
    LET = 279,                     /* LET  */
    CAST = 280,                    /* CAST  */
    EXPRPREC = 281,                /* EXPRPREC  */
    FUNCALLPREC = 282,             /* FUNCALLPREC  */
    INTTYPE = 283,                 /* INTTYPE  */
    FLOATTYPE = 284,               /* FLOATTYPE  */
    BOOLTYPE = 285,                /* BOOLTYPE  */
    VOIDTYPE = 286,                /* VOIDTYPE  */
    NEG = 287,                     /* NEG  */
    IF = 288,                      /* IF  */
    ELSE = 289,                    /* ELSE  */
    WHILE = 290,                   /* WHILE  */
    FOR = 291,                     /* FOR  */
    RETURNTOKEN = 292,             /* RETURNTOKEN  */
    EXPORT = 293,                  /* EXPORT  */
    EXTERN = 294,                  /* EXTERN  */
    FORTOKEN = 295,                /* FORTOKEN  */
    DOTOKEN = 296,                 /* DOTOKEN  */
    NUM = 297,                     /* NUM  */
    FLOAT = 298,                   /* FLOAT  */
    ID = 299,                      /* ID  */
    NEGPREC = 300,                 /* NEGPREC  */
    THEN = 301                     /* THEN  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define BRACKET_L 258
#define BRACKET_R 259
#define COMMA 260
#define SEMICOLON 261
#define CURLY_BRACKET_L 262
#define CURLY_BRACKET_R 263
#define MINUS 264
#define PLUS 265
#define STAR 266
#define SLASH 267
#define PERCENT 268
#define LE 269
#define LT 270
#define GE 271
#define GT 272
#define EQ 273
#define NE 274
#define OR 275
#define AND 276
#define TRUEVAL 277
#define FALSEVAL 278
#define LET 279
#define CAST 280
#define EXPRPREC 281
#define FUNCALLPREC 282
#define INTTYPE 283
#define FLOATTYPE 284
#define BOOLTYPE 285
#define VOIDTYPE 286
#define NEG 287
#define IF 288
#define ELSE 289
#define WHILE 290
#define FOR 291
#define RETURNTOKEN 292
#define EXPORT 293
#define EXTERN 294
#define FORTOKEN 295
#define DOTOKEN 296
#define NUM 297
#define FLOAT 298
#define ID 299
#define NEGPREC 300
#define THEN 301

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 24 "src/scanparse/parser.y"

 char               *id;
 int                 cint;
 float               cflt;
 enum binop_type     cbinop;
 node_st             *node;
 enum Types          ctypes;
 enum MonOpEnum      cmonops;

#line 246 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;

int yyparse (void);



/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_BRACKET_L = 3,                  /* BRACKET_L  */
  YYSYMBOL_BRACKET_R = 4,                  /* BRACKET_R  */
  YYSYMBOL_COMMA = 5,                      /* COMMA  */
  YYSYMBOL_SEMICOLON = 6,                  /* SEMICOLON  */
  YYSYMBOL_CURLY_BRACKET_L = 7,            /* CURLY_BRACKET_L  */
  YYSYMBOL_CURLY_BRACKET_R = 8,            /* CURLY_BRACKET_R  */
  YYSYMBOL_MINUS = 9,                      /* MINUS  */
  YYSYMBOL_PLUS = 10,                      /* PLUS  */
  YYSYMBOL_STAR = 11,                      /* STAR  */
  YYSYMBOL_SLASH = 12,                     /* SLASH  */
  YYSYMBOL_PERCENT = 13,                   /* PERCENT  */
  YYSYMBOL_LE = 14,                        /* LE  */
  YYSYMBOL_LT = 15,                        /* LT  */
  YYSYMBOL_GE = 16,                        /* GE  */
  YYSYMBOL_GT = 17,                        /* GT  */
  YYSYMBOL_EQ = 18,                        /* EQ  */
  YYSYMBOL_NE = 19,                        /* NE  */
  YYSYMBOL_OR = 20,                        /* OR  */
  YYSYMBOL_AND = 21,                       /* AND  */
  YYSYMBOL_TRUEVAL = 22,                   /* TRUEVAL  */
  YYSYMBOL_FALSEVAL = 23,                  /* FALSEVAL  */
  YYSYMBOL_LET = 24,                       /* LET  */
  YYSYMBOL_CAST = 25,                      /* CAST  */
  YYSYMBOL_EXPRPREC = 26,                  /* EXPRPREC  */
  YYSYMBOL_FUNCALLPREC = 27,               /* FUNCALLPREC  */
  YYSYMBOL_INTTYPE = 28,                   /* INTTYPE  */
  YYSYMBOL_FLOATTYPE = 29,                 /* FLOATTYPE  */
  YYSYMBOL_BOOLTYPE = 30,                  /* BOOLTYPE  */
  YYSYMBOL_VOIDTYPE = 31,                  /* VOIDTYPE  */
  YYSYMBOL_NEG = 32,                       /* NEG  */
  YYSYMBOL_IF = 33,                        /* IF  */
  YYSYMBOL_ELSE = 34,                      /* ELSE  */
  YYSYMBOL_WHILE = 35,                     /* WHILE  */
  YYSYMBOL_FOR = 36,                       /* FOR  */
  YYSYMBOL_RETURNTOKEN = 37,               /* RETURNTOKEN  */
  YYSYMBOL_EXPORT = 38,                    /* EXPORT  */
  YYSYMBOL_EXTERN = 39,                    /* EXTERN  */
  YYSYMBOL_FORTOKEN = 40,                  /* FORTOKEN  */
  YYSYMBOL_DOTOKEN = 41,                   /* DOTOKEN  */
  YYSYMBOL_NUM = 42,                       /* NUM  */
  YYSYMBOL_FLOAT = 43,                     /* FLOAT  */
  YYSYMBOL_ID = 44,                        /* ID  */
  YYSYMBOL_NEGPREC = 45,                   /* NEGPREC  */
  YYSYMBOL_THEN = 46,                      /* THEN  */
  YYSYMBOL_YYACCEPT = 47,                  /* $accept  */
  YYSYMBOL_program = 48,                   /* program  */
  YYSYMBOL_decls = 49,                     /* decls  */
  YYSYMBOL_decl = 50,                      /* decl  */
  YYSYMBOL_fundef = 51,                    /* fundef  */
  YYSYMBOL_funbody = 52,                   /* funbody  */
  YYSYMBOL_vardecl = 53,                   /* vardecl  */
  YYSYMBOL_params = 54,                    /* params  */
  YYSYMBOL_globdef = 55,                   /* globdef  */
  YYSYMBOL_globdecl = 56,                  /* globdecl  */
  YYSYMBOL_stmts = 57,                     /* stmts  */
  YYSYMBOL_stmt = 58,                      /* stmt  */
  YYSYMBOL_ifelse = 59,                    /* ifelse  */
  YYSYMBOL_assign = 60,                    /* assign  */
  YYSYMBOL_while = 61,                     /* while  */
  YYSYMBOL_for = 62,                       /* for  */
  YYSYMBOL_dowhile = 63,                   /* dowhile  */
  YYSYMBOL_return = 64,                    /* return  */
  YYSYMBOL_block = 65,                     /* block  */
  YYSYMBOL_varlet = 66,                    /* varlet  */
  YYSYMBOL_expr = 67,                      /* expr  */
  YYSYMBOL_exprs = 68,                     /* exprs  */
  YYSYMBOL_constant = 69,                  /* constant  */
  YYSYMBOL_floatval = 70,                  /* floatval  */
  YYSYMBOL_intval = 71,                    /* intval  */
  YYSYMBOL_boolval = 72,                   /* boolval  */
  YYSYMBOL_types = 73                      /* types  */
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
#define YYFINAL  16
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   592

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  89
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  193

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   301


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
      45,    46
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    70,    70,    76,    80,    86,    90,    94,   100,   104,
     108,   112,   116,   120,   127,   130,   135,   139,   146,   150,
     154,   158,   165,   169,   175,   180,   184,   189,   195,   201,
     205,   211,   215,   219,   223,   227,   231,   235,   241,   245,
     249,   253,   257,   262,   268,   274,   278,   282,   286,   292,
     296,   301,   305,   310,   314,   321,   329,   333,   337,   342,
     347,   352,   357,   362,   367,   372,   377,   382,   387,   392,
     397,   402,   406,   410,   414,   418,   422,   429,   433,   439,
     443,   447,   453,   459,   465,   469,   475,   479,   483,   487
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
  "\"end of file\"", "error", "\"invalid token\"", "BRACKET_L",
  "BRACKET_R", "COMMA", "SEMICOLON", "CURLY_BRACKET_L", "CURLY_BRACKET_R",
  "MINUS", "PLUS", "STAR", "SLASH", "PERCENT", "LE", "LT", "GE", "GT",
  "EQ", "NE", "OR", "AND", "TRUEVAL", "FALSEVAL", "LET", "CAST",
  "EXPRPREC", "FUNCALLPREC", "INTTYPE", "FLOATTYPE", "BOOLTYPE",
  "VOIDTYPE", "NEG", "IF", "ELSE", "WHILE", "FOR", "RETURNTOKEN", "EXPORT",
  "EXTERN", "FORTOKEN", "DOTOKEN", "NUM", "FLOAT", "ID", "NEGPREC", "THEN",
  "$accept", "program", "decls", "decl", "fundef", "funbody", "vardecl",
  "params", "globdef", "globdecl", "stmts", "stmt", "ifelse", "assign",
  "while", "for", "dowhile", "return", "block", "varlet", "expr", "exprs",
  "constant", "floatval", "intval", "boolval", "types", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-143)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-56)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -13,  -143,  -143,  -143,  -143,    38,    38,    19,  -143,   -13,
    -143,  -143,  -143,   -21,   -15,    -9,  -143,  -143,    48,   142,
      18,     2,  -143,   249,    59,  -143,   249,   204,  -143,    43,
      51,    13,   162,   249,  -143,  -143,   249,  -143,  -143,    57,
     458,  -143,  -143,  -143,  -143,    54,    67,   474,    69,    75,
      89,    66,    77,   318,    82,  -143,  -143,    61,  -143,   249,
     249,   249,   249,   249,   249,   249,   249,   249,   249,   249,
     249,   249,    89,    84,  -143,  -143,    93,    92,    98,   264,
      99,   137,    -2,   100,   222,  -143,   222,  -143,  -143,  -143,
    -143,  -143,  -143,    86,   490,    62,    89,    38,  -143,   249,
    -143,   425,   111,   140,   140,  -143,  -143,  -143,   186,   186,
     186,   186,   575,   575,   551,   564,   108,    89,  -143,   249,
     249,  -143,   506,    38,   179,    88,    90,  -143,  -143,  -143,
     249,  -143,    -4,   120,  -143,  -143,   249,  -143,  -143,   126,
     336,   354,  -143,    95,  -143,   133,   139,   144,   522,    38,
     249,  -143,  -143,  -143,   137,   148,   125,  -143,   249,   249,
    -143,  -143,   538,   123,   124,  -143,   249,   372,   390,    38,
     206,   148,   442,   155,   156,  -143,   222,  -143,  -143,   249,
    -143,  -143,   159,   300,  -143,   137,   249,  -143,  -143,   408,
     137,  -143,  -143
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    86,    87,    88,    89,     0,     0,     0,     2,     4,
       7,     6,     5,     0,     0,     0,     1,     3,     0,     0,
       0,     0,    24,     0,     0,    25,     0,     0,    28,     0,
       0,     0,     0,     0,    84,    85,     0,    83,    82,    57,
       0,    56,    79,    80,    81,     0,     0,     0,     0,     0,
      14,     0,    23,     0,     0,    71,    72,     0,    26,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    14,     0,    27,     8,     0,     0,     0,     0,
       0,     0,    57,     0,    15,    17,    30,    36,    31,    32,
      33,    34,    35,     0,     0,     0,    14,     0,    73,     0,
      76,    78,     0,    59,    58,    60,    61,    63,    66,    64,
      67,    65,    62,    69,    68,    70,     0,    14,     9,     0,
       0,    52,     0,     0,     0,     0,     0,    12,    16,    29,
       0,    37,     0,     0,    22,    74,     0,    75,    10,     0,
       0,     0,    51,     0,    54,     0,     0,     0,     0,    19,
       0,    13,    77,    11,     0,     0,     0,    53,     0,     0,
      43,    18,     0,    40,    41,    44,     0,     0,     0,    21,
       0,     0,     0,     0,     0,    20,     0,    39,    42,     0,
      49,    50,     0,     0,    38,     0,     0,    46,    47,     0,
       0,    45,    48
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -143,  -143,   166,  -143,  -143,   -68,  -142,   -16,  -143,  -143,
     -72,   -76,  -143,  -143,  -143,  -143,  -143,  -143,   -17,  -143,
     -23,    28,  -143,  -143,  -143,  -143,    53
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     7,     8,     9,    10,    83,    84,    30,    11,    12,
      85,    86,    87,    88,    89,    90,    91,    92,   126,    93,
      94,   102,    41,    42,    43,    44,    95
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      40,    57,   149,    47,   116,   125,    29,   161,    46,    53,
      55,    49,   128,    56,   129,     1,     2,     3,     4,    16,
     150,    27,   -55,    18,    28,     5,     6,   175,   133,    19,
       1,     2,     3,     4,   101,    20,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   139,
      50,    21,   145,    13,    22,    51,   122,    52,    14,    15,
      57,    72,    13,    45,    32,   100,     1,     2,     3,     4,
      33,    73,    23,    96,    31,    75,   135,    31,   163,    76,
      31,   134,    97,    34,    35,    54,    99,     1,     2,     3,
       4,   117,    32,    36,   177,   119,   140,   141,    33,   118,
     182,   120,   123,    37,    38,    39,   132,   148,   127,   187,
     130,    34,    35,   101,   191,   137,   138,     1,     2,     3,
       4,    36,    77,   146,    78,   147,    79,   162,   151,    80,
      81,    37,    38,    82,   153,   167,   168,   164,   165,   156,
      32,   157,   158,   172,   124,    24,    33,   159,    25,   166,
      31,    61,    62,    63,   178,   124,   183,   170,   171,    34,
      35,   180,   181,   189,   152,    32,    26,   184,   188,    36,
      77,    33,    78,   192,    79,    17,   143,    80,    81,    37,
      38,    82,    32,     0,    34,    35,     0,   144,    33,     0,
       1,     2,     3,     4,    36,    59,    60,    61,    62,    63,
       0,    34,    35,     0,    37,    38,    39,     0,    48,    32,
       0,    36,    77,   176,    78,    33,    79,     0,     0,    80,
      81,    37,    38,    82,     0,    32,     0,     0,    34,    35,
       0,    33,     1,     2,     3,     4,     0,     0,    36,    77,
       0,    78,     0,    79,    34,    35,    80,    81,    37,    38,
      82,     0,    32,     0,    36,    77,     0,    78,    33,    79,
       0,     0,    80,    81,    37,    38,    82,    32,     0,     0,
     121,    34,    35,    33,     0,     0,     0,     0,     0,     0,
       0,    36,     0,     0,     0,     0,    34,    35,     0,     0,
       0,    37,    38,    39,     0,     0,    36,     0,     0,     0,
       0,     0,     0,     0,   185,   186,    37,    38,    39,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    98,     0,     0,     0,     0,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
     154,     0,     0,     0,     0,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,   155,     0,
       0,     0,     0,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,   173,     0,     0,     0,
       0,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,   174,     0,     0,     0,     0,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,   190,     0,     0,     0,     0,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
     136,     0,     0,     0,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,   179,     0,     0,
       0,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    58,     0,     0,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      74,     0,     0,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,   131,     0,     0,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,   142,     0,     0,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,   160,     0,
       0,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,   169,     0,     0,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,     0,    71,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    59,    60,    61,    62,    63,    64,
      65,    66,    67
};

static const yytype_int16 yycheck[] =
{
      23,     3,     6,    26,    72,    81,     4,   149,    24,    32,
      33,    27,    84,    36,    86,    28,    29,    30,    31,     0,
      24,     3,    24,    44,     6,    38,    39,   169,    96,    44,
      28,    29,    30,    31,    57,    44,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,   117,
       7,     3,   124,     0,     6,     4,    79,    44,     5,     6,
       3,     7,     9,     4,     3,     4,    28,    29,    30,    31,
       9,     4,    24,     7,    21,     6,    99,    24,   154,     4,
      27,    97,     5,    22,    23,    32,     4,    28,    29,    30,
      31,     7,     3,    32,   170,     3,   119,   120,     9,     6,
     176,     3,     3,    42,    43,    44,    44,   130,     8,   185,
      24,    22,    23,   136,   190,     4,     8,    28,    29,    30,
      31,    32,    33,    35,    35,    35,    37,   150,     8,    40,
      41,    42,    43,    44,     8,   158,   159,   154,   155,    44,
       3,     8,     3,   166,     7,     3,     9,     3,     6,    24,
      97,    11,    12,    13,   171,     7,   179,    34,    34,    22,
      23,     6,     6,   186,   136,     3,    24,     8,   185,    32,
      33,     9,    35,   190,    37,     9,   123,    40,    41,    42,
      43,    44,     3,    -1,    22,    23,    -1,     8,     9,    -1,
      28,    29,    30,    31,    32,     9,    10,    11,    12,    13,
      -1,    22,    23,    -1,    42,    43,    44,    -1,     4,     3,
      -1,    32,    33,     7,    35,     9,    37,    -1,    -1,    40,
      41,    42,    43,    44,    -1,     3,    -1,    -1,    22,    23,
      -1,     9,    28,    29,    30,    31,    -1,    -1,    32,    33,
      -1,    35,    -1,    37,    22,    23,    40,    41,    42,    43,
      44,    -1,     3,    -1,    32,    33,    -1,    35,     9,    37,
      -1,    -1,    40,    41,    42,    43,    44,     3,    -1,    -1,
       6,    22,    23,     9,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    32,    -1,    -1,    -1,    -1,    22,    23,    -1,    -1,
      -1,    42,    43,    44,    -1,    -1,    32,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     4,     5,    42,    43,    44,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,     4,    -1,    -1,    -1,    -1,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
       4,    -1,    -1,    -1,    -1,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,     4,    -1,
      -1,    -1,    -1,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,     4,    -1,    -1,    -1,
      -1,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,     4,    -1,    -1,    -1,    -1,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,     4,    -1,    -1,    -1,    -1,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
       5,    -1,    -1,    -1,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,     5,    -1,    -1,
      -1,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,     6,    -1,    -1,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
       6,    -1,    -1,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,     6,    -1,    -1,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,     6,    -1,    -1,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,     6,    -1,
      -1,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,     6,    -1,    -1,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    -1,    21,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,     9,    10,    11,    12,    13,    14,
      15,    16,    17
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    28,    29,    30,    31,    38,    39,    48,    49,    50,
      51,    55,    56,    73,    73,    73,     0,    49,    44,    44,
      44,     3,     6,    24,     3,     6,    24,     3,     6,     4,
      54,    73,     3,     9,    22,    23,    32,    42,    43,    44,
      67,    69,    70,    71,    72,     4,    54,    67,     4,    54,
       7,     4,    44,    67,    73,    67,    67,     3,     6,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,     7,     4,     6,     6,     4,    33,    35,    37,
      40,    41,    44,    52,    53,    57,    58,    59,    60,    61,
      62,    63,    64,    66,    67,    73,     7,     5,     4,     4,
       4,    67,    68,    67,    67,    67,    67,    67,    67,    67,
      67,    67,    67,    67,    67,    67,    52,     7,     6,     3,
       3,     6,    67,     3,     7,    58,    65,     8,    57,    57,
      24,     6,    44,    52,    54,    67,     5,     4,     8,    52,
      67,    67,     6,    73,     8,    57,    35,    35,    67,     6,
      24,     8,    68,     8,     4,     4,    44,     8,     3,     3,
       6,    53,    67,    58,    65,    65,    24,    67,    67,     6,
      34,    34,    67,     4,     4,    53,     7,    58,    65,     5,
       6,     6,    58,    67,     8,     4,     5,    58,    65,    67,
       4,    58,    65
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    47,    48,    49,    49,    50,    50,    50,    51,    51,
      51,    51,    51,    51,    52,    52,    52,    52,    53,    53,
      53,    53,    54,    54,    55,    55,    55,    55,    56,    57,
      57,    58,    58,    58,    58,    58,    58,    58,    59,    59,
      59,    59,    59,    60,    61,    62,    62,    62,    62,    63,
      63,    64,    64,    65,    65,    66,    67,    67,    67,    67,
      67,    67,    67,    67,    67,    67,    67,    67,    67,    67,
      67,    67,    67,    67,    67,    67,    67,    68,    68,    69,
      69,    69,    70,    71,    72,    72,    73,    73,    73,    73
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     6,     7,
       8,     9,     7,     8,     0,     1,     2,     1,     4,     3,
       6,     5,     4,     2,     3,     4,     5,     6,     4,     2,
       1,     1,     1,     1,     1,     1,     1,     2,     9,     7,
       5,     5,     7,     4,     5,    12,    10,    10,    12,     7,
       7,     3,     2,     3,     2,     1,     1,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     2,     2,     3,     4,     4,     3,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1
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
  case 2: /* program: decls  */
#line 71 "src/scanparse/parser.y"
         {
           parseresult = ASTprogram((yyvsp[0].node));
         }
#line 1633 "y.tab.c"
    break;

  case 3: /* decls: decl decls  */
#line 77 "src/scanparse/parser.y"
       {
         (yyval.node) = ASTdecls((yyvsp[-1].node), (yyvsp[0].node));
       }
#line 1641 "y.tab.c"
    break;

  case 4: /* decls: decl  */
#line 81 "src/scanparse/parser.y"
       {
         (yyval.node) = ASTdecls((yyvsp[0].node), NULL);
       }
#line 1649 "y.tab.c"
    break;

  case 5: /* decl: globdecl  */
#line 87 "src/scanparse/parser.y"
      {
        (yyval.node) = (yyvsp[0].node);
      }
#line 1657 "y.tab.c"
    break;

  case 6: /* decl: globdef  */
#line 91 "src/scanparse/parser.y"
      {
        (yyval.node) = (yyvsp[0].node);
      }
#line 1665 "y.tab.c"
    break;

  case 7: /* decl: fundef  */
#line 95 "src/scanparse/parser.y"
      {
        (yyval.node) = (yyvsp[0].node);
      }
#line 1673 "y.tab.c"
    break;

  case 8: /* fundef: EXTERN types ID BRACKET_L BRACKET_R SEMICOLON  */
#line 101 "src/scanparse/parser.y"
         {
           (yyval.node) = ASTfundef(NULL, NULL, (yyvsp[-4].ctypes), (yyvsp[-3].id), false);
         }
#line 1681 "y.tab.c"
    break;

  case 9: /* fundef: EXTERN types ID BRACKET_L params BRACKET_R SEMICOLON  */
#line 105 "src/scanparse/parser.y"
         {
           (yyval.node) = ASTfundef(NULL, (yyvsp[-2].node), (yyvsp[-5].ctypes), (yyvsp[-4].id), false);
         }
#line 1689 "y.tab.c"
    break;

  case 10: /* fundef: EXPORT types ID BRACKET_L BRACKET_R CURLY_BRACKET_L funbody CURLY_BRACKET_R  */
#line 109 "src/scanparse/parser.y"
         {
           (yyval.node) = ASTfundef((yyvsp[-1].node), NULL, (yyvsp[-6].ctypes), (yyvsp[-5].id), true);
         }
#line 1697 "y.tab.c"
    break;

  case 11: /* fundef: EXPORT types ID BRACKET_L params BRACKET_R CURLY_BRACKET_L funbody CURLY_BRACKET_R  */
#line 113 "src/scanparse/parser.y"
         {
           (yyval.node) = ASTfundef((yyvsp[-1].node), (yyvsp[-4].node), (yyvsp[-7].ctypes), (yyvsp[-6].id), true);
         }
#line 1705 "y.tab.c"
    break;

  case 12: /* fundef: types ID BRACKET_L BRACKET_R CURLY_BRACKET_L funbody CURLY_BRACKET_R  */
#line 117 "src/scanparse/parser.y"
         {
           (yyval.node) = ASTfundef((yyvsp[-1].node), NULL, (yyvsp[-6].ctypes), (yyvsp[-5].id), false);
         }
#line 1713 "y.tab.c"
    break;

  case 13: /* fundef: types ID BRACKET_L params BRACKET_R CURLY_BRACKET_L funbody CURLY_BRACKET_R  */
#line 121 "src/scanparse/parser.y"
         {
           (yyval.node) = ASTfundef((yyvsp[-1].node), (yyvsp[-4].node), (yyvsp[-7].ctypes), (yyvsp[-6].id), false);
         }
#line 1721 "y.tab.c"
    break;

  case 14: /* funbody: %empty  */
#line 127 "src/scanparse/parser.y"
         {
           (yyval.node) = ASTfunbody(NULL, NULL);
         }
#line 1729 "y.tab.c"
    break;

  case 15: /* funbody: vardecl  */
#line 131 "src/scanparse/parser.y"
          {
            (yyval.node) = ASTfunbody((yyvsp[0].node), NULL);

          }
#line 1738 "y.tab.c"
    break;

  case 16: /* funbody: vardecl stmts  */
#line 136 "src/scanparse/parser.y"
          {
            (yyval.node) = ASTfunbody((yyvsp[-1].node), (yyvsp[0].node));
          }
#line 1746 "y.tab.c"
    break;

  case 17: /* funbody: stmts  */
#line 140 "src/scanparse/parser.y"
         {
           (yyval.node) = ASTfunbody(NULL, (yyvsp[0].node));
         }
#line 1754 "y.tab.c"
    break;

  case 18: /* vardecl: types ID SEMICOLON vardecl  */
#line 147 "src/scanparse/parser.y"
          {
            (yyval.node) = ASTvardecl(NULL, (yyvsp[0].node), (yyvsp[-2].id), (yyvsp[-3].ctypes));
          }
#line 1762 "y.tab.c"
    break;

  case 19: /* vardecl: types ID SEMICOLON  */
#line 151 "src/scanparse/parser.y"
          {
            (yyval.node) = ASTvardecl(NULL, NULL, (yyvsp[-1].id), (yyvsp[-2].ctypes));
          }
#line 1770 "y.tab.c"
    break;

  case 20: /* vardecl: types ID LET expr SEMICOLON vardecl  */
#line 155 "src/scanparse/parser.y"
          {
            (yyval.node) = ASTvardecl((yyvsp[-2].node), (yyvsp[0].node), (yyvsp[-4].id), (yyvsp[-5].ctypes));
          }
#line 1778 "y.tab.c"
    break;

  case 21: /* vardecl: types ID LET expr SEMICOLON  */
#line 159 "src/scanparse/parser.y"
          {
            (yyval.node) = ASTvardecl((yyvsp[-1].node), NULL, (yyvsp[-3].id), (yyvsp[-4].ctypes));
          }
#line 1786 "y.tab.c"
    break;

  case 22: /* params: types ID COMMA params  */
#line 166 "src/scanparse/parser.y"
        {
          (yyval.node) = ASTparam((yyvsp[0].node), (yyvsp[-2].id), (yyvsp[-3].ctypes));
        }
#line 1794 "y.tab.c"
    break;

  case 23: /* params: types ID  */
#line 170 "src/scanparse/parser.y"
        {
          (yyval.node) = ASTparam(NULL, (yyvsp[0].id), (yyvsp[-1].ctypes));
        }
#line 1802 "y.tab.c"
    break;

  case 24: /* globdef: types ID SEMICOLON  */
#line 176 "src/scanparse/parser.y"
           {
             (yyval.node) = ASTglobdef(NULL, (yyvsp[-2].ctypes), (yyvsp[-1].id), false);
           }
#line 1810 "y.tab.c"
    break;

  case 25: /* globdef: EXPORT types ID SEMICOLON  */
#line 181 "src/scanparse/parser.y"
           {
             (yyval.node) = ASTglobdef(NULL, (yyvsp[-2].ctypes), (yyvsp[-1].id), true);;
           }
#line 1818 "y.tab.c"
    break;

  case 26: /* globdef: types ID LET expr SEMICOLON  */
#line 185 "src/scanparse/parser.y"
           {
             (yyval.node) = ASTglobdef((yyvsp[-1].node), (yyvsp[-4].ctypes), (yyvsp[-3].id), false);
           }
#line 1826 "y.tab.c"
    break;

  case 27: /* globdef: EXPORT types ID LET expr SEMICOLON  */
#line 190 "src/scanparse/parser.y"
           {
             (yyval.node) = ASTglobdef((yyvsp[-1].node), (yyvsp[-4].ctypes), (yyvsp[-3].id), true);;
           }
#line 1834 "y.tab.c"
    break;

  case 28: /* globdecl: EXTERN types ID SEMICOLON  */
#line 196 "src/scanparse/parser.y"
           {
             (yyval.node) = ASTglobdecl(NULL, (yyvsp[-2].ctypes), (yyvsp[-1].id));
           }
#line 1842 "y.tab.c"
    break;

  case 29: /* stmts: stmt stmts  */
#line 202 "src/scanparse/parser.y"
        {
          (yyval.node) = ASTstmts((yyvsp[-1].node), (yyvsp[0].node));
        }
#line 1850 "y.tab.c"
    break;

  case 30: /* stmts: stmt  */
#line 206 "src/scanparse/parser.y"
        {
          (yyval.node) = ASTstmts((yyvsp[0].node), NULL);
        }
#line 1858 "y.tab.c"
    break;

  case 31: /* stmt: assign  */
#line 212 "src/scanparse/parser.y"
       {
         (yyval.node) = (yyvsp[0].node);
       }
#line 1866 "y.tab.c"
    break;

  case 32: /* stmt: while  */
#line 216 "src/scanparse/parser.y"
        {
          (yyval.node) = (yyvsp[0].node);
        }
#line 1874 "y.tab.c"
    break;

  case 33: /* stmt: for  */
#line 220 "src/scanparse/parser.y"
        {
          (yyval.node) = (yyvsp[0].node);
        }
#line 1882 "y.tab.c"
    break;

  case 34: /* stmt: dowhile  */
#line 224 "src/scanparse/parser.y"
        {
          (yyval.node) = (yyvsp[0].node); 
        }
#line 1890 "y.tab.c"
    break;

  case 35: /* stmt: return  */
#line 228 "src/scanparse/parser.y"
        {
          (yyval.node) = (yyvsp[0].node); 
        }
#line 1898 "y.tab.c"
    break;

  case 36: /* stmt: ifelse  */
#line 232 "src/scanparse/parser.y"
        {
          (yyval.node) = (yyvsp[0].node);    
        }
#line 1906 "y.tab.c"
    break;

  case 37: /* stmt: expr SEMICOLON  */
#line 236 "src/scanparse/parser.y"
        {
          (yyval.node) = ASTexprstmt((yyvsp[-1].node)); 
        }
#line 1914 "y.tab.c"
    break;

  case 38: /* ifelse: IF BRACKET_L expr BRACKET_R stmt ELSE CURLY_BRACKET_L stmt CURLY_BRACKET_R  */
#line 242 "src/scanparse/parser.y"
        {
          (yyval.node) = ASTifelse((yyvsp[-6].node), ASTstmts((yyvsp[-4].node), NULL), (yyvsp[-1].node));
        }
#line 1922 "y.tab.c"
    break;

  case 39: /* ifelse: IF BRACKET_L expr BRACKET_R stmt ELSE stmt  */
#line 246 "src/scanparse/parser.y"
        {
          (yyval.node) = ASTifelse((yyvsp[-4].node), ASTstmts((yyvsp[-2].node), NULL), (yyvsp[0].node));
        }
#line 1930 "y.tab.c"
    break;

  case 40: /* ifelse: IF BRACKET_L expr BRACKET_R stmt  */
#line 250 "src/scanparse/parser.y"
        {
          (yyval.node) = ASTifelse((yyvsp[-2].node), ASTstmts((yyvsp[0].node), NULL), NULL);
        }
#line 1938 "y.tab.c"
    break;

  case 41: /* ifelse: IF BRACKET_L expr BRACKET_R block  */
#line 254 "src/scanparse/parser.y"
        {
          (yyval.node) = ASTifelse((yyvsp[-2].node), (yyvsp[0].node), NULL);
        }
#line 1946 "y.tab.c"
    break;

  case 42: /* ifelse: IF BRACKET_L expr BRACKET_R block ELSE block  */
#line 258 "src/scanparse/parser.y"
        {
          (yyval.node) = ASTifelse((yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node));
        }
#line 1954 "y.tab.c"
    break;

  case 43: /* assign: varlet LET expr SEMICOLON  */
#line 263 "src/scanparse/parser.y"
        {
          (yyval.node) = ASTassign((yyvsp[-3].node), (yyvsp[-1].node));
        }
#line 1962 "y.tab.c"
    break;

  case 44: /* while: WHILE BRACKET_L expr BRACKET_R block  */
#line 269 "src/scanparse/parser.y"
      {
        (yyval.node) = ASTwhile((yyvsp[-2].node), (yyvsp[0].node));
      }
#line 1970 "y.tab.c"
    break;

  case 45: /* for: FORTOKEN BRACKET_L types ID LET expr COMMA expr COMMA expr BRACKET_R stmt  */
#line 275 "src/scanparse/parser.y"
    {
      (yyval.node) = ASTfor((yyvsp[-6].node), (yyvsp[-4].node), (yyvsp[-2].node), ASTstmts((yyvsp[0].node), NULL), (yyvsp[-8].id));
    }
#line 1978 "y.tab.c"
    break;

  case 46: /* for: FORTOKEN BRACKET_L types ID LET expr COMMA expr BRACKET_R stmt  */
#line 279 "src/scanparse/parser.y"
    {
      (yyval.node) = ASTfor((yyvsp[-4].node), (yyvsp[-2].node), NULL, ASTstmts((yyvsp[0].node), NULL), (yyvsp[-6].id));
    }
#line 1986 "y.tab.c"
    break;

  case 47: /* for: FORTOKEN BRACKET_L types ID LET expr COMMA expr BRACKET_R block  */
#line 283 "src/scanparse/parser.y"
      {
        (yyval.node) = ASTfor((yyvsp[-4].node), (yyvsp[-2].node), NULL, (yyvsp[0].node), (yyvsp[-6].id));
      }
#line 1994 "y.tab.c"
    break;

  case 48: /* for: FORTOKEN BRACKET_L types ID LET expr COMMA expr COMMA expr BRACKET_R block  */
#line 287 "src/scanparse/parser.y"
      {
        (yyval.node) = ASTfor((yyvsp[-6].node), (yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node), (yyvsp[-8].id));
      }
#line 2002 "y.tab.c"
    break;

  case 49: /* dowhile: DOTOKEN stmt WHILE BRACKET_L expr BRACKET_R SEMICOLON  */
#line 293 "src/scanparse/parser.y"
      {
        (yyval.node) = ASTdowhile((yyvsp[-2].node), ASTstmts((yyvsp[-5].node), NULL));
      }
#line 2010 "y.tab.c"
    break;

  case 50: /* dowhile: DOTOKEN block WHILE BRACKET_L expr BRACKET_R SEMICOLON  */
#line 297 "src/scanparse/parser.y"
      {
        (yyval.node) = ASTdowhile((yyvsp[-2].node), (yyvsp[-5].node));        
      }
#line 2018 "y.tab.c"
    break;

  case 51: /* return: RETURNTOKEN expr SEMICOLON  */
#line 302 "src/scanparse/parser.y"
      {
        (yyval.node) = ASTreturn((yyvsp[-1].node));
      }
#line 2026 "y.tab.c"
    break;

  case 52: /* return: RETURNTOKEN SEMICOLON  */
#line 306 "src/scanparse/parser.y"
      {
        (yyval.node) = ASTreturn(NULL);
      }
#line 2034 "y.tab.c"
    break;

  case 53: /* block: CURLY_BRACKET_L stmts CURLY_BRACKET_R  */
#line 311 "src/scanparse/parser.y"
      {
        (yyval.node) = (yyvsp[-1].node);
      }
#line 2042 "y.tab.c"
    break;

  case 54: /* block: CURLY_BRACKET_L CURLY_BRACKET_R  */
#line 315 "src/scanparse/parser.y"
      {
        (yyval.node) = NULL; 
      }
#line 2050 "y.tab.c"
    break;

  case 55: /* varlet: ID  */
#line 322 "src/scanparse/parser.y"
        {
          (yyval.node) = ASTvarlet((yyvsp[0].id), NULL);
          AddLocToNode((yyval.node), &(yylsp[0]), &(yylsp[0]));
        }
#line 2059 "y.tab.c"
    break;

  case 56: /* expr: constant  */
#line 330 "src/scanparse/parser.y"
      {
        (yyval.node) = (yyvsp[0].node);
      }
#line 2067 "y.tab.c"
    break;

  case 57: /* expr: ID  */
#line 334 "src/scanparse/parser.y"
      {
        (yyval.node) = ASTvar((yyvsp[0].id));
      }
#line 2075 "y.tab.c"
    break;

  case 58: /* expr: expr PLUS expr  */
#line 338 "src/scanparse/parser.y"
      {
        (yyval.node) = ASTbinop((yyvsp[-2].node), (yyvsp[0].node), BO_add);
        AddLocToNode((yyval.node), &(yylsp[-2]), &(yylsp[0]));
      }
#line 2084 "y.tab.c"
    break;

  case 59: /* expr: expr MINUS expr  */
#line 343 "src/scanparse/parser.y"
      {
        (yyval.node) = ASTbinop((yyvsp[-2].node), (yyvsp[0].node), BO_sub);
        AddLocToNode((yyval.node), &(yylsp[-2]), &(yylsp[0]));
      }
#line 2093 "y.tab.c"
    break;

  case 60: /* expr: expr STAR expr  */
#line 348 "src/scanparse/parser.y"
      {
        (yyval.node) = ASTbinop((yyvsp[-2].node), (yyvsp[0].node), BO_mul);
        AddLocToNode((yyval.node), &(yylsp[-2]), &(yylsp[0]));
      }
#line 2102 "y.tab.c"
    break;

  case 61: /* expr: expr SLASH expr  */
#line 353 "src/scanparse/parser.y"
      {
        (yyval.node) = ASTbinop((yyvsp[-2].node), (yyvsp[0].node), BO_div);
        AddLocToNode((yyval.node), &(yylsp[-2]), &(yylsp[0]));
      }
#line 2111 "y.tab.c"
    break;

  case 62: /* expr: expr EQ expr  */
#line 358 "src/scanparse/parser.y"
      {
        (yyval.node) = ASTbinop((yyvsp[-2].node), (yyvsp[0].node), BO_eq);
        AddLocToNode((yyval.node), &(yylsp[-2]), &(yylsp[0]));
      }
#line 2120 "y.tab.c"
    break;

  case 63: /* expr: expr PERCENT expr  */
#line 363 "src/scanparse/parser.y"
      {
        (yyval.node) = ASTbinop((yyvsp[-2].node), (yyvsp[0].node), BO_mod);
        AddLocToNode((yyval.node), &(yylsp[-2]), &(yylsp[0]));
      }
#line 2129 "y.tab.c"
    break;

  case 64: /* expr: expr LT expr  */
#line 368 "src/scanparse/parser.y"
      {
        (yyval.node) = ASTbinop((yyvsp[-2].node), (yyvsp[0].node), BO_lt);
        AddLocToNode((yyval.node), &(yylsp[-2]), &(yylsp[0]));
      }
#line 2138 "y.tab.c"
    break;

  case 65: /* expr: expr GT expr  */
#line 373 "src/scanparse/parser.y"
      {
        (yyval.node) = ASTbinop((yyvsp[-2].node), (yyvsp[0].node), BO_gt);
        AddLocToNode((yyval.node), &(yylsp[-2]), &(yylsp[0]));
      }
#line 2147 "y.tab.c"
    break;

  case 66: /* expr: expr LE expr  */
#line 378 "src/scanparse/parser.y"
      {
        (yyval.node) = ASTbinop((yyvsp[-2].node), (yyvsp[0].node), BO_le);
        AddLocToNode((yyval.node), &(yylsp[-2]), &(yylsp[0]));
      }
#line 2156 "y.tab.c"
    break;

  case 67: /* expr: expr GE expr  */
#line 383 "src/scanparse/parser.y"
      {
        (yyval.node) = ASTbinop((yyvsp[-2].node), (yyvsp[0].node), BO_ge);
        AddLocToNode((yyval.node), &(yylsp[-2]), &(yylsp[0]));
      }
#line 2165 "y.tab.c"
    break;

  case 68: /* expr: expr OR expr  */
#line 388 "src/scanparse/parser.y"
      {
        (yyval.node) = ASTbinop((yyvsp[-2].node), (yyvsp[0].node), BO_or);
        AddLocToNode((yyval.node), &(yylsp[-2]), &(yylsp[0]));
      }
#line 2174 "y.tab.c"
    break;

  case 69: /* expr: expr NE expr  */
#line 393 "src/scanparse/parser.y"
      {
        (yyval.node) = ASTbinop((yyvsp[-2].node), (yyvsp[0].node), BO_ne);
        AddLocToNode((yyval.node), &(yylsp[-2]), &(yylsp[0]));
      }
#line 2183 "y.tab.c"
    break;

  case 70: /* expr: expr AND expr  */
#line 398 "src/scanparse/parser.y"
      {
        (yyval.node) = ASTbinop((yyvsp[-2].node), (yyvsp[0].node), BO_and);
        AddLocToNode((yyval.node), &(yylsp[-2]), &(yylsp[0]));
      }
#line 2192 "y.tab.c"
    break;

  case 71: /* expr: MINUS expr  */
#line 403 "src/scanparse/parser.y"
      {
        (yyval.node) = ASTmonop((yyvsp[0].node), MO_neg);
      }
#line 2200 "y.tab.c"
    break;

  case 72: /* expr: NEG expr  */
#line 407 "src/scanparse/parser.y"
      {
        (yyval.node) = ASTmonop((yyvsp[0].node), MO_not);
      }
#line 2208 "y.tab.c"
    break;

  case 73: /* expr: BRACKET_L expr BRACKET_R  */
#line 411 "src/scanparse/parser.y"
      {
        (yyval.node) = (yyvsp[-1].node);
      }
#line 2216 "y.tab.c"
    break;

  case 74: /* expr: BRACKET_L types BRACKET_R expr  */
#line 415 "src/scanparse/parser.y"
      {
        (yyval.node) = ASTcast((yyvsp[0].node), (yyvsp[-2].ctypes));
      }
#line 2224 "y.tab.c"
    break;

  case 75: /* expr: ID BRACKET_L exprs BRACKET_R  */
#line 419 "src/scanparse/parser.y"
      {
        (yyval.node) = ASTfuncall((yyvsp[-1].node), (yyvsp[-3].id));
      }
#line 2232 "y.tab.c"
    break;

  case 76: /* expr: ID BRACKET_L BRACKET_R  */
#line 423 "src/scanparse/parser.y"
      {
        (yyval.node) = ASTfuncall(NULL, (yyvsp[-2].id));
      }
#line 2240 "y.tab.c"
    break;

  case 77: /* exprs: expr COMMA exprs  */
#line 430 "src/scanparse/parser.y"
      {
        (yyval.node) = ASTexprs((yyvsp[-2].node), (yyvsp[0].node));
      }
#line 2248 "y.tab.c"
    break;

  case 78: /* exprs: expr  */
#line 434 "src/scanparse/parser.y"
        {
          (yyval.node) = ASTexprs((yyvsp[0].node), NULL);
        }
#line 2256 "y.tab.c"
    break;

  case 79: /* constant: floatval  */
#line 440 "src/scanparse/parser.y"
          {
            (yyval.node) = (yyvsp[0].node);
          }
#line 2264 "y.tab.c"
    break;

  case 80: /* constant: intval  */
#line 444 "src/scanparse/parser.y"
          {
            (yyval.node) = (yyvsp[0].node);
          }
#line 2272 "y.tab.c"
    break;

  case 81: /* constant: boolval  */
#line 448 "src/scanparse/parser.y"
          {
            (yyval.node) = (yyvsp[0].node);
          }
#line 2280 "y.tab.c"
    break;

  case 82: /* floatval: FLOAT  */
#line 454 "src/scanparse/parser.y"
           {
             (yyval.node) = ASTfloat((yyvsp[0].cflt));
           }
#line 2288 "y.tab.c"
    break;

  case 83: /* intval: NUM  */
#line 460 "src/scanparse/parser.y"
        {
          (yyval.node) = ASTnum((yyvsp[0].cint));
        }
#line 2296 "y.tab.c"
    break;

  case 84: /* boolval: TRUEVAL  */
#line 466 "src/scanparse/parser.y"
         {
           (yyval.node) = ASTbool(true);
         }
#line 2304 "y.tab.c"
    break;

  case 85: /* boolval: FALSEVAL  */
#line 470 "src/scanparse/parser.y"
         {
           (yyval.node) = ASTbool(false);
         }
#line 2312 "y.tab.c"
    break;

  case 86: /* types: INTTYPE  */
#line 476 "src/scanparse/parser.y"
       {
         (yyval.ctypes) = CT_int;
       }
#line 2320 "y.tab.c"
    break;

  case 87: /* types: FLOATTYPE  */
#line 480 "src/scanparse/parser.y"
       {
         (yyval.ctypes) = CT_float;
       }
#line 2328 "y.tab.c"
    break;

  case 88: /* types: BOOLTYPE  */
#line 484 "src/scanparse/parser.y"
       {
         (yyval.ctypes) = CT_bool;
       }
#line 2336 "y.tab.c"
    break;

  case 89: /* types: VOIDTYPE  */
#line 488 "src/scanparse/parser.y"
        {
          (yyval.ctypes) = CT_void;
        }
#line 2344 "y.tab.c"
    break;


#line 2348 "y.tab.c"

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

#line 492 "src/scanparse/parser.y"


void AddLocToNode(node_st *node, void *begin_loc, void *end_loc)
{
    // Needed because YYLTYPE unpacks later than top-level decl.
    YYLTYPE *loc_b = (YYLTYPE*)begin_loc;
    YYLTYPE *loc_e = (YYLTYPE*)end_loc;
    NODE_BLINE(node) = loc_b->first_line;
    NODE_BCOL(node) = loc_b->first_column;
    NODE_ELINE(node) = loc_e->last_line;
    NODE_ECOL(node) = loc_e->last_column;
}

static int yyerror( char *error)
{
  CTI(CTI_ERROR, true, "line %d, col %d\nError parsing source code: %s\n",
            global.line, global.col, error);
  CTIabortOnError();
  return( 0);
}

node_st *SPdoScanParse(node_st *root)
{
    DBUG_ASSERT(root == NULL, "Started parsing with existing syntax tree.");
    yyin = fopen(global.input_file, "r");
    if (yyin == NULL) {
        CTI(CTI_ERROR, true, "Cannot open file '%s'.", global.input_file);
        CTIabortOnError();
    }
    yyparse();
    return parseresult;
}
