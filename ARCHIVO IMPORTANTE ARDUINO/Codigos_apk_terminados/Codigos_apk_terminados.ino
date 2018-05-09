
/*
int LED = 3;

void setup() {
Serial.begin(9600); //Iniciar el serial por defecto los bluetooht usan 9600
 pinMode(LED, OUTPUT); //Establecer el pin 13 como salida
}

void loop() {
 if(Serial.available()>=1)
 {
    char entrada = Serial.read(); //Leer un caracter
  
    if(entrada == 'h' or entrada == 'H') //Si es 'H', encender el LED
    {
       digitalWrite(LED, HIGH);
       Serial.println("LED encendido");
    }
 
    else if(entrada == 'l' or entrada == 'L') //Si es 'L', apagar el LED
    {
       digitalWrite(LED, LOW);
       Serial.println("LED apagado");
    }
 
  }

}
*/

//////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////

#include <Servo.h>

int LED_verde = 3;
int LED_amarillo = 4;
int LED_rojo = 5;
int MOTOR = 6;
int LED_SERVO = 8;

Servo servoMotor;

int estado = 0;

void setup(){

 Serial.begin(9600);
 pinMode(LED_verde, OUTPUT);
 pinMode(LED_amarillo, OUTPUT);
 pinMode(LED_rojo, OUTPUT);
 pinMode(MOTOR, OUTPUT);
 pinMode(LED_SERVO, OUTPUT);

 servoMotor.attach(7);

}


void loop(){
 
if (Serial.available()> 0){
estado = Serial.read();
}

if (estado == '1'){
 digitalWrite(LED_verde, HIGH);
 digitalWrite(LED_amarillo, HIGH);
 digitalWrite(LED_rojo, HIGH);
}

if (estado == '2'){
 digitalWrite(LED_verde, LOW);
 digitalWrite(LED_amarillo, LOW);
 digitalWrite(LED_rojo, LOW);

}

if (estado == '3'){

  digitalWrite(LED_verde, HIGH);
}

if (estado == '4'){

  digitalWrite(LED_amarillo, HIGH);
}

if (estado == '5'){

  digitalWrite(LED_rojo, HIGH);
  digitalWrite(LED_SERVO, HIGH);
}

if (estado == '6'){

  digitalWrite(MOTOR, HIGH);
 
}
if (estado == '7'){

  digitalWrite (MOTOR, LOW);
 
}

if (estado == '8'){

   servoMotor.write(0);
   digitalWrite(LED_SERVO, LOW);
 
}
if (estado == '9'){

  servoMotor.write(90);
 
}
if (estado == 'a'){

   servoMotor.write(180);
   digitalWrite(LED_SERVO, HIGH);
}
}
