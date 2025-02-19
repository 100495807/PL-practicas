/*
JORGE MEJIAS DONOSO - ALBERTO MENCHEN MONTERO - 206
100495807@alumons.uc3m.es 100495692@alumnos.uc3m.es
*/

%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define YYSTYPE double

#define MAX_VARIABLES 256

double variables[MAX_VARIABLES]; // Array para almacenar valores de variables (a-z)
char current_variable; // Variable global para almacenar el nombre de la variable actual

int get_variable_index(char var) {
    return var - 'a';
}
%}

%token NUMERO VARIABLE
%left '+' '-'
%left '*' '/'
%left SIGNO_UNARIO

%%
axioma:       expresion '\n' { printf("Expresion=%lf\n", $1); } r_expr
            | VARIABLE '=' expresion '\n' { 
                variables[get_variable_index(current_variable)] = $3;
                printf("Asignacion: %c = %lf\n", current_variable, $3);
              } r_expr
            ;

r_expr:                    /* lambda */
            | axioma
            ;

expresion:    expresion '+' expresion  { $$ = $1 + $3; }
            | expresion '-' expresion  { $$ = $1 - $3; }
            | expresion '*' expresion  { $$ = $1 * $3; }
            | expresion '/' expresion  { $$ = $1 / $3; }
            | NUMERO                   { $$ = $1; }
            | VARIABLE                 { $$ = variables[get_variable_index(current_variable)]; }
            | '+' expresion %prec SIGNO_UNARIO { $$ = $2; }
            | '-' expresion %prec SIGNO_UNARIO { $$ = -$2; }
            | '(' expresion ')'        { $$ = $2; }
            ;
%%

int n_linea = 1;

int yyerror(char *mensaje) {
    fprintf(stderr, "%s en la linea %d\n", mensaje, n_linea);
}

/* suprimir la funcion yylex () si se usa flex */
/*
int yylex() {
    int c;

    do {
        c = getchar();
    } while (c == ' ');

    if (c == '.' || (c >= '0' && c <= '9')) {
        ungetc(c, stdin);
        scanf("%lf", &yylval);
        return NUMERO;
    }

    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
        current_variable = c; // Almacenar el nombre de la variable actual
        yylval = c;
        return VARIABLE;
    }

    if (c == '\n')
        n_linea++;

    return c;
}
*/

int main() {
    yyparse();
}