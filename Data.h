//
// Created by renana on 12/19/18.
//

#ifndef MILLSTONE_DATA_H
#define MILLSTONE_DATA_H

#include <iostream>
#include <map>

using namespace std;

class Data {
private:
    map<string,string> varPath;
    map<string, double > symbleTable;
    int clientId;

public:
    map<string,string> getVarPathMap();
    map<string,double > getsymbleTablehMap();
    Data();
    void setClientId(int id);
    int getClientId() const;
    void addVarToPath(string var, string path);
    void addVarToSymbleTable(string var, double value);
    void updateSymbleTable(string var, double value);
    string getPath(string var);
    void setSymbleTable();
    void setVarPath();
    double getValueOfVar(string var);

};


#endif //MILLSTONE_DATA_H
