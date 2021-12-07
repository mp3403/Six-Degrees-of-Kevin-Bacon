#pragma once
#include <set>
#include <string>

using namespace std;

class Person
{
    set<string> films;
    enum Occupations {ACTOR, DIRECTOR, PRODUCER};

    public:
        set<string> getFilms();
        void setFilms(set<string>& films);
};