#include "AddConsultantCommand.h"

class AddConsultantCommand;

AddConsultantCommand::AddConsultantCommand(PersonRepository* repository) : MenuCommand(2, "Add consultant"){
    this->repository = repository;
}

void AddConsultantCommand::execute() {

    std::cout << "Enter name: ";

    std::string consultantName;
    std::getline (std::cin, consultantName);
    Person p(consultantName);
    bool result = this->repository->savePerson(&p);
    std::cout << (result ? "Consultant saved" : "Could not save consultant") << std::endl;

}