#ifndef TASKS_H
#define TASKS_H

#include <Arduino.h>
#include <FreeRTOS.h>
#include <task.h>


#define ON (1)
#define OFF (0)

#define HEARTBEAT_C0 (OFF)
#define HEARTBEAT_C1 (OOFFN)
#define PRINT_STATISTICS (OFF)

#define NUMBER_OF_CORES (2)
#define NUMBER_OF_CORE0_TASKS (2)  // without platform tasks
#define NUMBER_OF_CORE1_TASKS (2)  // without platform tasks

enum Tasks{
    TASK_C0_100MS,
    TASK_C0_1000MS,
    TASK_C1_100MS,
    TASK_C1_1000MS,
    NUMBER_OF_TASKS
};

typedef struct{
    unsigned long starttime;
    unsigned long runtime;
    unsigned long runtime_max;
    unsigned long runtime_min;
    unsigned long cycletime;
    unsigned long cycletime_max;
    unsigned long cycletime_min;
    unsigned long callcounter;
    UBaseType_t uxHighWaterMark;
    UBaseType_t xWasDelayed;

}TaskInfo_t;

extern TaskInfo_t TaskInfo[];

extern void setupTasks(void);
extern void c0_task_100ms(void *param);
extern void c0_task_1000ms(void *param);
extern void c1_task_100ms(void *param);
extern void c1_task_1000ms(void *param);

#endif