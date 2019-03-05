#ifndef RANDOMIZESEATSCOMMAND_H
#define RANDOMIZESEATSCOMMAND_H
#include "MenuCommand.h"
#include "SeatRandomizer.h"
#include "PersonRepository.h"
#include <iostream>

class RandomizeSeatsCommand : public MenuCommand {
    private:
    SeatRandomizer* seatRandomizer;
    PersonRepository* repository;

    public:
    RandomizeSeatsCommand(PersonRepository* repository,SeatRandomizer* SeatRandomizer);
    void execute();
};
#endif