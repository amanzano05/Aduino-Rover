

/*---------------------------------------------------------------------------------------*/
/*-------------------------------------Main loop-----------------------------------------*/
/*---------------------------------------------------------------------------------------*/
//main loop 
void loop() {
  Speed(MAX_SPEED);
  displaySpeed();
  readBluetooth();
  switch (mode){
     case 0:
      BTRead='S';
      break;
     case 1: 
      RCcar();
      break;
     case 2 : 
      avoidOsbtacles();
      break;
     case 3 :
      ReadLine();
      break;
     case 4 :
      fallLine();
  }
}
