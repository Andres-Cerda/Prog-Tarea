#include <stdio.h>

int CalcularIVA (int Valor_compra);

int main(){
    
    int Valor_total = 0;

    printf(" Buenos dias, este programa esta hecho meramente para calcular e IVA\n");
    printf("Ingrese el valor de la compra\n");
    scanf("%i", &Valor_total); 
    int IVA_Calculado = CalcularIVA (Valor_total);

    printf("El IVA agregado a su compra es %d \n", IVA_Calculado);
    printf("El valor de la comra queda en %d \n", Valor_total + IVA_Calculado);


    return 0; 
}

 int CalcularIVA (int Valor_compra){

     int IVA_Calculado =  ( Valor_compra * 19 )/100;
     return IVA_Calculado; 
 }

 