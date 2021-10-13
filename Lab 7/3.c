#include <stdio.h>

int main(){

   int numero;
   int resultado; 

   printf("Escriba un numero y le mostrare los divisores\n");
   scanf("%d", &numero);

   for (int i = 1; i < numero; i++)
    {
        resultado = (numero%i);
        if (resultado!=0)
        
        {
            continue;
        }

        printf("%d\n",i);
    }
   

   



    
    return 0;
}
