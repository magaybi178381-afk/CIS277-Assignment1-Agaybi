#include <cstddef>
#include "Stack.h"

class MemoryPool
{
Private:
    size_t blockS;
    size_t blockC;

    unsigned char* memory;

    Stack<void*> freeStack;

    bool* allocated;
public:
    MemoryPool(size_t blockSize, size_t blockCount);
    ~MemoryPool();

    void* allocate();
    bool deallocate(void* ptr);

    size_t availableBlocks() const;
    size_t allocatedBlocks() const;
    size_t blockSize() const;
    size_t capacity() const;
};
