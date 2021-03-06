;   This is the code which boots the Main OS
;   The OS depends upon GRUB2 as its bootloader
;   GRUB2 searches for specific magic number and 
;   numerical patterns on the disk to identify any 
;   installed OS. 
;   The code written here makes those patterns for
;   GRUB2 to identify and run our OS.

section .multiboot      ;   This is the topmost section of the entire OS code.
ALIGN 4     
dd 0x1BADB002           ;   GRUB 2 Magic Number
dd 3                    ;   Flags
dd -(0x1BADB005)        ;   Checksum of this entire section

ALIGN 32
section .text           ;   Multiboot header immediately followed by the OS Code
[EXTERN kernel_start]
[GLOBAL _start]
_start:                 ;   First Function to get executed; places the CPU on the orbit of the OS
    call kernel_start   ;   Call our C Function 
    hlt                 ;   Ideally it should never reach here
