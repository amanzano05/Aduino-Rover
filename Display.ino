


void displaySpeed(){
 long now=millis();
  int presentRead=digitalRead(2);
  if (lastState==LOW && presentRead==HIGH){
    count++;
    lastState=HIGH;
   // Serial.println(count);
  }
  if (lastState==HIGH && presentRead==LOW){
    lastState=LOW;
    
  }
  if (now-previousTime>2000){
    previousTime=now;
    rpm=(count/20.00)*60;
    velocity=(rpm*60*2.65*3.1416)/63360;
    String msg=String(velocity);
    msg=String(msg + " MpH");
    printLCD("Speed: ", msg);
    Serial.println(velocity);
    count=0;
  }
}




/*---------------------------------------------------------------------------------------*/
void printLCD(String msg1, String msg2){
  lcd.print("                      ");
  lcd.setCursor(0,1);
  lcd.print("      ");
  lcd.setCursor(0, 0);
  lcd.print(msg1);
  lcd.setCursor(0,1);
  lcd.print(msg2);
}
