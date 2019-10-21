#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include "Sort.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

template <typename T>
void printArray(T* arr, int length){
  for (int i = 0 ; i < length; i++){
    cout << arr[i] << " ";
  }
  cout << endl;
}

void Exercise2(){
  
  double quickTime[6] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };
  measureQuick(quickTime);
  cout << "QuickSort: " << endl;
  printArray(quickTime, 6);
  
  double heapTime[6] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };
  measureHeap(heapTime);
  cout << "Heap Sort: " << endl;
  printArray(heapTime, 6);

  double mergeTime[6] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };
  measureMerge(mergeTime);
  cout << "Merge Sort: " << endl;
  printArray(mergeTime, 6);

  double insertTimes[6] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };
  measureInsertion(insertTimes);
  cout << "Insertion Sort: " << endl;
  printArray(insertTimes, 6);
}

void Exercise1(){
  // PointerHeap<int> *root = new PointerHeap<int>(0);
  // PointerHeap<int> *lastChild = root;
  // PointerHeap<int> *pth1 = new PointerHeap<int>(1);
  // root->Insert(lastChild,pth1,false,false);
  // lastChild = pth1;
  // PointerHeap<int> *pth2 = new PointerHeap<int>(2);
  // root->Insert(lastChild,pth2,false,false);
  // lastChild = pth2;
  // PointerHeap<int> *pth3 = new PointerHeap<int>(3);
  // root->Insert(lastChild,pth3,false,false);
  // lastChild = pth3;
  // PointerHeap<int> *pth4 = new PointerHeap<int>(4);
  // root->Insert(lastChild,pth4,false,false);
  // lastChild = pth4;
  // PointerHeap<int> *pth5 = new PointerHeap<int>(5);
  // root->Insert(lastChild,pth5,false,false);
  // lastChild = pth5;
}

int main()
{
  Exercise2();
  system("pause");
}