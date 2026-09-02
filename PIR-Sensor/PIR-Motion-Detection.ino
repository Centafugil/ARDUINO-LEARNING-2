void setup(){
  Serial.begin(9600);

  pinMode(7, INPUT);
  pinMode(2, OUTPUT);
}

int sensorPin = 7;
int ledPin = 2;


bool motionDetected;
unsigned long motionTime;
bool ledOn = false;

void loop(){


  motionDetected = digitalRead(sensorPin);
  


  if(motionDetected && ledOn == false){
    motionTime = millis();
    digitalWrite(ledPin, LOW);
    ledOn = true;
    

  } 
  
  if(millis() - motionTime > 5000 && ledOn){
    digitalWrite(ledPin, HIGH);
    ledOn = false;
    
  }


  Serial.println(motionDetected);
  

}