/* Print values from analog pin A0 to serial monitor */

int relayPin = 2; // relay to pump

int watval;       // reading from water sensor

void setup()
{
  Serial.begin(9600);
  pinMode(relayPin, OUTPUT);

}

void loop()
{
  watval = analogRead(A0);

  Serial.print("Capacitance Reading: ");
  Serial.println(watval);
  delay(100);

  if (watval < 450 & watval >= 350){

    digitalWrite(relayPin, HIGH); // begin releasing water
    // water for 1 sec and then prevent watering for another 5 mins
    delay(1000);

    // turn off and wait for
    digitalWrite(relayPin,LOW);
    delay(300000);
    
  }
  else if (watval < 350){
    digitalWrite(relayPin, LOW); // enough water in pot
  }
  else if (watval > 450){
    digitalWrite(relayPin, LOW); // no contact or overwatered
  }
  else{
    digitalWrite(relayPin, LOW); // safety shut off
    Serial.print("Error Condition: ");
    Serial.println(watval);
  }
  

}
