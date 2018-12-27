#ifndef MILLSTONE_GETCOMMANDMAP_H
#define MILLSTONE_GETCOMMANDMAP_H
#include <map>
#include <iostream>
#include "ExpressionCommand.h"

using namespace std;

class GetCommandMap {
    map<string, ExpressionCommand *> commandMap;
public:
    map<string, ExpressionCommand *> getMap();
    ~GetCommandMap();
};


#endif //MILLSTONE_GETCOMMANDMAP_H
