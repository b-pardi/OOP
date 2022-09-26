#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Text
{
    string text;
public:
    // default constructor
    Text()
    {
        text = "Default text";
    }

    // arg constructor
    Text(string fn)
    {
        ifstream infile(fn);
        if (!infile.is_open())
        {
            cerr << "Can't open file: " << fn << endl;
            exit(1);
        }
        text.assign(istreambuf_iterator<char>(infile), istreambuf_iterator<char>());
    }

    // return contents of string
    string contents()
    {
        return text;
    }
};


int main()
{
    Text defaultText;
    cout << defaultText.contents() << endl;

    Text argText("joke.txt");
    cout << argText.contents() << endl;
}