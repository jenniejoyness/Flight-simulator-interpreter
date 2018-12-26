#include "Plus.h"

Plus::Plus(Expression *left, Expression *right) : BinaryExpression(left, right) {}

double Plus::Calculate() {
    return leftExpression->Calculate() + rightExpression->Calculate();
}
