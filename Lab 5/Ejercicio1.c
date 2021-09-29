#include <stdio.h>

int main(){
      
      /*Se muestra por pantalla la descripción del programa*/
     
    printf("\n Buenas tardes, espero vengas con ganas de sumar \n\n ");
    printf(" ingrese dos numeros a continuacion por favor \n\n");
    
      /* Se declaran las variables */

    int numero1;
    int numero2;
    int resultado;
   

    printf(" Ingrese un numero:  ");
    scanf("%i", &numero1);
    printf("\n Ingrese segundo numero: ");
    scanf("%i", &numero2);

    resultado = numero1 + numero2 ;


    printf("\n El resultado de la suma es %i\n\n", resultado);


return 0 ;
}