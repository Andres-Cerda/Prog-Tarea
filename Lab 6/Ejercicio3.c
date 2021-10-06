#include <stdio.h>

int main(){

    int clave = 21213041;

    printf("Bienvenido, a continuacion es escriba su clave de acceso: \n");
    
    scanf("%i", &clave);

    switch(clave){
        
        case 21213041: printf("Felicidades, has ingresado correctamente la clave.\n");
                       break;
        case 2: printf ("recuerde que su clave es su RUT sin el digito verificador\n");
                       break;
        case 3: printf (" Le quedan dos intentos")                              

        defaul: printf( "No era su clave");

    }

 
    return 0;
}