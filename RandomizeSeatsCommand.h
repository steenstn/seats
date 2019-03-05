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
    RandomizeSeatsCommand(SeatRandomizer* SeatRandomizer, PersonRepository* repository);
    void execute();
};
#endif