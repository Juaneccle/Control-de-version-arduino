#include <Keyboard.h>
 long valor;         // Valor potenciometro
 
 const int pulsadorPin = 2;
 const int pulsadorPin2 = 3;
 const int Trigger = 6;          //Pin digital 2 para el Trigger del sensor
 const int Echo = 4;             //Pin digital 3 para el echo del sensor
 const int inX = A0;             // analog input for x-axis
 const int inY = A1;             // analog input for y-axis
 const int inX2 = A2;             // analog input for x-axis
 const int inY2 = A3;             // analog input for y-axis
 const int presionJ = 8;
 const int micro = A4;
 
 int volumen;               // volumen de audio
 int intensidad;            // intensidad luminica
 int distancia;             // Valor distancia 
 int potencia;              // Valor potencia
 int valorTacto;            // Valor de tacto
 int valorPulsador  = 0;    // Estado del Boton
 int valorPulsador2 = 0;    // Estado del Boton 2
 int xValue  = 0;            // Valor X
 int yValue  = 0;            // Valor Y
 int xValue2 = 0;            // Valor X
 int yValue2 = 0;            // Valor Y
 int Presion = 0;           // Precion Joystic
 
 // SALIDA DE PINES
 int LED_A = 2;      
 int LED_B = 3;
 int LED_C = 4;
 int LED_D = 5;
 int LED_E = 6; 
 int tacto = 8;        // Pin sensor Tacto

void setup() {
  
  pinMode(pulsadorPin,  INPUT);
  pinMode(pulsadorPin2, INPUT);
  pinMode(Trigger, OUTPUT);        //pin como salida 
  pinMode(Echo, INPUT);            //pin como entrada
  pinMode(tacto, INPUT);
  pinMode(inX, INPUT); 
  pinMode(inY, INPUT); 
  pinMode(inX2, INPUT); 
  pinMode(inY2, INPUT); 
  pinMode(presionJ, INPUT_PULLUP);
  pinMode(micro, INPUT);
  
  Serial.begin(9600);
  Keyboard.begin();

  digitalWrite(Trigger, LOW);      //Inicializamos el pin con 0
}

void loop() {
delay(10);   // Delay Global
  
//// DECLARACIONES //// 
volumen        = analogRead(A4); 
//intensidad    = analogRead(A1);
//potencia      = analogRead(A2);
valorPulsador  = digitalRead(pulsadorPin);
valorTacto     = digitalRead(tacto);
xValue2        = analogRead(inX2); 
yValue2        = analogRead(inY2); 
xValue         = analogRead(inX); 
yValue         = analogRead(inY); 
Presion        = digitalRead(presionJ);

long t;      //timepo que demora en llegar el eco
long d;      //distancia en centimetros


////////////////////// SONIDO ////////////////////////////
/////////////////////////////////////////////////////////// 

//Serial.println(volumen); 
if (volumen > 50){
   Keyboard.press('v');  
     Keyboard.releaseAll(); 
  

}else if(volumen < 50) {
     Keyboard.releaseAll(); 
  
}
///////////////////////////////////////////////////////////
/////////////////////// FOTORESISTENCIA /////////////////
/*
Serial.println(intensidad);
if(intensidad < 15){
digitalWrite(LED_B, HIGH);
Keyboard.press('k');  
}else {
  digitalWrite(LED_B,LOW);
  Keyboard.releaseAll(); 
}
 
   //delay(150);
   //Serial.println("Distancia");
*/  

//////////////////////////////////////////////////////////
///////////////////////// DISTANCIA //////////////////////

  
  digitalWrite(Trigger, HIGH);
  //delayMicroseconds(10);          //Enviamos un pulso de 1sssssssss0us
  digitalWrite(Trigger, LOW);
  
  t = pulseIn(Echo, HIGH);      //obtenemos el ancho del pulso
  d = t/59;                     //escalamos el tiempo a una distancia en cm

// COMPROBACION //

  //Todo esto es para la impresion serial
  //Serial.print("Distancia: ");
  //Serial.print(d);               
  //Serial.print("cm");
  //Serial.println();

  if(d < 12){   
   //delay(150);
   //Serial.println("Distancia");
     Keyboard.press('s');  
  } else {
     Keyboard.releaseAll(); 
  }

//////////////////////////////////////////////////////////
/////////////////////// POTENCIOMETRO ////////////////////
delay(10);   // Delay Global

/*
// COMBROBACION // 

  //Serial.print("El valor es = ");
  //Serial.println(potencia);

 if(potencia < 100){
    //delay(150);
    //Serial.println("Potencia");
      Keyboard.press('s');
  } else {
      Keyboard.releaseAll();
 }
*/
/////////////////////////////////////////////////////////
/////////////////////////// BOTON 1 ///////////////////////

 /*if (valorPulsador == HIGH) {
   //delay(150);
   //Serial.println("tecla verde");
     Keyboard.press('a');     
  } else {
     Keyboard.releaseAll();
  }
*/

/////////////////////////////////////////////////////////
/////////////////////////// BOTON 2 ///////////////////////
/*
 if (valorPulsador2 == HIGH) {
     delay(150);
     Serial.println("tecla amarilla");
     Keyboard.press('k');     
  } else {
     Keyboard.releaseAll();
  }
*/

/////////////////////////////////////////////////////////
/////////////////////////// TACTO ///////////////////////

if (valorTacto == HIGH){      
    //delay(150);
    Keyboard.press('j');
    //Serial.println("Tacto");
    //Serial.println("ACTIVADO");
  } else {                      
    //Serial.println("NO ACTIVADO");
    Keyboard.releaseAll();
  }

/////////////////////////////////////////////////////////
///////////////////////// JOYSTICK ///////////////////////

if (yValue > 700){    // Movimiento para abajo    
    Keyboard.press('p');
    Serial.println("Tecla abajo");
  } else {                      
    Keyboard.releaseAll();
  }
  
if (yValue < 12){      //Movimiento para Arriba    
    //delay(150);
    Keyboard.press('o');
    Serial.println("Tecla arriba");
   } else {                      
    Keyboard.releaseAll();
  }

/*
  Serial.print("X: ");
  Serial.println(xValue);
  Serial.print("Y: ");
  Serial.println(yValue);
  Serial.print("Not pressed: ");
  Serial.println(Presion);
*/

 Keyboard.releaseAll();


/////////////////////////////////////////////////////////
///////////////////////// JOYSTICK 2 ///////////////////////opppp

if (yValue2 > 1000){    // Movimiento para abajo    
    Keyboard.press('o');
    Serial.println("Tecla abajo");
  } else {                      
    Keyboard.releaseAll();
  }
  
if (yValue2 < 12){      //Movimiento para Arriba    
    //delay(150);
    Keyboard.press('p');
    Serial.println("Tecla arriba");
   } else {                      
    Keyboard.releaseAll();
  }

////////////////////////////////// COMPROBACIONES //////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////


 Serial.print("Distancia: ");
    Serial.print(d);
    Serial.print("\t   ");
    Serial.print("Potensia: ");
    Serial.print(potencia);
    Serial.print("\t");
    Serial.print("Luz: ");
    Serial.print(intensidad);
    Serial.print("\t    ");
    Serial.print("Volumen: ");
    Serial.print(volumen);
    Serial.print("\t");
    Serial.print("Tacto: ");
    Serial.print(valorTacto);
    Serial.print("\t");
    Serial.print("Boton: ");
    Serial.print(valorPulsador);
    Serial.print("\t");
    Serial.print("X: ");
    Serial.print(xValue);
    Serial.print("\t");
    Serial.print("Y: ");
    Serial.println(yValue);
    Serial.print("\t     ");
    Serial.print("X2: ");
    Serial.print(xValue2);
    Serial.print("\t");
    Serial.print("Y2: ");
    Serial.println(yValue2);
  
  
  }


// BASURA





