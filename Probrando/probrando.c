#include <stdio.h>

int main(){
  // dat. para escribir en binario 
    FILE * LeerCantidades = fopen ("Cantidad.dat", "r");
    FILE * EscribirCantidades; 
    FILE * LeerProductos = fopen ("Datos.txt", "r");
    char Codigo[20];
    char Producto[20];
    int  Cant_produto = 0;
    int  inicio = 0;
    int  Codigo_Usuario = 0;
    int  contador = 0;
    int  guardar = 0;
    int  Cantidad_ingresada;
    

    // idea 
    int Cantidad_Por_Productoss[1000];
    rewind(LeerCantidades);
    rewind(LeerProductos);
    

    printf("Ingrese el codigo del producto que quiere consultar\n");
    scanf("%d", &Codigo_Usuario);
  // hace que cada numero del .dat vaya a un arreglo
while ( fscanf(LeerCantidades, "%d ", &Cantidad_Por_Productoss[inicio]) == 1 && fscanf(LeerProductos,"%s %s", Codigo, Producto) == 2){

           contador++;
           
           if(Codigo_Usuario == contador){

           printf("--- Codigo %s---\n", Codigo);
           printf("Producto: %s \n", Producto);
           printf("cantidad: %d \n", Cantidad_Por_Productoss[inicio]);
           printf("----------------\n");
           inicio++;
           
           
          
           }
           
           }
           fclose (LeerCantidades);

           
           

          
           
           printf("%d \n", Cantidad_Por_Productoss[0]);
           printf("%d \n", Cantidad_Por_Productoss[1]);
           printf("%d \n", Cantidad_Por_Productoss[2]);

            EscribirCantidades = fopen ("Cantidad.dat","w");

            fprintf(LeerCantidades, "%d ", Cantidad_Por_Productoss[0]); 
            fprintf(LeerCantidades, "%d ", Cantidad_Por_Productoss[1]);
            fprintf(LeerCantidades, "%d ", Cantidad_Por_Productoss[2]); 

            

    

    
   // imprime un nuevo numero al arreglo
    // fprintf(EscribirCantidades, " %d", Cantidad_Por_Productoss[0] + 10);



    fclose (LeerCantidades);
    
    fclose(LeerProductos);
    
   


    
    return 0;
}

