#include "BinaryExpression.h"

class Mult : public BinaryExpression {
public:
    Mult(Expression *leftExpression, Expression *rightExpression) : BinaryExpression(leftExpression, rightExpression) {}

    double Calculate() {
        return leftExpression->Calculate() * rightExpression->Calculate();
    }
};