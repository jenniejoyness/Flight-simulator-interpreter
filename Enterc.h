//
// Created by jennie on 12/24/18.
//

#ifndef MILLSTONE_ENTERC_H
#define MILLSTONE_ENTERC_H


#include "Command.h"

class Enterc : public Command{
public:
    void doCommand() override;
    void setParameters(vector<string> params, Data *data) override;
};


#endif //MILLSTONE_ENTERC_H
