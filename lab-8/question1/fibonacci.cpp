#include <iostream>
using namespace std;

// all other cases where n > 1 iterate adding previous values
// default T to int unless otherwise specified
template<int n, typename T = int>
class fibonacci {
public:
    static constexpr T value = fibonacci<n-1,T>::value + fibonacci<n-2,T>::value;
};

// base case 1 where n = 0
template<typename T>
class fibonacci<0,T> {
public:
    static constexpr T value = 0;
};

// base case 2 where n = 1
template<typename T>
class fibonacci<1,T> {
public:
    static constexpr T value = 1;
};


int main()
{
    const int n1 = 90;

    // 90th fibonacci number is large, so must specify long data type
    cout <<fibonacci<n1, long>::value << endl;
    return 0;
}