#include "DoubleStack.h"
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;


template <typename T>
DoubleStack<T>::DoubleStack(){
    this->size = 0;
    this->firstTop = -1;
    this->secondTop = -1;
    this->fristSize = 0;
    this->secondSize = 0;
}

template <typename T>
DoubleStack<T>::~DoubleStack(){
    delete this->data;
}

template <typename T>
void DoubleStack<T>::doubleLength(){
    int newSize = (this->size)*2;
    T* newArray = new T[newSize];
    this->secondTop = newSize - this->secondSize -1;

    for(int i = 0; i < newSize; i++){
        if(i < this->firstTop) newArray[i] = this->data[i];
        else if(i > this->secondTop) newArray[i] = this->data[i-this->size];
    }
    this->size = newSize;
    this->data = newArray;
}

// member methods
template <typename T>
void DoubleStack<T>::pushFirst(T value){

    if(this->size == 0){
        T* newData = new T[3];
        newData[0] = value;
        this->data = newData;
        this->firstTop = 1;
        this->secondTop = 2;
        this->size = 3;
    }
    else{
        if(this->fristSize + this->secondSize + 2 == this->size) this->doubleLength();
        int ind = this->firstTop;
        this->data[ind] = value;
        this->firstTop++;
    }
    this->fristSize++;
}

template <typename T>
void DoubleStack<T>::pushSecond(T value){
    if(this->size == 0){
        T* newData = new T[3];
        newData[2] = value;
        this->data = newData;
        this->secondTop = 1;
        this->firstTop = 0;
        this->size = 3;
    }
    else{
        if(this->fristSize + this->secondSize + 2 == this->size) this->doubleLength();
        this->data[this->secondTop] = value;
        this->secondTop--;
    }
    this->secondSize++;
}

template <typename T>
void DoubleStack<T>::popFirst(){
    if(this->fristSize > 0){
        this->fristSize--;
        this->firstTop--;
    }
}

template <typename T>
void DoubleStack<T>::popSecond(){
        if(this->secondSize > 0){
        this->secondSize--;
        this->secondTop++;
    }
}

template <typename T>
const void DoubleStack<T>::print() const {
    for(int i = 0; i < this->size ; i++)
        if(i<this->firstTop || i>this->secondTop) cout << this->data[i];
        else cout << "0";
    cout << endl;
}

template <typename T>
const T DoubleStack<T>::peekFirst() const{
    return this->data[this->firstTop-1];
}

template <typename T>
const T DoubleStack<T>::peekSecond() const{
    return this->data[this->secondTop+1];
}

template <typename T>
const bool DoubleStack<T>::emptyFirst() const{
    return this->firstSize == 0;
}

template <typename T>
const bool DoubleStack<T>::emptySecond() const{
    return this->secondSize == 0;
}
