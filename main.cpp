#include <iostream>
#include <fstream>
#include <vector>
#include "CommandReader.h"
#include "ShuntingYard.h"
#include <regex>

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
  /*  ShuntingYard sh;
    //
    vector<string> s  ;
    s.push_back("(");
    s.push_back("4");
    s.push_back("-");
    s.push_back("3");
    s.push_back(")");
    s.push_back("*");
    s.push_back("(");
    s.push_back("10");
    s.push_back("/");
    s.push_back("2");
    s.push_back(")");
    vector<string> g = sh.infixToPostfix(s);
    for (int i = 0; i < g.size(); ++i){
        //cout<<g[i];
    }
    Expression*e = sh.stringToExpression(g);
    cout<<e->Calculate()<<endl;*/
    // Target sequence
    return 0;
}
