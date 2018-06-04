/* Con "translate" se puede cambiar la pocision de origen del cambas, es decir, que el (0,0)
   puede estar en otro lugar,.
   EL Pushmatrix guarda la memoria del origen en el programa:
   
   ellipse(10,10,10,10);
   Rotate("variables");
   PushMAtrix // funciona como si fuera con corchetes, aisalndo la matriz para que los valores
              // no se alteren con funciones anteriores
   PopMAtrix  // sirve para volver al estado anterior (Lo que esta fuera del push)           


*/
float o = 0;
float p = 0;
float px = 0;
float py = 200;

void setup(){
size(400,400);  

  
  
}


void draw(){
background(255,190,90);

fill(50,123,14);
o = o + 9;
translate(width/2,height/2);
rotate(radians(o));
ellipse(50,80,80,80);
////////////////////
pushMatrix();
////////////////////////////////////////////////////////////  
p += 5;    // cristobal aweonao 
//p = p +5;
fill(140,255,100);  
translate(0, 0);  
rotate(radians(p));  
ellipse(10,10,60,60);
////////////////////////////////////////////////////////////
popMatrix();
///////////////

//for(int i; i >= 1; i++){
   
   
 //}
}
