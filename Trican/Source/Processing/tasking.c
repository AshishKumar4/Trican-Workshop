#include "tasking.h"
#include "stdint.h"
#include "stdio.h"
#include "stdlib.h"
#include "Memory/mem.h"

#include "Scheduler.c"
#include "Shell/Shell.h"

void idle_task()
{
    while(1);
}

void Spawner_Task()
{
  kill();
  while(1);
}
/*
void Spawner_Task2()
{
  printf("This Shit is WORKING2!");
  while(1)
    printf("2 ");
}

void Spawner_Task3()
{
  printf("This Shit is WORKING!");
  while(1)
    printf("3 ");
}*/

int tasking_init()
{
    MAX_ACTIVE_TASKS = 4096;
    active_queue.queue = (task_t**)kmalloc(MAX_ACTIVE_TASKS * sizeof(task_t*));
    temp_stack_switcher = kmalloc(4096);
    temp_stack_switcher += 1024;

    Idle_task = create_task("Idle_task", &idle_task, 0, 0x202);
    current_task = Idle_task;

    Enqueue_task(&active_queue, create_task("System_Spawner", &Spawner_Task, 0, 0x202));
   /* Enqueue_task(&active_queue, create_task("System_Spawner2", &Spawner_Task2, 0, 0x202));
    Enqueue_task(&active_queue, create_task("System_Spawner3", &Spawner_Task3, 0, 0x202));*/

    Shell_task = create_task("Shell", &Shell, 0, 0x202);
    Enqueue_task(&active_queue, Shell_task);

    idtSetEntry(32, (uint32_t)&switcher_ksp_t, 0x08, makeFlagByte(1, KERNEL_MODE), (uint64_t*)&idt_entries);
    lidt((void *)&idt_ptr);
    return 0;
}

task_t* create_task(char* name, func_t func, uint32_t priority, uint32_t flags)  /// Create a New Task for a given Process
{
	task_t* New_task = (task_t*)pmem_4k(2);
	uint32_t* stack = (uint32_t*)New_task;

    memset_fast((void*)stack,0,4096);
    
	strcpy(New_task->name, name);
	New_task->task_id = task_counter;
	New_task->mem_used = 0;

	stack += 1024;

	uint32_t base=(uint32_t)stack;

	*--stack = flags; //EFLAGS
	*--stack = 0x8; //cs
	*--stack = (uint32_t)func; //eip

	*--stack = 0x4284; // eax
	*--stack = 0; // ecx
	*--stack = 0; // edx;
	*--stack = 0; //ebx
	*--stack = (uint32_t)(base-16); //esp
	*--stack = (uint32_t)(base-16); //ebp
	*--stack = 0; //esi
	*--stack = 0; //edi


	New_task->stack = (uint32_t)stack;
	New_task->tokens = priority;
    
	return New_task;
}

task_t* task_GetSelf()
{
	return current_task;
}

void Enqueue_task(TaskQueue_t* Queue, task_t* task) /// Put a given Task_entry into an appropriate queue for it to be executed.
{
    Queue->queue[Queue->Qlength++] = task;  // Put the task into the queue as well as extend the queue length
    if(Queue->Qlength == MAX_ACTIVE_TASKS)
    {
        // Reallocate the queue memory
    }
    task->active = (uintptr_t)&Queue->queue[Queue->Qlength - 1];
}

void Task_Remover(TaskQueue_t* Queue, uintptr_t place_holder)		// Remove the task from scheduler queue
{
	*(task_t**)place_holder = Queue->queue[--Queue->Qlength];      // Remove a task from the end of the queue and place it here
}

void kill()	
{
	uintptr_t place_holder = (uintptr_t)(current_task->active);
	Task_Remover(&active_queue, place_holder);
    kfree(current_task);
    asm volatile("sti");
    while(1);
    //Scheduler();
}

/*
    Not much functionality added for sleeping tasks, Activation and Wakeup diverge 
    as the level of complexity of the code increases.
*/

void Task_sleep(task_t* task)
{
	Task_Remover(&active_queue, (uintptr_t)(task->active));
}

void Task_wakeup(task_t* task)
{
    Enqueue_task(&active_queue, task);
}

