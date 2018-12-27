#ifndef MILLSTONE_PLUS_H
#define MILLSTONE_PLUS_H

#include "BinaryExpression.h"

class Plus : public BinaryExpression {

public:
    Plus(Expression *left, Expression *right);
    double Calculate () override;
};

#endif //MILLSTONE_PLUS_H
