#include "stdint.h"
#include "mem.h"

/*
    Your first step shall be to implement a good Physical Memory Allocator
    And when the time comes to turn on Paging, You need a good Memory Management System Altogether
    Checkout github.com/AshishKumar4/Aqeous for help
*/

uint32_t* frame_stack_end = (uint32_t*)(16*1024*1024);

// Frames allocated after 512th MB to 2GB

void mem_init()
{
    for(int i = 524288; i > 131072 ; i-=4096)
    {
        push_frameStack(i);
    }
}

uint32_t pop_frameStack()
{
	uint32_t fr;
	back:
	fr = *frame_stack_end;
	--frame_stack_end;
	if(!fr)
	{
		printf("\nNo memory left! %x",fr);
		asm volatile("hlt");
		goto back;
	}
	return fr;
}

void push_frameStack(uint32_t fr)
{
	++frame_stack_end;
	*frame_stack_end = fr;
}

uint32_t phy_alloc4K()
{
    return pop_frameStack()*4096;
}

uint32_t base_addr = (40*1024*1024);

void* kmalloc(size_t size)
{
    uint32_t a = base_addr;
	base_addr += size;
    return (void*)a;
}

uint32_t pmem_4k(int size)  // Returns 4 Kilobyte aligned Memory i.e, memory address rounded up to 4096.
{
	uint32_t tmp = ((uint32_t)kmalloc((size+1)*4096));
	return ROUNDUP(tmp, 4096);
}

void kfree(void* addr)
{
    *(int*)addr = 0;
    return;
}
