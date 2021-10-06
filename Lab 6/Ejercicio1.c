#include  <stdio.h>

int main(){

    int num;

    printf("Escriba un numero para que le indique si es par o impar: \n\n");
    scanf("%i", &num);
    
    if ( num % 2 == 0) {

        printf ("Su numero es par");
    } else {
        printf ("Su numero es impar");
    }





    return 0;
}