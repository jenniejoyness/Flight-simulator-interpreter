

#include "Command.h"
class OpenServerCommand : public Command {

    void doCommand(vector<string> line) {
        if (line.size() != 2) {
            throw "invalid number of parameters";
        }

    }
};