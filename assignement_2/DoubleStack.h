#ifndef DOUBLESTACK_H
#define DOUBLESTACK_H

template <typename T>
class DoubleStack
{
private:
    T* data;
    int firstTop;
    int secondTop;
    int size;
    int fristSize;
    int secondSize;
    void doubleLength();

public:
    DoubleStack();
    ~DoubleStack();

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

#endif