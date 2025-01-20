#include <Servo.h> // servo library
Servo s1;
FEEDING_INTERVAL = 4000 ; //entered in milliseconds, edit to match your needs
void setup()
{ 
  pinMode(3,OUTPUT);
 s1.attach(5);    // servo attach 3 pin of arduino

}
void loop() 
{
  
s1.write(140);
digitalWrite(3,LOW);
delay(FEEDING_INTERVAL);

s1.write(0);
digitalWrite(3,HIGH);
delay(1000);

}
