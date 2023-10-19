/*
 * 
 * Created by: Jamylli Vitória Guedes Pereira
 * Created by: Emerson Medeiros Noberto
 * 16/10/2023
 * 
 */

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 20, 4);

const int SensorSolo1 = A1;
const int SensorSolo2 = A2;
const int SensorSolo3 = A3;

int valor1;
int valor2;
int valor3;

int SoloSeco = 1012; 
int SoloMolhado = 500; 
int percSoloSeco = 0; 
int percSoloMolhado = 99; 

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();

  lcd.setCursor (3,0);
  lcd.print ("1 INFORMATICA.");
  
  lcd.setCursor (6,1);
  lcd.print ("SEMATEC");

  lcd.setCursor (8,3);
  lcd.print ("2023");
  delay(5000);
  lcd.clear();
}

void loop(){
 valor1 = constrain(analogRead(SensorSolo1),SoloMolhado,SoloSeco);
 valor2 = constrain(analogRead(SensorSolo2),SoloMolhado,SoloSeco);
 valor3 = constrain(analogRead(SensorSolo3),SoloMolhado,SoloSeco);
 
 valor1 = map(valor1,SoloMolhado,SoloSeco,percSoloMolhado,percSoloSeco);
 valor2 = map(valor2,SoloMolhado,SoloSeco,percSoloMolhado,percSoloSeco);
 valor3 = map(valor3,SoloMolhado,SoloSeco,percSoloMolhado,percSoloSeco);

  lcd.setCursor (1,0);
  lcd.print ("Umidade plantinhas");
  delay(100);

  lcd.setCursor (0,1);
  lcd.print ("____________________");
  delay(100);
  
  lcd.setCursor (0,2);
  lcd.print ("plant1 plant2 plant3");
  delay(100);

  lcd.setCursor (1,3);
  if(valor1 < 10) {
    lcd.print("0");
  }
  lcd.print (valor1);
  lcd.print ("%");

  lcd.setCursor (8,3);
  if(valor2 < 10) {
    lcd.print("0");
  }
  lcd.print (valor2);
  lcd.print ("%");

  lcd.setCursor (15,3);
  if(valor3 < 10) {
    lcd.print("0");
  }
  lcd.print (valor3);
  lcd.print ("%");
}
