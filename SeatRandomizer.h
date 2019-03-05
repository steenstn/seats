#ifndef SEATRANDOMIZER_H
#define SEATRANDOMIZER_H
#include <vector>
#include "person.h"
#include <stdlib.h>     
#include <time.h>       
class SeatRandomizer {
    private:
    int numDays;
    int numSlotsPerDay;
    public:
    SeatRandomizer(int numDays, int numSlotsPerDay);
    std::vector<std::vector<Person>> getRandomizedSeats(std::vector<Person> persons);
};
#endif