



/*
   -- projet sem --
   
   This source code of graphical user interface 
   has been generated automatically by RemoteXY editor.
   To compile this code using RemoteXY library 3.1.8 or later version 
   download by link http://remotexy.com/en/library/
   To connect using RemoteXY mobile app by link http://remotexy.com/en/download/                   
     - for ANDROID 4.11.1 or later version;
     - for iOS 1.9.1 or later version;
    
   This source code is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.    
*/

//////////////////////////////////////////////
//        RemoteXY include library          //
//////////////////////////////////////////////

// RemoteXY select connection mode and include library 
#define REMOTEXY_MODE__ESP8266WIFI_LIB_POINT
#include <ESP8266WiFi.h>
#include <DHT.h>
#include <DHT_U.h>
#include <Servo.h>
#include <RemoteXY.h>


// RemoteXY connection settings 
#define REMOTEXY_WIFI_SSID "RemoteXY"
#define REMOTEXY_WIFI_PASSWORD "12345678"
#define REMOTEXY_SERVER_PORT 6377


// RemoteXY configurate  
#pragma pack(push, 1)
uint8_t RemoteXY_CONF[] =   // 494 bytes
  { 255,6,0,42,0,231,1,16,26,4,131,1,2,3,23,5,2,31,8,100,
  111,111,114,0,131,4,2,19,23,5,3,255,31,115,97,108,111,110,0,131,
  4,3,29,21,5,4,12,31,98,101,100,114,111,111,109,32,49,0,131,4,
  3,36,21,5,5,13,31,98,101,100,114,111,111,109,32,50,0,131,4,3,
  43,21,5,6,12,31,98,101,100,114,111,111,109,32,51,0,67,4,81,10,
  12,4,0,31,26,11,129,0,38,2,46,5,0,29,87,105,115,97,114,100,
  39,115,32,104,111,117,115,101,0,67,4,48,10,12,4,0,31,26,11,129,
  0,67,11,13,3,0,7,116,101,109,112,32,67,194,176,32,58,0,129,0,
  36,11,11,3,0,13,104,117,109,32,37,32,58,0,129,0,36,38,19,4,
  2,30,68,111,111,114,32,108,111,99,107,0,129,0,50,36,18,6,3,30,
  83,97,108,111,110,0,129,0,47,37,26,5,4,30,66,101,100,114,111,111,
  109,32,49,0,129,0,47,37,26,5,5,30,66,101,100,114,111,111,109,32,
  50,0,129,0,48,30,26,5,6,30,66,101,100,114,111,111,109,32,51,0,
  65,73,74,46,14,8,2,129,0,69,38,23,4,2,30,68,111,111,114,32,
  115,116,97,116,117,115,0,2,1,50,46,19,10,3,12,223,31,31,79,78,
  0,79,70,70,0,2,1,51,46,19,9,4,12,23,31,31,79,78,0,79,
  70,70,0,2,1,51,48,19,9,5,12,23,31,31,79,78,0,79,70,70,
  0,2,1,51,44,19,9,6,12,23,31,31,79,78,0,79,70,70,0,71,
  56,38,16,14,14,0,0,2,24,135,0,0,0,0,0,0,200,66,0,0,
  160,65,0,0,32,65,0,0,0,64,24,0,71,56,70,16,14,14,0,0,
  2,24,135,0,0,0,0,0,0,200,66,0,0,160,65,0,0,32,65,0,
  0,0,64,24,0,131,0,3,55,21,5,1,31,24,99,108,105,109,97,116,
  105,115,101,117,114,0,4,48,56,39,6,23,1,2,31,67,4,65,48,20,
  5,1,31,26,11,129,0,47,34,26,5,1,31,99,108,105,109,97,116,105,
  115,101,117,114,0,4,128,33,46,29,6,2,2,31 };
  
// this structure defines all the variables and events of your control interface 
struct {

    // input variables
  uint8_t switch_1; // =1 if switch ON and =0 if OFF 
  uint8_t switch_2; // =1 if switch ON and =0 if OFF 
  uint8_t switch_3; // =1 if switch ON and =0 if OFF 
  uint8_t switch_4; // =1 if switch ON and =0 if OFF 
  uint8_t pushSwitch_1; // =1 if state is ON, else =0 
  int8_t slider_1; // =-100..100 slider position 
  int8_t door_slider; // =0..100 slider position

    // output variables
  char text_temp[11];  // string UTF8 end zero 
  char text_hum[11];  // string UTF8 end zero 
  uint8_t led_door_status_r; // =0..255 LED Red brightness 
  float instrument_1;  // from 0 to 100 
  float instrument_2;  // from 0 to 100 
  char text_1[11];  // string UTF8 end zero 

    // other variable
  uint8_t connect_flag;  // =1 if wire connected, else =0 

} RemoteXY;
#pragma pack(pop)

/////////////////////////////////////////////
//           END RemoteXY include          //
/////////////////////////////////////////////

#define PIN_SWITCH_1 D0
#define PIN_SWITCH_2 D1
#define PIN_SWITCH_3 D2
#define PIN_SWITCH_4 D3
#define PIN_PUSHSWITCH_1 D4
#define DHT_PIN D5
#define DHTTYPE DHT11
DHT dht(DHT_PIN, DHTTYPE);
Servo myservo; 


void setup() 
{
  RemoteXY_Init (); 
  
  pinMode (PIN_SWITCH_1, OUTPUT);
  pinMode (PIN_SWITCH_2, OUTPUT);
  pinMode (PIN_SWITCH_3, OUTPUT);
  pinMode (PIN_SWITCH_4, OUTPUT);
  pinMode (PIN_PUSHSWITCH_1, OUTPUT);

  
  //servo moteur setup
   
    
  
  // TODO you setup code
  
}

void loop() 
{ 
  RemoteXY_Handler ();
  
  digitalWrite(PIN_SWITCH_1, (RemoteXY.switch_1==0)?LOW:HIGH);
  digitalWrite(PIN_SWITCH_2, (RemoteXY.switch_2==0)?LOW:HIGH);
  digitalWrite(PIN_SWITCH_3, (RemoteXY.switch_3==0)?LOW:HIGH);
  digitalWrite(PIN_SWITCH_4, (RemoteXY.switch_4==0)?LOW:HIGH);
  digitalWrite(PIN_PUSHSWITCH_1, (RemoteXY.pushSwitch_1==0)?LOW:HIGH);
  
  
  //DHT CODE (temperature et humidité)
  
  float hum = dht.readHumidity();
  float temp = dht.readTemperature();
  if (isnan(temp)){strcpy(RemoteXY.text_temp, "Error!");}
  else{dtostrf(temp, 0, 1, RemoteXY.text_temp);}
  if (isnan(hum)){strcpy(RemoteXY.text_hum, "Error!");}
  else{dtostrf(hum, 0, 1, RemoteXY.text_hum);}
  
  
  //servo moteur 
  
 
  // TODO you loop code
  // use the RemoteXY structure for data transfer
  // do not call delay() 


}
