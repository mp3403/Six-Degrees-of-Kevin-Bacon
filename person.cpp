#include "person.h"

set<string> Person::getFilms() {
    return this->films;
}

void Person::setFilms(set<string>& films) {
    this->films = films;
}