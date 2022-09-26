//: C05:Handle.h
// Handle classes
#ifndef HANDLE_H
#define HANDLE_H
class Handle 
{
    struct Cheshire; // Class declaration only
    Cheshire* smile;
public:
    //void initialize();
    // constructor to replace initialize
    Handle();
    //void cleanup();
    // destructor to replace cleanup
    ~Handle();
    int read();
    void change(int);
};
#endif // HANDLE_H ///:~