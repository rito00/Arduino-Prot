#include "SoftwareSerial.h"

SoftwareSerial mySerial(16, 17);  // GP16をRX, GP17をTXとして使用

const int analogPin = A0;  // アナログ入力ピン
const int digitalPin = 2;  // デジタル入力ピン

void setup() {
  mySerial.begin(9600);
  Serial.begin(9600);  // デバッグ用にUSBシリアルを開始
  pinMode(digitalPin, INPUT);  // デジタル入力ピンを入力モードに設定
}

void loop() {
  if (mySerial.available()) {
    String data = mySerial.readStringUntil('\n');
    Serial.println("Received from Pico1: " + data);
    
    // アナログ入力値とデジタル入力値を取得
    int analogValue = analogRead(analogPin);
    int digitalValue = digitalRead(digitalPin);
    
    // 応答の準備
    String response = "Acknowledged: " + data + ", Analog: " + String(analogValue) + ", Digital: " + String(digitalValue);
    mySerial.println(response);
  }
}