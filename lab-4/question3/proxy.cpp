#include <iostream>

using namespace std;

class Subject
{
public:
    virtual void f(){}

    virtual void g(){}

    virtual void h(){}

};

// proxy inherited from subject
class Proxy : public Subject
{
    // Proxy should contain a pointer to a Subject
    Subject* sub_ptr;
public:
    // proxy constructor takes a pointer to a Subject,
    // that is installed in the Proxy (usually by the constructor)
    // pre initialize sub_ptr before calling constructor
    Proxy(Subject* s) : sub_ptr(s)
    {
        Subject();
    }

    // all the member functions for Proxy should just turn around,
    // and make the same calls through the Subject pointer
    void f()
    {
        sub_ptr->f();
    }
    void g()
    {
        sub_ptr->g();
    }
    void h()
    {
        sub_ptr->h();
    }

    // setter for private pointer
    void modifyProxy(Subject* s)
    {
        sub_ptr = s;
    }
};

// inherited class from subject
// implementation 1 of the virtual void functions from subject
class Implementation1 : public Subject
{
public:
    void f()
    {
        cout << "imp1 'f' called" << endl;
    }
    void g()
    {
        cout << "imp1 'g' called" << endl;
    }
    void h()
    {
        cout << "imp1 'h' called" << endl;
    }
};

// inherited class from subject
// implementation 1 of the virtual void functions from subject
class Implementation2 : public Subject
{
public:
    void f()
    {
        cout << "imp2 'f' called" << endl;
    }
    void g()
    {
        cout << "imp2 'g' called" << endl;
    }
    void h()
    {
        cout << "imp2 'h' called" << endl;
    }
};

int main()
{
    // create two different Proxy objects 
    // that use the two different implementations. 
    Implementation1 imp_sub1;
    Implementation2 imp_sub2;
    
    Proxy proxy(&imp_sub1);
    cout << "Before: " << endl;
    proxy.f();
    proxy.g();
    proxy.h();

    // now modify Proxy so that you can dynamically change implementations
    proxy.modifyProxy(&imp_sub2);
    cout << endl << "After: " << endl;
    proxy.f();
    proxy.g();
    proxy.h();
}