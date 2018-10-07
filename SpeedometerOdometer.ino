#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
unsigned int count=0;
boolean prevstate=0;
boolean currstate=0;
float circumference=0.00172;  //circumference=pi*d=3.14*0.5461
int prevsec=0;
int currsec=0;
float maxspeed=0;
float dist=0;
float distance=0;

void setup() {
pinMode(7,INPUT);  //hall sensor to D7
lcd.begin(16, 2);
lcd.setCursor(4,0);
lcd.print("Welcome!");
lcd.setCursor(1,1);
lcd.print("Team Yantriki!");
}

void loop() {
prevsec=currsec;
count=0;
while(currsec-prevsec<=5000)
{
  prevstate=currstate;
  delay(1);
  currstate=digitalRead(7);
  if(currstate==1 && prevstate==0)
    count++;
  currsec=millis();
}
dist=count*circumference;
distance=distance+dist;
maxspeed=(count*circumference)/0.0013889;
lcd.clear();
lcd.setCursor(0,0);
lcd.print("SPEED:");
lcd.setCursor(6,0);
lcd.print(maxspeed);
lcd.setCursor(11,0);
lcd.print("km/h");
lcd.setCursor(0,1);
lcd.print("DISTANCE:");
lcd.print(distance);
lcd.setCursor(9,1);
lcd.print(distance);
lcd.setCursor(14,1);
lcd.print("km");

}
