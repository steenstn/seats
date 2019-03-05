#include <iostream>
#include <stdlib.h>
#include <vector>
#include <map>
#include "person.h"
#include "FilePersonRepository.h"
#include "Presenter.h"
#include "SeatRandomizer.h"
#include "MenuCommand.h"
#include "ListConsultantsCommand.h"
#include "AddConsultantCommand.h"
#include "RemoveConsultantCommand.h"
#include "RandomizeSeatsCommand.h"

int main(void) {
    
    PersonRepository* repository = new FilePersonRepository("persons.txt");
    Presenter presenter;
    SeatRandomizer seatRandomizer(5, 5);
    int inputChoice = 0;

    std::map<int, MenuCommand*> choiceMap;
    std::vector<MenuCommand*> choiceCommands({
        new ListConsultantsCommand(repository, &presenter),
        new AddConsultantCommand(repository),
        new RemoveConsultantCommand(repository, &presenter),
        new RandomizeSeatsCommand(&seatRandomizer, repository)
        });
    
    for(int i = 0; i < choiceCommands.size(); i++) {
        choiceMap[choiceCommands[i]->getKey()] = choiceCommands[i];
    }

    while(true) {
        presenter.printMenu(choiceCommands);
        std::cin >> inputChoice;
        auto choice = choiceMap[inputChoice];
        if(choice) {
            choice->execute();
        }
        
    }
    return 0;
}
