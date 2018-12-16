
#include "CommandReader.h"


vector<string> CommandReader::lexer(string line) {
    vector<string> data;
    size_t pos = 0;
    string delimiter = " ";
    while ((pos = line.find(delimiter)) != string::npos) {
        data.push_back(line.substr(0, pos));
        line.erase(0, pos + delimiter.length());
    }
    data.push_back(line.substr(0, pos));
    return data;
}

void CommandReader::parser(vector<string> lineData) {
    Command* command = commandMap.find(lineData[0])->second;
    lineData.erase(lineData.begin());
    command->doCommand(lineData);
}