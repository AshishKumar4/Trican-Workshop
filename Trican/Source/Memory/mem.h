#pragma once

void mem_init();
uint32_t pop_frameStack();
void push_frameStack(uint32_t fr);
uint32_t phy_alloc4K();
void* kmalloc(size_t size);
uint32_t pmem_4k(int size);
void kfree(void* addr);
