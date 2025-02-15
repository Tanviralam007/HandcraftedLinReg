cmake_minimum_required(VERSION 3.10)
project(HandcraftedLinReg)

set(CMAKE_CXX_STANDARD 11)
include_directories(include)

add_executable(HandcraftedLinReg src/main.cpp src/LinearRegression.cpp)