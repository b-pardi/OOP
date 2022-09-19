#include <iostream>
using namespace std;

// function finds length by incrementing searching for null terminator,
// then dynamically creates a new array,
// and lastly copies over old array to the new with the null term
char* stringAllocator(char* cArr)
{
    //int len = sizeof(cArr)/sizeof(*cArr);
    int len = 0;
    while(cArr[len] != '\0')
        len++;

    cout << len<< endl;
    char *newArr = new char[len];

    for (int i = 0; i<len; i++)
    {
        newArr[i] = cArr[i];
    }

    newArr[len] = '\0';

    return newArr;
}

int main()
{
    char* testString = "I like bananas";
    char* feedString = stringAllocator(testString);
    char* resultString = stringAllocator(feedString);

    cout << "static string: " << testString << " its ptr: " << &testString << endl;
    cout << "'new' string: " << resultString << " its ptr: " << &resultString << endl;
}