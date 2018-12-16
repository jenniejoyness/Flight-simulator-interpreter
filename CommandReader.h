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

using namespace std;

class CommandReader {
    map<string, Command> commandMap;
    map<string, double> symbolTable;

public:
    CommandReader() {
        commandMap.insert(pair<string, Command>())
    }
    vector<string> lexer(string line);
    void parser(vector<string>                      );

};


#endif //MILLSTONE_COMMANDREADER_H
