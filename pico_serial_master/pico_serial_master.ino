#include "SoftwareSerial.h"

void checkSoftSerial(SoftwareSerial &serial, String label);
void checkHardSerial(SerialUART &serial, String label);

SoftwareSerial Pico2Serial(13, 14);
SoftwareSerial Pico3Serial(16, 17);
SoftwareSerial Pico4Serial(10, 11);
SoftwareSerial Pico5Serial(24, 25);

void setup() {
  Pico2Serial.begin(9600);
  Pico3Serial.begin(9600);
  Pico4Serial.begin(9600);
  Pico5Serial.begin(9600);

  Serial.begin(115200);

  // UART0の初期化
  Serial1.begin(115200); // PicoのUART0、GP0 (TX), GP1 (RX)
  
  // UART1の初期化
  Serial2.setTX(4); // これ忘れない
  Serial2.setRX(5);
  Serial2.begin(115200); // PicoのUART1、GP4 (TX), GP5 (RX)
}

void loop() {
  Serial.println("MasterLOOP");

  // ソフトシリアルに送信
  Pico2Serial.println("Hello Pico2");
  Pico3Serial.println("Hello Pico3");
  Pico4Serial.println("Hello Pico4");
  Pico5Serial.println("Hello Pico5");
  // ハードシリアルに送信
  Serial1.println("Hello Serial1");
  Serial2.println("Hello Serial2");

  // 受信した文字列をUSBシリアルに送信
  checkSoftSerial(Pico2Serial, "Pico2");
  checkSoftSerial(Pico3Serial, "Pico3");
  checkSoftSerial(Pico4Serial, "Pico4");
  checkSoftSerial(Pico5Serial, "Pico5");
  checkHardSerial(Serial1, "Serial1");
  checkHardSerial(Serial2, "Serial2");

  delay(1000);
}

void checkSoftSerial(SoftwareSerial &serial, String label) {
  if (serial.available()) {
    String received = serial.readStringUntil('\n');
    if (received.length() > 0) {
      Serial.println(label + " received: " + received);
    }
  }
}

void checkHardSerial(SerialUART &serial, String label) {
  if (serial.available()) {
    String received = serial.readStringUntil('\n');
    if (received.length() > 0) {
      Serial.println(label + " received: " + received);
    }
  }
}