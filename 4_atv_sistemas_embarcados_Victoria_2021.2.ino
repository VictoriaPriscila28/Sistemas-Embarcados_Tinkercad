#include <LiquidCrystal_I2C.h>

#include <Wire.h>
#define pinBut 5

LiquidCrystal_I2C lcd(0x20,16,2);
LiquidCrystal_I2C lcd2(0x20,16,2);
int contagem =0;
bool statusBotao = false;
void setup(){
  pinMode(pinBut,INPUT);
 lcd.init();// inicializa o lcd
  lcd.backlight();//acende a luz de fundo
  lcd.home();//coloca na posição inicial 0,0
  lcd.blink();
  delay(2000);
  lcd.print("Loading...");
  lcd.setCursor(0,1);
  lcd.print("Hello stranger!");
  delay(2000);
  lcd.clear();
  
  lcd2.init();
  lcd2.backlight();
  lcd2.home();
  lcd2.blink();
  lcd2.print("Emily still away");
  delay(2000);
}

void loop()
{
  if(digitalRead(pinBut)){
    if(statusBotao== true){
      statusBotao=false;
    }else{
      statusBotao=true;}
  }
  if(statusBotao==true){
 lcd.setCursor(0,0); 
 lcd.print("contando...");
 lcd.setCursor(0,1);
 lcd.print(contagem);
  for(int i=0; i<16; i++){
   lcd.scrollDisplayRight();
   delay(40);
  }
  delay(1000);
 }
  if(statusBotao==false){
 lcd2.setCursor(0,0); 
 lcd2.print("contando...");
 lcd2.setCursor(0,1);
 lcd2.print(contagem);
 contagem++;
  for(int i=0; i<16; i++){
   lcd.scrollDisplayRight();
   delay(40);
  }
  delay(1000);
  }
}