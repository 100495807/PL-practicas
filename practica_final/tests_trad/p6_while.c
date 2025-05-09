main() {
    int i = 0;
    while (i < 5) {
        printf("%d", i);
        i = i + 1;
    }

    while (i > 0) {
        while (i > 0) {
            printf("%d", i);
            i = i - 1;
        }
    }
    
}

//@ (main)
