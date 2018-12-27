#include <iostream>
#include <fstream>
#include <vector>
#include "Reader.h"
#include "GetCommandMap.h"
#include "ShuntingYard.h"
#include <regex>
#include <unistd.h>

using namespace std;

ifstream file;
int main(int argc, char* argv[]) {
    map<string, ExpressionCommand*> commandMap = GetCommandMap::getMap();
    Data* data = new Data();
    file.open(argv[1], ifstream::in | ifstream::app);
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

    cout<<"finished"<<endl;
    delete reader;
    return 0;

}