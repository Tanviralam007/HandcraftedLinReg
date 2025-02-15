cmake_minimum_required(VERSION 3.10)
project(HandcraftedLinReg)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(HandcraftedLinReg 
    src/main.cpp 
    src/LinearRegression.cpp 
    src/DataHandler.cpp
)

target_include_directories(HandcraftedLinReg PRIVATE include)
