#include <stdio.h>

int numero;
int suma;
int numero1=0;
int numero2=1;



int main(){
    printf(" Buenas a continuacion se mostrara el codigo Fibonacci\n");
    printf("ingrese numero por favor \n");
    scanf("%d", &numero);

    printf("0\n");

        for (int i = 0; i <= numero; i++)
        {
            suma= numero1 + numero2;
            printf("%d\n",suma);
            numero1=numero2;
            numero2=suma;          
        }
        return 0;