section .bss


section .text

[GLOBAL switcher_ksp_t]
[GLOBAL switcher_end_t]
[EXTERN current_task]
[EXTERN temp_stack_switcher]
[EXTERN Scheduler]

switcher_ksp_t:
    cli 
    pusha

    mov dword eax, [current_task]                 ;   Thread Structure
    mov dword [eax], esp                        ;   Save Current Stack

    mov dword esp, [temp_stack_switcher]          ;   Change to some temporary stack, I dont want to take risk
    mov dword ebp, [temp_stack_switcher]

    call Scheduler                              ;   call our scheduler
    
    mov dword eax, [current_task]                 ;   Get New Task Entry

    mov dword esp, [eax]                        ;   Load New Stack
    mov dword ebp, [eax]                        ;   Load New Stack

    popa                                        ;   Unload all Registers
    push dword eax                              ;   Safety Purpose
    push dword edx
    mov dx, 0x20                                ; PIC Timer End Of Interrupt
    mov ax, 0x20
    out dx, ax
    pop dword edx
    pop dword eax

    iretd

switcher_end_t:


