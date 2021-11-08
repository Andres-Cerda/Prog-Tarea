#include <stdio.h>

int main () {

/* Los codigos van en orden es decir el 101 es de las papas, el 102 es de los fideos, el 103 es del acite y el 104 es de la leche. */
int  producto [4] = {101,102,103,104};
int  precios[4] = {1000,500,1300,1000};
int  Cantidad_Sala[4] = {8,8,7,5};
int  Cantidad_Bodega[4] = {5,7,8,8};
int Total_Bodega_Sala;

long usuario_trabajador0 = 123456789;
long usuario_trabajador = 0; 
int  usuario_bloqueado = 0; 

char producto_1[6] = "Papas";
char producto_2[7] = "Fideos";
char producto_3[7] = "Aceite";
char producto_4[6] = "Leche";

long usuario_creado = 0;
long usuario_creado0 = 0;

int  opcion = 0;
int  menu = 0;
int  inventario = 0;
int  inventario_2 = 0;
int  compra = 0;
int  Total = 0;
int  Pago = 0;
int  Restante = 0; 

int compra_cancelada = 0;

int  codigo_productos_agregados = 0;
int  cantidad_productos_agregados = 0;

int  codigo_producto_robado = 0;
int  cantidad_productos_robados = 0;

int  codigo_producto_falla = 0;
int  cantidad_productos_fallados_sala = 0;
int  cantidad_productos_fallados_bodega = 0;

int  codigo_producto_vendido = 0;
int  vendidos = 0; 
int  cantidad_producto_vendido = 0;

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

                               printf ( "Clave incorrecta, usuario bloqueado");
                               usuario_bloqueado = 1;



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
             } else { 
                 printf("Se reiniciara el programa, hasta luego.");
                usuario_bloqueado = 1;
             }

        
         }
    break;

default : /* esta opcion es para limitar las opciones a 1 y 2 */
  
        printf("Numero no valido\n"); 
    
     break;

 /* el if de a continuacion es para que al momento de que la opcion ingresada no sea 1 o 2, no siga con las demas intrucciones 
 y solo se apague el programa*/          
} if (opcion == 1 && usuario_bloqueado == 0|| opcion == 2 && usuario_bloqueado == 0) {

    printf("-----------------------\n");
    printf("---------Menu----------\n");
    printf("-----------------------\n");
    printf("1) venta de producto\n");
    printf("2) editar inventario\n");
    printf("elija una de las dos opciones\n");
    scanf("%d", &menu); } 

    if(menu == 1 || menu == 2 ) {

        if(menu == 1 ){ 

            do
            {    
                printf("ingrese el codigo del producto quiere vender \n");
                scanf("%d", &codigo_producto_vendido);
                printf("ingrese la cantidad de existencias que quiere vender \n");
                scanf("%d", &cantidad_producto_vendido);
            if(producto[0] == codigo_producto_vendido){
                    if(Cantidad_Sala[0] >= cantidad_producto_vendido){ 
                        printf("El valor de ese articulo es %d \n", precios[0]);
                        printf("Se restaran %d existencias al producto %s \n", cantidad_producto_vendido, producto_1);
                        Cantidad_Sala[0] = Cantidad_Sala[0] - cantidad_producto_vendido;
                        Total = Total + (precios[0] * cantidad_producto_vendido);

                    } else { 
                        Total_Bodega_Sala = Cantidad_Sala[0] + Cantidad_Bodega[0];
                             if(Total_Bodega_Sala >= cantidad_producto_vendido ){
                             printf("Se restaran %d existencias que faltan en la sala al producto %s desde la bodega \n", cantidad_producto_vendido, producto_1);    
                             vendidos = cantidad_producto_vendido - Cantidad_Sala[0];
                             Cantidad_Sala[0] = Cantidad_Sala[0] - Cantidad_Sala[0];
                             Cantidad_Bodega[0] = Cantidad_Bodega[0] - vendidos;
                            printf("%d en sala y %d en bodega \n", Cantidad_Sala[0], Cantidad_Bodega[0]);
                            Total = Total + (precios[0] * cantidad_producto_vendido);
                        } else { printf("solo se pueden vender %d cantidad de existencias, ingrese un numero valido\n", Total_Bodega_Sala);
                        }

                    }

            }   else if (producto[1] == codigo_producto_vendido){
                 if(Cantidad_Sala[1] >= cantidad_producto_vendido){ 
                        printf("El valor de ese articulo es %d \n", precios[1]);
                        printf("Se restaran %d existencias al producto %s \n", cantidad_producto_vendido, producto_2);
                        Total = Total + (precios[1] * cantidad_producto_vendido);

                    }  else { 
                        Total_Bodega_Sala = Cantidad_Sala[1] + Cantidad_Bodega[1];
                             if(Total_Bodega_Sala >= cantidad_producto_vendido ){
                             printf("Se restaran %d existencias que faltan en la sala al producto %s desde la bodega \n", cantidad_producto_vendido, producto_2);    
                             vendidos = cantidad_producto_vendido - Cantidad_Sala[1];
                             Cantidad_Sala[1] = Cantidad_Sala[1] - Cantidad_Sala[1];
                             Cantidad_Bodega[1] = Cantidad_Bodega[1] - vendidos;
                            printf("%d en sala y %d en bodega \n", Cantidad_Sala[1], Cantidad_Bodega[1]);
                            Total = Total + (precios[1] * cantidad_producto_vendido);
                        } else { printf("solo se pueden vender %d cantidad de existencias, ingrese un numero valido\n", Total_Bodega_Sala);
                        }

                    }

            }  else if (producto[2] == codigo_producto_vendido){
                if(Cantidad_Sala[2] >= cantidad_producto_vendido){ 
                        printf("El valor de ese articulo es %d \n", precios[2]);
                        printf("Se restaran %d existencias al producto %s \n", cantidad_producto_vendido, producto_3);
                        Total = Total + (precios[2] * cantidad_producto_vendido);

                    }  else { 
                        Total_Bodega_Sala = Cantidad_Sala[2] + Cantidad_Bodega[2];
                             if(Total_Bodega_Sala >= cantidad_producto_vendido ){
                             printf("Se restaran %d existencias que faltan en la sala al producto %s desde la bodega \n", cantidad_producto_vendido, producto_3);    
                             vendidos = cantidad_producto_vendido - Cantidad_Sala[2];
                             Cantidad_Sala[2] = Cantidad_Sala[2] - Cantidad_Sala[2];
                             Cantidad_Bodega[2] = Cantidad_Bodega[2] - vendidos;
                            printf("%d en sala y %d en bodega \n", Cantidad_Sala[2], Cantidad_Bodega[2]);
                            Total = Total + (precios[2] * cantidad_producto_vendido);
                        } else { printf("solo se pueden vender %d cantidad de existencias, ingrese un numero valido\n", Total_Bodega_Sala);
                        }

                    }

            } else if (producto[3] == codigo_producto_vendido){
               if(Cantidad_Sala[3] >= cantidad_producto_vendido){ 
                        printf("El valor de ese articulo es %d \n", precios[3]);
                        printf("Se restaran %d existencias al producto %s \n", cantidad_producto_vendido, producto_4);
                        Total = Total + (precios[3] * cantidad_producto_vendido);

                    } else { 
                        Total_Bodega_Sala = Cantidad_Sala[3] + Cantidad_Bodega[3];
                             if(Total_Bodega_Sala >= cantidad_producto_vendido ){
                             printf("Se restaran %d existencias que faltan en la sala al producto %s desde la bodega \n", cantidad_producto_vendido, producto_4);    
                             vendidos = cantidad_producto_vendido - Cantidad_Sala[3];
                             Cantidad_Sala[3] = Cantidad_Sala[3] - Cantidad_Sala[3];
                             Cantidad_Bodega[3] = Cantidad_Bodega[3] - vendidos;
                            printf("%d en sala y %d en bodega \n", Cantidad_Sala[3], Cantidad_Bodega[3]);
                            Total = Total + (precios[3] * cantidad_producto_vendido);
                        } else { printf("solo se pueden vender %d cantidad de existencias, ingrese un numero valido\n", Total_Bodega_Sala);
                        }

                    }

            } else { printf("ingrese un codigo valido\n"); }
            
            if(producto[0] == codigo_producto_vendido 
            || producto[1] == codigo_producto_vendido 
            || producto[2] == codigo_producto_vendido
            || producto[3] == codigo_producto_vendido ){

                  printf ("¿Ingresara otro productos?\n");
                  printf("1) Si \n 2) No\n");
                  scanf("%d", &compra);
                  
                  } else { if ( codigo_producto_vendido != 101 
                            || codigo_producto_vendido != 102 
                            || codigo_producto_vendido != 103 
                            || codigo_producto_vendido != 104)
                    
                  {
                     printf("El codigo no esta validado, coloque uno que lo este\n");
                  } else { if( compra == 2) 
                           compra = 2;
                           break;   }}
                  
                            
            
            printf("$%d es el total de la compra \n", Total);

                
            } while (compra == 1);

            printf("Ingrese el efectivo entregado a continuacion\n");
            scanf("%d", &Pago);

            if(Total == Pago ){

                printf("Dado que el pago fue exacto, el vuelto sera $0\n");
                printf("Gracias por su compra, hasta luego.\n");
            } else if (Total > Pago)
            {
                printf("le faltan $%d \n", Total-Pago);
                printf("Si desea cancelar la compra ingrese 1, si desea agregar lo que falta ingrese 2.\n");
                scanf("%d", &compra_cancelada);
                
                if(compra_cancelada == 2){
                printf("En caso de que falte efectivo por segunda vez se cancelara la compra\n");    
                printf("Ingrese el efectivo restante.\n");    
                scanf("%d", &Restante);
              
                  if(Total == Pago + Restante){
                      printf("Muchas gracias por la compra, hasta luego.\n");
                      } else if (Total > (Pago + Restante)){ 
                          printf("Dado que por segunda vez falta, se cancelara la compra\n");
                      } else{ 
                          printf("Su vuelto es %d, hasta luego\n", (Pago + Restante)- Total);}
                      
                } else {printf("Muchas gracias por su visita, hasta luego\n");}

            } else {
                
                printf("Su vuelto es $%d, hasta luego.\n", Pago-Total); }
             


            
            
 
     }

           else if(menu == 2){

             printf("Ingrese numero 1 si desea ingresar productos y numero 2 si desea descontarlos\n");
             scanf("%d", &inventario);

            if (inventario == 1 ) {

                     int  codigo_productos_agregados;
                     int  cantidad_productos_agregados;

                     printf("Ingrese el codigo del producto que quiere agregar\n");
                     scanf("%d", &codigo_productos_agregados);
                     printf("Ingrese la cantidad de productos que quiere agregar\n");
                     scanf("%d", &cantidad_productos_agregados);

                     if (producto[0] == codigo_productos_agregados)
                     {
                          printf("Se agregaron %d existencias al producto %s \n", cantidad_productos_agregados, producto_1 );
                          Cantidad_Bodega[0]= Cantidad_Bodega[0] + cantidad_productos_agregados;
                          printf("El almacen a sido actualizado correctamente \n");
                        
                     
                     } else if (producto[1] == codigo_productos_agregados){
                         
                         printf("Se agregaron %d existencias al producto %s \n", cantidad_productos_agregados, producto_2 );
                        Cantidad_Bodega[1]= Cantidad_Bodega[1] + cantidad_productos_agregados;
                        printf("El almacen a sido actualizado correctamente \n");


                     }else if (producto[2] == codigo_productos_agregados){
                         
                         printf("Se agregaron %d existencias al producto %s \n", cantidad_productos_agregados, producto_3 );
                         Cantidad_Bodega[2]= Cantidad_Bodega[2] + cantidad_productos_agregados;
                         printf("El almacen a sido actualizado correctamente \n");
                     
                     }else if (producto[3] == codigo_productos_agregados){
                         
                         printf("Se agregaron %d existencias al producto %s \n", cantidad_productos_agregados, producto_4 );
                         Cantidad_Bodega[3]= Cantidad_Bodega[3] + cantidad_productos_agregados;
                         printf("El almacen a sido actualizado correctamente \n");
                     
                     } else {  printf("El codigo ingresado no es correcto"); }


        } else if (inventario == 2) { 
            
            printf("A continuacion le apareceran las causas por las que se descuentas los productos, eliga una por favor\n");
            printf("1)Hurto\n 2)Fallo\n 3)introduzca el codigo y le diremos si fue vendido recientemente\n");
            scanf("%d", &inventario_2);

            switch (inventario_2)
            {        

            
            case 1 : 
                     
                     printf("Escriba el codigo del producto que robaron, por favor\n");
                     scanf("%d", &codigo_producto_robado);
                     printf("Indique cual fue la cantidad sustraida\n");
                     scanf("%d", &cantidad_productos_robados);

                     if (producto[0] == codigo_producto_robado) {

                          printf("Se restaran %d existencias del producto %s \n", cantidad_productos_robados, producto_1 );
                          if( Cantidad_Sala[0] >= cantidad_productos_robados)
                          {
                          Cantidad_Sala[0]= Cantidad_Sala[0] - cantidad_productos_robados;
                          printf("El almacen a sido actualizado correctamente \n");
                          printf("%d existencias totales del producto %s", Cantidad_Sala[0], producto_1);

                          } else { printf("No habian tantas existecias del producto %s en sala \n", producto_1);}
                        
                     
                   } else if (producto[1] == codigo_producto_robado){
                         
                         printf("Se restaran %d existencias del producto %s \n", cantidad_productos_robados, producto_2 );
                         if(Cantidad_Sala[1] >= cantidad_productos_robados )
                         {
                        Cantidad_Sala[1]= Cantidad_Sala[1] - cantidad_productos_robados;
                        printf("El almacen a sido actualizado correctamente \n");
                        printf("%d existencias totales del producto %s", Cantidad_Sala[1], producto_2);

                        } else { printf("No habian tantas existecias del producto %s en sala\n", producto_2);}


                   } else if (producto[2] == codigo_producto_robado){
                         
                         printf("Se restaran %d existencias del producto %s \n", cantidad_productos_robados, producto_3 );
                         if(Cantidad_Sala[2] >= cantidad_productos_robados)
                         {
                         Cantidad_Bodega[2]= Cantidad_Sala[2] - cantidad_productos_robados;
                         printf("El almacen a sido actualizado correctamente \n");
                         printf("%d existencias totales del producto %s", Cantidad_Sala[2], producto_3);

                         } else { printf("No habian tantas existecias del producto %s en sala\n", producto_3);}
                     
                   } else if (producto[3] == codigo_producto_robado ){
                         
                         printf("Se restaran %d existencias del producto %s \n", cantidad_productos_robados, producto_4 );
                         if(Cantidad_Sala[3] >= cantidad_productos_robados)
                         {
                         Cantidad_Sala[3]= Cantidad_Sala[3] - cantidad_productos_robados;
                         printf("El almacen a sido actualizado correctamente \n");
                         printf("%d existencias totales del producto %s", Cantidad_Sala[3], producto_4);

                         } else { printf("No habian tantas existecias del producto %s en sala\n", producto_4);}
                     
                   } else {  printf("El codigo ingresado no es correcto"); }

                    
                break;
            
            case 2:  
            
                     printf("Escriba el codigo del producto que tiene una falla o se ha vencido, por favor\n");
                     scanf("%d", &codigo_producto_falla);
                     printf("Indique cuantos productos fallaron en Bodega\n");
                     scanf("%d", &cantidad_productos_fallados_bodega);
                     printf("Indique cuantos productos fallaron en Sala\n");
                     scanf("%d", &cantidad_productos_fallados_sala);

                     if (producto[0] == codigo_producto_falla)
                        {
                         if(cantidad_productos_fallados_bodega != 0){ 
                             if (Cantidad_Bodega[0] >= cantidad_productos_fallados_bodega) { 
                             printf("Se restaran %d cantidad de existencias al productos %s en Bodega\n",
                             cantidad_productos_fallados_bodega, producto_1);
                             Cantidad_Bodega[0]= Cantidad_Bodega[0] - cantidad_productos_fallados_bodega;
                             printf("El almacen a sido actualizado correctamente \n"); 
                             printf("%d cantidad de %s \n",Cantidad_Bodega[0], producto_1);
                             } else { printf("No habian tantas existencias del producto %s en Bodega, introduzca un numero valido\n", producto_1); 
                                      printf("Tenga en cuenta que hay %d existencias en Bodega", Cantidad_Bodega[0]);}

                         } if (cantidad_productos_fallados_sala != 0) {
                             if (Cantidad_Sala[0] >= cantidad_productos_fallados_sala) { 
                             printf("Se restaran %d cantidad de existencias al productos %s en Sala\n",
                             cantidad_productos_fallados_sala, producto_1);
                             Cantidad_Sala[0]= Cantidad_Sala[0] - cantidad_productos_fallados_sala;
                             printf("El almacen a sido actualizado correctamente \n");
                             printf("%d cantidad de %s \n",Cantidad_Sala[0], producto_1);
                             } else { printf("No habian tantas existencias del producto %s en Sala, introduzca un numero valido\n", producto_1); 
                                      printf("Tenga en cuenta que hay %d existencias en Sala", Cantidad_Sala[0]); } }
                             
                    } else if (producto[1] == codigo_producto_falla) {
                         if(cantidad_productos_fallados_bodega != 0){ 
                             if (Cantidad_Bodega[1] >= cantidad_productos_fallados_bodega) { 
                             printf("Se restaran %d cantidad de existencias al productos %s en Bodega\n",
                             cantidad_productos_fallados_bodega, producto_2);
                             Cantidad_Bodega[1]= Cantidad_Bodega[1] - cantidad_productos_fallados_bodega;
                             printf("El almacen a sido actualizado correctamente \n"); 
                             printf("%d cantidad de %s \n",Cantidad_Bodega[1], producto_2);
                             } else { printf("No habian tantas existencias del producto %s en Bodega, introduzca un numero valido\n", producto_2); 
                                      printf("Tenga en cuenta que hay %d existencias en Bodega", Cantidad_Bodega[1]);}

                         } if (cantidad_productos_fallados_sala != 0) {
                             if (Cantidad_Sala[1] >= cantidad_productos_fallados_sala) { 
                             printf("Se restaran %d cantidad de existencias al productos %s en Sala\n",
                             cantidad_productos_fallados_sala, producto_2);
                             Cantidad_Sala[1]= Cantidad_Sala[1] - cantidad_productos_fallados_sala;
                             printf("El almacen a sido actualizado correctamente \n");
                             printf("%d cantidad de %s \n",Cantidad_Sala[1], producto_1);
                             } else { printf("No habian tantas existencias del producto %s en Sala, introduzca un numero valido\n", producto_2);  
                                      printf("Tenga en cuenta que hay %d existencias en Sala", Cantidad_Sala[1]);} }
                             
                    } else if (producto[2] == codigo_producto_falla)
                        {
                         if(cantidad_productos_fallados_bodega != 0){ 
                             if (Cantidad_Bodega[2] >= cantidad_productos_fallados_bodega) { 
                             printf("Se restaran %d cantidad de existencias al productos %s en Bodega\n",
                             cantidad_productos_fallados_bodega, producto_3);
                             Cantidad_Bodega[2]= Cantidad_Bodega[2] - cantidad_productos_fallados_bodega;
                             printf("El almacen a sido actualizado correctamente \n"); 
                             printf("%d cantidad de %s \n",Cantidad_Bodega[2], producto_3);
                             } else { printf("No habian tantas existencias del producto %s en Bodega, introduzca un numero valido\n", producto_3); 
                                      printf("Tenga en cuenta que hay %d existencias en Bodega", Cantidad_Bodega[2]);
                                      }

                         } if (cantidad_productos_fallados_sala != 0) {
                             if (Cantidad_Sala[2] >= cantidad_productos_fallados_sala) { 
                             printf("Se restaran %d cantidad de existencias al productos %s en Sala\n",
                             cantidad_productos_fallados_sala, producto_3);
                             Cantidad_Sala[2]= Cantidad_Sala[2] - cantidad_productos_fallados_sala;
                             printf("El almacen a sido actualizado correctamente \n");
                             printf("%d cantidad de %s \n",Cantidad_Sala[2], producto_3);
                             } else { printf("No habian tantas existencias del producto %s en Sala, introduzca un numero valido\n", producto_3);  
                                      printf("Tenga en cuenta que hay %d existencias en Sala", Cantidad_Sala[2]); } }
                             
                    } else if (producto[3] == codigo_producto_falla)
                        {
                         if(cantidad_productos_fallados_bodega != 0){ 
                             if (Cantidad_Bodega[3] >= cantidad_productos_fallados_bodega) { 
                             printf("Se restaran %d cantidad de existencias al productos %s en Bodega\n",
                             cantidad_productos_fallados_bodega, producto_4);
                             Cantidad_Bodega[3]= Cantidad_Bodega[3] - cantidad_productos_fallados_bodega;
                             printf("El almacen a sido actualizado correctamente \n"); 
                             printf("%d cantidad de %s \n",Cantidad_Bodega[3], producto_4);
                             } else { printf("No habian tantas existencias del producto %s en Bodega, introduzca un numero valido\n", producto_4); 
                                      printf("Tenga en cuenta que hay %d existencias en Bodega", Cantidad_Bodega[3]);
                                      } 

                         } if (cantidad_productos_fallados_sala != 0) {
                             if (Cantidad_Sala[3] >= cantidad_productos_fallados_sala) { 
                             printf("Se restaran %d cantidad de existencias al productos %s en Sala\n",
                             cantidad_productos_fallados_sala, producto_4);
                             Cantidad_Sala[3]= Cantidad_Sala[3] - cantidad_productos_fallados_sala;
                             printf("El almacen a sido actualizado correctamente \n");
                             printf("%d cantidad de %s \n",Cantidad_Sala[3], producto_4);
                             } else { printf("No habian tantas existencias del producto %s en Sala, introduzca un numero valido\n", producto_4);  
                                      printf("Tenga en cuenta que hay %d existencias en Sala", Cantidad_Sala[3]);} }


                    } else { printf("El codigo ingresado es erroneo.\n"); }

                          
                        break;


            default: printf("Ingrese una opcion valida.");
                break;
                
                }  
            


        } else {printf("ingrese una opcion valida."); }



    } else {  printf("ingrese una opcion valida.");}
    
} 
           
    
    

return 0;
} 

