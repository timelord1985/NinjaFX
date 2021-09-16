/*****************************************************************************************
                "FAST HANDS" SOUND EFFECT SLAP BAND TOY PROTOTYPE CODE
         The idea: Sensor is set at reading above 4g, at which point when it reads 4g,
                  it will activate the "woooooosh" sound effect on the DF Player.
  https://www.adafruit.com/products/2019
  https://www.dfrobot.com/wiki/index.php/DFPlayer_Mini_SKU:DFR0299#Connection_Diagram 
******************************************************************************************/
/*Included library and objects. Note: If adafruit trinket has onboard LED I'll add that to indicate it's on*/
#include <Wire.h>
#include <Adafruit_MMA8451.h>
#include <Adafruit_Sensor.h>
#include "Arduino.h"
#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"
Adafruit_MMA8451 mma = Adafruit_MMA8451();
SoftwareSerial mySoftwareSerial(10, 11);
DFRobotDFPlayerMini myDFPlayer;          
void printDetail(uint8_t type, int value);

/*The Setup.
From what I know, Arduino code requires at least one thing in setup.
So I'm going to have it print out a Wu Tang Clan quote in the serial monitor,
and also set the read range to  4g*/
void setup()
{
  Serial.begin(9600);
  Serial.println("A sword fight is like a game of chess, you must think first before you move!");
  if (! mma.begin()) {
    Serial.println("Couldnt start");
    while (1);
  }
  Serial.println("MMA8451 found!");
  mma.setRange(MMA8451_RANGE_4_G);
  Serial.print("Range = "); Serial.print(2 << mma.getRange());  
  Serial.println("G");
    
}

/*The Loop. 
Again, Arduino also requires at least one loop.
So "hey sensor read all your data, if you read 4g or more,
play at a volume of 30 the first song on the DF Player.*/

void loop() {

  /* Read the 'raw' data in 14-bit counts*/
  mma.read();
  Serial.print("X:\t"); Serial.print(mma.x); 
  Serial.print("\tY:\t"); Serial.print(mma.y); 
  Serial.print("\tZ:\t"); Serial.print(mma.z); 
  Serial.println();
  
  /*This is the code I had to create in my head, it's like a puzzle, still don't fully understand it, but hope it works*/
  if (true); {
    myDFPlayer.volume(30);  /*Set volume value. From 0 to 30*/
    myDFPlayer.play(1);     /*Play first Mp3*/
    while(true);
  }
  
}
