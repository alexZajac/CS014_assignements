#include <iostream>
#include <string>
#include <vector>
#include "PriorityQueue.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
  PriorityQueue *dummyHead = new PriorityQueue(-1);
  PriorityQueue *newNode1 = new PriorityQueue(1);
  dummyHead->Enqueue(newNode1);
  PriorityQueue *newNode2 = new PriorityQueue(2);
  dummyHead->Enqueue(newNode2);
  PriorityQueue *newNode3 = new PriorityQueue(1);
  dummyHead->Enqueue(newNode3);
  PriorityQueue *newNode4 = new PriorityQueue(4);
  dummyHead->Enqueue(newNode4);
  PriorityQueue *newNode5 = new PriorityQueue(5);
  dummyHead->Enqueue(newNode5);
  PriorityQueue *newNode6 = new PriorityQueue(6);
  dummyHead->Enqueue(newNode6);
  PriorityQueue *newNode7 = new PriorityQueue(7);
  dummyHead->Enqueue(newNode7);
  PriorityQueue *newNode8 = new PriorityQueue(8);
  dummyHead->Enqueue(newNode8);
  PriorityQueue *newNode9 = new PriorityQueue(9);
  dummyHead->Enqueue(newNode9);
  PriorityQueue *newNode10 = new PriorityQueue(10);
  dummyHead->Enqueue(newNode10);
  PriorityQueue *newNode11 = new PriorityQueue(11);
  dummyHead->Enqueue(newNode11);
  PriorityQueue *newNode12 = new PriorityQueue(12);
  dummyHead->Enqueue(newNode12);
  PriorityQueue *newNode13 = new PriorityQueue(4);
  dummyHead->Enqueue(newNode13);
  dummyHead->Display();
  system("pause");
  return 0;
}