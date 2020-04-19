/*Arduino code for guitar bot
    Author : Akash Kumbar

    Edits made = 0
    Edits log = NULL
    
    This bot is controlled through an android app.
    For controlling the servo motors a 16 servo PCA9685 controller is used
    So, to run this code Adafruit_PWMServoDriver header library should be downloaded.

    FAQ :
    (1) Why the function is named 'f' instead of 'F'?
    Ans : F is a predefined macro, so the name of the function has to be changed to f.
*/


#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>   //Additional library needs to be downloaded to run this code..

// called this way, it uses the default address 0x40
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
// you can also call it with a different address you want
//Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x41);


//The below SERVOMIN and SERVOMAX can be used with tower-pro servo SG-90 and MG-90, but for other servos it might vary..
#define SERVOMIN  125 // this is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX  575 // this is the 'maximum' pulse length count (out of 4096)

// The below naming are for servo motors(SG-90) at the strumming unit :
#define servo6 6
#define servo7 7
#define servo8 8
#define servo9 9
#define servo10 10
#define servo11 11

//And the below naming are for servo motors(MG-90) at the fret system :
#define servo1 1 
#define servo2 2 
#define servo3 3 
#define servo4 4 
#define servo5 5 
 
//To understand where the servo motors are placed on the guitar, visit :  

// our servo # counter
uint8_t servonum = 0;

void setup() {
  Serial.begin(9600);
  Serial.println("Guitar bot!!");

  pwm.begin();
  
  pwm.setPWMFreq(60);  // Analog servos run at ~60 Hz updates

  //yield();
}


void loop() {
      int i = 0;
      //The below variables represent the angle of servo motor.
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

      if(Serial.available()>'0')
      {                                     //input from bluetooth
          char data=(char)Serial.read();
          char choice;

          switch(data)
          {
              case 'a' : while(1)
                          {
                              choice = (char)Serial.read();
                              if(choice == '1')
                              {
                                  for( i = 0 ; i < 2 ; i++)
                                  {
                                        C(angle10 , angle5);
                                        delay(20);
                                  }

                                        D(angle9);
                                        delay(20);
                                        C(angle10 , angle5);
                                        delay(20);
                                        f(angle4 , angle9);
                                        delay(20);
                                        E(angle2 , angle9);
                                        delay(50);

                                  for ( i = 0 ; i < 2 ; i++)
                                  {
                                        C(angle10 , angle5);
                                        delay(20);
                                  }
                                        D(angle9);
                                        delay(20);
                                        C(angle10 , angle5);
                                        delay(20);
                                        G(angle8);
                                        delay(20);
                                        f(angle4, angle9);
                                        delay(50);

                                    for(i = 0 ; i < 3 ; i++)
                                    {
                                        C(angle10 , angle5);
                                        delay(20);
                                    }
                                        A( angle1 , angle8);
                                        delay(20);
                                        f( angle4 , angle9);
                                        delay(20);
                                        E(angle2, angle9);
                                        delay(20);
                                        D(angle9);
                                        delay(50);

                                      for( i = 0 ; i < 2 ; i++)
                                      {
                                          A_sharp(angle3, angle8);
                                          delay(20);
                                      }
                                          A(angle1 , angle8);
                                          delay(20);
                                          f(angle4, angle9);
                                          delay(20);
                                          G(angle8);
                                          delay(20);
                                          f(angle4, angle9);
                                          delay(50);

                                  }
                                  else
                                    break;
                          }
                                  break;
                          }
                          
            
          }
      
    delay(1000);
 
}



 //The below function converts the angle(in degrees) to pulse width, as the servo controller used in this project uses pulse width, not angles..
int angleToPulse(int ang){
   int pulse = map(ang,0, 180, SERVOMIN,SERVOMAX);// map angle of 0 to 180 to Servo min and Servo max 

   return pulse;
}


//The below written functions are for different music notes
//Right now the music notes required to play the tunes are : C, D, F, E, G, A, A#


void C(int angle10 , int angle5)
{
    int angle = 0;
    pwm.setPWM(servo5 , 0 , angleToPulse(30));
    if(angle10 == 0)
    {
        angle = 45;
        pwm.setPWM(servo10 , 0 , angleToPulse(angle) );
        angle10 = angle ;
    }
    else
    {
        angle = 0;
        pwm.setPWM(servo10 , 0 , angleToPulse(angle) );
        angle10 = angle;
    }
    pwm.setPWM(servo5 , 0 , angleToPulse(0) );
}


void D(int angle9)
{
    int angle = 0;
    
    if(angle9 == 0)
    {
        angle = 45;
        pwm.setPWM(servo9 , 0 , angleToPulse(angle) );
        angle9 = angle ;
    }
    else
    {
        angle = 0;
        pwm.setPWM(servo9 , 0 , angleToPulse(angle) );
        angle9 = angle;
    }
}

void f(int angle4, int angle9)
{
    int angle = 0;

    pwm.setPWM(servo4 , 0 , angleToPulse(30));

    if(angle9 == 0)
    {
        angle = 45;
        pwm.setPWM(servo9 , 0 , angleToPulse(angle) );
        angle9 = angle ;
    }
    else
    {
        angle = 0;
        pwm.setPWM(servo9 , 0 , angleToPulse(angle) );
        angle9 = angle;
    }
    pwm.setPWM(servo4 , 0 , angleToPulse(0));
}

void E(int angle2, int angle9)
{
    int angle = 0;

    pwm.setPWM(servo2 , 0 , angleToPulse(30) );

    if(angle9 == 0)
    {
        angle = 45;
        pwm.setPWM(servo9 , 0 , angleToPulse(angle) );
        angle9 = angle ;
    }
    else
    {
        angle = 0;
        pwm.setPWM(servo9 , 0 , angleToPulse(angle) );
        angle9 = angle;
    }

    pwm.setPWM(servo2 , 0 , angleToPulse(0) );
}

void G(int angle8)
{
    int angle = 0;

    if(angle8 == 0)
    {
        angle = 45;
        pwm.setPWM(servo8 , 0 , angleToPulse(angle) );
        angle8 = angle ;
    }
    else
    {
        angle = 0;
        pwm.setPWM(servo8 , 0 , angleToPulse(angle) );
        angle8 = angle;
    } 
}

void A(int angle1 , int angle8)
{
    int angle = 0;

    pwm.setPWM(servo1 , 0 , angleToPulse(30) );

    if(angle8 == 0)
    {
        angle = 45;
        pwm.setPWM(servo8 , 0 , angleToPulse(angle) );
        angle8 = angle ;
    }
    else
    {
        angle = 0;
        pwm.setPWM(servo8 , 0 , angleToPulse(angle) );
        angle8 = angle;
    }

    pwm.setPWM(servo1 , 0 , angleToPulse(0) );
}

void A_sharp(int angle3, int angle8)
{
    int angle = 0;

    pwm.setPWM(servo3 , 0 , angleToPulse(30) );

    if(angle8 == 0)
    {
        angle = 45;
        pwm.setPWM(servo8 , 0 , angleToPulse(angle) );
        angle8 = angle ;
    }
    else
    {
        angle = 0;
        pwm.setPWM(servo8 , 0 , angleToPulse(angle) );
        angle8 = angle;
    }

    pwm.setPWM(servo3 , 0 , angleToPulse(0) );
}
