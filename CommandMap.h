#include "Command.h"
#include "map"

#ifndef PROJECTNUM1_COMMANDMAP_H
#define PROJECTNUM1_COMMANDMAP_H

/**
 * CommandMap class
 */
class CommandMap {
    //member
    map<string, Command *> commandMAp;
public:
    /**
     * constructor
     */
    CommandMap();
    /**
     * add a command to the map
     * @param key  the key to add to the map
     * @param command  the command to add to the map
     */
    void addCommand(string key,Command* command);
    /**
     * return the command according to the asked key
     * @param key the key from the map
     * @return the command according to the key
     */
    Command* getCommand(string key);
    /**
     * the function gets a key and checks if it in the map
     * @param key the key to check if in the map
     * @return true if the key in the map, fale otherwise
     */
    bool isKeyInMap(string key);
};


#endif //PROJECTNUM1_COMMANDMAP_H
