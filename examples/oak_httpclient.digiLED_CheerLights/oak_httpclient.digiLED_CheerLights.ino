//
// oak_httpclient_digiLED_CheerLights
//
// Simple demo to retrieve colour from CheerLights API (http://cheerlights.com/cheerlights-api/)
// and display on a DigiLED in default configuration on pin 1.  The CheerLights API is polled every 
// 10 seconds
//
// Adapted from ESP8266HTTPClient/BasicHTTPClient.ino and DigiLED sample code
//
// NOTE:
//   - Set SSID and PASSWORD before compiling.
//   - Serial does not work because of issue in NeoPixel library
//
// ver Date       Author       Comment
// 1.0 07/02/2016 ajpowell     Initial version

// Would be nice to be able to pick these up from the particle.io config...
#define WIFI_SSID     "xxxxxx"
#define WIFI_PASSWORD "xxxxxxx"

#define BRIGHTNESS    128

#include <Arduino.h>

#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>

#include <ESP8266HTTPClient.h>

#include <Adafruit_NeoPixel.h>

// NOTE: Cannot use Serial currently as port 4 is initially taken over by NeoPixel library :(
// #define USE_SERIAL Serial

// Forward declaration of functions
int find_text(String needle, String haystack);

ESP8266WiFiMulti WiFiMulti;

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

void setup() {
    // For Use of Oak pin 1, GPIO pin 5
    pinMode ( 1, OUTPUT ); // See detail above
    digitalWrite ( 1, 0 ); // See detail above

    pixels.begin(); // This initializes the NeoPixel library.

    pinMode ( 4, INPUT ); //the constructor and begin will set this up as an output, change it back to an input if desired
  
    pixels.show(); // Initialize all pixels to 'off'
    
    Particle.delay(5000);

    pixels.setBrightness(BRIGHTNESS);
    
    WiFiMulti.addAP(WIFI_SSID, WIFI_PASSWORD);

}

void loop() {
    // wait for WiFi connection
    if((WiFiMulti.run() == WL_CONNECTED)) {

        HTTPClient http;
        
        // Configure target server and url
        http.begin("144.212.80.11", 80, "/channels/1417/field/1/last.txt"); //HTTP

        // start connection and send HTTP header
        int httpCode = http.GET();
        if(httpCode) {
            // HTTP header has been send and Server response header has been handled

            if(httpCode == 200) { //file found at server
                String payload = http.getString();
                // Returns 4 lines of output of the form:
                // 4
                // blue
                // 0
                //
                // Using function find_text to locate a colour in the returned payload
                // These are the colours defined for the CheerLights API

                if(find_text("red",payload) != -1) {
                  pixels.setPixelColor(0, pixels.Color(255, 0, 0)); //red
                  pixels.show();
                }
                if(find_text("green",payload) != -1) {
                  pixels.setPixelColor(0, pixels.Color(0, 255, 0)); //green
                  pixels.show();
                }
                if(find_text("blue",payload) != -1) {
                  pixels.setPixelColor(0, pixels.Color(0, 0, 255)); //blue
                  pixels.show();
                }
                if(find_text("cyan",payload) != -1) {
                  pixels.setPixelColor(0, pixels.Color(0, 255, 255)); //blue
                  pixels.show();
                }
                if(find_text("white",payload) != -1) {
                  pixels.setPixelColor(0, pixels.Color(255, 255, 255)); //blue
                  pixels.show();
                }
                if((find_text("oldlace",payload) != -1) || (find_text("warmwhite",payload) != -1)) {
                  pixels.setPixelColor(0, pixels.Color(253, 245, 230)); //blue
                  pixels.show();
                }
                if(find_text("purple",payload) != -1) {
                  pixels.setPixelColor(0, pixels.Color(128, 0, 128)); //blue
                  pixels.show();
                }
                if(find_text("magenta",payload) != -1) {
                  pixels.setPixelColor(0, pixels.Color(255, 0, 255)); //blue
                  pixels.show();
                }
                if(find_text("yellow",payload) != -1) {
                  pixels.setPixelColor(0, pixels.Color(255, 255, 0)); //blue
                  pixels.show();
                }
                if(find_text("orange",payload) != -1) {
                  pixels.setPixelColor(0, pixels.Color(255, 165, 0)); //blue
                  pixels.show();
                }
                if(find_text("pink",payload) != -1) {
                  pixels.setPixelColor(0, pixels.Color(255, 192, 203)); //blue
                  pixels.show();
                }
                
            }
        } else {
            //USE_SERIAL.print("[HTTP] GET... failed, no connection or no HTTP server\n");
        }
    }

    Particle.delay(10000);
}

// function to search for a string within a string
// Taken from: http://playground.arduino.cc/Main/FindText
int find_text(String needle, String haystack) {
  int foundpos = -1;
  for (int i = 0; (i < haystack.length() - needle.length()); i++) {
    if (haystack.substring(i,needle.length()+i) == needle) {
      foundpos = i;
    }
  }
  return foundpos;
}

