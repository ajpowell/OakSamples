//
// oak_particle.variable
//
// Demo to publish an integer value to particle
// Integer is incremented once per second - a 'heartbeat' triggers the LED on pin1 each second too.
//
// ver Date       Author       Comment
// 1.0 30/01/2016 ajpowell     Initial version
//
// Value is accessible at

//https://api.particle.io/v1/devices/{DEVICE_ID}/{VARIABLE}?access_token={ACCESS_TOKEN}


int testValue = 0;

void setup() {
  // variable name max length is 12 characters long
  Particle.variable("testValue", testValue);
  
  // initialize the digital pin as an output.
  pinMode(1, OUTPUT); //LED on 
}

void loop() {
  // put your main code here, to run repeatedly:
  Particle.delay(950);     // wait for 950ms
  // Total loop delay is 950+50=1000ms i.e. 1 second (approx)

  // Increment counter
  testValue=testValue+1;

  // Provide 'heartbeat' from LED
  digitalWrite(1, HIGH);   // turn the LED on (HIGH is the voltage level)
  Particle.delay(50);      // wait for 50ms
  digitalWrite(1, LOW);
}
