#include <Arduino.h>

void setup() {
  // UART0の初期化
  Serial1.begin(115200); // PicoのUART0、GP0 (TX), GP1 (RX)
}

void loop() {
  if (Serial1.available()) {
    String data = Serial1.readStringUntil('\n');
    Serial.println("Received from Pico1: " + data);
    // Pico1へ応答
    Serial1.println("Acknowledged: " + data);
  }
}
