// Sketch to all the setting of the colour remotely using particle API
//
// ver Date       Author       Comment
// 1.0 30/01/2016 ajpowell     Based on oak_digiLED v1.2
//
// Set the LED/NeoPixel colour with:
// curl https://api.particle.io/v1/devices/{DEVICE_ID}/SetColour -d access_token={ACCESS_TOKEN} -d "args=red"
//
//

#include <Adafruit_NeoPixel.h>

// Forward declaration of the function
int setColour (String command);
/*
// From http://digistump.com/board/index.php/topic,1984.0.html
<snip>
Looking at pins_arduino.h in the OakCore/variants/oak/ repository I found the following mapping comment:

                                ///0, 1, 2, 3, 4, 5,  6,  7,  8,  9, 10, 11
//uint8_t esp8266_pinToGpio[12] = {2, 5, 0, 3, 1, 4, 15, 13, 12, 14, 16, 17};

Using this mapping it told me that if I wanted to connect the neopixels to OAK pin 5, the corresponding ESP8266 GPIO designation was 4.

With this information I believe that the following will work without any modification to the libraries,  For example, using the Adafruit library.

<snip>
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
  
  pixels.begin(); // This initializes the NeoPixel library.

  pinMode ( 4, INPUT ); //the constructor and begin will set this up as an output, change it back to an input if desired
  
  pixels.show(); // Initialize all pixels to 'off'

  // We are also going to declare a Spark.function so that we can set the LED (NeoPixel) from the cloud.
   Particle.function("setColour",setColour);
}
 
void loop()
{
  // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
  // in Red,Green,Blue order
  /*
  pixels.setPixelColor(0, pixels.Color(255, 255, 255)); //white
  pixels.show(); // This sends the updated pixel color to the hardware.
  Particle.delay(delayval); // Delay for a period of time (in milliseconds).

  pixels.setPixelColor(0, pixels.Color(0, 255, 255)); //cyan
  pixels.show();
  Particle.delay(delayval);

  pixels.setPixelColor(0, pixels.Color(255, 0, 255)); //violet
  pixels.show();
  Particle.delay(delayval);

  pixels.setPixelColor(0, pixels.Color(255, 255, 0)); //yellow
  pixels.show();
  Particle.delay(delayval);

  pixels.setPixelColor(0, pixels.Color(255, 0, 0)); //red
  pixels.show();
  Particle.delay(delayval);
  
  pixels.setPixelColor(0, pixels.Color(0, 255, 0)); //green
  pixels.show();
  Particle.delay(delayval);

  pixels.setPixelColor(0, pixels.Color(0, 0, 255)); //blue
  pixels.show();
  Particle.delay(delayval);
  */
}

int setColour (String command) {
  // Set the colour based on the name sent in 'command'
    if(command == "red") {
      pixels.setPixelColor(0, pixels.Color(255, 0, 0)); //red
      pixels.show();
      return 1;
    }
    if(command == "green") {
      pixels.setPixelColor(0, pixels.Color(0, 255, 0)); //green
      pixels.show();
      return 1;
    }
    if(command == "blue") {
      pixels.setPixelColor(0, pixels.Color(0, 0, 255)); //blue
      pixels.show();
      return 1;
    }
    if(command == "cyan") {
      pixels.setPixelColor(0, pixels.Color(0, 255, 255)); //blue
      pixels.show();
      return 1;
    }
    if(command == "white") {
      pixels.setPixelColor(0, pixels.Color(255, 255, 255)); //blue
      pixels.show();
      return 1;
    }
    if(command == "oldlace" || command == "warmwhite") {
      pixels.setPixelColor(0, pixels.Color(253, 245, 230)); //blue
      pixels.show();
      return 1;
    }
    if(command == "purple") {
      pixels.setPixelColor(0, pixels.Color(128, 0, 128)); //blue
      pixels.show();
      return 1;
    }
    if(command == "magenta") {
      pixels.setPixelColor(0, pixels.Color(255, 0, 255)); //blue
      pixels.show();
      return 1;
    }
    if(command == "yellow") {
      pixels.setPixelColor(0, pixels.Color(255, 255, 0)); //blue
      pixels.show();
      return 1;
    }
    if(command == "orange") {
      pixels.setPixelColor(0, pixels.Color(255, 165, 0)); //blue
      pixels.show();
      return 1;
    }
    if(command == "pink") {
      pixels.setPixelColor(0, pixels.Color(255, 192, 203)); //blue
      pixels.show();
      return 1;
    }

    // Default i.e. unknown colour specified.
    // Set white, but minimum brightness, i.e. off
    pixels.setPixelColor(1, pixels.Color(255, 255, 255)); //white
    pixels.show();
    return -1;
  }

