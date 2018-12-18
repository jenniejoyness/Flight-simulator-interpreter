//
// Created by renana on 12/18/18.
//

#ifndef MILLSTONE_DEFINEVARCOMMAND_H
#define MILLSTONE_DEFINEVARCOMMAND_H


#include "Command.h"

class DefineVarCommand : public Command {
private:
    string varName;
    bool bind;
    string path;
public:
    void doCommand();
    void setParameters(vector<string> params);
};


#endif //MILLSTONE_DEFINEVARCOMMAND_H
