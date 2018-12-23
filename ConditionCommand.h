//
// Created by jennie on 12/20/18.
//

#ifndef MILLSTONE_CONDITIONCOMMAND_H
#define MILLSTONE_CONDITIONCOMMAND_H

#include "Command.h"
#include "ShuntingYard.h"
#include "ConditionOperators.h"
#include "ExpressionCommand.h"
#include "Reader.h"

class ConditionCommand : public Command {
protected:
    vector<string> condition;
    vector<vector<string>> commands;
    Data* data;
    map<string, ExpressionCommand*> commandMap;
public:

    void setCommandsParam(vector<vector<string>> commands, map<string, ExpressionCommand*> commandMap);
    bool isConditionOperator(char c);
    bool stuff(vector<string> condition);
    void commandExecute(vector<vector<string>> commands, Reader* reader);

};
#endif //MILLSTONE_CONDITIONCOMMAND_H
