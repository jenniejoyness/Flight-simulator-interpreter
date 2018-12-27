#ifndef MILLSTONE_GETCOMMANDMAP_H
#define MILLSTONE_GETCOMMANDMAP_H
#pragma once

#include <map>
#include <iostream>
#include "ExpressionCommand.h"

using namespace std;

class GetCommandMap {
public:
    static map<string, ExpressionCommand *> getMap();
};


#endif //MILLSTONE_GETCOMMANDMAP_H
