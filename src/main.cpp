#include <Arduino.h>

#define LED_PIN 2

void setup() {
    // 시리얼 통신 시작 (전송 속도 115200)
    Serial.begin(115200);
    pinMode(LED_PIN, OUTPUT);

    Serial.println("ESP32가 성공적으로 연결되었습니다!");
}

void loop() {
    // LED 켜기
    digitalWrite(LED_PIN, HIGH);
    Serial.println("LED ON - 농장 시스템 가동 중...");
    delay(1000);  // 1초 대기

    // LED 끄기
    digitalWrite(LED_PIN, LOW);
    Serial.println("LED OFF - 대기 중...");
    delay(1000);  // 1초 대기
}