int LUZ = 0;
int LUZ2 = 0;

int FOTO = A1;
int FOTO2 = A0;


void setup() {
pinMode(FOTO, INPUT);
pinMode(FOTO2, INPUT);

Serial.begin(9600);
}

void loop() {
LUZ = analogRead(FOTO);
LUZ2 = analogRead(FOTO2);

Serial.print("Fotoresistencia1 ");
Serial.print(LUZ);
Serial.print("\t");
Serial.print(LUZ2);
Serial.println("\t");

}



/*
EN UN ARDUINO SOLO SE PUEDEN CONECTAR 10 LEDS

APUNTES:
el amperaje se saca una vez que se calcula el voltaje total, es
decir que mientras mas weas le conecte.

// BUSCAR VOLTAGE DIVIDER PARA REDUCIR LA INTERFERECNCIA


//////////////////////////////////////////////////////////////

ENCARGO 
 
 */
