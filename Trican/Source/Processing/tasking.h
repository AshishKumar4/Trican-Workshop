#pragma once

extern void switcher_ksp_t();

// Task Descriptor Structure
typedef struct task     
{
    uint32_t stack;
    uint32_t tokens;            //20
    uintptr_t active;            //24
    uint32_t RtFlags;
    uint32_t mem_used;
    uint32_t task_id;
    char name[50];
}task_t;

typedef struct TaskQueue 
{
    task_t** queue;
    uint32_t Qlength;
}TaskQueue_t;

TaskQueue_t active_queue;
task_t* current_task;   // The Currently running task
task_t* Idle_task;
uint32_t current_Qpos = 0;     // The Position of the current_task in the active_queue
uint32_t task_counter = 0;
uint32_t MAX_ACTIVE_TASKS;
uint32_t* temp_stack_switcher;

task_t* create_task(char* name, func_t func, uint32_t priority, uint32_t flags);
task_t* task_GetSelf();
void Enqueue_task(TaskQueue_t* Queue, task_t* task);
void Task_Remover(TaskQueue_t* Queue, uintptr_t place_holder);
void kill();
void Task_sleep(task_t* task);
void Task_wakeup(task_t* task);

void Scheduler();