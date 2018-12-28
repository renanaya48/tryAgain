#include "LoopCommand.h"

/**
 * do command
 * @param script  the iterator
 * @return 0 when finish
 */
int LoopCommand::doCommand(vector<string>::iterator &script) {
    list<CommandExpression*> tempList;
    while (this->boolExpression->calculateBool(
            this->symbolTable->getSymbols())) {
        tempList =this->commandExpressions;
        list<CommandExpression *>::iterator itr;
        for (itr = tempList.begin();
             itr !=tempList.end(); itr++) {
            map<string, double> symbolMap = this->symbolTable->getSymbols();
            (*itr)->calculate(symbolMap);
        }

    }
}