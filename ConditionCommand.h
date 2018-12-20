//
// Created by jennie on 12/20/18.
//

#ifndef MILLSTONE_CONDITIONCOMMAND_H
#define MILLSTONE_CONDITIONCOMMAND_H

#include "Command.h"

class ConditionCommand : public Command {
protected:
    vector<string> condition;
    vector<vector<string>> commands;
    Data* data;
public:
    void setCommandsParam(vector<vector<string>> commands) {
        this->commands = commands;
    }

};
#endif //MILLSTONE_CONDITIONCOMMAND_H
