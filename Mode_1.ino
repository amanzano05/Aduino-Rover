
/*---------------------------------------------------------------------------------------*/
// funtion to control the robot manually
void RCcar(){
do{
  Speed(MAX_SPEED);
  displaySpeed();
  if(xVal==0 && yVal==0){BTRead='S';}
   if(yVal>0 && -2*xVal<yVal && 2*xVal<yVal){
    BTRead='F';
    }
   if(yVal<0 && -2*xVal>yVal && 2*xVal>yVal){
    BTRead='B';
    } 
   if(yVal>0 && -2*xVal>yVal && -2*yVal<xVal){BTRead='G';}
   if(xVal<0 && -2*yVal>xVal && 2*yVal>xVal){BTRead='L';}
   if(xVal>0 && -2*yVal<xVal && 2*yVal<xVal){BTRead='R';}
   if(yVal>0 && 2*xVal>yVal && 2*yVal>xVal){BTRead='I';}
   if(yVal<0 && 2*xVal<yVal && 2*yVal<xVal){BTRead='H';}
   if(yVal<0 && -2*xVal<yVal && -2*yVal>xVal){BTRead='J';}
   movement(BTRead);
   readBluetooth();
} while(mode==1);
}


/*---------------------------------------------------------------------------------------*/
//function to move the motor according to best path
void movement(char Direction){
  if(Direction == 'F'){forward(); }
  if(Direction == 'B'){backward();}
  if(Direction == 'L'){left();}
  if(Direction == 'R'){right();}
  if(Direction == 'I'){FRight();}
  if(Direction == 'G'){FLeft();}
  if(Direction == 'J'){BRight();}
  if(Direction == 'H'){BLeft();}
  if (Direction == 'S'){Stop();} 
}
