#include <vector>
#include "Data.h"

Data::Data(){
    paths.emplace_back("\"/instrumentation/airspeed-indicator/indicated-speed-kt\"");
    paths.emplace_back("\"/instrumentation/altimeter/indicated-altitude-ft\"");
    paths.emplace_back("\"/instrumentation/altimeter/pressure-alt-ft\"");
    paths.emplace_back("\"/instrumentation/attitude-indicator/indicated-pitch-deg\"");
    paths.emplace_back("\"/instrumentation/attitude-indicator/indicated-roll-deg\"");
    paths.emplace_back("\"/instrumentation/attitude-indicator/internal-pitch-deg\"");
    paths.emplace_back("\"/instrumentation/attitude-indicator/internal-roll-deg\"");
    paths.emplace_back("\"/instrumentation/encoder/indicated-altitude-ft\"");
    paths.emplace_back("\"/instrumentation/encoder/pressure-alt-ft\"");
    paths.emplace_back("\"/instrumentation/gps/indicated-altitude-ft\"");
    paths.emplace_back("\"/instrumentation/gps/indicated-ground-speed-kt\"");
    paths.emplace_back("\"/instrumentation/gps/indicated-vertical-speed</node>\"");
    paths.emplace_back("\"/instrumentation/heading-indicator/indicated-heading-deg\"");
    paths.emplace_back("\"/instrumentation/magnetic-compass/indicated-heading-deg\"");
    paths.emplace_back("\"/instrumentation/slip-skid-ball/indicated-slip-skid\"");
    paths.emplace_back("\"/instrumentation/turn-indicator/indicated-turn-rate\"");
    paths.emplace_back("\"/instrumentation/vertical-speed-indicator/indicated-speed-fpm\"");
    paths.emplace_back("\"/controls/flight/aileron\"");
    paths.emplace_back("\"/controls/flight/rudder\"");
    paths.emplace_back("\"/controls/flight/flaps\"");
    paths.emplace_back("\"/controls/engines/engine/throttle\"");
    paths.emplace_back("\"/engines/engine/rpm\"");
    setPaths();
}

/*
 * in the valuePath map, inserting 0 as default
 */
void Data::setPaths() {
    for (int i = 0; i < paths.size(); ++i) {
        valuePath.insert(pair<string,double>(paths[i],0));
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

/*
 * find the value of the var from the map and return
 */
double Data::getValueOfVar(string var) {
    return symbleTable.find(var)->second;
}

/*
 * returns path of var
 */
string Data::getPathOfVar(string var) {
    return varPath.find(var)->second;
}

/*
 * returns true if str is a var
 */
bool Data::isVar(string str) {
    for (auto pair: symbleTable){
        if(pair.first == str){
            return true;
        }
    }
    return false;
}
vector<string> Data::getPathList() {
    return paths;
}

double Data::getValueByPath(string path) {
    return valuePath.find(path)->second;
}

string Data::getVarByPath(string path) {
    for (auto pair: varPath){
        if(pair.second == path){
            return pair.first;
        }
    }

}

void Data::updateValuePathMap(string path, double value) {
    valuePath.find(path)->second = value;
}
