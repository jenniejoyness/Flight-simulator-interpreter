#ifndef MILLSTONE_CONDITIONOPERATORS_H
#define MILLSTONE_CONDITIONOPERATORS_H


#include "Expression.h"
#include "Data.h"

class ConditionOperators {
public:
    bool smaller(Expression *left, Expression *right);

    bool bigger(Expression *left, Expression *right);

    bool smallerEqual(Expression *left, Expression *right);

    bool biggerEqual(Expression *left, Expression *right);

    bool equal(Expression *left, Expression *right);

    bool notEqual(Expression *left, Expression *right);

};


#endif //MILLSTONE_CONDITIONOPERATORS_H
