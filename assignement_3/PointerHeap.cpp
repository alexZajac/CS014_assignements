
#include "PointerHeap.h"
#include <iostream>

using namespace std;

template<typename T> 
PointerHeap<T>::PointerHeap(T value){
    this->value = value;
    this->parent = nullptr;
    this->leftChild = nullptr;
    this->rightChild = nullptr;
}

template<typename T> 
PointerHeap<T>* PointerHeap<T>::GetParent(){
    return this->parent;
}

template<typename T> 
bool PointerHeap<T>::IsLeaf(PointerHeap* actualNode){
    return actualNode->leftChild == nullptr && actualNode->rightChild == nullptr;
}

template<typename T> 
void PointerHeap<T>::trickleDown(PointerHeap* actualNode, PointerHeap* nodeToAdd){
    if(!IsLeaf(actualNode->leftChild)) trickleDown(actualNode->leftChild,nodeToAdd);
    else if(!IsLeaf(actualNode->rightChild)) trickleDown(actualNode->rightChild,nodeToAdd);
    else actualNode->leftChild = nodeToAdd;
}

template<typename T> 
void PointerHeap<T>::Insert(PointerHeap* actualNode, PointerHeap* nodeToAdd, bool comeFromLeft,bool plop){
    PointerHeap<T>* actualNodeParent = actualNode->parent;
    // if(actualNodeParent == nullptr) asReachRoot = true;
    // if(asReachRoot && actualNodeParent->leftChild != nullptr){
    //     Insert(actualNodeParent->leftChild,nodeToAdd,true);
    // }
    else if(actualNodeParent->leftChild == nullptr){
        actualNodeParent->leftChild = nodeToAdd;
        nodeToAdd->parent = actualNodeParent;
    }
    else if(actualNodeParent->rightChild == nullptr){
        actualNodeParent->rightChild = nodeToAdd;
        nodeToAdd->parent = actualNodeParent;
    }
    else{
        if(actualNodeParent->parent->left==actualNodeParent) Insert(actualNodeParent->parent->right,nodeToAdd);
        if(actualNodeParent->parent != nullptr) Insert(actualNodeParent->parent,nodeToAdd,false);
        else Insert(actualNodeParent->leftChild,nodeToAdd,true);
    }
}

// template<typename T> 
// void PointerHeap<T>::Insert(PointerHeap* actualNode, PointerHeap* nodeToAdd, bool asReachRoot,bool goToRight){
//     PointerHeap<T>* actualNodeParent = actualNode->parent;
//     if(actualNodeParent == nullptr || asReachRoot || goToRight) actualNodeParent = actualNode;
//     if(goToRight) Insert(actualNodeParent->rightChild,nodeToAdd,false,false);
//     if(asReachRoot && actualNodeParent->leftChild != nullptr){
//         Insert(actualNodeParent->leftChild,nodeToAdd,true,false);
//     }
//     else if(actualNodeParent->leftChild == nullptr){
//         actualNodeParent->leftChild = nodeToAdd;
//         nodeToAdd->parent = actualNodeParent;
//     }
//     else if(actualNodeParent->rightChild == nullptr){
//         actualNodeParent->rightChild = nodeToAdd;
//         nodeToAdd->parent = actualNodeParent;
//     }
//     else{
//         if(actualNodeParent->parent != nullptr) Insert(actualNodeParent->parent,nodeToAdd,false,actualNodeParent->parent->leftChild==actualNodeParent);
//         else Insert(actualNodeParent->leftChild,nodeToAdd,true,false);
//     }
// }

template<typename T> 
PointerHeap<T>::~PointerHeap(){
    delete this->leftChild;
    delete this->rightChild;
}
