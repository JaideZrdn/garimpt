const int ldrPin = A0;  
const int limiar = 475; 
const int limiar2 = 490;
unsigned long startTime = 0;  
unsigned long totalTime = 0;  
void setup() {
   pinMode(ldrPin, INPUT);
   Serial.begin(9600);
}

void loop() {
  int valorldr = analogRead(ldrPin);
    if (valorldr >= limiar && valorldr<= limiar2) {
    unsigned long endTime = millis();
    unsigned long duration = (endTime - startTime) / 1;
    totalTime+=duration;
    if (duration>65){
    	Serial.println("Tempo de faixa " + String(duration) + " microssegundos. Tempo total: " + String(totalTime) + " microssegundos");
		startTime = 0;
    	startTime = millis();
    }
  }
  Serial.println(valorldr);
  delay(100);
}
