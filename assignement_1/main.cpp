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
 * Function for spliting polynomial and removing spaces
 */
vector<string> SplitStr(string polynomial, char splitChar)
{
    vector<string> splitVector;
    string splitString = "";
    for (int position = 0; (unsigned int)position < polynomial.size(); position++)
    {
        if (polynomial[position] != ' ')
        {
            if (polynomial[position] != splitChar)
                splitString += polynomial[position];
            else
            {
                splitVector.push_back(splitString);
                splitString = "";
            }
        }
    }
    splitVector.push_back(splitString);
    return splitVector;
}

/**
 * * Function for exercise 1
 * Function for checking invalid characters in polynomial
 */
bool findNativeError(string polynomial, vector<char> exception)
{
    bool hasError = false;
    int position = 0;
    while (!hasError && (unsigned int)position < polynomial.size())
    {
        int exceptionIndex = 0;
        while (!hasError && (unsigned int)exceptionIndex < exception.size())
        {
            hasError = polynomial[position] == exception[exceptionIndex];
            exceptionIndex++;
        }
        position++;
    }
    return hasError;
}

/**
 * * Function for exercise 1
 * Function for checking if a vector contains a value
 */
bool VectorContains(vector<int> vec, int searchedVal)
{
    for (int value : vec)
        if (value == searchedVal)
            return true;
    return false;
}

/**
 * * Function for exercise 1
 * Function for getting the maximum value of a vector
 */
int GetMaxVector(vector<int> vec)
{
    int max = vec[0];
    for (unsigned int i = 1; i < vec.size(); i++)
        if (vec[i] > max)
            max = vec[i];
    return max;
}

/**
 * * Function for exercise 1
 * Function checking if a member of the polynomial is valid and return his complexity
 */
int CheckMember(string member)
{

    int complexity = -1;
    int i = 0;
    int last = member.size() - 1;
    while (i <= last && ((member[i] >= '0' && member[i] <= '9') || member[i] == '.'))
        i++;
    if (i - 1 == last)
        complexity = 0;
    else
    {
        bool cont = false;
        if (member[i] == 'n')
        {
            if (i == 0)
                cont = true;
            else if (member[i - 1] == '*')
                cont = true;
        }
        else if (member[i] == '*' && i != last)
        {
            if (member[++i] == 'n')
                cont = true;
        }
        if (cont)
        {
            if (i == last)
                complexity = 1;
            else
            {
                if (member[++i] == '^')
                {
                    string lastDigits = "";
                    i++;
                    while (i <= last && (member[i] >= '0' && member[i] <= '9'))
                        lastDigits += member[i++];
                    if (i == last + 1)
                        complexity = stoi(lastDigits);
                }
            }
        }
    }
    return complexity;
}

/**
 * * Function for exercise 1
 * Function for checking validity of a polynomial
 */
void checkPolynomial(string polynomial)
{
    cout << "Testing for " << polynomial << endl;
    if (findNativeError(polynomial, {'(', ')', '-'}))
    {
        cout << "Invalid polynomial expression" << endl;
        return;
    }
    vector<string> members = SplitStr(polynomial, '+');
    vector<int> degres;

    for (string member : members)
    {
        int degre = CheckMember(member);
        if (degre == -1 || VectorContains(degres, degre))
        {
            cout << "Invalid polynomial expression.\n"
                 << endl;
            return;
        }
        else
            degres.push_back(degre);
    }
    int complexity = GetMaxVector(degres);
    cout << "Polynomial is valid, and it's complexity is O(n^" << complexity << ").\n"
         << endl;

    return;
}

/**
 * * First exercise of the assignement
 */
void Exercise1()
{
    char polynomial[100];
    cout << "Enter a polynomial : " << endl;
    cin.getline(polynomial, sizeof(polynomial));

    checkPolynomial(polynomial);
}

/** 
 * * Helper function that prints the content of a vector<T>
 */
template <typename T>
void PrintVector(vector<T> vec)
{
    for (const T elm : vec)
    {
        cout << elm << " ";
    }
    cout << endl;
}

/**
 * * Function for exercise 2
 * Find a subset in input array that multiplies to given target
 */
vector<int> findMultiplyingSubset(vector<int> integers, int target)
{
    // Find divisibles of target
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
            // we have to check here for further loops iterations with target being modified hereunder
            if (target % currentDiv == 0)
            {
                target /= currentDiv;
                result.push_back(currentDiv);
            }
            // if target is 1 then we found a subset
            if (target == 1)
                return result;
            ++j;
        }
        // reseting variables
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
    cout << "EXERCISE 1: \n"
         << endl;
    Exercise1();
    cout << "EXERCISE 2: \n"
         << endl;
    Exercise2();
    cout << system("pause");
    return 0;
}