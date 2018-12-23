//
// Created by renana on 12/19/18.
//

#ifndef MILLSTONE_DATA_H
#define MILLSTONE_DATA_H

#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
using namespace std;

class Data {
private:
    map<string,string> varPath;
    unordered_map<string,double > valuePath;
    map<string, double > symbleTable;
    int clientId;
    vector<string> paths;

public:
    map<string,string> getVarPathMap();
    map<string,double > getsymbleTablehMap();
    Data();
    void setPaths();
    void setClientId(int id);
    int getClientId() const;
    void addVarToPath(string var, string path);
    void addVarToSymbleTable(string var, double value);
    void updateSymbleTable(string var, double value);
    string getPath(string var);
    double getValueOfVar(string var);
    string getPathOfVar(string var);
    bool isVar(string str);
    vector<string> getPathList();

};

#endif //MILLSTONE_DATA_H
