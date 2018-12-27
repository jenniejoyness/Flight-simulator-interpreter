#ifndef MILLSTONE_CONNECTCOMMAND_H
#define MILLSTONE_CONNECTCOMMAND_H


#include "Command.h"
class ConnectCommand : public Command {
private:
    string ipAddress;
    int port;
    Data* data;

public:
void setParameters(vector<string> params, Data *data) override;
void doCommand() override;

    struct MyParams {
        int port;
        string ipAddress;
        Data* data;
    };

};


#endif //MILLSTONE_CONNECTCOMMAND_H
