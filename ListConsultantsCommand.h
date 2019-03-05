#ifndef LISTCONSULTANTSCOMMAND_H
#define LISTCONSULTANTSCOMMAND_H
#include "MenuCommand.h"
#include "Presenter.h"
#include "PersonRepository.h"
#include <stdlib.h>
#include <iostream>

class ListConsultantsCommand : public MenuCommand {
    private:
    PersonRepository* repository;
    Presenter* presenter;

    public:
    ListConsultantsCommand(PersonRepository* repository, Presenter* presenter);
    void execute();
};

#endif