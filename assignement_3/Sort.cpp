#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include <chrono>
#include "Sort.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::chrono::high_resolution_clock;

int* generateRandomArray(int size){
    int* arr = new int[size];
    srand(time(0));
    for (int i = 0; i < size; i++){
        arr[i] = rand() % size;
    }
    return arr;
}

void insertionSort(int* arr, int length){
    for (int i = 1; i < length; i++){
        int currentVal = arr[i];
        int j = i-1;
        while (j >= 0 && arr[j] > currentVal){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = currentVal;
    }
}

void measureInsertion(double* execTimes){
    int i = 0;
    while (i < 1){
        int startSize = 10;
        int pow = 1;
        while(startSize <= 1000000){
            int* arr = generateRandomArray(startSize);
            auto start = high_resolution_clock::now();
            insertionSort(arr, startSize);
            auto end = high_resolution_clock::now();
            std::chrono::duration<double> elapsed = end - start;
            cout << elapsed.count() << endl;
            execTimes[pow-1] += elapsed.count();
            startSize *= 10;
            pow++;
        }
        i++;
    }
    for (int j = 0; j < 6; j++){
        execTimes[j] /= 30;
    }
}


int* split(int* arr, int start, int end){
    int size = end-start+1;
    int* res = new int[size];
    int i = 0;
    int j = start;
    while(j <= end){
        res[i] = arr[j];
        i++;
        j++;
    }
    return res;
}

int* merge(int* left, int lSize, int* right, int rSize){
    int* res = new int[lSize + rSize];
    int li = 0, ri = 0, i = 0;
    while(li < lSize && ri < rSize){
        if (left[li] < right[ri]){
            res[i] = left[li];
            li++;
        }
        else{
            res[i] = right[ri];
            ri++;
        }
        i++;
    }
    while(li < lSize){
        res[i] = left[li];
        li++;
        i++;
    }
    while(ri < rSize){
        res[i] = right[ri];
        ri++;
        i++;
    }
    delete[] left;
    delete[] right;
    return res;
    
}

int* mergeSort(int* arr, int length){
    if (length <= 1)
        return arr;
    int mid = length / 2;
    int* leftPart = mergeSort(split(arr, 0, mid-1), mid);
    int* rightPart = mergeSort(split(arr, mid, length-1), length-mid);
    delete[] arr;
    return merge(leftPart, mid, rightPart, length-mid);
}


void measureMerge(double* execTimes){
    int i = 0;
    while (i < 30){
        int startSize = 10;
        int pow = 1;
        while(startSize <= 1000000){
            int* arr = generateRandomArray(startSize);
            auto start = high_resolution_clock::now();
            arr = mergeSort(arr, startSize);
            delete[] arr;
            auto end = high_resolution_clock::now();
            std::chrono::duration<double> elapsed = end - start;
            execTimes[pow-1] += elapsed.count();
            startSize *= 10;
            pow++;
        }
        i++;
    }
    for (int j = 0; j < 6; j++){
        execTimes[j] /= 30;
    }
}

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int* arr, int lo, int hi){
    // picking pviot as high
    int pivot = arr[hi];
    int i = lo, j = lo;
    while(j < hi){
        // keeping all values inferior to pivot at its left
        if (arr[j] < pivot){
            swap(&arr[i], &arr[j]);
            ++i;
        }
        ++j;
    }
    // resetting pivot and returning index
    swap(&arr[i], &arr[hi]);
    return i;
}

void quickSort(int* arr, int lo, int hi){
    if (lo < hi){
        int partitionIndex = partition(arr, lo, hi);
        quickSort(arr, lo, partitionIndex-1);
        quickSort(arr, partitionIndex+1, hi);
    }
}


void measureQuick(double* execTimes){
    int i = 0;
    while (i < 30){
        int startSize = 10;
        int pow = 1;
        while(startSize <= 1000000){
            int* arr = generateRandomArray(startSize);
            auto start = high_resolution_clock::now();
            quickSort(arr, 0, startSize-1);
            auto end = high_resolution_clock::now();
            std::chrono::duration<double> elapsed = end - start;
            execTimes[pow-1] += elapsed.count();
            startSize *= 10;
            pow++;
        }
        i++;
    }
    for (int j = 0; j < 6; j++){
        execTimes[j] /= 30;
    }  
}

void trickleDown(int* arr, int start, int end){
    int root = start;
    // while root has at least one child
    while ((2*root + 1) < end){
        int child = 2*root + 1;
        int toSwap = root;
        // if left child is greater
        if (arr[toSwap] < arr[child])
            toSwap = child;
        // if right child exist and is greater
        if (child+1 < end && arr[toSwap] < arr[child+1]){
            toSwap = child+1;
        }
        // swapping if it's a child, and tricling down
        if (toSwap != root){
            swap(&arr[root], &arr[toSwap]);
            root = toSwap;
        }
        else
            break;
    }
}

void buildHeap(int* arr, int length){
    // start with parent
    int start = (length-1) / 2;
    while (start >= 0){
        trickleDown(arr, start, length);
        start--;
    }
}

void heapSort(int* arr, int length){
    buildHeap(arr, length);
    int end = length;
    while (end > 1){
        swap(&arr[0], &arr[end-1]);
        --end;
        trickleDown(arr, 0, end);
    }
}


void measureHeap(double* execTimes){
    int i = 0;
    while (i < 30){
        int startSize = 10;
        int pow = 1;
        while(startSize <= 1000000){
            int* arr = generateRandomArray(startSize);
            auto start = high_resolution_clock::now();
            heapSort(arr, startSize);
            auto end = high_resolution_clock::now();
            std::chrono::duration<double> elapsed = end - start;
            execTimes[pow-1] += elapsed.count();
            startSize *= 10;
            pow++;
        }
        i++;
    }
    for (int j = 0; j < 6; j++){
        execTimes[j] /= 30;
    }
}