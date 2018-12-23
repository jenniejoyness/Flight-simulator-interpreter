//
// Created by renana on 12/19/18.
//

#ifndef MILLSTONE_CONNECTCOMMAND_H
#define MILLSTONE_CONNECTCOMMAND_H


#include "Command.h"
//TODO - CHECK IF CLASS WORKS!!!!!!!
class ConnectCommand : public Command {
private:
    string ipAddress;
    int port;
    Data* data;

public:
void setParameters(vector<string> params, Data *data);
void doCommand();
    struct MyParams {
        int port;
        string ipAddress;
        Data* data;
    };

};


#endif //MILLSTONE_CONNECTCOMMAND_H
