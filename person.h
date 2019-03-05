#ifndef PERSON_H
#define PERSON_H
#include <string>
class Person {
    private:
    enum {ACTIVE = 1};
    std::string name;
    int bitStatus;
    std::string note;

    public:
    Person(std::string);
    Person(std::string, int status);
    Person(std::string, int status, std::string note);
    std::string getName();
    bool isActive();
    int getBitStatus();
    std::string getNote();

};
#endif
