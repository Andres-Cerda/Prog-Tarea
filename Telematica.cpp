// C++ code
//


// Entradas 

int potenciador_1_pin= A0;  // Control de tiempo ON/OFF
int potenciador_2_pin= A1;  // Control de brillo

//
int potenciador_1_valor= 0; // Valor (0 a 1023)
int potenciador_2_valor= 0; // Valor (0 a 1023)

// Salidas

int ledPin= 9;

void setup()
{
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  // Leer sensores
  
  potenciador_1_valor= analogRead(potenciador_1_pin);
  
  potenciador_2_valor= analogRead(potenciador_2_pin);
  
  Serial.print(potenciador_1_valor);
  Serial.print(" ");
  Serial.println(potenciador_2_valor);
  
  
  // Escalar
  
  // Control de tiempo ON/OFF
  
  potenciador_1_valor= map(potenciador_1_valor, 0, 1023, 500, 1000);
  
  Serial.print(potenciador_1_valor);
  Serial.print(" ");
  
  
  // Control de brillo
  
  potenciador_2_valor= map(potenciador_2_valor, 0, 1023, 500, 255);
  
  Serial.println(potenciador_2_valor);
  
 
  
  //Control de tiempo
  
  digitalWrite(ledPin, 1);
  delay(potenciador_1_valor); // ON
  
  digitalWrite(ledPin, 0);
  delay(potenciador_2_valor); // OFF
  
  


}
