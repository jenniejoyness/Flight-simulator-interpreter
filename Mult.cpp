#include "Mult.h"

Mult::Mult(Expression *leftExpression, Expression *rightExpression) : BinaryExpression(leftExpression,
                                                                                       rightExpression) {}

double Mult::Calculate() {
    return leftExpression->Calculate() * rightExpression->Calculate();
}
