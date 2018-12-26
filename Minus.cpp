
#include "Minus.h"

Minus::Minus(Expression *leftExpression, Expression *rightExpression) : BinaryExpression(leftExpression,
                                                                                         rightExpression) {}
double Minus::Calculate() {
    return leftExpression->Calculate() - rightExpression->Calculate();
}