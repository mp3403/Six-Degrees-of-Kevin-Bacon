#pragma once
#include "person.h"
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

class Graph
{
    unordered_map<string, Person>* m;
    unordered_map<string, set<string>>* adjList;

public:
    Graph();
    Graph(const Graph& g);
    ~Graph();
    void operator=(const Graph& g);
    int V(); //returns num vertices
    int E(); //returns num edges

    void insert(vector<pair<string, Person::Occupation>> crew, string title);
    bool pathExistsBFS(string& from, string& to); // returns if path exists
    vector<Person> BFS(string& from, string& to); // returns path
    bool DFS(string& from, string& to); //returns shortest DFS path
};