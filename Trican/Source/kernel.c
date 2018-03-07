#include "KLibrary/Library.c"
#include "Sources.c"

void kernel_start()
{
    init_descriptor_tables();
    vga_init();
    enable_pic();
    init_timer_PIT(1000);

    mem_init();
    
    keyboard_init();
    tasking_init();
    
   // printf("\nHello World");
    while(1);
}