#include <iostream>
#include <fstream>
#include <vector>
#include "CommandReader.h"
#include "ShuntingYard.h"

using namespace std;

ifstream file;

int main() {
 /*   file.open("script.txt", ifstream::in | ifstream::app);
    if (!file) {
        throw "Failed opening file";
    }
    CommandReader commandReader;
    string buffer;
    vector<string> data;
    while (getline(file,buffer)) {
        data = commandReader.lexer(buffer);
        commandReader.parser(data);

    }*/
    ShuntingYard sh;
    string s = ("(2-3)*4") ;
    cout << sh.infixToPostfix(s) << std::endl;
    return 0;
}
