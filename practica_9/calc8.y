
/*
JORGE MEJIAS DONOSO - ALBERTO MENCHEN MONTERO - 206
100495807@alumons.uc3m.es 100495692@alumnos.uc3m.es
*/

%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


extern int yylex();
int yyerror(char *s);

char temp[2048];

typedef struct ASTnode t_node;

struct ASTnode {
    char *op;
    int type;
    t_node *left;
    t_node *right;
};

t_node *createASTNode(char *op, int type, t_node *left, t_node *right) {
    t_node *node = (t_node *)malloc(sizeof(t_node));
    node->op = strdup(op);
    node->type = type;
    node->left = left;
    node->right = right;
    return node;
}

void freeAST(t_node *node) {
    if (node) {
        freeAST(node->left);
        freeAST(node->right);
        free(node->op);
        free(node);
    }
}

void printAST2Prefix(t_node *node) {
    if (!node) return;
    if (node->type == 0) {
        printf("%s ", node->op);
    } else if (node->type == 1) {
        printf("( %s ", node->op);
        printAST2Prefix(node->left);
        printf(") ");
    } else {
        printf("( %s ", node->op);
        printAST2Prefix(node->left);
        printAST2Prefix(node->right);
        printf(") ");
    }
}

char *char_to_string(int c) {
    sprintf(temp, "%c", c);
    return strdup(temp);
}

char *int_to_string(int n) {
    sprintf(temp, "%d", n);
    return strdup(temp);
}

typedef struct {
    int value;
    int index;
    char *code;
    t_node *node;
} t_attr;

#define YYSTYPE t_attr
%}

%token NUMBER VARIABLE
%right '='
%left '+' '-'
%left '*' '/'
%left UNARY_SIGN

%%

axiom:
    /* permite varias líneas */
    /* vacío */                      
  | axiom expression '\n' {
        printAST2Prefix($2.node);
        printf("\n");
        freeAST($2.node);
    }
;

expression:
      expression '+' expression  { $$.node = createASTNode("+", 2, $1.node, $3.node); }
    | expression '-' expression  { $$.node = createASTNode("-", 2, $1.node, $3.node); }
    | expression '*' expression  { $$.node = createASTNode("*", 2, $1.node, $3.node); }
    | expression '/' expression  { $$.node = createASTNode("/", 2, $1.node, $3.node); }
    | VARIABLE '=' expression {
        char *name = char_to_string($1.index + 'A');
        $$.node = createASTNode("setq", 2,
                        createASTNode(name, 0, NULL, NULL),
                        $3.node);
    }
    | term { $$ = $1; }
;

term:
      '+' operand %prec UNARY_SIGN { $$.node = $2.node; }
    | '-' operand %prec UNARY_SIGN {
        $$.node = createASTNode("-", 2,
            createASTNode("0", 0, NULL, NULL),
            $2.node);
    }
    | operand { $$ = $1; }
;

operand:
      VARIABLE {
        char *name = char_to_string($1.index + 'A');
        $$.node = createASTNode(name, 0, NULL, NULL);
    }
    | NUMBER {
        char *num = int_to_string($1.value);
        $$.node = createASTNode(num, 0, NULL, NULL);
    }
    | '(' expression ')' { $$ = $2; }
;

%%

int n_line = 1;

int yyerror(char *s) {
    fprintf(stderr, "Error: %s at line %d\n", s, n_line);
    return 1;
}

int yylex() {
    int c;

    // Saltar espacios y tabulaciones
    do {
        c = getchar();
    } while (c == ' ' || c == '\t');

    // Saltar comentarios si los hubiera (opcional)

    // Número
    if (isdigit(c)) {
        ungetc(c, stdin);
        scanf("%d", &yylval.value);
        return NUMBER;
    }

    // Variable (letra minúscula o mayúscula)
    if (isalpha(c)) {
        yylval.index = (c & ~32) - 'A';  // Normaliza minúscula a mayúscula
        return VARIABLE;
    }

    // Fin de línea
    if (c == '\n') {
        n_line++;
        return '\n';
    }

    // Fin de archivo
    if (c == EOF) return 0;

    // Cualquier otro símbolo se devuelve directamente
    return c;
}

int main() {
    return yyparse();
}