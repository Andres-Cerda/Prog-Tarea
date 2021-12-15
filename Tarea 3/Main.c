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
* Programa dedicado a regular la mercancía que llega al local y también se encarga de descontarlo en caso de que fuera hurtado o haya 
fallado. 
*/

#include <stdio.h>
#include <stdlib.h> // llama al sistema
#include <string.h> // Funciones para manejo de caracteres
#include "libreria.h"

int main () {

printf("######                                                       \n");
printf("#     # # ###### #    # #    # ###### #    # # #####   ####  \n");
printf("#     # # #      ##   # #    # #      ##   # # #    # #    # \n");
printf("######  # #####  # #  # #    # #####  # #  # # #    # #    # \n");
printf("#     # # #      #  # # #    # #      #  # # # #    # #    # \n");
printf("#     # # #      #   ##  #  #  #      #   ## # #    # #    # \n");
printf("######  # ###### #    #   ##   ###### #    # # #####   ####  \n");

printf ("Hola bienvenido al sistema regulador de mercaderia\n");
printf ("En caso de tener usuario ingrese el numero 1 \nSi no tiene y desea uno, ingrese el numero 2\n");
scanf  ("%d",&opcion);

// Se le pedirá al usuario que ingrese una opción, que en este caso serian 1 o 2 para que la función "switch" la lea. 

switch (opcion)

{
case 1 : // Se le pedirá el usuario entregado por la empresa. 
         printf("Ingrese su usuario, por favor\n");
         scanf("%lu", &usuarioTrabajador);
         // Se verifica si es correcto.
          if (USUARIO_TRABAJADOR_ENTREGADO == usuarioTrabajador ) {

            printf( "Usuario ingresado correctamente, Bienvenido\n\n");

            // En caso de no serlo, se le pedirá de nuevo y se le dirá que le quedan dos intentos.
              }  else {

                printf("Clave incorrecta\n");
                printf("Dos intentos restantes\n");
                printf("Por favor ingrese nuevamente su usuario:\n ");
                scanf("%lu", &usuarioTrabajador);
         
                 // Se verifica por segunda vez si es correcto.
                    if (USUARIO_TRABAJADOR_ENTREGADO == usuarioTrabajador){

                      printf("Usuario ingresado correctamente, Bienvenido\n\n");
                    // Si no es correcto por segunda vez se le pedirá de nuevo y se le dirá que le queda un intento.
                         } else { 

                          printf("Clave incorrecta\n");
                          printf("Recuerde que la clave es el rut con el digito verificador pero sin guion\n");
                          printf("Un intentos restantes\n");
                          printf("Por favor ingrese nuevamente su usuario: \n");
                          scanf("%lu", &usuarioTrabajador);  
                      // Se verifica por última vez.
                            if(USUARIO_TRABAJADOR_ENTREGADO == usuarioTrabajador){ 

                             printf("Usuario ingresado correctamente, Bienvenido\n\n");
                        // Como ya es el tercer intento fallido, se bloqueará al usuario.
                             } else {  

                               printf ( "Clave incorrecta, usuario bloqueado");
                               // Se le da el valor de 1 para que así no siga de largo.
                               usuarioBloqueado = 1;



                                  }


                


                }
   }
         
         
    
    break;

case 2 : // Se le pedirá el Rut para crear el usuario.
         printf("Escriba su rut con digito verificador pero sin guion para crear su usuario\n");
         scanf("%lu", &usuarioCreado );
         printf("Usuario creado exitosamente\n");
         // Se le pedirá de nuevo para confirmar el usuario.
         printf("Ingrese su usuario, por favor\n");
         scanf("%lu", &usuarioCreado0);
           // Verifica el ingresado y el que es para confirmar son iguales.
         if (usuarioCreado == usuarioCreado0 ){ 
             printf("Usuario ingresado correctamente\n\n");
          // En caso de no ser correcto, se le recordara cual es. 
         } else {
             printf("Recuerde que el usuario ingresado es %lu\n", usuarioCreado);
             printf("Ingrese nuevamente su usuario, por favor\n");
             scanf("%lu", &usuarioCreado0);
             // Se verifica por segunda vez.
             if(usuarioCreado == usuarioCreado0){
                 printf("Usuario ingresado correctamente\n\n");
             // Y si no es correcto por segunda vez se apagará.    
             } else { 
                 printf("Se apagara el programa, hasta luego.");
                // Se le da el valor de 1 para que así no siga de largo. 
                usuarioBloqueado = 1;
             }

        
         }
    break;

default : // Esta opción es para limitar las opciones a 1 y 2. 
         printf("Numero no valido\n"); 
    
     break;

 // El if hace de limite. En caso de no ser opción 1 o 2, no pasara y pasara lo mismo si la variable usuario bloqueado es 1.         
} if (opcion == 1 && usuarioBloqueado == 0|| opcion == 2 && usuarioBloqueado == 0) {

    printf("    /|    //| |                              \n");
    printf("   //|   // | |     ___       __             \n");
    printf("  // |  //  | |   //___) ) //   ) ) //   / / \n");
    printf(" //  | //   | |  //       //   / / //   / /  \n");
    printf("//   |//    | | ((____   //   / / ((___( (   \n\n");
    printf("1) Listar agendas de cada seccion \n");
    printf("2) Crear una nueva agenda de seccion \n");
    printf("3) Mostrar contenido de una agenda \n");
    printf("4) venta de producto \n");
    printf("5) editar inventario \n");
    printf("elija una de las dos opciones \n");
    scanf("%d", &menu); } 
    // Es if de a continuación es para dar las opciones del menú.
    if(menu == 1 || menu == 2 || menu == 3 || menu == 4) {


        if(menu == 1){ //lista las agendas llamando al sistema con el comando "system" y elige que tipo de archivo busca con el *
          
               printf("Las secciones disponibles son: \n");
               system("dir *.txt");   
               
               }

        if (menu == 2)
        {
            // Crea una agenda agregando .txt al nombre con el comando "strcat" para que luego se llame a FILE y se cree con "w"
           do
           {
             
               printf("Ingrese el nombre nueva seccion de productos que quiere crear:\n");
               scanf("%s", agendaSeccionNueva);

               // Nombre del producto

               strcat(agendaSeccionNueva, "-Productos.txt");         
               baseDeDatos = fopen(agendaSeccionNueva, "w");
               printf("La agenda se ha creado correctamente");
               fclose(baseDeDatos); 

               

               printf("Desea agregar otra agenda?\n");
               printf("1 es SI y 2 es NO\n");
               scanf("%d", &opcion);
               if (opcion == 2)
               {
                  opcion = 2;
               }
               
                   
               } while (opcion == 1);
        }

        if (menu == 3)
        {
            
             
            
        }

        if (menu == 4)
        
        {



        }
        



























































































































               

         // Venta de producto
        if(menu == 3 ){ 
       
            do
            // El siguiente do-while hará que se repita el proceso la cantidad de veces que quiera el vendedor.
            {   
                // Se le pedirá el Código del producto. 
                printf("ingrese el codigo del producto quiere vender \n");
                scanf("%d", &codigoProductoVendido);
                // Se le pedirá la cantidad que quiere vender.
                printf("ingrese la cantidad de existencias que quiere vender \n");
                scanf("%d", &cantidadProductoVendido);

            // Al momento de ser 101 el código se hará este proceso y lo mismo para los otros 3 códigos (102, 103, 104).
            if(PRODUCTO[0] == codigoProductoVendido){
                    // Se verifica si hay tantos productos en sala para vender como pide el usuario. 
                    if(cantidadSala[0] >= cantidadProductoVendido){ 
                        // En caso de que la cantidad de productos vendidos sea mayor a cero se ejecutara el if.
                        if(cantidadProductoVendido > 0 ){
                        // Se dará el valor del producto.
                        printf("El valor de ese articulo es %d \n", PRECIOS[0]);
                        // Se restan las existencias que se vendieron al producto en sala. 
                        printf("Se restaran %d existencias al producto %s \n", cantidadProductoVendido, producto_1);
                        cantidadSala[0] = cantidadSala[0] - cantidadProductoVendido;
                        // Se multiplicará el valor del producto por la cantidad que se pide y se le sumará a la variable Total.
                        Total = Total + (PRECIOS[0] * cantidadProductoVendido);
                        } else { printf("ingrese un numero mayor a cero \n "); }

                    } else { 
                        if(cantidadProductoVendido > 0 ){  
                        // En caso de no ser suficiente con los productos en sala se hará un total de bodega y sala. 
                        totalBodegaSala = cantidadSala[0] + cantidadBodega[0];
                             // Si la cantidad de existencias en bodega y sala es mayor entonces se ejecutara el if. 
                             if(totalBodegaSala >= cantidadProductoVendido ){ 
                             printf("Se restaran %d existencias que faltan en la sala al producto %s desde la bodega \n", cantidadProductoVendido, producto_1);
                             // Se guardará en la variable vendidos para restarle eso a la cantidad en bodega.
                             vendidos = cantidadProductoVendido - cantidadSala[0];
                             // Ya que se vendieron todas las existencias de sala se le restaran todas.
                             cantidadSala[0] = cantidadSala[0] - cantidadSala[0];
                             // Se le resta a la bodega la variable vendidos o más bien lo que faltaba para cumplir con lo que se pide.
                             cantidadBodega[0] = cantidadBodega[0] - vendidos;
                             // Se mostrarán cuantas existencias quedan en sala y bodega.
                            printf("%d en sala y %d en bodega \n", cantidadSala[0], cantidadBodega[0]);
                             // Y se le sumara todo lo que se vendió al total.
                            Total = Total + (PRECIOS[0] * cantidadProductoVendido);
                            // En caso de que se pidan mas de los que hay se le dirá que solo se puede vender una cantidad X de existencias.
                        } else { printf("solo se pueden vender %d cantidad de existencias, ingrese un numero valido\n", totalBodegaSala);}

                          } else { printf("ingrese un numero mayor a cero \n "); }
                        
                          
                        
                    }
                    

            }   else if (PRODUCTO[1] == codigoProductoVendido){
                 if(cantidadSala[1] >= cantidadProductoVendido){ 
                        if(cantidadProductoVendido > 0 ){
                        printf("El valor de ese articulo es %d \n", PRECIOS[1]);
                        printf("Se restaran %d existencias al producto %s \n", cantidadProductoVendido, producto_2);
                        Total = Total + (PRECIOS[1] * cantidadProductoVendido);
                        } else { printf("ingrese un numero mayor a cero \n "); }

                    }  else { 
                        if(cantidadProductoVendido > 0 ){
                        totalBodegaSala = cantidadSala[1] + cantidadBodega[1];
                             if(totalBodegaSala >= cantidadProductoVendido ){
                             printf("Se restaran %d existencias que faltan en la sala al producto %s desde la bodega \n", cantidadProductoVendido, producto_2);    
                             vendidos = cantidadProductoVendido - cantidadSala[1];
                             cantidadSala[1] = cantidadSala[1] - cantidadSala[1];
                             cantidadBodega[1] = cantidadBodega[1] - vendidos;
                            printf("%d en sala y %d en bodega \n", cantidadSala[1], cantidadBodega[1]);
                            Total = Total + (PRECIOS[1] * cantidadProductoVendido);
                        } else { printf("solo se pueden vender %d cantidad de existencias, ingrese un numero valido\n", totalBodegaSala);}

                          } else { printf("ingrese un numero mayor a cero \n "); }

                    }

            }  else if (PRODUCTO[2] == codigoProductoVendido){
                if(cantidadSala[2] >= cantidadProductoVendido){ 
                        if(cantidadProductoVendido > 0 ){
                        printf("El valor de ese articulo es %d \n", PRECIOS[2]);
                        printf("Se restaran %d existencias al producto %s \n", cantidadProductoVendido, producto_3);
                        Total = Total + (PRECIOS[2] * cantidadProductoVendido);
                        } else { printf("ingrese un numero mayor a cero \n "); }

                    }  else { 
                        if(cantidadProductoVendido > 0 ){
                        totalBodegaSala = cantidadSala[2] + cantidadBodega[2];
                             if(totalBodegaSala >= cantidadProductoVendido ){
                             printf("Se restaran %d existencias que faltan en la sala al producto %s desde la bodega \n", cantidadProductoVendido, producto_3);    
                             vendidos = cantidadProductoVendido - cantidadSala[2];
                             cantidadSala[2] = cantidadSala[2] - cantidadSala[2];
                             cantidadBodega[2] = cantidadBodega[2] - vendidos;
                            printf("%d en sala y %d en bodega \n", cantidadSala[2], cantidadBodega[2]);
                            Total = Total + (PRECIOS[2] * cantidadProductoVendido);
                        } else { printf("solo se pueden vender %d cantidad de existencias, ingrese un numero valido\n", totalBodegaSala);}

                          } else { printf("ingrese un numero mayor a cero \n "); }

                    }

            } else if (PRODUCTO[3] == codigoProductoVendido){
               if(cantidadSala[3] >= cantidadProductoVendido){ 
                        if(cantidadProductoVendido > 0 ){
                        printf("El valor de ese articulo es %d \n", PRECIOS[3]);
                        printf("Se restaran %d existencias al producto %s \n", cantidadProductoVendido, producto_4);
                        Total = Total + (PRECIOS[3] * cantidadProductoVendido);
                        } else { printf("ingrese un numero mayor a cero \n "); }

                    } else {
                        if(cantidadProductoVendido > 0 ){ 
                        totalBodegaSala = cantidadSala[3] + cantidadBodega[3];
                             if(totalBodegaSala >= cantidadProductoVendido ){
                             printf("Se restaran %d existencias que faltan en la sala al producto %s desde la bodega \n", cantidadProductoVendido, producto_4);    
                             vendidos = cantidadProductoVendido - cantidadSala[3];
                             cantidadSala[3] = cantidadSala[3] - cantidadSala[3];
                             cantidadBodega[3] = cantidadBodega[3] - vendidos;
                            printf("%d en sala y %d en bodega \n", cantidadSala[3], cantidadBodega[3]);
                            Total = Total + (PRECIOS[3] * cantidadProductoVendido);
                        } else { printf("solo se pueden vender %d cantidad de existencias, ingrese un numero valido\n", totalBodegaSala);}

                          } else { printf("ingrese un numero mayor a cero \n "); }

                    }

            } else { printf("ingrese un codigo valido\n"); }
           // El if hace de límite para que solo funciones al momento de que, si no es, no se ejecuta esta parte.
            if(PRODUCTO[0] == codigoProductoVendido 
            || PRODUCTO[1] == codigoProductoVendido 
            || PRODUCTO[2] == codigoProductoVendido
            || PRODUCTO[3] == codigoProductoVendido ){
                 
                // Se le mostrara la opción de si quiere seguir agregando más productos o no.
                  printf ("¿Ingresara otro productos?\n");
                  printf("1) Si \n 2) No\n");
                  scanf("%d", &compra);
                  
                 // Este else tiene dentro un if que igual hace de límite para que al momento de que no sea, imprima que el Código no es válido.
                  } else { if ( codigoProductoVendido != 101 
                            || codigoProductoVendido != 102 
                            || codigoProductoVendido != 103 
                            || codigoProductoVendido != 104)
                    
                  {
                     printf("El codigo no esta validado, coloque uno que lo este\n");
                // Al momento de cambiar "compra" a 2, se cumple que la condición del while es falsa ósea que sale de la iteración.
                  } else { if( compra == 2) 
                           compra = 2;
                           break;   }
                           
                           }
                  
                            
            // Se muestra el valor total de la compra.
            printf("$%d es el total de la compra \n", Total);

                
            } while (compra == 1);
            // Al momento de salir de la iteración se mostrara el método de pago que por ahora solo es en efectivo.

            // El if para que no aparezca el método a menos que el total sea mayor a cero.
            if( Total > 0 ){
            // Se le pedirá que ingrese la cantidad de efectivo que ingreso el cliente.
            printf("Ingrese el efectivo entregado a continuacion\n");
            scanf("%d", &Pago);

            // Si el pago es equivalente al total de la compra entonces se ejecuta el if.
            if(Total == Pago ){
                // Como es exacto no da vuelto ni queda debiendo dinero.
                printf("Dado que el pago fue exacto, el vuelto sera $0\n");
                printf("Gracias por su compra, hasta luego.\n");

            // Si el pago es menor se ejecuta lo siguiente.
            } else if (Total > Pago)
            {
                // Se le dirá cuanto le falta y se le ofrecerá la opción de cancelar la compra o pagar lo que falta.
                printf("le faltan $%d \n", Total-Pago);
                printf("Si desea cancelar la compra ingrese 1, si desea agregar lo que falta ingrese 2.\n");
                scanf("%d", &compraCancelada);

                // Como deseo entregar lo que falta se le pedirá el efectivo faltante y se le dirá que, si falta de nuevo, se cancelará.
                if(compraCancelada == 2){
                printf("En caso de que falte efectivo por segunda vez se cancelara la compra\n");    
                printf("Ingrese el efectivo restante.\n");    
                scanf("%d", &Restante);
                   
                  // En caso de que el efectivo faltante más lo que ya había pagado sea igual entonces el vuelto será cero.
                  if(Total == Pago + Restante){
                      printf("Muchas gracias por la compra, hasta luego.\n");

                      // Como es menor por segunda vez se cancela la compra. 
                      } else if (Total > (Pago + Restante)){ 
                          printf("Dado que por segunda vez falta, se cancelara la compra\n");
                      // Ya que el pago y lo que entrego después es mayor al total se le entregara su vuelto.     
                      } else{ 
                          printf("Su vuelto es %d, hasta luego\n", (Pago + Restante)- Total);}
                      
                } else {printf("Muchas gracias por su visita, hasta luego\n");}

            } else {
                // Ya que el pago es mayor al total se le entregara su vuelto. 
                 printf("Su vuelto es $%d, hasta luego.\n", Pago-Total); }
                 // Para que al momento en que la compra sea cero, se hace este else. 
                 } else {printf("Dado que el valor de la compra es cero, se tomara como que no hay una venta, hasta luego");}
             


            
            
 
     }

           else if(menu == 2){
             // El menú 2 se separa en dos partes, una es ingresar productos (1) y la otra es descontar productos (2).
             printf("Ingrese numero 1 si desea ingresar productos y numero 2 si desea descontarlos\n");
             scanf("%d", &inventario);

            // Ingresar productos.
            if (inventario == 1 ) {

                     do
                     // El siguiente do-while hará que se repita el proceso la cantidad de veces que quiera el vendedor.

                     {
                     // Se le pedira el código del producto que quiere agregar   
                     printf("Ingrese el codigo del producto que quiere agregar\n");
                     scanf("%d", &codigoProductosAgregados);
                     // Se le pedirá que ingrese la cantidad de productos que quiere agregar.    
                     printf("Ingrese la cantidad de productos que quiere agregar\n");
                     scanf("%d", &cantidadProductosAgregados);

                      // Al momento de ser 101 el código se hará este proceso y lo mismo para los otros 3 códigos (102, 103, 104).
                     if (PRODUCTO[0] == codigoProductosAgregados) 

                     {         // En caso de que la cantidad de productos agregados sea mayor a cero se ejecutara el if.
                             if(cantidadProductosAgregados > 0 ){
                          // Se dirá cuántas existencias del producto se agregaron a bodega.
                          printf("Se agregaron %d existencias al producto %s \n", cantidadProductosAgregados, producto_1 );
                          // Se le sumaran los productos agregados a bodega.
                          cantidadBodega[0]= cantidadBodega[0] + cantidadProductosAgregados;
                          printf("El almacen a sido actualizado correctamente \n");
                          // Y se dirá el almacén actualizado.
                          printf("%d existencias totales del producto %s \n", cantidadBodega[0], producto_1);
                          } else { printf("ingrese un numero mayor a cero \n "); } 
                        
                     
                     } else if (PRODUCTO[1] == codigoProductosAgregados){

                         if(cantidadProductosAgregados > 0 ){
                         printf("Se agregaron %d existencias al producto %s \n", cantidadProductosAgregados, producto_2 );
                        cantidadBodega[1]= cantidadBodega[1] + cantidadProductosAgregados;
                        printf("El almacen a sido actualizado correctamente \n");
                        printf("%d existencias totales del producto %s \n", cantidadBodega[1], producto_2);
                        } else { printf("ingrese un numero mayor a cero \n "); } 


                     }else if (PRODUCTO[2] == codigoProductosAgregados){

                         if(cantidadProductosAgregados > 0 ){
                         printf("Se agregaron %d existencias al producto %s \n", cantidadProductosAgregados, producto_3 );
                         cantidadBodega[2]= cantidadBodega[2] + cantidadProductosAgregados;
                         printf("El almacen a sido actualizado correctamente \n");
                         printf("%d existencias totales del producto %s \n", cantidadBodega[2], producto_3);
                         } else { printf("ingrese un numero mayor a cero \n "); } 
                     
                     }else if (PRODUCTO[3] == codigoProductosAgregados){

                         if(cantidadProductosAgregados > 0 ){
                         printf("Se agregaron %d existencias al producto %s \n", cantidadProductosAgregados, producto_4 );
                         cantidadBodega[3]= cantidadBodega[3] + cantidadProductosAgregados;
                         printf("El almacen a sido actualizado correctamente \n");
                         printf("%d existencias totales del producto %s \n", cantidadBodega[3], producto_4);
                          } else { printf("ingrese un numero mayor a cero \n "); }
                     
                     } else {  printf("El codigo ingresado no es correcto\n"); }
                     // El if hace de límite para que solo funciones al momento de que, si no es, no se ejecuta esta parte.
                     if(PRODUCTO[0] == codigoProductosAgregados 
                     || PRODUCTO[1] == codigoProductosAgregados 
                     || PRODUCTO[2] == codigoProductosAgregados 
                     || PRODUCTO[3] == codigoProductosAgregados){

                        // Se le mostrara la opción de si quiere seguir agregando más productos o no.
                        printf ("¿Ingresara otro productos?\n");
                        printf("1) Si \n 2) No\n");
                        scanf("%d", &otroProducto);

                       // Este else tiene dentro un if que igual hace de límite para que al momento de que no sea, imprima que el Código no es válido.
                     }  else { if(PRODUCTO[0] != codigoProductosAgregados 
                              || PRODUCTO[1] != codigoProductosAgregados 
                              || PRODUCTO[2] != codigoProductosAgregados 
                              || PRODUCTO[3] != codigoProductosAgregados) { 
                     
                     printf("El codigo no esta validado, coloque uno que lo este\n");} 
                     // Al momento de cambiar "Otro_producto" a 2, se cumple que la condición del while es falsa ósea que sale de la iteración.
                     else { if (otroProducto == 2){ 
                         
                         otroProducto = 2;
                         break;

                     }
                    
            }
                          
                     
    }  


                 

                     } while (otroProducto == 1 ); 

        
                  
                     
          // Descontar productos.
        } else if (inventario == 2) { 
            // Se separa en dos partes, la primera seria descontar por hurto (1) y la otra descontar por fallo (2).
            printf("A continuacion le apareceran las causas por las que se descuentas los productos, eliga una por favor\n");
            printf("1)Hurto\n 2)Fallo\n");
            scanf("%d", &inventario_2);

            // La función switch leerá la variable inventario_2.
            switch (inventario_2)
            {        

            // Descontado por hurto. 
            case 1 : 
                     do
                     // El siguiente do-while hará que se repita el proceso la cantidad de veces que quiera el vendedor.
                     {
                        
                     // Se le pedirá que ingrese el código del producto que fue hurtado.
                     printf("Escriba el codigo del producto que robaron, por favor\n");
                     scanf("%d", &codigoProductoRobado);
                     // Se le pedirá la cantidad que fue sustraída.
                     printf("Indique cual fue la cantidad sustraida\n");
                     scanf("%d", &cantidadProductosRobados);

                     // Al momento de ser 101 el código se hará este proceso y lo mismo para los otros 3 códigos (102, 103, 104).
                     if (PRODUCTO[0] == codigoProductoRobado) {
                           // En caso de que la cantidad de productos agregados sea mayor a cero se ejecutara el if.
                          if(cantidadProductosRobados > 0 ){
                          // Se dirá cuántas existencias se restaran al producto que del código que ingreso.
                          printf("Se restaran %d existencias del producto %s \n", cantidadProductosRobados, producto_1 );
                          // Se ejecutará el if si la cantidad en sala cubre la cantidad que se robo.
                          if( cantidadSala[0] >= cantidadProductosRobados)
                          {
                          // En caso de que cumpla se le restaran a sala la cantidad de existencias que fue hurtada.    
                          cantidadSala[0]= cantidadSala[0] - cantidadProductosRobados;
                          printf("El almacen a sido actualizado correctamente \n");
                          // Se muestra la sala actualizada.
                          printf("%d existencias totales del producto %s \n", cantidadSala[0], producto_1);

                          // En caso de que no cumpla se dirá cuantas existencias hay en sala para que tenga una idea.
                          } else { printf("No habian tantas existecias del producto %s en sala \n", producto_1);}
                           } else { printf("ingrese un numero mayor a cero \n "); }
                        
                     
                   } else if (PRODUCTO[1] == codigoProductoRobado){

                     if(cantidadProductosRobados > 0 ){  
                         printf("Se restaran %d existencias del producto %s \n", cantidadProductosRobados, producto_2 );
                         if(cantidadSala[1] >= cantidadProductosRobados )
                         {
                        cantidadSala[1]= cantidadSala[1] - cantidadProductosRobados;
                        printf("El almacen a sido actualizado correctamente \n");
                        printf("%d existencias totales del producto %s \n", cantidadSala[1], producto_2);

                        } else { printf("No habian tantas existecias del producto %s en sala\n", producto_2);}
                          } else { printf("ingrese un numero mayor a cero \n "); }


                   } else if (PRODUCTO[2] == codigoProductoRobado){

                      if(cantidadProductosRobados > 0 ){  
                         printf("Se restaran %d existencias del producto %s \n", cantidadProductosRobados, producto_3 );
                         if(cantidadSala[2] >= cantidadProductosRobados)
                         {
                         cantidadSala[2]= cantidadSala[2] - cantidadProductosRobados;
                         printf("El almacen a sido actualizado correctamente \n");
                         printf("%d existencias totales del producto %s \n", cantidadSala[2], producto_3);

                         } else { printf("No habian tantas existecias del producto %s en sala\n", producto_3);}
                            } else { printf("ingrese un numero mayor a cero \n "); }
                     
                   } else if (PRODUCTO[3] == codigoProductoRobado ){
                         
                      if(cantidadProductosRobados > 0 ){  
                         printf("Se restaran %d existencias del producto %s \n", cantidadProductosRobados, producto_4 );
                         if(cantidadSala[3] >= cantidadProductosRobados)
                         {
                         cantidadSala[3]= cantidadSala[3] - cantidadProductosRobados;
                         printf("El almacen a sido actualizado correctamente \n");
                         printf("%d existencias totales del producto %s \n", cantidadSala[3], producto_4);

                         } else { printf("No habian tantas existecias del producto %s en sala\n", producto_4);}
                           } else { printf("ingrese un numero mayor a cero \n "); }
                     
                   } else {  printf("El codigo ingresado no es correcto\n"); }
                     // El if hace de límite para que solo funciones al momento de que, si no es, no se ejecuta esta parte.
                    if(PRODUCTO[0] == codigoProductoRobado
                     || PRODUCTO[1] == codigoProductoRobado 
                     || PRODUCTO[2] == codigoProductoRobado 
                     || PRODUCTO[3] == codigoProductoRobado){ 

                       // Se le mostrara la opción de si quiere seguir agregando más productos o no.
                        printf ("¿Ingresara otro productos?\n");
                        printf("1) Si \n 2) No\n");
                        scanf("%d", &otroProductoRobado);

                        // Este else tiene dentro un if que igual hace de límite para que al momento de que no sea, imprima que el Código no es válido.
                     }  else { if(PRODUCTO[0] != codigoProductoRobado
                              || PRODUCTO[1] != codigoProductoRobado 
                              || PRODUCTO[2] != codigoProductoRobado 
                              || PRODUCTO[3] != codigoProductoRobado) { 
                     
                     printf("El codigo no esta validado, coloque uno que lo este\n");} 
                     // Al momento de cambiar "Otro_producto_robado" a 2, se cumple que la condición del while es falsa ósea que sale de la iteración.
                     else { if (otroProductoRobado == 2){ 
                         otroProductoRobado = 2;
                         break;

                     }
                    
            }
                          
                     
    }


               

                     } while (otroProductoRobado == 1 );

                    
                break;
            // Descuento por fallo.
            case 2:  
            do
            // En este caso es diferente a arriba, ya que, ahora se descuentan de bodega y sala.
            
            {        // Se le pide el código del producto que quiere descontar. 
                     printf("Escriba el codigo del producto que tiene una falla o se ha vencido, por favor\n");
                     scanf("%d", &codigoProductoFalla);
                     // Se le pide la cantidad para descontar en bodega.
                     printf("Indique cuantos productos fallaron en Bodega\n");
                     scanf("%d", &cantidadProductosFalladosBodega);
                     // Se le pide de nuevo la cantidad, pero esta vez es para sala.
                     printf("Indique cuantos productos fallaron en Sala\n");
                     scanf("%d", &cantidadProductosFalladosSala);
          
                    // Al momento de ser 101 el código se hará este proceso y lo mismo para los otros 3 códigos (102, 103, 104).
                     if (PRODUCTO[0] == codigoProductoFalla)
                        {
                         // En caso de que la cantidad de productos agregados sea mayor a cero se ejecutara el if.
                         if(cantidadProductosFalladosBodega > 0){ 
                             // Ahora se evalúa que la cantidad en bodega sea mayor o igual a la cantidad de productos descontados.
                             if (cantidadBodega[0] >= cantidadProductosFalladosBodega) {
                                 // En caso de serlo se descuentan los productos fallados de bodega. 
                             printf("Se restaran %d cantidad de existencias al productos %s en Bodega\n",
                             cantidadProductosFalladosBodega, producto_1);
                              //  Se le resta a bodega la cantidad de existencias falladas.
                             cantidadBodega[0]= cantidadBodega[0] - cantidadProductosFalladosBodega;
                             printf("El almacen a sido actualizado correctamente \n"); 
                             // Se muestra el almacén actualizado.
                             printf("%d cantidad de %s \n",cantidadBodega[0], producto_1);
                               // En caso de que la cantidad de existencias falladas sea mayor a lo que hay en bodega se indica cuantos hay. 
                             } else { printf("No habian tantas existencias del producto %s en Bodega, introduzca un numero valido\n", producto_1); 
                                      printf("Tenga en cuenta que hay %d existencias en Bodega\n", cantidadBodega[0]);}

                        // Se ve si la cantidad ingresada sea mayor a cero. 
                         } if (cantidadProductosFalladosSala > 0) {
                             // Ahora se evalúa que la cantidad en sala sea mayor o igual a la cantidad de productos descontados.
                             if (cantidadSala[0] >= cantidadProductosFalladosSala) {
                             // Se indica cuantos se van a restar y a que producto. 
                             printf("Se restaran %d cantidad de existencias al productos %s en Sala\n",
                             cantidadProductosFalladosSala, producto_1);
                             // Se le resta a sala la cantidad de existencias falladas.
                             cantidadSala[0]= cantidadSala[0] - cantidadProductosFalladosSala;
                             printf("El almacen a sido actualizado correctamente \n");
                             // Se muestra el almacén actualizado.
                             printf("%d cantidad de %s \n",cantidadSala[0], producto_1);
                               //  En caso de que la cantidad de existencias falladas sea mayor a lo que hay en bodega se indica cuantos hay.
                             } else { printf("No habian tantas existencias del producto %s en Sala, introduzca un numero valido\n", producto_1); 
                                      printf("Tenga en cuenta que hay %d existencias en Sala\n", cantidadSala[0]); } }
                             
                    } else if (PRODUCTO[1] == codigoProductoFalla) {
                         if(cantidadProductosFalladosBodega > 0){ 
                             if (cantidadBodega[1] >= cantidadProductosFalladosBodega) { 
                             printf("Se restaran %d cantidad de existencias al productos %s en Bodega\n",
                             cantidadProductosFalladosBodega, producto_2);
                             cantidadBodega[1]= cantidadBodega[1] - cantidadProductosFalladosBodega;
                             printf("El almacen a sido actualizado correctamente \n"); 
                             printf("%d cantidad de %s \n",cantidadBodega[1], producto_2);
                             } else { printf("No habian tantas existencias del producto %s en Bodega, introduzca un numero valido\n", producto_2); 
                                      printf("Tenga en cuenta que hay %d existencias en Bodega\n", cantidadBodega[1]);}

                         } if (cantidadProductosFalladosSala > 0) {
                             if (cantidadSala[1] >= cantidadProductosFalladosSala) { 
                             printf("Se restaran %d cantidad de existencias al productos %s en Sala\n",
                             cantidadProductosFalladosSala, producto_2);
                             cantidadSala[1]= cantidadSala[1] - cantidadProductosFalladosSala;
                             printf("El almacen a sido actualizado correctamente \n");
                             printf("%d cantidad de %s \n",cantidadSala[1], producto_1);
                             } else { printf("No habian tantas existencias del producto %s en Sala, introduzca un numero valido\n", producto_2);  
                                      printf("Tenga en cuenta que hay %d existencias en Sala\n", cantidadSala[1]);} }
                             
                    } else if (PRODUCTO[2] == codigoProductoFalla)
                        {
                         if(cantidadProductosFalladosBodega > 0){ 
                             if (cantidadBodega[2] >= cantidadProductosFalladosBodega) { 
                             printf("Se restaran %d cantidad de existencias al productos %s en Bodega\n",
                             cantidadProductosFalladosBodega, producto_3);
                             cantidadBodega[2]= cantidadBodega[2] - cantidadProductosFalladosBodega;
                             printf("El almacen a sido actualizado correctamente \n"); 
                             printf("%d cantidad de %s \n",cantidadBodega[2], producto_3);
                             } else { printf("No habian tantas existencias del producto %s en Bodega, introduzca un numero valido\n", producto_3); 
                                      printf("Tenga en cuenta que hay %d existencias en Bodega\n", cantidadBodega[2]);
                                      }

                         } if (cantidadProductosFalladosSala > 0) {
                             if (cantidadSala[2] >= cantidadProductosFalladosSala) { 
                             printf("Se restaran %d cantidad de existencias al productos %s en Sala\n",
                             cantidadProductosFalladosSala, producto_3);
                             cantidadSala[2]= cantidadSala[2] - cantidadProductosFalladosSala;
                             printf("El almacen a sido actualizado correctamente \n");
                             printf("%d cantidad de %s \n",cantidadSala[2], producto_3);
                             } else { printf("No habian tantas existencias del producto %s en Sala, introduzca un numero valido\n", producto_3);  
                                      printf("Tenga en cuenta que hay %d existencias en Sala\n", cantidadSala[2]); } }
                             
                    } else if (PRODUCTO[3] == codigoProductoFalla)
                        {
                         if(cantidadProductosFalladosBodega > 0){ 
                             if (cantidadBodega[3] >= cantidadProductosFalladosBodega) { 
                             printf("Se restaran %d cantidad de existencias al productos %s en Bodega\n",
                             cantidadProductosFalladosBodega, producto_4);
                             cantidadBodega[3]= cantidadBodega[3] - cantidadProductosFalladosBodega;
                             printf("El almacen a sido actualizado correctamente \n"); 
                             printf("%d cantidad de %s \n",cantidadBodega[3], producto_4);
                             } else { printf("No habian tantas existencias del producto %s en Bodega, introduzca un numero valido\n", producto_4); 
                                      printf("Tenga en cuenta que hay %d existencias en Bodega\n", cantidadBodega[3]);
                                      } 

                         } if (cantidadProductosFalladosSala > 0) {
                             if (cantidadSala[3] >= cantidadProductosFalladosSala) { 
                             printf("Se restaran %d cantidad de existencias al productos %s en Sala\n",
                             cantidadProductosFalladosSala, producto_4);
                             cantidadSala[3]= cantidadSala[3] - cantidadProductosFalladosSala;
                             printf("El almacen a sido actualizado correctamente \n");
                             printf("%d cantidad de %s \n",cantidadSala[3], producto_4);
                             } else { printf("No habian tantas existencias del producto %s en Sala, introduzca un numero valido\n", producto_4);  
                                      printf("Tenga en cuenta que hay %d existencias en Sala\n", cantidadSala[3]);} }


                    } else { printf("El codigo ingresado es erroneo.\n"); }
                   // El if hace de límite para que solo funciones al momento de que, si no es, no se ejecuta esta parte.
                    if(PRODUCTO[0] == codigoProductoFalla
                     || PRODUCTO[1] == codigoProductoFalla
                     || PRODUCTO[2] == codigoProductoFalla 
                     || PRODUCTO[3] == codigoProductoFalla){

                        // Se le mostrara la opción de si quiere seguir descontando más productos o no.
                        printf ("¿Ingresara otro productos?\n");
                        printf("1) Si \n 2) No\n");
                        scanf("%d", &otroProductoFallado);

                         // Este else tiene dentro un if que igual hace de límite para que al momento de que no sea, imprima que el código no es válido.
                     }  else { if(PRODUCTO[0] != codigoProductoFalla
                              || PRODUCTO[1] != codigoProductoFalla
                              || PRODUCTO[2] != codigoProductoFalla
                              || PRODUCTO[3] != codigoProductoFalla) { 
                     
                     printf("El codigo no esta validado, coloque uno que lo este\n");}

                     // Al momento de cambiar "Otro_producto_fallado" a 2, se cumple que la condición del while es falsa ósea que sale de la iteración.
                     else { if (otroProductoFallado == 2){ 
                         otroProductoFallado = 2;
                         break;

                     }
                    
            }
                          
                     
    }


                 

                     } while (otroProductoFallado == 1 );

                          
                        break;


            default: printf("Ingrese una opcion valida.");
                break;
                
                }  
            


        } else {printf("ingrese una opcion valida."); }



    } else {  printf("ingrese una opcion valida.");}
    
} 
           
    
    

return 0;
} 

