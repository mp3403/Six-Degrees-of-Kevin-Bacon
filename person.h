#pragma once

using namespace std;

class Person
{
    set<pair<string, string>> films;
    enum occupations {actor, director, producer};
    enum occupations job;
};