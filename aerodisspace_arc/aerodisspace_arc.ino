#include "src/include/wrapper.h"

#ifdef IS_AIRCRAFT
#define RADIO_IDX 0
#elif IS_CONTROLLER
#define RADIO_IDX 1
#else
#error "Define IS_AIRCRAFT or IS_CONTROLLER to identify the role of the device."
#endif

void setup()
{
    Serial.begin(115200);
    delay(1000);
    // Setup radio both for aircraft and controller
    radio_setup(RADIO_IDX);

#ifdef IS_AIRCRAFT
    Serial.println("Aircraft Mode");
    // Will wait for the first radio signal from controller, to get the pins configuration for motor and sensors

#elif IS_CONTROLLER
    Serial.println("Controller Mode");
    // Setup BLUETOOTH for controller and Wifi to connect to the server
    // Bluetooth to connect with a device that will provide the wifi credentials and the server credentials
    // this credentials will be saved in the EEPROM and used to connect to the server (just one time or when the credentials are changed)
    //
    // Wait for the bluetooth to connect and get the credentials

#endif
}

void loop()
{
}
