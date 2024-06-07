#include <SPI.h>

#define PWM 25  //PWM 出力は 25th pin おまけ

void setup() {
  pinMode(PWM, OUTPUT);
}

void loop() {
  for (int i = 0; i < 360; i++) {
    float rad = radians(i);
    int brightness = (sin(rad) * 127.5) + 127.5; // 0から255の範囲に変換
    analogWrite(PWM, brightness);
    delay(10);
  }
}