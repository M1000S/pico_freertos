#include <Arduino.h>
#include <FreeRTOS.h>
#include <task.h>
#include "os/tasks.h"


void setup () {
    Serial1.setRX(1);
    Serial1.setTX(0);
    Serial1.begin(115200);
    Serial1.println("Pico Pi FreeRTOS");
    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
    setupTasks();
}



void loop () {
  
  delay(1500);
}


void setup1 () {

}

void loop1 () {
    delay(2000);
}