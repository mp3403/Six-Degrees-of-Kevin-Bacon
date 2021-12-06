#pragma once
#include "person.h"
#include <list>
#include <map>
#include <unordered_map>

using namespace std;

class Graph
{
    //TODO: do away with array, make map<Person, vector<Person>> pointer
    list<Person>* adjList;
    unordered_map<int, Person> m;

    public:
        Graph(int numInputs);
        ~Graph();
        int V(); //returns num vertices
        int E(); //returns num edges

        void insert(Person p);
        void isEdge(Person from, Person to);
        list<Person>& getAdjacent(Person p);
        void printGraph();
};