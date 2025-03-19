/*
JORGE MEJIAS DONOSO - ALBERTO MENCHEN MONTERO - 206
100495807@alumons.uc3m.es 100495692@alumnos.uc3m.es
*/

%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

extern int yylex();
extern int yyerror();

char temp[2048];

#define FF fflush(stdout);

char *allocate_malloc(int nbytes) {
    char *p;
    static long int nb = 0;
    static int nv = 0;

    p = malloc(nbytes);
    if (p == NULL) {
        fprintf(stderr, "No queda memoria para %d bytes mas\n", nbytes);
        fprintf(stderr, "Reservados %ld bytes en %d llamadas\n", nb, nv);
        exit(1);
    }
    nb += (long) nbytes;
    nv++;

    return p;
}

char *generate_string(char *nombre) {
    char *p;
    int l = strlen(nombre) + 1;
    p = (char *) allocate_malloc(l);
    strcpy(p, nombre);
    return p;
}

char *int_to_string(int n) {
    sprintf(temp, "%d", n);
    return generate_string(temp);
}

char *char_to_string(char c) {
    sprintf(temp, "%c", c);
    return generate_string(temp);
}

// Liberación de memoria antes de salir
void free_memory(char *cadena) {
    if (cadena != NULL) {
        free(cadena);
    }
}

typedef struct s_attr {
    int valor;
    int indice;
    char *cadena;
} t_attr;

#define YYSTYPE t_attr

%}

%token NUMERO
%token VARIABLE
%token PRINT  

%right '='
%left '+' '-'
%left '*' '/'
%left SIGNO_UNARIO

%%

axioma: axioma expresion '\n' {
        printf("%s\n", $2.cadena);
        free_memory($2.cadena);
    }
    | axioma VARIABLE '=' expresion '\n' {
        sprintf(temp, "(setq %c %s)", $2.indice, $4.cadena);
        printf("%s\n", temp);
        free_memory($4.cadena);
    }
    | axioma PRINT expresion '\n' {  
        sprintf(temp, "(print %s)", $3.cadena);
        printf("%s\n", temp);
        free_memory($3.cadena);
    }
    | /* producción vacía */
    ;

expresion: termino {
        $$.cadena = $1.cadena;
    }
    | expresion '+' expresion {
        sprintf(temp, "(+ %s %s)", $1.cadena, $3.cadena);
        $$.cadena = generate_string(temp);
        free_memory($1.cadena);
        free_memory($3.cadena);
    }
    | expresion '-' expresion {
        sprintf(temp, "(- %s %s)", $1.cadena, $3.cadena);
        $$.cadena = generate_string(temp);
        free_memory($1.cadena);
        free_memory($3.cadena);
    }
    | expresion '*' expresion {
        sprintf(temp, "(* %s %s)", $1.cadena, $3.cadena);
        $$.cadena = generate_string(temp);
        free_memory($1.cadena);
        free_memory($3.cadena);
    }
    | expresion '/' expresion {
        sprintf(temp, "(/ %s %s)", $1.cadena, $3.cadena);
        $$.cadena = generate_string(temp);
        free_memory($1.cadena);
        free_memory($3.cadena);
    }
    ;

termino: operando {
        $$.cadena = $1.cadena;
    }
    | '+' operando %prec SIGNO_UNARIO {
        $$.cadena = $2.cadena;
    }
    | '-' operando %prec SIGNO_UNARIO {
        sprintf(temp, "(- %s)", $2.cadena);
        $$.cadena = generate_string(temp);
        free_memory($2.cadena);
    }
    ;

operando: VARIABLE {
        sprintf(temp, "%c", $1.indice);
        $$.cadena = generate_string(temp);
    }
    | NUMERO {
        $$.cadena = int_to_string($1.valor);
    }
    | '(' expresion ')' {
        $$.cadena = $2.cadena;
    }
    ;

%%

int n_linea = 1;

int yyerror(char *mensaje) {
    fprintf(stderr, "%s en la linea %d\n", mensaje, n_linea);
    return 0;
}

int yylex() {
    unsigned char c;

    do {
        c = getchar();
    } while (c == ' ' || c == '\r');

    if (c == '.' || (c >= '0' && c <= '9')) {
        ungetc(c, stdin);
        scanf("%d", &yylval.valor);
        return NUMERO;
    }

    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
        yylval.indice = c;
        return VARIABLE;
    }

    if (c == '@') {  // Reconocer '@' como PRINT
        return PRINT;
    }

    if (c == '\n')
        n_linea++;
    return c;
}

int main() {
    yyparse();
    return 0;
}
