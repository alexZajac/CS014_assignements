#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

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
 * * Function for exercise 2
 * Find a subset in input array that multiplies to given target
 * TODO
 */
void findMultiplyingSubset(int integers[], int target)
{
    return;
}
/**
 * * Second exercise of the assignement
 */
void Exercise2()
{
    int integers[] = {1, 4, 5, 3, 6};
    int target(90);
    findMultiplyingSubset(integers, target);
}

int main()
{
    Exercise1();
    Exercise2();
    return 0;
}