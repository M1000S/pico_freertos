#include "tasks.h"
#include "../proclist.h"
#include "trace.h"

TaskInfo_t TaskInfo[NUMBER_OF_TASKS]  = {0};


void setupTasks(void){
    //Core0
    xTaskCreateAffinitySet(c0_task_100ms, "C0_100", 1024, nullptr, 6, 0x01, nullptr);
    xTaskCreateAffinitySet(c0_task_1000ms, "C0_1000", 1024, nullptr, 5, 0x01, nullptr);
    //Core1
    xTaskCreateAffinitySet(c1_task_100ms, "C1_100", 1024, nullptr, 6, 0x02, nullptr);
    xTaskCreateAffinitySet(c1_task_1000ms, "C1_1000", 1024, nullptr, 5, 0x02, nullptr);
}



void c0_task_100ms(void *param){

    TickType_t xLastWakeTime;
    const TickType_t xFrequency = pdMS_TO_TICKS(100);
    xLastWakeTime = xTaskGetTickCount();
    TaskInfo[TASK_C0_100MS].starttime = millis();

    while(true)
    {
        TaskInfo[TASK_C0_100MS].xWasDelayed = xTaskDelayUntil( &xLastWakeTime, xFrequency );
        PreExeInfo(TASK_C0_100MS);

        #if (HEARTBEAT_C0 == ON)
        taskENTER_CRITICAL();
        Serial1.print("C0 100 cycle time: ");
        Serial1.print(TaskInfo[TASK_C0_100MS].cycletime);
        Serial1.print(" C0 100 run time: ");
        Serial1.println(TaskInfo[TASK_C0_100MS].runtime);
        taskEXIT_CRITICAL();
        #endif
        
        PROCLIST_C0_100
        delayMicroseconds(5000);

        PostExeInfo(TASK_C0_100MS);
    }
}

void c0_task_1000ms(void *param){
  
    TickType_t xLastWakeTime;
    const TickType_t xFrequency = pdMS_TO_TICKS(1000);
    xLastWakeTime = xTaskGetTickCount();
    TaskInfo[TASK_C0_1000MS].starttime = millis();

    while(true)
    {
        TaskInfo[TASK_C0_1000MS].xWasDelayed = xTaskDelayUntil( &xLastWakeTime, xFrequency );
        PreExeInfo(TASK_C0_1000MS);

        #if (HEARTBEAT_C0 == ON)
        taskENTER_CRITICAL();
        Serial1.print("C0 1000 cycle time: ");
        Serial1.print(TaskInfo[TASK_C0_1000MS].cycletime);
        Serial1.print(" C0 1000 run time: ");
        Serial1.println(TaskInfo[TASK_C0_1000MS].runtime);
        taskEXIT_CRITICAL();
        #endif
        
        PROCLIST_C0_1000
        delayMicroseconds(500000);

        PostExeInfo(TASK_C0_1000MS);
    }
}



void c1_task_100ms(void *param){
    TickType_t xLastWakeTime;
    const TickType_t xFrequency = pdMS_TO_TICKS(100);
    xLastWakeTime = xTaskGetTickCount();
    TaskInfo[TASK_C1_100MS].starttime = millis();

    while(true)
    {
        TaskInfo[TASK_C1_100MS].xWasDelayed = xTaskDelayUntil( &xLastWakeTime, xFrequency );
        PreExeInfo(TASK_C1_100MS);

        #if (HEARTBEAT_C1 == ON)
        taskENTER_CRITICAL();
        Serial1.print("C1 100 cycle time: ");
        Serial1.print(TaskInfo[TASK_C1_100MS].cycletime);
        Serial1.print(" C1 100 run time: ");
        Serial1.println(TaskInfo[TASK_C1_100MS].runtime);
        taskEXIT_CRITICAL();
        #endif
        
        PROCLIST_C1_100
        delayMicroseconds(5000);

        PostExeInfo(TASK_C1_100MS);
    }
}

void c1_task_1000ms(void *param){
    TickType_t xLastWakeTime;
    const TickType_t xFrequency = pdMS_TO_TICKS(1000);
    xLastWakeTime = xTaskGetTickCount();
    TaskInfo[TASK_C1_1000MS].starttime = millis();

    while(true)
    {
        TaskInfo[TASK_C1_1000MS].xWasDelayed = xTaskDelayUntil( &xLastWakeTime, xFrequency );
        PreExeInfo(TASK_C1_1000MS);

        #if (HEARTBEAT_C1 == ON)
        taskENTER_CRITICAL();
        Serial1.print("C1 1000 cycle time: ");
        Serial1.print(TaskInfo[TASK_C1_1000MS].cycletime);
        Serial1.print(" C1 1000 run time: ");
        Serial1.println(TaskInfo[TASK_C1_1000MS].runtime);
        taskEXIT_CRITICAL();
        #endif
        
        PROCLIST_C1_1000
        delayMicroseconds(500000);

        PostExeInfo(TASK_C1_1000MS);
    }
}


