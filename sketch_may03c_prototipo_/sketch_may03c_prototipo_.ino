int potenciometro = A0;// pin analogico
int rojo = 11;
int verde = 10;
int azul = 9; //colores y sus pines de salida que serian el puerto 11,10 y 19 respectivamente
int pulsador1 = 7;
int pulsador2 = 8;
int valpuls1;
int valpuls2;
int valpot;//valores a modificar gracias a los pulsadores y el potenciometro respectivamente
int puertaand=0;
int puertanand=0;
int puertaor=0;
int puertanor=0;
int puertaxor=0;//valores para mostrar que la puerta esta activa (hecho a la "mala")

void setup() {
  Serial.begin(9600);
  pinMode(pulsador1, INPUT);//pulsador 1 cable gris
  pinMode(pulsador2, INPUT);//pulsador 2 cable blanco
  pinMode(rojo, OUTPUT);//pin salida rojo
  pinMode(verde, OUTPUT);//pin salida verde
  pinMode(azul, OUTPUT);//pin salida azul
  valpuls1 = 0;
  valpuls2 = 0;
  valpot = 0;//aqui se establecen todos los modos de los pins y las constantes

}

void loop() {
//LECTURA SENSORES
  valpuls2 = digitalRead(pulsador2);
  valpuls1 = digitalRead(pulsador1);
  valpot = analogRead(potenciometro);// se leen los valores arrojados por los sensores y se establecen como variables para ser usados como condiciones

 //SALIDA COLORES 
  if(valpot>=0 && valpot<205){  
    if (valpuls1 == 1 & valpuls2 == 1) {//AND
      digitalWrite(rojo, LOW);
      digitalWrite(verde, HIGH);
      digitalWrite(azul, HIGH); //color rojo
      puertaand=1;
      }else{
        digitalWrite(rojo,HIGH);
        digitalWrite(azul,HIGH);
        digitalWrite(verde,HIGH);//apagar
        puertaand=0;
      }
    }  
   if(valpot>=205 &&  valpot<410){
    if ((valpuls1 == 1 | valpuls2 == 1)) {//or
      
      digitalWrite(verde, HIGH);
      digitalWrite(azul, LOW);
      digitalWrite(rojo, LOW); // color violeta
      puertaor=1;
    }else{
        digitalWrite(rojo,HIGH);
        digitalWrite(azul,HIGH);
        digitalWrite(verde,HIGH);//apagar
        puertaor=0;
      }
   }   
  if(valpot>=410 && valpot<615){ 
    if (!(valpuls1 == 1 & valpuls2 == 1)) {//NAND
      digitalWrite(verde, LOW);
      digitalWrite(azul, HIGH);
      digitalWrite(rojo, LOW); //color amarillo
      puertanand=1;
    }else{
        digitalWrite(rojo,HIGH);
        digitalWrite(azul,HIGH);
        digitalWrite(verde,HIGH);//apagar
        puertanand=0;
      }
    }
  
  if(valpot>=615 && valpot<820){
    if (!(valpuls1 == 1 | valpuls2 == 1)){//NOR
      digitalWrite(azul, LOW);
      digitalWrite(rojo, HIGH);
      digitalWrite(verde, HIGH);//color azul
      puertanor=1;
    }else{
        digitalWrite(rojo,HIGH);
        digitalWrite(azul,HIGH);
        digitalWrite(verde,HIGH);//apagar
        puertanor=0;
      
      }
  }
  if(valpot>=820 && valpot<1025){    
    if (valpuls1 == 1 ^ valpuls2 == 1) {//XOR
      digitalWrite(verde, LOW);
      digitalWrite(azul, HIGH);
      digitalWrite(rojo, HIGH);//color verde
      puertaxor=1;
    }else{
        digitalWrite(rojo,HIGH);
        digitalWrite(azul,HIGH);
        digitalWrite(verde,HIGH);//apagar
        puertaxor=0;      
      }
    }
    /* en cada if, cuando se cumple la condicion, se establece una variable =1 para mostrar que la compuerta logica
     *  cumple las condiciones de activacion (pulsadores y el valor del potenciometro)
     */
  Serial.println((String)"[pulsador 1 =" +valpuls1 +"][pulsador 2 =" + valpuls2 +"][valor potenciometro="+valpot+"][puerta activada =1"+" AND="+puertaand+" OR="+puertaor+" NAND="+puertanand+" NOR="+puertanor+" XOR="+puertaxor+"]");  
  puertaand=0;
  puertaor=0;
  puertanand=0;
  puertanor=0;
  puertaxor=0;//reinicio de variables que permiten ver si la compuerta esta activada o no
  }
