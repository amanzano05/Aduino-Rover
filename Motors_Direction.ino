
/*---------------------------------------------------------------------------------------*/
//function to move motors forward
void forward (){
  leftMotor1->run(FORWARD);
  leftMotor2->run(FORWARD);
  rightMotor1->run(FORWARD);
  rightMotor2->run(FORWARD);
}

/*---------------------------------------------------------------------------------------*/
//function to move backward
void backward(){
  leftMotor1->run(BACKWARD);
  leftMotor2->run(BACKWARD);
  rightMotor1->run(BACKWARD);
  rightMotor2->run(BACKWARD);
}

/*---------------------------------------------------------------------------------------*/
//function to move left
void left(){
   leftMotor1->run(BACKWARD);
   leftMotor2->run(BACKWARD);
   rightMotor1->run(FORWARD);
   rightMotor2->run(FORWARD);
}

/*---------------------------------------------------------------------------------------*/
//function to move right
void right(){
    leftMotor1->run(FORWARD);
    leftMotor2->run(FORWARD);
    rightMotor1->run(BACKWARD);
    rightMotor2->run(BACKWARD);
}

/*---------------------------------------------------------------------------------------*/
//function to move forward and to the right
void FRight(){//forward right
  leftMotor1->setSpeed(MAX_SPEED);
  leftMotor2->setSpeed(MAX_SPEED);
  leftMotor1->run(FORWARD);
  leftMotor2->run(FORWARD);
  rightMotor1->setSpeed(MIN_SPEED);
  rightMotor2->setSpeed(MIN_SPEED);
  rightMotor1->run(FORWARD);
  rightMotor2->run(FORWARD);
}

/*---------------------------------------------------------------------------------------*/
//function to move forward and to the left
void FLeft(){
  rightMotor1->setSpeed(MAX_SPEED);
  rightMotor2->setSpeed(MAX_SPEED);
  rightMotor1->run(FORWARD);
  rightMotor2->run(FORWARD);
  leftMotor1->setSpeed(MIN_SPEED);
  leftMotor2->setSpeed(MIN_SPEED);
  leftMotor1->run(FORWARD);
  leftMotor2->run(FORWARD);
}

/*---------------------------------------------------------------------------------------*/
//function to move backward and to the right
void BRight(){
  leftMotor1->setSpeed(MAX_SPEED);
  leftMotor2->setSpeed(MAX_SPEED);
  leftMotor1->run(BACKWARD);
  leftMotor2->run(BACKWARD);
  rightMotor1->setSpeed(MIN_SPEED);
  rightMotor2->setSpeed(MIN_SPEED);
  rightMotor1->run(BACKWARD);
  rightMotor2->run(BACKWARD);
}

/*---------------------------------------------------------------------------------------*/
//function to move backward and to the left
void BLeft(){
  rightMotor1->setSpeed(MAX_SPEED);
  rightMotor2->setSpeed(MAX_SPEED);
  rightMotor1->run(BACKWARD);
  rightMotor2->run(BACKWARD);
  leftMotor1->setSpeed(MIN_SPEED);
  leftMotor2->setSpeed(MIN_SPEED);
  leftMotor1->run(BACKWARD);
  leftMotor2->run(BACKWARD);
}

/*---------------------------------------------------------------------------------------*/
// function to stop motors
void Stop(){ //stop
  rightMotor1->run(RELEASE);
  rightMotor2->run(RELEASE);
  leftMotor1->run(RELEASE);
  leftMotor2->run(RELEASE);
} 
