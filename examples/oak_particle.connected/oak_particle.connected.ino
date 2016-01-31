//
// oak_particle.connected
//
// Simple example to demonstrate Particle.connected();
//
// Includes 'heartbeat' to verify that device is running
//
//
// Extended version of code given in Particle Reference, Cloud Functions
//
// ver Date       Author       Comment
// 1.0 31/01/2016 ajpowell     Initial version

#define D1  1

void setup() {
  Serial.begin(57600);
  
  // initialize the digital pin as an output.
  pinMode(D1, OUTPUT); //LED on Oak pin 1  
}

void loop() {
  if (Particle.connected()) {
    Serial.println("Connected!");
  }

  // 'Heartbeat' code to flash led
  digitalWrite(D1, HIGH);   // turn the LED on (HIGH is the voltage level)
  Particle.delay(100);     // wait for a tenth second
  digitalWrite(D1, LOW);    // turn the LED off by making the voltage LOW
  
  delay(1000);
}
