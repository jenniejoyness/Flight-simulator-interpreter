

#ifndef MILLSTONE_BINARYEXPRESSION_H
#define MILLSTONE_BINARYEXPRESSION_H

#include "Expression.h"

class BinaryExpression : public Expression {
protected:
    Expression* leftExpression;
    Expression* rightExpression;

public:
    //jennie
    BinaryExpression(Expression *leftExpression, Expression *rightExpression) : leftExpression(leftExpression),
                                                                                rightExpression(rightExpression) {}


};
#endif //MILLSTONE_BINARYEXPRESSION_H
