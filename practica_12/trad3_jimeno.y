/*
MIGUEL JIMENO CASAS - HECTOR HERRAIZ DIEZ - GRUPO 211
 100495932@alumnos.uc3m.es - 100499734@alumnos.uc3m.es
*/

%{                          // SECCION 1 Declaraciones de C-Yacc

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
%}

// Definitions for explicit attributes

%token NUMBER        
%token IDENTIF       // Identificador=variable
%token INTEGER       // identifica el tipo entero
%token STRING
%token MAIN          // identifica el comienzo del proc. main
%token WHILE         // identifica el bucle main
%token FOR          // identifica el bucle for
%token IF            // identifica la sentencia if
%token ELSE          // identifica la sentencia else
%token PUTS         // identifica la sentencia puts
%token PRINTF       // identifica la sentencia printf
%token IGUAL DISTINTO MENORIGUAL MAYORIGUAL 
%token AND OR
%token RETURN




%right '='                        // asignación
%left OR                          // or lógico
%left AND                         // and lógico
%right NOT                         // not lógico
%left IGUAL DISTINTO             // comparación de igualdad
%left '<' '>' MENORIGUAL MAYORIGUAL  // comparación numérica
%left '+' '-'                    // suma y resta
%left '*' '/' '%'                   // multiplicación y división
%left UNARY_SIGN                 // signo unario


%%                            // Seccion 3 Gramatica - Semantico

programa:
      declaraciones funciones
    | funciones ;


declaraciones:
      declaraciones declaracion_variable ';'
    | declaracion_variable ';' ;

funciones:
      funciones funcion
    | funcion ;


instrucciones:
      instruccion_sep                { $$ = $1; }
    | instrucciones instruccion_sep { sprintf(temp, "%s\n%s", $1.code, $2.code);
                                      $$.code = gen_code(temp); }
    ;


instruccion_sep:
            sentencia_simple ';'   { $$ = $1; }
        | sentencia_bloque         { $$ = $1; }
        | declaracion_variable ';' { $$ = $1; }
        | RETURN ';'               { sprintf(temp, "(return)"); $$.code = gen_code(temp); }
        | RETURN expresion ';' {
            sprintf(temp, "(return-from %s %s)", current_function, $2.code);
            $$.code = gen_code(temp); }
        | funcion                  { $$ = $1; }
        | IF '(' expresion ')' sentencia_simple ';' {
            sprintf(temp, "(if %s\n%s)", $3.code, $5.code);
            $$.code = gen_code(temp);
        }
        ;




sentencia_simple:
                    IDENTIF '[' expresion ']' '=' expresion { sprintf(temp, "(setf (aref %s %s) %s)", $1.code, $3.code, $6.code);
                                                        $$.code = gen_code(temp); }
                    | IDENTIF '=' expresion {
                                                sprintf(temp, "(setf %s %s)", decorate($1.code), $3.code);
                                                $$.code = gen_code(temp); }

                    | '@' expresion                   { sprintf(temp, "(print %s)", $2.code);
                                                        $$.code = gen_code(temp); }
                    | PUTS '(' STRING ')'             { sprintf(temp, "(print \"%s\")", $3.code);
                                                        $$.code = gen_code(temp); }
                    | PRINTF '(' STRING ',' lista_elementos ')' {
    sprintf(temp, "(princ \"%s\")\n%s", $3.code, $5.code);
    $$.code = gen_code(temp);
}

                    | IDENTIF '(' ')'           { sprintf(temp, "(%s)", $1.code);
                                                $$.code = gen_code(temp); }
                    | IDENTIF '(' lista_argumentos ')' { sprintf(temp, "(%s %s)", $1.code, $3.code);
                                                        $$.code = gen_code(temp); }
                    | RETURN {
                                            sprintf(temp, "(return)");
                                            $$.code = gen_code(temp);
                                        }
                                        | RETURN expresion {
                                            sprintf(temp, "(return-from %s %s)", current_function, $2.code);
                                            $$.code = gen_code(temp);
                                        }

                    ;

sentencia_bloque:
                    IF '(' expresion ')' '{' bloque_instrucciones '}' {
                        sprintf(temp, "(if %s\n%s\n)", $3.code, $6.code);
                        $$.code = gen_code(temp);
                    }
                    | IF '(' expresion ')' '{' bloque_instrucciones '}' ELSE '{' bloque_instrucciones '}' {
                            char temp_then[2048], temp_else[2048], temp_if[8192];
                            if (strchr($6.code, '\n') != NULL)
                                sprintf(temp_then, "(progn\n%s)", $6.code);
                            else
                                sprintf(temp_then, "%s", $6.code);
                            if (strchr($10.code, '\n') != NULL)
                                sprintf(temp_else, "(progn\n%s)", $10.code);
                            else
                                sprintf(temp_else, "%s", $10.code);

                            sprintf(temp_if, "(if %s\n%s\n%s)", $3.code, temp_then, temp_else);
                            $$.code = gen_code(temp_if);
                        }
                    | WHILE '(' expresion ')' '{' bloque_instrucciones '}' {
                        sprintf(temp, "(loop while %s do\n%s)", $3.code, $6.code);
                        $$.code = gen_code(temp);
                    }
                    | FOR '(' sentencia_simple ';' expresion ';' sentencia_simple ')' '{' bloque_instrucciones '}' {
                            sprintf(temp, "%s\n(loop while %s do\n%s\n%s)", $3.code, $5.code, $10.code, $7.code);  
                            $$.code = gen_code(temp);} 
                    ;



declaracion_variable:
    INTEGER lista_declaracion {
        printf("%s\n", $2.code); 
        $$.code = gen_code("");    // no acumular, ya está impreso
    }
    ;


lista_declaracion:  IDENTIF {
                            printf("Declarando variable: %s (inside_main = %d)\n", $1.code, inside_main);
                            if (in_function_scope()) {
                                insert_local($1.code);
                                sprintf(temp, "(setq %s_%s 0)", current_function, $1.code);
                            } else {
                                sprintf(temp, "(setq %s 0)", $1.code);
                            }
                            $$.code = gen_code(temp);
                        }
                    | IDENTIF '=' NUMBER {
                        if (in_function_scope()) {
                            insert_local($1.code);
                            sprintf(temp, "(setq %s_%s 0)", current_function, $1.code);
                        } else {
                            sprintf(temp, "(setq %s %d)", $1.code, $3.value);
                        }
                        $$.code = gen_code(temp);
                    }
                    | lista_declaracion ',' IDENTIF {
                        if (in_function_scope()) {
                            insert_local($3.code);
                            sprintf(temp, "(setq %s_%s 0)", current_function, $1.code);
                        } else {
                            sprintf(temp, "%s\n(setq %s 0)", $1.code, $3.code);
                        }
                        $$.code = gen_code(temp);
                    }
                    | lista_declaracion ',' IDENTIF '=' NUMBER {
                        if (in_function_scope()) {
                            insert_local($3.code);
                            sprintf(temp, "(setq %s_%s 0)", current_function, $1.code);
                        } else {
                            sprintf(temp, "%s\n(setq %s %d)", $1.code, $3.code, $5.value);
                        }
                        $$.code = gen_code(temp);
                    }


lista_parametros:
      INTEGER IDENTIF                 { $$.code = $2.code; }
    | lista_parametros ',' INTEGER IDENTIF {
        sprintf(temp, "%s %s", $1.code, $4.code);
        $$.code = gen_code(temp);
    }
  ;


expresion:      termino                   { $$ = $1; }
            | expresion '+' expresion     { sprintf(temp, "(+ %s %s)", $1.code, $3.code);
                                            $$.code = gen_code(temp); }
            | expresion '-' expresion     { sprintf(temp, "(- %s %s)", $1.code, $3.code);
                                            $$.code = gen_code(temp); }
            | expresion '*' expresion     { sprintf(temp, "(* %s %s)", $1.code, $3.code);
                                            $$.code = gen_code(temp); }
            | expresion '/' expresion     { sprintf(temp, "(/ %s %s)", $1.code, $3.code);
                                            $$.code = gen_code(temp); }
            | expresion '%' expresion { sprintf(temp, "(mod %s %s)", $1.code, $3.code);
                                            $$.code = gen_code(temp); }
            | expresion '>' expresion     { sprintf(temp, "(> %s %s)", $1.code, $3.code);
                                            $$.code = gen_code(temp); }
            | expresion '<' expresion     { sprintf(temp, "(< %s %s)", $1.code, $3.code);
                                            $$.code = gen_code(temp); }
            | expresion IGUAL expresion      { sprintf(temp, "(= %s %s)", $1.code, $3.code);
                                               $$.code = gen_code(temp); }
            | expresion DISTINTO expresion   { sprintf(temp, "(/= %s %s)", $1.code, $3.code);
                                               $$.code = gen_code(temp); }
            | expresion MENORIGUAL expresion { sprintf(temp, "(<= %s %s)", $1.code, $3.code);
                                               $$.code = gen_code(temp); }
            | expresion MAYORIGUAL expresion { sprintf(temp, "(>= %s %s)", $1.code, $3.code);
                                               $$.code = gen_code(temp); }
            | expresion AND expresion    { sprintf(temp, "(and %s %s)", $1.code, $3.code);
                                           $$.code = gen_code(temp); }
            | expresion OR expresion     { sprintf(temp, "(or %s %s)", $1.code, $3.code);
                                           $$.code = gen_code(temp); }
            | '!' expresion %prec UNARY_SIGN { sprintf(temp, "(not %s)", $2.code);
                                   $$.code = gen_code(temp); }
            ;

termino:        operando                  { $$ = $1; }                          
            | '+' operando %prec UNARY_SIGN
                                          { $$ = $2; }
            | '-' operando %prec UNARY_SIGN
                                          { sprintf(temp, "(- %s)", $2.code);
                                            $$.code = gen_code(temp); }    
            ;

operando:
      IDENTIF {
        sprintf(temp, "%s", decorate($1.code));
        $$.code = gen_code(temp);
      }
    | NUMBER {
        sprintf(temp, "%d", $1.value);
        $$.code = gen_code(temp);
      }
    | '(' expresion ')' {
        $$ = $2;
      }
    | IDENTIF '(' ')' {
        sprintf(temp, "(%s)", $1.code); // funciones no se decoran
        $$.code = gen_code(temp);
      }
    | IDENTIF '(' lista_argumentos ')' {
        sprintf(temp, "(%s %s)", $1.code, $3.code);
        $$.code = gen_code(temp);
      }
    | IDENTIF '[' expresion ']' {
        sprintf(temp, "(aref %s %s)", decorate($1.code), $3.code);
        $$.code = gen_code(temp);
      }
    ;


lista_elementos:    elemento { $$.code = $1.code; }
            | lista_elementos ',' elemento { sprintf(temp, "%s\n%s", $1.code, $3.code);
                                            $$.code = gen_code(temp); }
            ;

elemento:           expresion { sprintf(temp, "(princ %s)", $1.code);
                                 $$.code = gen_code(temp); }
                    | STRING { sprintf(temp, "(princ \"%s\")", $1.code);
                                 $$.code = gen_code(temp); }
            ;

lista_argumentos:
      expresion               { $$.code = $1.code; }
    | lista_argumentos ',' expresion { sprintf(temp, "%s %s", $1.code, $3.code);
                                       $$.code = gen_code(temp); }
    ;



// FASE 2: funcion main
funcion:
        MAIN '(' ')' '{' {
        reset_local_table();
        strcpy(current_function, "main");
        inside_main = 1;
    }
        bloque_instrucciones '}'
        {
                inside_main = 0;
                char *cuerpo = $5.code;
                snprintf(temp, sizeof(temp), "(defun main ()\n%s\n)", cuerpo);
                printf("%s\n", temp);
                $$.code = gen_code("");
            }

        | INTEGER IDENTIF '(' lista_parametros ')' '{' { reset_local_table();
                            strcpy(current_function, $2.code); }
                            bloque_instrucciones '}' {
                            inside_main = 0;
                            char *cuerpo = $8.code;
                            char *ultima_linea = strrchr(cuerpo, '\n');

                            if (ultima_linea && strncmp(ultima_linea + 1, "(return ", 8) == 0) {
                            *ultima_linea = '\0';
                            char expr[2048];
                            sscanf(ultima_linea + 8, "%[^)]", expr);
                            snprintf(temp, sizeof(temp), "(defun %s (%s)\n%s\n%s)", $2.code, $4.code, cuerpo, expr);
                            } else {    
                            snprintf(temp, sizeof(temp), "(defun %s (%s)\n%s\n)", $2.code, $4.code, cuerpo); }

                printf("%s\n", temp);
                $$.code = gen_code("");
            }

        | INTEGER IDENTIF '(' ')' '{' bloque_instrucciones '}' {
                reset_local_table();
                strcpy(current_function, $2.code);
                char *cuerpo = $6.code;
                char *ultima_linea = strrchr(cuerpo, '\n');

                if (ultima_linea && strncmp(ultima_linea + 1, "(return ", 8) == 0) {
                    *ultima_linea = '\0';
                    char expr[2048];
                    sscanf(ultima_linea + 8, "%[^)]", expr);
                    snprintf(temp, sizeof(temp), "(defun %s ()\n%s\n%s)", $2.code, cuerpo, expr);
                } else {
                    snprintf(temp, sizeof(temp), "(defun %s ()\n%s\n)", $2.code, cuerpo);
                }

                printf("%s\n", temp);
                $$.code = gen_code("");
            }
        ;





bloque_instrucciones: instrucciones ;

%%                            // SECCION 4    Codigo en C

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
