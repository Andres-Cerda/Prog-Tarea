#include <stdio.h>
#include <stdlib.h> // llama al sistema
#include <string.h> // Funciones para manejo de caracteres


int main(){
    int  opcion = 0;
    char nombreAgenda[100];
    char nombre[20];
    char apellido[20];
    char telefono[20];
    int  cant_contactos = 0;
    FILE * baseDeDatos;


    printf("Bienvenido a la aplicacion de agenda telefonica\n");
    printf("    /|    //| |                              \n");
    printf("   //|   // | |     ___       __             \n");
    printf("  // |  //  | |   //___) ) //   ) ) //   / / \n");
    printf(" //  | //   | |  //       //   / / //   / /  \n");
    printf("//   |//    | | ((____   //   / / ((___( (   \n\n");

 
    printf("1.- Listar agendas\n");
    printf("2.- Crear agenda\n");
    printf("3.- Mostrar registros de una agenda\n");
    printf("4.- Añadir registro en agenda\n");
    printf("5.- Eliminar agenda\n");
    printf("6.- Salir\n");
    printf("Ingrese su opción:\n");
    scanf("%d", &opcion);

    switch (opcion)
    
    {
    case 1:   //lista las agendas llamando al sistema con el comando "system" y elige que tipo de archivo busca con el *
          
               printf("Las agendas disponibles son: \n");
               system("dir *.txt");

    case 2:   // Crea una agenda agregando .txt al nombre con el comando "strcat" para que luego se llame a FILE y se cree con "w"
           do
           {
             
           
               printf("Ingrese el nombre de la agenda que quiere crear:\n");
               scanf("%s", nombreAgenda);
               strcat(nombreAgenda, ".txt");          
               baseDeDatos = fopen(nombreAgenda, "w");
               printf("La agenda se ha creado correctamente");
               fclose(baseDeDatos); 
               baseDeDatos = fopen ( "contactos.txt","r" );

                fclose(baseDeDatos);

               printf("Desea agregar otra agenda?\n");
               printf("1 es SI y 2 es NO\n");
               scanf("%d", &opcion);
               if (opcion == 2)
               {
                  opcion = 2;
               }
               
                   
               } while (opcion == 1);
         
        
        break; 
               

    case 3:     // Se listan con "System", se busca agrega a al nombre .txt con "strcat" para asi buscarla y luego se lee con r
             do
             {
               
             
                printf("Las agendas de contactos disponibles son:\n");
                system("dir *.txt");
                printf("Ingrese el nombre de la agenda que quiere revisar:\n");
                scanf("%s", nombreAgenda);
                strcat(nombreAgenda, ".txt");
                baseDeDatos = fopen(nombreAgenda, "r");

                printf("Su lista de contactos es \n");
                printf("_________________________\n");

               /* este while analisa si "fscanf devuelve un 3, ya que, este devuelve un numero equivalente a la cantidad de componentes
                  que tenga, es decir que como pide nombre, apellido y telefono debe devolver un 3*/
               while ( fscanf(baseDeDatos,"%s %s %s", nombre, apellido, telefono) == 3 )
               {
                 cant_contactos++ ;
                 printf("------ CONTACTO %d ------\n ",cant_contactos);
                 printf("Nombre: %s \n Apellido: %s \n Telefono: %s \n ", nombre, apellido, telefono);
                 printf("--------------------------\n");

                }
                fclose(baseDeDatos);

               printf("Desea revisar otra agenda?\n");
               printf("1 es SI y 2 es NO\n");
               scanf("%d", &opcion);
               if (opcion == 2)
               {
                  opcion = 2;
               }
               
                   
               } while (opcion == 1);
                break;

    case 4:     // Se listan con "system", se busca agrega a al nombre .txt con "strcat" para asi buscarla
                printf("Las agendas de contactos disponibles son:\n");
                system("dir *.txt");
                printf("Ingrese el nombre de la agenda que quiere editar:\n");
                scanf("%s", nombreAgenda);
                strcat(nombreAgenda, ".txt");
               
               do{ 

               printf("Escriba el contacto en formato Nombre Apellido Telefono, por favor\n");
               scanf("%s %s %s", nombre, apellido, telefono);
               // mode "a" para editar 
               baseDeDatos = fopen (nombreAgenda,"a");
               fprintf(baseDeDatos, "\n%s %s %s", nombre, apellido, telefono);

               fclose(baseDeDatos);
               printf("Desea agregar otro contacto?\n");
               printf("1 es SI y 2 es NO\n");
               scanf("%d", &opcion);
               if (opcion == 2)
               {
                  opcion = 2;
               }
               
                   
               } while (opcion == 1);
               
                break;
        
    case 5:    // se listan con "system" y se eliminan con el comando remove
               printf("Las agendas de contactos disponibles para eliminar son: \n");
               system("dir *.txt");
               printf("Ingrese el nombre de la agenda que quiere eliminar:\n");
               scanf("%s", nombreAgenda);
               strcat(nombreAgenda, ".txt");  
               remove(nombreAgenda);
               printf("La agenda %s ha sido eliminada correctamente!\n", nombreAgenda);
               break;

    case 6: 
               printf(":::    :::     :::      :::::::: ::::::::::: :::           :::       :::    ::: :::::::::: ::::::::   ::::::::  \n");
               printf(":+:    :+:   :+: :+:   :+:    :+:    :+:   :+: :+:         :+:       :+:    :+: :+:       :+:    :+: :+:    :+: \n");
               printf("+:+    +:+  +:+   +:+  +:+           +:+  +:+   +:+        +:+       +:+    +:+ +:+       +:+        +:+    +:+ \n");
               printf("+#++:++#++ +#++:++#++: +#++:++#++    +#+ +#++:++#++:       +#+       +#+    +:+ +#++:++#  :#:        +#+    +:+ \n");
               printf("+#+    +#+ +#+     +#+        +#+    +#+ +#+     +#+       +#+       +#+    +#+ +#+       +#+   +#+# +#+    +#+ \n");
               printf("#+#    #+# #+#     #+# #+#    #+#    #+# #+#     #+#       #+#       #+#    #+# #+#       #+#    #+# #+#    #+# \n");
               printf("###    ### ###     ###  ########     ### ###     ###       ########## ########  ########## ########   ########  \n");
               break;
               
               
            
                
                
}
    

    return 0;
}