#include "GetCommandMap.h"
#include "OpenDataServerCommand.h"
#include "WhileCommand.h"
#include "IfCommand.h"
#include "PrintCommand.h"
#include "DefineVarCommand.h"
#include "EqualCommand.h"
#include "ConnectCommand.h"
#include "SleepCommand.h"
#include "Enterc.h"

map<string, ExpressionCommand *> GetCommandMap::getMap() {
    map<string, ExpressionCommand *> commandMap;
    commandMap.insert(pair<string, ExpressionCommand *>("openDataServer",
                                                        new ExpressionCommand(new OpenDataServerCommand())));
    commandMap.insert(pair<string, ExpressionCommand *>("while",
                                                        new ExpressionCommand(new WhileCommand())));
    commandMap.insert(pair<string, ExpressionCommand *>("if",
                                                        new ExpressionCommand(new IfCommand())));
    commandMap.insert(pair<string, ExpressionCommand *>("print",
                                                        new ExpressionCommand(new PrintCommand())));
    commandMap.insert(pair<string, ExpressionCommand *>("var",
                                                        new ExpressionCommand(new DefineVarCommand())));
    commandMap.insert(pair<string, ExpressionCommand *>("=",
                                                        new ExpressionCommand(new EqualCommand())));
    commandMap.insert(pair<string, ExpressionCommand *>("connect",
                                                        new ExpressionCommand(new ConnectCommand())));
    commandMap.insert(pair<string, ExpressionCommand *>("sleep",
                                                        new ExpressionCommand(new SleepCommand())));
    commandMap.insert(pair<string, ExpressionCommand *>("Enterc",
                                                        new ExpressionCommand(new Enterc())));

    return commandMap;
}