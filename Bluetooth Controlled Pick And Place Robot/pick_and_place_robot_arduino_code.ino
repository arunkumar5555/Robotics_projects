#include<AFMotor.h>
#include<Servo.h>
AF_DCMotor motorR(1);
AF_DCMotor motorL(2);
Servo elbowServo;
Servo gripperServo;
int command;

void setup() {

gripperServo.attach(9);
elbowServo.attach(10);
Serial.begin(9600);
motorR.setSpeed(255);
motorL.setSpeed(255);
}

void loop() {
command = Serial.read();

                                        /*     ARM Code    */

if(command>=1 && command <=180)   //elbow servo move according to the thumb position on the mob app between 0 -- 180  .
{
  elbowServo.write(command);
}
else if (command == 205)    //Gripper Move To Angle 0
{
  gripperServo.write(0);
}
else if (command == 206)    //Gripper movw to angle 90
{
  gripperServo.write(90);  
}
else if (command == 207)    //gripper move to angle 180
{
  gripperServo.write(180);
}

                                            /*  CAR CODE  */  

else if (command == 200)
{
  motorR.run(FORWARD);
  motorL.run(FORWARD);
}
else if(command == 201)
{
  motorR.run(FORWARD);
  motorL.run(BACKWARD);  
}
else if(command == 202)
{
  motorR.run(RELEASE);
  motorL.run(RELEASE);  
}
else if(command == 203)
{
  motorR.run(BACKWARD);
  motorL.run(FORWARD);  
}
else if(command == 204)
{
  motorR.run(BACKWARD);
  motorL.run(BACKWARD);  
}
else if(command == 0)
{
  motorR.run(RELEASE);
  motorL.run(RELEASE);  
}
}
