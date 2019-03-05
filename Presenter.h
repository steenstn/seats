#ifndef PRESENTER_H
#define PRESENTER_H
#include <vector>
#include "person.h"
#include "MenuCommand.h"
class Presenter {

    public:
    void printMenu(std::vector<MenuCommand*> choices);
    void printConsultantList(std::vector<Person> consultants);
};
#endif