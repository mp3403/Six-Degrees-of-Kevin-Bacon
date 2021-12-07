#include "graph.h"
#include <algorithm>
#include <iterator>
#include <unordered_map>

Graph::Graph(int numInputs) {
    this->adjList = new unordered_map<Person, vector<Person>>;
}

Graph::~Graph() {
    delete this->adjList;
}

int Graph::V() {
    return this->adjList->size();
}

int Graph::E() {
    int numEdges;

    for (auto iter = this->adjList->begin(); iter != this->adjList->end(); ++iter) {
        numEdges += iter->second.size();
    }

    return numEdges;
}

void Graph::insert(Person& p) {
    vector<Person> v;
    this->adjList->insert(make_pair(p, v));

    set<string> intersection;

    for (auto iter = this->adjList->begin(); iter != this->adjList->end(); ++iter) {
        //TODO: if intersection != null, add edge
        //TODO: change variables below
        set_intersection(p.getFilms().begin(), p.getFilms().end(), iter->first.getFilms().begin(), iter->first.getFilms().end(), inserter(intersection, intersection.begin()));

        if (intersection.size() > 0)
            iter->second.push_back(p);
    }
}