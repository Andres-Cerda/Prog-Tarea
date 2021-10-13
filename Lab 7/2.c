#include <stdio.h>

int main(){

    int num1;
    int num2;
    int num3= 0;

    printf("Escriba un numero, por favor\n");
    scanf ("%d", &num1);
    printf("Escriba otro numero\n");
    scanf("%d", &num2);

    for (int i = 0; i < num2 ; i++)
    {
       
       num3 = num3 + num1;
        
    } 

    printf ("El resultado de su multiplicacion es %d", num3);
    




    return 0 ;
}