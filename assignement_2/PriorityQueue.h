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
    PriorityQueue *tenNext;

public:
    PriorityQueue(int data);
    ~PriorityQueue();
    // accessors
    const int GetData() const;
    const PriorityQueue* GetNext() const;
    // mutators
    void SetNext(PriorityQueue* newNode);
    // member methods
    void Enqueue(PriorityQueue* newNode);
    void Dequeue();
    void Display();
};