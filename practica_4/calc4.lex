/*
JORGE MEJIAS DONOSO - ALBERTO MENCHEN MONTERO - 206
100495807@alumons.uc3m.es 100495692@alumnos.uc3m.es
*/
%{
#include "calc4.tab.h"        /* Cabecera con decl. de token etc. */
extern int n_linea;
extern char current_variable;
%}

%%                            /* Segunda Seccion */
[ \t]                    { ; } /* ignorar espacios y tabuladores */
[0-9]+(\.[0-9]*)?|\.[0-9]+ { sscanf(yytext, "%lf", &yylval); return NUMERO; }
[a-zA-Z]                 { current_variable = yytext[0]; return VARIABLE; }
\n                       { n_linea++; return '\n'; }
.                        { return yytext[0]; }   /* literales */

%%                            /* Tercera Seccion */
int yywrap ()     /* se incluye para evitar un error de compilacion */
{
    return 1; /* para el control de fin de fichero */
}