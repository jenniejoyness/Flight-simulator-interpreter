//
// Created by jennie on 12/17/18.
//

#ifndef MILLSTONE_OPENDATASERVERCOMMAND_H
#define MILLSTONE_OPENDATASERVERCOMMAND_H
#include "Command.h"

class OpenDataServerCommand: public Command {
    int port;
    int HZ;
public:
    void doCommand();
    void setParameters(vector<string> params);
    //void* openServer(void* arg);



};


#endif //MILLSTONE_OPENDATASERVERCOMMAND_H
