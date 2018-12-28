#ifndef PROJECT1_CONDITIONPARSER_H
#define PROJECT1_CONDITIONPARSER_H

#include "Command.h"
#include <list>
#include "VarCommand.h"
//#include "ifCommand.h"

class conditionParser:public Command {
    list<Command*> listCommands;
    std::map<string, Command*> mapCommands;
public:
    conditionParser();
    conditionParser(std::map<string, Command*> commands);
    virtual int doCommand(vector<string>::iterator &vectorIt);

     /*   while (*vectorIt != "}"){
            if (this->commands.count(*vectorIt)) {
                listCommands.push_back(this->commands.find(*vectorIt)->second);
                vectorIt++;
            } else if (*vectorIt == "while"){
                //TODO
            } else if (*vectorIt == "if"){
                //TODO
            } else if (*vectorIt == "print"){
                //TODO
            } else if (*vectorIt == "sleep"){
                //TODO
            } else if (this->SymbolTable.count(*vectorIt)) {
                //TODO
            }
        }*/
    //virtual bool isTrue();
    //void toParser(vector<string>::iterator &vectorIt)


};


#endif //PROJECT1_CONDITIONPARSER_H