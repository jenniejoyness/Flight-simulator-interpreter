//
// Created by jennie on 12/20/18.
//

#ifndef MILLSTONE_WHILECOMMAND_H
#define MILLSTONE_WHILECOMMAND_H
#include "Reader.h"
#include "ConditionCommand.h"

class WhileCommand : public ConditionCommand {
private:
    Reader reader;
public:
    void doCommand();
    void setParameters(vector<string> params, Data *data);
    void stuff(string condition);
};


#endif //MILLSTONE_WHILECOMMAND_H
