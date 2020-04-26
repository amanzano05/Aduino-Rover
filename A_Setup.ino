
/*-----------------------------------setup function--------------------------------------*/
/*---------------------------------------------------------------------------------------*/

//this function runs once to set everything ready. 
void setup() {
  Serial.begin(9600);
  analogWrite(V0, 100);
  lcd.begin(16, 20);
  lcd.clear();
  lcd.print("Hello");
  btSet(); 
  motorSet();
  startP=false;
  endP=false;
}
