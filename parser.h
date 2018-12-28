#ifndef PROJECT1_PARSER_H
#define PROJECT1_PARSER_H

#include <map>
#include "Command.h"
#include <vector>
#include "OpenServerCommand.h"
#include "ConnectCommand.h"
#include "VarCommand.h"
#include "SymbolTable.h"
#include "CheckConnection.h"
#include "FlightValueMap.h"
#include "PathMap.h"
#include "StringFlightControls.h"
#include "CommandMap.h"
#include "ConditionParser.h"
#include "SleepCommand.h"

using namespace std;

/**
 * parser class
 */
class parser {
    CommandMap* commands;
    SymbolTable* symbols;
    CheckConnection* connection;
    FlightValueMap* valueMap;
    PathMap* bindMap;
    StringFlightControls* stringControl;


public:
    /**
     * constructor
     */
    parser();
    /**
     * the function gets a vector and parser it by words
     * @param v the vector the function gets
     */
    void runParser(vector<string> v);
};


#endif //PROJECT1_PARSER_H