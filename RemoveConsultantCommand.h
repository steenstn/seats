#ifndef REMOVECONSULTANTCOMMAND_H
#define REMOVECONSULTANTCOMMAND_H
#include "MenuCommand.h"
#include "PersonRepository.h"
#include "Presenter.h"

class RemoveConsultantCommand : public MenuCommand {
    private:
    PersonRepository* repository;
    Presenter* presenter;

    public:
    RemoveConsultantCommand(PersonRepository* repository, Presenter* presenter);
    void execute();
};
#endif