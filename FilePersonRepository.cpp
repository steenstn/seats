#include "FilePersonRepository.h"
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
class FilePersonRepository;

bool FilePersonRepository::saveAllConsultants(std::vector<Person> consultants) {
    std::ofstream personsFile;
    personsFile.open (this->fileName);
    for(int i = 0; i < consultants.size();i++) {
        personsFile << consultants[i].getName() << "\n";
        personsFile << consultants[i].getBitStatus() << "\n";
        
    }
    personsFile.close();
    return true;
}

FilePersonRepository::FilePersonRepository(std::string fileName) {
    this->fileName = fileName;
}

std::vector<Person> FilePersonRepository::getAllPersons() {
    std::ifstream infile(this->fileName);

    std::vector<Person> result;

    
    int index = 0;
    int numFields = 2;
    while (infile.peek()!=EOF) {
        std::string name;
        std::getline(infile, name);
        std::string statusString;
        std::getline(infile, statusString);
        int status = std::stoi(statusString);
        result.push_back(Person(name, status));
    }
    infile.get();
    infile.close();
    return result;
}

bool FilePersonRepository::savePerson(Person* person) {
    std::vector<Person> allPersons = getAllPersons();
    allPersons.push_back(*person);
    saveAllConsultants(allPersons);
}

bool FilePersonRepository::removePerson(Person* person) {
    std::vector<Person> allPersons = getAllPersons();
    for(int i = 0; i < allPersons.size(); i++) {
        if(allPersons[i].getName() == person->getName()) {
            allPersons.erase(allPersons.begin()+i);
            return saveAllConsultants(allPersons);
        }
    }
    return false;
}


