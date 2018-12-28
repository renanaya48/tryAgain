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
#include "string"
#include "CheckConnection.h"
#include "StringFlightControls.h"

#ifndef PROJECT1_CONNECTCOMMAND_H
#define PROJECT1_CONNECTCOMMAND_H

using namespace std;
/**
 * class ConnectCommand inheritors Command
 */
class ConnectCommand : public Command {
    //members
    CheckConnection* isConnected;
    StringFlightControls* flightString;

public:
/**
 * connection client
 * @param args agrs
 * @return
 */
    ConnectCommand(CheckConnection* check, StringFlightControls* flightStr);
 /**
 *
 * @param vectorIt the iterator
 * @return 0 when done
 */
    virtual int doCommand(vector<string>::iterator &vectorIt);
};

#endif //PROJECT1_CONNECTCOMMAND_H
