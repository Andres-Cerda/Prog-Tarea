#include <stdio.h>

int main(){

   long clave = 21213041;
   long clave_ingresada = 0;

   printf("Bienvenido, ingrese su clave a continuacion: \n\n");
   scanf("%lu", &clave_ingresada);

   if (clave_ingresada == clave) {

       printf( "Clave ingresada correctamente, Bienvenido");

   }  else {

        printf("Clave incorrecta\n");
        printf("dos intentos restantes\n");
         printf("Por favor ingrese nuevamente su clave:\n ");
        scanf("%lu", &clave_ingresada);
    
          if (clave_ingresada == clave){

             printf("Clave ingresada correctamente, Bienvenido\n");
                
                } else { 

                    printf("Clave incorrecta\n");
                    printf("Recuerde que la clave es el rut sin el digito verificador\n");
                    printf("un intentos restantes\n");
                     printf("Por favor ingrese nuevamente su clave: \n");
                    scanf("%lu", &clave_ingresada);  

                       if(clave_ingresada == clave){ 

                            printf("Clave ingresada correctamente, Bienvenido");

                           } else {  

                               printf ( "Clave incorrecta, usuario bloquedo");



                                  }


                


                }
   }

            



       
   



 
    return 0;
}