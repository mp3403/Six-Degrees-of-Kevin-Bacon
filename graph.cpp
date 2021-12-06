#include "graph.h"

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
    }
}