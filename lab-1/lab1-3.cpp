#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    string str;
    int val = 0;
    fstream infile;
    infile.open("lab1-3-in.txt", ios::in);
    while (1)
    {
        infile >> str;

        if (str == "cow")
            val = 1;

        if (str == "apple")
            val = 2;

        if (str == "condemn")
            val = 3;

        if (str == "juxtapose")
            val = 4;

        if (str == "onomatopoeia")
            val = 10;

        if (str == "break")
            break;

        switch (val)
        {
        case 1:
            cout << "Word kinda short" << endl;
            break;

        case 2:
            cout << "still kind of short" << endl;
            break;

        case 3:
            cout << "That is a decent length word" << endl;
            break;

        case 4:
            cout << "Impressive word" << endl;
            break;

        case 10:
            cout << "That is a godly word" << endl;
            break;

        default:
            cout << "not aassigned word" << endl;
        }
        val = 0;
    }
    infile.close();
}