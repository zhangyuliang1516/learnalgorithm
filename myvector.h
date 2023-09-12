#pragma once

template <typename T>
class Vector
{
public:
    Vector()
    {
        data = new T[10];
        size = 0;
        capacity = 10;
    }
    void push_back(T t)
    {
        if (size == capacity)
            resize(2 * capacity);
        data[size++] = t;
    }
    T pop_back()
    {
        size--;
        return data[size];
    }

private:
    void resize(int newCapacity)
    {
        T *newData = new T[newCapacity];
        for (int i = 0; i < size; ++i)
            newData[i] = data[i];
        data = newData;
        capacity = newCapacity;
    }

    T *data;
    int size;
    int capacity;
};
