/*
JORGE MEJIAS DONOSO - ALBERTO MENCHEN MONTERO - 206
100495807@alumons.uc3m.es 100495692@alumnos.uc3m.es
*/
%{
#include "calc52.tab.h"   /* Cabecera generada por Bison con los tokens y union */
#include <stdio.h>

extern int n_linea;       /* Declarado en calc52.y */
%}

%%                  /* Segunda Seccion */

[ \t]           {;}  /* ignorar espacios y tabuladores */ 

[0-9]+(\.[0-9]*)?|\.[0-9]+   {
    /* Convertir la cadena a double y almacenarlo en yylval.valor */
    sscanf(yytext, "%lf", &yylval.valor);
    return NUMERO;
}

[A-Z]           {
    /* Carácter en mayúscula => índice 0..25 */
    yylval.indice = yytext[0] - 'A';
    return VARIABLE;
}

[a-z]           {
    /* Carácter en minúscula => índice 26..51 */
    yylval.indice = 26 + (yytext[0] - 'a');
    return VARIABLE;
}

\n             {
    /* Contabilizar la nueva línea */
    n_linea++;
    return '\n';
}

.              {
    /* Devolver cualquier otro carácter (símbolo) tal cual */
    return yytext[0];
}

%%

int yywrap() {
    return 1;
}