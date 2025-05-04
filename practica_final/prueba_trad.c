#include <stdio.h> 

square (int v) { 
   int i ;
    return (v*v) ; 
} 
 
fact (int n) { 
   int f ; 
   if (n == 1) { 
      for (i = 0; i < 10; i=i+1) { 
         printf ("i = %d\n", i) ; 
      } 
   } else { 
     f = n * fact (n-1) ; 
   } 
   return f ; 
} 
 
is_even (int v) { 
   int ep  ; 
   int mivector[10]; 
   printf ("%d", v) ; 
   while (v > 0) { 
      v = v ; 
   }
   if (v % 2 == 0) { 
      puts (" is even") ; 
      ep = 1 ; 
   } else { 
      puts (" is odd") ; 
      ep = 0 ; 
   }
   mivector [5] = 123 ;
   return ep ; 
} 
 
main () { 
   printf ("%d\n", square (7)) ; 
   printf ("%d\n", fact (7)) ; 
   printf ("%d\n", is_even (7)) ; 
   printf ("%d\n", is_even (8)) ; 
   is_even (8) ;
}

//@ (main)
