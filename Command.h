//
// Created by renana on 12/13/18.
//

#ifndef MILLSTONE_COMMAND_H
#define MILLSTONE_COMMAND_H
#include <iostream>
#include <vector>
using namespace std;

class Command{
public:
    virtual void doCommand() = 0;
    virtual void setParameters(vector<string> params) = 0;
};
#endif //MILLSTONE_COMMAND_H
