#include <stdio.h>

int main(){

    int num1, num2, num3;

    printf(" Escriba un numero :\n ");
    scanf("%i", &num1);
    printf( " Escriba un segundo numero: \n");
    scanf("%i", &num2); 
    printf("Escriba un ultimo numero: \n");
    scanf ("%i",&num3); 

    if ( num1 > num2 && num1 > num3) {

        printf( "El numero mayor es: %i", num1);

    } else if ( num2 > num1 && num2 > num3) {

        printf(" El numero mayor es: %i", num2);

    } else if  (num3 > num1 && num3 > num2){

        printf (" El numero mayor es: %i", num3);

    } else {
    
        printf(" Sus numeros son iguales ");
    }
    




 return 0;
}