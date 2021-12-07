#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <algorithm>
#include <regex>
using namespace std;

void Menu()
{
    cout << "                 Six Degrees of Kevin Bacon                 " << endl;
    cout << "============================================================" << endl;
    cout << "	Calculate the degrees of separation of :" << endl;
    cout << "[1] Kevin Bacon and any actor / actress" << endl;
    cout << "[2] Kevin Bacon and any director" << endl;
    cout << "[3] Kevin Bacon and any producer" << endl;
    cout << "[4] Any combination of 2 actors, directors, or producers" << endl;
    cout << "[5] Exit" << endl;
    cout << "============================================================" << endl;
    cout << endl;
    cout << "Enter a menu option: ";
}

void Interface()
{
    bool run = true;
    while (run)
    {
        Menu();
        int input;
        string input2, input3;
        cin >> input;
        cout << endl;
        if (input == 1)
        {
            cout << "Enter the first and last name of any actor / actress: ";
            cin >> input2;
            //graph.Separation("Kevin Bacon", input);
        }
        else if (input == 2)
        {
            cout << "Enter the first and last name of any director: ";
            cin >> input2;
            //graph.Separation("Kevin Bacon", input);
        }
        else if (input == 3)
        {
            cout << "Enter the first and last name of any producer: ";
            cin >> input2;
            //graph.Separation("Kevin Bacon", input);
        }
        else if (input == 4)
        {
            cout << "Enter the first and last name of the first actor / actress: ";
            cin >> input2;
            cout << "Enter the first and last name of the other actor / actress: ";
            cin >> input3;
            //graph.Separation(input2, input3);
        }
        if (input == 5)
            run = false;
        else
        {
            input2.clear();
            input3.clear();
            cout << endl << "Run again? (enter y or n): ";
            string again;
            cin >> again;
            if (again == "y")
                cout << "\033[2J\033[1;1H"; //this clears the terminal lol idk how
            if (again == "n")
                run = false;
        }
    }
}

void IO()
{
    ifstream file("data.txt");
    const int NUMBER_OF_FILMS = 146727;

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
            int titleFilm = line.find("(film)");
            int hasCast = line.find("cast");
            int castActor = line.find("(actor)");
            int castActress = line.find("actress)");
            int hasDirectors = line.find("directors");
            int hasProducers = line.find("producers");

            if (hasTitle > 0 && hasCast > 0 && hasDirectors > 0 && hasProducers > 0 && titleFilm < 0 && castActor < 0 && castActress < 0)
            {

                title = line.substr(10, line.find("cast") - 13);
                line = line.substr(line.find("cast") + 6);
                cout << title << endl;

                cast = line.substr(1, line.find("directors") - 4);
                cout << "Cast: " << cast << endl;

                if (cast != "[]}" && cast != "[]") {
                    line = line.substr(line.find("directors") + 11);

                    int k = count(cast.begin(), cast.end(), ']') / 2;
                    for (int j = 0; j < k; j++)
                    {
                        string actorName = cast.substr(cast.find("[") + 2, cast.find("]") - 2);
                        if (j < k - 1)
                            cast = cast.substr(actorName.length() + 7);
                        cout << actorName << endl;
                    }


                    directors = line.substr(0, line.find("producers") - 2);
                    line = line.substr(line.find("producers") + 11);
                    cout << "Directors: " << directors << endl;

                    producers = line.substr(0, line.find("companies") - 2);
                    cout << "Producers: " << producers << endl;
                }
            }
        }
    }
}

int main()
{
    Interface();

    return 0;
}