#include "ConditionParser.h"
#include "IfCommand.h"
#include "LoopCommand.h"

/**
 * constructor
 */
ConditionParser::ConditionParser() {
}
/**
 * constructor
 */
ConditionParser::ConditionParser(CommandMap* commandMap,
                                 SymbolTable *symbolMap) {
    this->symbolTable = symbolMap;
    this->commandMap = commandMap;

}
/**
 * parser the condition
 * @param script iterator
 * @return 0 when finish
 */
int ConditionParser::doCommand(vector<string>::iterator &script) {
    //what kind is the condition, get the string value from the iterator
    string ifOrWhile=(*script);
    string condition = "";
    Command *newCommand;
    script++;
    //until the end of the condition
    while ((*script) != "{") {
        //get the condition
        condition += (*script);
        script++;
    }
    //make a condition type from the string of the condition
    this->boolExpression = new BoolExpression(condition);
    script++;
    this->createCommand(script);
    //if the type of the condition is "if"
    if (ifOrWhile == "if") {
        //create new ifCommand
        newCommand = new IfCommand(this->boolExpression,this->expressionCommandList,this->symbolTable);
        //if the type of the condition us "while"
    } else if (ifOrWhile == "while") {
        //create new LoopCommand
        newCommand = new LoopCommand(this->boolExpression,this->expressionCommandList,this->symbolTable);
    }
    //do the command of the type
    newCommand->doCommand(script);
    return 0;

}
/**
 * create new command
 * @param vectorIt the iterator
 */
void ConditionParser::createCommand(vector<string>::iterator &vectorIt) {
    Command *newCommand;
    Expression *newExpression;
    CommandExpression *commandExp;
    //until the end
    while ((*vectorIt) != "}") {
        //get the symbolMap
        map<string, double> symbolsMap = this->symbolTable->getSymbols();
        //if the command is in the map
        if (this->symbolTable->getSymbols().count(*vectorIt)) {
            Command *newCommand = this->commandMap->getCommand(
                    "control");
            commandExp = new CommandExpression(vectorIt, newCommand);
            //add the new command to the list
            this->expressionCommandList.push_back(commandExp);
            //check if the key is in the map
        } else if (this->commandMap->isKeyInMap(*vectorIt)) {
            //new command expression
            commandExp = new CommandExpression(vectorIt,
                                               this->commandMap->getCommand(*vectorIt));
            //add to the list
            this->expressionCommandList.push_back(commandExp);
        }
        //to the end
        while ((*vectorIt) != ";"){
            vectorIt++;
        }
        //move the iterator 1
        vectorIt++;
    }
}