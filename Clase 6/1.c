#include <stdio.h>

int main(){

    int num1, num2, resul ;

    printf ("Por favor escriba un numero");
    scanf ("%i", &num1);
    printf ("Por favor escriba un segundo numero");
    scanf ("%i", &num2 );

    if ( num2 == 0 ) {

        resul = num1 + num2 ; 
        printf (" el resultado de su suma es %i \n", resul) ;

    }


 


    return 0; 
}
