#include <Servo.h>
#include <IRremote.h>

int RECV_PIN = 12;

int LEDVERDE = 2;
int LEDAMA = 3;
int LEDROJO = 4;

int estado = 0;

int n1 = 0;
int n2 = 0;
int n3 = 0;
int n4 = 0;
int n5 = 0;
int n6 = 0;
int n7 = 0;
int n8 = 0;

IRrecv irrecv(RECV_PIN);
decode_results results;

Servo servoMotor;

void setup()
{

//estado = Serial.read();

  pinMode(LEDVERDE, OUTPUT);
  Serial.begin(9600);
  // In case the interrupt driver crashes on setup, give a clue
  // to the user what's going on.
  Serial.println("Enabling IRin");
  irrecv.enableIRIn(); // Start the receiver
  Serial.println("Enabled IRin");
   servoMotor.attach(8);
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
   // Serial.println(estado);
    irrecv.resume(); // Receive the next value
 }
  delay(100);

// NUMERO 1
if(results.value == 0xFF30CF){    
n1 = 1;
} 

// NUMERO 2
if(results.value == 0xFF18E7 && n1 == 1 ){
n2 = 1;
} 

// NUMERO 3
if(results.value == 0xFF7A85 && n1 == 1 && n2 == 1){
n3 = 1;
}

// NUMERO 4
if(results.value == 0xFF10EF && n1 == 1 && n2 == 1 && n3 == 1){
n4 = 1;
}

// NUMERO 5
if(results.value == 0xFF38C7 && n1 == 1 && n2 == 1 && n3 == 1 && n4 == 1){
n5 = 1;
}

// NUMERO 6
if(results.value == 0xFF5AA5 && n1 == 1 && n2 == 1 && n3 == 1 && n4 == 1 && n5 ==1){
n6 = 1;
}

// NUMERO 7
if(results.value == 0xFF42BD  && n1 == 1 && n2 == 1 && n3 == 1 && n4 == 1 && n5 ==1 && n6 ==1){
  n7 = 1;
}

// NUMERO 8
if(results.value == 0xFF4AB5 && n1 == 1 && n2 == 1 && n3 == 1 && n4 == 1 && n5 ==1 && n6 ==1 && n7 == 1 ){
n8 = 1;
}
// NUMERO 9
if(results.value == 0xFF52AD){
n1 = 0;
n2 = 0;
n3 = 0;
n4 = 0;
n5 = 0;
n6 = 0;
n7 = 0;
n8 = 0;
servoMotor.write(0);
}

// SERVO
if ( n1 == 1 && n2 == 1 && n3 == 1 && n4 == 1 && n5 ==1 && n6 ==1 && n7 == 1 && n8 == 1){
servoMotor.write(360);
  
}

}
