#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <algorithm>
using namespace std;

int main() 
{
    ifstream file("data.txt");
    const int NUMBER_OF_FILMS = 146725;

    if (file.is_open())
    {
        string line; // "line" is the whole line from the data file, "line" contains all data for a single film
        // separate the string into respective parts
        string title;
        string cast;
        string directors;
        string producers;

        // while there is a line to be gotten
        for (int i = 0; i < 146727; i++)
        {
            getline(file, line);

            int hasTitle = line.find("title");
            int hasCast = line.find("cast");
            int hasDirectors = line.find("directors");;
            int hasProducers = line.find("producers");

            if (hasTitle > 0 && hasCast > 0 && hasDirectors > 0 && hasProducers > 0)
            {

                title = line.substr(10, line.find("cast") - 13);
                line = line.substr(line.find("cast") - 13);

                cast = line.substr(19, line.find("directors") - 21);
                if (cast != "[]}" && cast != "[]") {
                    line = line.substr(line.find("directors") + 13);
                    for (int j = 0; j < (count(cast.begin(), cast.end(), ']') - 1) / 2; j++)
                    {
                        string actorName = cast.substr(2, cast.find(']') - 2);
                        cast = cast.substr(cast.find(']') + 3);
                        //if: actor vertex does not exist
                            //create new actor vertex
                        //else:
                            //add current film to actor vertex
                        cout << actorName << endl;
                    }


                    directors = line.substr(0, line.find("producers") - 2);
                    line = line.substr(line.find("producers") + 11);

                    producers = line.substr(0, line.find("companies") - 2);
                }
            }
        }
    }


    return 0;
}