#ifndef MILLSTONE_MULT_H
#define MILLSTONE_MULT_H


#include "BinaryExpression.h"

class Mult : public BinaryExpression {
public:
    Mult(Expression *leftExpression, Expression *rightExpression);

    double Calculate() override;
};

#endif //MILLSTONE_MULT_H
