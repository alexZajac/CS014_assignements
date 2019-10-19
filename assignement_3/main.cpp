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

int main()
{
  Exercise2();
  system("pause");
}