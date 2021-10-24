#include <stdio.h>

int main () {


int  Sala =20;
int  Bodega =68;
int producto =0;
long usuario_trabajador0 =214275721;
long usuario_trabajador =0;  
long usuario_creado =0;
long usuario_creado0 =0;
int opcion=0;
printf ("El Programa ha sido encendido\n");
printf ("Hola bienvenido al sistema regulador de mercaderia\n");


printf ("En caso de tener usuario ingrese el numero 1 \nSi no tiene y desea uno, ingrese el numero 2\n");
scanf("%d",&opcion);

switch (opcion)
{
case 1 : printf("Ingrese su usuario, por favor\n");
         scanf("%lu", &usuario_trabajador);
         
          if (usuario_trabajador0 == usuario_trabajador ) {

            printf( "Usuario ingresado correctamente, Bienvenido");

              }  else {

                printf("Clave incorrecta\n");
                printf("dos intentos restantes\n");
                printf("Por favor ingrese nuevamente su usuario:\n ");
                scanf("%lu", &usuario_trabajador);
    
                    if (usuario_trabajador0 == usuario_trabajador){

                      printf("Usuario ingresado correctamente, Bienvenido\n");
                
                         } else { 

                          printf("Clave incorrecta\n");
                          printf("Recuerde que la clave es el rut con el digito verificador pero sin guion\n");
                          printf("un intentos restantes\n");
                          printf("Por favor ingrese nuevamente su usuario: \n");
                          scanf("%lu", &usuario_trabajador);  

                            if(usuario_trabajador0 == usuario_trabajador){ 

                             printf("Usuario ingresado correctamente, Bienvenido");

                             } else {  

                               printf ( "Clave incorrecta, usuario bloquedo");



                                  }


                


                }
   }
         
         
    
    break;

case 2 : printf("Escriba su rut con digito verificador pero sin guion para crear su usuario\n");
         scanf("%lu", &usuario_creado );
         printf("Usuario creado exitosamente\n");
         printf("Ingrese su usuario, por favor\n");
         scanf("%lu", &usuario_creado0);
         
         if (usuario_creado == usuario_creado0 ){ 
             printf("Usuario ingresado correctamente\n");
         
         } else {
             printf("recuerde que el usuario ingresado es %lu\n", usuario_creado);
             printf("Ingrese nuevamente su usuario, por favor\n");
             scanf("%lu", &usuario_creado0);
             
             if(usuario_creado == usuario_creado0){
                 printf("Usuario ingresado correctamente\n");
             } else {
                 printf("Dado que no puede ingresar correctamente el usuario creado el programa se apagara\n");
             }

        
         }
    break;

default : printf(" numero no valido\n"); 
    
     break;
           
} 


return 0;
} 
