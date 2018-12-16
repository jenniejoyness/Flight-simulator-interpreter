
#ifndef MILLSTONE_SHUNTINGYARD_H
#define MILLSTONE_SHUNTINGYARD_H
using namespace std;

#include <iostream>
#include "Expression.h"

class ShuntingYard {
public:
    int getPriority(char C);
    string infixToPostfix(string infix);
    Expression* stringToExpression(string postfix);
};


#endif //MILLSTONE_SHUNTINGYARD_H
