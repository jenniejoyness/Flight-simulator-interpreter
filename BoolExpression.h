//
// Created by renana on 12/20/18.
//

#ifndef MILLSTONE_BOOLEXPRESSION_H
#define MILLSTONE_BOOLEXPRESSION_H

#include <iostream>
#include <vector>
#include "Expression.h"
#include "Data.h"

using namespace std;
class BoolExpression {
    Expression* left;
    Expression* right;
    string conditionOperator;
    Data* data;
public:
    BoolExpression(vector<string> condition, Data* data);

    //bool isTrue()

};


#endif //MILLSTONE_BOOLEXPRESSION_H
