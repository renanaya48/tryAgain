#ifndef PROJECT1_SETCONTROLCOMMAND_H
#define PROJECT1_SETCONTROLCOMMAND_H

#include "Command.h"
#include "SymbolTable.h"
#include "StringFlightControls.h"

/**
 * SetControlCommand class inheritors Command
 */
class SetControlCommand: public Command {
    StringFlightControls* stringControl;
    SymbolTable* symbols;

public:
    /**
     * constructor
     * @param stringC StringFlightControls
     * @param symbol SymbolTable
     */
    SetControlCommand(StringFlightControls* stringC, SymbolTable* symbol){
        this->symbols = symbol;
        this->stringControl = stringC;
    }
/**
 *
 * @param vectorIt the iterator
 * @return o when done
 */
    virtual int doCommand(vector<string>::iterator &vectorIt);

};


#endif //PROJECT1_SETCONTROLCOMMAND_H