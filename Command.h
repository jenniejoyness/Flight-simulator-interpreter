#ifndef MILLSTONE_COMMAND_H
#define MILLSTONE_COMMAND_H

#include <iostream>
#include <vector>
#include "Data.h"

using namespace std;

class Command {
public:
    virtual void doCommand() = 0;

    virtual void setParameters(vector<string> params, Data *data) = 0;
    // virtual ~Command() = default;
};

#endif //MILLSTONE_COMMAND_H
