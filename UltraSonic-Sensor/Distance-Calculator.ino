#include <Wire.h>
#include <Adafruit_SH110X.h>
#include <Adafruit_GFX.h>




#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT  64
#define RESET_PIN  -1
#define oledColor SH110X_WHITE



Adafruit_SH1106G display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, RESET_PIN);  //Constructor arguemnts of class adafruit

const int triggerPin = 6;
const int echoPin = 5;


int16_t x0;
int16_t y0;
int16_t w;
int16_t h;



void setup(){
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
  display.begin(0x3C, true);
  display.clearDisplay();

}

unsigned long timeDuration;
int distance;
float speed = 0.0351;

int pulseTime = 10; //trigger sound pulse time high -> low 


void loop(){
  
  triggerSound(pulseTime);
  measureEchoTime();
  displayText(oledColor, 2, distanceCalculator());
  Serial.println(distance/2);
}

int measureEchoTime(){
  timeDuration = pulseIn(echoPin, HIGH);
}



int distanceCalculator(){
 
  distance = speed * timeDuration;
  return distance/2;
  
}

void triggerSound(int pulseTime){
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(pulseTime);
  digitalWrite(triggerPin, LOW);
}

void displayText(int color, int size, int text){
  
  display.setTextColor(color);
  display.setTextSize(size);
  display.getTextBounds(String(text), 0, 0, &x0, &y0, &w, &h);  //Displaying distance on OLED
  display.setCursor((SCREEN_WIDTH - w)/2 , (SCREEN_HEIGHT - h) / 2);
  display.println(text);
  display.display();
  display.clearDisplay();

}


