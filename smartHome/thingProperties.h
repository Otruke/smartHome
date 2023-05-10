// DO NOT EDIT THIS CODE.

#include <ArduinoIoTCloud.h>
#include <Arduino_ConnectionHandler.h>

const char DEVICE_LOGIN_NAME[]  = "f0d5d13c-fdc8-466f-8d92-64d0066e11ab";

const char SSID[]               = SECRET_SSID;    // Network SSID (name)
const char PASS[]               = SECRET_OPTIONAL_PASS;    // Network password (use for WPA, or use as key for WEP)
const char DEVICE_KEY[]  = SECRET_DEVICE_KEY;    // Secret device password

void onLight1Change();
void onLight2Change();
void onLight3Change();
void onLight4Change();

bool light_1;
bool light_2;
bool light_3;
bool light_4;

void initProperties(){

  ArduinoCloud.setBoardId(DEVICE_LOGIN_NAME);
  ArduinoCloud.setSecretDeviceKey(DEVICE_KEY);
  ArduinoCloud.addProperty(light_1, READWRITE, ON_CHANGE, onLight1Change);
  ArduinoCloud.addProperty(light_2, READWRITE, ON_CHANGE, onLight2Change);
  ArduinoCloud.addProperty(light_3, READWRITE, ON_CHANGE, onLight3Change);
  ArduinoCloud.addProperty(light_4, READWRITE, ON_CHANGE, onLight4Change);

}

WiFiConnectionHandler ArduinoIoTPreferredConnection(SSID, PASS);
