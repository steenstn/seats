#include <iostream>
#include "Presenter.h"
class Presenter;
using namespace std;
void Presenter::printMenu(std::vector<MenuCommand*> choices) {
    cout << endl;
    cout << "Menu"<<endl;
    for(int i = 0; i < choices.size();i++) {
        cout << choices[i]->getKey() << ": " << choices[i]->getDescription() <<endl;
    }
    cout << endl << "Choose option" << endl;
}

void Presenter::printConsultantList(std::vector<Person> consultants) {
    for(int i = 0; i < consultants.size(); i++) {
        cout << i << ": " << consultants[i].getName() << endl;
    }
    cout << endl;
}