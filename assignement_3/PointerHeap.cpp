
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
    delete this->root;
    delete this->last;
}

template<typename T> 
HeapNode<T>* PointerHeap<T>::GetRoot(){
    return this->root;
}

template<typename T> 
HeapNode<T>* PointerHeap<T>::GetLast(){
    return this->last;
}

template<typename T> 
void PointerHeap<T>::Insert(T data){
    HeapNode<T>* node = new HeapNode<T>(data);
    this->root->Insert(node, &this->root,&this->last);
}

template<typename T> 
void PointerHeap<T>::DeleteMin(){
    this->root->DeleteMin(&this->root,&this->last);
}

