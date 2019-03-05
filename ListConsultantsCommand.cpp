#include "MenuCommand.h"
#include "Presenter.h"
#include "PersonRepository.h"
#include <stdlib.h>
#include <iostream>
#include "ListConsultantsCommand.h"

class ListConsultantsCommand;

ListConsultantsCommand::ListConsultantsCommand(PersonRepository* repository, Presenter* presenter) : MenuCommand(1, "List consultants"){
    this->repository = repository;
    this->presenter = presenter;
}

void ListConsultantsCommand::execute() {
    system("cls");
    std::cout << "Consultants" << std::endl << std::endl;
    presenter->printConsultantList(repository->getAllPersons());
}
