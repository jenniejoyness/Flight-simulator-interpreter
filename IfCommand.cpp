#include <cstring>
#include "IfCommand.h"

void IfCommand::doCommand() {
    Reader *reader = new Reader(data, commandMap);
    if (calculateCondition(condition)) {
        commandExecute(commands, reader);
    }
    delete reader;
}

void IfCommand::setParameters(vector<string> params, Data *data) {
    this->condition = params;
    this->data = data;
}
