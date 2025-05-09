int x = 10;

valida(int a, int b) {
    if (x > a) {
        puts("x es mayor que a");
    } else {
        puts("x no es mayor");
    }

    for (b = 0; b < 3; b = b + 1) {
        printf("%d", b);
    }
}

main() {
    int a = 2;
    int b = 0;

    valida(a, b);

    
}

//@ (main)
