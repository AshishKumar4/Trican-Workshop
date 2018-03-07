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
    
    printf("Level 5 : Memory Initialization\n");   
    while(1);   // An Infinite While loop so that our CPU does not wander off coast cuz it cant swim.
}