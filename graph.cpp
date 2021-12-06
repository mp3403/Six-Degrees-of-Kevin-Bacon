#include "graph.h"
#include <algorithm>
#include <iterator>

Graph::Graph(int numInputs) {
    this->adjList = new list<Person>[numInputs];
}

Graph::~Graph() {
    delete this->adjList;
}

int Graph::V() {
    return this->adjList->size();
}

int Graph::E() {
    int numEdges;

    for (int i = 0; i < this->adjList->size(); i++) {
        numEdges += this->adjList[i].size();
    }

    return numEdges;
}

void Graph::insert(Person p) {


    for (int i = 0; i < this->adjList->size(); i++) {
        //TODO: if intersection != null, add edge
        set<string> intersection;
        //TODO: change variables below
        set_intersection(set1.begin(), set1.end(), set2.begin(), set2.end(), inserter(res1,res1.begin()));
    }
}