#include <stdio.h>

int numero;
int resultado;
int numero1=0;
int numero2=1;



int main(){
    printf(" Buenas a continuacion se mostrara el codigo Fibonacci\n");
    printf("ingrese numero por favor \n");
    scanf("%d", &numero);

    printf("0\n");

        for (int p = 0; p <= numero; p++)
        {
            resultado= numero1 + numero2;
            printf("%d\n",resultado);
            numero1=numero2;
            numero2=resultado;          
        }
        return 0;