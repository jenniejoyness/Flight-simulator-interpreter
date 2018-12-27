#ifndef MILLSTONE_DEFINEVARCOMMAND_H
#define MILLSTONE_DEFINEVARCOMMAND_H


#include "Command.h"

class DefineVarCommand : public Command {
    Data *data;
    string var;
    bool bind;
    string value;
public:
    void setParameters(vector<string> params, Data *data) override;

    void doCommand() override;

    void binding();

    void changingVarValue();

};

#endif //MILLSTONE_DEFINEVARCOMMAND_H
