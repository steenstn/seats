#ifndef ADDCONSULTANTCOMMAND_H
#define ADDCONSULTANTCOMMAND_H
#include "MenuCommand.h"
#include "PersonRepository.h"
#include <iostream>

class AddConsultantCommand : public MenuCommand {
    private:
    PersonRepository* repository;

    public:
    AddConsultantCommand(PersonRepository* repository);
    void execute();
};
#endif