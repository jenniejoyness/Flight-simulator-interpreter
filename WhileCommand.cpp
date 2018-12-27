#include <cstring>
#include "WhileCommand.h"
#include "ShuntingYard.h"
#include "ConditionOperators.h"


void WhileCommand::doCommand() {
    Reader *reader = new Reader(data, commandMap);
    while (calculateCondition(condition)) {
        commandExecute(commands, reader);
    }
    delete reader;
}


void WhileCommand::setParameters(vector<string> params, Data *data) {
    this->condition = params;
    this->data = data;
}
