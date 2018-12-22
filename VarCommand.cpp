#include <cstring>
#include "VarCommand.h"
#include "ShuntingYard.h"
#include "EqualCommand.h"

void VarCommand::setParameters(vector<string> params, Data *data) {
    ShuntingYard shuntingYard;
    //if has bind in command
    if(params.size() == 4){
        this->bind = true;
        this->value = to_string(shuntingYard.infixToPostfix(params[3])->Calculate());
        //does not have bind
    } else{
        this->bind = false;
        this->value = to_string(shuntingYard.infixToPostfix(params[2])->Calculate());
    }
    this->var = params[0];
    this->data = data;

}
void VarCommand::doCommand() {
    if(bind){
        binding();
    }else{
        changingVarValue();
    }
}

void VarCommand::binding() {
    //found brackets, need to add path
    if(value.find("\"") == 0){
        data->addVarToPath(var,value);
        //the value is a var in symbol table
    } else if (data->getsymbleTablehMap().find(value) != data->getsymbleTablehMap().end()) {
        //find the path of the var in- var value
        data->addVarToPath(var,data->getPathOfVar(value));
    }

}

void VarCommand::changingVarValue() {
    //if found the var in symbol table - send to equal command
    if(data->getsymbleTablehMap().find(var) != data->getsymbleTablehMap().end()){
        //calling equal command
        Command* equalCommand = new EqualCommand();
        vector<string> params = {var,value};
        setParameters(params, data);
        equalCommand->doCommand();
        //is a new var in the symbol map, need to add to map
    } else {
        data->addVarToSymbleTable(var,stoi(value));
    }

}

/*
double VarCommand::findValue() {
    ShuntingYard shuntingYard;
    vector<string> chunks = shuntingYard.splitString(value);
    for (int i = 0; i < chunks.size() ; ++i) {
        if(data->getsymbleTablehMap().find(value) != data->getsymbleTablehMap().end()){

        }
    }
    //double this->value = shuntingYard.infixToPostfix(params[1])->Calculate();
    //if the value is a var in the map return the value
    if(data->getsymbleTablehMap().find(value) != data->getsymbleTablehMap().end()){
        return data->getValueOfVar(value);
    } else{
        return stoi(value);
    }
    
}*/
