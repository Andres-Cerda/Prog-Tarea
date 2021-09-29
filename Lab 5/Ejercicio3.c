#include <stdio.h>

int main(){

    printf("Por favor, escriba dos numero de la forma; X.X , Y:Y ; para multiplicarlo");

    float numero1 ;
    float numero2 ;
    float resultado ; 

printf("Ingrese un numero de la forma: X.X");
scanf ("%f , %f", &numero1 );
printf("ingrese otro numero de la forma: Y.Y");
scanf("%f , %f", &numero2 );

resultado = numero1 * numero2;

printf("el resultado de su multiplicacion entre %.2f y %.2f es: %.2f", resultado );

  

    return 0;
}
