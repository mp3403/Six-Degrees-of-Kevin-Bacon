#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include "graph.h"
#include "person.h"

using namespace std;
using std::fstream;

//============ file in/out ============
void input()
{
    ifstream file("data.txt");
    const int NUMBER_OF_FILMS = 146725;

    if (file.is_open())
    {
        string line; // "line" is the whole line from the data file, "line" contains all data for a single film

        // while there is a line to be gotten
        while (getline(file, line))
        {
            // separate the string into respective parts
            string title;
            string cast;
            string directors;
            string producers;
            string companies; // not used by program
            string year;

            title = line.substr(10, line.find("cast") - 13);

            cast = line.substr(line.find("cast") + 6, line.find("directors") - 29);
            
            cout << title << endl;
            cout << cast << endl;
        }
    }
}


int main() {
    input();
    return 0;
}