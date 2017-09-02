/* DeviceInfo_ExpLoRer.ino
 *  
 * Get the device information (DevEUI) of the LoRaWAN radio 
 * on a Sodaq ExpLoRer board, for use with The Things Network 
 * (or compatible service).
 *  
 * Requires The Things Network Library: https://github.com/TheThingsNetwork/arduino-device-lib
 * 
 * @DefProc
 */
 
#include <TheThingsNetwork.h>

#define debugSerial SerialUSB
#define hwSerial    Serial
#define btSerial    Serial1
#define loraSerial  Serial2

// Use either TTN_FP_EU868 or TTN_FP_US915
#define freqPlan TTN_FP_EU868

TheThingsNetwork ttn(loraSerial, debugSerial, freqPlan);

void setup()
{
  debugSerial.begin(115200);
  //hwSerial.begin(57600);  
  //btSerial.begin(57600);  
  loraSerial.begin(57600);

  while ((!SerialUSB) && (millis() < 10000)) {
    // Wait for SerialUSB or start after 10 seconds
  }
  
  debugSerial.println("Device Information");
  debugSerial.println();
  ttn.showStatus();
  debugSerial.println();
  debugSerial.println("Use the EUI to register the device for OTAA");
  debugSerial.println("-------------------------------------------");
  debugSerial.println();
}

void loop()
{
  //none
  return;
}
