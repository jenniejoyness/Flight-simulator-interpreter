//
// Created by renana on 12/26/18.
//

#ifndef MILLSTONE_NUM_H
#define MILLSTONE_NUM_H


#include "Expression.h"

class Num : public Expression {
private:
    double num;

public:

    Num(double num);
    double Calculate() override;
};

#endif //MILLSTONE_NUM_H
