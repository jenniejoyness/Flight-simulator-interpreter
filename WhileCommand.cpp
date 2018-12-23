//
// Created by jennie on 12/20/18.
//

#include <cstring>
#include "WhileCommand.h"
#include "ShuntingYard.h"
#include "ConditionOperators.h"


void WhileCommand::doCommand() {
    Reader *reader = new Reader(data, commandMap);
    while (true/*stuff(condition)*/) {
        commandExecute(commands, reader);
    }
}


void WhileCommand::setParameters(vector<string> params, Data *data) {
    this->condition = params;
    this->data = data;
}
