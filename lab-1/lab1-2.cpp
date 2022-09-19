#include "lab1-2.h"
#include <iostream>
using namespace std;

void aVoidFunc()
{
    cout << "This is aVoidFunc()" << endl;
    cout << "args: N/A" << endl;
    cout << "I will return nothing :(" << endl;
}

char aCharFunc(int my_num, char my_char)
{
    cout << "This is aCharFunc()" << endl;
    cout << "args: " << my_num << ", " << my_char << endl;
    cout << "I will return char" << endl;
    return my_num + my_char;
}

int anIntFunc(float my_float)
{
    cout << "This is afloatingFunc()" << endl;
    cout << "args: " << my_float << endl;
    cout << "I will return int" << endl;
    return my_float + 6.9;
}

float aFloatingFunc(int my_int)
{
    cout << "This is afloatingFunc()" << endl;
    cout << "args: " << my_int << endl;
    cout << "I will return float" << endl;
    return my_int + 42;
}