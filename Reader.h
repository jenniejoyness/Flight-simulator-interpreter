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
    map<string, ExpressionCommand*> commandMap;
    Data* data;

public:
    Reader();
    vector<string> split(string str, string del);
    vector<string> lexer(string line);
    void parser(vector<string>);
    vector<string> openDataServerRegex(string line);
    string addSpaces(string str);
    bool isOperator(char s);
    void addParameter(int j, int i, vector<string>&params, vector<string> line);
    vector<string> findParameters(vector<string> line);
    void conditionParser(string str);

};


#endif //MILLSTONE_COMMANDREADER_H
