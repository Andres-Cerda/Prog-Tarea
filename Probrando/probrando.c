#include <stdio.h>

int main(){

    FILE * Basededatos;
    char Codigo[20];
    char Producto[20];
    int  Cant_produto = 0;

    int Cantidad_Por_Producto[1000];

    Basededatos = fopen ("Datos.txt","r");
    while ( fscanf(Basededatos,"%s %s",Codigo , Producto) == 2){

                 Cant_produto++;
                 printf("------ Codigo %s ------\n ", (int)Codigo);
                 printf("Producto: %s \n Cantidad: %d \n ", Producto, Cantidad_Por_Producto[Cant_produto -1]);
                 printf("--------------------------\n");

                 printf("Desea modificar algun producto");
                 scanf("%d", &Cant_produto - 1 );
    }
    fclose (Basededatos);
      

   
 


    /*Basededatos = fopen ("Datos.txt","r");
    while ( fscanf(Basededatos,"%s %s %s",Codigo , Producto, Cantidad) == 3)
    {
                 
                 Cant_produto++;
                 printf("------ Producto %d ------\n ", Cant_produto);
                 printf("Codigo: %s \n Producto: %s \n Cantidad: %s \n ",(int)Codigo, Producto, (int)Cantidad);
                 printf("--------------------------\n");

                  if(Cant_produto == 3 && (int)Codigo == 105){

                  printf("Bien ahi");
                  }
                 
            }
    fclose (Basededatos); */

    

   


    
    return 0;
}

