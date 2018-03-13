#include "string.h"
#include "stdint.h"
#include "stdlib.h"
#include "stddef.h"
#include "sys.h"
#include "Drivers/Keyboard/scancodes.h"
#include "Drivers/Keyboard/keyboard.h"

void divByZero_handler()
{
  printf("\nFault0");
  asm volatile("hlt");
}

void debug_handler()
{
  printf("\nFault1");
  asm volatile("hlt");
}

void NMI_handler()
{
  printf("\nFault2");
  asm volatile("hlt");
}

void breakpoint_handler()
{
  printf("\nFault3");
  asm volatile("hlt");
}

void overflow_handler()
{
  printf("\nFault4");
  asm volatile("hlt");
}

void outOfBounds_handler()
{
  printf("\nFault5");
  asm volatile("hlt");
}

void invalidInstr_handler()
{
  printf("\nFault6");
  asm volatile("hlt");
}

void noCoprocessor_handler()
{
  printf("\nFault7");
  asm volatile("hlt");
}

void doubleFault_handler()
{
  printf("\nFault8");
  asm volatile("hlt");
}

void coprocessor_handler()
{
  printf("\nFault9");
  asm volatile("hlt");
}


void badTSS_handler()
{
  printf("\nFault10");
  asm volatile("hlt");
}

void segmentNotPresent_handler()
{
  printf("\nFault11");
  asm volatile("hlt");
}

void stackFault_handler()
{
  printf("\nFault12");
  asm volatile("hlt");
}

void generalProtectionFault_handler()
{
  printf("\nFault13");
  asm volatile("hlt");
}

void pageFault_caller()
{
  printf("\nFault14");
  asm volatile("hlt");
}

void unknownInterrupt_handler()
{
  printf("\nFaul15");
  asm volatile("hlt");
}


void coprocessorFault_handler()
{
  printf("\nFault16");
  asm volatile("hlt");
}


void alignmentCheck_handler()
{
  printf("\nFault17");
  asm volatile("hlt");
}


void machineCheck_handler()
{
  printf("\nFault18");
  asm volatile("hlt");
}


void reserved_handler()
{
  printf("\nFault19");
  asm volatile("hlt");
}

void PIT_Handle()
{
    //printf("\nPIT ticked");
}

void keyboardInterrupt_handler()
{
  int scancode=inb(0x60);
  if(scancode <= 0x80+0x60)
  {
    MainScodes->scodes[scancode].func(MainScodes->scodes[scancode].code);
   // printf("[%x %x]", scancode, scancodes[scancode]);
  }
}

void cascade_handler()
{
    printf("\nInterrupt 2");
    while(1);
}

//This particular interrupt is never raised
void COM2_handler()
{
    asm volatile("cli");
    printf("\nInterrupt 3");
    while(1);
    asm volatile("iret");
}


void COM1_handler()
{
  asm volatile("cli");
  printf("\nInterrupt 4");
  while(1);
  asm volatile("iret");
}


void LPT2_handler()
{
  asm volatile("cli");
  printf("\nInterrupt 5");
  while(1);
  asm volatile("iret");
}


void floppyDisk_handler()
{
  asm volatile("cli");
  printf("\nInterrupt 6");
  while(1);
  asm volatile("iret");
}


void LPT1_handler()
{
  asm volatile("cli");
  printf("\nInterrupt 7");
  while(1);
  asm volatile("iret");
}


void RTC_handler()
{
  asm volatile("cli");
  printf("\nInterrupt 8");
  while(1);
  asm volatile("iret");
}


void periph1_handler()
{
  asm volatile("cli");
  printf("\nInterrupt 9");
  while(1);
  asm volatile("iret");
}


void periph2_handler()
{
  asm volatile("cli");
  printf("\nInterrupt 10");
  while(1);
  asm volatile("iret");
}


void periph3_handler()
{
  asm volatile("cli");
  printf("\nInterrupt 11");
  while(1);
  asm volatile("iret");
}

void mouse_handler()
{
}

void FPU_handler()
{
  asm volatile("cli");
  printf("\nInterrupt 13");
  while(1);
  asm volatile("iret");
}


void primaryHDD_handler()
{
  asm volatile("cli");
  printf("\nInterrupt 14");
  while(1);
  asm volatile("iret");
}

//P -> Primary
void secondaryHDD_handler()
{
  asm volatile("cli");
  printf("\nInterrupt 15");
  while(1);
  asm volatile("iret");
}

//S -> Secondary
