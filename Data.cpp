//
// Created by renana on 12/19/18.
//

#include "Data.h"


void Data::setClientId(int id) {
    this->clientId = id;
}

int Data::getClientId() const {
    return clientId;
}

void Data::updateSymbleTable(string var, double value) {
    symbleTable.find(var)->second = value;
}

void Data::addVarToPath(string var, string path) {
    varPath.insert(pair<string, string>(var, path));
}

void Data::addVarToSymbleTable(string var, double value) {
    symbleTable.insert(pair<string, double>(var, value));
}

map<string,double > Data::getsymbleTablehMap() {
    return symbleTable;
}