/* Universidad de La Frontera
* Departamento de Ingeniería Eléctrica
*
* ICC-202 PROGRAMACION DE COMPUTADORES
*
* Tarea 2
*
* Autores: 
* Cristobal Pincheira. (c.pincheira07@ufromail.cl)
* Nely Castro (desaparecida en combate)
* Andrés Cerda. (a.cerda07@ufromail.cl)
*
* Fecha: 09/11/2021
*
* Programa dedicado a regular la mercancia que llega al local y tambien se encarga de descontarlo en caso de que fuera hurtado o haya 
fallado. 
*/
#include <stdio.h>

int main () {

/* Los codigos van en orden es decir el 101 es de las papas, el 102 es de los fideos, el 103 es del acite y el 104 es de la leche. */
int  PRODUCTO [4] = {101,102,103,104};
int  PRECIOS [4] = {1000,500,1300,1000};
int  CANTIDAD_SALA [4] = {8,8,7,5};
int  CANTIDAD_BODEGA [4] = {5,7,8,8};
int  Total_Bodega_Sala = 0;

long USUARIO_TRABAJADOR_ENTREGADO = 123456789;
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

int  compra_cancelada = 0;

int  codigo_productos_agregados = 0;
int  cantidad_productos_agregados = 0;
int  Otro_producto = 0;

int  codigo_producto_robado = 0;
int  cantidad_productos_robados = 0;
int  Otro_producto_robado = 0;

int  codigo_producto_falla = 0;
int  cantidad_productos_fallados_sala = 0;
int  cantidad_productos_fallados_bodega = 0;
int  Otro_producto_fallado = 0;

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
         
          if (USUARIO_TRABAJADOR_ENTREGADO == usuario_trabajador ) {

            printf( "Usuario ingresado correctamente, Bienvenido\n\n");

              }  else {

                printf("Clave incorrecta\n");
                printf("Dos intentos restantes\n");
                printf("Por favor ingrese nuevamente su usuario:\n ");
                scanf("%lu", &usuario_trabajador);
    
                    if (USUARIO_TRABAJADOR_ENTREGADO == usuario_trabajador){

                      printf("Usuario ingresado correctamente, Bienvenido\n\n");
                
                         } else { 

                          printf("Clave incorrecta\n");
                          printf("Recuerde que la clave es el rut con el digito verificador pero sin guion\n");
                          printf("Un intentos restantes\n");
                          printf("Por favor ingrese nuevamente su usuario: \n");
                          scanf("%lu", &usuario_trabajador);  

                            if(USUARIO_TRABAJADOR_ENTREGADO == usuario_trabajador){ 

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
  /* es if de a continuacion es para dar la opciones del menu*/
    if(menu == 1 || menu == 2 ) {

        if(menu == 1 ){ 
         /* el menu 1 seria venta. Se pide el codigo y la cantidad para asi ver si queda en sala y en caso de que no quede 
            se busca en bodega. Si en aun con los dos almacenamientos no alcanza se le dice que solo hay X cantidad y que no puede
            pedir mas. Se repite cuatro veces ya que hay cuatro productos*/
            do
            /* el siguiente do-while es para el momento en que se quieran agregar mas productos*/
            {    
                printf("ingrese el codigo del producto quiere vender \n");
                scanf("%d", &codigo_producto_vendido);
                printf("ingrese la cantidad de existencias que quiere vender \n");
                scanf("%d", &cantidad_producto_vendido);

                /*al momento de agregar un producto se dira el precio y se restaran las existencias de la sala o bodega
                  luego se iran sumando los precios para dar un total y asi pueda pagar*/
            if(PRODUCTO[0] == codigo_producto_vendido){
                    if(CANTIDAD_SALA[0] >= cantidad_producto_vendido){ 
                        printf("El valor de ese articulo es %d \n", PRECIOS[0]);
                        printf("Se restaran %d existencias al producto %s \n", cantidad_producto_vendido, producto_1);
                        CANTIDAD_SALA[0] = CANTIDAD_SALA[0] - cantidad_producto_vendido;
                        Total = Total + (PRECIOS[0] * cantidad_producto_vendido);

                    } else { 
                        Total_Bodega_Sala = CANTIDAD_SALA[0] + CANTIDAD_BODEGA[0];
                             if(Total_Bodega_Sala >= cantidad_producto_vendido ){
                             printf("Se restaran %d existencias que faltan en la sala al producto %s desde la bodega \n", cantidad_producto_vendido, producto_1);    
                             vendidos = cantidad_producto_vendido - CANTIDAD_SALA[0];
                             CANTIDAD_SALA[0] = CANTIDAD_SALA[0] - CANTIDAD_SALA[0];
                             CANTIDAD_BODEGA[0] = CANTIDAD_BODEGA[0] - vendidos;
                            printf("%d en sala y %d en bodega \n", CANTIDAD_SALA[0], CANTIDAD_BODEGA[0]);
                            Total = Total + (PRECIOS[0] * cantidad_producto_vendido);
                        } else { printf("solo se pueden vender %d cantidad de existencias, ingrese un numero valido\n", Total_Bodega_Sala);
                        }

                    }

            }   else if (PRODUCTO[1] == codigo_producto_vendido){
                 if(CANTIDAD_SALA[1] >= cantidad_producto_vendido){ 
                        printf("El valor de ese articulo es %d \n", PRECIOS[1]);
                        printf("Se restaran %d existencias al producto %s \n", cantidad_producto_vendido, producto_2);
                        Total = Total + (PRECIOS[1] * cantidad_producto_vendido);

                    }  else { 
                        Total_Bodega_Sala = CANTIDAD_SALA[1] + CANTIDAD_BODEGA[1];
                             if(Total_Bodega_Sala >= cantidad_producto_vendido ){
                             printf("Se restaran %d existencias que faltan en la sala al producto %s desde la bodega \n", cantidad_producto_vendido, producto_2);    
                             vendidos = cantidad_producto_vendido - CANTIDAD_SALA[1];
                             CANTIDAD_SALA[1] = CANTIDAD_SALA[1] - CANTIDAD_SALA[1];
                             CANTIDAD_BODEGA[1] = CANTIDAD_BODEGA[1] - vendidos;
                            printf("%d en sala y %d en bodega \n", CANTIDAD_SALA[1], CANTIDAD_BODEGA[1]);
                            Total = Total + (PRECIOS[1] * cantidad_producto_vendido);
                        } else { printf("solo se pueden vender %d cantidad de existencias, ingrese un numero valido\n", Total_Bodega_Sala);
                        }

                    }

            }  else if (PRODUCTO[2] == codigo_producto_vendido){
                if(CANTIDAD_SALA[2] >= cantidad_producto_vendido){ 
                        printf("El valor de ese articulo es %d \n", PRECIOS[2]);
                        printf("Se restaran %d existencias al producto %s \n", cantidad_producto_vendido, producto_3);
                        Total = Total + (PRECIOS[2] * cantidad_producto_vendido);

                    }  else { 
                        Total_Bodega_Sala = CANTIDAD_SALA[2] + CANTIDAD_BODEGA[2];
                             if(Total_Bodega_Sala >= cantidad_producto_vendido ){
                             printf("Se restaran %d existencias que faltan en la sala al producto %s desde la bodega \n", cantidad_producto_vendido, producto_3);    
                             vendidos = cantidad_producto_vendido - CANTIDAD_SALA[2];
                             CANTIDAD_SALA[2] = CANTIDAD_SALA[2] - CANTIDAD_SALA[2];
                             CANTIDAD_BODEGA[2] = CANTIDAD_BODEGA[2] - vendidos;
                            printf("%d en sala y %d en bodega \n", CANTIDAD_SALA[2], CANTIDAD_BODEGA[2]);
                            Total = Total + (PRECIOS[2] * cantidad_producto_vendido);
                        } else { printf("solo se pueden vender %d cantidad de existencias, ingrese un numero valido\n", Total_Bodega_Sala);
                        }

                    }

            } else if (PRODUCTO[3] == codigo_producto_vendido){
               if(CANTIDAD_SALA[3] >= cantidad_producto_vendido){ 
                        printf("El valor de ese articulo es %d \n", PRECIOS[3]);
                        printf("Se restaran %d existencias al producto %s \n", cantidad_producto_vendido, producto_4);
                        Total = Total + (PRECIOS[3] * cantidad_producto_vendido);

                    } else { 
                        Total_Bodega_Sala = CANTIDAD_SALA[3] + CANTIDAD_BODEGA[3];
                             if(Total_Bodega_Sala >= cantidad_producto_vendido ){
                             printf("Se restaran %d existencias que faltan en la sala al producto %s desde la bodega \n", cantidad_producto_vendido, producto_4);    
                             vendidos = cantidad_producto_vendido - CANTIDAD_SALA[3];
                             CANTIDAD_SALA[3] = CANTIDAD_SALA[3] - CANTIDAD_SALA[3];
                             CANTIDAD_BODEGA[3] = CANTIDAD_BODEGA[3] - vendidos;
                            printf("%d en sala y %d en bodega \n", CANTIDAD_SALA[3], CANTIDAD_BODEGA[3]);
                            Total = Total + (PRECIOS[3] * cantidad_producto_vendido);
                        } else { printf("solo se pueden vender %d cantidad de existencias, ingrese un numero valido\n", Total_Bodega_Sala);
                        }

                    }

            } else { printf("ingrese un codigo valido\n"); }
            /* el if es para que el progama solo siga si el codigo esta dentro de los asignados y asi le ofrezca si quiere poner mas 
               productos*/
            if(PRODUCTO[0] == codigo_producto_vendido 
            || PRODUCTO[1] == codigo_producto_vendido 
            || PRODUCTO[2] == codigo_producto_vendido
            || PRODUCTO[3] == codigo_producto_vendido ){

                  printf ("¿Ingresara otro productos?\n");
                  printf("1) Si \n 2) No\n");
                  scanf("%d", &compra);
                  /* este else tiene un if dentro que es para que al momento de poner un codigo que no sea los que estan dentro,
                     no siga.*/
                  } else { if ( codigo_producto_vendido != 101 
                            || codigo_producto_vendido != 102 
                            || codigo_producto_vendido != 103 
                            || codigo_producto_vendido != 104)
                    
                  {
                     printf("El codigo no esta validado, coloque uno que lo este\n");
                     /* al momento de cambiar "compra" a 2, se cumple que la condicion del while es falsa osea que sale de la iteracion*/ 
                  } else { if( compra == 2) 
                           compra = 2;
                           break;   }
                           
                           }
                  
                            
            
            printf("$%d es el total de la compra \n", Total);

                
            } while (compra == 1);
            /*a continuacion se pedira que ingrese el efectivo que le dio el cliente para pagar la compra
              en caso de que le falte el programa le dira si quiere o no pagar lo que falta y en caso de que le falte
              le dara vuelto*/
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
          /* el menu 2 se separa en dos partes, una es ingresar y la otra es descontar, se hace con un if*/
             printf("Ingrese numero 1 si desea ingresar productos y numero 2 si desea descontarlos\n");
             scanf("%d", &inventario);

            if (inventario == 1 ) {

                     do

                     /* la parte de ingresar se hace pidiendo cantidad que quiere agregary el codigo pero solo en bodega.
                      Se les suman la cantidad de existencias al producto que se eligio*/
                     {
                     printf("Ingrese el codigo del producto que quiere agregar\n");
                     scanf("%d", &codigo_productos_agregados);
                     printf("Ingrese la cantidad de productos que quiere agregar\n");
                     scanf("%d", &cantidad_productos_agregados);

                     if (PRODUCTO[0] == codigo_productos_agregados)
                     {
                          printf("Se agregaron %d existencias al producto %s \n", cantidad_productos_agregados, producto_1 );
                          CANTIDAD_BODEGA[0]= CANTIDAD_BODEGA[0] + cantidad_productos_agregados;
                          printf("El almacen a sido actualizado correctamente \n");
                          printf("%d existencias totales del producto %s \n", CANTIDAD_SALA[0], producto_1);
                        
                     
                     } else if (PRODUCTO[1] == codigo_productos_agregados){
                         
                         printf("Se agregaron %d existencias al producto %s \n", cantidad_productos_agregados, producto_2 );
                        CANTIDAD_BODEGA[1]= CANTIDAD_BODEGA[1] + cantidad_productos_agregados;
                        printf("El almacen a sido actualizado correctamente \n");
                        printf("%d existencias totales del producto %s \n", CANTIDAD_SALA[1], producto_2);


                     }else if (PRODUCTO[2] == codigo_productos_agregados){
                         
                         printf("Se agregaron %d existencias al producto %s \n", cantidad_productos_agregados, producto_3 );
                         CANTIDAD_BODEGA[2]= CANTIDAD_BODEGA[2] + cantidad_productos_agregados;
                         printf("El almacen a sido actualizado correctamente \n");
                         printf("%d existencias totales del producto %s \n", CANTIDAD_SALA[2], producto_3);
                     
                     }else if (PRODUCTO[3] == codigo_productos_agregados){
                         
                         printf("Se agregaron %d existencias al producto %s \n", cantidad_productos_agregados, producto_4 );
                         CANTIDAD_BODEGA[3]= CANTIDAD_BODEGA[3] + cantidad_productos_agregados;
                         printf("El almacen a sido actualizado correctamente \n");
                         printf("%d existencias totales del producto %s \n", CANTIDAD_SALA[3], producto_4);
                     
                     } else {  printf("El codigo ingresado no es correcto\n"); }
                 /*lo mismo que arriba, se hace un if para que no pase de largo y darle la opcion de agregar mas o no*/
                     if(PRODUCTO[0] == codigo_productos_agregados 
                     || PRODUCTO[1] == codigo_productos_agregados 
                     || PRODUCTO[2] == codigo_productos_agregados 
                     || PRODUCTO[3] == codigo_productos_agregados){ 

                        printf ("¿Ingresara otro productos?\n");
                        printf("1) Si \n 2) No\n");
                        scanf("%d", &Otro_producto);
                     }  else { if(PRODUCTO[0] != codigo_productos_agregados 
                              || PRODUCTO[1] != codigo_productos_agregados 
                              || PRODUCTO[2] != codigo_productos_agregados 
                              || PRODUCTO[3] != codigo_productos_agregados) { 
                     
                     printf("El codigo no esta validado, coloque uno que lo este\n");} 
                     
                     else { if (Otro_producto == 2){ 
                         
                         Otro_producto = 2;
                         break;

                     }
                    
            }
                          
                     
    }  


                 

                     } while (Otro_producto == 1 ); 

        
                  
                     

        } else if (inventario == 2) { 
            
            printf("A continuacion le apareceran las causas por las que se descuentas los productos, eliga una por favor\n");
            printf("1)Hurto\n 2)Fallo\n");
            scanf("%d", &inventario_2);

            switch (inventario_2)
            {        

            
            case 1 : 
                     do
                     {
                        
                     
                     printf("Escriba el codigo del producto que robaron, por favor\n");
                     scanf("%d", &codigo_producto_robado);
                     printf("Indique cual fue la cantidad sustraida\n");
                     scanf("%d", &cantidad_productos_robados);

                     if (PRODUCTO[0] == codigo_producto_robado) {

                          printf("Se restaran %d existencias del producto %s \n", cantidad_productos_robados, producto_1 );
                          if( CANTIDAD_SALA[0] >= cantidad_productos_robados)
                          {
                          CANTIDAD_SALA[0]= CANTIDAD_SALA[0] - cantidad_productos_robados;
                          printf("El almacen a sido actualizado correctamente \n");
                          printf("%d existencias totales del producto %s \n", CANTIDAD_SALA[0], producto_1);

                          } else { printf("No habian tantas existecias del producto %s en sala \n", producto_1);}
                        
                     
                   } else if (PRODUCTO[1] == codigo_producto_robado){
                         
                         printf("Se restaran %d existencias del producto %s \n", cantidad_productos_robados, producto_2 );
                         if(CANTIDAD_SALA[1] >= cantidad_productos_robados )
                         {
                        CANTIDAD_SALA[1]= CANTIDAD_SALA[1] - cantidad_productos_robados;
                        printf("El almacen a sido actualizado correctamente \n");
                        printf("%d existencias totales del producto %s \n", CANTIDAD_SALA[1], producto_2);

                        } else { printf("No habian tantas existecias del producto %s en sala\n", producto_2);}


                   } else if (PRODUCTO[2] == codigo_producto_robado){
                         
                         printf("Se restaran %d existencias del producto %s \n", cantidad_productos_robados, producto_3 );
                         if(CANTIDAD_SALA[2] >= cantidad_productos_robados)
                         {
                         CANTIDAD_SALA[2]= CANTIDAD_SALA[2] - cantidad_productos_robados;
                         printf("El almacen a sido actualizado correctamente \n");
                         printf("%d existencias totales del producto %s \n", CANTIDAD_SALA[2], producto_3);

                         } else { printf("No habian tantas existecias del producto %s en sala\n", producto_3);}
                     
                   } else if (PRODUCTO[3] == codigo_producto_robado ){
                         
                         printf("Se restaran %d existencias del producto %s \n", cantidad_productos_robados, producto_4 );
                         if(CANTIDAD_SALA[3] >= cantidad_productos_robados)
                         {
                         CANTIDAD_SALA[3]= CANTIDAD_SALA[3] - cantidad_productos_robados;
                         printf("El almacen a sido actualizado correctamente \n");
                         printf("%d existencias totales del producto %s \n", CANTIDAD_SALA[3], producto_4);

                         } else { printf("No habian tantas existecias del producto %s en sala\n", producto_4);}
                     
                   } else {  printf("El codigo ingresado no es correcto\n"); }

                    if(PRODUCTO[0] == codigo_producto_robado
                     || PRODUCTO[1] == codigo_producto_robado 
                     || PRODUCTO[2] == codigo_producto_robado 
                     || PRODUCTO[3] == codigo_producto_robado){ 

                        printf ("¿Ingresara otro productos?\n");
                        printf("1) Si \n 2) No\n");
                        scanf("%d", &Otro_producto_robado);
                     }  else { if(PRODUCTO[0] != codigo_producto_robado
                              || PRODUCTO[1] != codigo_producto_robado 
                              || PRODUCTO[2] != codigo_producto_robado 
                              || PRODUCTO[3] != codigo_producto_robado) { 
                     
                     printf("El codigo no esta validado, coloque uno que lo este\n");} 
                     
                     else { if (Otro_producto_robado == 2){ 
                         Otro_producto_robado = 2;
                         break;

                     }
                    
            }
                          
                     
    }


                 /*en caso de no querer agregar se cambia la variable a 2 y se sale del do-while*/

                     } while (Otro_producto_robado == 1 );

                    
                break;
            
            case 2:  
            do
            /*en este caso es diferenet a arriba,ya que, ahora se descuentan de bodega y sala. De nuevo se descuentas dependiendo del
            codigo.*/
            {        printf("Escriba el codigo del producto que tiene una falla o se ha vencido, por favor\n");
                     scanf("%d", &codigo_producto_falla);
                     printf("Indique cuantos productos fallaron en Bodega\n");
                     scanf("%d", &cantidad_productos_fallados_bodega);
                     printf("Indique cuantos productos fallaron en Sala\n");
                     scanf("%d", &cantidad_productos_fallados_sala);
           /*hay varios if, el primero es para ver que producto se quiere descontar, el segundo es para ver si hay tantas
             existencias para descontar en caso de que no, se le avisa y se le dice cuantas hay. En caso de que si hayan 
            se restaran X cantidad de la bodega o sala y luego se indicara como quedo el almacen luego de descontar.
            El mismo proceso para bodega y sala y para los 4 productos. */
                     if (PRODUCTO[0] == codigo_producto_falla)
                        {
                         if(cantidad_productos_fallados_bodega != 0){ 
                             if (CANTIDAD_BODEGA[0] >= cantidad_productos_fallados_bodega) { 
                             printf("Se restaran %d cantidad de existencias al productos %s en Bodega\n",
                             cantidad_productos_fallados_bodega, producto_1);
                             CANTIDAD_BODEGA[0]= CANTIDAD_BODEGA[0] - cantidad_productos_fallados_bodega;
                             printf("El almacen a sido actualizado correctamente \n"); 
                             printf("%d cantidad de %s \n",CANTIDAD_BODEGA[0], producto_1);
                             } else { printf("No habian tantas existencias del producto %s en Bodega, introduzca un numero valido\n", producto_1); 
                                      printf("Tenga en cuenta que hay %d existencias en Bodega\n", CANTIDAD_BODEGA[0]);}

                         } if (cantidad_productos_fallados_sala != 0) {
                             if (CANTIDAD_SALA[0] >= cantidad_productos_fallados_sala) { 
                             printf("Se restaran %d cantidad de existencias al productos %s en Sala\n",
                             cantidad_productos_fallados_sala, producto_1);
                             CANTIDAD_SALA[0]= CANTIDAD_SALA[0] - cantidad_productos_fallados_sala;
                             printf("El almacen a sido actualizado correctamente \n");
                             printf("%d cantidad de %s \n",CANTIDAD_SALA[0], producto_1);
                             } else { printf("No habian tantas existencias del producto %s en Sala, introduzca un numero valido\n", producto_1); 
                                      printf("Tenga en cuenta que hay %d existencias en Sala\n", CANTIDAD_SALA[0]); } }
                             
                    } else if (PRODUCTO[1] == codigo_producto_falla) {
                         if(cantidad_productos_fallados_bodega != 0){ 
                             if (CANTIDAD_BODEGA[1] >= cantidad_productos_fallados_bodega) { 
                             printf("Se restaran %d cantidad de existencias al productos %s en Bodega\n",
                             cantidad_productos_fallados_bodega, producto_2);
                             CANTIDAD_BODEGA[1]= CANTIDAD_BODEGA[1] - cantidad_productos_fallados_bodega;
                             printf("El almacen a sido actualizado correctamente \n"); 
                             printf("%d cantidad de %s \n",CANTIDAD_BODEGA[1], producto_2);
                             } else { printf("No habian tantas existencias del producto %s en Bodega, introduzca un numero valido\n", producto_2); 
                                      printf("Tenga en cuenta que hay %d existencias en Bodega\n", CANTIDAD_BODEGA[1]);}

                         } if (cantidad_productos_fallados_sala != 0) {
                             if (CANTIDAD_SALA[1] >= cantidad_productos_fallados_sala) { 
                             printf("Se restaran %d cantidad de existencias al productos %s en Sala\n",
                             cantidad_productos_fallados_sala, producto_2);
                             CANTIDAD_SALA[1]= CANTIDAD_SALA[1] - cantidad_productos_fallados_sala;
                             printf("El almacen a sido actualizado correctamente \n");
                             printf("%d cantidad de %s \n",CANTIDAD_SALA[1], producto_1);
                             } else { printf("No habian tantas existencias del producto %s en Sala, introduzca un numero valido\n", producto_2);  
                                      printf("Tenga en cuenta que hay %d existencias en Sala\n", CANTIDAD_SALA[1]);} }
                             
                    } else if (PRODUCTO[2] == codigo_producto_falla)
                        {
                         if(cantidad_productos_fallados_bodega != 0){ 
                             if (CANTIDAD_BODEGA[2] >= cantidad_productos_fallados_bodega) { 
                             printf("Se restaran %d cantidad de existencias al productos %s en Bodega\n",
                             cantidad_productos_fallados_bodega, producto_3);
                             CANTIDAD_BODEGA[2]= CANTIDAD_BODEGA[2] - cantidad_productos_fallados_bodega;
                             printf("El almacen a sido actualizado correctamente \n"); 
                             printf("%d cantidad de %s \n",CANTIDAD_BODEGA[2], producto_3);
                             } else { printf("No habian tantas existencias del producto %s en Bodega, introduzca un numero valido\n", producto_3); 
                                      printf("Tenga en cuenta que hay %d existencias en Bodega\n", CANTIDAD_BODEGA[2]);
                                      }

                         } if (cantidad_productos_fallados_sala != 0) {
                             if (CANTIDAD_SALA[2] >= cantidad_productos_fallados_sala) { 
                             printf("Se restaran %d cantidad de existencias al productos %s en Sala\n",
                             cantidad_productos_fallados_sala, producto_3);
                             CANTIDAD_SALA[2]= CANTIDAD_SALA[2] - cantidad_productos_fallados_sala;
                             printf("El almacen a sido actualizado correctamente \n");
                             printf("%d cantidad de %s \n",CANTIDAD_SALA[2], producto_3);
                             } else { printf("No habian tantas existencias del producto %s en Sala, introduzca un numero valido\n", producto_3);  
                                      printf("Tenga en cuenta que hay %d existencias en Sala\n", CANTIDAD_SALA[2]); } }
                             
                    } else if (PRODUCTO[3] == codigo_producto_falla)
                        {
                         if(cantidad_productos_fallados_bodega != 0){ 
                             if (CANTIDAD_BODEGA[3] >= cantidad_productos_fallados_bodega) { 
                             printf("Se restaran %d cantidad de existencias al productos %s en Bodega\n",
                             cantidad_productos_fallados_bodega, producto_4);
                             CANTIDAD_BODEGA[3]= CANTIDAD_BODEGA[3] - cantidad_productos_fallados_bodega;
                             printf("El almacen a sido actualizado correctamente \n"); 
                             printf("%d cantidad de %s \n",CANTIDAD_BODEGA[3], producto_4);
                             } else { printf("No habian tantas existencias del producto %s en Bodega, introduzca un numero valido\n", producto_4); 
                                      printf("Tenga en cuenta que hay %d existencias en Bodega\n", CANTIDAD_BODEGA[3]);
                                      } 

                         } if (cantidad_productos_fallados_sala != 0) {
                             if (CANTIDAD_SALA[3] >= cantidad_productos_fallados_sala) { 
                             printf("Se restaran %d cantidad de existencias al productos %s en Sala\n",
                             cantidad_productos_fallados_sala, producto_4);
                             CANTIDAD_SALA[3]= CANTIDAD_SALA[3] - cantidad_productos_fallados_sala;
                             printf("El almacen a sido actualizado correctamente \n");
                             printf("%d cantidad de %s \n",CANTIDAD_SALA[3], producto_4);
                             } else { printf("No habian tantas existencias del producto %s en Sala, introduzca un numero valido\n", producto_4);  
                                      printf("Tenga en cuenta que hay %d existencias en Sala\n", CANTIDAD_SALA[3]);} }


                    } else { printf("El codigo ingresado es erroneo.\n"); }
                   /*de nuevo el mismo if para que no pase de largo al momento de que no sea un codigo valido */
                    if(PRODUCTO[0] == codigo_producto_falla
                     || PRODUCTO[1] == codigo_producto_falla
                     || PRODUCTO[2] == codigo_producto_falla 
                     || PRODUCTO[3] == codigo_producto_falla){ 

                        printf ("¿Ingresara otro productos?\n");
                        printf("1) Si \n 2) No\n");
                        scanf("%d", &Otro_producto_fallado);
                     }  else { if(PRODUCTO[0] != codigo_producto_falla
                              || PRODUCTO[1] != codigo_producto_falla
                              || PRODUCTO[2] != codigo_producto_falla
                              || PRODUCTO[3] != codigo_producto_falla) { 
                     
                     printf("El codigo no esta validado, coloque uno que lo este\n");} 
                     
                     else { if (Otro_producto_fallado == 2){ 
                         Otro_producto_fallado = 2;
                         break;

                     }
                    
            }
                          
                     
    }


                 

                     } while (Otro_producto_fallado == 1 );

                          
                        break;


            default: printf("Ingrese una opcion valida.");
                break;
                
                }  
            


        } else {printf("ingrese una opcion valida."); }



    } else {  printf("ingrese una opcion valida.");}
    
} 
           
    
    

return 0;
} 

