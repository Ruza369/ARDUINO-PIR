
// Pri zaznamenani pohybu za tmy pohybovym cidlem, bude rozsvicena LED = hlavni svetlo, pokud je tma a nebude sepnute cidlo, tak bude svítit LED1
// Pohybove cidlo a LED svìtla budou funkcni pouze za tmy.
// --------------------------------------------------------
#define LDR 4      // LDR rezistor
#define PIR 2      // pohybove cidlo 
#define LED 3      // hlavni led svetlo 
#define LED1 9     // oznacujici vchodove dvere PWM

int pirState;       // stav Cidla PIR
int ldrValue;       // stav LDR rezistoru

void setup() {                   
  Serial.begin(9600);            // zapne serial komunikaci s PC po USB
  pinMode(LED, OUTPUT);          
  pinMode(LED1, OUTPUT);         
  pinMode(PIR, INPUT);           // nastavi pin 2 jako vstup - vystup z PIR cidla
  pinMode(LDR, INPUT);           // nastavi pin 4 jako vystup z LDR
  digitalWrite(LED, LOW);        // nastavi LED = svetlo, aby nesvitilo po spusteni programu
  analogWrite(LED1, 0);          // nastavi LED1 = aby nesvitila po spusteni programu
}

void loop(){
  ldrValue = analogRead(LDR);              // cte hodnotu ze vstupu LDR
  Serial.print(" Analog vstup LDR = ");    // zobrazeni hodnoty ze vstupu LDR
  Serial.println(ldrValue);                // terminal na PC

  if (ldrValue >= 646) {                   // pokud je tma
    analogWrite(LED1, 2);                  // rozsvit LED1 = LED1 sviti vždy za tmy a intenzitou 2
    pirState = digitalRead(PIR);           
    Serial.print(" PIR je ve stavu = ");   
    Serial.println(pirState);              

    if (pirState == HIGH) {                // pokud je PIR aktivovano
      analogWrite(LED1, 0);                // zhasni LED1
      digitalWrite(LED, HIGH);             // rozsvit LED = svetlo
      delay(15000);                        // cekej 15 vterin - sviti LED
      digitalWrite(LED, LOW);              // zhasni LED = svetlo
    } 
    else {                                 // pokud PIR neaktivni
      digitalWrite(LED, LOW);              // LED = svetlo je vypnuto
    }
  }
  else
    analogWrite(LED1, 0);                  // zhasni LED1, kdyz neni tma
}
