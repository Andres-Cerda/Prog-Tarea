/*#include <stdio.h>

int main(){

 int misiones; 
 int tesoros_encontrados = 0;
 int tesoros_totales; 
  
 int tesoros[10][10]= {{2,9,0,0,10,9,6,10,5,4},
                        {9,6,5,0,0,9,6,3,2,8},
                        {3,3,8,10,6,9,5,4,3,9},
                        {2,6,3,6,4,3,6,2,8,3},
                        {6,6,9,10,3,4,6,2,9,9},
                        {4,10,4,4,9,0,9,10,8,8},
                        {2,2,0,3,5,4,4,6,6,5},
                        {8,4,1,3,9,5,6,6,7,7},
                        {8,1,4,9,5,7,7,3,4,4},
                        {4,8,5,4,2,3,3,2,3,6}};
 int tesoros_descubiertos[10][10];
 
  
  printf("¿Cuántas misiones desea hacer hoy?\n");
  printf("Tenga en cuenta que las misiones tienen un minimo de 2 y un maximo de 10.\n");
  scanf("%d", &misiones);
  
if(misiones>=2 && misiones<=10){
  
   for(int i=0; i <misiones; i++){ 

     int filas_llegada;
     int columnas_llegada;
     int filas_ida;
     int columnas_ida;

     printf("Ingrese las coordenadas teniendo en cuenta que es un formato 10x10 en las que desea que el robot se sumerja en formato X,Y (filas)(columas)\n");
     scanf("%d,%d", &filas_llegada, &columnas_llegada);

     if (filas_llegada <=10 && columnas_llegada <=10 )
     
     { 
     printf("%d es el numero de tesoros en ese lugar\n", tesoros[filas_llegada][columnas_llegada]);
     
     tesoros_totales = tesoros_encontrados + tesoros[filas_llegada][columnas_llegada];

     printf("Escriba una cordenada a donde quiera llegar en formato X,Y teniendo en cuenta que la cuadricula es 10x10\n");
     scanf("%d,%d", filas_ida, columnas_ida);

     while
           ( filas_llegada < filas_ida && columnas_llegada < columnas_ida ) { 

         filas_llegada-1;
         columnas_llegada-1;
        tesoros_totales= tesoros_encontrados + tesoros[filas_llegada][columnas_llegada];
        printf("lleva un total de %d tesoros", tesoros_totales);



         
     }
     
     } else if (filas_llegada < filas_ida && columnas_llegada > columnas_ida)


     
       
 
    








     
       
     
     }

    

      
   

  
     

      
    
  
  
  
  
  return (0);
  
}*/