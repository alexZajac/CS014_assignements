#include <iostream>
#include <string>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

/**
 * * Function for exercise 1
 * Function for checking validity of a polynomial
 * TODO
 */
void checkPolynomial(string polynomial)
{
    return;
}

/**
 * * First exercise of the assignement
 */
void Exercise1()
{
    cout << "Enter a polynomial: " << endl;
    string polynomial;
    cin >> polynomial;
    checkPolynomial(polynomial);
}

/** 
 * * Prints the content of a vector<int>
 */
void PrintVector(vector<int> vec)
{
    for (const int i : vec)
    {
        cout << i << ", ";
    }
    cout << endl;
}

/**
 * * Function for exercise 2
 * Find a subset in input array that multiplies to given target
 * TODO
 */
vector<int> findMultiplyingSubset(vector<int> integers, int target)
{
    // Find divisibles
    vector<int> divisibles;
    for (const int v : integers)
    {
        if (target % v == 0)
            divisibles.push_back(v);
    }
    // Traverse them to find subset
    vector<int> result;
    int divisiblesSize = divisibles.size();
    int i = 0, j = 0;
    int copyTarget = target;
    while (i < divisiblesSize)
    {
        j = i;
        while (j < divisiblesSize)
        {
            int currentDiv = divisibles[j];
            if (target % currentDiv == 0)
            {
                target /= currentDiv;
                result.push_back(currentDiv);
            }
            if (target == 1)
                return result;
            ++j;
        }
        ++i;
        result.clear();
        target = copyTarget;
    }
    return result;
}

/**
 * * Second exercise of the assignement
 * ! Modify the inputs directly in the function
 */
void Exercise2()
{
    vector<int> integers = {2, 27, 18, 5, 7, 23, 9, 8, 2, 12, 10, 17, 5, 2, 7, 9, 8, 10, 4, 10, 8, 5, 4, 8, 9, 10, 7, 6, 5, 4, 1, 24, 5, 8, 9, 7, 2, 5, 11, 4, 2, 5, 2, 5, 2, 5, 25, 2, 5, 52};
    int target(2100);
    vector<int> result = findMultiplyingSubset(integers, target);
    if (result.size() == 0)
    {
        cout << "There is no subset of your input that multiplies to the given target." << endl;
    }
    else
    {
        cout << "The subset of your input that multiplies to " << target << " is :" << endl;
        PrintVector(result);
    }
}

int main()
{
    //Exercise1();
    Exercise2();
    cout << system("pause");
    return 0;
}