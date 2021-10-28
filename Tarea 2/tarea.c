#include <stdio.h>

int main () {


int  Sala [4] = {101,102,103,103};
int  Cantidad_Sala[4]={8,8,7,5};

int  Bodega[4]= {101,102,103,104};
int  Cantidad_Bodega[4]= {5,7,8,8};

long usuario_trabajador0 = 123456789;
long usuario_trabajador = 0; 

long usuario_creado = 0;
long usuario_creado0 = 0;

int  opcion = 0;
int  menu = 0;
int  inventario = 0;
int  produtos_agregados = 0;

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
                printf("Dos intentos restantes\n");
                printf("Por favor ingrese nuevamente su usuario:\n ");
                scanf("%lu", &usuario_trabajador);
    
                    if (usuario_trabajador0 == usuario_trabajador){

                      printf("Usuario ingresado correctamente, Bienvenido\n\n");
                
                         } else { 

                          printf("Clave incorrecta\n");
                          printf("Recuerde que la clave es el rut con el digito verificador pero sin guion\n");
                          printf("Un intentos restantes\n");
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
             printf("Recuerde que el usuario ingresado es %lu\n", usuario_creado);
             printf("Ingrese nuevamente su usuario, por favor\n");
             scanf("%lu", &usuario_creado0);
             
             if(usuario_creado == usuario_creado0){
                 printf("Usuario ingresado correctamente\n\n");
             }

        
         }
    break;

default : /* esta opcion es para limitar las opciones a 1 y 2 */
  
        printf("Numero no valido\n"); 
    
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
    case 1: printf("Venta de producto\n\n");
             
        break;

    case 2: printf("Ingrese 1 si quiere agregar mas productos y en caso de querer descontar, ingrese 2\n\n");
            scanf("%d", &inventario);
    
    
        switch (inventario)
    {
            case 1 : printf("Ingrese la cantidad de productos que quiere agregar\n");
                     scanf("%d", &produtos_agregados);
                     Bodega = Bodega + produtos_agregados; 
                     printf("Se a actualizado la bodega correctamente");
                     printf("En bodega hay %d productos\n", Bodega);
                     printf("Se finalizan los cambios en el inventario");
            break;
    
            case 2 : 

             break;
    }
    

        break;
            

    default: printf("hola mundo ");
        break;
    }

}


return 0;
} 

