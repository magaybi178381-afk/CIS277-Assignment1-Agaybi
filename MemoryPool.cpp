#include "MemoryPool.h"

MemoryPool::MemoryPool(size_t blockSize, size_t blockCount)
{
    blockSize_ = blockSize;
    blockCount_ = blockCount;

    memory = new unsigned char[blockSize_ * blockCount_];

    allocated = new bool[blockCount_];

    for (size_t i = 0; i < blockCount_; i++)
    {
        allocated[i] = false;

        void* block = memory + i * blockSize_;

        freeStack.push(block);
    }
}

MemoryPool::~MemoryPool()
{
    delete[] memory;
    delete[] allocated;
}

void* MemoryPool::allocate()
{
    if (freeStack.empty())
    {
        return nullptr;
    }

    void* block = freeStack.pop();

    unsigned char* address =
        static_cast<unsigned char*>(block);

    size_t index =
        (address - memory) / blockSize_;

    allocated[index] = true;

    return block;
}

bool MemoryPool::deallocate(void* ptr)
{
    if (ptr == nullptr)
    {
        return false;
    }

    unsigned char* address =
        static_cast<unsigned char*>(ptr);

    if (address < memory ||
        address >= memory + blockSize_ * blockCount_)
    {
        return false;
    }

    size_t index =
        (address - memory) / blockSize_;

    if ((address - memory) % blockSize_ != 0)
    {
        return false;
    }

    if (!allocated[index])
    {
        return false;
    }

    allocated[index] = false;

    freeStack.push(ptr);

    return true;
}

size_t MemoryPool::availableBlocks() const
{
    return freeStack.size();
}

size_t MemoryPool::allocatedBlocks() const
{
    return blockCount_ - freeStack.size();
}

size_t MemoryPool::blockSize() const
{
    return blockSize_;
}

size_t MemoryPool::capacity() const
{
    return blockSize_ * blockCount_;
}
