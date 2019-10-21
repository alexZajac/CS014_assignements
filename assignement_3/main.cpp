#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include "Sort.h"
#include "PointerHeap.cpp"
#include "IntCell.h"

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
  double* insertionTime = measureInsertion();
  cout << "Insertion Sort: " << endl;
  printArray(insertionTime, 6);
  double* mergeTime = measureMerge();
  cout << "Merge Sort: " << endl;
  printArray(mergeTime, 6);
  double* quickTime = measureQuick();
  cout << "QuickSort: " << endl;
  printArray(quickTime, 6);
  double* heapTime = measureHeap();
  cout << "Heap Sort: " << endl;
  printArray(heapTime, 6);
}

void Exercise1(){
  PointerHeap<IntCell>* heap = new PointerHeap<IntCell>();
  heap->Insert(*new IntCell(0));
  heap->Insert(*new IntCell(1));
  heap->Insert(*new IntCell(2));
  heap->Insert(*new IntCell(3));
  heap->Insert(*new IntCell(4));
  heap->Insert(*new IntCell(11));
  heap->Insert(*new IntCell(12));
  heap->Insert(*new IntCell(13));
  heap->Insert(*new IntCell(14));
  heap->Insert(*new IntCell(15));
  heap->Insert(*new IntCell(5));
  heap->Insert(*new IntCell(6));
  heap->Insert(*new IntCell(7));
  heap->Insert(*new IntCell(8));
  heap->Insert(*new IntCell(9));
  heap->Insert(*new IntCell(10));

  heap->Remove();
}

int main()
{
  Exercise1();
  system("pause");
}