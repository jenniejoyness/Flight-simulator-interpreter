//
// Created by renana on 12/18/18.
//

#include "DefineVarCommand.h"

#include <cstring>
#include "DefineVarCommand.h"
#include "ShuntingYard.h"
#include "EqualCommand.h"

void DefineVarCommand::setParameters(vector<string> params, Data *data) {
    ShuntingYard shuntingYard(data);
    //if has bind in command
    if(params.size() == 4){
        this->bind = true;
        //this->value = to_string(shuntingYard.infixToPostfix(params[3])->Calculate());
        this->value = params[3];
        //does not have bind
    } else {
        this->bind = false;
        this->value = to_string(shuntingYard.infixToPostfix(params[2])->Calculate());
    }
    this->var = params[0];
    this->data = data;

}
void DefineVarCommand::doCommand() {
    if(bind) {
        binding();
    } else {
        changingVarValue();
    }
}

/*
 * add path to var
 */
void DefineVarCommand::binding() {
    //todo if path not in valuepath?
    //found brackets, need to add path
    if(value.find("\"") == 0) {
        data->addVarToPath(var,value);
        // add to symbol table
        data->addVarToSymbleTable(var,data->getValueByPath(value));
    } else {
        //find path to value var
        string path = data->getPathOfVar(value);
        data->addVarToPath(var,path);
        // add to symbol table
        data->addVarToSymbleTable(var,data->getValueByPath(path));
    }
}

/*
 * if is var gear, send to equal command
 * if is not var gear - add to symbol table
 */
void DefineVarCommand::changingVarValue() {
    //if found the var in symbol table - send to equal command
    if(data->isVar(var)){
        //calling equal command
        Command* equalCommand = new EqualCommand();
        vector<string> params;
        params.push_back(var);
        params.push_back(value);
        equalCommand->setParameters(params, data);
        equalCommand->doCommand();
        //is a new var in the symbol map, need to add to map
    } else {
        data->addVarToSymbleTable(var,stoi(value));
    }

}