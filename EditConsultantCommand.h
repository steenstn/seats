#ifndef EDITCONSULTANTCOMMAND_H
#define EDITCONSULTANTCOMMAND_H
#include "MenuCommand.h"
#include "Presenter.h"
#include "PersonRepository.h"
#include <iostream>

class EditConsultantCommand : public MenuCommand {
    private:
    PersonRepository* repository;
    Presenter* presenter;
    public:
    EditConsultantCommand(PersonRepository* repository, Presenter* presenter);
    void execute();
};
#endif