//
// Created by jennie on 12/17/18.
//

#include "ExpressionCommand.h"

ExpressionCommand::ExpressionCommand(Command *command) : command(command) {}
double ExpressionCommand::Calculate() {
    command->doCommand();
}

Command* ExpressionCommand::getCommand() { return command;}
