#include <iostream>

using namespace std;

// function of return type int address, take in pointer reference to a another pointer,
// modifies it, then returns the destination of the pointer
int& complexPointer(int* ptr_arg)
{
    int& dest = *ptr_arg;
    return dest += 4;
}

int main()
{
    // pass in pointer argument
    int pointed = 2;
    cout << pointed << ": " << complexPointer(&pointed) << endl;
}