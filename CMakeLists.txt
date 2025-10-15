cmake_minimum_required(VERSION 4.0)
project(ML_algo_implementations)

set(CMAKE_CXX_STANDARD 14)

# Create separate executables for each algorithm
add_executable(Linear_Regression
        Linear_Regression.cpp
)

add_executable(Logistic_Regression
        Logistic_Regression.cpp
)

add_executable(CNN
        CNN.cpp
)
