
void ReadLine () {
Speed(MIN_SPEED);
do{
  displaySpeed();
  RRead = digitalRead(rIR);
  LRead = digitalRead(lIR);
  while(RRead==HIGH && LRead==HIGH && mode==3){
      displaySpeed();
      movement('S');
      RRead = digitalRead(rIR);
      LRead = digitalRead(lIR);
      readBluetooth();
   }
  if (RRead==LOW && LRead==LOW){movement('F');}
  else{
        if (RRead==HIGH && LRead==LOW){
          movement('R');
          delay(250);
        }

        if (LRead==HIGH && RRead==LOW){
          movement('L');
          delay(250);
        }
  }
readBluetooth();
}while(mode==3);
}
