#include "Div.h"

Div::Div(Expression *leftExpression, Expression *rightExpression) : BinaryExpression(leftExpression, rightExpression) {}

double Div::Calculate() {
    if (rightExpression->Calculate() == 0) {
        throw "cannot divide by zero";
    }
    return leftExpression->Calculate() / rightExpression->Calculate();
}
