// Created by Alfonso Manzano on 11/1/18.
// Copyright © 2017 Alfonso Manzano. All rights reserved.

/*The robot uses a bluetooth connection to operate. It has two modes that can be
selected from the app on the phone. The first mode (manual mode) uses a joystick
in the phone to operate the robot. The second mode(obstacle avoidance) uses a 
ultrasonic sensor to detect objects and calculate distances to choose the best path. */

/*-----------------------------------Libraries---------------------------------------------*/
#include <SoftwareSerial.h> //library used for bluetooth
#include <Adafruit_MotorShield.h> //library used for motorshield
#include <NewPing.h>//ultrasonic sensor
#include <LiquidCrystal.h>



/*-----------------------------------pins used---------------------------------------------*/
//------------LCD----------//
#define V0 3
#define EN 13
#define RS 12
#define D4 4
#define D5 5
#define D6 6
#define D7 7 
//------------Bluetooth----------//
#define BLUETOOTH_TX  8 // pin Tx for bluetooth communication
#define BLUETOOTH_RX  9 // pin RX for bluetooth communication
//------------Infrared----------//
#define rIR 10
#define lIR 11
//------------Ultrasonic-----------//
#define TRIGGER A0

/*---------------------------Constants-----------------------------*/
//----------Ultrasonic------------//
#define COLLISIONDIST 40 // constant 30 cm to collision
#define MAXDISTANCE 50 //max distance to read

//------------LCD----------//
#define CONTRAST 100//lcd contrast on V0



//-----speed for motors----//
#define MAX_SPEED 250
#define MIN_SPEED 100



/*----------------------------------Variables-----------------------------------------------*/
int Lscan,Rscan, Cscan; //variables for the ultrasonic detect objects.
int xVal, yVal, mode; //variables for calculating the coordinates of the joystick and mode 
boolean startP, endP; // boolean for knowing when a packet from the Bluetooth starts and ends.
char BestDirection, BTRead;// variables for saving the best path and the command received 
char inPacket[20]; // Array to store stores what is received from bluetooth.
byte index;//index used for the array.

//variables used for speed
int slotsCounter;
int numSlots=20;
float rpm=0.00;
float velocity=0.00;
float diameter=2.625;// inches
long previousTime = 0; 
int lastState=0;
int sRead;
float count=0;

//infrared
int RRead, LRead; 



/*-------------------------------------Objects---------------------------------------------*/
SoftwareSerial bluetooth(BLUETOOTH_TX, BLUETOOTH_RX);//creates the bluetooth object
Adafruit_MotorShield MotorShield = Adafruit_MotorShield(); // creates the motorshield object
Adafruit_DCMotor *leftMotor2  = MotorShield.getMotor(1); // creates the motor object on the motor shield
Adafruit_DCMotor *rightMotor2 = MotorShield.getMotor(2); // creates the motor object on the motor shield
Adafruit_DCMotor *rightMotor1 = MotorShield.getMotor(3); // creates the motor object on the motor shield
Adafruit_DCMotor *leftMotor1 = MotorShield.getMotor(4); // creates the motor object on the motor shield


LiquidCrystal lcd(RS, EN, D4, D5, D6, D7);

NewPing ultraR(A0, A1, MAXDISTANCE);
NewPing ultraC(A0, A2, MAXDISTANCE);
NewPing ultraL(A0, A3, MAXDISTANCE);
/*-----------------------------------Functions prototypes----------------------------------*/
void btSet(); //function to set up bluetooth communication
void motorSet();// function to set up the motors
void avoidOsbtacles();//funtion to avoid obstacles
void movement(char Direction);//function to move the motor according to best path
void RCcar(int x, int y);// funtion to control the robot manually
void forward ();// function to move forward
void backward();// fuction to move backward
void left();// function to move left
void right();//function to move right
void FRight();//function to move forward and to the right
void FLeft();//function to move forward and to the left
void BRight();//function to move backward and to the right
void BLeft();//function to move backward and to the left
void Stop();// function to stop motors  
void calDir();//function to choose best path
void readBluetooth();//funtion for reading the input from bluetooth
void printLCD(String msg1, String msg2);
void displaySpeed();
