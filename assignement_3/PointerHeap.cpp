
#include "HeapNode.cpp"
#include "PointerHeap.h"
#include <iostream>

using namespace std;

template<typename T> 
PointerHeap<T>::PointerHeap(){
    this->root = nullptr;
    this->last = nullptr;
}

template<typename T> 
PointerHeap<T>::~PointerHeap(){
    //TODO
}

template<typename T> 
void PointerHeap<T>::Insert(T data){
    HeapNode<T>* node = new HeapNode<T>(data);
    this->root->Insert(node, &this->root,&this->last);
}

template<typename T> 
void PointerHeap<T>::Remove(){
    this->root->Remove(&this->root,&this->last);
}

