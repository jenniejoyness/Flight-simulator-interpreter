
#include "BinaryExpression.h"

class Minus : public BinaryExpression {
public:
    Minus(Expression *leftExpression, Expression *rightExpression) : BinaryExpression(leftExpression,
                                                                                      rightExpression) {}

    double Calculate() {
        return leftExpression->Calculate() - rightExpression->Calculate();
    }
};