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
    void doCommand() override;
    void setParameters(vector<string> params, Data* data) override;
    ~OpenDataServerCommand();

    struct MyParams {
        Data* data;
    };


};


#endif //MILLSTONE_OPENDATASERVERCOMMAND_H
