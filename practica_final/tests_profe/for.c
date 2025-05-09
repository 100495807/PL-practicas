#include <stdio.h>

main() {
    int i, j;

    for (i = 1; i <= 3; i=i+1) { // Bucle exterior
        printf("Tabla del %d:\n", i);
        
        for (j = 1; j <= 5; j=j+1) { // Bucle interior
            printf("%d x %d = %d\n", i, j, i * j);
        }
        
        puts("\n"); // Salto de línea entre tablas
    }

    return 0;
}