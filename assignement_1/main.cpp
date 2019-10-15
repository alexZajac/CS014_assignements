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

string RemoveSpace(string polynomial)
{
    string newString = "";
    for (int position = 0; position < polynomial.size(); position++)
    {
        if(polynomial[position] != ' ') newString += polynomial[position];
    }
    return newString;
}

vector<string> Split(string polynomial,char splitChar)
{
    vector<string> splitVector;
    string splitString = "";
    for (int position = 0; position < polynomial.size(); position++)
    {
        if(polynomial[position] != ' '){
            if(polynomial[position] != splitChar) splitString += polynomial[position];
            else {
                splitVector.push_back(splitString);
                splitString = "";
            }
        }
    }
    return splitVector;
}


bool findNativeError(string polynomial,vector<char> exception)
{
    bool hasError = false;
    int position = 0;
    while(!hasError && position < polynomial.size()){
        int exceptionIndex = 0;
        while(!hasError && exceptionIndex < exception.size()) {
            hasError = polynomial[position] == exception[exceptionIndex];
            exceptionIndex++;
        }
        position++;
    }
    return hasError;
}

/**
 * * First exercise of the assignement
 */
void Exercise1()
{
    // cout << "Enter a polynomial: " << endl;
    string polynomial = "2*n + 4.54* n^5 +4 +5*n";
    // cin >> polynomial;e
    vector<string> plop = Split(polynomial,'+');
    for (size_t i = 0; i < plop.size(); i++)
    {
       cout << plop[i] << endl;
    }

    cout << findNativeError(polynomial,{'(',')','-'});
    
    cout << system("pause");
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