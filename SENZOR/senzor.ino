#define PIR 2       // definice promenne PIR = 2
#define LED 3       // definice promenne LED = 3

int pirState;       // promenna - stav Cidla PIR

void setup() {                   // nastavi pocatecni hodnoty programu
  Serial.begin(9600);            // zapne serial komunikaci s PC po USB
  pinMode(LED, OUTPUT);          // nastavi pin 3 jako vystup - pro LED = svetlo
  pinMode(PIR, INPUT);           // nastavi pin 2 jako vstup - vystup z PIR cidla
}



void loop(){

  if (pirState == HIGH) {                // pokud je PIR aktivovano
      digitalWrite(LED,HIGH);            // rozsvit LED = svetlo
      delay(1000);                       // cekej 1 vterin
      digitalWrite(LED,LOW);             // zhasni LED = svetlo
      delay(1000);                       // cekej 1 vterinu
  }
  else {                                 // pokud PIR neaktivni
      digitalWrite(LED, LOW);            // LED = svetlo je vzpnuto
  }
      delay(1000);                             // cekej 1 vterinu
}                                              
