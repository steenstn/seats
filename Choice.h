#ifndef CHOICE_H
#define CHOICE_H
#include <string>
#include <functional>
class Choice {
    private:
    int key;
    std::string name;
    std::function<void()> func;
    public:
    Choice(int key, std::string name);
    int getKey();
    std::string getName();

};
#endif