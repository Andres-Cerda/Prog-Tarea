#include <stdio.h>

int main(){
 
  char nombre[15];
    char apellido[20]; 

    char nombres_clientes[50][15];
    char apellidos_clientes[50][20];

    int cantidad_clientes = 0;
    printf("Ingrese su nombre:\n");
    scanf("%s", nombres_clientes[cantidad_clientes]);
    printf("Ingrese su apellido:\n");
    scanf("%s", apellidos_clientes[cantidad_clientes]);
    cantidad_clientes++;
    printf("Bienvenido %s %s!!\n", nombres_clientes[0], apellidos_clientes[0]);

    return 0;
}