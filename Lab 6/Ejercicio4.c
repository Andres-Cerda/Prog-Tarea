  
#include <stdio.h>

int main(){

    int edad , destino;
    
    printf("ingrese edad, por favor: \n");
    scanf("%i", &edad);
    
    if(edad < 15){  
        printf("Indique su destino: \n");
        scanf("%i", &destino);

          if (destino == 1){
             printf("El valor de su pasaje son 2.500$");
             
             } else if (destino == 2) { 
                 printf("El valor de su pasaje son 1.200$ \n");

             } else { 
                 printf("El valor de su pasaje son 2.000$");
             }
             
        } else if (edad >= 15 && edad <= 65 ){ 

              printf("Indique su destino: \n");
              scanf("%i", &destino);

                      if (destino == 1){

                         printf("El valor de su pasaje son 4.200$");
             
                           } else if (destino == 2) {

                             printf("El valor de su pasaje son 3.000$ ");

                                 } else {

                                   printf("El valor de su pasaje son 3.800$");}
             } else {  
                 
                 printf("Indique su destino: \n");
                 scanf("%i", &destino);

                      if (destino == 1){

                         printf("El valor de su pasaje son 3.000$");
             
                           } else if (destino == 2) {

                             printf("El valor de su pasaje son 2.000$ ");

                                 } else {

                                   printf("El valor de su pasaje son 2.500$");}
                                   
                                    }   
                                  
  
return 0;
}

        
        
       