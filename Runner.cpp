#include <iostream>
#include <fstream>
#include <vector>
#include "Reader.h"
#include "GetCommandMap.h"
#include "ShuntingYard.h"
#include <regex>
#include <unistd.h>
#include "Runner.h"

void Runner::run(char *fileName) {
    GetCommandMap getCommandMap;
    map<string, ExpressionCommand*> commandMap = getCommandMap.getMap();
    Data* data = new Data();
    this->data = data;
    ifstream file;
    file.open(fileName, ifstream::in | ifstream::app);
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

        if (strstr(buffer.c_str(), "while")!= nullptr || strstr(buffer.c_str(), "if")!= nullptr) {
            inCondition = true;
            if (strstr(buffer.c_str(), "{")!= nullptr) {
                counter++;
                bracketInNextLine = false;
            }
        }
        if (inCondition) {
            if (bracketInNextLine && strstr(buffer.c_str(), "{")!= nullptr) {
                counter++;
            } else if (strstr(buffer.c_str(), "}")!= nullptr) {
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

    }

    data->setShouldStop(false);
    delete reader;
}

void Runner::exit() {
    close(data->getServerId());
    close(data->getClientId());
    delete(data);
}
