//
// oak_blink
//
// Simple example to display 'heartbeat' on pin 1
// This blink is different from the default 50:50 mark:space ratio
// of the default sketch on the device.
//
// ver Date       Author       Comment
// 1.0 30/01/2016 ajpowell     Initial version

void setup() {                
  // initialize the digital pin as an output.
  pinMode(1, OUTPUT); //LED on Model A   
}

// the loop routine runs over and over again forever:
void loop() {
  digitalWrite(1, HIGH);   // turn the LED on (HIGH is the voltage level)
  Particle.delay(100);               // wait for a tenth second
  digitalWrite(1, LOW);    // turn the LED off by making the voltage LOW
  Particle.delay(4000);               // wait for a second
}
