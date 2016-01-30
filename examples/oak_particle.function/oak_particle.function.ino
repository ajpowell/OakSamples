//
// oak_particle.function
//
// Demo to expose a function on Particle.io - pin 5 controlled from 
// Particle.io api call.  Heartbeat on pin 1
//
// ver Date       Author       Comment
// 1.0 30/01/2016 ajpowell     Initial version
//
// Switch the LED on with:
//
// curl https://api.particle.io/v1/devices/{DEVICE_ID}/led -d access_token={ACCESS_TOKEN} -d "args=off"
//
// and off with
//
// curl https://api.particle.io/v1/devices/{DEVICE_ID}/led -d access_token={ACCESS_TOKEN} -d "args=off"

int switchLed(String command);

void setup() {
  Serial.begin(57600);
  Serial.println("oak_particle.function");
  // register the cloud function
  Particle.function("led", switchLed);

  // initialize the digital pin as an output.
  pinMode(1, OUTPUT); //LED on 
  pinMode(5, OUTPUT); //LED on

  Serial.println("Setup complete");
}

void loop() {
  Particle.delay(1950);     // wait for 1950ms
  // Total loop delay is 1950+50=2000ms i.e. 2 second (approx)

  // Provide 'heartbeat' from LED
  digitalWrite(1, HIGH);   // turn the LED on (HIGH is the voltage level)
  Particle.delay(50);      // wait for 50ms
  digitalWrite(1, LOW);
}

int switchLed(String command)
{
  // look for the matching argument - max of 64 characters long
  if(command == "on")
  {
    Serial.println("Received 'ON' command...");
    digitalWrite(5, HIGH);   // turn the LED on
    return 1;
  }
  if(command == "off")
  {
    Serial.println("Received 'OFF' command...");
    digitalWrite(5, LOW);   // turn the LED off
    return 1;
  }
  else return -1;
}
