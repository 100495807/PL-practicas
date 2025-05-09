// Función auxiliar que devuelve una expresión aritmética compleja
calculo(int a, int b) {
    return (a + b) * (a - b);
}

// Función principal
main() {
    int x = 6;
    int y = 2;
    int r;
    r = calculo(x, y);
    printf("%d", r);
}

//@ (main)
