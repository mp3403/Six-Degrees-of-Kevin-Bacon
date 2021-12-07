#pragma once
#include <set>
#include <string>

using namespace std;

class Person
{
    string name;
    set<string> films;
    enum Occupations {ACTOR, DIRECTOR, PRODUCER};

    public:
        set<string> getFilms() const;
        void setFilms(set<string>& films);
        string getName() const;
        void setName(string& name);
};