#include "BinaryExpression.h"

class Plus : public BinaryExpression {

public:
    Plus(Expression *left, Expression *right) : BinaryExpression(left, right) {}

    double Calculate() {
        return leftExpression->Calculate() + rightExpression->Calculate();
    }
};
