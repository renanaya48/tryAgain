#include "Command.h"
#include <iostream>
#include <thread>
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>
#include <netinet/in.h>
#include <string.h>
#include <sys/socket.h>
#include <functional>
#include <vector>
#include <pthread.h>
#include "CheckConnection.h"

#ifndef PROJECT1_OPENSERVERCOMMAND_H
#define PROJECT1_OPENSERVERCOMMAND_H

#include "FlightValueMap.h"

using namespace std;

/**
 * OpenServerCommand class inheritors Command
 */
class OpenServerCommand : public Command {
    CheckConnection* isConnected;
    FlightValueMap* valueMap;

public:
    /**
     * constructor
     * @param check CheckConnection
     * @param vaules FlightValueMap
     */
    OpenServerCommand(CheckConnection* check, FlightValueMap* vaules);
    /**
     *
     * @param vectorIt the iterator
     * @return 0 when done
     */
    virtual int doCommand(vector<string>::iterator &vectorIt);
};


#endif //PROJECT1_OPENSERVERCOMMAND_H