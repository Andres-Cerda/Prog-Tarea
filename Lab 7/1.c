#include <stdio.h>

int main(){ 

    printf(" A continuacion se le mostraran los numeros pares entre 0 y 100\n\n");
    
   for (int i = 0; i <= 100; i++)
    {
       while (i % 2 == 0)
       {
           printf ("%i \n", i);
           break;
       } 
       
            
           
    }

    
         
    
    
    return 0 ;
}
