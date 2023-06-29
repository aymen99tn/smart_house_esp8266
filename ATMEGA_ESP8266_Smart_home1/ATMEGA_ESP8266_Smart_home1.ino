////////////////////////////////////////////// 
//        RemoteXY include library          // 
////////////////////////////////////////////// 
#define REMOTEXY_MODE__ESP8266_HARDSERIAL_CLOUD

#include <RemoteXY.h> 

// RemoteXY connection settings  
#define REMOTEXY_SERIAL Serial 
#define REMOTEXY_SERIAL_SPEED 115200 
#define REMOTEXY_WIFI_SSID "***********" 
#define REMOTEXY_WIFI_PASSWORD "***********" 
#define REMOTEXY_CLOUD_SERVER "cloud.remotexy.com" 
#define REMOTEXY_CLOUD_PORT 6376 
#define REMOTEXY_CLOUD_TOKEN "****************"

#include <Servo.h>
#include <EEPROM.h>
#include <DHT.h>
Servo doorlock;
   
#pragma pack(push, 1) 
uint8_t RemoteXY_CONF[] = 
  { 255,14,0,33,0,220,2,8,26,4,
  131,4,2,13,23,5,1,15,31,108,
  105,118,105,110,103,32,114,111,111,109,
  0,131,1,2,3,23,5,2,31,8,
  83,101,114,118,105,99,101,115,0,131,
  4,2,19,23,5,3,255,31,115,97,
  108,111,110,0,131,4,3,29,21,5,
  4,12,31,98,101,100,114,111,111,109,
  32,49,0,131,4,3,36,21,5,5,
  13,31,98,101,100,114,111,111,109,32,
  50,0,131,4,3,43,21,5,6,12,
  31,98,101,100,114,111,111,109,32,51,
  0,131,4,3,53,21,5,7,1,31,
  107,105,116,99,104,101,110,0,67,4,
  80,10,18,5,0,31,26,11,129,0,
  30,1,65,7,0,29,40,40,32,77,
  121,32,115,109,97,114,116,32,72,111,
  109,101,32,41,41,0,129,0,75,58,
  23,4,0,29,40,40,66,101,32,83,
  109,97,114,116,41,41,0,67,4,48,
  10,17,5,0,31,26,11,129,0,67,
  11,13,3,0,7,116,101,109,112,32,
  67,194,176,32,58,0,129,0,36,11,
  11,3,0,13,104,117,109,32,37,32,
  58,0,4,128,31,27,31,5,2,1,
  31,129,0,37,19,19,4,2,30,68,
  111,111,114,32,108,111,99,107,0,1,
  10,32,44,20,11,2,9,31,68,111,
  111,114,0,2,1,67,44,22,11,2,
  8,55,31,31,61,0,61,0,2,1,
  73,43,21,11,7,5,13,31,31,61,
  0,61,0,2,1,34,28,21,11,7,
  38,192,31,31,61,0,61,0,2,1,
  48,37,29,15,3,5,13,31,31,61,
  0,61,0,129,0,48,17,32,6,1,
  29,108,105,118,105,110,103,32,114,111,
  111,109,0,129,0,53,18,18,6,3,
  30,83,97,108,111,110,0,6,0,28,
  24,36,36,1,2,26,2,1,48,37,
  29,15,4,5,13,31,31,61,0,61,
  0,129,0,46,18,31,6,4,30,66,
  101,100,114,111,111,109,32,49,0,129,
  0,46,18,31,6,5,30,66,101,100,
  114,111,111,109,32,50,0,129,0,46,
  18,31,6,6,30,66,101,100,114,111,
  111,109,32,51,0,129,0,50,18,21,
  6,7,30,107,105,116,99,104,101,110,
  0,65,44,60,44,9,9,7,65,42,
  60,29,9,9,7,65,44,69,25,18,
  9,2,129,0,66,19,23,4,2,30,
  68,111,111,114,32,115,116,97,116,117,
  115,0,65,42,84,40,9,9,3,65,
  42,84,40,9,9,4,2,1,48,37,
  29,15,5,5,13,31,31,61,0,61,
  0,65,42,84,40,9,9,5,2,1,
  48,37,29,15,6,5,13,31,31,61,
  0,61,0,65,42,84,40,9,9,6,
  2,1,78,46,21,11,1,5,13,31,
  31,61,0,61,0,2,1,78,31,21,
  11,1,38,192,31,31,61,0,61,0,
  65,42,67,47,9,9,1,65,42,67,
  32,9,9,1,129,0,29,45,28,5,
  7,30,119,97,116,101,114,32,112,117,
  109,112,0,129,0,75,30,13,6,7,
  30,76,105,103,104,116,0,65,42,91,
  46,7,7,2,65,42,54,46,7,7,
  2,129,0,7,49,13,3,0,27,40,
  40,217,129,217,138,217,131,32,216,177,
  216,167,216,179,41,41,0,129,0,7,
  25,13,3,0,27,40,40,217,129,217,
  138,217,131,32,216,177,216,167,216,179,
  41,41,0,129,0,7,9,13,3,0,
  27,40,40,217,129,217,138,217,131,32,
  216,177,216,167,216,179,41,41,0 }; 
    
struct { 
  int8_t slider_1; // =0..100 slider position 
  uint8_t button_door; // =1 if button pressed, else =0 
  uint8_t switch_door_ligh; // =1 if switch ON and =0 if OFF 
  uint8_t switch_pump; // =1 if switch ON and =0 if OFF 
  uint8_t switch_kit_ligh; // =1 if switch ON and =0 if OFF 
  uint8_t switch_sal; // =1 if switch ON and =0 if OFF 
  uint8_t rgb_1_r; // =0..255 Red color value 
  uint8_t rgb_1_g; // =0..255 Green color value 
  uint8_t rgb_1_b; // =0..255 Blue color value 
  uint8_t switch_bed1; // =1 if switch ON and =0 if OFF 
  uint8_t switch_bed2; // =1 if switch ON and =0 if OFF 
  uint8_t switch_bed3; // =1 if switch ON and =0 if OFF 
  uint8_t switch_liv1; // =1 if switch ON and =0 if OFF 
  uint8_t switch_liv2; // =1 if switch ON and =0 if OFF 

  char text_temp[11];  // string UTF8 end zero 
  char text_hum[11];  // string UTF8 end zero 
  uint8_t led_pump_r; // =0..255 LED Red brightness 
  uint8_t led_kit_ligh_g; // =0..255 LED Green brightness 
  uint8_t led_door_status_r; // =0..255 LED Red brightness 
  uint8_t led_sal_g; // =0..255 LED Green brightness 
  uint8_t led_bed1_g; // =0..255 LED Green brightness 
  uint8_t led_bed2_g; // =0..255 LED Green brightness 
  uint8_t led_bed3_g; // =0..255 LED Green brightness 
  uint8_t led_liv1_g; // =0..255 LED Green brightness 
  uint8_t led_liv2_g; // =0..255 LED Green brightness 
  uint8_t led_door_ligh_g; // =0..255 LED Green brightness 
  uint8_t led_door_g; // =0..255 LED Green brightness 

  uint8_t connect_flag;  // =1 if wire connected, else =0 

} RemoteXY; 
#pragma pack(pop) 

///////////////////////////////////////////// 
//           END RemoteXY include          // 
///////////////////////////////////////////// 

#define PIN_BUTTON_DOOR A4
#define PIN_SWITCH_DOOR_LIGH A3
#define PIN_SWITCH_PUMP 6
#define PIN_SWITCH_KIT_LIGH 5
#define PIN_SWITCH_SAL A5
#define PIN_SWITCH_BED1 13
#define PIN_SWITCH_BED2 12
#define PIN_SWITCH_BED3 4
#define PIN_SWITCH_LIV1 7
#define PIN_SWITCH_LIV2 8

#define r 9
#define g 10
#define b 11

#define DHT_PIN 2 
#define DHTTYPE DHT22
DHT dht(DHT_PIN, DHTTYPE);

void setup()  
{ 
  RemoteXY_Init ();
  
  pinMode (r, OUTPUT);
  pinMode (g, OUTPUT);
  pinMode (b, OUTPUT);

  pinMode (A2, INPUT);
  pinMode (3, OUTPUT);
  pinMode (PIN_BUTTON_DOOR, OUTPUT);
  pinMode (PIN_SWITCH_DOOR_LIGH, OUTPUT);
  pinMode (PIN_SWITCH_PUMP, OUTPUT);
  pinMode (PIN_SWITCH_KIT_LIGH, OUTPUT);
  pinMode (PIN_SWITCH_SAL, OUTPUT);
  pinMode (PIN_SWITCH_BED1, OUTPUT);
  pinMode (PIN_SWITCH_BED2, OUTPUT);
  pinMode (PIN_SWITCH_BED3, OUTPUT);
  pinMode (PIN_SWITCH_LIV1, OUTPUT);
  pinMode (PIN_SWITCH_LIV2, OUTPUT);

  RemoteXY.switch_door_ligh = EEPROM.read(101);
  RemoteXY.switch_pump = EEPROM.read(102);
  RemoteXY.switch_kit_ligh = EEPROM.read(103);
  RemoteXY.switch_sal = EEPROM.read(104);
  RemoteXY.switch_bed1 = EEPROM.read(105);
  RemoteXY.switch_bed2 = EEPROM.read(106);
  RemoteXY.switch_bed3 = EEPROM.read(107);
  RemoteXY.switch_liv1 = EEPROM.read(108);
  RemoteXY.switch_liv2 = EEPROM.read(109);
  RemoteXY.slider_1 = EEPROM.read(100);

  RemoteXY.rgb_1_r = EEPROM.read(110);
  RemoteXY.rgb_1_g = EEPROM.read(111);
  RemoteXY.rgb_1_b = EEPROM.read(112);
}

void setColor(int red, int green, int blue)
{
analogWrite(r, red);
analogWrite(g, green);
analogWrite(b, blue);
}

void loop()  
{  
  RemoteXY_Handler ();
  analogWrite(3,(180 - RemoteXY.slider_1 * 1.8));
  EEPROM.update (100, RemoteXY.slider_1);

  setColor(RemoteXY.rgb_1_r, RemoteXY.rgb_1_g, RemoteXY.rgb_1_b);
  EEPROM.update (110, RemoteXY.rgb_1_r); 
  EEPROM.update (111, RemoteXY.rgb_1_g);
  EEPROM.update (112, RemoteXY.rgb_1_b);
  
  digitalWrite(PIN_BUTTON_DOOR, (RemoteXY.button_door==0)?LOW:HIGH);
  digitalWrite(PIN_SWITCH_DOOR_LIGH, (RemoteXY.switch_door_ligh==0)?LOW:HIGH);
  EEPROM.update (101, RemoteXY.switch_door_ligh);
  digitalWrite(PIN_SWITCH_PUMP, (RemoteXY.switch_pump==0)?LOW:HIGH);
  EEPROM.update (102, RemoteXY.switch_pump);
  digitalWrite(PIN_SWITCH_KIT_LIGH, (RemoteXY.switch_kit_ligh==0)?LOW:HIGH);
  EEPROM.update (103, RemoteXY.switch_kit_ligh);
  digitalWrite(PIN_SWITCH_SAL, (RemoteXY.switch_sal==0)?LOW:HIGH);
  EEPROM.update (104, RemoteXY.switch_sal);
  digitalWrite(PIN_SWITCH_BED1, (RemoteXY.switch_bed1==0)?LOW:HIGH);
  EEPROM.update (105, RemoteXY.switch_bed1);
  digitalWrite(PIN_SWITCH_BED2, (RemoteXY.switch_bed2==0)?LOW:HIGH);
  EEPROM.update (106, RemoteXY.switch_bed2);
  digitalWrite(PIN_SWITCH_BED3, (RemoteXY.switch_bed3==0)?LOW:HIGH);
  EEPROM.update (107, RemoteXY.switch_bed3);
  digitalWrite(PIN_SWITCH_LIV1, (RemoteXY.switch_liv1==0)?LOW:HIGH);
  EEPROM.update (108, RemoteXY.switch_liv1);
  digitalWrite(PIN_SWITCH_LIV2, (RemoteXY.switch_liv2==0)?LOW:HIGH);
  EEPROM.update (109, RemoteXY.switch_liv2);

  float hum = dht.readHumidity();
  float temp = dht.readTemperature();
  
  if (isnan(temp)){strcpy(RemoteXY.text_temp, "Error!");}
  else{dtostrf(temp, 0, 1, RemoteXY.text_temp);}
  if (isnan(hum)){strcpy(RemoteXY.text_hum, "Error!");}
  else{dtostrf(hum, 0, 1, RemoteXY.text_hum);}

  RemoteXY.led_pump_r = (digitalRead(6)==HIGH)?255:0; 
  RemoteXY.led_kit_ligh_g = (digitalRead(5)==HIGH)?255:0; 
  RemoteXY.led_sal_g = (digitalRead(A5)==HIGH)?255:0; 
  RemoteXY.led_bed1_g = (digitalRead(13)==HIGH)?255:0; 
  RemoteXY.led_bed2_g = (digitalRead(12)==HIGH)?255:0; 
  RemoteXY.led_bed3_g = (digitalRead(4)==HIGH)?255:0;
  RemoteXY.led_liv1_g = (digitalRead(7)==HIGH)?255:0; 
  RemoteXY.led_liv2_g = (digitalRead(8)==HIGH)?255:0; 
  RemoteXY.led_door_status_r = (digitalRead(A2)==HIGH)?255:0;
  RemoteXY.led_door_ligh_g = (digitalRead(A3)==HIGH)?255:0;
  RemoteXY.led_door_g = (digitalRead(A4)==HIGH)?255:0;
}

