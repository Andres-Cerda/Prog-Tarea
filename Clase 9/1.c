#include <stdio.h>

int main(){

int numeros[100];

for(int i = 0; i < 100 ; i++)
{
    numeros[i]=i + 1 ;
    printf("%d \n", numeros[i]);
}

   return 0;
}