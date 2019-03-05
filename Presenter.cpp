#include <iostream>
#include "Presenter.h"
#include <Windows.h>
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
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    for(int i = 0; i < consultants.size(); i++) {
        Person consultant = consultants[i];
        int characterColor = consultant.isActive() ? FOREGROUND_GREEN | FOREGROUND_INTENSITY : FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED;
        SetConsoleTextAttribute(out, characterColor);
        cout << i << ": " << consultant.getName() << "\t" << consultant.getNote() << endl;
    }
    SetConsoleTextAttribute(out, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
    cout << endl;
}