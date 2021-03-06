#include <LiquidCrystal.h>

const int rgb1=8;
const int rgb2=9;
const int rgb3=10;

const int enc1=5;
const int enc2=4;
const int sw=3;

int rgb[3];
int i;
String  colores[3]={"Rojo","Verde","Azul"};
bool A,B,auxA,auxB,aux1,menu;
LiquidCrystal lcd(38, 41, 44, 47, 48, 50);
                //rs  en  d4 d5 d6 d7
void setup() {
  // put your setup code here, to run once:

pinMode(rgb1,OUTPUT);
pinMode(rgb2,OUTPUT);
pinMode(rgb3,OUTPUT);

pinMode(enc1,INPUT);
pinMode(enc2,INPUT);
pinMode(sw,INPUT);

 A=0;  B=0;
 lcd.begin(16, 2);
 lcd.clear();
 lcd.setCursor(1,1);
 lcd.print("Proyecto RBG");
 delay(1000);

 Serial.begin(9600);
  menu=0;
 aux1=0;
 i=0;
 rgb[0]=0;
 rgb[1]=0;
 rgb[2]=0;
}

void loop() {
  // put your main code here, to run repeatedly:
  A=digitalRead(enc1);
  B=digitalRead(enc2);
  
    analogWrite(rgb1,rgb[0]);
    analogWrite(rgb2,rgb[1]);
    analogWrite(rgb3,rgb[2]);
    
  if(auxA!=A || auxB!=B){
        Serial.print("rgb1: ");
    Serial.print(rgb[0]);
    Serial.print("rgb2: ");
    Serial.print(rgb[1]);
    Serial.print("rgb3: ");
    Serial.println(rgb[2]);
    
    if(menu==0){
      i=UpDown(i);
      if(i<0){
      i=0;
      }
      if(i>2){
      i=2;
      }
    }else{
      rgb[i]=UpDown(rgb[i]);
      if(rgb[i]>255){
        rgb[i]=255;
      }
      if(rgb[i]<0){
        rgb[i]=0;
      }
    }
    
    lcd.clear();
    lcd.setCursor(1,0);
    lcd.print(colores[i]);
    lcd.setCursor(1,2);
    lcd.print(rgb[i]);
    if(menu==0){
      lcd.setCursor(10,0);
      lcd.print("<-");
    }else{
      lcd.setCursor(10,1);
      lcd.print("<-");
    }
    auxA=A;
    auxB=B;
  }

  if(digitalRead(sw)==0){
    while(digitalRead(sw)==0){}
    if(menu==0){
    menu=1;
    }else{
    menu=0;
    }
    if(menu==0){
      lcd.setCursor(10,1);
      lcd.print("  ");
      lcd.setCursor(10,0);
      lcd.print("<-");
    }else{
      lcd.setCursor(10,1);
      lcd.print("<-");
      lcd.setCursor(10,0);
      lcd.print("  ");
    }
  }
}

int UpDown(int vari){
  if(auxA==A || auxB!=B){
      if(B==A){
        if(aux1==1){
          vari++;
          aux1=0;
        }else{
        aux1++;
        }
      }
      if(B!=A){
        if(aux1==1){
          vari--;
          aux1=0;
        }else{
        aux1++;
        }
      } 
    }
    return vari;
}
/*
Giro a la derecha
         A: 1 B: 1
A: 1 B: 0//
A: 0 B: 0
A: 0 B: 1//

Giro a la Izquierda

A: 1 B: 1//
A: 0 B: 1
A: 0 B: 0//
A: 1 B: 0

*/














