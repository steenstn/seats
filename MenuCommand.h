#ifndef MENUCOMMAND_H
#define MENUCOMMAND_H
#include <string>
class MenuCommand {
    private:
        int key;
        std::string description;

    public:
    MenuCommand() {};
        virtual void execute() = 0;
        int getKey() { return key; }
        std::string getDescription() { return description; }

    
        MenuCommand(int key, std::string description) {
            this->key = key;
            this->description = description;
        }
};
#endif