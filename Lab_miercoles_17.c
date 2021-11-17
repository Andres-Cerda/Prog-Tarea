#include <stdio.h>


//Funciones
void imprimirTablero();
int  verificarGanador_O();
int  verificarGanador_X();



// Variables
 char tablero[3][3];
 int  fila;
 int  columna;
 int  ganador = 0; 

int main(){

    printf("Bienvenido al juego del gato, una competencia belica esta a punto de comenzar \n");

    int turnos = 0;  

     for(int i = 0 ; i < 3 ; i++){
        for(int j = 0 ; j < 3 ; j++){
            tablero[i][j] = '-';
        }
    }
   
    imprimirTablero();
 // Este while evalua desde el turno 1 hasta el 5, ya que, es el minimo para que un jugador gane
 while (turnos < 5)
 {
     
   // Turno X
    printf("Turno del jugador X\n");
    printf ("Por favor haga la jugada de modo X,Y\n"); 
    scanf ("%i,%i",&fila,&columna);

    while(tablero [fila-1][columna-1]!='-'){
    printf ("Esta casilla ya fue ocupada\n");
    printf ("Por favor haga la jugada de modo X,Y\n"); 
    scanf ("%i,%i",&fila,&columna);}

    tablero[fila-1][columna-1]='X';

    turnos = turnos + 1;

    imprimirTablero();

    if(turnos == 5){

        break;
    }

    //Turno jugador O
    printf("Turno del jugador O\n");
    printf ("Por favor haga la jugada de modo X,Y\n"); 
    scanf ("%i,%i",&fila,&columna);

    while(tablero [fila-1][columna-1]!='-'){
    printf ("Esta casilla ya fue ocupada\n");
    printf ("Por favor haga la jugada de modo X,Y\n"); 
    scanf ("%i,%i",&fila,&columna);}

    tablero[fila-1][columna-1]='O';

    imprimirTablero();

    turnos = turnos + 1;
    
    }  
    
// este do_while evalua los turnos del 6 (contandolo) al 9
do {
   

 verificarGanador_X();

 if(ganador == 1 ){

    printf("Felicidades el jugador X ha ganado\n");
    break;

} else {
    
    //Turno jugador O
    printf("Turno del jugador O\n");
    printf ("Por favor haga la jugada de modo X,Y\n"); 
    scanf ("%i,%i",&fila,&columna);

    while(tablero [fila-1][columna-1]!='-'){
    printf ("Esta casilla ya fue ocupada\n");
    printf ("Por favor haga la jugada de modo X,Y\n"); 
    scanf ("%i,%i",&fila,&columna);}

    tablero[fila-1][columna-1]='O';

    imprimirTablero();

    turnos = turnos + 1; 

     verificarGanador_O();

     if(ganador == 1){

         printf("Felicidades el jugador O ha ganado");
         break;

     } 



} 
    
    // Turno X
    printf("Turno del jugador X\n");
    printf ("Por favor haga la jugada de modo X,Y\n"); 
    scanf ("%i,%i",&fila,&columna);

    while(tablero [fila-1][columna-1]!='-'){
    printf ("Esta casilla ya fue ocupada\n");
    printf ("Por favor haga la jugada de modo X,Y\n"); 
    scanf ("%i,%i",&fila,&columna);}

    tablero[fila-1][columna-1]='X';

    turnos = turnos + 1;

    imprimirTablero();


} while ( ganador == 0 && turnos < 9 );

 

 if(turnos == 9 && ganador == 0){

    printf("Empate, hasta otra");
    
 }



      
      

    
    

    

    return 0;
}  
// Imprime el tablero 
void imprimirTablero(){

    
    printf ("%c  |  %c  |  %c\n", tablero[0][0], tablero[0][1], tablero[0][2]);
    printf ("----------------\n");
    printf ("%c  |  %c  |  %c\n", tablero[1][0], tablero[1][1], tablero[1][2]);
    printf ("----------------\n");
    printf ("%c  |  %c  |  %c\n", tablero[2][0], tablero[2][1], tablero[2][2]);

}
// Verifica todas las posiciones de X para que si se repiten 3 en linea, retorna un  1
int  verificarGanador_X(){


    if (('X'== tablero[0][0]&& tablero[0][0]==tablero[0][1]&& tablero[0][1]==tablero[0][2])||
        ('X'== tablero[1][0]&& tablero[1][0]==tablero[1][1]&& tablero[1][1]==tablero[1][2])||
        ('X'== tablero[2][0]&& tablero[2][0]==tablero[2][1]&& tablero[2][1]==tablero[2][2])||
        ('X'== tablero[0][0]&& tablero[0][0]==tablero[1][0]&& tablero[1][0]==tablero[2][0])||
        ('X'== tablero[0][1]&& tablero[0][1]==tablero[1][1]&& tablero[1][1]==tablero[2][1])||
        ('X'== tablero[0][2]&& tablero[0][2]==tablero[1][2]&& tablero[1][2]==tablero[2][2])||
        ('X'== tablero[0][0]&& tablero[0][0]==tablero[1][1]&& tablero[1][1]==tablero[2][2])||
        ('X'== tablero[2][0]&& tablero[2][0]==tablero[1][1]&& tablero[1][1]==tablero[0][2])){


ganador = 1;
} else { ganador = 0; }

return ganador;
}
// Verifica todas las posiciones de O para que si se repiten 3 en linea, retorna un  1
int  verificarGanador_O(){

    if (('O'== tablero[0][0]&& tablero[0][0]==tablero[0][1]&& tablero[0][1]==tablero[0][2])||
        ('O'== tablero[1][0]&& tablero[1][0]==tablero[1][1]&& tablero[1][1]==tablero[1][2])||
        ('O'== tablero[2][0]&& tablero[2][0]==tablero[2][1]&& tablero[2][1]==tablero[2][2])||
        ('O'== tablero[0][0]&& tablero[0][0]==tablero[1][0]&& tablero[1][0]==tablero[2][0])||
        ('O'== tablero[0][1]&& tablero[0][1]==tablero[1][1]&& tablero[1][1]==tablero[2][1])||
        ('O'== tablero[0][2]&& tablero[0][2]==tablero[1][2]&& tablero[1][2]==tablero[2][2])||
        ('O'== tablero[0][0]&& tablero[0][0]==tablero[1][1]&& tablero[1][1]==tablero[2][2])||
        ('O'== tablero[2][0]&& tablero[2][0]==tablero[1][1]&& tablero[1][1]==tablero[0][2])){


ganador = 1;
} else { ganador = 0; }

return ganador;
}