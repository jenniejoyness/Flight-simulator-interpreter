//
// Created by jennie on 12/20/18.
//

#include <cstring>
#include "IfCommand.h"

void IfCommand::doCommand() {
    Reader *reader = new Reader(data, commandMap);
    if (true/*stuff(condition)*/) {
        commandExecute(commands, reader);
    }
}

void IfCommand::setParameters(vector<string> params, Data *data) {
    this->condition = params;
    this->data = data;
}
