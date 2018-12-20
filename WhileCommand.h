//
// Created by jennie on 12/20/18.
//

#ifndef MILLSTONE_WHILECOMMAND_H
#define MILLSTONE_WHILECOMMAND_H


#include "ConditionCommand.h"

class WhileCommand : ConditionCommand {
    void doCommand();
    void setParameters(vector<string> params, Data *data);
};


#endif //MILLSTONE_WHILECOMMAND_H
