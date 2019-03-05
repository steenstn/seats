#include "person.h"
class Person;
Person::Person(std::string name, int status) {
    this->name = name;
    this->bitStatus = status;
}

Person::Person(std::string name) {
    this->name = name;
    this->bitStatus = ACTIVE;
}

std::string Person::getName() {
    return this->name;
}

bool Person::isActive() {
    return this->bitStatus & ACTIVE == ACTIVE;
}

int Person::getBitStatus() {
    return this->bitStatus;
}
