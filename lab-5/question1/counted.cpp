#include <iostream>
using namespace std;

class Counted
{
    int id;
    static int count;
public:
    // counted constructor incr count
    Counted() : id(count++)
    {
        cout << "created: " << id << endl;
    }

    // counted deconstructor
    ~Counted()
    {
        cout << "destroyed: " << id << endl;
    }
};

int Counted::count = 0;

int main()
{
    // create count objects to demonstrate static vars,
    // are shared by multiple objects since memory allocated only once
    Counted count1;
    Counted count2;
    Counted count3;
}