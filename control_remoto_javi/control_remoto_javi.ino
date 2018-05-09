 int volumen;      // volumen de audio
 int intensidad;   // intensidad luminica
 // SALIDA DE PINES
 
 int LED_A = 2;      
 int LED_B = 3;
 int LED_C = 4;
 int LED_D = 5;
 int LED_E = 6; 

void setup() {
  Serial.begin(9600);
}

void loop() {
// DECLARACIONES
volumen = analogRead(A0); 
intensidad = analogRead (A1);

        ////////////////// SONIDO //////////////////
/////////////////////////////////////////////////////////// 
//Serial.println(volumen); 
delay(50); 
if (volumen > 50){
digitalWrite(LED_A, HIGH);
  
}else if(volumen < 50) {
digitalWrite(LED_A, LOW);
  
}
///////////////////////////////////////////////////////////
       /////////////////// FOTORESISTENCIA /////////////////
Serial.println(intensidad);
if(intensidad > 1010){
digitalWrite(LED_B, HIGH);
  
}else {
  digitalWrite(LED_B,LOW);
}
//////////////////////////////////////////////////////////


}
