#include <stdio.h>

int main(){
  // dat. para escribir en binario 
    FILE * LeerCantidades = fopen ("Cantidad.dat", "r");
    FILE * EscribirCantidades = fopen("Cantidad.dat", "a");
    char Codigo[20];
    char Producto[20];
    int  Cant_produto = 0;
    int  inicio = 0;
    int  inicio2 = 0;

    
    int Cantidad_Por_Productoss[1000];
    rewind(LeerCantidades);
  // hace que cada numero del .dat vaya a un arreglo
    while ( fscanf(LeerCantidades, "%d ", &Cantidad_Por_Productoss[inicio]) == 1){
          
           printf("%d es la cantidad \n", Cantidad_Por_Productoss[inicio]);
           inicio++;
             

    }

    
   // imprime un nuevo numero al arreglo
    fprintf(EscribirCantidades, " %d", Cantidad_Por_Productoss[7] + 2);


    fclose (LeerCantidades);
   


    
    return 0;
}

