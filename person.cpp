#include "graph.h"
#include "person.h"

Person::Person() {
    this->name = "Kevin Bacon";
    this->films = {};
    this->occupation = Person::ACTOR;
}

Person::Person(string& name, Occupation occupation) {
    this->name = name;
    this->occupation = occupation;
}

void Person::addFilm(string& film) {
    this->films.insert(film);
}

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