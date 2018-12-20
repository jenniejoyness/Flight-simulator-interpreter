
#include <vector>
#include "Data.h"

Data::Data(){
    setSymbleTable();
}

void Data::setSymbleTable() {
    vector<string> vars;
    for (int i = 0; i < vars.size(); ++i) {
        symbleTable.insert(pair<string,double>(vars[i],0));
    }

}
void Data::setVarPath() {
    /*
     *
    this->pathRead.insert(pair<string,double>(",0));
    this->pathRead.insert(pair<string,double>(",0));
    this->pathRead.insert(pair<string,double>(,0));
    this->pathRead.insert(pair<string,double>(,0));
    this->pathRead.insert(pair<string,double>("/instrumentation/encoder/indicated-altitude-ft",0));
    this->pathRead.insert(pair<string,double>("/instrumentation/encoder/pressure-alt-ft",0));
    this->pathRead.insert(pair<string,double>("/instrumentation/gps/indicated-altitude-ft",0));
    this->pathRead.insert(pair<string,double>("/instrumentation/gps/indicated-ground-speed-kt",0));
    this->pathRead.insert(pair<string,double>("/instrumentation/gps/indicated-vertical-speed",0));
    this->pathRead.insert(pair<string,double>("/instrumentation/heading-indicator/indicated-heading-deg",0));
    this->pathRead.insert(pair<string,double>("/instrumentation/magnetic-compass/indicated-heading-deg",0));
    this->pathRead.insert(pair<string,double>("/instrumentation/slip-skid-ball/indicated-slip-skid",0));
    this->pathRead.insert(pair<string,double>("/instrumentation/turn-indicator/indicated-turn-rate",0));
    this->pathRead.insert(pair<string,double>("/instrumentation/vertical-speed-indicator/indicated-speed-fpm",0));
    this->pathRead.insert(pair<string,double>("/controls/flight/aileron",0));
    this->pathRead.insert(pair<string,double>("/controls/flight/elevator",0));
    this->pathRead.insert(pair<string,double>("/controls/flight/rudder",0));
    this->pathRead.insert(pair<string,double>("/controls/flight/flaps",0));
    this->pathRead.insert(pair<string,double>("/controls/engines/engine/throttle",0));
    this->pathRead.insert(pair<string,double>("/engines/engine/rpm",0));
     */
    vector<string> vars;
    vector<string> paths ={"/instrumentation/airspeed-indicator/indicated-speed-kt",
                           "/instrumentation/altimeter/indicated-altitude-ft"
                           "/instrumentation/altimeter/pressure-alt-ft",
                            "/instrumentation/attitude-indicator/indicated-pitch-deg",
                            "/instrumentation/attitude-indicator/indicated-roll-deg",
                           "/instrumentation/attitude-indicator/internal-pitch-deg",
                           "/instrumentation/attitude-indicator/internal-roll-deg",
                           };
    for (int i = 0; i < vars.size(); ++i) {
        varPath.insert(pair<string,string>(vars[i],paths[i]));
    }

}
/*
 * set the socket id of the client
 */
void Data::setClientId(int id) {
    this->clientId = id;
}

/*
 * return the socket id of the client
 */
int Data::getClientId() const {
    return clientId;
}

/*
 * update the value(double) in the symboltable map
 */
void Data::updateSymbleTable(string var, double value) {
    symbleTable.find(var)->second = value;
}

/*
 * add a var pair (var,path) to pathmap
 */
void Data::addVarToPath(string var, string path) {
    varPath.insert(pair<string, string>(var, path));
}

/*
 * add var pair(var,value) to the symbolmap
 */
void Data::addVarToSymbleTable(string var, double value) {
    symbleTable.insert(pair<string, double>(var, value));
}
/*
 * return the whole symbol table map
 */
map<string,double > Data::getsymbleTablehMap() {
    return symbleTable;
}

/*
 * find the path of the var from the map and return
 */
string Data::getPath(string var) {
    return varPath.find(var)->second;
}