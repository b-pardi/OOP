#include "myHeader2.h"

namespace ns = myNamespace;

void test1()
{
    ns::fun1();
    ns::fun2();
}

void test2()
{
    using namespace ns;
    fun3();
    fun4();
}

int main()
{
    test1();
    test2();
}