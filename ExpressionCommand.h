//
// Created by jennie on 12/17/18.
//

#ifndef MILLSTONE_EXPRESSIONCOMMAND_H
#define MILLSTONE_EXPRESSIONCOMMAND_H

#include "Command.h"
#include "Expression.h"


class ExpressionCommand : public Expression {
private:
    Command* command;
public:
    ExpressionCommand(Command* command);
    Command* getCommand();
    double Calculate() override;

};


#endif //MILLSTONE_EXPRESSIONCOMMAND_H
