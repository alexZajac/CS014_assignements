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
vector<string> SplitStr(string polynomial,char splitChar)
{
    vector<string> splitVector;
    string splitString = "";
    for (int position = 0; (unsigned int) position < polynomial.size(); position++)
    {
        if(polynomial[position] != ' '){
            if(polynomial[position] != splitChar) splitString += polynomial[position];
            else {
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
bool findNativeError(string polynomial,vector<char> exception)
{
    bool hasError = false;
    int position = 0;
    while(!hasError && (unsigned int) position < polynomial.size()){
        int exceptionIndex = 0;
        while(!hasError && (unsigned int) exceptionIndex < exception.size()) {
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
bool VectorContains(vector<int> vec, int searchedVal){
    for(int value : vec)
        if(value == searchedVal)
            return true;
    return false;
}

/**
 * * Function for exercise 1
 * Function for getting the maximum value of a vector
 */
int GetMaxVector(vector<int> vec){
    int max = vec[0];
    for(unsigned int i = 1; i< vec.size(); i++)
        if(vec[i]>max)
            max = vec[i];
    return max;
}

/**
 * * Function for exercise 1
 * Function checking if a member of the polynomial is valid and return his complexity
 */
int CheckMember(string member){

    int complexity = -1;
    int i = 0;
    int last = member.size()-1;
    while(i <= last && (( member[i] >= '0' && member[i] <='9') || member[i] == '.'))i++;
    if (i-1 == last) complexity = 0;
    else{
        bool cont = false;
        if(member[i] == 'n'){
            if(i == 0) cont = true;
            else if(member[i-1] == '*') cont = true;
        }
        else if(member[i] == '*' && i != last){
            if(member[++i] == 'n') cont = true;
        }
        if(cont){
            if(i == last) complexity = 1;
            else{
                if(member[++i] == '^'){
                    string lastDigits = "";
                    i++;
                    while(i <= last && (member[i] >= '0' && member[i] <='9')) lastDigits+=member[i++];
                    if(i == last+1) complexity = stoi(lastDigits);
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
    if(findNativeError(polynomial,{'(',')','-'})){
        cout << "Invalid polynomial expression" << endl;
        return;
    }
    vector<string> members = SplitStr(polynomial,'+');
    vector<int> degres;

    for(string member : members){
        int degre = CheckMember(member);
        if(degre == -1 || VectorContains(degres,degre)){
            cout << "Invalid polynomial expression" << endl;
            return;
        }
        else degres.push_back(degre);
    }
    int complexity = GetMaxVector(degres);
    cout << "Valid polynomial of complexity " << complexity << endl;

    return;
}

/**
 * * First exercise of the assignement
 */
void Exercise1()
{
    char polynomial[100];
    cout << "Enter a polynomial : " << endl;
    cin.getline(polynomial,sizeof(polynomial));

    checkPolynomial(polynomial);
}

/**
 * * Function for exercise 2
 * Find a subset in input array that multiplies to given target
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
    cout << system("pause");
    return 0;
}