#include "ExpressionCommand.h"

ExpressionCommand::ExpressionCommand(Command *command) : command(command) {}

double ExpressionCommand::Calculate() {
    command->doCommand();
}

Command *ExpressionCommand::getCommand() {
    return command;
}

/*ExpressionCommand::~ExpressionCommand() {
    delete command;
}*/
