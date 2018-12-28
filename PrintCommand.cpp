#include "PrintCommand.h"

int PrintCommand::doCommand(vector<string>::iterator &vectorIt) {
    string printString = "";
    if ((*vectorIt)[0] == '\"') {
        while ((*vectorIt) != ";") {
            printString += (*vectorIt);
            vectorIt++;
        }
        printString=printString.substr(1, printString.length() - 2);
    } else {
        printString = (*vectorIt);
    }
    cout << printString << endl;
    vectorIt++;
    return 0;
}