section .bss

esp_backup: RESD 1

esp_backup2: RESD 1

curr_dir: RESD 1
eax_backup: RESD 1

syscall_stack_back1: RESD 1
syscall_stack_back2: RESD 1
syscall_stack_back3: RESD 1

tmp_stack: RESD 1

tmp_intStack: RESD 4096

tmp_cr3: RESD 1

global t_c
t_c: RESD 1

section .text

[EXTERN PIT_Handle]
[GLOBAL PIT_handler]


PIT_handler:
  cli
  pusha

  call PIT_Handle

  popa 
  push eax 
  push ebx 
  mov dx, 0x20                      ; PIT Timer End Of Interrupt
  mov ax, 0x20
  out dx, ax
  mov dx, 0xA0
  mov ax, 0x20
  out dx, ax
  pop edx
  pop eax 
  iretd

 ; mov eax, [current_pdir]
 ; mov cr3, eax
 ; pop eax

  ;  push eax
    mov ax, ds 
    cmp ax, 0x10
    je jtetn

    mov eax, [tmp_cr3]
    mov cr3, eax
jtetn:
    pop eax 

  iret


[GLOBAL kb_handle]
[EXTERN keyboardInterrupt_handler]

kb_handle:
    cli
    pusha

    mov eax, esp
    mov [esp_backup], eax

    call keyboardInterrupt_handler

    mov eax, [esp_backup]
    mov esp, eax

    popa

    push eax
    mov eax, 0xFEE000B0                ; APIC Timer End Of Interrupt
    mov dword [eax], 0
    
    push edx
    mov dx, 0x20                      ; PIT Timer End Of Interrupt
    mov ax, 0x20
    out dx, ax
    pop edx
    pop eax

    iretd

[GLOBAL mouse_handle]
[EXTERN mouse_handler]

mouse_handle:
iretd;
    cli
    pusha

    mov eax, esp
    mov [esp_backup2], eax

    call mouse_handler

    mov eax, [esp_backup2]
    mov esp, eax

    popa

    push eax
    mov eax, 0xFEE000B0                ; APIC Timer End Of Interrupt
    mov dword [eax], 0
    ;    pop eax

    ;    push eax
    push edx
    mov dx, 0x20                      ; PIT Timer End Of Interrupt
    mov ax, 0x20
    out dx, ax
    mov dx, 0xA0
    mov ax, 0x20
    out dx, ax
    pop edx
    pop eax

    iretd

