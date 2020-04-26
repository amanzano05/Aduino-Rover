
 /*---------------------------------------------------------------------------------------*/
//funtion to set up bluetooth communication
void btSet(){
  bluetooth.begin(9600);  
}


/*---------------------------------------------------------------------------------------*/
/*funtion for reading the input from bluetooth. The packet is sent in the format 
'sX=value,Y=valuee sC=1e', for example 'sX=10,Y=6e sC=1e', where X and Y are coordinates
and C is the mode. I used the app's example as a reference*/
void readBluetooth(){
while(bluetooth.available()){
      char inChar= (char)bluetooth.read();
      if (inChar=='s'){
        startP=true;
        endP=false;
        index=0;
        inPacket[index]='\0';
      }
      else if (inChar=='e'){
        endP=true;
        break;
      }
      else {
        if (index<19){
          inPacket[index]=inChar;
          index++;
          inPacket[index]='\0';
        }
      }
    }
if(startP && endP)
  {
    char *name = strtok(inPacket, "=");
    while(name)
    {
      char *valToken = strtok(NULL, ",");
      if(valToken)
      {
        int val = atoi(valToken);
        if(strcmp(name, "X") == 0)
        {
          xVal = val;
        }
        else if(strcmp(name, "Y") == 0) 
        {
          yVal = val;
        }
        else if(strcmp(name, "C") == 0) 
        {
          mode = val;
        }
      }
      name = strtok(NULL, "=");
    }
   }    
}
