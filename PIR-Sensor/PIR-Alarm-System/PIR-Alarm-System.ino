

const int sensor = 8;
const int buzzer = 10;
const int ledRed =  5;
const int ledBlue = 4;
const int ledGreen = 3;





void setup(){
  pinMode(sensor, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(ledRed, OUTPUT);
  pinMode(ledGreen, OUTPUT);
  pinMode(ledBlue, OUTPUT);
  Serial.begin(9600);

  digitalWrite(ledGreen, HIGH);
  digitalWrite(ledBlue, HIGH);
}


unsigned long motionTime;   
bool ledOn = false;
bool motionDetected;
bool firstLoop = true;
bool previousMotion = false;
bool duringEvent = false;
bool currentMotion = false;


void loop(){
    
   if(firstLoop){
    warmUpSequence();
   }

    

    currentMotion = digitalRead(sensor);

    motionSensor();

  

    if(motionDetected && !duringEvent){

        
        digitalWrite(ledBlue, LOW);
        tone(buzzer, 1000);
        motionTime = millis();
        ledOn = true;
        Serial.println("Motion detected");
        duringEvent = true;
       

    }else if(motionDetected && duringEvent){

        motionTime = millis();
        Serial.println("Reseted");

    }

    if(ledOn && millis() - motionTime >= 5000){
        digitalWrite(ledBlue, HIGH);
        ledOn = false;
        noTone(buzzer);
        Serial.println("5 sec passed away");
        duringEvent = false;
    }

    Serial.println(currentMotion);
    firstLoop = false;
}

void warmUpSequence(){
   
  while(millis() < 60000){
        digitalWrite(ledRed, LOW);
        delay(1000);
        digitalWrite(ledRed, HIGH);
        delay(1000);
        Serial.println("pleaseWait");
  }
    Serial.println("ready to use");
}

void motionSensor(){

    if(currentMotion && !previousMotion){
        motionDetected = true;
        previousMotion = true;
        

    }else if(!currentMotion && previousMotion){
        motionDetected = false;
		previousMotion = false;

    }else if(currentMotion && previousMotion){
        motionDetected = false;
    }
}

