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
double* measureInsertion();
int* mergeSort(int *, int);
double* measureMerge();
int* split(int*, int, int);
void swap(int*, int*);
int partition(int*, int, int);
void quickSort(int *, int, int);
double* measureQuick();
void trickleDown(int*, int, int);
void buildHeap(int*, int);
void heapSort(int *, int);
double* measureHeap();
int* generateRandomArray(int);