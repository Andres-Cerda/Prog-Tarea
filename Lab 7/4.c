#include <stdio.h>

int main(){ 

    int numero;

    printf("Buenos dias, a continuacion escriba un numero y le daremos los todos los numeros primos anterior a el y el mismo\n");
    scanf("%i", &numero);

    for (int i=2 ; i <= numero; i++) {

         printf ("revisando si numero %d es primo \n", i);
         int divisores=0;

         for (int p = 2; p < i ; p++)
         {
             int resto = i%p;
             if(resto==0)
             {   divisores++;  }
             

         }
         if(divisores == 0)
         
         { printf(" %d Es primo\n", i); } 
         
         else { printf (" %d no es primo\n",i);}
    }





    return 0;
}