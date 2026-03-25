#include <Arduino.h>

const int ldrPin = 34;
const int ledPin = 2;

void setup() {
    Serial.begin(115200);
    pinMode(ledPin, OUTPUT);
    Serial.println("--- 스마트 가로등 시스템 가동 ---");
}

void loop() {
    int val = analogRead(ldrPin);

    // 조도 수치 출력
    Serial.print("LDR: ");
    Serial.println(val);

    // [중요] 태성님의 수치(600~2500)를 고려한 기준점 설정
    // 600(어둠)과 2500(밝음)의 중간인 1200~1500 정도가 적당합니다.
    int threshold = 1200;

    if (val < threshold) {
        // 어두워지면 LED ON
        digitalWrite(ledPin, HIGH);
        Serial.println("상태: [DARK] - 가로등 점등");
    } else {
        // 밝아지면 LED OFF
        digitalWrite(ledPin, LOW);
        Serial.println("상태: [BRIGHT] - 가로등 소등");
    }

    delay(500);  // 0.5초마다 스캔 (Throttle)
}