//
// Created by renana on 12/22/18.
//

#include <cstring>
#include "ConditionCommand.h"

void ConditionCommand::setCommandsParam(vector<vector<string>> commands, map<string, ExpressionCommand*> commandMap) {
    this->commands = commands;
    this->commandMap = commandMap;
}

bool ConditionCommand::isConditionOperator(char c) {
    if (c == '<' || c == '<' || c == '<=' || c == '>=' || c == '=='|| c == '=!') {
        return true;
    }
    return false;
}

bool ConditionCommand::stuff(vector<string> condition) {
    //erase "while"
    condition.erase(condition.begin());
    if (condition.back() == "}") {
        condition.erase(condition.begin()+condition.size()-1);
    }

    //in shunting yard
   /* //check if there is a var in the string by searching in the map,
    //if it does - replace it in his value
    for (int j = 0; j < condition.size() ; ++j) {
        //if it found
        if (data->getsymbleTablehMap().find(condition[j]) != data->getsymbleTablehMap().end()) {
            condition[j] = to_string(data->getValueOfVar(condition[j]));
        }
    }*/

    int i = 0;
    string left;
    string right;
    while (!isConditionOperator(condition[i][0]) && i != condition.size()) {
        left += condition[i];
        i++;
    }
    string op = condition[i];
    while (!isConditionOperator(condition[i + 1][0]) && i != condition.size()) {
        right += condition[i];
        i++;
    }
    ShuntingYard shuntingYard(data);
    Expression* leftExp = shuntingYard.infixToPostfix(left);
    Expression* rightExp = shuntingYard.infixToPostfix(right);
    ConditionOperators conditionOperators;
    switch (op[0]) {
        case '<':
            return conditionOperators.smaller(leftExp, rightExp);
        case '<=':
            return conditionOperators.smallerEqual(leftExp, rightExp);
        case '>':
            return conditionOperators.bigger(leftExp, rightExp);
        case '>=':
            return conditionOperators.biggerEqual(leftExp, rightExp);
        case '==':
            return conditionOperators.equal(leftExp, rightExp);
        case '!=':
            return conditionOperators.notEqual(leftExp, rightExp);
    }
}

void ConditionCommand::commandExecute(vector<vector<string>> commands, Reader* reader) {
    for (auto command : commands) {
        //if the command is not a while command send to parser to execute
        if (strstr(command[0].c_str(), "while") == NULL && strstr(command[0].c_str(), "if") == NULL) {
            reader->parser(command);
            //otherwise send to condition parser
        } else {
            reader->conditionParser(command[0]);
        }
    }
}