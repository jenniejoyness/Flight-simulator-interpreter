#include <cstring>
#include "ConditionCommand.h"

void ConditionCommand::setCommandsParam(vector<vector<string>> commands, map<string, ExpressionCommand *> commandMap) {
    this->commands = commands;
    this->commandMap = commandMap;
}

bool ConditionCommand::isConditionOperator(char c) {
    if (c == '<' || c == '>' || c == '=' || c == '=' || c == '!') {
        return true;
    }
    return false;
}

bool ConditionCommand::calculateCondition(vector<string> condition) {
    //erase "while"
    condition.erase(condition.begin());
    if (condition.back() == "{") {
        condition.erase(condition.end());
    }

    int i = 0;
    string left;
    string right;
    string op;
    while (!isConditionOperator(condition[i][0]) && i != condition.size()) {
        left += condition[i];
        i++;
    }
    while (isConditionOperator(condition[i][0])) {
        op += condition[i];
        i++;
    }
    while (!isConditionOperator(condition[i][0]) && i != condition.size()) {
        right += condition[i];
        i++;
    }
    ShuntingYard shuntingYard(data);
    Expression *leftExp = shuntingYard.infixToPostfix(left);
    Expression *rightExp = shuntingYard.infixToPostfix(right);
    ConditionOperators conditionOperators;
    if (op == "<")
        return conditionOperators.smaller(leftExp, rightExp);
    if (op == "<=")
        return conditionOperators.smallerEqual(leftExp, rightExp);
    if (op == ">")
        return conditionOperators.bigger(leftExp, rightExp);
    if (op == ">=")
        return conditionOperators.biggerEqual(leftExp, rightExp);
    if (op == "==")
        return conditionOperators.equal(leftExp, rightExp);
    if (op == "!=")
        return conditionOperators.notEqual(leftExp, rightExp);
}

void ConditionCommand::commandExecute(vector<vector<string>> commands, Reader *reader) {
    for (auto command : commands) {
        //if the command is not a while command send to parser to execute
        if (strstr(command[0].c_str(), "while") == nullptr &&
            strstr(command[0].c_str(), "if") == nullptr) {
            reader->parser(command);
            //otherwise send to condition parser
        } else {
            reader->conditionParser(command[0]);
        }
    }
}