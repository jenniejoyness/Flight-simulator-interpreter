//
// Created by renana on 12/13/18.
//

#ifndef MILLSTONE_COMMANDREADER_H
#define MILLSTONE_COMMANDREADER_H

#include <vector>
#include <iostream>
#include <hash_map>
#include <map>
#include "Command.h"
#include "Expression.h"

using namespace std;

class CommandReader {
    map<string, Expression*> commandMap;
    map<string, double> symbolTable;

public:
    CommandReader() {
        //commandMap.insert(pair<string, Command>())
    }
    vector<string> lexer(string line);
    void parser(vector<string>);
    vector<string> openDataServerRegex(string line);

};


#endif //MILLSTONE_COMMANDREADER_H
