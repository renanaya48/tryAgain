#include "IfCommand.h"


/**
 * if the condition true- do the next.
 * @param script the iterator
 * @return 0 when finish
 */
int IfCommand::doCommand(vector<string>::iterator &script) {
    //if the condition is true
    if (this->boolExpression->calculateBool(this->symbolTable->getSymbols())) {
        //iterator on the list of the commands
        list<CommandExpression *>::iterator itr;
        //for all the list
        for (itr = this->commandExpressions.begin();
             itr != this->commandExpressions.end(); itr++) {
            //do the commands
            map<string, double> symbolMap = this->symbolTable->getSymbols();
            (*itr)->calculate(symbolMap);
        }
    }
    return 0;
}