# OakSamples

A number of simple examples to demonstrate use of the Digistump Oak board and connectivity to Particle.io.

Full details of Oak are here: [http://digistump.com/]

NOTE:
These are intended to be used from the Arduino IDE to upload OTA to the target device - details on how to configure this is here: [http://digistump.com/wiki/oak/tutorials/arduino]

## Current samples

###oak_blink
Simple sketch to flash the LED attached to pin 1

###oak_particle.variable
Sketch to write a variable to Particle.io and make it available via an api call.
###oak_particle.function
Sketch to expose a function on Particle.io - this can be called to switch an LED on or off.
###oak_particle.connected
Sketch to test if device is connected to Particle
###oak_particle.devicename
Sketch to get the device name from Particle
###oak_particle.deviceip
Sketch to get the device IP address from Particle
###oak_digiLED
Code compiles and now works - needed tweak due to mapping Oak and GPIO outputs
###oak_particle.digiLED-SetColour
Sketch using Particle.io function to set the colour of a DigiLED
###oak_httpclient.digiLED_CheerLights
Sketch using ESP8266 HTTP client to get colour from CheerLights API and set colour on DigiLED

###oak_1wire_ds18b20
Code does now compiles and executes - you need to edit pins_arduino.h to add 
```
#define ARDUINO_ARCH_ESP8266 1
```
Raised issue #22 against OakCore for this.

## WIP


