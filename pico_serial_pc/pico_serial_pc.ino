#include <Arduino.h>
#define LED_PIN 25
#define ADC_PIN 26
#define BUTTON_PIN 21

void setup() {
  Serial.begin(115200);  // PCへのシリアル通信の開始
  Serial1.begin(115200);  // Pico Wからのシリアル通信の開始
}

void loop() {
  if (Serial1.available()) {
    String data = Serial1.readStringUntil('\n');  // 改行文字まで読み取り
    if (data.length() > 0) {  // データが空でない場合
      int sensorValue = data.toInt();  // 文字列を整数に変換
      Serial.println(sensorValue);  // PCにデータを送信
    }
  }
}