// Variables globales necesarias para que gforth funcione
int a = 5;
int b = 3;
int r1, r2, r3, r4;

main() {
    r1 = a + b * 2;
    r2 = (a + b) * 2;
    r3 = a > b && b < 4;
    r4 = !(a == b);
    
}

//@ (main)