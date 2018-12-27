#ifndef MILLSTONE_MINUS_H
#define MILLSTONE_MINUS_H


#include "BinaryExpression.h"

class Minus : public BinaryExpression {
public:
    Minus(Expression *leftExpression, Expression *rightExpression);

    double Calculate() override;
};

#endif //MILLSTONE_MINUS_H
