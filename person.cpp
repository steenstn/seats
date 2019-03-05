#include "person.h"
class Person;

Person::Person(std::string name, int status, std::string note) {
    this->name = name;
    this->bitStatus = status;
    this->note = note;
}

Person::Person(std::string name, int status) : Person(name, status, "") {}
Person::Person(std::string name) : Person(name, ACTIVE, "") {}

std::string Person::getName() {
    return this->name;
}

bool Person::isActive() {
    return this->bitStatus & ACTIVE == ACTIVE;
}

int Person::getBitStatus() {
    return this->bitStatus;
}

std::string Person::getNote() {
    return this->note;
}
