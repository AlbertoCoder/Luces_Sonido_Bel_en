#include <Arduino.h>

short int altavoz = A0;

int btnCanci_on = 2;
int estadoBtn = 0;
bool secuenciaActiva = false;
short int ledVerde = 6;
short int ledAzul = 9;

unsigned long miliSegsIniciales;
unsigned long miliSegsActuales;
const unsigned long periodo = 1000;


float notaDo = 130.81;
float notaDoSos = 138.59;
float notaRe = 146.83;
float notaReSos = 155.56;
float notaMi = 164.81;
float notaFa = 174.61;
float notaFaSos = 185.00;
float notaSol = 196;
float notaSolSos = 207.65;
float notaLa = 220;
float notaLaSos = 233.08;
float notaSi = 246.94;

float redonda = 3000;
float blanca = redonda/2;
float blanca_punt = blanca + blanca/2;
float negra = blanca/2;
float negra_punt = negra + negra/2;
float corchea = negra/2;
float corchea_punt = negra + negra/2;
float semicorch = corchea/2;
float semicorch_punt = corchea + corchea/2;

void manejar_leds(int valorVerde, int valorAzul){

  analogWrite(ledVerde,valorVerde);
  analogWrite(ledAzul,valorAzul);


}

void tocarNota(float nota, int durac){

  tone(altavoz, nota);
  delay(durac);
  noTone(altavoz);

}

void tocarArpegioDoMayorTriada(){

  tocarNota(notaDo,semicorch);
  manejar_leds(50,0);
  tocarNota(notaMi,semicorch);
  manejar_leds(100,50);
  tocarNota(notaSol,semicorch);
  manejar_leds(12,70);
  tocarNota(notaSi,semicorch);
  manejar_leds(140,90);
  tocarNota(notaRe*2,semicorch);
  manejar_leds(160,110);
  tocarNota(notaFa*2,semicorch);
  manejar_leds(180,130);
  tocarNota(notaLa*2,blanca);
  manejar_leds(200,150);

}
void tocarhaciaBel(){

  manejar_leds(100,100);
  tocarNota(notaFa*2,corchea);
  manejar_leds(255,255);
  tocarNota(notaLaSos*2,corchea);
  manejar_leds(100,100);
  tocarNota(notaLaSos*2,corchea);
  manejar_leds(255,255);
  tocarNota(notaLaSos*2,corchea);
  manejar_leds(100,100);
  tocarNota(notaLaSos*2,negra);
  
  manejar_leds(255,255);
  tocarNota(notaRe*4,corchea);
  manejar_leds(100,100);
  tocarNota(notaFa*4,corchea);
  manejar_leds(255,255);
  tocarNota(notaReSos*4,corchea);
  manejar_leds(100,100);
  tocarNota(notaRe*4,corchea);
  manejar_leds(255,255);
  tocarNota(notaDo*4,negra);
  delay(negra);
  manejar_leds(100,100);
  tocarNota(notaDo*4,corchea);
  manejar_leds(255,255);
  tocarNota(notaLaSos*2,corchea);
  manejar_leds(100,100);
  tocarNota(notaLa*2,corchea);
  manejar_leds(255,255);
  tocarNota(notaLaSos*2,corchea);
  manejar_leds(100,100);
  tocarNota(notaDo*4,corchea);
  manejar_leds(255,255);
  tocarNota(notaRe*4,corchea);
  manejar_leds(100,100);
  tocarNota(notaDo*4,corchea);
  manejar_leds(255,255);
  tocarNota(notaLaSos*2,corchea);
  manejar_leds(100,100);
  tocarNota(notaLa*2,corchea);
  manejar_leds(255,255);
  tocarNota(notaLaSos*2,corchea);
  manejar_leds(100,100);
  tocarNota(notaDo*4,corchea);

   delay(negra);
  manejar_leds(100,100);
  tocarNota(notaDo*4,corchea);
  manejar_leds(255,255);
  tocarNota(notaLaSos*2,corchea);
  manejar_leds(100,100);
  tocarNota(notaLa*2,corchea);
  manejar_leds(255,255);
  tocarNota(notaLaSos*2,corchea);
  manejar_leds(100,100);
  tocarNota(notaDo*4,corchea);
  manejar_leds(255,255);
  tocarNota(notaRe*4,corchea);
  manejar_leds(100,100);
  tocarNota(notaDo*4,corchea);
  manejar_leds(255,255);
  tocarNota(notaLaSos*2,corchea);
  manejar_leds(100,100);
  tocarNota(notaLa*2,corchea);
  manejar_leds(255,255);
  tocarNota(notaLaSos*2,corchea);
  manejar_leds(100,100);
  tocarNota(notaDo*4,corchea);

  delay(negra);
  manejar_leds(100,100);
  tocarNota(notaDo*4,corchea);
  manejar_leds(255,255);
  tocarNota(notaRe*4,corchea);
  manejar_leds(100,100);
  tocarNota(notaReSos*4,corchea);
  manejar_leds(255,255);
  tocarNota(notaSol*4,corchea);
  manejar_leds(100,100);
  tocarNota(notaFa*4,negra);
  manejar_leds(255,255);
  tocarNota(notaReSos*4,corchea);
  manejar_leds(100,100);
  tocarNota(notaRe*4,negra);
  manejar_leds(255,255);
  tocarNota(notaRe*4,negra);
  manejar_leds(100,100);
  tocarNota(notaDo*4,corchea);
  manejar_leds(255,255);
  tocarNota(notaLaSos*2,negra);

  delay(negra);
  manejar_leds(255,255);
  tocarNota(notaRe*4,semicorch);
  manejar_leds(100,100);
  tocarNota(notaReSos*4,semicorch);
  manejar_leds(255,255);
  tocarNota(notaFa*4,corchea);
  manejar_leds(100,100);
  tocarNota(notaFa*4,corchea);
  manejar_leds(255,255);
  tocarNota(notaDo*4,corchea);
  manejar_leds(100,100);
  tocarNota(notaRe*4,corchea);

  delay(negra);
  manejar_leds(255,255);
  tocarNota(notaRe*4,semicorch);
  manejar_leds(100,100);
  tocarNota(notaReSos*4,semicorch);
  manejar_leds(255,255);
  tocarNota(notaFa*4,corchea);
  manejar_leds(100,100);
  tocarNota(notaFa*4,corchea);
  manejar_leds(255,255);
  tocarNota(notaDo*4,corchea);
  manejar_leds(100,100);
  tocarNota(notaRe*4,corchea);

  delay(negra);
  manejar_leds(255,255);
  tocarNota(notaLaSos*2,semicorch);
  manejar_leds(100,100);
  tocarNota(notaLaSos*2,semicorch);
  manejar_leds(255,255);
  tocarNota(notaReSos*4,corchea);
  manejar_leds(100,100);
  tocarNota(notaReSos*4,corchea);
  manejar_leds(255,255);
  tocarNota(notaDo*4,corchea);
  manejar_leds(100,100);
  tocarNota(notaRe*4,corchea);
  manejar_leds(255,255);
  tocarNota(notaRe*4,corchea);
  manejar_leds(100,100);
  tocarNota(notaLaSos*2,corchea);
  manejar_leds(255,255);
  tocarNota(notaDo*4,corchea);
  manejar_leds(100,100);
  tocarNota(notaDo*4,corchea);
  manejar_leds(255,255);
  tocarNota(notaLa*2,corchea);
  manejar_leds(100,100);
  tocarNota(notaLaSos*2,blanca);


  
}
void tocarYaVienenLosReyesMagos(){

  manejar_leds(50,0);
  tocarNota(notaDo*3,semicorch);
  manejar_leds(60,0);
  tocarNota(notaMi*3,corchea);
  manejar_leds(70,0);
  tocarNota(notaSol*3,semicorch_punt);
  manejar_leds(80,0);
  tocarNota(notaLa*3,semicorch);
  manejar_leds(70,0);
  tocarNota(notaSol*3,corchea);
  manejar_leds(65,0);
  tocarNota(notaFa*3,corchea);
  manejar_leds(70,0);
  tocarNota(notaSol*3,corchea);
  manejar_leds(60,0);
  tocarNota(notaMi*3,corchea);

  manejar_leds(50,0);
  tocarNota(notaDo*3,corchea);
  manejar_leds(60,0);
  tocarNota(notaMi*3,corchea);
  manejar_leds(70,0);
  tocarNota(notaSol*3,semicorch_punt);
  manejar_leds(80,0);
  tocarNota(notaLa*3,semicorch);
  manejar_leds(70,0);
  tocarNota(notaSol*3,corchea);
  manejar_leds(65,0);
  tocarNota(notaFa*3,corchea);
  manejar_leds(70,0);
  tocarNota(notaSol*3,corchea);
  manejar_leds(60,0);
  tocarNota(notaMi*3,corchea);

  manejar_leds(70,0);
  tocarNota(notaSol*3,corchea);
  manejar_leds(0,70);
  tocarNota(notaSol*3,corchea);
  manejar_leds(70,0);
  tocarNota(notaSol*3,corchea);
  manejar_leds(0,70);
  tocarNota(notaMi*3,corchea);
  manejar_leds(50,0);
  tocarNota(notaDo*3,corchea);
  manejar_leds(60,0);
  tocarNota(notaMi*3,corchea);
  manejar_leds(70,0);
  tocarNota(notaRe*3,negra_punt);
  delay(500);
  manejar_leds(255,0);
  tocarNota(notaSol*3,corchea);
  manejar_leds(0,255);
  tocarNota(notaLa*3,corchea);
  manejar_leds(255,0);
  tocarNota(notaSol*3,corchea);
  manejar_leds(0,255);
  tocarNota(notaFa*3,corchea);
  manejar_leds(255,0);
  tocarNota(notaMi*3,corchea);
  manejar_leds(0,255);
  tocarNota(notaFa*3,negra);
  manejar_leds(255,0);
  tocarNota(notaRe*3,corchea);
  manejar_leds(0,255);
  tocarNota(notaMi*3,corchea);
  manejar_leds(255,0);
  tocarNota(notaFa*3,negra_punt);
  manejar_leds(0,255);

  tocarNota(notaMi*3,corchea);
  manejar_leds(255,0);
  tocarNota(notaSol*3,corchea);
  manejar_leds(0,255);
  tocarNota(notaFa*3,corchea);
  manejar_leds(255,0);
  tocarNota(notaMi*3,corchea);
  manejar_leds(0,255);
  tocarNota(notaRe*3,corchea);
  manejar_leds(255,0);
  tocarNota(notaDo*3,redonda);
  manejar_leds(255,255);

}

void tocarNewYearsDay(){

  manejar_leds(255,0);
  tocarNota(notaSolSos*2,blanca + corchea);
  manejar_leds(0,255);
  tocarNota(notaSolSos*2,corchea);
  manejar_leds(255,0);
  tocarNota(notaDoSos*4,corchea);
  manejar_leds(0,255);
  tocarNota(notaReSos*4,blanca);
  manejar_leds(255,0);
  tocarNota(notaSi*2,corchea);
  manejar_leds(0,255);
  tocarNota(notaDoSos*4,corchea);
  manejar_leds(255,0);
  tocarNota(notaLaSos*2,redonda);

}



void tocarNocheDePaz(){

  manejar_leds(55,55);
  tocarNota(notaDo*2,negra_punt);
  tocarNota(notaRe*2,corchea);
  tocarNota(notaDo*2,negra);
  tocarNota(notaLa,blanca_punt);

  manejar_leds(65,65);
  tocarNota(notaDo*2,negra_punt);
  tocarNota(notaRe*2,corchea);
  tocarNota(notaDo*2,negra);
  tocarNota(notaLa,blanca_punt);
  
  manejar_leds(75,75);
  tocarNota(notaSol*2,blanca);
  tocarNota(notaSol*2,negra);
  tocarNota(notaMi*2,blanca_punt);
  
  manejar_leds(85,85);
  tocarNota(notaFa*2,blanca);
  tocarNota(notaFa*2,negra);
  tocarNota(notaDo*2,blanca_punt);

  manejar_leds(95,95);
  tocarNota(notaRe*2,blanca);
  tocarNota(notaRe*2,negra);
  tocarNota(notaFa*2,negra_punt);

  manejar_leds(105,105);
  tocarNota(notaMi*2,corchea);
  tocarNota(notaRe*2,negra);

  tocarNota(notaDo*2,negra_punt);

  tocarNota(notaRe*2,corchea);
  tocarNota(notaDo*2,negra);

  tocarNota(notaLa,blanca_punt);

   tocarNota(notaRe*2,blanca);
  tocarNota(notaRe*2,negra);
  tocarNota(notaFa*2,negra_punt);

  manejar_leds(155,155);
  tocarNota(notaMi*2,corchea);
  tocarNota(notaRe*2,negra);

  tocarNota(notaDo*2,negra_punt);

  tocarNota(notaRe*2,corchea);
  tocarNota(notaDo*2,negra);

  tocarNota(notaLa,blanca_punt);

  tocarNota(notaSol*2,blanca);
  tocarNota(notaSol*2,negra);
  tocarNota(notaLaSos*2,negra_punt);
  tocarNota(notaSol*2,corchea);
  tocarNota(notaMi*2,negra);

  tocarNota(notaFa*2,blanca_punt);
  tocarNota(notaLa*2,blanca_punt),

  tocarNota(notaFa*2,negra),
  tocarNota(notaDo*2,negra);
  tocarNota(notaLa,negra);

  manejar_leds(255,255);
  tocarNota(notaDo*2,negra);
  tocarNota(notaLaSos,negra);
  tocarNota(notaSol,negra);
  tocarNota(notaFa,blanca_punt);

}

void tocarTamborilero(){


    secuenciaActiva = true;
  
  manejar_leds(0,255);
  tocarNota(notaDo*2,negra_punt);
  manejar_leds(255,0);
  tocarNota(notaRe*2,corchea);
  manejar_leds(0,255);
  tocarNota(notaMi*2,negra);
  manejar_leds(255,0);
  tocarNota(notaMi*2,corchea);
  manejar_leds(0,255);
  tocarNota(notaMi*2,corchea);
  manejar_leds(255,0);
  tocarNota(notaFa*2,semicorch);
  manejar_leds(0,255);
  tocarNota(notaMi*2,semicorch);
  manejar_leds(255,0);
  tocarNota(notaFa*2,corchea);
  manejar_leds(0,255);
  tocarNota(notaMi*2,negra_punt);
  manejar_leds(255,0);
  
  tocarNota(notaDo*2,corchea);
  manejar_leds(0,255);
  tocarNota(notaDo*2,corchea);
  manejar_leds(255,0);
  tocarNota(notaRe*2,corchea);
  manejar_leds(0,255);
  tocarNota(notaMi*2,corchea);
  manejar_leds(255,0);
  tocarNota(notaMi*2,corchea);
  manejar_leds(0,255);
  tocarNota(notaMi*2,corchea);
  manejar_leds(255,0);
  tocarNota(notaMi*2,corchea);
  manejar_leds(0,255);
  
  tocarNota(notaFa*2,semicorch);
  manejar_leds(255,0);
  tocarNota(notaMi*2,semicorch);
  manejar_leds(0,255);
  tocarNota(notaFa*2,corchea);
  manejar_leds(122,122);
  tocarNota(notaMi*2,blanca);


manejar_leds(255,0);
  tocarNota(notaRe*2,corchea);
  manejar_leds(0,255);
  tocarNota(notaMi*2,corchea);
  manejar_leds(255,0);
  tocarNota(notaFa*2,corchea);
  manejar_leds(0,255);
  tocarNota(notaSol*2,corchea);
  manejar_leds(255,0);
  tocarNota(notaSol*2,corchea);
  manejar_leds(0,255);
  tocarNota(notaSol*2,corchea);
  manejar_leds(255,0);
  tocarNota(notaLa*2,corchea);
manejar_leds(0,255);
  tocarNota(notaSol*2,semicorch);
  manejar_leds(255,0);
  tocarNota(notaFa*2,semicorch);
  manejar_leds(0,255);
  tocarNota(notaMi*2,corchea);
  manejar_leds(255,0);
  tocarNota(notaRe*2,blanca_punt);
  manejar_leds(0,255);
  tocarNota(notaRe*2,corchea);
  manejar_leds(255,0);
  tocarNota(notaMi*2,corchea);
  manejar_leds(0,255);
  tocarNota(notaFa*2,corchea);
  manejar_leds(255,0);
  tocarNota(notaSol*2,corchea);
  manejar_leds(0,255);
  tocarNota(notaSol*2,corchea);
  manejar_leds(255,0);
  tocarNota(notaSol*2,corchea);
  manejar_leds(0,255);
  tocarNota(notaLa*2,corchea);
manejar_leds(255,0);
  tocarNota(notaLaSos*2,semicorch);
  manejar_leds(0,255);
  tocarNota(notaLa*2,semicorch);
  manejar_leds(255,0);
  tocarNota(notaSol*2,corchea);
  manejar_leds(0,255);
  tocarNota(notaFa*2,negra);
manejar_leds(255,0);
  tocarNota(notaLa*2,semicorch);
  manejar_leds(0,255);
  tocarNota(notaSol*2,semicorch);
  manejar_leds(255,0);
  tocarNota(notaFa*2,corchea);
  manejar_leds(0,255);
  tocarNota(notaMi*2,negra);
manejar_leds(255,0);
  tocarNota(notaSol*2,semicorch);
  manejar_leds(0,255);
  tocarNota(notaFa*2,semicorch);
  manejar_leds(255,0);
  tocarNota(notaMi*2,corchea);
  manejar_leds(0,255);
  tocarNota(notaRe*2,blanca);
manejar_leds(0,0);
  delay(1000);
manejar_leds(255,0);
  tocarNota(notaDo*2,negra_punt);
    manejar_leds(0,255);

  tocarNota(notaRe*2,corchea);
  manejar_leds(255,0);

  tocarNota(notaMi*2,corchea);
    manejar_leds(0,255);

  tocarNota(notaMi*2,corchea);
  manejar_leds(255,0);

  tocarNota(notaMi*2,corchea);
    manejar_leds(0,255);

  tocarNota(notaMi*2,corchea);
  manejar_leds(255,0);

  tocarNota(notaFa*2,semicorch);
    manejar_leds(0,255);

  tocarNota(notaMi*2,semicorch);
  manejar_leds(255,0);

  tocarNota(notaFa*2,corchea);
  manejar_leds(0,255);

  tocarNota(notaMi*2,blanca);
  manejar_leds(255,0);

  tocarNota(notaRe*2,semicorch);
  manejar_leds(0,255);

  tocarNota(notaDo*2,semicorch);
    manejar_leds(255,0);

  tocarNota(notaRe*2,corchea);
manejar_leds(0,255);

  tocarNota(notaDo*2,redonda);
  manejar_leds(255,255);

 

  noTone(altavoz);
  manejar_leds(0,0);
    secuenciaActiva = false;
  delay(1000);
}

void secuencia_silenciosa(){

  for(int i = 10000;i<=25500;i++){


    analogWrite(ledVerde,i/100);
    analogWrite(ledAzul,i/100);
   
  }

  for(int i = 25500;i>10000;i--){

    analogWrite(ledVerde,i/100);
    analogWrite(ledAzul,i/100);
   

    
  }
  
  
}



void setup() {
  
  pinMode(btnCanci_on,INPUT_PULLUP);
  pinMode(altavoz,OUTPUT);
  pinMode(ledVerde,OUTPUT);
  pinMode(ledAzul,OUTPUT);

  Serial.begin(9600);
  tocarArpegioDoMayorTriada();

  tocarNewYearsDay();

}

void loop() {

  miliSegsActuales = millis();

  estadoBtn = digitalRead(btnCanci_on);



if(miliSegsActuales - miliSegsIniciales >= periodo){

  miliSegsIniciales = miliSegsActuales;

  if (estadoBtn == LOW && !secuenciaActiva) {
    
    tocarhaciaBel();

    tocarTamborilero();

    tocarNocheDePaz();

    tocarNewYearsDay();

    tocarYaVienenLosReyesMagos();
    
  }else{
 secuencia_silenciosa();

    digitalWrite(ledVerde,0);
    digitalWrite(ledAzul,0);
    noTone(altavoz);
    
  }
}
}
