#include "graph.h"
#include "person.h"
#include <algorithm>
#include <iterator>
#include <unordered_map>
#include <queue>
#include <stack>

Graph::Graph() {
    this->m = new unordered_map<string, Person>;
    this->adjList = new unordered_map<string, set<string>>;
}

Graph::Graph(const Graph& g) {
    this->m = g.m;
    this->adjList = g.adjList;
}

Graph::~Graph() {
    delete this->m;
    delete this->adjList;
}

void Graph::operator=(const Graph& g) {
    this->m = g.m;
    this->adjList = g.adjList;
}

int Graph::V() {
    return this->adjList->size();
}

int Graph::E() {
    int numEdges{};

    for (auto iter = this->adjList->begin(); iter != this->adjList->end(); ++iter) {
        numEdges += iter->second.size();
    }

    return numEdges;
}

void Graph::insert(vector<pair<string, Person::Occupation>> crew, string title) {
    for (pair<string, Person::Occupation> person : crew)
    {
        if (this->adjList->find(person.first) == this->adjList->end()) {
            set<string> s;
            this->adjList->insert(make_pair(person.first, s));
            Person p = Person(person.first, person.second);
            this->m->insert(make_pair(person.first, p));
        }
        else {
            this->m->at(person.first).addFilm(title);
        }

        for (pair<string, Person::Occupation> person2 : crew)
        {
            if (person.first != person2.first)
            {
                this->adjList->at(person.first).insert(person2.first);
            }
        }
    }
}

bool Graph::pathExistsBFS(string& from, string& to) {
    queue<string> q;
    set<string> visited;

    visited.insert(from);
    q.push(from);

    while (!q.empty()) {
        string p = q.front();
        q.pop();

        if (p == to) {
            return true;
        }

        set<string> neighbors = this->adjList->at(p);

        for (string i : neighbors) {
            if (visited.count(i) == 0) {
                visited.insert(i);
                q.push(i);
            }
        }
    }

    return false;
}

vector<Person> Graph::BFS(string& from, string& to) {
    queue<string> q;
    set<string> visited;
    vector<Person> path;

    visited.insert(from);
    q.push(from);
    path.push_back(m->at(from));

    while (!q.empty()) {
        string p = q.front();
        q.pop();

        path.push_back(m->at(p));

        if (p == to) {
            break;
        }

        set<string> neighbors = this->adjList->at(p);

        for (string i : neighbors) {
            if (visited.count(i) == 0) {
                visited.insert(i);
                q.push(i);
            }
        }
    }

    return path;
}

bool Graph::DFS(string& from, string& to) {
    stack<string> stk;
    set<string> visited;

    visited.insert(from);
    stk.push(from);

    while (!stk.empty()) {
        string p = stk.top();
        stk.pop();

        if (p == to) {
            return true;
        }

        set<string> neighbors = this->adjList->at(p);

        for (string i : neighbors) {
            if (visited.count(i) == 0) {
                visited.insert(i);
                stk.push(i);
            }
        }
    }

    return false;
}