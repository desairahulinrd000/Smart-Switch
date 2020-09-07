#include <LiquidCrystal.h>

#define Relay_pin 12
LiquidCrystal lcd(10,11,4,5,6,7);

int state=0 ;
int sec_15=15;  
int sec_30=30;
int sec_45=45;
int sec_60=60;

void setup() 
{
 lcd.begin(16,2);
 pinMode(Relay_pin, OUTPUT);
 digitalWrite(Relay_pin, LOW);
 Serial.begin(9600);// put your setup code here, to run once:
 lcd.print("Time Based");
 delay(2000);
 lcd.setCursor(0,1);
 lcd.print("Charging Control");
 delay(2000);
}


void loop() {
 // put your main code here, to run repeatedly:
 lcd.clear();
 lcd.print("Waiting for...");
 lcd.setCursor(0,1);
 lcd.print("Input :)");
 delay(500);
 if(Serial.available()>0)
   {     
      state= Serial.read(); // reading the data received from the bluetooth module
   }
   charging(); 
   
   delay(50);
}

void charging()
{
   if(state == '1')
        {
          digitalWrite(Relay_pin, HIGH);
          count1();
          //Serial.println("led:off");
          digitalWrite(Relay_pin, LOW);
          lcd.clear();
          lcd.print("Thank you... (:");
          delay(2000);
          state='0';
        }
          else if(state == '2')
        {
          
          digitalWrite(Relay_pin, HIGH);
          count2();
          digitalWrite(Relay_pin, LOW);
          lcd.clear();
          lcd.print("Thank you... (:");
          delay(2000);
         // Serial.println("led:oN");
          state='0';
        }
          else if(state == '3')
        {
         digitalWrite(Relay_pin, HIGH);
         count3();
         digitalWrite(Relay_pin, LOW);
          lcd.clear();
          lcd.print("Thank you... (:");
          delay(2000);
         //Serial.println("led:oN");
         state='0';
        }
          else if(state == '4')
        {
         digitalWrite(Relay_pin, HIGH);
         count4();
         digitalWrite(Relay_pin, LOW);
          lcd.clear();
          lcd.print("Thank you... (:");
          delay(2000);
         //Serial.println("led:oN");
         state='0';
        }
        else if(state == '9')
        {
          digitalWrite(Relay_pin, LOW);
          lcd.clear();
          lcd.print("Thank you... (:");
          delay(2000);
         //Serial.println("led:oN");
         state='0';
        }
        
}


void count1()
{
  while(sec_15>=0)
  {
    lcd.clear();
          lcd.print("Charging...!");
          lcd.setCursor(0,1);
          lcd.print("Time Left:");
          lcd.print(sec_15);
          delay(1000);
          sec_15-=1;
  }
  sec_15=15;
}

void count2()
{
  while(sec_30>=0)
  {
    lcd.clear();
          lcd.print("Charging...!");
          lcd.setCursor(0,1);
          lcd.print("Time Left:");
          lcd.print(sec_30);
          delay(1000);
          sec_30-=1;
  }
  sec_30=30;
}

void count3()
{
  while(sec_45>=0)
  {
    lcd.clear();
          lcd.print("Charging...!");
          lcd.setCursor(0,1);
          lcd.print("Time Left:");
          lcd.print(sec_45);
          delay(1000);
          sec_45-=1;
  }
  sec_45=45;
}

void count4()
{
  while(sec_60>=0)
  {
    lcd.clear();
          lcd.print("Charging...!");
          lcd.setCursor(0,1);
          lcd.print("Time Left:");
          lcd.print(sec_60);
          delay(1000);
          sec_60-=1;
  }
  sec_60=60;
}
