cmake_minimum_required(VERSION 3.12)
project(ZAD_4_zmpo)

set(CMAKE_CXX_STANDARD 98)

add_executable(ZAD_4_zmpo main.cpp CIndividual.cpp CIndividual.h CGeneticAlgorithm.cpp CGeneticAlgorithm.h CKnapsackProblem.cpp CKnapsackProblem.h Knapsack.cpp Knapsack.h ReadFile.cpp ReadFile.h)