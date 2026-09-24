#include <cstddef>

template <typename T>
class Stack
{   
Private:
    T* data;
    size_t capacity;
    size_t count;
    
Public:
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
        if(count ==  capacity)
        {
            size_t newCap = capacity + 1;
            T* newData = new T[newCap];

            for(size_t = 0; i <count; i++)
            {
                newData[i] = data[i];
            }
            
            delete[] data;
            data = newData;
            capacity = newCap;

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
        data[count-1];
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
