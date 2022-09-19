#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
using namespace std;

int main()
{
    int rad;
    cout << "Enter a radius: " << endl;
    cin >> rad;
    cout << "Area: " << M_PI * rad * rad << endl;
}