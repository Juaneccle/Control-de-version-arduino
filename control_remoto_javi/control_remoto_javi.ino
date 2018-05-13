 //#include <Keyboard.h>
 
 const int pulsadorPin = 2;
 
 int volumen;               // volumen de audio
 int intensidad;            // intensidad luminica
 int distancia;             // Valor distancia 
 int potencia;              // Valor potencia
 int valorPulsador  = 0;    // Estado del Boton

 
 // SALIDA DE PINES
 int LED_A = 2;      
 int LED_B = 3;
 int LED_C = 4;
 int LED_D = 5;
 int LED_E = 6; 

void setup() {
  
  pinMode(pulsadorPin, INPUT);
  Serial.begin(9600);
  //Keyboard.begin();
  
}

void loop() {
  
//// DECLARACIONES //// 
volumen = analogRead(A0); 
intensidad = analogRead (A1);
valorPulsador = digitalRead(pulsadorPin);
delay(50); 

////////////////////// SONIDO ////////////////////////////
/////////////////////////////////////////////////////////// 

//Serial.println(volumen); 
if (volumen > 50){
digitalWrite(LED_A, HIGH);
Serial.println("Sonido prendido");  
}else if(volumen < 50) {
digitalWrite(LED_A, LOW);
  
}
///////////////////////////////////////////////////////////
/////////////////////// FOTORESISTENCIA /////////////////

//Serial.println(intensidad);
if(intensidad > 1010){
digitalWrite(LED_B, HIGH);
  
}else {
  digitalWrite(LED_B,LOW);
}

//////////////////////////////////////////////////////////
///////////////////////// DISTANCIA //////////////////////




//////////////////////////////////////////////////////////
/////////////////////// POTENCIOMETRO ////////////////////




/////////////////////////////////////////////////////////
/////////////////////////// BOTON ///////////////////////

 if (valorPulsador == HIGH) {
     delay(150);
     Serial.println("Hola ql");
    // Keyboard.press('k');     
  } 
  //else {
    // Keyboard.releaseAll();
 // }


}
