
#include "HeepDeviceDefinitions.h"
#include <Servo.h>

#define SERVOMOVE_PIN 14
Servo myservo;

void InitializeControlHardware(){
  pinMode(SERVOMOVE_PIN,OUTPUT);
}

int WriteServoMove(){
  int currentSetting = GetControlValueByName("ServoMove");
  myservo.write(map(currentSetting,0,100,0,180));
  return currentSetting;
}

void setup()
{

  Serial.begin(115200);
  myservo.attach(SERVOMOVE_PIN);
  InitializeControlHardware();
  AddRangeControl("ServoMove",HEEP_INPUT,100,0,0);
  StartHeep("Servo", 8);

}

void loop()
{
  PerformHeepTasks();
  WriteServoMove();

}