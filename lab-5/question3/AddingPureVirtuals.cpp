#include <iostream>
#include <string>
using namespace std;

class Pet {
    string pname;
public:
    Pet(const string& petName) : pname(petName) {}
    // member functions now pure virtual to be overridden later
    virtual string name() =0;
    virtual string speak() =0;
};

// defining Pet::name() function (getter)
string Pet::name()
{
    return pname;
}

class Dog : public Pet {
public:
    Dog(const string& petName) : Pet(petName) {}

    // New virtual function in the Dog class:
    // sit() not in base class, not overriding
    virtual string sit() 
    {
        return Pet::name() + " sits";
    }

    // override speak since (made pure virtual in base class)
    string speak()  
    {
        return Pet::name() + " says 'Bark!'";
    }

    // override name
    string name()
    {
        return Pet::name();
    }
};

int main()
{
    // new dog object given name Fido
    Pet * pet = new Dog("Fido");
    Dog * dog = new Dog("Frank");

    // test dog obj
    cout << pet->name() << endl;
    cout << pet->speak() << endl;
    cout << dog->sit() << endl;
} 