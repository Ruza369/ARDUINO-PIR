void setup() {                   // probehne jen jednou, nastavi pocatecni hodnoty programu
  pinMode(13,OUTPUT);
}


// probiha stale dokola jako smycka = hlavni program ---------------------------------------
void loop(){
  digitalWrite(13,HIGH);
  delay(1000);
  digitalWrite(13,LOW);
  delay(1000);
  }
  
