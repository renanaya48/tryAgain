#include <string>
#include <vector>

#ifndef PROJECT1_COMMAND_H
#define PROJECT1_COMMAND_H

#include <map>
#include <mutex>

using namespace std;

/**
 * Command class.
 */
class Command {
public:
    //member
    map<string, double> symbolTable;
    //std::map<string, Command*> commands;
public:
    /**
     * constructor
     */
    Command();
    /**
     *
     * @param vectorIt the iterator that point to the
     *                  place at the vector
     * @return o if succeed
     */
    virtual int doCommand(vector<string>::iterator &vectorIt) = 0;

};


#endif //PROJECT1_COMMAND_H
