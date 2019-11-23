#include <iostream>
#include <string>
#include <vector>
#include "PriorityQueue.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

/**
 * * Constructor
 * @param: integer initializing the node
 */
PriorityQueue::PriorityQueue(int data)
{
    this->data = data;
    this->next = nullptr;
    this->tenthNext = nullptr;
}

/**
 * *Deconstructor
 */
PriorityQueue::~PriorityQueue()
{
    delete next;
    delete tenthNext;
    next = nullptr;
    tenthNext = nullptr;
}

/**
 * * Mutuator
 * @param: PriorityQueue pointer, the next node to set
 */
void PriorityQueue::SetNext(PriorityQueue *newNode)
{
    newNode->next = this->next;
    this->next = newNode;
}

/**
 * * Public member
 * @param: PriorityQueue pointer, the node to enqueue
 */
void PriorityQueue::Enqueue(PriorityQueue *newNode)
{
    // keeping two references for processing
    PriorityQueue *tempNode = this;
    PriorityQueue *temp10 = this;
    int count = 0;
    // while the node has a lower priority
    while (tempNode->next && tempNode->next->data < newNode->data)
    {
        // if we can jump 10 nodes
        if (tempNode->tenthNext && tempNode->tenthNext->data < newNode->data)
        {
            // if we know we already have more than ten nodes, the temp10 jumps also by 10 nodes
            if (count >= 10)
                temp10 = temp10->tenthNext;
            else
                temp10 = temp10->next;
            tempNode = tempNode->tenthNext;
            count += 10;
        }
        else
        {
            if (count >= 10)
                temp10 = temp10->next;
            tempNode = tempNode->next;
            count += 1;
        }
    }
    // enqueing newNode
    tempNode->SetNext(newNode);
    // resetting tenthNode pointers
    while (tempNode->next)
    {
        if (count >= 10)
        {
            temp10->next->tenthNext = tempNode->next;
            temp10 = temp10->next;
        }

        tempNode = tempNode->next;
        count++;
    }
}

/**
 * * Public member
 */
void PriorityQueue::Dequeue()
{
    if (this->next)
    {
        PriorityQueue *tempToDelete = this->next;
        this->next = this->next->next;
        tempToDelete->next = nullptr;
        tempToDelete->tenthNext = nullptr;
        delete tempToDelete;
    }
    else
    {
        cout << "List is empty." << endl;
    }
}

/**
 * * Accessor
 */
const int PriorityQueue::GetData() const
{
    return this->data;
}

/**
 * * Accessor
 */
const PriorityQueue *PriorityQueue::GetNext() const
{
    return this->next;
}

/**
 * * Accessor
 */
const PriorityQueue *PriorityQueue::GetTenthNext() const
{
    return this->tenthNext;
}

/**
 * * Public member
 */
void PriorityQueue::Display()
{
    if (this->next)
    {
        PriorityQueue *temp = this->next;
        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    else
    {
        cout << "List is empty." << endl;
    }
}
