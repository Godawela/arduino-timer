#include <LiquidCrystal.h> // library for the LCD
LiquidCrystal lcd(7, 6, 5, 4, 3, 2); // pins of Arduino for LCD
// initializing the variables
int hrs =2;  // hours
int mins = 0;  // minutes
int sec = 0;  // seconds
int h;
int z;
int m;
int s;
const int buttonPin = A4;
int buttonState;
const int buzzer = 9; //buzzer
void setup()
{
  lcd.begin(16, 2); // initializing the dimensions of LCD
  pinMode(buzzer, OUTPUT); // Set buzzer - pin 9 as an output
  pinMode(buttonPin, INPUT);

}
void loop()
{
  buttonState = digitalRead(buttonPin);
  if (buttonState == LOW) {
  lcd.setCursor(0, 0);
  
// displaying the time
  lcd.print("TIME:" );
  lcd.print(hrs);
  lcd.print(":");
  lcd.print(mins);
  lcd.print(":");
  lcd.print(sec);

delay(800); 


  if (sec == 60)   /* seconds is equal to 60 then again start from zero and add an increment of one in the minute value */
  {
    
    sec = 0;
    mins = mins + 1;
  };
  if (mins == 60)
  {
/* if minute is equal to 60 then again start from zero and add an increment of one in the hour value */
    
    mins = 0;
    hrs = hrs + 1;
   
  };
/* if hour value is 24 then replace its value from 24 to 0 to changet*/

  if (hrs == 24)
  {
    
    hrs = 0;
  };
sec++;



  if (hrs==2) { 
       z=2; 
       sec=0;  
       hrs=0;
       mins=0;
   lcd.setCursor(0, 1);
  lcd.print("Get Up"); 
  digitalWrite(buzzer, HIGH);
  delay(5000);                      // wait for a second
  digitalWrite(buzzer, LOW);   // turn the LED off by making the voltage LOW
  delay(1000);                      // wait for a second
  lcd.clear();
  sec++;
  
};

  }
   
else {  
              s=s+sec; 
              m=m+mins;
              h=h+hrs+z;  
               
                 
                
                if(s>=60){
                    
                    s=s-60;
                    m++;
                } ;
                
               
                if (m>=60){
                    s=0;
                    m=m-60;
                    h++;
                } ;
               
                if(h>=24){
                    s=0;
                    m=0;
                    h=0;
                };                

                lcd.clear();
                lcd.setCursor(0, 0);
                
                lcd.print(h);
                lcd.print(":");
                lcd.print(m);
                lcd.print(":");
                lcd.print(s);

               lcd.setCursor(0,1);
               lcd.print("Daily Prograss ");
                
                delay(200);      
                lcd.clear();
                
                sec=0;
                mins=0;
                hrs=0; 
                z=0;

                
};  
           
               
};
  

