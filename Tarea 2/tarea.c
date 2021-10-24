#include <stdio.h>

int main () {


int  Sala = 20;
int  Bodega = 68;
int producto = 0;
long usuario_trabajador0 = 214275721;
long usuario_trabajador = 0;  
long usuario_creado = 0;
long usuario_creado0 = 0;
int opcion = 0;
int menu = 0;
printf ("El Programa ha sido encendido\n");
printf ("Hola bienvenido al sistema regulador de mercaderia\n");


printf ("En caso de tener usuario ingrese el numero 1 \nSi no tiene y desea uno, ingrese el numero 2\n");
scanf("%d",&opcion);

/* Se le pedira al usuario que ingrese una opcion, que en este caso serian 1 o 2 para que la funcion "switch" la lea */

switch (opcion)

{
case 1 : /* a continuacion se hara una estructura if para que cuando ingrese el usuario le diga si es correcto, 
        en caso de no serlo se dira que es incorrecto y que le queda cierta cantidad de intentos hasta que se bloquee */
         printf("Ingrese su usuario, por favor\n");
         scanf("%lu", &usuario_trabajador);
         
          if (usuario_trabajador0 == usuario_trabajador ) {

            printf( "Usuario ingresado correctamente, Bienvenido\n\n");

              }  else {

                printf("Clave incorrecta\n");
                printf("dos intentos restantes\n");
                printf("Por favor ingrese nuevamente su usuario:\n ");
                scanf("%lu", &usuario_trabajador);
    
                    if (usuario_trabajador0 == usuario_trabajador){

                      printf("Usuario ingresado correctamente, Bienvenido\n\n");
                
                         } else { 

                          printf("Clave incorrecta\n");
                          printf("Recuerde que la clave es el rut con el digito verificador pero sin guion\n");
                          printf("un intentos restantes\n");
                          printf("Por favor ingrese nuevamente su usuario: \n");
                          scanf("%lu", &usuario_trabajador);  

                            if(usuario_trabajador0 == usuario_trabajador){ 

                             printf("Usuario ingresado correctamente, Bienvenido\n\n");

                             } else {  

                               printf ( "Clave incorrecta, usuario bloquedo");



                                  }


                


                }
   }
         
         
    
    break;

case 2 : /* aqui lo que se desea es crear el usuario, entonces se le pedira el rut sin guion y se le dara un valor, 
          para comprobar que no se equivoque se le pedira de nuevo pero ese valor se le asignara a otra variable para poder comparar */

         printf("Escriba su rut con digito verificador pero sin guion para crear su usuario\n");
         scanf("%lu", &usuario_creado );
         printf("Usuario creado exitosamente\n");
         printf("Ingrese su usuario, por favor\n");
         scanf("%lu", &usuario_creado0);
         
         if (usuario_creado == usuario_creado0 ){ 
             printf("Usuario ingresado correctamente\n\n");
         
         } else {
             printf("recuerde que el usuario ingresado es %lu\n", usuario_creado);
             printf("Ingrese nuevamente su usuario, por favor\n");
             scanf("%lu", &usuario_creado0);
             
             if(usuario_creado == usuario_creado0){
                 printf("Usuario ingresado correctamente\n\n");
             } else {
                 printf("Dado que no puede ingresar correctamente el usuario creado el programa se apagara\n");
             }

        
         }
    break;

default : /* esta opcion es para limitar las opciones a 1 y 2 */
  
        printf(" numero no valido\n"); 
    
     break;

 /* el if de a continuacion es para que al momento de que la opcion ingresada no sea 1 o 2, no siga con las demas intrucciones 
 y solo se apague el programa*/          
} if (opcion == 1 || opcion == 2) {

    printf("-----------------------\n");
    printf("---------Menu----------\n");
    printf("-----------------------\n");
    printf("1) venta de producto\n");
    printf("2) editar inventario\n");
    printf("elija una de las dos opciones\n");
    scanf("%d", &menu); 
    
    switch (menu)
    {
    case 1: printf("venta de producto");
             
        break;

    case 2: printf("editar inventario");

        break;
            

    default: printf("hola mundo gaturro");
        break;
    }

}


return 0;
} 

