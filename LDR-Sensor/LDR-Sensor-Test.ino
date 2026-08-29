void setup(){

  Serial.begin(9600);
  pinMode(A0, INPUT);
  pinMode(3, OUTPUT);
}

void loop(){
  int LDRvalue = analogRead(A0);

  Serial.println(LDRvalue);

  if(LDRvalue <= 90){
    digitalWrite(3, LOW);
  }else{
    digitalWrite(3, HIGH);
  }
}