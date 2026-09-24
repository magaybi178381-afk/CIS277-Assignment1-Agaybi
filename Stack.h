#ifndef STACK_H
#define STACK_H

#include <cstddef>

template <typename T>
class Stack
{
private:
    T* data;
    size_t capacity;
    size_t count;

public:
    Stack()
    {
        data = nullptr;
        capacity = 0;
        count = 0;
    }

    ~Stack()
    {
        delete[] data;
    }

    void push(const T& value)
    {
        if (count == capacity)
        {
            size_t newCapacity = capacity + 1;

            T* newData = new T[newCapacity];

            for (size_t i = 0; i < count; i++)
            {
                newData[i] = data[i];
            }

            delete[] data;

            data = newData;
            capacity = newCapacity;
        }

        data[count] = value;
        count++;
    }

    T pop()
    {
        count--;
        return data[count];
    }

    T& top()
    {
        return data[count - 1];
    }

    bool empty() const
    {
        return count == 0;
    }

    size_t size() const
    {
        return count;
    }
};

#endif
