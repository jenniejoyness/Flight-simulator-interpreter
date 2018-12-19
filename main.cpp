#include <iostream>
#include <fstream>
#include <vector>
#include "Reader.h"
#include "ShuntingYard.h"
#include "ServerSocket.h"
#include "ClientSocket.h"
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
    //ShuntingYard sh;
    //
    //string s = "( 1 + 4 ) * 9";
    //Expression*e = sh.infixToPostfix(s);
//    for (int i = 0; i < g.size(); ++i){
//        //cout<<g[i];
//    }
//    Expression*e = sh.;
    //cout<<e->Calculate()<<endl;
    // Target sequence
//    Reader reader;
//    string s = "rudder = bind ""abc";
//    string g = reader.addSpaces(s);
//    cout<<g;
//    vector<string> f = reader.lexer(g);
//    vector<string> h = reader.findParameters(f);
//    //reader.parser(h);
//    vector<int > sd = {1, 2,4};
//    sd.erase(sd.begin() +1);

    //Socket *s = new Socket();
    //s->DataReader();
    //ClientSocket::openSocket(nullptr);
//    Data* d = new Data;
//    d->addVarToSymbleTable("a",8);
//    d->addVarToSymbleTable("b", 7);
//    d->updateSymbleTable("a", 6);

    while (true) {}

    return 0;
}
