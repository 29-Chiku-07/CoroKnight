#include "ESP8266WiFi.h" 
#include "FirebaseArduino.h"
#include "Firebase.h" 

int t1,t2,t3;
#define FIREBASE_HOST "dht-data-b1ef1.firebaseio.com" 
#define FIREBASE_AUTH "PuaIFUdHeyo5DIqQcci37dV4MTqWRnpdrHVAce2D" 
#define WIFI_SSID "devd" 
#define WIFI_PASSWORD "12341234"


void setup () {
  Serial.begin (9600);
 //Serial.begin(9600);
pinMode(A0,INPUT);
  delay (1000);
  WiFi.begin (WIFI_SSID, WIFI_PASSWORD); 
  Serial.print ("Connecting to");
  Serial.print (WIFI_SSID);
  while (WiFi.status()!= WL_CONNECTED) {
    Serial.print (".");
    delay (500);
  }
  Serial.println ();
  Serial.print ("Connected to");
  Serial.print (" ");
  Serial.println (WIFI_SSID);
  Serial.print ("IP Address is:");
  Serial.println (WiFi.localIP ()); 
  Firebase.begin (FIREBASE_HOST, FIREBASE_AUTH); 
   
}
void loop () 
{
 int analogValue=analogRead(A0);
  // put your main code here, to run repeatedly:
  t1=(analogValue/1024.0) *3300;    // multiplied with 3300 because I am                                              using 3.3 volts for vcc of lm35
       // Serial.print("temp: ");
       // Serial.println(t1);

        t2=(t1/10);
        //Serial.print("celc: ");
        //Serial.println(t2);

        t3=((t2 * 9)/5 + 32);
        //Serial.print("fhrn: ");
        Serial.println(t3);      
 
//  String firebaseTemp = String (t) + String ("°C"); 
//  Firebase.setFloat("Humidity", h); 
  Firebase.setFloat("Temperature", t3);
  
  delay (5000); 
} 
