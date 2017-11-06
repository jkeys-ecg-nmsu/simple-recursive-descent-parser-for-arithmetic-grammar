cmake_minimum_required(VERSION 3.2)
project(Lab_1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    error.c
    error.h
    expr.c
    expr.h
    input_token.c
    input_token.h
    main.c)

add_executable(Lab_1 ${SOURCE_FILES})