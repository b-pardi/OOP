#include <iostream>
using namespace std;

class mySimpleClass
{
    int x;
public:
    // default constructor x to 0
    mySimpleClass() : x(0) {}
    //  constructors inits x to passed in value for x
    mySimpleClass(int x) : x(x) {}

    // operator overload addition to add the x value of 2 objects
    const mySimpleClass operator +(const mySimpleClass &rhs)
    {
        return mySimpleClass(x + rhs.x);
    }
    
    // same as above for multiplication
    const mySimpleClass operator *(const mySimpleClass &rhs)
    {
        return mySimpleClass(x * rhs.x);
    }

    // print takes a stream reference to output x to terminal
    void print(ostream &out)
    {
        out << x << endl;
    }
};

int main()
{
    // create mySimpleClass objects
    mySimpleClass x1(6), x2(9);
    // 2 more objects demonstrating operator overloading
    mySimpleClass y1 = x1 + x2;
    mySimpleClass y2 = x1 * x2;

    // print result of overloaded operators
    y1.print(cout);
    y2.print(cout);
}