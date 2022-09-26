#include <iostream>

using namespace std;

class Fibonacci
{
public:
    int fibArr[8];
    Fibonacci() : fibArr{1,1,2,3,5,8,13,21} {}
};

int main()
{
    // init fib object
    Fibonacci fib;
    // init type fib ptr object, pointed to addr of fib member
    Fibonacci* fib_ptr = &fib;

    // create array of type fib ptrs set to address of fib class arr (ptrs to members)
    int (Fibonacci::*arr_ptrs)[8] = &Fibonacci::fibArr;

    for (int i = 0; i < 8; i++)
        cout << *(fib_ptr->*arr_ptrs+i) << ", ";
        //cout << *(fib_ptr->fibArr+i) << endl;
    cout << endl;
}