cmake_minimum_required(VERSION 3.21)
project(grammatic_analyse)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_LIB Parser.cpp Rule.cpp Expression.cpp ExpressionHelper.cpp)

add_executable(grammatic_analyse main.cpp Parser.cpp Rule.cpp Expression.cpp ExpressionHelper.cpp ExpressionHelper.cpp BasicRuleExecuteHelper.cpp BasicRuleExecuteHelper.h)
