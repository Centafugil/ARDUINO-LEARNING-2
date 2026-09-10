#include <Wire.h>
#include <Adafruit_SH110X.h>
#include <Adafruit_GFX.h>

int16_t x1, y1;
uint16_t w, h;

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1

Adafruit_SH1106G display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);


void setup(){

  display.begin(0x3C, true);

  display.clearDisplay();
  
  
  display.setTextColor(SH110X_WHITE);
  display.setTextSize(2);
  display.getTextBounds("Yummy", 0, 0, &x1, &y1, &w, &h);
  display.setCursor((SCREEN_WIDTH - w)/ 2, (SCREEN_HEIGHT - h)/ 2);
  display.println("Yummy");
  
  display.display();
  Serial.begin(9600);


  Serial.print("x1 = ");
  Serial.println(x1);

  Serial.print("y1 = ");
  Serial.println(y1);

  Serial.print("w = ");
  Serial.println(w);

  Serial.print("h = ");
  Serial.println(h);

}


void loop(){
  
  

}