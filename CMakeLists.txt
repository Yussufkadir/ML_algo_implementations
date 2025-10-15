cmake_minimum_required(VERSION 4.0)
project(ML_algo_implementations)

set(CMAKE_CXX_STANDARD 14)

add_executable(ML_algo_implementations
        Linear_Regression.cpp
        Logistic_Regression.cpp
        CNN.cpp
)
