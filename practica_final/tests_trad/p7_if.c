if_complejos(int a){
    if (a < 0) {
        puts("negativo");
        puts("menos");
    } else {
        puts("no es negativo");
        puts("mas");
    }

    if (a > 0) {
        puts("positivo");
        if (a == 0) {
            puts("cero");
        } else {
            puts("no es cero");
            a = a + 1;
        }
    } else {
        puts("negativo");
    }
}

main() {
    int a = 4;
    if (a > 0) {
        puts("positivo");
    }

    if (a == 0) {
        puts("cero");
    } else {
        puts("no es cero");
    }

    if_complejos(a)  ;  
}

//@ (main)
