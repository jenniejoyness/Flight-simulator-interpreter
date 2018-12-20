#include <iostream>
#include <fstream>
#include <vector>
#include "Reader.h"
#include "ShuntingYard.h"
#include "Socket.h"
#include <regex>

using namespace std;

ifstream file;

int main() {
     file.open("script.txt", ifstream::in | ifstream::app);
       if (!file) {
           throw "Failed opening file";
       }
       Reader commandReader;
       string buffer;
       vector<string> data;
       while (getline(file,buffer)) {
           data = commandReader.lexer(buffer);
           commandReader.parser(data);


       }

    while (true) {}

    return 0;
}
