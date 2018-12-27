//
// Created by jennie on 12/26/18.
//

#ifndef MILLSTONE_RUNNER_H
#define MILLSTONE_RUNNER_H

#include "Data.h"

class Runner {
    Data* data;
public:
 void run(char* fileName);
 void exit();
};


#endif //MILLSTONE_RUNNER_H
