//
// Created by jennie on 12/20/18.
//

#ifndef MILLSTONE_IFCOMMAND_H
#define MILLSTONE_IFCOMMAND_H

#include "ConditionCommand.h"
#include "Reader.h"

class IfCommand : public ConditionCommand{
public:
    void doCommand() override;
    void setParameters(vector<string> params, Data *data) override;
};


#endif //MILLSTONE_IFCOMMAND_H
