#include <iostream>
#include <vector>
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

    int getID()
    {
        return id;
    }
};

int Counted::count = 0;

// access and print 'Counted' object's member: id
void printCounted(Counted& c)
{
    cout << c.getID() << " ";
}

int main()
{
    // vector of counted objects
    vector<Counted*> c;

    // loop pushes back new counted objects into vector
    for (int i = 0; i < 5; i++)
        c.push_back(new Counted);

    // print each element in vector
    cout << "Printing vector elements..." << endl;
    for (int i = 0; i < c.size(); i++)
        printCounted(*c[i]);

    // deleting each object
    cout << endl << "Deleting vector elements..." << endl;
    Counted* temp;
    while (c.size() > 0)
    {
        temp = c.back();
        c.pop_back();
        delete temp;
    }
}