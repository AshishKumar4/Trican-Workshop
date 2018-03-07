#include "KLibrary/Library.c"
#include "Sources.c"

/*
   Our C Kernel, Initializes the GDT, IDT and then the VGA, and prints "Hello World" 
*/

void kernel_start()
{
    init_descriptor_tables(); // Initialize Descriptor Tables, the GDT and the IDT.
    vga_init(); // Initialize Console Screen (VGA)
    printf("Level 2 : Descriptor Tables\nHello World");   
    while(1);   // An Infinite While loop so that our CPU does not wander off coast cuz it cant swim.
}