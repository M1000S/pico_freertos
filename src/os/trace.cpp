#include "trace.h"


void PreExeInfo(Tasks task)
{
    TaskInfo[task].callcounter++;
    TaskInfo[task].cycletime = millis() - TaskInfo[task].starttime; 
    TaskInfo[task].starttime = millis();
    if(TaskInfo[task].cycletime > TaskInfo[task].cycletime_max)
    {
        TaskInfo[task].cycletime_max = TaskInfo[task].cycletime;
    }
}

unsigned long PostExeInfo(Tasks task)
{
    TaskInfo[task].uxHighWaterMark = uxTaskGetStackHighWaterMark(NULL);
    TaskInfo[task].runtime = millis() - TaskInfo[task].starttime;
    if(TaskInfo[task].runtime > TaskInfo[task].runtime_max)
    {
        TaskInfo[task].runtime_max = TaskInfo[task].runtime;
    }
    return TaskInfo[task].runtime;
}