int relayPin = 2; // relay

#include <NewPing.h>

#define TRIGGER_PIN  11  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     12  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.

double cm2ft = 0.0328;  // used to convert cm to ft

void setup() {
  // setup, to run once:

  Serial.begin(9600);
  
  pinMode(relayPin,OUTPUT); // set digital pin as output

}

void loop() {
  // repeat

  unsigned int uS = sonar.ping() / US_ROUNDTRIP_CM ; // Send ping, get ping time in microseconds (uS).
  double uS_ft = double(uS) * cm2ft;
  Serial.print("Ping: ");
  Serial.print( uS_ft ); // Convert ping time to distance and print result (0 = outside set distance range, no ping echo)
  Serial.println("ft");

  if (uS_ft > 3.0 || uS_ft == 0.0){
    // too far or no ping return
    digitalWrite(relayPin,LOW); // sets the digital pin off
  }
  else if (uS_ft <= 3.0 && uS_ft > 0.0){
    // turn on air puff
    digitalWrite(relayPin,HIGH); // sets the digital pin on
    delay(500);
  }
  else{
    // boundary condition
    Serial.println("Error");
  }
  
}
