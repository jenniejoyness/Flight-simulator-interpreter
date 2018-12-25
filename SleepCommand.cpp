//
// Created by jennie on 12/21/18.
//

#include <unistd.h>
#include "SleepCommand.h"
#include "ShuntingYard.h"

void SleepCommand::setParameters(vector<string> params, Data *data) {
    ShuntingYard shuntingYard(data);
    seconds = (int)shuntingYard.infixToPostfix(params[0])->Calculate() * 1000;


}
void SleepCommand::doCommand() {
    sleep(seconds);
}