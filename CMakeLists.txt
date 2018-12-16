cmake_minimum_required(VERSION 3.12)
project(millStone)

set(CMAKE_CXX_STANDARD 14)

add_executable(millStone main.cpp CommandReader.cpp CommandReader.h Command.h Expression.h BinaryExpression.h Plus.cpp Div.cpp Minus.cpp Mult.cpp Num.cpp OpenServerCommand.cpp DataReaderServer.cpp ShuntingYard.cpp ShuntingYard.h)