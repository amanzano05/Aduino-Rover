
//funtion to avoid obstacles
void avoidOsbtacles(){
 Speed(MIN_SPEED);
 do{
 displaySpeed();
 Cscan=ultraC.ping_cm();
 delay(50);
 if (Cscan==0){Cscan=100;};
 Lscan=ultraL.ping_cm();
 delay(50);
 if (Lscan==0){Lscan=100;}
 Rscan=ultraR.ping_cm();
 delay(50);
 if (Rscan==0){Rscan=100;}
 calDir();
 readBluetooth();
 }while(mode==2);        
}


/*---------------------------------------------------------------------------------------*/
//function to choose best path
void calDir(){   
   if (Cscan<10){
          Serial.println("Stop");
          Stop();
    }
   if (Lscan>COLLISIONDIST && Cscan>COLLISIONDIST && Rscan>COLLISIONDIST){
      Serial.print("forward ");
      Serial.println(Cscan);
      forward();
    }
   if (Lscan>COLLISIONDIST && Cscan>COLLISIONDIST && Rscan<COLLISIONDIST){
      Serial.print("left ");
      Serial.println(Lscan);
      left();
    }
    if (Lscan>COLLISIONDIST && Cscan<COLLISIONDIST && Rscan>COLLISIONDIST){
      Serial.print("Right ");
      Serial.println(Rscan);
      right();
    }
    if (Lscan>COLLISIONDIST && Cscan<COLLISIONDIST && Rscan<COLLISIONDIST){
      Serial.print("Left ");
      Serial.println(Lscan);
      left();
    }
    if (Lscan<COLLISIONDIST && Cscan>COLLISIONDIST && Rscan>COLLISIONDIST){
      Serial.print("Right ");
      Serial.println(Rscan);
      right();
    }
    if (Lscan<COLLISIONDIST && Cscan>COLLISIONDIST && Rscan<COLLISIONDIST){
      Serial.print("forward ");
      Serial.println(Cscan);
      forward();
    }
    if (Lscan<COLLISIONDIST && Cscan<COLLISIONDIST && Rscan<COLLISIONDIST){
      Serial.print("Back ");
      Serial.println(Cscan);
      backward();
      delay(800);
      left();
      delay(1600);
    }            
}
