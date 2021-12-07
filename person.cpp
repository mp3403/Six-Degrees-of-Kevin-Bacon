#include "person.h"

set<string> Person::getFilms() const {
    return this->films;
}

void Person::setFilms(set<string>& films) {
    this->films = films;
}

string Person::getName() const {
    return this->name;
}

void Person::setName(string& name) {
    this->name = name;
}