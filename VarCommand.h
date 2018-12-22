#ifndef MILLSTONE_VARCOMMAND_H
#define MILLSTONE_VARCOMMAND_H


#include "Command.h"

class VarCommand: public Command {
    Data* data;
    string var;
    bool bind;
    string value;
public:
    void setParameters(vector<string> params, Data *data);
    void doCommand();
    void binding();
    void changingVarValue();
    //double findValue();

};


#endif //MILLSTONE_VARCOMMAND_H
