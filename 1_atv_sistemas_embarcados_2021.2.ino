// C++ code
//
void setup()
{
  pinMode(11,INPUT);
  pinMode(12,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(7,OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  if (digitalRead(11)){
  	Serial.println(digitalRead(11));
  }
  if(digitalRead(11) && analogRead(A5)==0){
    digitalWrite(12,HIGH);
    delay(5000);
  }
  else if(digitalRead(11) && analogRead(A5)==1023){
    digitalWrite(8,HIGH);
    delay(3000);
  }
  else if(digitalRead(11) || analogRead(A5)==0){
    digitalWrite(7,HIGH);
    delay(1000);
  }
  else{
    digitalWrite(12,LOW);
    digitalWrite(8,LOW);
    digitalWrite(7,LOW);
   }    
}


   