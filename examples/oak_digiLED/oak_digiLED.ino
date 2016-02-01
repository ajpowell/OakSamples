// Based on NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// released under the GPLv3 license
//
// ver Date       Author       Comment
// 1.0 30/01/2016 ajpowell     Updated for Digistump Oak - using Particle.delay() 
//                             rather than delay()
// 1.1 01/02/2016 ajpowell     Added Serial output for debugging

#include <Adafruit_NeoPixel.h>
 
// Which pin on the Digispark is connected to the DigiLED?
#define PIN            1
 
// How many DigiLEDs are attached to the Digispark?
#define NUMPIXELS      1
 
// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// For the WS2812B type through hole LED used by the DigiLED,  NEO_RGB + NEO_KHZ800 is the correct data format
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_RGB + NEO_KHZ800);
 
int delayval = 500; // delay for half a second
 
void setup() 
{
  Serial.begin(74880);
  pixels.begin(); // This initializes the NeoPixel library.
  pixels.show(); // Initialize all pixels to 'off'
  Serial.println("\n oak_digiLED\n");
}
 
void loop()
{
  // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
  // in Red,Green,Blue order

  Serial.println("White...");
  pixels.setPixelColor(0, pixels.Color(255, 255, 255)); //white
  pixels.show(); // This sends the updated pixel color to the hardware.
  Particle.delay(delayval); // Delay for a period of time (in milliseconds).

  Serial.println("Cyan...");
  pixels.setPixelColor(0, pixels.Color(0, 255, 255)); //cyan
  pixels.show();
  Particle.delay(delayval);

  Serial.println("Violet...");
  pixels.setPixelColor(0, pixels.Color(255, 0, 255)); //violet
  pixels.show();
  Particle.delay(delayval);

  Serial.println("Yellow...");
  pixels.setPixelColor(0, pixels.Color(255, 255, 0)); //yellow
  pixels.show();
  Particle.delay(delayval);

  Serial.println("Red...");
  pixels.setPixelColor(0, pixels.Color(255, 0, 0)); //red
  pixels.show();
  Particle.delay(delayval);

  Serial.println("Green...");
  pixels.setPixelColor(0, pixels.Color(0, 255, 0)); //green
  pixels.show();
  Particle.delay(delayval);

  Serial.println("Blue...");
  pixels.setPixelColor(0, pixels.Color(0, 0, 255)); //blue
  pixels.show();
  Particle.delay(delayval);
}
