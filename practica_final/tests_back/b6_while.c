// Declaraciones globales para gforth
int i = 0;
int contador = 0;

main() {
    while (i < 3) {
        puts("Iteración");
        contador = contador + 1;
        i = i + 1;
    }
    //@ (main)
}
