#include "Choice.h"
class Choice;

Choice::Choice(int key, std::string name) {
    this->key = key;
    this->name = name;
}   

int Choice::getKey() {
    return this->key;
}

std::string Choice::getName() {
    return this->name;
}