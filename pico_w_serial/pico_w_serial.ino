#include <Arduino.h>
#define LED_PIN 25
#define ADC_PIN 26
#define BUTTON_PIN 21

void setup() {
  pinMode(LED_PIN, OUTPUT); // Pico LED output

  Serial.begin(115200);  // PCへのシリアル通信の開始
  Serial1.begin(115200);  // Pico Wからのシリアル通信の開始
  analogReadResolution(12);  // ADCの分解能を12ビットに設定

  pinMode(BUTTON_PIN, INPUT);
  
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH); // Pico W LED
  digitalWrite(LED_PIN, HIGH); // Pico LED

  // int sensorValue = analogRead(ADC_PIN);
  // Serial1.println(sensorValue); // PicoにADC値を送信
  // delay(1000);

  int buttonState = digitalRead(BUTTON_PIN);  // ボタンの状態を読み取り
  Serial1.println(buttonState);  // ボタンの状態をPico2に送信
  Serial.println(buttonState);
  delay(100);  // 少しの遅延で連続送信を防ぐ
}