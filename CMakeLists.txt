cmake_minimum_required(VERSION 3.13)
project(Lesson1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Lesson1
        Calculator.cpp
        Calculator.h
        Evaluator.cpp
        Evaluator.h
        main.cpp
        Parser.cpp
        Parser.h
        Tokens.h)