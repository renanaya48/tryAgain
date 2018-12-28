cmake_minimum_required(VERSION 3.12)
project(project1)

set(CMAKE_CXX_STANDARD 14)

add_executable(project1 main.cpp BineryExpression.h BoolExpression.cpp BoolExpression.h CheckConnection.cpp CheckConnection.h Command.h CommandExpression.cpp CommandExpression.h CommandMap.cpp CommandMap.h ConditionParser.cpp ConditionParser.h ConnectCommand.cpp ConnectCommand.h CreateExpression.cpp CreateExpression.h Div.cpp Div.h Expression.h FlightValueMap.cpp FlightValueMap.h IfCommand.cpp IfCommand.h LoopCommand.cpp LoopCommand.h Minus.cpp Minus.h Mul.cpp Mul.h Neg.cpp Neg.h Num.cpp Num.h OpenServerCommand.cpp OpenServerCommand.h PathMap.cpp PathMap.h Plus.cpp Plus.h PrintCommand.cpp PrintCommand.h SetControlCommand.cpp SetControlCommand.h SleepCommand.cpp SleepCommand.h StringFlightControls.cpp StringFlightControls.h SymbolTable.cpp SymbolTable.h Var.cpp Var.h VarCommand.cpp VarCommand.h parser.cpp parser.h lexer.cpp lexer.h conditionParser.cpp conditionParser.h)