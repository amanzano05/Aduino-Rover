void fallLine () {
char BestDirection;
Speed(MIN_SPEED);
do{
displaySpeed();
RRead = digitalRead(rIR);
LRead = digitalRead(lIR);
if (RRead==LOW && LRead==LOW){
  movement('F');
  }else{
       if (RRead==HIGH){
           movement('B');
           delay(1000);
           movement('L');
           delay(800);
        }
        if (LRead==HIGH){
           movement('B');
           delay(1000);
           movement('R');
           delay(800);
        }
   }      
readBluetooth();
}while(mode==4);
}
