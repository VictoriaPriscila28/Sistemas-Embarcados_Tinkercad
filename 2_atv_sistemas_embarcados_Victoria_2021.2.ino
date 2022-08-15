// C++ code
int vetor[15], soma, media;

void setup(){  
  pinMode(8,INPUT);
  pinMode(7,INPUT);
  Serial.begin(9600);
  Serial.println("Iniciando programa...");  
}
void loop(){
  if(digitalRead(8)){    
    for(int i = 0; i<=14; i++){
      vetor[i]=analogRead(A0);
      Serial.println(vetor[i]);
      delay(2000);    
  	}
  }

  if(digitalRead(7)){
    for(int i =0;i<=14;i++){
      soma = soma+vetor[i];
    }
    delay(1000);
    media= soma/15;
  	Serial.println(media);
    soma = 0;
    media = 0;
  }
 }
