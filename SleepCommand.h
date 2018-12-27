#ifndef MILLSTONE_SLEEPCOMMAND_H
#define MILLSTONE_SLEEPCOMMAND_H


#include "Command.h"

class SleepCommand : public Command {
    int seconds;
    Data *data;
public:
    void setParameters(vector<string> params, Data *data) override;

    void doCommand() override;
};


#endif //MILLSTONE_SLEEPCOMMAND_H
