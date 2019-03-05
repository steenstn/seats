#include "SeatRandomizer.h"
class SeatRandomizer;

SeatRandomizer::SeatRandomizer(int numDays, int numSlotsPerDay) {
    this->numDays = numDays;
    this->numSlotsPerDay = numSlotsPerDay;
    srand (time(NULL));
}

std::vector<std::vector<Person>> SeatRandomizer::getRandomizedSeats(std::vector<Person> persons) {

    std::vector<std::vector<Person>> result(this->numDays);
    int totalSeats = this->numDays * this->numSlotsPerDay;
    for(int i = 0; i < totalSeats; i++) {
        int dayIndex = rand() % numDays;
        int personIndex = rand() % persons.size();
        result[dayIndex].push_back(persons[personIndex]);
    }

    return result;
}