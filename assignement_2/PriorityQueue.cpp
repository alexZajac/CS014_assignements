#include <iostream>
#include <string>
#include <vector>
#include "PriorityQueue.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

PriorityQueue::PriorityQueue(int data){
    this->data = data;
    this->next = nullptr;
    this->tenNext = nullptr;
}


PriorityQueue::~PriorityQueue(){
    delete next;
    delete tenNext;
    next = nullptr;
}

void PriorityQueue::SetNext(PriorityQueue* newNode){
    newNode->next = this->next;
    this->next = newNode;
}

void PriorityQueue::Enqueue(PriorityQueue* newNode){
    PriorityQueue *tempNode = this;
    PriorityQueue *tempTenNode = this;
    int count = 0;
    while (tempNode->next != nullptr && tempNode->next->data<newNode->data)
    {
        if(tempNode->tenNext != nullptr && tempNode->tenNext->data<newNode->data){ 
            if(count>=10) tempTenNode = tempTenNode->tenNext; 
            else tempTenNode = tempTenNode->next;
            tempNode = tempNode->tenNext; 
            count +=10;
        }
        else{
            if(count>=10) tempTenNode = tempTenNode->next;
            tempNode = tempNode->next;  
            count +=1;
        } 
    }
    tempNode->SetNext(newNode);
    while(tempNode->next != nullptr){
        if(count>=10) {
            tempTenNode->tenNext = tempNode->next;
            tempTenNode = tempTenNode->next;
        }

        tempNode = tempNode->next; 
        count++;
    }
}

void PriorityQueue::Dequeue(){
    if(this->next != nullptr){
        PriorityQueue *tempToDelete = this->next;
        this->next = this->next->next;
        tempToDelete->next = nullptr;
        tempToDelete->tenNext = nullptr;
        delete tempToDelete;
    }
    else
    {
        cout << "Empty List" << endl;
    }
    
}

void PriorityQueue::Display(){
    if(this->next != nullptr){
        PriorityQueue *temp = this->next;
        while(temp != nullptr){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    else
    {
        cout << "Empty List" << endl;
    }
    
}
