//
// Created by renana on 12/19/18.
//

#ifndef MILLSTONE_DATA_H
#define MILLSTONE_DATA_H


#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Data {
private:
    map<string,string> varPath;
    map<string,double > valuePath;
    map<string, double > symbleTable;
    int clientId;
    int serverId;
    vector<string> paths;
    bool shouldStop = true;
    mutable pthread_mutex_t mutex;

public:
    map<string,string> getVarPathMap();
    map<string,double > getsymbleTablehMap();
    Data();
    void setPaths();
    void setClientId(int id);
    void setServerId(int id);
    int getClientId() const;
    int getServerId() const;
    void addVarToPath(string var, string path);
    void addVarToSymbleTable(string var, double value);
    void updateSymbleTable(string var, double value);
    string getPath(string var);
    string getVarByPath(string path);
    double getValueOfVar(string var);
    string getPathOfVar(string var);
    bool isVar(string str);
    bool isVarPath(string str);
    vector<string> getPathList();
    double getValueByPath(string path);
    void updateValuePathMap(string path, double value);
    void setShouldStop(bool shouldStop);
    bool isShouldStop() const;

    pthread_mutex_t* getMutex() const;

};

#endif //MILLSTONE_DATA_H
