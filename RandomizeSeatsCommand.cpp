#include "RandomizeSeatsCommand.h"

class RandomizeSeatsCommand;

RandomizeSeatsCommand::RandomizeSeatsCommand(SeatRandomizer* seatRandomizer, PersonRepository* repository) : MenuCommand(4, "Randomize seats") {
    this->seatRandomizer = seatRandomizer;
    this->repository = repository;
    
}

void RandomizeSeatsCommand::execute() {
    auto result = seatRandomizer->getRandomizedSeats(repository->getAllPersons());
    for(int i = 0; i < result.size(); i++) {
        std::cout << i << std::endl;
        for(int j = 0; j < result[i].size();j++) {
            std::cout << result[i][j].getName() << std::endl;
        }
        std::cout << std::endl;
    }
}