//
// oak_blink
//
// Simple example to display 'heartbeat' on pin 1
// This blink is different from the default 50:50 mark:space ratio
// of the default sketch on the device - this has 1:40 mark:space
// ratio...clearly very different.
//
// ver Date       Author       Comment
// 1.0 30/01/2016 ajpowell     Initial version
// 1.1 01/02/2016 ajpowell     Edited to use BUILTIN_LED

// BUILTIN_LED is defined in oak/pins_arduino.h
// static const uint8_t BUILTIN_LED = 1;

void setup() {                
  // initialize the digital pin as an output.
  pinMode(BUILTIN_LED, OUTPUT); //LED on Model A   
}

// the loop routine runs over and over again forever:
void loop() {
  digitalWrite(BUILTIN_LED, HIGH);   // turn the LED on (HIGH is the voltage level)
  Particle.delay(100);               // wait for a tenth second
  digitalWrite(BUILTIN_LED, LOW);    // turn the LED off by making the voltage LOW
  Particle.delay(4000);               // wait for a second
}
