#include <iostream>
using namespace std;

class myClass
{
    float f1;
    const float f2;

public:
    myClass() : f1(4.2), f2(6.9) {}
    float getf1()
    {
        return f1;
    }
    float getf2()
    {
        return f2;
    }
};

int main()
{
    myClass f;
    cout << f.getf1() << endl;
}