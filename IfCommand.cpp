//
// Created by jennie on 12/20/18.
//

#include <cstring>
#include "IfCommand.h"
#include "Reader.h"

void IfCommand::doCommand() {
    Reader reader;
    if (condition == true){
        for (int i = 0; i < commands.size(); ++i) {
            //if the command is not a while command send to parser to execute
            if (strstr(commands[i][0].c_str(), "while") == NULL || strstr(commands[i][0].c_str(), "if") == NULL) {
                reader.parser(commands[i]);
                //otherwise send to condition parser
            } else {
                reader.conditionParser(commands[i][0]);
            }
        }
    }
}