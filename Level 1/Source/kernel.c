#include "KLibrary/Library.c"
#include "Sources.c"

/*
   Our C Kernel, Just initializes VGA, and prints "Hello World" 
*/

void kernel_start()
{
    vga_init(); // Initialize Console Screen (VGA)
    printf("Level 1: Getting Started\nHello World");   
    while(1);   // An Infinite While loop so that our CPU does not wander off coast cuz it cant swim.
}