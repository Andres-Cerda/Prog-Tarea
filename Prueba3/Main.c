#include <stdio.h>

int main(){
FILE * baseDeDatos;

int SumatoriaPasaje(int arreglo[], int longitud);

int  Total = 0;
int  Contador = 0;
int  tarjetaBip = 0;
int  origen;
int  Destino;
char nombreEstacion[100];
int  costoParaLLegar[10]={425,360,250,480,390,410,375,270,460,340};


printf("Bienvenido a la linea 6 del Metro de Santiago\n");
printf("Las lineas de este metro son\n");

baseDeDatos = fopen ("Nombre_estaciones.txt", "r");

while (!feof(baseDeDatos))
{                
                 Contador++;
                 fscanf(baseDeDatos,"%s",nombreEstacion) == 1;
                
                 printf("------ Estacion %d ------\n ",Contador);
                 printf("Nombre: %s \n ", nombreEstacion);
                 printf("Valor: %d \n", costoParaLLegar[Contador - 1]);
                 printf("--------------------------\n");
                
                 }
fclose(baseDeDatos);

printf("Indique su estacion de origen");
scanf("%i", &origen);

printf("Indique su estacion de destino");
scanf("%i", &Destino);

printf("TOTAL: $%i\n", SumatoriaPasaje(costoParaLLegar, origen));










    return 0;
}


int SumatoriaPasaje(int arreglo[], int longitud){
    int sumatoria = 0;
    for(int i = 0 ; i < longitud ; i++){
        sumatoria += arreglo[i];
    }
    return sumatoria;
}