#include <stdio.h> 

int mivector[10]; 

 
fact (int n) { 
   int f ; 
   if (n == 1) { 
      f = 1 ; 
   } else { 
     f = n * fact (n-1) ; 
   } 
   return f ; 
} 
 
is_even (int v) { 
   int ep  ; 
   printf ("%d", v) ;            

   if (v % 2 == 0) { 
      puts (" is even") ; 
      ep = 1 ; 
   } else { 
      puts (" is odd") ; 
      ep = 0 ; 
   } 
   return ep ; 
} 

factorial (int n) {
    if (n==0) {
        return 1;
    } else {
        printf("%d %d \n", n, n*factorial(n-1)) ;
    }
}

imprime (int n) {
    int i, prime = 1;
    for (i=2; i<=n; i = 1+ i) {
        if (i%2==0) {
            printf("%d ", i) ;
        }
    }
    return prime;
}
 
main () {             
   puts (" ") ;
   printf ("%d\n", fact (7)) ; 
   puts (" ") ;
   printf ("%d\n", is_even (7)) ; 
   puts (" ") ;
   printf ("%d\n", is_even (8)) ; 
   puts (" ") ;
   imprime (10) ;
   is_even (8) ;
}


//@ (main)
