#include "EditConsultantCommand.h"
#include "PersonRepository.h"
#include <stdlib.h>
#include <iostream>
#include <string>
class EditConsultantCommand;

EditConsultantCommand::EditConsultantCommand(PersonRepository* repository, Presenter* presenter) : MenuCommand(5, "Edit consultant") {
    this->repository = repository;
    this->presenter = presenter;
}

void EditConsultantCommand::execute() {
    auto allConsultants = this->repository->getAllPersons();
    this->presenter->printConsultantList(allConsultants);
    std::cout << "Select consultant: ";
    int consultantIndex;
    std::cin >> consultantIndex;
    std::cin.ignore();
    if(consultantIndex < 0 || consultantIndex >=allConsultants.size()) {
        return;
    }
    Person* p = &allConsultants[consultantIndex];
    system("cls");
    std::cout << p->getName() << std::endl << "Choose action" << std::endl;
    std::cout << "1. Flip active status" << std::endl;
    std::cout << "2. Edit note" << std::endl;

    int choice;
    std::cin >> choice;
    std::cin.ignore();
    if(choice == 1) {
        Person updatedPerson(p->getName(), p->isActive() ? 0 : 1, p->getNote()); // TODO: Fix for all status
        allConsultants[consultantIndex] = updatedPerson;
        this->repository->saveAllConsultants(allConsultants);
    } else if(choice == 2) {
        std::cout << "Enter note: ";
        std::string note;
        std::getline(std::cin, note);
        Person updatedPerson(p->getName(), p->getBitStatus(), note);
        allConsultants[consultantIndex] = updatedPerson;
        this->repository->saveAllConsultants(allConsultants);
    }

}