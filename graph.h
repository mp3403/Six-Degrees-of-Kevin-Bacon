#pragma once
#include "person.h"
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

class Graph
{
    unordered_map<Person, vector<Person>>* adjList;

    public:
        Graph(int numInputs);
        ~Graph();
        int V(); //returns num vertices
        int E(); //returns num edges

        void insert(Person& p);
        void isEdge(Person from, Person to);
        list<Person>& getAdjacent(Person& p);
        void printGraph();
        Person BFS(); //finds Kevin Bacon vertex
        vector<Person> BFS(Person& to); //from Kevin Bacon vertex, returns path
        vector<Person> BFS(Person& from, Person& to); // returns path
        Person DFS(); //finds Kevin Bacon vertex
        vector<Person> DFS(Person& to); //from Kevin Bacon vertex, returns shortest DFS path
        vector<Person> DFS(Person& from, Person& to); //returns shortest DFS path
};