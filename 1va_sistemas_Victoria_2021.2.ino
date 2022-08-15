#define ledR 7
#define ledG 6

int numeroCorreto = 28;
int input;
int tentativasRestante = 10;
bool perdeuJogo = false;
void setup(){
  pinMode(ledR,OUTPUT);
  pinMode(ledG,OUTPUT);
 
  Serial.begin(9600);
  Serial.println("Oi, estranho! Que tal voce tentar se divertir tentando acertar a data do meu aniversario?");
  Serial.println("Nesse jogo voce tem um total de 10 tentativas e a cada erro tu perde uma chance.");
}


void loop(){
  if(Serial.available())
  {    
    if (!perdeuJogo){
      tentativasRestante = tentativasRestante - 1;

      input = Serial.readString().toInt();
      Serial.print("Esse foi o numero que tu escolheu: ");
      Serial.println(input);

      if(input == numeroCorreto){
        digitalWrite(ledG,1);
        Serial.println("Uhuhuhu! Isso mesmo pow!! Tu acertaste :) ");
        Serial.println("-----------------------------------------------------");

        delay(100);

      }else if(input < numeroCorreto ){
        digitalWrite(ledR,1);
        Serial.println("Eita! O numero que tu escolheu eh menor do que o escolhido.");
        Serial.print("agora te restam ");
        Serial.print(tentativasRestante); 
        Serial.println(" tentativas.");
        Serial.println("------------------------------------------------------");
        delay(100);


      }else if(input > numeroCorreto){
        digitalWrite(ledR,1);
        Serial.println("Calma la pequeno gafanhoto,o numero que tu escolheu eh maior do que o escolhido.");
        Serial.print("agora te restam ");
        Serial.print(tentativasRestante);
        Serial.println(" tentativas");
        Serial.println("-----------------------------------------------------");
        delay(100);

      }

      delay(1000);


      if (tentativasRestante==0 && input != numeroCorreto){
        digitalWrite(ledR,1);
        Serial.println("Amigo(a),voce perdeu todas as tentativas de acertar o numero correto.");
        Serial.print("O numero escolhido era 28 ");
        Serial.println("Desanima nao. Que pelo menos isso te serviu de aprendizado!");
        perdeuJogo = true;
      }
    }

    
    }else{
    digitalWrite(ledR,0);
    digitalWrite(ledG,0);
   
  }    
}

