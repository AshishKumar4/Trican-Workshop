#pragma once

//Defines
#define KERNEL_MODE 0b00
#define USER_MODE 0b11

//Assembly Functions to load descriptors table onto the processor
extern void lgdt(void *);
extern void lidt(void *);
extern void tss_flush();

void init_descriptor_tables();

extern void PIT_handler();
extern void kb_handle();
extern void mouse_handle();

typedef uint64_t gdt_entry_t;
typedef uint16_t gdt_ptr_t[3];

typedef uint64_t idt_entry_t;
typedef uint16_t idt_ptr_t[3];