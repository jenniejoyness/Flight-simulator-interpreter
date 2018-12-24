//
// Created by renana on 12/13/18.
//

#ifndef MILLSTONE_COMMANDREADER_H
#define MILLSTONE_COMMANDREADER_H

#include <vector>
#include <iostream>
#include <map>
#include "Command.h"
#include "Expression.h"
#include "ExpressionCommand.h"

using namespace std;

class Reader {
    map<string, ExpressionCommand*> commandMap;
    Data* data;

public:
    Reader(Data* data, map<string,ExpressionCommand*> map);
    vector<string> split(string str, string del);
    vector<string> lexer(string line);
    void parser(vector<string>);
    string addSpaces(string str);
    bool isOperator(char s);
    void addParameter(int j, int i, vector<string>&params, vector<string> line);
    vector<string> findParameters(vector<string> line);
    void conditionParser(string str);
};



#endif //MILLSTONE_COMMANDREADER_H
