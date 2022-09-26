//: C05:Handle.cpp {O}
// Handle implementation
#include "Handle.h"

// Define Handle's implementation:
struct Handle::Cheshire {
    int i;
};

// constructor to replace initialize
Handle::Handle() {
    smile = new Cheshire;
    smile->i = 0;
}

// desctructor to replace cleanup
Handle::~Handle() {
    delete smile;
}

int Handle::read() {
    return smile->i;
}

void Handle::change(int x) {
    smile->i = x;
} ///:~