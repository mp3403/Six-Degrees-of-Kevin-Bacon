#include "graph.h"
#include <algorithm>
#include <iterator>
#include <unordered_map>
#include <queue>
#include <stack>

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

vector<Person> Graph::BFS(Person& to) {
    Person src = this->BFS();
    queue<Person> q;
    set<Person> visited;
    vector<Person> path;
    
    visited.insert(src);
    q.push(src);
    path.push_back(src);
    
    while (!q.empty()) {
        Person p = q.front();
        q.pop();

        path.push_back(p);

        if (p.getName() == to.getName()) {
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

    return path;
}

vector<Person> Graph::BFS(Person& from, Person& to) {
    queue<Person> q;
    set<Person> visited;
    vector<Person> path;
    
    visited.insert(from);
    q.push(from);
    path.push_back(from);
    
    while (!q.empty()) {
        Person p = q.front();
        q.pop();

        path.push_back(p);

        if (p.getName() == to.getName()) {
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

    return path;
}

Person Graph::DFS() {
    Person kevinBacon;
    stack<Person> stk;
    set<Person> visited;
    
    visited.insert(this->adjList->begin()->first);
    stk.push(this->adjList->begin()->first);
    
    while (!stk.empty()) {
        Person p = stk.top();
        stk.pop();

        if (p.getName() == "Kevin Bacon") {
            kevinBacon = p;
            break;
        }
        
        vector<Person> neighbors = this->adjList->at(p);
        
        for (Person i : neighbors) {
            if (visited.count(i) == 0) {
                visited.insert(i);
                stk.push(i);
            }
        }
    }

    return kevinBacon;
}

vector<Person> Graph::DFS(Person& to) {
    vector<Person> shortestPath(V()); //the shortest path will be, in the worst case, V vertices long

    for (auto iter = this->adjList->begin(); iter != this->adjList->end(); ++iter) {
        stack<Person> stk;
        set<Person> visited;
        vector<Person> tempPath;
        
        visited.insert(iter->first);
        stk.push(iter->first);
        tempPath.push_back(iter->first);
        
        while (!stk.empty()) {
            Person p = stk.top();
            stk.pop();

            tempPath.push_back(p);

            if (p.getName() == to.getName()) {
                break;
            }
            
            vector<Person> neighbors = this->adjList->at(p);
            
            for (Person i : neighbors) {
                if (visited.count(i) == 0) {
                    visited.insert(i);
                    stk.push(i);
                }
            }
        }

        if (tempPath.size() < shortestPath.size())
            shortestPath = tempPath;
    }

    return shortestPath;
}