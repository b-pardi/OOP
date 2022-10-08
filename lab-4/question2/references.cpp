#include <iostream>

using namespace std;

// modify a reference to a pointer to a pointer
void modRef(int**& ref2ptr2ptr)
{
    (*ref2ptr2ptr) += 4;
}

int main() 
{
    int arr[] = {0, 1, 1, 2, 3, 5, 8, 13};
    // first ptr to head of array
    int* arrhead = arr;
    // then point to the pointer of the arr head
    int** arrhead_ptr = &arrhead;

    // compare before and after modifying reference
    cout << "original: " << **arrhead_ptr << endl;
    modRef(arrhead_ptr);
    cout << "modified: " << **arrhead_ptr << endl;
}