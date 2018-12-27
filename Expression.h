
#ifndef MILLSTONE_EXPRESSION_H
#define MILLSTONE_EXPRESSION_H

class Expression {
public:
    virtual double Calculate() = 0;
    virtual ~Expression() = default;
};

#endif //MILLSTONE_EXPRESSION_H
