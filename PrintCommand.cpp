//
// Created by renana on 12/21/18.
//

#include "PrintCommand.h"

void PrintCommand::doCommand() {
    //if th print object is var replace it in his value
    if (print[0] == '"' && print[print.size() - 1] == '"') {
        print = print.substr(1 , print.size() - 2);
    }
    /*if (data->getsymbleTablehMap().find(print) != data->getsymbleTablehMap().end()) {
        print = to_string(data->getValueOfVar(print));
    }*/
    cout << print << endl;
}

void PrintCommand::setParameters(vector<string> params, Data *data) {
    if (params.size() != 1) {
        throw "Invalid number of arguments";
    }
    this->print = params[0];
    this->data = data;
}