#include <iostream>
using namespace std;


class aGoodClass;

class aNiceClass
{
public:
    void aNiceFunction(aGoodClass *)
    {
        cout << "Nice Class" << endl;
    }
};

class aGoodClass
{
public:
    void aGoodFunction(aNiceClass *)
    {
        cout << "Good Class" << endl;
    }
};


int main()
{
    aGoodClass good;
    aNiceClass nice;

    good.aGoodFunction(&nice);
    nice.aNiceFunction(&good);
}