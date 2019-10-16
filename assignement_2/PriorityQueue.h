#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

class PriorityQueue
{
private:
    int data;
    PriorityQueue *next;
    PriorityQueue *tenthNext;

public:
    PriorityQueue(int data);
    ~PriorityQueue();
    // accessors
    const int GetData() const;
    const PriorityQueue *GetNext() const;
    const PriorityQueue *GetTenthNext() const;
    // mutators
    void SetNext(PriorityQueue *newNode);
    // member methods
    void Enqueue(PriorityQueue *newNode);
    void Dequeue();
    const PriorityQueue *Peek() const;
    void Display();
};