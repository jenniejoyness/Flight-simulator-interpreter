//
// Created by renana on 12/21/18.
//

#include "GetCommandMap.h"
#include "OpenDataServerCommand.h"
#include "WhileCommand.h"
#include "IfCommand.h"
#include "PrintCommand.h"

map<string, ExpressionCommand*> GetCommandMap::getMap() {
    map<string, ExpressionCommand*> commandMap;
    commandMap.insert(pair<string, ExpressionCommand *>("openDataServer",
                                                        new ExpressionCommand(new OpenDataServerCommand())));
  /*  commandMap.insert(pair<string, ExpressionCommand *>("while",
                                                        new ExpressionCommand(new WhileCommand())));*/
    commandMap.insert(pair<string, ExpressionCommand *>("if",
                                                        new ExpressionCommand(new IfCommand())));
    commandMap.insert(pair<string, ExpressionCommand *>("print",
                                                        new ExpressionCommand(new PrintCommand())));

    return commandMap;
}