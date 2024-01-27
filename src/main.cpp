#include <Arduino.h>
#include <FreeRTOS.h>
#include <task.h>
#include "os/tasks.h"


void setup () {
    Serial1.setRX(1);
    Serial1.setTX(0);
    Serial1.begin(115200);
    Serial1.println("Pico Pi OS");
    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
    setupTasks();
}



void loop () {
  #if (PRINT_STATISTICS == ON)
    
    
    //taskENTER_CRITICAL();
  
    Serial1.print("Max Task cycle times [ms] \t- ");
    for(uint j = 0; j < (NUMBER_OF_CORE0_TASKS+NUMBER_OF_CORE1_TASKS); j++){
      Serial1.printf("%.4d, ", TaskInfo[j].cycletime_max);
    }
    for(uint j = 0; j < (NUMBER_OF_CORE0_TASKS+NUMBER_OF_CORE1_TASKS); j++){
      Serial1.printf("%.4d, ", TaskInfo[j].cycletime);
    }
    Serial1.print("Max Task run times [ms] \t- ");
    for(uint j = 0; j < (NUMBER_OF_CORE0_TASKS+NUMBER_OF_CORE1_TASKS); j++){
      Serial1.printf("%.4d, ", TaskInfo[j].runtime_max);
    }
    Serial1.println(xWasDelayed);
    Serial1.println("");
    //taskEXIT_CRITICAL();
  #endif
  
  delay(1500);
}


void setup1 () {

}

void loop1 () {
    delay(2000);
}