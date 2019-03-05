#ifndef PERSONREPOSITORY_H
#define PERSONREPOSITORY_H
#include "person.h"
#include <vector>
class PersonRepository {
    public:
    virtual std::vector<Person> getAllPersons() = 0; 
    virtual bool savePerson(Person* person) = 0;
    virtual bool removePerson(Person* person) = 0;
};
#endif