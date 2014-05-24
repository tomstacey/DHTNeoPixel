#include <Adafruit_NeoPixel.h>

#define PIN 8

#include "DHT.h"

#define DHTPIN 2     // what pin we're connected to

// Uncomment whatever type you're using!
//#define DHTTYPE DHT11   // DHT 11 
#define DHTTYPE DHT22   // DHT 22  (AM2302)
//#define DHTTYPE DHT21   // DHT 21 (AM2301)



DHT dht(DHTPIN, DHTTYPE);

//Create NeoPixel Strip
Adafruit_NeoPixel strip = Adafruit_NeoPixel(8, PIN, NEO_GRB + NEO_KHZ800);

int pixelTemp;
void setup() {
  Serial.begin(9600); 
  Serial.println("DHT test!");
  dht.begin();
  strip.begin();
  strip.show(); 
  strip.setBrightness(30); 
}

void loop() {
  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  int humd = (int)h;
  int temp = (int)t;

  
  delay(50);

//Turn temp into smaller figure to light a reasonable amount of pixels
 if (temp < 18) {
   pixelTemp = 0;
 }
   else {
     pixelTemp = temp - 22;
   }
showAmount();
delay(1000);
}

void showAmount()
{
int i;  
  if(pixelTemp == 0)
  {
      for (i = 0; i <=7; i++)
      {
        strip.setPixelColor(i, 255, 255, 255);
      }    
  }
  else if(pixelTemp == 8)
  {

      for (i = 0; i <=7; i++)
      {
        strip.setPixelColor(i, 255, 0, 0);
      }    
  }
  else if (pixelTemp >= 0 && pixelTemp <= 8)
 {
  
      for (i = 0; i <=pixelTemp-1; i++)
      {
        strip.setPixelColor(i, 255, 0, 0);
      }  
      for (i = pixelTemp; i <= 7; i++)
      {
        strip.setPixelColor(i, 255, 255, 255);
      }  

 } 
 
     strip.show();         
}
