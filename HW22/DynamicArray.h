#pragma once
#include <iostream>
#include <cstdlib>
#include <algorithm>

template <typename T>

class DynamicArray
{
public:
    //default c-tor
    DynamicArray() : m_array(nullptr), m_size(0), m_capacity(0) {}

    //c-tor with size
    DynamicArray(std::size_t size) : m_size(size), m_capacity(size)
    {
        m_array = new T[m_capacity];
    }

    //copy c-tor
    DynamicArray(const DynamicArray& otherArray) : m_size(otherArray.m_size) , m_capacity(otherArray.m_capacity)
    {
        m_array = new int[m_capacity];
        std::copy(otherArray.m_array, otherArray.m_array + m_size, m_array);
    }


    //free allocated memory
    ~DynamicArray() 
    {
        delete[] m_array;
    }

    DynamicArray& operator=(const DynamicArray& otherArray)
    {
        if (this != &otherArray) {
            delete[] m_array;
            m_size = otherArray.m_size;
            m_capacity = otherArray.m_capacity;
            m_array = new int[m_capacity];
            std::copy(otherArray.m_array, otherArray.m_array + m_size, m_array);
        }
        return *this;
    }
   

    T& operator[](std::size_t idx)
    {
        if (idx >= m_size) {
            std::cout << "Out of range!" << std::endl;
        }
        return m_array[idx];
    }

    //delete previous memory, create new inner array with updated size
    void setSize(std::size_t newSize)
    {
        if (newSize != m_size)
        {
            if (newSize > m_capacity)
            {
                T* newArray = new T[newSize];
                std::copy(m_array, m_array + m_size, newArray);
                delete[] m_array;
                m_array = newArray;
                m_capacity = newSize;
            }
            m_size = newSize;
        }
    }
    std::size_t getSize() const
    {
        return m_size;
    }

    void reserve(std::size_t space)
    {
        if (space > m_capacity)
        {
            T* newArray = new T[space];
            std::copy(m_array, m_array + m_size, newArray);
            delete[] m_array;
            m_array = newArray;
            m_capacity = space;
        }
    }

    std::size_t getCapacity() const
    {
        return m_capacity;
    }

    void shrinkToFit()
    {
        if (m_capacity > m_size)
        {
            T* newArray = new T[m_size];
            std::copy(m_array, m_array + m_size, newArray);
            delete[] m_array;
            m_array = newArray;
            m_capacity = m_size;
        }
    }


    //Clear internal memory, set size to 0
    void clear() 
    {
        delete[] m_array;
        m_array = nullptr;
        m_size = 0;
    }

    bool operator==(const DynamicArray& otherArray)
    {
        if (m_size != otherArray.m_size) {
            return false;
        }
        for (std::size_t i = 0; i < m_size; ++i) {
            if (m_array[i] != otherArray.m_array[i]) {
                return false;
            }
        }
        return true;
    }
    bool operator !=(const DynamicArray & otherArray)
    {
        return !(*this == otherArray);
    }

    // Allocate new memory for new element
    // Copy old content to new inner array
    // insert element at the last index
    // update size
    void push_back(T param)
    {
        setSize(m_size + 1);
        m_array[m_size - 1] = param;
    }

    void pop_back()
    {
        if (m_size > 0)
        {
            m_size--;
        }
    }

    T bakc() const
    {
        if (m_size)
        {
            std::cout << "Out of range!" << std::endl;
        }
        return m_array[m_size - 1];
    }



private:
    T* m_array;
    std::size_t m_size;
    std::size_t m_capacity;

};
