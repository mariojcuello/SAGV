#include "DualG2HighPowerMotorShield.h"
DualG2HighPowerMotorShield24v14 md;

byte RIGHT_PIN = 5;
byte LEFT_PIN = 11;
 
int right_pwm;
int left_pwm;

int right_speed;
int left_speed;

void stopIfFault()
{
  if (md.getM1Fault())
  {
    md.disableDrivers();
    delay(1);
    Serial.println("M1 fault");
    while (1);
  }
  if (md.getM2Fault())
  {
    md.disableDrivers();
    delay(1);
    Serial.println("M2 fault");
    while (1);
  }
}

void setup() {
  pinMode(RIGHT_PIN, INPUT);
  pinMode(LEFT_PIN, INPUT);
  Serial.begin(9600);
  md.init();
  md.calibrateCurrentOffsets();
  delay(1000);
}
 
void loop() {
  
  md.enableDrivers();
  delay(1);
  
  right_pwm = pulseIn(RIGHT_PIN, HIGH);
  left_pwm = pulseIn(LEFT_PIN, HIGH);
  
  right_speed = map(right_pwm, 1180, 1890, -410, 410);
  left_speed = map(left_pwm, 1200, 2000, -400, 410);
  Serial.println(right_pwm);
  Serial.println(right_speed);
  Serial.println(left_pwm);
  Serial.println(left_speed);

  md.setM1Speed(right_speed);
  md.setM2Speed(left_speed);     
  
  stopIfFault();

}
