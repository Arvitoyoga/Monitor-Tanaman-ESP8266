/* pin D0 = output relay pompa.
    pin A0 = input sensor tanah.
    pin D1&D2 = lcd.
    pin D3 = input dht11.
    pin D4 = input sensor hujan
    pin D5 = output relay pestisida.
    pin D6 = input tombol pull up siram.
    pin D7 = input tombol pull up pestisida. */

#include <ESP8266WiFi.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>
#include <BlynkSimpleEsp8266.h>
#define BLYNK_PRINT Serial
#define pompaA 16
#define sensorS A0
#define sensorH 2
#define pompaB 14
#define tombolA 12
#define tombolB 13
int nilaiS=0;
int nilaiH;

DHT dht (D3,DHT11);
LiquidCrystal_I2C lcd(0x27,20,4);
const char* auth="NSnbtlmDD_eExb4nyi7470GcCUcL9OOt12233";
const char* ssid="";
const char* pass="";

BlynkTimer timer;

void setup() {
pinMode(pompaA,OUTPUT);
pinMode(sensorS,INPUT);
pinMode(sensorH,INPUT);
pinMode(pompaB,OUTPUT);
pinMode(tombolA,INPUT);
pinMode(tombolB,INPUT);
lcd.init();
lcd.backlight();
Blynk.begin(auth,ssid,pass);
dht.begin();
    

}

void pestisida() {
     if(tombolB==LOW) {digitalWrite(pompaB,LOW);}
    else {digitalWrite(pompaB,HIGH);}
}
 
void siram() {
    nilaiS=analogRead(sensorS);
    if(nilaiS<500) { digitalWrite(pompaA,LOW);}
    else {digitalWrite(pompaA,HIGH);}
    lcd.setCursor(0,2);
    lcd.print("Tanah:");
    lcd.print(nilaiS);
    
    if(tombolA==LOW) {digitalWrite(pompaA,LOW);}
    else {digitalWrite(pompaA,HIGH);}
    
}

void hujan() {
    nilaiH=digitalRead(sensorH);
    if(nilaiH==LOW) {Blynk.notify("Sedang Hujan");}
}

void suhu() {
float h=dht.readHumidity();
float t=dht.readTemperature();
Blynk.virtualWrite(V0,t);
Blynk.virtualWrite(V1,h);
lcd.setCursor(0,0);
lcd.print("Temp:");
lcd.print(t);
lcd.setCursor(0,1);
lcd.print("Humi:");
lcd.print(h);
}
 

void loop() {
    Blynk.run();
    timer.run();
    suhu();
    siram();
    hujan();
    pestisida();
    
    
}
