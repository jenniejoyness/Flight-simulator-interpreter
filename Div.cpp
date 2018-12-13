#include "BinaryExpression.h"

class Div : public BinaryExpression {

public:
    Div(Expression *leftExpression, Expression *rightExpression) : BinaryExpression(leftExpression, rightExpression) {}

    double Calculate() {
        if (rightExpression->Calculate() == 0) {
            throw "cannot divide by zero";
        }
        return leftExpression->Calculate() / rightExpression->Calculate();
    }
};