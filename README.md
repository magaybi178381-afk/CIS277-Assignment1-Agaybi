
#**CIS-277 Assignment 1: Network Packet Buffer Pool**

**Student**

Marc Agaybi

**Description**

This program implements a fixed-size memory pool for network packet buffers.

The memory pool creates a set number of blocks of the same size. Blocks can be allocated and returned to the pool. The pool also checks that blocks being returned are valid and prevents double deallocation.

The program demonstrates allocating blocks, writing binary data, releasing a block, reusing a block, exhausting the pool, and rejecting a double deallocation.

**Stack Implementation**

Dynamic Array

I selected a dynamic array because it is simple to implement and allows the stack to grow when more elements are added. The stack stores the free memory block pointers used by the memory pool.

**How to Compile**
g++ main.cpp MemoryPool.cpp -o main

**How to Run**
./main

**Analysis Questions**

1. Why is a Stack appropriate for managing the free blocks in this memory pool?

A Stack is appropriate because it allows the program to quickly add and remove free blocks. The most recently released block can be reused first.

2. What happens when the free-block Stack becomes empty?

When the Stack is empty, there are no free blocks available. allocate() returns nullptr.

3. Why must a released block be returned to the Stack?

The released block needs to be added back to the Stack so it can be reused by a future allocate() call.

4. What problem could occur if the same block were deallocated twice?

The same block could be added to the Stack twice. This could cause the program to allocate the same memory block more than once, which could lead to memory corruption.

5. What is the Big-O time complexity of allocate()? Explain why.

allocate() is O(1) because it checks if the Stack is empty and then pops one block from the top. Neither operation depends on the number of blocks.

6. What is the Big-O time complexity of deallocate()? Explain why.

deallocate() is O(1) because it checks the block's address, checks whether it is already allocated, and then pushes it back onto the Stack. These operations do not require searching through all the blocks.
