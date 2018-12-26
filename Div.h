//
// Created by renana on 12/26/18.
//

#ifndef MILLSTONE_DIV_H
#define MILLSTONE_DIV_H

#include "BinaryExpression.h"

class Div : public BinaryExpression {

public:
    Div(Expression *leftExpression, Expression *rightExpression);
    double Calculate() override;
};

#endif //MILLSTONE_DIV_H
