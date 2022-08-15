// C++ code
//
#define ledR 7
#define ledG 6
#define ledY 5

String palavra = "";
void setup()
{
  pinMode(ledR,OUTPUT);
  pinMode(ledG,OUTPUT);
  pinMode(ledY,OUTPUT);
  Serial.begin(9600);
  Serial.println("Serial inicializada");
}

void loop()
{
  if(Serial.available())
  {
    palavra = Serial.readString();
    Serial.print("A mensagem enviada foi:");
    Serial.println(palavra);
    if(palavra == "agua"){
      digitalWrite(ledR,1);
    }else if(palavra == "suco"){
      digitalWrite(ledY,1);
    }else if(palavra == "refrigerante"){
      digitalWrite(ledG,1);
    }
    delay(1000);
     
  }else{
    digitalWrite(ledR,0);
    digitalWrite(ledG,0);
    digitalWrite(ledY,0);
  }    
}
