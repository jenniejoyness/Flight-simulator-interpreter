//
// Created by jennie on 12/17/18.
//

#ifndef MILLSTONE_OPENDATASERVERCOMMAND_H
#define MILLSTONE_OPENDATASERVERCOMMAND_H
#include "Command.h"
#include "Data.h"

class OpenDataServerCommand: public Command {
    int port;
    int HZ;
    Data* data;
public:
    void doCommand();
    void setParameters(vector<string> params, Data* data);
    //void* openServer(void* arg);

    struct MyParams {
        int port;
        int hz;
        Data* data;
    };


};


#endif //MILLSTONE_OPENDATASERVERCOMMAND_H
