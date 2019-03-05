#ifndef FILEPERSONREPOSITORY_H
#define FILEPERSONREPOSITORY_H
#include "PersonRepository.h"
class FilePersonRepository : public PersonRepository {
    private:
    std::string fileName;

    public:
    bool saveAllConsultants(std::vector<Person> consultants);
    FilePersonRepository(std::string fileName);
    std::vector<Person> getAllPersons(); 
    bool savePerson(Person* person);
    bool removePerson(Person* person);
};
#endif