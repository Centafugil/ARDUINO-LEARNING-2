#include <Wire.h>
#include <Adafruit_SH110X.h>
#include <Adafruit_GFX.h>
#include <string.h>

Adafruit_SH1106G display(128,64, &Wire, -1);

const int triggerPin = 6;
const int echoPin = 5;



void setup(){
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);

  Serial.begin(9600);
}

int timeDuration;
float distance;
float speed = 0.0351;

void loop(){
  
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(100);
  digitalWrite(triggerPin, LOW);


  timeDuration = pulseIn(echoPin, HIGH);

  distance = speed * timeDuration;

  Serial.println(distance/2);


}