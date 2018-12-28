#include "conditionParser.h"
#include "ifCommand.h"
#include "LoopCommand.h"

conditionParser::conditionParser(std::map<string, Command*> commands){
    this->mapCommands = commands;
}

conditionParser::conditionParser(){}

int conditionParser::doCommand(vector<string>::iterator &vectorIt){
    Command* command;
    if (*vectorIt == "if"){
        vectorIt++;
        command = new ifCommand(vectorIt);
    } else if (*vectorIt == "while"){
        vectorIt++;
        command = new LoopCommand(vectorIt);
    }
    while (*vectorIt != "}"){
        if(this->mapCommands.count(*vectorIt)){
            this->listCommands.push_back(this->mapCommands.find(*vectorIt)->second);
        }
    }

}