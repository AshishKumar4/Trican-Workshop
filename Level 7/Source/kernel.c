#include "KLibrary/Library.c"
#include "Sources.c"

/*
    Our C Kernel
    Initializes the Descriptor Tables, Console Drivers, and Interrupts throught PIC Chip
*/

void kernel_start()
{
    init_descriptor_tables(); // Initialize Descriptor Tables, the GDT and the IDT.
    vga_init(); // Initialize Console Screen (VGA)
    enable_pic();   // Initialize PIC Chip to enable Hardware Interrupt Handling
    init_timer_PIT(10);

    mem_init();

    keyboard_init();
    setIRQMask(0);  // Switch off the PIT Timer Interrupts
    tasking_init();
    
    printf("Level 7: Premptive Multitasking\nPress Enter to watch Process A, Process B and Prcocess C print simultaneously on the screen!");   
    while(!enter_pressed); 
    setIRQMask(1); // Enable the PIT Timer so to enable the multitasking system
    while(1);   // An Infinite While loop so that our CPU does not wander off coast cuz it cant swim.
}