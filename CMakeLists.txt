cmake_minimum_required(VERSION 3.12)
project(millStone)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS -pthread)

add_executable(millStone main.cpp Reader.cpp Reader.h Command.h Expression.h BinaryExpression.h Plus.cpp Div.cpp Minus.cpp Mult.cpp Num.cpp ShuntingYard.cpp ShuntingYard.h OpenDataServerCommand.cpp OpenDataServerCommand.h ExpressionCommand.cpp ExpressionCommand.h DefineVarCommand.cpp DefineVarCommand.h ServerSocket.cpp ServerSocket.h ClientSocket.cpp ClientSocket.h Socket.h Data.cpp Data.h ConnectCommand.cpp ConnectCommand.h EqualCommand.cpp EqualCommand.h WhileCommand.cpp WhileCommand.h IfCommand.cpp IfCommand.h ConditionCommand.h ConditionOperators.cpp ConditionOperators.h PrintCommand.h PrintCommand.cpp GetCommandMap.cpp GetCommandMap.h ConditionCommand.cpp SleepCommand.h SleepCommand.cpp Enterc.cpp Enterc.h Div.h Mult.h Plus.h Minus.h Num.h Runner.cpp Runner.h)