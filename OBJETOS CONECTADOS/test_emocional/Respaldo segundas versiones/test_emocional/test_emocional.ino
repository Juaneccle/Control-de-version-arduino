int MOTOR = 2;
int MOTOR2 = 3;
//int Sonido = 5;
int LED = 4;

int estado = 0;
const int Trigger = 12; 
const int Echo = 11;

void setup() {

  Serial.begin(9600);
  pinMode(MOTOR, OUTPUT);
  pinMode(MOTOR2, OUTPUT);
  //pinMode(Sonido, OUTPUT);
  pinMode(Trigger, OUTPUT);
  pinMode(Echo, INPUT);
  pinMode(LED, OUTPUT); 

}

void loop() {
 
 long t;      //timepo que demora en llegar el eco
 long d;      //distancia en centimetros

  if (Serial.available()> 0){
  estado = Serial.read();
}

  t = pulseIn(Echo, HIGH);      //obtenemos el ancho del pulso
  d = t/59;                     //escalamos el tiempo a una distancia en cm
  
  digitalWrite(Trigger, HIGH);
  delayMicroseconds(10);          //Enviamos un pulso de 10us
  digitalWrite(Trigger, LOW);

  //if(d < 12){   
  // digitalWrite(LED, HIGH);
  //  } else {
  // digitalWrite(LED, LOW);
  //}
  
if (estado == '1' && d < 50 ){
    digitalWrite(LED,    HIGH);
    digitalWrite(MOTOR,  HIGH);
    digitalWrite(MOTOR2, HIGH);
    //digitalWrite(Sonido, HIGH);
    
  } else {

     digitalWrite(MOTOR,  LOW);
     digitalWrite(MOTOR2, LOW);
     digitalWrite(LED,    LOW);
     //digitalWrite(Sonido, LOW);
  }
  
    if (estado == '2'){
    digitalWrite(LED,    LOW);
    digitalWrite(MOTOR,  LOW);
    digitalWrite(MOTOR2, LOW);
}
}



