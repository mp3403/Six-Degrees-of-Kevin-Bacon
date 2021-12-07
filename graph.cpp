#include "graph.h"
#include <algorithm>
#include <iterator>
#include <unordered_map>
#include <queue>

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
        set_intersection(p.getFilms().begin(), p.getFilms().end(), iter->first.getFilms().begin(), iter->first.getFilms().end(), inserter(intersection, intersection.begin()));

        if (intersection.size() > 0)
            iter->second.push_back(p);
    }
}

Person Graph::BFS() {
    Person kevinBacon;
    queue<Person> q;
    set<Person> visited;
    
    visited.insert(this->adjList->begin()->first);
    q.push(this->adjList->begin()->first);
    
    while (!q.empty()) {
        Person p = q.front();
        q.pop();

        if (p.getName() == "Kevin Bacon") {
            kevinBacon = p;
            break;
        }
        
        vector<Person> neighbors = this->adjList->at(p);
        
        for (Person i : neighbors) {
            if (visited.count(i) == 0) {
                visited.insert(i);
                q.push(i);
            }
        }
    }

    return kevinBacon;
}

Person Graph::BFS(Person& to) {
    Person src = this->BFS();
    queue<Person> q;
    set<Person> visited;
    
    visited.insert(src);
    q.push(src);
    
    while (!q.empty()) {
        Person p = q.front();
        q.pop();
        
        vector<Person> neighbors = this->adjList->at(p);
        
        for (Person i : neighbors) {
            if (visited.count(i) == 0) {
                visited.insert(i);
                q.push(i);
            }
        }
    }
}