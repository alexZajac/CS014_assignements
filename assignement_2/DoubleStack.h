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
    T data[];
    int size;

public:
    DoubleStack();
    ~DoubleStack();
    // member methods
    void pushFirst(T);
    void pushSecond(T);
    void popFirst();
    void popSecond();
    const T peekFirst() const;
    const T peekSecond() const;
    const bool emptyFirst() const;
    const bool emptySecond() const;
};