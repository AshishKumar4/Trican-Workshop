#include "tasking.h"

void Scheduler()    // Round Robin Simple
{
    if(current_Qpos >= active_queue.Qlength)
    {
        current_Qpos = 0;
    }
    current_task = active_queue.queue[current_Qpos++];
    if(!current_task)
    {
        printf("No Task found");
        current_task = Idle_task;
    }
}