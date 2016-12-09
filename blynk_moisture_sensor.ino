#define BLYNK_PRINT Serial

#include <DHT.h>


#include <ESP8266_Lib.h>
#include <BlynkSimpleShieldEsp8266.h>
#include <SimpleTimer.h>


#define DHTPIN 12
#define DHTTYPE DHT22

#define EspSerial Serial
#define ESP8266_BAUD 9600

DHT dht(DHTPIN, DHTTYPE);

char auth[] = "5fc84747acb64b5396fd8911a5e65741";

char ssid[] = "IoT";
char pass[] = "open4meplease";

SimpleTimer timer;

const int vcc1 = 2;
const int vcc2 = 4;
const int vcc3 = 5;
const int vcc4 = 6;
const int vcc5 = 7;
const int vcc6 = 8;

ESP8266 wifi(&EspSerial);




void setup()
  {
  EspSerial.begin(ESP8266_BAUD);
  delay(10);

  Blynk.begin(auth, wifi, ssid, pass);
  
  dht.begin();


  pinMode(vcc1, OUTPUT);
  pinMode(vcc2, OUTPUT);
  pinMode(vcc3, OUTPUT);
  pinMode(vcc4, OUTPUT);
  pinMode(vcc5, OUTPUT);
  pinMode(vcc6, OUTPUT);


  digitalWrite(vcc1, LOW);
  digitalWrite(vcc2, LOW);
  digitalWrite(vcc3, LOW);
  digitalWrite(vcc4, LOW);
  digitalWrite(vcc5, LOW);
  digitalWrite(vcc6, LOW);



  timer.setInterval(60000, myTimerEvent);
  
  }



void myTimerEvent()
  {
  digitalWrite(vcc1, HIGH);
  delay(50);
  Blynk.virtualWrite(V1, (1023 - analogRead(0)));
  digitalWrite(vcc1, LOW);
  
  digitalWrite(vcc2, HIGH);
  delay(50);
  Blynk.virtualWrite(V2, (1023 - analogRead(1)));
  digitalWrite(vcc2, LOW);
  
  digitalWrite(vcc3, HIGH);
  delay(50);
  Blynk.virtualWrite(V3, (1023 - analogRead(2)));
  digitalWrite(vcc3, LOW);
  
  digitalWrite(vcc4, HIGH);
  delay(50);
  Blynk.virtualWrite(V4, (1023 - analogRead(3)));
  digitalWrite(vcc4, LOW);

  
  digitalWrite(vcc5, HIGH);
  delay(50);
  Blynk.virtualWrite(V5, (1023 - analogRead(4)));
  digitalWrite(vcc5, LOW);
  
  digitalWrite(vcc6, HIGH);
  delay(50);
  Blynk.virtualWrite(V6, (1023 - analogRead(5)));
  digitalWrite(vcc6, LOW);




  Blynk.virtualWrite(V10,(dht.readTemperature(true)));
  Blynk.virtualWrite(V12,(dht.readHumidity()));

  

  }





void loop()
{
  Blynk.run();
  timer.run();

}


