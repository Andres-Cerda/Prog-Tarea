#include <stdio.h>

int main(){

    int num1, num2;

    printf("Escriba un numero:\n");
    scanf( "%i", &num1 );
    printf("Escriba un segundo numero:\n");
    scanf("%i", &num2 );
    
    if ( num1 > num2 ){

        printf (" El numero %i es mayor que %i", num1, num2);
    }
    
    else { 
        printf ( " El numero %i es mayor que %i", num2, num1);
    }

    return 0;
}