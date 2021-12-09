#include "person.h"
#include "graph.h"
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
    cout << endl;
    cout << "[5] Find any actor, director, or producer in the data" << endl;
    cout << "[6] Exit" << endl;
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
        string firstName, lastName, name;
        cin >> input;
        cout << endl;
        if (input == 1)
        {
            cout << "Enter the first and last name of any actor / actress: ";
            cin >> firstName;
            cin >> lastName;
            name = firstName + " " + lastName;
            //graph.Separation("Kevin Bacon", input);
        }
        else if (input == 2)
        {
            cout << "Enter the first and last name of any director: ";
            cin >> firstName;
            cin >> lastName;
            name = firstName + " " + lastName;
            //graph.Separation("Kevin Bacon", input);
        }
        else if (input == 3)
        {
            cout << "Enter the first and last name of any producer: ";
            cin >> firstName;
            cin >> lastName;
            name = firstName + " " + lastName;
            //graph.Separation("Kevin Bacon", input);
        }
        else if (input == 4)
        {
            cout << "Enter the first and last name of the first actor / actress: ";
            cin >> firstName;
            cin >> lastName;
            name = firstName + " " + lastName;
            cout << "Enter the first and last name of the other actor / actress: ";
            string firstName2, lastName2, name2;
            cin >> firstName2;
            cin >> lastName2;
            name2 = firstName2 + " " + lastName2;
            //graph.Separation(name, name2);
            firstName2.clear();
            lastName2.clear();
            name2.clear();
        }
        else if (input == 5)
        {
            cout << "Enter the first and last name of any producer: ";
            cin >> firstName;
            cin >> lastName;
            name = firstName + " " + lastName;
            //start timer
            /*
            if (DFS(name))
            {
                //stop timer
                cout << "DFS: " << duration << " milliseconds" << endl;
            }
            //start timer
            if (BFS(name))
            {
                //stop timer
                cout << "DFS: " << duration << " milliseconds" << endl;
                cout << "Films: " << endl;
                for (string title : name.films)
                    cout << title << endl;
            }
            cout << endl << "BFS :"*/
        }
        if (input == 6)
            run = false;
        else
        {
            firstName.clear();
            lastName.clear();
            name.clear();
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

void BuildGraph(Graph& graph)
{
    ifstream file("data.txt");
    const int NUMBER_OF_FILMS = 146727;

    if (file.is_open())
    {
        cout << "Creating graph..." << endl;
        
        string line; // "line" is the whole line from the data file, "line" contains all data for a single film
        // separate the string into respective parts
        string title;
        string cast;
        string directors;
        string producers;

        // while there is a line to be gotten
        for (int i = 0; i < 146545; i++)
        {
            getline(file, line);

            int hasTitle = line.find("title");
            int titleFilm = line.find("(film)");
            int hasCast = line.find("cast");
            int castActor = line.find("(actor)");
            int castActress = line.find("actress)");
            int hasDirectors = line.find("directors");
            int hasProducers = line.find("producers");
            int hasBR = line.find("<br/>");
            int hasDash = line.find("\\");
            bool left = count(line.begin(), line.end(), '[');
            bool right = count(line.begin(), line.end(), ']');

            if (hasTitle > 0 && hasCast > 0 && hasDirectors > 0 && hasProducers > 0 && titleFilm < 0 && castActor < 0 && castActress < 0 && hasBR < 0 && hasDash < 0 && (left == right))
            {

                title = line.substr(10, line.find("cast") - 13);
                line = line.substr(line.find("cast") + 6);

                cast = line.substr(1, line.find("directors") - 4);

                if (cast != "[]}" && cast != "[]") {
                    line = line.substr(line.find("directors") + 11);

                    int k = count(cast.begin(), cast.end(), '\"') / 2;
                    for (int j = 0; j < k; j++)
                    {
                        string actorName;
                        if (cast.at(1) == '[')
                        {
                            actorName = cast.substr(cast.find("\"") + 3, cast.find("]") - 3);
                            if (j < k - 1)
                                cast = cast.substr(actorName.length() + 7);
                        }
                        else
                        {
                            if (cast.at(0) == '\"')
                                cast = cast.substr(1);
                            actorName = cast.substr(0, cast.find("\""));
                            if (j < k - 1)
                                cast = cast.substr(actorName.length() + 2);
                        }
                        //mark use actorName here to build graph
                        Person p(actorName, Person::ACTOR);
                        graph.insert(p);
                    }

                    directors = line.substr(1, line.find("producers") - 4);
                    line = line.substr(line.find("producers") + 10);

                    if (directors != "[]}" && directors != "[]") {
                        line = line.substr(line.find("producers") + 2);

                        int m = count(directors.begin(), directors.end(), '\"') / 2;
                        for (int j = 0; j < m; j++)
                        {
                            string directorName;
                            if (directors.at(1) == '[')
                            {
                                directorName = directors.substr(directors.find("\"") + 3, directors.find("]") - 3);
                                if (j < m - 1)
                                    directors = directors.substr(directorName.length() + 7);
                            }
                            else
                            {
                                if (directors.at(0) == '\"')
                                    directors = directors.substr(1);
                                directorName = directors.substr(0, directors.find("\""));
                                if (j < m - 1)
                                    directors = directors.substr(directorName.length() + 2);
                            }
                            //mark use directorName here to build graph
                            Person p(directorName, Person::DIRECTOR);
                            graph.insert(p);
                        }

                        
                        producers = line.substr(1, line.find("companies") - 4);
                        line = line.substr(line.find("companies") + 10);

                        

                        if (producers.length() != 0 && producers.at(0) != ']' && producers != "[]}" && producers != "[]" && line != ":[]}") {
                            directors = line.substr(1, line.find("companies") - 4);
                            line = line.substr(line.find("companies") + 9);
                            line = line.substr(line.find("companies") + 2);

                            int o = count(producers.begin(), producers.end(), '\"') / 2;
                            for (int j = 0; j < o; j++)
                            {
                                string producerName;
                                if (producers.at(1) == '[')
                                {
                                    producerName = producers.substr(producers.find("\"") + 3, producers.find("]") - 3);
                                    if (j < o - 1)
                                        producers = producers.substr(producerName.length() + 7);
                                }
                                else
                                {
                                    if (producers.at(0) == '\"')
                                        producers = producers.substr(1);
                                    producerName = producers.substr(0, producers.find("\""));
                                    if (j < o - 1)
                                        producers = producers.substr(producerName.length() + 2);
                                }
                                if (producerName != ",")
                                {
                                    //mark use producerName here to build graph
                                    Person p(producerName, Person::PRODUCER);
                                    graph.insert(p);
                                }
                            }
                        }
                    }
                    //if we do something with vectors do it here
                }
            }
        }
        cout << "Graph complete!" << endl;
    }
}

int main()
{
    Graph graph;
    BuildGraph(graph); //builds graph from .txt data
    Interface();

    return 0;
}