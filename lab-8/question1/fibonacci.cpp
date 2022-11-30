#include <iostream>
using namespace std;

template <typename T>
T fibonacci(const T &n)
{
    static T *fib = new T[n + 1];
    fib[0] = 0;
    fib[1] = 1;

    for (int index = 2; index < n + 1; index++)
    {
        fib[index] = fib[index - 1] + fib[index - 2];
        cout << index << ". " << fib[index] << endl;
    }
    return fib[n];
}

int main()
{
    cout << fibonacci(165) << endl;
}