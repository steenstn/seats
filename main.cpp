#include <iostream>
#include <vector>
#include <map>
#include "FilePersonRepository.h"
#include "MenuCommand.h"
#include "ListConsultantsCommand.h"
#include "AddConsultantCommand.h"
#include "RemoveConsultantCommand.h"
#include "RandomizeSeatsCommand.h"
#include "EditConsultantCommand.h"

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
        new RandomizeSeatsCommand(repository, &seatRandomizer),
        new EditConsultantCommand(repository, &presenter)
        });
    
    for(int i = 0; i < choiceCommands.size(); i++) {
        choiceMap[choiceCommands[i]->getKey()] = choiceCommands[i];
    }

    while(true) {
        presenter.printMenu(choiceCommands);
        std::cin >> inputChoice;
        if(inputChoice == 0) {
            return 0;
        }
        auto choice = choiceMap[inputChoice];
        std::cin.ignore();
        if(choice) {
            choice->execute();
        }
        
    }
    return 0;
}
