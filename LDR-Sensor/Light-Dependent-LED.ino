void setup(){

  Serial.begin(9600);
  pinMode(A0, INPUT);
  pinMode(3, OUTPUT);
}

void loop(){
  int LDRvalue = analogRead(A0);



  int brightness = map(LDRvalue, 0, 1023, 0, 255);

  Serial.println( brightness);


  analogWrite(3, brightness);
}