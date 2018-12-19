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
#include "ExpressionCommand.h"
#include "OpenDataServerCommand.h"

using namespace std;

class Reader {
    Data* data;
    map<string, ExpressionCommand*> commandMap;

public:
    Reader() {
        this->data = new Data();
        //todo insert commands
        commandMap.insert(pair<string,ExpressionCommand*>
                ("openDataServer",new ExpressionCommand(new OpenDataServerCommand)));
    }
    vector<string> split(string str);
    vector<string> lexer(string line);
    void parser(vector<string>);
    string addSpaces(string str);
    bool isOperator(char s);
    void addParameter(int j, int i, vector<string>&params, vector<string> line);
    vector<string> findParameters(vector<string> line);

};


#endif //MILLSTONE_COMMANDREADER_H
