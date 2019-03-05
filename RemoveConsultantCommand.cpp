#include "RemoveConsultantCommand.h"
#include <stdio.h>
#include <iostream>

class RemoveConsultantCommand;

RemoveConsultantCommand::RemoveConsultantCommand(PersonRepository* repository, Presenter* presenter) : MenuCommand(3, "Remove consultant") {
    this->repository = repository;
    this->presenter = presenter;
}

void RemoveConsultantCommand::execute() {
    system("cls");
    std::vector<Person> persons = repository->getAllPersons();
    presenter->printConsultantList(persons);
    int choice;
    std::cin >> choice;
    std::cin.get();
    bool result = repository->removePerson(&persons[choice]);
    std::cout << (result ? "Consultant removed" : "Could not remove consultant") << std::endl;
}