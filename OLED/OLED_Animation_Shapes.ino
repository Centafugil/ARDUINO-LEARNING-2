#include <Wire.h>
#include <Adafruit_SH110X.h>
#include <Adafruit_GFX.h>

#define SCREEN_HEIGHT 64
#define SCREEN_WIDTH  128
#define OLED_RESET   -1


int16_t y0 = 30;
int16_t r  = 10;
uint16_t color = SH110X_WHITE;

int16_t x =  44;
int16_t y = 12;
int16_t w  = 40;
int16_t h = 40;



Adafruit_SH1106G display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);


void setup(){
  display.begin(0x3C, true);

  display.clearDisplay();
  Serial.begin(9600);
  
}

void loop(){


  
  

  for(int16_t x0 = 0; x0 < 128; x0++){
    display.drawLine(x0, y0, 0, 30, color);
    
    display.display();
    
    display.clearDisplay();

    

  }

  
 
  
}