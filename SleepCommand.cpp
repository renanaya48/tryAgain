#include <unistd.h>
#include "SleepCommand.h"


int SleepCommand::doCommand(vector<string>::iterator &vectorIt){
    int num = atoi((*vectorIt).c_str());
    sleep(num);
    vectorIt += 2;
}