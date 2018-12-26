//
// Created by renana on 12/26/18.
//

#ifndef MILLSTONE_PLUS_H
#define MILLSTONE_PLUS_H

#include "BinaryExpression.h"

class Plus : public BinaryExpression {

public:
    Plus(Expression *left, Expression *right);
    double Calculate () override;
};

#endif //MILLSTONE_PLUS_H
