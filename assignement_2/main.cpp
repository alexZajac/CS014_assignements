#include <iostream>
#include <string>
#include <vector>
#include "DoubleStack.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
  DoubleStack<int> dStack;
  dStack.pushFirst(2);
  dStack.pushFirst(4);
  dStack.pushSecond(7);
  const int *toTest = dStack.GetData();
  int arrayCompare[6] = {4, 2, 0, 0, 0, 7};
  int *toCompare = arrayCompare;
  system("pause");
  return 0;
}