
#include "thingProperties.h"

void setup() {
  // Initialize serial and wait for port to open:
  Serial.begin(9600);
  pinMode (12, OUTPUT);
  pinMode (14, OUTPUT);
  pinMode (26, OUTPUT);
  pinMode (27, OUTPUT);
  
  digitalWrite (12, LOW);
  digitalWrite (14, LOW);
  digitalWrite (26, LOW);
  digitalWrite (27, LOW);
  // This delay gives the chance to wait for a Serial Monitor without blocking if none is found
  delay(1500); 

  // Defined in thingProperties.h
  initProperties();

  // Connect to Arduino IoT Cloud
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  
  /*
     The following function allows you to obtain more information
     related to the state of network and IoT Cloud connection and errors
     the higher number the more granular information you’ll get.
     The default is 0 (only errors).
     Maximum is 4
 */
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
}

void loop() {
  ArduinoCloud.update();
  // Your code here if needed 
  
  
}


/*
  Since Light1 is READ_WRITE variable, onLight1Change() is
  executed every time a new value is received from IoT Cloud.
*/
void onLight1Change()  {
  if (light_1 == 1) {
    digitalWrite(12, HIGH);
  }
  else{
    digitalWrite(12, LOW);
  }
}

/*
  Since Light2 is READ_WRITE variable, onLight2Change() is
  executed every time a new value is received from IoT Cloud.
*/
void onLight2Change()  {
  if (light_2 == 1) {
    digitalWrite(14, HIGH);
  }
  else{
    digitalWrite(14, LOW);
  }

  
}

/*
  Since Light3 is READ_WRITE variable, onLight3Change() is
  executed every time a new value is received from IoT Cloud.
*/
void onLight3Change()  {
  if (light_3 == 1) {
    digitalWrite(26, HIGH);
  }
  else{
    digitalWrite(26, LOW);
  }
  
}

/*
  Since Light4 is READ_WRITE variable, onLight4Change() is
  executed every time a new value is received from IoT Cloud.
*/
void onLight4Change()  {
  if (light_4 == 1) {
    digitalWrite(27, HIGH);
  }
  else{
    digitalWrite(27, LOW);
  }
  
}


