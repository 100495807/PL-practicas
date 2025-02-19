%{
#include <stdio.h>
#define YYSTYPE double
double pot;
%}
%token DIG

%%
axioma:      expresion '\n' { printf("Expresion=%lf\n", $1); }  r_expr 
           ;

r_expr:      /* lambda */
           | axioma
           ;

expresion:   operando                { $$ = $1; }
           | operando '+' expresion  { $$ = $1 + $3; }
           | operando '-' expresion  { $$ = $1 - $3; }
           | operando '*' expresion  { $$ = $1 * $3; }
           | operando '/' expresion  { $$ = $1 / $3; }
           ;

operando:    resto_operando          { $$ = $1; } 
           | '-' resto_operando      { $$ = -$2; } 
           | '+' resto_operando      { $$ = $2; } 
           ; 
 
resto_operando:     
             numero                  { $$ = $1; } 
           | '('  expresion  ')'     { $$ = $2; } 
           ;

numero:      n_entero '.' n_decimal  { $$ = $1 + $3 ; } 
           | '.' n_decimal           { $$ = $2 ; } 
           | n_entero                { $$ = $1 ; }
           ;
 
n_entero:    DIG                    { $$ = $1 ; pot = 1 ; } 
           | DIG n_entero           { pot *= 10 ; $$ = $1 * pot + $2 ; } 
           ; 
 
n_decimal  : DIG                    { $$ = $1 / 10.0 ; } 
           | DIG n_decimal          { $$ = ($1 + $2) / 10.0 ; } 
           ;

%%

int yyerror(char *mensaje)
{
    fprintf(stderr, "%s\n", mensaje);
}

int yylex()
{
    unsigned char c;
    int valor;

    do {
         c = getchar();
    } while (c == ' ');

    if (c >= '0' && c <= '9') {
         yylval = c - '0';
         return DIG;
    }

    return c;
}

int main()
{
    yyparse();
}