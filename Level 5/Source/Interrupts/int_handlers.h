#pragma once


//Interrupt handlers
void divByZero_handler();
void debug_handler();
void NMI_handler();
void breakpoint_handler();
void overflow_handler();
void outOfBounds_handler();
void invalidInstr_handler();
void noCoprocessor_handler();
void doubleFault_handler();
void coprocessor_handler();
void badTSS_handler();
void segmentNotPresent_handler();
void stackFault_handler();
void generalProtectionFault_handler();
void pageFault_handler();
void unknownInterrupt_handler();
void coprocessorFault_handler();
void alignmentCheck_handler();
void machineCheck_handler();
void reserved_handler();

//#ifdef PIC
extern void PIT_handler();
extern void kb_handle();
extern void switch_ToUserspace();
extern void switch_ToKernelspace();
//extern void Scheduler_Promoter_assistance();
extern void switcher_ksp();
extern void switcher_ksp2();
void keyboardInterrupt_handler();
void cascade_handler();//This particular interrupt is never raised
void COM2_handler();
void COM1_handler();
void LPT2_handler();
void floppyDisk_handler();
void LPT1_handler();
void RTC_handler();
void periph1_handler();
void periph2_handler();
void periph3_handler();
void mouse_handle();
void FPU_handler();
void primaryHDD_handler();//P -> Primary
void secondaryHDD_handler();//S -> Secondary
//#endif
