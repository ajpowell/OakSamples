// Based on NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// released under the GPLv3 license
//
// ver Date       Author       Comment
// 1.0 30/01/2016 ajpowell     Updated for Digistump Oak - using Particle.delay() 
//                             rather than delay()
// 1.1 01/02/2016 ajpowell     Added Serial output for debugging
// 1.2 06/02/2016 ajpowell     Fixes based on comments on Digistump forum

#include <Adafruit_NeoPixel.h>

/*
// From http://digistump.com/board/index.php/topic,1984.0.html
Re: NeoPixel library and pin names
« Reply #3 on: 05-02-2016, 17:24:26 »

I am no expert here. I'm a "jack of all trades and master of none", so weigh the following accordingly.

I found that the neopixel libraries referenced previously set up the control pin with the standard Arduino pinMode() and digitalWrite() functions and using the OAK port numbers work as expected, but that the ESP8266 implementation of the transmit data uses the GPIO port names.

Looking at pins_arduino.h in the OakCore/variants/oak/ repository I found the following mapping comment:

                                ///0, 1, 2, 3, 4, 5,  6,  7,  8,  9, 10, 11
//uint8_t esp8266_pinToGpio[12] = {2, 5, 0, 3, 1, 4, 15, 13, 12, 14, 16, 17};

Using this mapping it told me that if I wanted to connect the neopixels to OAK pin 5, the corresponding ESP8266 GPIO designation was 4.

With this information I believe that the following will work without any modification to the libraries,  For example, using the Adafruit library.

Assuming that you are using OAK pin 5 to control the neopixels, call the constructor with the corresponding GPIO port number, 4 (see mapping above):

  Adafruit_NeoPixel strip = Adafruit_NeoPixel(1, 4, NEO_RGB + NEO_KHZ800); 

Then in setup() make OAK pin 5 an output and restore OAK pin 4 back to an input if desired:

  pinMode ( 5, OUTPUT );
  digitalWrite ( 5, 0 );

  strip.begin();
  
  pinMode ( 4, INPUT ); //the constructor and begin will set this up as an output, change it back to an input if desired
    
  strip.show(); // Initialize all pixels to 'off'
  
The above changes worked with Adafruit's strandtest example.

And if you are interested in controlling neopixels via WIFI, check out: http://pance.mk/index.php/wifi-light-with-esp8266-and-arduino-code/

Again, comments, corrections and/or a better solution will be appreciated!
*/

// Which pin on the Digispark is connected to the DigiLED?
//#define PIN            4 //equiv to pin 5 on Oak - see detail above
#define PIN            5 //equiv to pin 1 on Oak - default setup for DigiLED shield - see detail above
 
// How many DigiLEDs are attached to the Digispark?
#define NUMPIXELS      1
 
// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// For the WS2812B type through hole LED used by the DigiLED,  NEO_RGB + NEO_KHZ800 is the correct data format
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_RGB + NEO_KHZ800);
 
int delayval = 500; // delay for half a second
 
void setup() 
{
  // For Use of Oak pin 1, GPIO pin 5
  pinMode ( 1, OUTPUT ); // See detail above
  digitalWrite ( 1, 0 ); // See detail above

  // For Use of Oak pin 5, GPIO pin 4
  //pinMode ( 5, OUTPUT ); // See detail above
  //digitalWrite ( 5, 0 ); // See detail above
  
  Serial.begin(74880);
  pixels.begin(); // This initializes the NeoPixel library.

  pinMode ( 4, INPUT ); //the constructor and begin will set this up as an output, change it back to an input if desired
  
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
