
#ifndef MILLSTONE_SHUNTINGYARD_H
#define MILLSTONE_SHUNTINGYARD_H
using namespace std;

#include <iostream>
#include "Expression.h"
#include <vector>

class ShuntingYard {
public:
    int getPriority(string C);
    //TODO - send with spaces inbetween chars
    vector<string>  infixToPostfix(vector<string> infix);
    Expression* stringToExpression(vector<string>  postfix);
    bool isOperator(string s);
};


#endif //MILLSTONE_SHUNTINGYARD_H
