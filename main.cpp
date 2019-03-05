#include <iostream>
#include <stdlib.h>
#include <vector>
#include <map>
#include "person.h"
#include "FilePersonRepository.h"
#include "Choice.h"
#include "Presenter.h"
#include "SeatRandomizer.h"
#include "MenuCommand.h"
#include "ListConsultantsCommand.h"
#include "AddConsultantCommand.h"
#include "RemoveConsultantCommand.h"
#include "RandomizeSeatsCommand.h"


void listConsultants(FilePersonRepository* repository, Presenter* presenter);
void addConsultant(FilePersonRepository* repository);
void removeConsultant(FilePersonRepository* repository, Presenter* presenter);
int main(void) {
    
    PersonRepository* repository = new FilePersonRepository("persons.txt");
    Presenter presenter;
    SeatRandomizer* seatRandomizer = new SeatRandomizer(5, 5);
    int inputChoice = 0;

    std::vector<Choice> choices({Choice(0, "Exit"), Choice(1, "List consultants"), Choice(2, "Add consultant"), Choice(3, "Remove consultant"), Choice(4, "Randomize seats")});
    enum {EXIT = 0, LIST_CONSULTANTS = 1, ADD_CONSULTANT = 2, REMOVE_CONSULTANT = 3, RANDOMIZE_SEATS = 4};
    std::map<int, MenuCommand*> choiceMap;
    std::vector<MenuCommand*> choiceCommands({
        new ListConsultantsCommand(repository, &presenter),
        new AddConsultantCommand(repository),
        new RemoveConsultantCommand(repository, &presenter),
        new RandomizeSeatsCommand(seatRandomizer, repository)
        });
    
    for(int i = 0; i < choiceCommands.size(); i++) {
        choiceMap[choiceCommands[i]->getKey()] = choiceCommands[i];
    }

    while(true) {
        presenter.printMenu(choiceCommands);
        std::cin >> inputChoice;
        std::cin.get();
        auto choice = choiceMap[inputChoice];
        if(choice) {
            choice->execute();
        }
    }
    return 0;
}
