#include <stdio.h>

int main () {

    int Bodega[4]= {101,102,103,104};
    int Cantidad_Bodega[4]= {5,7,8,8};
    int Producto = 0;
    int num = 0;


    char Producto_1[5]= "papas";
    char Producto_2[6]= "Melon";

    printf("Tiene 4 productos introduzca el numero que quiere\n"); 
    scanf("%d", &Producto);
    printf("El codigo de su producto es %d y hay %d en stock\n", Bodega[Producto -1], Cantidad_Bodega[Producto -1]);
    printf("Escriba el codigo de su producto\n");
    scanf("%d", &num);
    



    if (Bodega[Producto-1] == num)
    {
        printf("HOla mundo ");
    }
    
 
    
   return 0;
}