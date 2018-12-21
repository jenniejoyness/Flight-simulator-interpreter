#include <iostream>
#include <fstream>
#include <vector>
#include "Reader.h"
#include "ShuntingYard.h"
#include "Socket.h"
#include "WhileCommand.h"
#include <regex>

using namespace std;

ifstream file;

int main() {
    file.open("script.txt", ifstream::in | ifstream::app);
    if (!file) {
        throw "Failed opening file";
    }

    Reader* reader = new Reader();
    string buffer;
    vector<string> data;
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
            data = reader->lexer(buffer);
            reader->parser(data);
        }


    }

    while (true) {}
    return 0;

}
