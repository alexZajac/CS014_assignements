#include <iostream>
#include <string>
#include <vector>
#include <chrono>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

void insertionSort(int *, int);
void measureInsertion(double*);
int* mergeSort(int *, int);
void measureMerge(double* );
int* split(int*, int, int);
void swap(int*, int*);
int partition(int*, int, int);
void quickSort(int *, int, int);
void measureQuick(double*);
void trickleDown(int*, int, int);
void buildHeap(int*, int);
void heapSort(int *, int);
void measureHeap(double* );
int* generateRandomArray(int);