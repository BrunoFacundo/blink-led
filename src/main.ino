#include <TickerScheduler.h>

TickerScheduler scheduler(3);

int PIN_LED_1 = D2;
int PIN_LED_2 = D3;

int TIME_LED_1 = 250;
int TIME_LED_2 = 500;

bool isLed1On = false;
bool isLed2On = false;

void setup() {
    pinMode(PIN_LED_1, OUTPUT);
    pinMode(PIN_LED_2, OUTPUT);

    digitalWrite(PIN_LED_1, LOW);
    digitalWrite(PIN_LED_2, LOW);

    scheduler.add(0, TIME_LED_1, [&](void *) {
        blinkLed1();
    }, nullptr, true);
    scheduler.add(1, TIME_LED_2, [&](void *) {
        blinkLed2();
    }, nullptr, true);
}

void loop() {
    scheduler.update();

    digitalWrite(PIN_LED_1, isLed1On ? HIGH : LOW);
    digitalWrite(PIN_LED_2, isLed2On ? HIGH : LOW);
}

void blinkLed1() {
    isLed1On = !isLed1On;
}

void blinkLed2() {
    isLed2On = !isLed2On;
}