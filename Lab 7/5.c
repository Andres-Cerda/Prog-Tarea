#include <stdio.h>

int main(){

    int numero;
    int suma;

    printf("Buenas esta es la sumatoria de numeros positivos, en caso de que ingrese un negrativo se le entregara el resultado de la suma de los positivos y se apagara el programa\n\n");
    
    while(numero>=0){
    printf("Ingrese otro numero\n");
    scanf("%d", &numero);
    suma=suma+numero;
    }

  printf("El resultado final es: %d \n",suma);

return 0;

}