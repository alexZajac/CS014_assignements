#ifndef DOUBLESTACK_H
#define DOUBLESTACK_H

#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

template <typename T>
class DoubleStack
{
private:
    T *data;
    int firstTop;
    int secondTop;
    int size;
    int firstSize;
    int secondSize;
    void doubleLength();

public:
    DoubleStack();
    ~DoubleStack();
    // accessors
    int GetSize() const;
    int GetFirstSize() const;
    int GetSecondSize() const;
    const T *GetData() const;

    // member methods
    void pushFirst(T);
    void pushSecond(T);
    void popFirst();
    void popSecond();
    // optionnal
    const T peekFirst() const;
    const T peekSecond() const;
    const bool emptyFirst() const;
    const bool emptySecond() const;

    const void print() const;
};

template <typename T>
DoubleStack<T>::DoubleStack()
{
    this->size = 0;
    this->firstTop = -1;
    this->secondTop = -1;
    this->firstSize = 0;
    this->secondSize = 0;
    this->data = new T[0];
}

template <typename T>
DoubleStack<T>::~DoubleStack()
{
    delete[] this->data;
}

template <typename T>
int DoubleStack<T>::GetSize() const
{
    return this->size;
}

template <typename T>
const T *DoubleStack<T>::GetData() const
{
    return this->data;
}

template <typename T>
int DoubleStack<T>::GetFirstSize() const
{
    return this->firstSize;
}

template <typename T>
int DoubleStack<T>::GetSecondSize() const
{
    return this->secondSize;
}

template <typename T>
void DoubleStack<T>::doubleLength()
{
    int newSize = (this->size) * 2;
    T *newArray = new T[newSize];
    this->secondTop = newSize - this->secondSize - 1;

    for (int i = 0; i < newSize; i++)
    {
        if (i < this->firstTop)
            newArray[i] = this->data[i];
        else if (i > this->secondTop)
            newArray[i] = this->data[i - this->size];
        else
            newArray[i] = T();
    }
    this->size = newSize;
    this->data = newArray;
}

// member methods
template <typename T>
void DoubleStack<T>::pushFirst(T value)
{

    if (this->size == 0)
    {
        T *newData = new T[3];
        newData[0] = value;
        newData[1] = T();
        newData[2] = T();
        this->data = newData;
        this->firstTop = 1;
        this->secondTop = 2;
        this->size = 3;
    }
    else
    {
        if (this->firstSize + this->secondSize + 2 == this->size)
            this->doubleLength();
        int ind = this->firstTop;
        this->data[ind] = value;
        this->firstTop++;
    }
    this->firstSize++;
}

template <typename T>
void DoubleStack<T>::pushSecond(T value)
{
    if (this->size == 0)
    {
        T *newData = new T[3];
        newData[2] = value;
        newData[1] = T();
        newData[0] = T();
        this->data = newData;
        this->secondTop = 1;
        this->firstTop = 0;
        this->size = 3;
    }
    else
    {
        if (this->firstSize + this->secondSize + 2 == this->size)
            this->doubleLength();
        this->data[this->secondTop] = value;
        this->secondTop--;
    }
    this->secondSize++;
}

template <typename T>
void DoubleStack<T>::popFirst()
{
    if (this->firstSize > 0)
    {
        this->firstSize--;
        this->firstTop--;
    }
}

template <typename T>
void DoubleStack<T>::popSecond()
{
    if (this->secondSize > 0)
    {
        this->secondSize--;
        this->secondTop++;
    }
}

template <typename T>
const void DoubleStack<T>::print() const
{
    for (int i = 0; i < this->size; i++)
        if (i < this->firstTop || i > this->secondTop)
            cout << this->data[i];
        else
            cout << "0";
    cout << endl;
}

template <typename T>
const T DoubleStack<T>::peekFirst() const
{
    if (!this->emptyFirst())
        return this->data[this->firstTop - 1];
    else
        return T();
}

template <typename T>
const T DoubleStack<T>::peekSecond() const
{
    if (!this->emptySecond())
        return this->data[this->secondTop + 1];
    else
        return T();
}

template <typename T>
const bool DoubleStack<T>::emptyFirst() const
{
    return this->firstSize == 0;
}

template <typename T>
const bool DoubleStack<T>::emptySecond() const
{
    return this->secondSize == 0;
}
#endif
