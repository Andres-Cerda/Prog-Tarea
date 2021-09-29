#include <stdio.h>

int main(){

    /* se muestra una descripcion del programa */

    printf(" Si no recuerda que caracte de código ASCII es el que tienes, escribalo y nosotros se lo daremos");

    char caracter; 

    printf(" Escriba su caracter para que se lo demos en codigo ASCII: ");
    scanf("%c", &caracter);

    printf(" El formato en codigo ASCII de %c es %i ", caracter, caracter);

    return 0; 
    }


    