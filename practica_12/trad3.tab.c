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
#line 6 "trad3.y"
                          // SECCION 1 Declaraciones de C-Yacc

#include <stdio.h>
#include <ctype.h>            // declaraciones para tolower
#include <string.h>           // declaraciones para cadenas
#include <stdlib.h>           // declaraciones para exit ()

#define FF fflush(stdout);    // para forzar la impresion inmediata

int yylex () ;
int yyerror () ;
char *mi_malloc (int) ;
char *gen_code (char *) ;
char *int_to_string (int) ;
char *char_to_string (char) ;

char temp [4096] ;
char current_function[256] = "main"; // Nombre de la función actual
int inside_main = 0; // 0 fuera de main, 1 dentro

int is_local(char *name);
void insert_local(char *name);
void reset_local_table();
char *decorate(char *name);
int in_function_scope();  // ← declaración anticipada




// Abstract Syntax Tree (AST) Node Structure

typedef struct ASTnode t_node ;

struct ASTnode {
    char *op ;
    int type ;		// leaf, unary or binary nodes
    t_node *left ;
    t_node *right ;
} ;

// Definitions for explicit attributes

typedef struct s_attr {
    int value ;    // - Numeric value of a NUMBER 
    char *code ;   // - to pass IDENTIFIER names, and other translations 
    t_node *node ; // - for possible future use of AST
} t_attr ;

#define YYSTYPE t_attr

#line 122 "trad3.tab.c"

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

#include "trad3.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_NUMBER = 3,                     /* NUMBER  */
  YYSYMBOL_IDENTIF = 4,                    /* IDENTIF  */
  YYSYMBOL_INTEGER = 5,                    /* INTEGER  */
  YYSYMBOL_STRING = 6,                     /* STRING  */
  YYSYMBOL_MAIN = 7,                       /* MAIN  */
  YYSYMBOL_WHILE = 8,                      /* WHILE  */
  YYSYMBOL_FOR = 9,                        /* FOR  */
  YYSYMBOL_IF = 10,                        /* IF  */
  YYSYMBOL_ELSE = 11,                      /* ELSE  */
  YYSYMBOL_PUTS = 12,                      /* PUTS  */
  YYSYMBOL_PRINTF = 13,                    /* PRINTF  */
  YYSYMBOL_IGUAL = 14,                     /* IGUAL  */
  YYSYMBOL_DISTINTO = 15,                  /* DISTINTO  */
  YYSYMBOL_MENORIGUAL = 16,                /* MENORIGUAL  */
  YYSYMBOL_MAYORIGUAL = 17,                /* MAYORIGUAL  */
  YYSYMBOL_AND = 18,                       /* AND  */
  YYSYMBOL_OR = 19,                        /* OR  */
  YYSYMBOL_RETURN = 20,                    /* RETURN  */
  YYSYMBOL_21_ = 21,                       /* '='  */
  YYSYMBOL_NOT = 22,                       /* NOT  */
  YYSYMBOL_23_ = 23,                       /* '<'  */
  YYSYMBOL_24_ = 24,                       /* '>'  */
  YYSYMBOL_25_ = 25,                       /* '+'  */
  YYSYMBOL_26_ = 26,                       /* '-'  */
  YYSYMBOL_27_ = 27,                       /* '*'  */
  YYSYMBOL_28_ = 28,                       /* '/'  */
  YYSYMBOL_29_ = 29,                       /* '%'  */
  YYSYMBOL_UNARY_SIGN = 30,                /* UNARY_SIGN  */
  YYSYMBOL_31_ = 31,                       /* ';'  */
  YYSYMBOL_32_ = 32,                       /* '('  */
  YYSYMBOL_33_ = 33,                       /* ')'  */
  YYSYMBOL_34_ = 34,                       /* '['  */
  YYSYMBOL_35_ = 35,                       /* ']'  */
  YYSYMBOL_36_ = 36,                       /* '@'  */
  YYSYMBOL_37_ = 37,                       /* ','  */
  YYSYMBOL_38_ = 38,                       /* '{'  */
  YYSYMBOL_39_ = 39,                       /* '}'  */
  YYSYMBOL_40_ = 40,                       /* '!'  */
  YYSYMBOL_YYACCEPT = 41,                  /* $accept  */
  YYSYMBOL_programa = 42,                  /* programa  */
  YYSYMBOL_declaraciones = 43,             /* declaraciones  */
  YYSYMBOL_funciones = 44,                 /* funciones  */
  YYSYMBOL_instrucciones = 45,             /* instrucciones  */
  YYSYMBOL_instruccion_sep = 46,           /* instruccion_sep  */
  YYSYMBOL_sentencia_simple = 47,          /* sentencia_simple  */
  YYSYMBOL_sentencia_bloque = 48,          /* sentencia_bloque  */
  YYSYMBOL_declaracion_variable = 49,      /* declaracion_variable  */
  YYSYMBOL_lista_declaracion = 50,         /* lista_declaracion  */
  YYSYMBOL_lista_parametros = 51,          /* lista_parametros  */
  YYSYMBOL_expresion = 52,                 /* expresion  */
  YYSYMBOL_termino = 53,                   /* termino  */
  YYSYMBOL_operando = 54,                  /* operando  */
  YYSYMBOL_lista_elementos = 55,           /* lista_elementos  */
  YYSYMBOL_elemento = 56,                  /* elemento  */
  YYSYMBOL_lista_argumentos = 57,          /* lista_argumentos  */
  YYSYMBOL_funcion = 58,                   /* funcion  */
  YYSYMBOL_59_1 = 59,                      /* @1  */
  YYSYMBOL_60_2 = 60,                      /* $@2  */
  YYSYMBOL_bloque_instrucciones = 61       /* bloque_instrucciones  */
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
#define YYLAST   343

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  21
/* YYNRULES -- Number of rules.  */
#define YYNRULES  72
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  170

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   277


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
       2,     2,     2,    40,     2,     2,     2,    29,     2,     2,
      32,    33,    27,    25,    37,    26,     2,    28,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    31,
      23,    21,    24,     2,    36,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    34,     2,    35,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    38,     2,    39,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    22,    30
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    91,    91,    92,    96,    97,   100,   101,   105,   106,
     112,   113,   114,   115,   116,   119,   120,   130,   132,   136,
     138,   140,   145,   147,   149,   153,   161,   165,   179,   183,
     191,   198,   208,   217,   226,   238,   239,   246,   247,   249,
     251,   253,   255,   257,   259,   261,   263,   265,   267,   269,
     271,   273,   277,   278,   280,   286,   290,   294,   297,   301,
     305,   312,   313,   317,   319,   324,   325,   333,   333,   347,
     347,   366,   390
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
  "\"end of file\"", "error", "\"invalid token\"", "NUMBER", "IDENTIF",
  "INTEGER", "STRING", "MAIN", "WHILE", "FOR", "IF", "ELSE", "PUTS",
  "PRINTF", "IGUAL", "DISTINTO", "MENORIGUAL", "MAYORIGUAL", "AND", "OR",
  "RETURN", "'='", "NOT", "'<'", "'>'", "'+'", "'-'", "'*'", "'/'", "'%'",
  "UNARY_SIGN", "';'", "'('", "')'", "'['", "']'", "'@'", "','", "'{'",
  "'}'", "'!'", "$accept", "programa", "declaraciones", "funciones",
  "instrucciones", "instruccion_sep", "sentencia_simple",
  "sentencia_bloque", "declaracion_variable", "lista_declaracion",
  "lista_parametros", "expresion", "termino", "operando",
  "lista_elementos", "elemento", "lista_argumentos", "funcion", "@1",
  "$@2", "bloque_instrucciones", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-60)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      96,    14,    -9,    24,    96,   165,     2,   -60,   -12,     1,
      12,   -60,   165,    43,    77,   -60,   -60,   103,    46,   107,
      78,   -60,    83,   -60,   121,    91,   -22,   111,   -60,   -60,
     114,    95,   135,   138,   114,    51,   116,   117,   129,   130,
     139,     0,    88,   114,   -60,   152,   -60,   153,   -60,   142,
     -60,   188,   -60,   154,    88,     4,    88,    88,    35,    88,
     196,   197,   -60,   148,    18,    18,   -60,    88,    88,   232,
     -60,   -60,   268,   -60,   -60,   -60,   -60,   114,   -60,   -60,
     268,   -60,   268,    60,   128,   172,    88,   163,   192,   171,
     175,     9,    88,   -60,   -60,   212,   -60,    88,    88,    88,
      88,    88,    88,    88,    88,    88,    88,    88,    88,    88,
     -60,   174,   -60,    88,   193,   184,   268,    88,    74,   -60,
      50,   -60,    62,   150,   -60,   314,   314,   110,   110,   300,
     284,   110,   110,   131,   131,   -60,   -60,   -60,   -60,   268,
      88,   114,   250,   114,   201,   -60,   268,    65,   -60,   -60,
     -60,   268,   185,    35,   194,   -60,   -60,    50,   -60,   190,
     223,   -60,   204,   205,   114,   114,   213,   214,   -60,   -60
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     3,     0,     7,    31,    30,
       0,     1,     2,     0,     0,     6,     5,     0,     0,     0,
       0,     4,     0,    32,     0,     0,     0,    33,    67,    35,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    72,     8,     0,    11,     0,    15,     0,
      69,     0,    34,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    56,    55,     0,     0,    13,     0,     0,     0,
      37,    52,    19,     9,    10,    12,    71,     0,    36,    68,
      18,    22,    65,     0,     0,     0,    24,     0,     0,     0,
       0,     0,     0,    53,    54,     0,    51,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      14,     0,    23,     0,     0,     0,    25,     0,     0,    20,
       0,    58,     0,     0,    57,    45,    46,    47,    48,    49,
      50,    44,    43,    38,    39,    40,    41,    42,    70,    66,
       0,     0,     0,     0,     0,    64,    63,     0,    61,    59,
      60,    17,     0,     0,     0,    16,    21,     0,    28,     0,
      26,    62,     0,     0,     0,     0,     0,     0,    29,    27
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -60,   -60,   -60,   240,   -60,   211,   -48,   -60,   104,   -60,
     -60,   -40,   -60,   -59,   -60,   105,   179,    84,   -60,   -60,
     -34
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     3,     4,     5,    43,    44,    45,    46,    47,     9,
      26,    82,    70,    71,   147,   148,    83,    48,    34,    77,
      49
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      53,    69,    72,    62,    63,    93,    94,    62,    63,    17,
      87,    31,    62,    63,    80,    32,    84,    85,     8,    88,
      18,    62,    63,    10,    11,    64,    65,    95,    96,    64,
      65,    66,    67,    16,    64,    65,    67,    81,    19,    35,
      68,    67,   121,   111,    68,    20,   116,    39,    40,    68,
      67,    24,   123,    62,    63,    86,   145,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     144,    42,    54,   139,    21,    64,    65,   142,    35,    25,
     146,    22,    67,    55,     7,    56,    39,    40,     7,    15,
      68,    62,    63,   112,    86,   149,    15,   113,   156,   113,
     151,     1,   157,     2,     6,   159,    23,   152,    13,   154,
      42,    27,   143,    64,    65,    18,    28,   146,    35,     1,
      67,     2,    36,    37,    38,    29,    39,    40,    68,    30,
     166,   167,    33,    50,    41,   105,   106,   107,   108,   109,
      51,    52,    97,    98,    99,   100,   101,   102,    57,    58,
      42,   103,   104,   105,   106,   107,   108,   109,   107,   108,
     109,    59,    60,   114,    97,    98,    99,   100,   101,   102,
      14,    61,     2,   103,   104,   105,   106,   107,   108,   109,
      91,    76,    92,    74,    75,   150,    97,    98,    99,   100,
     101,   102,    78,    79,   117,   103,   104,   105,   106,   107,
     108,   109,    89,    90,   119,   115,    97,    98,    99,   100,
     101,   102,   120,   138,   140,   103,   104,   105,   106,   107,
     108,   109,   141,   162,   158,   118,    97,    98,    99,   100,
     101,   102,   155,   160,   163,   103,   104,   105,   106,   107,
     108,   109,   164,   165,    12,   124,    97,    98,    99,   100,
     101,   102,   168,   169,    73,   103,   104,   105,   106,   107,
     108,   109,   161,   110,    97,    98,    99,   100,   101,   102,
     122,     0,     0,   103,   104,   105,   106,   107,   108,   109,
       0,   153,    97,    98,    99,   100,   101,   102,     0,     0,
       0,   103,   104,   105,   106,   107,   108,   109,    97,    98,
      99,   100,   101,     0,     0,     0,     0,   103,   104,   105,
     106,   107,   108,   109,    97,    98,    99,   100,     0,     0,
       0,     0,     0,   103,   104,   105,   106,   107,   108,   109,
      99,   100,     0,     0,     0,     0,     0,   103,   104,   105,
     106,   107,   108,   109
};

static const yytype_int16 yycheck[] =
{
      34,    41,    42,     3,     4,    64,    65,     3,     4,    21,
      58,    33,     3,     4,    54,    37,    56,    57,     4,    59,
      32,     3,     4,    32,     0,    25,    26,    67,    68,    25,
      26,    31,    32,    31,    25,    26,    32,    33,    37,     4,
      40,    32,    33,    77,    40,    33,    86,    12,    13,    40,
      32,     5,    92,     3,     4,    20,     6,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     118,    36,    21,   113,    31,    25,    26,   117,     4,    33,
     120,     4,    32,    32,     0,    34,    12,    13,     4,     5,
      40,     3,     4,    33,    20,    33,    12,    37,    33,    37,
     140,     5,    37,     7,     0,   153,     3,   141,     4,   143,
      36,     4,    38,    25,    26,    32,    38,   157,     4,     5,
      32,     7,     8,     9,    10,     4,    12,    13,    40,    38,
     164,   165,    21,    38,    20,    25,    26,    27,    28,    29,
       5,     3,    14,    15,    16,    17,    18,    19,    32,    32,
      36,    23,    24,    25,    26,    27,    28,    29,    27,    28,
      29,    32,    32,    35,    14,    15,    16,    17,    18,    19,
       5,    32,     7,    23,    24,    25,    26,    27,    28,    29,
      32,    39,    34,    31,    31,    35,    14,    15,    16,    17,
      18,    19,     4,    39,    31,    23,    24,    25,    26,    27,
      28,    29,     6,     6,    33,    33,    14,    15,    16,    17,
      18,    19,    37,    39,    21,    23,    24,    25,    26,    27,
      28,    29,    38,    33,    39,    33,    14,    15,    16,    17,
      18,    19,    31,    39,    11,    23,    24,    25,    26,    27,
      28,    29,    38,    38,     4,    33,    14,    15,    16,    17,
      18,    19,    39,    39,    43,    23,    24,    25,    26,    27,
      28,    29,   157,    31,    14,    15,    16,    17,    18,    19,
      91,    -1,    -1,    23,    24,    25,    26,    27,    28,    29,
      -1,    31,    14,    15,    16,    17,    18,    19,    -1,    -1,
      -1,    23,    24,    25,    26,    27,    28,    29,    14,    15,
      16,    17,    18,    -1,    -1,    -1,    -1,    23,    24,    25,
      26,    27,    28,    29,    14,    15,    16,    17,    -1,    -1,
      -1,    -1,    -1,    23,    24,    25,    26,    27,    28,    29,
      16,    17,    -1,    -1,    -1,    -1,    -1,    23,    24,    25,
      26,    27,    28,    29
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     5,     7,    42,    43,    44,    49,    58,     4,    50,
      32,     0,    44,    49,     5,    58,    31,    21,    32,    37,
      33,    31,     4,     3,     5,    33,    51,     4,    38,     4,
      38,    33,    37,    21,    59,     4,     8,     9,    10,    12,
      13,    20,    36,    45,    46,    47,    48,    49,    58,    61,
      38,     5,     3,    61,    21,    32,    34,    32,    32,    32,
      32,    32,     3,     4,    25,    26,    31,    32,    40,    52,
      53,    54,    52,    46,    31,    31,    39,    60,     4,    39,
      52,    33,    52,    57,    52,    52,    20,    47,    52,     6,
       6,    32,    34,    54,    54,    52,    52,    14,    15,    16,
      17,    18,    19,    23,    24,    25,    26,    27,    28,    29,
      31,    61,    33,    37,    35,    33,    52,    31,    33,    33,
      37,    33,    57,    52,    33,    52,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    52,    52,    52,    39,    52,
      21,    38,    52,    38,    47,     6,    52,    55,    56,    33,
      35,    52,    61,    31,    61,    31,    33,    37,    39,    47,
      39,    56,    33,    11,    38,    38,    61,    61,    39,    39
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    41,    42,    42,    43,    43,    44,    44,    45,    45,
      46,    46,    46,    46,    46,    46,    46,    47,    47,    47,
      47,    47,    47,    47,    47,    47,    48,    48,    48,    48,
      49,    50,    50,    50,    50,    51,    51,    52,    52,    52,
      52,    52,    52,    52,    52,    52,    52,    52,    52,    52,
      52,    52,    53,    53,    53,    54,    54,    54,    54,    54,
      54,    55,    55,    56,    56,    57,    57,    59,    58,    60,
      58,    58,    61
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     1,     3,     2,     2,     1,     1,     2,
       2,     1,     2,     2,     3,     1,     6,     6,     3,     2,
       4,     6,     3,     4,     1,     2,     7,    11,     7,    11,
       2,     1,     3,     3,     5,     2,     4,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     2,     1,     2,     2,     1,     1,     3,     3,     4,
       4,     1,     3,     1,     1,     1,     3,     0,     7,     0,
       9,     7,     1
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
  case 8: /* instrucciones: instruccion_sep  */
#line 105 "trad3.y"
                                     { yyval = yyvsp[0]; }
#line 1308 "trad3.tab.c"
    break;

  case 9: /* instrucciones: instrucciones instruccion_sep  */
#line 106 "trad3.y"
                                    { sprintf(temp, "%s\n%s", yyvsp[-1].code, yyvsp[0].code);
                                      yyval.code = gen_code(temp); }
#line 1315 "trad3.tab.c"
    break;

  case 10: /* instruccion_sep: sentencia_simple ';'  */
#line 112 "trad3.y"
                                   { yyval = yyvsp[-1]; }
#line 1321 "trad3.tab.c"
    break;

  case 11: /* instruccion_sep: sentencia_bloque  */
#line 113 "trad3.y"
                                   { yyval = yyvsp[0]; }
#line 1327 "trad3.tab.c"
    break;

  case 12: /* instruccion_sep: declaracion_variable ';'  */
#line 114 "trad3.y"
                                   { yyval = yyvsp[-1]; }
#line 1333 "trad3.tab.c"
    break;

  case 13: /* instruccion_sep: RETURN ';'  */
#line 115 "trad3.y"
                                   { sprintf(temp, "(return)"); yyval.code = gen_code(temp); }
#line 1339 "trad3.tab.c"
    break;

  case 14: /* instruccion_sep: RETURN expresion ';'  */
#line 116 "trad3.y"
                               {
            sprintf(temp, "(return-from %s %s)", current_function, yyvsp[-1].code);
            yyval.code = gen_code(temp); }
#line 1347 "trad3.tab.c"
    break;

  case 15: /* instruccion_sep: funcion  */
#line 119 "trad3.y"
                                   { yyval = yyvsp[0]; }
#line 1353 "trad3.tab.c"
    break;

  case 16: /* instruccion_sep: IF '(' expresion ')' sentencia_simple ';'  */
#line 120 "trad3.y"
                                                    {
            sprintf(temp, "(if %s\n%s)", yyvsp[-3].code, yyvsp[-1].code);
            yyval.code = gen_code(temp);
        }
#line 1362 "trad3.tab.c"
    break;

  case 17: /* sentencia_simple: IDENTIF '[' expresion ']' '=' expresion  */
#line 130 "trad3.y"
                                                            { sprintf(temp, "(setf (aref %s %s) %s)", yyvsp[-5].code, yyvsp[-3].code, yyvsp[0].code);
                                                        yyval.code = gen_code(temp); }
#line 1369 "trad3.tab.c"
    break;

  case 18: /* sentencia_simple: IDENTIF '=' expresion  */
#line 132 "trad3.y"
                                            {
                                                sprintf(temp, "(setf %s %s)", decorate(yyvsp[-2].code), yyvsp[0].code);
                                                yyval.code = gen_code(temp); }
#line 1377 "trad3.tab.c"
    break;

  case 19: /* sentencia_simple: '@' expresion  */
#line 136 "trad3.y"
                                                      { sprintf(temp, "(print %s)", yyvsp[0].code);
                                                        yyval.code = gen_code(temp); }
#line 1384 "trad3.tab.c"
    break;

  case 20: /* sentencia_simple: PUTS '(' STRING ')'  */
#line 138 "trad3.y"
                                                      { sprintf(temp, "(print \"%s\")", yyvsp[-1].code);
                                                        yyval.code = gen_code(temp); }
#line 1391 "trad3.tab.c"
    break;

  case 21: /* sentencia_simple: PRINTF '(' STRING ',' lista_elementos ')'  */
#line 140 "trad3.y"
                                                                {
    sprintf(temp, "(princ \"%s\")\n%s", yyvsp[-3].code, yyvsp[-1].code);
    yyval.code = gen_code(temp);
}
#line 1400 "trad3.tab.c"
    break;

  case 22: /* sentencia_simple: IDENTIF '(' ')'  */
#line 145 "trad3.y"
                                                { sprintf(temp, "(%s)", yyvsp[-2].code);
                                                yyval.code = gen_code(temp); }
#line 1407 "trad3.tab.c"
    break;

  case 23: /* sentencia_simple: IDENTIF '(' lista_argumentos ')'  */
#line 147 "trad3.y"
                                                       { sprintf(temp, "(%s %s)", yyvsp[-3].code, yyvsp[-1].code);
                                                        yyval.code = gen_code(temp); }
#line 1414 "trad3.tab.c"
    break;

  case 24: /* sentencia_simple: RETURN  */
#line 149 "trad3.y"
                             {
                                            sprintf(temp, "(return)");
                                            yyval.code = gen_code(temp);
                                        }
#line 1423 "trad3.tab.c"
    break;

  case 25: /* sentencia_simple: RETURN expresion  */
#line 153 "trad3.y"
                                                           {
                                            sprintf(temp, "(return-from %s %s)", current_function, yyvsp[0].code);
                                            yyval.code = gen_code(temp);
                                        }
#line 1432 "trad3.tab.c"
    break;

  case 26: /* sentencia_bloque: IF '(' expresion ')' '{' bloque_instrucciones '}'  */
#line 161 "trad3.y"
                                                                      {
                        sprintf(temp, "(if %s\n%s\n)", yyvsp[-4].code, yyvsp[-1].code);
                        yyval.code = gen_code(temp);
                    }
#line 1441 "trad3.tab.c"
    break;

  case 27: /* sentencia_bloque: IF '(' expresion ')' '{' bloque_instrucciones '}' ELSE '{' bloque_instrucciones '}'  */
#line 165 "trad3.y"
                                                                                                          {
                            char temp_then[2048], temp_else[2048], temp_if[8192];
                            if (strchr(yyvsp[-5].code, '\n') != NULL)
                                sprintf(temp_then, "(progn\n%s)", yyvsp[-5].code);
                            else
                                sprintf(temp_then, "%s", yyvsp[-5].code);
                            if (strchr(yyvsp[-1].code, '\n') != NULL)
                                sprintf(temp_else, "(progn\n%s)", yyvsp[-1].code);
                            else
                                sprintf(temp_else, "%s", yyvsp[-1].code);

                            sprintf(temp_if, "(if %s\n%s\n%s)", yyvsp[-8].code, temp_then, temp_else);
                            yyval.code = gen_code(temp_if);
                        }
#line 1460 "trad3.tab.c"
    break;

  case 28: /* sentencia_bloque: WHILE '(' expresion ')' '{' bloque_instrucciones '}'  */
#line 179 "trad3.y"
                                                                           {
                        sprintf(temp, "(loop while %s do\n%s)", yyvsp[-4].code, yyvsp[-1].code);
                        yyval.code = gen_code(temp);
                    }
#line 1469 "trad3.tab.c"
    break;

  case 29: /* sentencia_bloque: FOR '(' sentencia_simple ';' expresion ';' sentencia_simple ')' '{' bloque_instrucciones '}'  */
#line 183 "trad3.y"
                                                                                                                   {
                            sprintf(temp, "%s\n(loop while %s do\n%s\n%s)", yyvsp[-8].code, yyvsp[-6].code, yyvsp[-1].code, yyvsp[-4].code);  
                            yyval.code = gen_code(temp);}
#line 1477 "trad3.tab.c"
    break;

  case 30: /* declaracion_variable: INTEGER lista_declaracion  */
#line 191 "trad3.y"
                              {
        printf("%s\n", yyvsp[0].code); 
        yyval.code = gen_code("");    // no acumular, ya está impreso
    }
#line 1486 "trad3.tab.c"
    break;

  case 31: /* lista_declaracion: IDENTIF  */
#line 198 "trad3.y"
                            {
                            printf("Declarando variable: %s (inside_main = %d)\n", yyvsp[0].code, inside_main);
                            if (in_function_scope()) {
                                insert_local(yyvsp[0].code);
                                sprintf(temp, "(setq %s_%s 0)", current_function, yyvsp[0].code);
                            } else {
                                sprintf(temp, "(setq %s 0)", yyvsp[0].code);
                            }
                            yyval.code = gen_code(temp);
                        }
#line 1501 "trad3.tab.c"
    break;

  case 32: /* lista_declaracion: IDENTIF '=' NUMBER  */
#line 208 "trad3.y"
                                         {
                        if (in_function_scope()) {
                            insert_local(yyvsp[-2].code);
                            sprintf(temp, "(setq %s_%s 0)", current_function, yyvsp[-2].code);
                        } else {
                            sprintf(temp, "(setq %s %d)", yyvsp[-2].code, yyvsp[0].value);
                        }
                        yyval.code = gen_code(temp);
                    }
#line 1515 "trad3.tab.c"
    break;

  case 33: /* lista_declaracion: lista_declaracion ',' IDENTIF  */
#line 217 "trad3.y"
                                                    {
                        if (in_function_scope()) {
                            insert_local(yyvsp[0].code);
                            sprintf(temp, "(setq %s_%s 0)", current_function, yyvsp[-2].code);
                        } else {
                            sprintf(temp, "%s\n(setq %s 0)", yyvsp[-2].code, yyvsp[0].code);
                        }
                        yyval.code = gen_code(temp);
                    }
#line 1529 "trad3.tab.c"
    break;

  case 34: /* lista_declaracion: lista_declaracion ',' IDENTIF '=' NUMBER  */
#line 226 "trad3.y"
                                                               {
                        if (in_function_scope()) {
                            insert_local(yyvsp[-2].code);
                            sprintf(temp, "(setq %s_%s 0)", current_function, yyvsp[-4].code);
                        } else {
                            sprintf(temp, "%s\n(setq %s %d)", yyvsp[-4].code, yyvsp[-2].code, yyvsp[0].value);
                        }
                        yyval.code = gen_code(temp);
                    }
#line 1543 "trad3.tab.c"
    break;

  case 35: /* lista_parametros: INTEGER IDENTIF  */
#line 238 "trad3.y"
                                      { yyval.code = yyvsp[0].code; }
#line 1549 "trad3.tab.c"
    break;

  case 36: /* lista_parametros: lista_parametros ',' INTEGER IDENTIF  */
#line 239 "trad3.y"
                                           {
        sprintf(temp, "%s %s", yyvsp[-3].code, yyvsp[0].code);
        yyval.code = gen_code(temp);
    }
#line 1558 "trad3.tab.c"
    break;

  case 37: /* expresion: termino  */
#line 246 "trad3.y"
                                          { yyval = yyvsp[0]; }
#line 1564 "trad3.tab.c"
    break;

  case 38: /* expresion: expresion '+' expresion  */
#line 247 "trad3.y"
                                          { sprintf(temp, "(+ %s %s)", yyvsp[-2].code, yyvsp[0].code);
                                            yyval.code = gen_code(temp); }
#line 1571 "trad3.tab.c"
    break;

  case 39: /* expresion: expresion '-' expresion  */
#line 249 "trad3.y"
                                          { sprintf(temp, "(- %s %s)", yyvsp[-2].code, yyvsp[0].code);
                                            yyval.code = gen_code(temp); }
#line 1578 "trad3.tab.c"
    break;

  case 40: /* expresion: expresion '*' expresion  */
#line 251 "trad3.y"
                                          { sprintf(temp, "(* %s %s)", yyvsp[-2].code, yyvsp[0].code);
                                            yyval.code = gen_code(temp); }
#line 1585 "trad3.tab.c"
    break;

  case 41: /* expresion: expresion '/' expresion  */
#line 253 "trad3.y"
                                          { sprintf(temp, "(/ %s %s)", yyvsp[-2].code, yyvsp[0].code);
                                            yyval.code = gen_code(temp); }
#line 1592 "trad3.tab.c"
    break;

  case 42: /* expresion: expresion '%' expresion  */
#line 255 "trad3.y"
                                      { sprintf(temp, "(mod %s %s)", yyvsp[-2].code, yyvsp[0].code);
                                            yyval.code = gen_code(temp); }
#line 1599 "trad3.tab.c"
    break;

  case 43: /* expresion: expresion '>' expresion  */
#line 257 "trad3.y"
                                          { sprintf(temp, "(> %s %s)", yyvsp[-2].code, yyvsp[0].code);
                                            yyval.code = gen_code(temp); }
#line 1606 "trad3.tab.c"
    break;

  case 44: /* expresion: expresion '<' expresion  */
#line 259 "trad3.y"
                                          { sprintf(temp, "(< %s %s)", yyvsp[-2].code, yyvsp[0].code);
                                            yyval.code = gen_code(temp); }
#line 1613 "trad3.tab.c"
    break;

  case 45: /* expresion: expresion IGUAL expresion  */
#line 261 "trad3.y"
                                             { sprintf(temp, "(= %s %s)", yyvsp[-2].code, yyvsp[0].code);
                                               yyval.code = gen_code(temp); }
#line 1620 "trad3.tab.c"
    break;

  case 46: /* expresion: expresion DISTINTO expresion  */
#line 263 "trad3.y"
                                             { sprintf(temp, "(/= %s %s)", yyvsp[-2].code, yyvsp[0].code);
                                               yyval.code = gen_code(temp); }
#line 1627 "trad3.tab.c"
    break;

  case 47: /* expresion: expresion MENORIGUAL expresion  */
#line 265 "trad3.y"
                                             { sprintf(temp, "(<= %s %s)", yyvsp[-2].code, yyvsp[0].code);
                                               yyval.code = gen_code(temp); }
#line 1634 "trad3.tab.c"
    break;

  case 48: /* expresion: expresion MAYORIGUAL expresion  */
#line 267 "trad3.y"
                                             { sprintf(temp, "(>= %s %s)", yyvsp[-2].code, yyvsp[0].code);
                                               yyval.code = gen_code(temp); }
#line 1641 "trad3.tab.c"
    break;

  case 49: /* expresion: expresion AND expresion  */
#line 269 "trad3.y"
                                         { sprintf(temp, "(and %s %s)", yyvsp[-2].code, yyvsp[0].code);
                                           yyval.code = gen_code(temp); }
#line 1648 "trad3.tab.c"
    break;

  case 50: /* expresion: expresion OR expresion  */
#line 271 "trad3.y"
                                         { sprintf(temp, "(or %s %s)", yyvsp[-2].code, yyvsp[0].code);
                                           yyval.code = gen_code(temp); }
#line 1655 "trad3.tab.c"
    break;

  case 51: /* expresion: '!' expresion  */
#line 273 "trad3.y"
                                             { sprintf(temp, "(not %s)", yyvsp[0].code);
                                   yyval.code = gen_code(temp); }
#line 1662 "trad3.tab.c"
    break;

  case 52: /* termino: operando  */
#line 277 "trad3.y"
                                          { yyval = yyvsp[0]; }
#line 1668 "trad3.tab.c"
    break;

  case 53: /* termino: '+' operando  */
#line 279 "trad3.y"
                                          { yyval = yyvsp[0]; }
#line 1674 "trad3.tab.c"
    break;

  case 54: /* termino: '-' operando  */
#line 281 "trad3.y"
                                          { sprintf(temp, "(- %s)", yyvsp[0].code);
                                            yyval.code = gen_code(temp); }
#line 1681 "trad3.tab.c"
    break;

  case 55: /* operando: IDENTIF  */
#line 286 "trad3.y"
              {
        sprintf(temp, "%s", decorate(yyvsp[0].code));
        yyval.code = gen_code(temp);
      }
#line 1690 "trad3.tab.c"
    break;

  case 56: /* operando: NUMBER  */
#line 290 "trad3.y"
             {
        sprintf(temp, "%d", yyvsp[0].value);
        yyval.code = gen_code(temp);
      }
#line 1699 "trad3.tab.c"
    break;

  case 57: /* operando: '(' expresion ')'  */
#line 294 "trad3.y"
                        {
        yyval = yyvsp[-1];
      }
#line 1707 "trad3.tab.c"
    break;

  case 58: /* operando: IDENTIF '(' ')'  */
#line 297 "trad3.y"
                      {
        sprintf(temp, "(%s)", yyvsp[-2].code); // funciones no se decoran
        yyval.code = gen_code(temp);
      }
#line 1716 "trad3.tab.c"
    break;

  case 59: /* operando: IDENTIF '(' lista_argumentos ')'  */
#line 301 "trad3.y"
                                       {
        sprintf(temp, "(%s %s)", yyvsp[-3].code, yyvsp[-1].code);
        yyval.code = gen_code(temp);
      }
#line 1725 "trad3.tab.c"
    break;

  case 60: /* operando: IDENTIF '[' expresion ']'  */
#line 305 "trad3.y"
                                {
        sprintf(temp, "(aref %s %s)", decorate(yyvsp[-3].code), yyvsp[-1].code);
        yyval.code = gen_code(temp);
      }
#line 1734 "trad3.tab.c"
    break;

  case 61: /* lista_elementos: elemento  */
#line 312 "trad3.y"
                             { yyval.code = yyvsp[0].code; }
#line 1740 "trad3.tab.c"
    break;

  case 62: /* lista_elementos: lista_elementos ',' elemento  */
#line 313 "trad3.y"
                                           { sprintf(temp, "%s\n%s", yyvsp[-2].code, yyvsp[0].code);
                                            yyval.code = gen_code(temp); }
#line 1747 "trad3.tab.c"
    break;

  case 63: /* elemento: expresion  */
#line 317 "trad3.y"
                              { sprintf(temp, "(princ %s)", yyvsp[0].code);
                                 yyval.code = gen_code(temp); }
#line 1754 "trad3.tab.c"
    break;

  case 64: /* elemento: STRING  */
#line 319 "trad3.y"
                             { sprintf(temp, "(princ \"%s\")", yyvsp[0].code);
                                 yyval.code = gen_code(temp); }
#line 1761 "trad3.tab.c"
    break;

  case 65: /* lista_argumentos: expresion  */
#line 324 "trad3.y"
                              { yyval.code = yyvsp[0].code; }
#line 1767 "trad3.tab.c"
    break;

  case 66: /* lista_argumentos: lista_argumentos ',' expresion  */
#line 325 "trad3.y"
                                     { sprintf(temp, "%s %s", yyvsp[-2].code, yyvsp[0].code);
                                       yyval.code = gen_code(temp); }
#line 1774 "trad3.tab.c"
    break;

  case 67: /* @1: %empty  */
#line 333 "trad3.y"
                         {
        reset_local_table();
        strcpy(current_function, "main");
        inside_main = 1;
    }
#line 1784 "trad3.tab.c"
    break;

  case 68: /* funcion: MAIN '(' ')' '{' @1 bloque_instrucciones '}'  */
#line 339 "trad3.y"
        {
                inside_main = 0;
                char *cuerpo = yyvsp[-2].code;
                snprintf(temp, sizeof(temp), "(defun main ()\n%s\n)", cuerpo);
                printf("%s\n", temp);
                yyval.code = gen_code("");
            }
#line 1796 "trad3.tab.c"
    break;

  case 69: /* $@2: %empty  */
#line 347 "trad3.y"
                                                       { reset_local_table();
                            strcpy(current_function, yyvsp[-4].code); }
#line 1803 "trad3.tab.c"
    break;

  case 70: /* funcion: INTEGER IDENTIF '(' lista_parametros ')' '{' $@2 bloque_instrucciones '}'  */
#line 349 "trad3.y"
                                                     {
                            inside_main = 0;
                            char *cuerpo = yyvsp[-1].code;
                            char *ultima_linea = strrchr(cuerpo, '\n');

                            if (ultima_linea && strncmp(ultima_linea + 1, "(return ", 8) == 0) {
                            *ultima_linea = '\0';
                            char expr[2048];
                            sscanf(ultima_linea + 8, "%[^)]", expr);
                            snprintf(temp, sizeof(temp), "(defun %s (%s)\n%s\n%s)", yyvsp[-7].code, yyvsp[-5].code, cuerpo, expr);
                            } else {    
                            snprintf(temp, sizeof(temp), "(defun %s (%s)\n%s\n)", yyvsp[-7].code, yyvsp[-5].code, cuerpo); }

                printf("%s\n", temp);
                yyval.code = gen_code("");
            }
#line 1824 "trad3.tab.c"
    break;

  case 71: /* funcion: INTEGER IDENTIF '(' ')' '{' bloque_instrucciones '}'  */
#line 366 "trad3.y"
                                                               {
                reset_local_table();
                strcpy(current_function, yyvsp[-5].code);
                char *cuerpo = yyvsp[-1].code;
                char *ultima_linea = strrchr(cuerpo, '\n');

                if (ultima_linea && strncmp(ultima_linea + 1, "(return ", 8) == 0) {
                    *ultima_linea = '\0';
                    char expr[2048];
                    sscanf(ultima_linea + 8, "%[^)]", expr);
                    snprintf(temp, sizeof(temp), "(defun %s ()\n%s\n%s)", yyvsp[-5].code, cuerpo, expr);
                } else {
                    snprintf(temp, sizeof(temp), "(defun %s ()\n%s\n)", yyvsp[-5].code, cuerpo);
                }

                printf("%s\n", temp);
                yyval.code = gen_code("");
            }
#line 1847 "trad3.tab.c"
    break;


#line 1851 "trad3.tab.c"

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

#line 392 "trad3.y"
                            // SECCION 4    Codigo en C

int n_line = 1 ;

int yyerror (mensaje)
char *mensaje ;
{
    fprintf (stderr, "%s en la linea %d\n", mensaje, n_line) ;
    printf ( "\n") ;	// bye
}

char *int_to_string (int n)
{
    sprintf (temp, "%d", n) ;
    return gen_code (temp) ;
}

char *char_to_string (char c)
{
    sprintf (temp, "%c", c) ;
    return gen_code (temp) ;
}

char *my_malloc (int nbytes)       // reserva n bytes de memoria dinamica
{
    char *p ;
    static long int nb = 0;        // sirven para contabilizar la memoria
    static int nv = 0 ;            // solicitada en total

    p = malloc (nbytes) ;
    if (p == NULL) {
        fprintf (stderr, "No queda memoria para %d bytes mas\n", nbytes) ;
        fprintf (stderr, "Reservados %ld bytes en %d llamadas\n", nb, nv) ;
        exit (0) ;
    }
    nb += (long) nbytes ;
    nv++ ;

    return p ;
}


/***************************************************************************/
/********************** Seccion de Palabras Reservadas *********************/
/***************************************************************************/

typedef struct s_keyword { // para las palabras reservadas de C
    char *name ;
    int token ;
} t_keyword ;

t_keyword keywords [] = { // define las palabras reservadas y los
    "main",        MAIN,           // y los token asociados
    "int",         INTEGER,
    "if",          IF,
    "else",        ELSE,
    "while",       WHILE,
    "for",         FOR,
    "puts",        PUTS,
    "printf",      PRINTF,
    "==",          IGUAL,
    "!=",          DISTINTO,
    "<=",          MENORIGUAL,
    ">=",          MAYORIGUAL,
    "&&",          AND,
    "||",          OR,
    "return",      RETURN,
    NULL,          0               // para marcar el fin de la tabla
} ;

t_keyword *search_keyword (char *symbol_name)
{                                  // Busca n_s en la tabla de pal. res.
                                   // y devuelve puntero a registro (simbolo)
    int i ;
    t_keyword *sim ;

    i = 0 ;
    sim = keywords ;
    while (sim [i].name != NULL) {
	    if (strcmp (sim [i].name, symbol_name) == 0) {
		                             // strcmp(a, b) devuelve == 0 si a==b
            return &(sim [i]) ;
        }
        i++ ;
    }

    return NULL ;
}


#define MAX_LOCAL_VARS 100
char *local_table[MAX_LOCAL_VARS];
int local_count = 0;

void reset_local_table() {
    local_count = 0;
}

int is_local(char *name) {
    for (int i = 0; i < local_count; i++) {
        if (strcmp(name, local_table[i]) == 0)
            return 1;
    }
    return 0;
}

int in_function_scope() {
    return inside_main != 0;
}



char* decorate(char *name) {
    static char decorated[512];
    int local = is_local(name);
    if (local) {
        snprintf(decorated, sizeof(decorated), "%s_%s", current_function, name);
        return decorated;
    }
    return name;
}

void insert_local(char *name) {
    if (local_count < MAX_LOCAL_VARS) {
        local_table[local_count++] = gen_code(name);
        printf("insert_local: %s\n", name);  // DEBUG
    }
}



 
/***************************************************************************/
/******************* Seccion del Analizador Lexicografico ******************/
/***************************************************************************/

char *gen_code (char *name)     // copia el argumento a un
{                                      // string en memoria dinamica
    char *p ;
    int l ;
	
    l = strlen (name)+1 ;
    p = (char *) my_malloc (l) ;
    strcpy (p, name) ;
	
    return p ;
}


int yylex ()
{
// NO MODIFICAR ESTA FUNCION SIN PERMISO
    int i ;
    unsigned char c ;
    unsigned char cc ;
    char ops_expandibles [] = "!<=|>%&/+-*" ;
    char temp_str [256] ;
    t_keyword *symbol ;

    do {
        c = getchar () ;

        if (c == '#') {	// Ignora las lineas que empiezan por #  (#define, #include)
            do {		//	OJO que puede funcionar mal si una linea contiene #
                c = getchar () ;
            } while (c != '\n') ;
        }

        if (c == '/') {	// Si la linea contiene un / puede ser inicio de comentario
            cc = getchar () ;
            if (cc != '/') {   // Si el siguiente char es /  es un comentario, pero...
                ungetc (cc, stdin) ;
            } else {
                c = getchar () ;	// ...
                if (c == '@') {	// Si es la secuencia //@  ==> transcribimos la linea
                    do {		// Se trata de codigo inline (Codigo embebido en C)
                        c = getchar () ;
                        putchar (c) ;
                    } while (c != '\n') ;
                } else {		// ==> comentario, ignorar la linea
                    while (c != '\n') {
                        c = getchar () ;
                    }
                }
            }
        } else if (c == '\\') c = getchar () ;
		
        if (c == '\n')
            n_line++ ;

    } while (c == ' ' || c == '\n' || c == 10 || c == 13 || c == '\t') ;

    if (c == '\"') {
        i = 0 ;
        do {
            c = getchar () ;
            temp_str [i++] = c ;
        } while (c != '\"' && i < 255) ;
        if (i == 256) {
            printf ("AVISO: string con mas de 255 caracteres en linea %d\n", n_line) ;
        }		 	// habria que leer hasta el siguiente " , pero, y si falta?
        temp_str [--i] = '\0' ;
        yylval.code = gen_code (temp_str) ;
        return (STRING) ;
    }

    if (c == '.' || (c >= '0' && c <= '9')) {
        ungetc (c, stdin) ;
        scanf ("%d", &yylval.value) ;
//         printf ("\nDEV: NUMBER %d\n", yylval.value) ;        // PARA DEPURAR
        return NUMBER ;
    }

    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
        i = 0 ;
        while (((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') ||
            (c >= '0' && c <= '9') || c == '_') && i < 255) {
            temp_str [i++] = tolower (c) ;
            c = getchar () ;
        }
        temp_str [i] = '\0' ;
        ungetc (c, stdin) ;

        yylval.code = gen_code (temp_str) ;
        symbol = search_keyword (yylval.code) ;
        if (symbol == NULL) {    // no es palabra reservada -> identificador antes vrariabre
//               printf ("\nDEV: IDENTIF %s\n", yylval.code) ;    // PARA DEPURAR
            return (IDENTIF) ;
        } else {
//               printf ("\nDEV: OTRO %s\n", yylval.code) ;       // PARA DEPURAR
            return (symbol->token) ;
        }
    }

    if (strchr (ops_expandibles, c) != NULL) { // busca c en ops_expandibles
        cc = getchar () ;
        sprintf (temp_str, "%c%c", (char) c, (char) cc) ;
        symbol = search_keyword (temp_str) ;
        if (symbol == NULL) {
            ungetc (cc, stdin) ;
            yylval.code = NULL ;
            return (c) ;
        } else {
            yylval.code = gen_code (temp_str) ; // aunque no se use
            return (symbol->token) ;
        }
    }

//    printf ("\nDEV: LITERAL %d #%c#\n", (int) c, c) ;      // PARA DEPURAR
    if (c == EOF || c == 255 || c == 26) {
//         printf ("tEOF ") ;                                // PARA DEPURAR
        return (0) ;
    }

    return c ;
}


int main ()
{
    yyparse () ;
}
