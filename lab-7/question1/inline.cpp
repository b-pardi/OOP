#include <iostream>
#include <cstring>
using namespace std;

class myClass
{
    // holds chars
    char charArr[100];
    // n is size of memset allocation
    int n = 100;
public:
    // inline constructor allocates passed in char to allocate to charArr
    myClass(char c = ' '){memset(charArr, c, n);}
    // inline function to print contents of charArr
    void print(){for(size_t i = 0; i<n; i++) cout << charArr[i]; cout << endl;}
};

int main()
{
    // init myclass obj to use letter b to allocate to charArr
    myClass ch('b');
    ch.print();
}