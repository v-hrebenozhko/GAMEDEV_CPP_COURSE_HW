#include "DynamicIntArray.h"

//Implementations go here

DynamicIntArray::DynamicIntArray() : m_array(nullptr), m_size(0) {}

DynamicIntArray::DynamicIntArray(std::size_t size) : m_size(size) 
{
    m_array = new int[size];
}

DynamicIntArray::DynamicIntArray(const DynamicIntArray& otherArray) : m_size(otherArray.m_size) 
{
    m_array = new int[m_size];
    std::copy(otherArray.m_array, otherArray.m_array + m_size, m_array);
}

DynamicIntArray::~DynamicIntArray() {
    delete[] m_array;
}

DynamicIntArray& DynamicIntArray::operator=(const DynamicIntArray& otherArray) 
{
    if (this != &otherArray) {
        delete[] m_array;
        m_size = otherArray.m_size;
        m_array = new int[m_size];
        std::copy(otherArray.m_array, otherArray.m_array + m_size, m_array);
    }
    return *this;
}

int& DynamicIntArray::operator[](std::size_t idx) 
{
    if (idx >= m_size) {
        std::cout << "Out of range!" << std::endl;
    }
    return m_array[idx];
}

void DynamicIntArray::setSize(std::size_t newSize) 
{
    if (newSize != m_size)
    {
        int* newArray = new int[newSize];
        std::size_t paramsToCopy = (m_size < newSize) ? m_size : newSize;
            std::copy(m_array, m_array + paramsToCopy, newArray);
        delete[] m_array;
        m_array = newArray;
        m_size = newSize;
    }
}

std::size_t DynamicIntArray::getSize() const 
{
    return m_size;
}

void DynamicIntArray::clear() {
    delete[] m_array;
    m_array = nullptr;
    m_size = 0;
}

bool DynamicIntArray::operator==(const DynamicIntArray& otherArray) 
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

bool DynamicIntArray::operator!=(const DynamicIntArray& otherArray) 
{
    return !(*this == otherArray);
}

void DynamicIntArray::push_back(int param) 
{
    setSize(m_size + 1);
    m_array[m_size - 1] = param;
}