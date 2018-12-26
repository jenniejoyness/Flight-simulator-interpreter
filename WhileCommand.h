//
// Created by jennie on 12/20/18.
//

#ifndef MILLSTONE_WHILECOMMAND_H
#define MILLSTONE_WHILECOMMAND_H
#include "ConditionCommand.h"

class WhileCommand : public ConditionCommand {
public:
    void doCommand() override;
    void setParameters(vector<string> params, Data *data) override;
};


#endif //MILLSTONE_WHILECOMMAND_H
