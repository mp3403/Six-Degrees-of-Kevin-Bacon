#pragma once
#include "person.h"
#include <list>

using namespace std;

class Graph
{
    list<Person>* adjList;

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