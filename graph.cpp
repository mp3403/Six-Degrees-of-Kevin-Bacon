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

bool Graph::pathExistsBFS(Person& to) {
    Person src = this->BFS();
    queue<Person> q;
    set<Person> visited;
    
    visited.insert(src);
    q.push(src);
    
    while (!q.empty()) {
        Person p = q.front();
        q.pop();

        if (p.getName() == to.getName()) {
            return true;
        }

        vector<Person> neighbors = this->adjList->at(p);
        
        for (Person i : neighbors) {
            if (visited.count(i) == 0) {
                visited.insert(i);
                q.push(i);
            }
        }
    }

    return false;
}

bool Graph::pathExistsBFS(Person& from, Person& to) {
    queue<Person> q;
    set<Person> visited;
    
    visited.insert(from);
    q.push(from);
    
    while (!q.empty()) {
        Person p = q.front();
        q.pop();

        if (p.getName() == to.getName()) {
            return true;
        }
        
        vector<Person> neighbors = this->adjList->at(p);
        
        for (Person i : neighbors) {
            if (visited.count(i) == 0) {
                visited.insert(i);
                q.push(i);
            }
        }
    }

    return false;
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

bool Graph::DFS(Person& to) {
    stack<Person> stk;
    set<Person> visited;
    Person src = this->DFS();
    
    visited.insert(src);
    stk.push(src);
    
    while (!stk.empty()) {
        Person p = stk.top();
        stk.pop();

        if (p.getName() == to.getName()) {
            return true;
        }
        
        vector<Person> neighbors = this->adjList->at(p);
        
        for (Person i : neighbors) {
            if (visited.count(i) == 0) {
                visited.insert(i);
                stk.push(i);
            }
        }
    }

    return false;
}

bool Graph::DFS(Person& from, Person& to) {
    stack<Person> stk;
    set<Person> visited;
    
    visited.insert(from);
    stk.push(from);
    
    while (!stk.empty()) {
        Person p = stk.top();
        stk.pop();

        if (p.getName() == to.getName()) {
            return true;
        }
        
        vector<Person> neighbors = this->adjList->at(p);
        
        for (Person i : neighbors) {
            if (visited.count(i) == 0) {
                visited.insert(i);
                stk.push(i);
            }
        }
    }

    return false;
}