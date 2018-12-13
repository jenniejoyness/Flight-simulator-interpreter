#include <iostream>
#include <fstream>
#include <vector>
#include "CommandReader.h"

using namespace std;

ifstream file;

int main() {
    file.open("script.txt", ifstream::in | ifstream::app);
    if (!file) {
        throw "Failed opening file";
    }
    CommandReader commandReader;
    string buffer;
    vector<string> data;
    while (getline(file,buffer)) {
        data = commandReader.lexer(buffer);
        commandReader.parser(data);

    }
}
