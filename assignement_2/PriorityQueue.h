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

public:
    PriorityQueue();
    ~PriorityQueue();
    // accessors
    const int getData() const;
    const PriorityQueue *getNext() const;
    // mutators
    void setData(int);
    void setNext(PriorityQueue *);
    // member methods
    void enqueue(PriorityQueue *);
    void dequeue();
};