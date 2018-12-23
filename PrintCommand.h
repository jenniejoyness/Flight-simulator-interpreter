//
// Created by renana on 12/21/18.
//

#ifndef MILLSTONE_PRINTCOMMAND_H
#define MILLSTONE_PRINTCOMMAND_H

#include "Command.h"

class PrintCommand : public Command {
private:
    string print;
    Data* data;
public:
    void doCommand();
    void setParameters(vector<string> params, Data *data);
};
#endif //MILLSTONE_PRINTCOMMAND_H
