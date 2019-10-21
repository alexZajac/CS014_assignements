
#include "HeapNode.h"
#include <iostream>

using namespace std;

template<typename T> 
HeapNode<T>::HeapNode(T value){
    this->value = value;
    this->parent = nullptr;
    this->leftChild = nullptr;
    this->rightChild = nullptr;
    this->previous = nullptr;
}

template<typename T> 
HeapNode<T>* HeapNode<T>::GetParent(){
    return this->parent;
}

template<typename T> 
bool HeapNode<T>::IsLeaf(){
    return this->leftChild == nullptr && this->rightChild == nullptr;
}

template<typename T> 
void HeapNode<T>::trickleDown(HeapNode* root){
    HeapNode* temp = root;
    if(temp->leftChild){
        if(temp->leftChild->value < temp->value){
            T valt = temp->value;
            temp->value = temp->leftChild->value;
            temp->leftChild->value = valt;
            this->trickleDown(temp->leftChild);
        }
    }
    if(temp->rightChild){
        if(temp->rightChild->value < temp->value){
            T valt = temp->value;
            temp->value = temp->rightChild->value;
            temp->rightChild->value = valt;
            this->trickleDown(temp->rightChild);
        }
    }
}

template<typename T> 
void HeapNode<T>::Insert(HeapNode* toInsert, HeapNode** root, HeapNode** last){

    //insert at the end
    if(*root == nullptr){
        *root = toInsert;
        *last = *root;
        return;
    }
    else if(*root == *last){
        (*root)->leftChild = toInsert;
        toInsert->parent = *root;
    }
    else if((*last)->parent->leftChild == *last){
        (*last)->parent->rightChild = toInsert;
        toInsert->parent = (*last)->parent;
    }
    else{
        if(!(*last)->parent->parent){
            HeapNode* temp = *root;
            while(temp->leftChild) temp = temp->leftChild;
            temp->leftChild = toInsert;
            toInsert->parent = temp;
        }
        else{
            if((*last)->parent->parent->leftChild == (*last)->parent){
                (*last)->parent->parent->rightChild->leftChild = toInsert;
                toInsert->parent = (*last)->parent->parent->rightChild;
            }
            else if((*last)->parent->parent->rightChild == (*last)->parent){
                HeapNode* temp = *last;
                while( temp->parent != *root && temp->parent->leftChild != temp) temp = temp->parent;
                if((*root)->rightChild == temp) temp = *root;
                else temp = temp->parent->rightChild;
                while(temp->leftChild) temp = temp->leftChild;
                temp->leftChild = toInsert;
                toInsert->parent = temp;
            }
        }
    }
    toInsert->previous = *last;
    *last = toInsert;

    //toogle up
    HeapNode* tup = *last;
    while(tup->parent != *root && tup->parent->value > tup->value){
          T temp = tup->value;
          tup->value = tup->parent->value;
          tup->parent->value = temp;
    }
    if(tup->parent == *root && (*root)->value > tup->value){
          T temp = tup->value;
          tup->value = (*root)->value;
          (*root)->value = temp;
    }
}

template<typename T> 
void HeapNode<T>::Remove(HeapNode** root, HeapNode** last){
    if(*root == nullptr) return;
    if(!(*root)->IsLeaf()){
        (*root)->value = (*last)->value;
        if((*last)->parent->leftChild == *last) (*last)->parent->leftChild = nullptr;
        else (*last)->parent->rightChild = nullptr;
        *last = (*last)->previous;
        this->trickleDown(*root);
    }
    else{
        *root = nullptr;
        *last = nullptr;
    }


}

template<typename T> 
HeapNode<T>::~HeapNode(){
    delete this->leftChild;
    delete this->rightChild;
}
