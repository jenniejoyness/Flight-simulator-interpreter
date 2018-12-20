//
// Created by jennie on 12/20/18.
//

#include "ConditionOperators.h"

bool ConditionOperators::bigger(Expression *left, Expression *right) {
    return left->Calculate() > right->Calculate();
}

bool ConditionOperators::biggerEqual(Expression *left, Expression *right) {
    return left->Calculate() >= right->Calculate();

}

bool ConditionOperators::smaller(Expression *left, Expression *right) {
    return left->Calculate() < right->Calculate();
}

bool ConditionOperators::smallerEqual(Expression *left, Expression *right) {
    return left->Calculate() <= right->Calculate();
}

bool ConditionOperators::equal(Expression *left, Expression *right) {
    return left->Calculate() == right->Calculate();
}

bool ConditionOperators::notEqual(Expression *left, Expression *right) {
    return left->Calculate() != right->Calculate();
}