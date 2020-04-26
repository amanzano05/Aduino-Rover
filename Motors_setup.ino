/*---------------------------------------------------------------------------------------*/
//function to set the speed of the motors
void Speed(int speedSet){
  leftMotor1->setSpeed(speedSet); 
  leftMotor2->setSpeed(speedSet); 
  rightMotor1->setSpeed(speedSet); 
  rightMotor2->setSpeed(speedSet); 
}


/*---------------------------------------------------------------------------------------*/
// function to set up the motors
void motorSet(){
  MotorShield.begin(1600); 
  leftMotor1->setSpeed(60);
  leftMotor2->setSpeed(60);
  leftMotor1->run(FORWARD); 
  leftMotor2->run(FORWARD); 
  leftMotor1->run(RELEASE);
  leftMotor2->run(RELEASE);
  rightMotor1->setSpeed(60);
  rightMotor2->setSpeed(60);
  rightMotor1->run(FORWARD);
  rightMotor2->run(FORWARD);
  rightMotor1->run(RELEASE);
  rightMotor2->run(RELEASE);
}
