#ifndef PERSON_H
#define PERSON_H
#include <string>
class Person {
    private:
    enum {ACTIVE = 1};
    std::string name;
    int bitStatus;

    public:
    Person(std::string);
    Person(std::string, int status);
    std::string getName();
    bool isActive();
    int getBitStatus();

};
#endif