#include <SoftwareSerial.h>

SoftwareSerial BLE(10, 9); // RX, TX

String tmp="";


void setup() {
  Serial.begin(9600);
  BLE.begin(9600); 
};

void loop() {

  while (BLE.available() > 0)  {
    tmp += char(BLE.read());
    delay(2);
  }

  if(tmp.length() > 0) {
    Serial.println(tmp);
    tmp = "";
  }

  if (Serial.available()) {
    BLE.write(Serial.read());
  }
}

