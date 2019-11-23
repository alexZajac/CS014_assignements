#include "MyTree.h"
#include <time.h>
#include <chrono>

using std::chrono::high_resolution_clock;

void InsertRandomArray(MyTree *t, int startSize){
  int index = 0;
  while(index <= startSize){
    int value = (rand()*rand())%1000000;
    t->insert(value,  std::to_string(value));
    index++;
  }
}

void PerformanceMeasure(){
  int startSize = 100;
  while(startSize <= 100000){
    MyTree *t = new MyTree();
    auto start = high_resolution_clock::now();
    InsertRandomArray(t,startSize);
    auto build = high_resolution_clock::now();
    t->preorder();
    cout << endl;
    auto preorder = high_resolution_clock::now();
    BinaryNode* b = t->findMax();
    auto findMax = high_resolution_clock::now();
    t->makeBST();
    auto makeBST = high_resolution_clock::now();
    std::chrono::duration<double> elapsedBuild = build - start;
    std::chrono::duration<double> elapsedPreorder = preorder - build;
    std::chrono::duration<double> elapsedFindMax = findMax - preorder;
    std::chrono::duration<double> elapsedMakeBST = makeBST - findMax;
    cout << "For " << startSize << " values, build : " << elapsedBuild.count();
    cout <<  ", preoder : " << elapsedPreorder.count() << ", finding the max : " << elapsedFindMax.count();
    cout << ", make BST : " << elapsedMakeBST.count() << endl;
    startSize *= 10;
  }
}

main() {
  srand(time(0));
  PerformanceMeasure();
  system("pause");
}
