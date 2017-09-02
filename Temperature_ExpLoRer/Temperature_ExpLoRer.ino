/* DeviceInfo_ExpLoRer.ino
 *  
 * Get the onboard temperature reading from a Sodaq ExpLoRer board.
 *  
 * @DefProc
 */
 
#define debugSerial SerialUSB
#define hwSerial    Serial
#define btSerial    Serial1
#define loraSerial  Serial2

void setup()
{
  debugSerial.begin(115200);
  //hwSerial.begin(57600);  
  //btSerial.begin(57600);  
  loraSerial.begin(57600);

  while ((!SerialUSB) && (millis() < 10000)) {
    // Wait for SerialUSB or start after 10 seconds
  }
  
  debugSerial.println(F("Temperature ExpLoRer:"));

  // use the onboard MCP9700AT analog output temperature sensor (on pin A6)
  pinMode(TEMP_SENSOR, INPUT);
}

void loop()
{
  // Vout from MCP9700AT is 10 mV/⁰C - 0.5V
  // -10 to +125⁰C, ±1⁰C accuracy
  float temp = -10.0;
  
  // run 10 times quickly and take the maximum (for stability)
  for (int i=0; i<10; i++) {
    float mVolts = (float)analogRead(TEMP_SENSOR) * 3300.0 / 1023.0;
    float new_temp = (mVolts - 500.0) / 10.0;
    // save value if it's higher than is already recorded
    if (new_temp > temp) {
      temp = new_temp;
    }
    delay(10);
  }
  
  debugSerial.print(temp);
  debugSerial.println(" ⁰C");

  delay(900);
}
