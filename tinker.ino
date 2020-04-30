/*Arduino code for testing guitar bot circuit on tinkercad
    How this code is different from the code that is to be used in the real model?
    Ans : This code doesn't use Adafruit library as it not supported in tinkercad.com. This code has also been modified in such a 
          way to make use of piezos to create tune according to the servo motors movement.*/

#include<Servo.h>


Servo servo2;
Servo servo3;
Servo servo4;
Servo servo7;
Servo servo8;
Servo servo9;
Servo servo10;
Servo servo11;

int angle1 = 0;
int angle2 = 0;
int angle3 = 0;
int angle4 = 0;
int angle5 = 0;
int angle6 = 0;
int angle7 = 0;
int angle8 = 0;
int angle9 = 0;
int angle10 = 0;
int angle11 = 0;


void setup()
{
  
  servo2.attach(12);
  servo3.attach(9);
  servo4.attach(8);
  servo7.attach(5);
  servo8.attach(4);
  servo9.attach(3);
  servo10.attach(2);
  servo11.attach(1);
  pinMode(13,OUTPUT);
}

void loop()
{
  int i = 0;
    

                
    C(angle10 , angle5);
     angle10 = 45;
  tone(13 , 262); /*C*/
 
  delay(80);
  
   noTone(13);
  C(angle10 , angle5);
    angle10 = 0;
  tone(13 , 262); /*C*/
  
   delay(80);
   noTone(13);
                                  

  D(angle9);
  tone(13 , 284);
  angle9 = 45;
   delay(80);
  noTone(13);
  
  
  C(angle10 , angle5);
  angle10 = 45;
  tone(13 , 262); 
   delay(80);
  noTone(13);
  
  f(angle4 , angle9);
  angle9 = 0;
  tone(13,349);
   delay(80);
  noTone(13);
  
  E(angle2 , angle9);
  angle9 = 45;
  tone(13,330);
  delay(300);
  noTone(13);
  
  C(angle10 , angle5);
  angle10 = 0;
  tone(13 , 262);
   delay(80);
  noTone(13);
  
  D(angle9);
  angle9 = 0;
  tone(13 , 284);
   delay(80);
  noTone(13);
  
  C(angle10 , angle5);
  angle10 = 45;
  tone(13 , 262);
   delay(80);
  noTone(13);
  
  G(angle8);
  angle8 = 45;
  tone(13 , 392);
   delay(80);
  noTone(13);
  
  f(angle4, angle9);
  angle9  = 45;
  tone(13 , 349);
   delay(300);
  noTone(13);

  C(angle10 , angle5);
  angle10 = 0;
  tone(13 , 262);
   delay(80);
  noTone(13);
  
  C(angle10 , angle5);
  angle10 = 45;
  tone(13 , 262);
   delay(80);
  noTone(13);
  
  
  C(angle10 , angle5);
  angle10 = 0;
  tone(13 , 262);
   delay(80);
  noTone(13);
  
  
  A( angle1 , angle8);
  angle8 = 0;
  tone(13 , 440);
   delay(80);
  noTone(13);
  
  f( angle4 , angle9);
  angle9 = 0;
  tone(13 , 349);
  delay(80);
  noTone(13);
  
  E(angle2, angle9);
  angle9 = 45;
  tone(13,330);
   delay(80);
  noTone(13);
  
  
  D(angle9);
  angle9 = 0;
  tone(13 , 284);
  delay(300);
  noTone(13);

                                    
  A_sharp(angle3, angle8);
  angle8 = 45;
  tone(13 , 466);
  delay(80);
  noTone(13);
  
  A(angle1 , angle8);
  angle8 = 0;
  tone(13 , 440);
   delay(80);
  noTone(13);
  
  f(angle4, angle9);
  angle9 = 45;
  tone(13 , 349);
   delay(80);
  noTone(13);
  
  G(angle8);
  angle8 = 45;
  tone(13 , 392);
  delay(80);
  noTone(13);
  
  f(angle4, angle9);
  angle9 = 0 ;
  tone(13 , 349);
  delay(80);
  noTone(13);

                                 
      
  delay(1000);
 
}


void C(int angle5 , int angle10)
{
  for(angle5 = 0 ; angle5 < 30 ; angle5++)
    servo7.write(angle5); 
  delay(20);
  
  if(angle10 == 0)
  {
    for(angle10 = 0 ; angle10 < 45 ; angle10++)
      servo2.write(angle10);
    angle10 = 45;
    delay(20);
  }
  else
  {
    for(angle10 = 45 ; angle10 > 0 ; angle10--)
      servo2.write(angle10);
    angle10 = 0;
    delay(20);
  }
  for(angle5 = 30 ; angle5 > 0 ; angle5--)
    servo7.write(angle5);
  delay(20);
}

void D(int angle9)
{
  if(angle9 == 0)
  {
    for(angle9 = 0 ; angle9 < 45 ; angle9++)
      servo3.write(angle9);
    angle9 = 45;
    delay(20);
  }
  else
  {
    for(angle9 = 45 ; angle9 > 0 ; angle9--)
      servo3.write(angle9);
    angle9 = 0;
    delay(20);
  }
}

void f(int angle4 , int angle9)
{
  for(angle4 = 0 ; angle4 < 30 ; angle4++)
    servo8.write(angle4);
  delay(20);
  
  if(angle9 == 0)
  {
    for(angle9 = 0 ; angle9 < 45 ; angle9++)
      servo3.write(angle9);
    angle9 = 45;
    delay(20);
  }
  else
  {
    for(angle9 = 45 ; angle9 > 0 ; angle9--)
      servo3.write(angle9);
    angle9 = 0;
    delay(20);
  }
  for(angle4 = 30 ; angle4 > 0 ; angle4--)
    servo8.write(angle4);
  delay(20);
}

void E(int angle2, int angle9)
{
  for(angle2 = 0 ; angle2 < 30 ; angle2++)
    servo10.write(angle2);
  delay(20);
  
  if(angle9 == 0)
  {
    for(angle9 = 0 ; angle9 < 45 ; angle9++)
      servo3.write(angle9);
    angle9 = 45;
    delay(20);
  }
  else
  {
    for(angle9 = 45 ; angle9 > 0 ; angle9--)
      servo3.write(angle9);
    angle9 = 0;
    delay(20);
  }
  
  for(angle2 = 30 ; angle2 >  0 ; angle2--)
    servo10.write(angle2);
  delay(20);
}

void G(int angle8)
{
  if(angle8 == 0)
  {
    for(angle8 = 0 ; angle8 < 45 ; angle8++)
      servo4.write(angle8);
    angle8 = 45;
    delay(20);
  }
  else
  {
    for(angle8 = 45 ; angle8 > 0 ; angle8--)
      servo4.write(angle8);
    angle8 = 0;
    delay(20);
  }
}

void A(int angle1 , int angle8)
{
  for(angle1 = 0 ; angle1 < 30 ; angle1++)
    servo11.write(angle1);
  delay(20);
  
  if(angle8 == 0)
  {
    for(angle8 = 0 ; angle8 < 45 ; angle8++)
      servo4.write(angle8);
    angle8 = 45;
    delay(20);
  }
  else
  {
    for(angle8 = 45 ; angle8 > 0 ; angle8--)
      servo4.write(angle8);
    angle8 = 0;
    delay(20);
  }
  
  for(angle1 = 30 ; angle1 > 0 ; angle1--)
    servo11.write(angle1);
  delay(20);
}
  
void A_sharp(int angle3 , int angle8)
{
  for(angle3 = 0 ; angle3 < 30 ; angle3++)
    servo9.write(angle3);
  delay(20);
  
  if(angle8 == 0)
  {
    for(angle8 = 0 ; angle8 < 45 ; angle8++)
      servo4.write(angle8);
    angle8 = 45;
    delay(20);
  }
  else
  {
    for(angle8 = 45 ; angle8 > 0 ; angle8--)
      servo4.write(angle8);
    angle8 = 0;
    delay(20);
  }
  
  for(angle3 = 30 ; angle3 > 0 ; angle3--)
    servo9.write(angle3);
  delay(20);
}
