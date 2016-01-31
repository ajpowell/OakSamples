//
// oak_particle.deviceip
//
// Simple example to demonstrate call to get Particle device IP address
//
// Includes 'heartbeat' to verify that device is running
//
// Extended version of code given in Particle Reference, Cloud Functions
//
// ver Date       Author       Comment
// 1.0 31/01/2016 ajpowell     Initial version

#define D1  1

void handler(const char *topic, const char *data) {
    Serial.println("received " + String(topic) + ": " + String(data));
}

void setup() {
  Serial.begin(57600);
  
  // initialize the digital pin as an output.
  pinMode(D1, OUTPUT); //LED on Oak pin 1

  for(int i=0;i<5;i++) {
    Serial.println("waiting... " + String(5 - i));
    delay(1000);
  }

  Particle.subscribe("spark/", handler);
  Particle.publish("spark/device/ip");
}

void loop() {
  // 'Heartbeat' code to flash led
  digitalWrite(D1, HIGH);   // turn the LED on (HIGH is the voltage level)
  Particle.delay(100);     // wait for a tenth second
  digitalWrite(D1, LOW);    // turn the LED off by making the voltage LOW
  
  delay(1000);
}
