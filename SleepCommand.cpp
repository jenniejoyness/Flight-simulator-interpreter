//
// Created by jennie on 12/21/18.
//

#include <unistd.h>
#include "SleepCommand.h"

void SleepCommand::setParameters(vector<string> params, Data *data) {
    seconds = stoi(params[0]) * 1000;


}
void SleepCommand::doCommand() {
    sleep(seconds);
}