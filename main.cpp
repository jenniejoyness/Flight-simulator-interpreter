#include <iostream>
#include <fstream>
#include <vector>
#include "Reader.h"
#include "GetCommandMap.h"
#include "ShuntingYard.h"
#include <regex>

using namespace std;

ifstream file;
int main() {
    map<string, ExpressionCommand*> commandMap = GetCommandMap::getMap();
    Data* data = new Data;
/*    file.open("script.txt", ifstream::in | ifstream::app);
    if (!file) {
        throw "Failed opening file";
    }
    Reader* reader = new Reader(data, commandMap);
    string buffer;
    vector<string> lineData;
    string conditionCommand;
    bool bracketInNextLine = true;
    int counter = 0;
    bool inCondition = false;
    while (getline(file,buffer)) {

        if (strstr(buffer.c_str(), "while")!= NULL || strstr(buffer.c_str(), "if")!= NULL) {
            inCondition = true;
            if (strstr(buffer.c_str(), "{")!= NULL) {
                counter++;
                bracketInNextLine = false;
            }
        }
        if (inCondition) {
            if (bracketInNextLine && strstr(buffer.c_str(), "{")!= NULL) {
                counter++;
            } else if (strstr(buffer.c_str(), "}")!= NULL) {
                counter--;
            }
            conditionCommand += buffer + "#";

            if (counter == 0) {
                inCondition = false;
                reader->conditionParser(conditionCommand);
            }
        } else {
            lineData = reader->lexer(buffer);
            reader->parser(lineData);
        }


    }*/

ShuntingYard shuntingYard(data);
double e = shuntingYard.infixToPostfix("3*(-4354)")->Calculate();

    while (true) {}
    return 0;

}