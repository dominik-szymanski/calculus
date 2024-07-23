cmake_minimum_required(VERSION 3.20)
project(calculus)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -Wextra -pedantic -Wunused -O0 -g -g3 -I. -D__DEBUG -fno-builtin -fPIC")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wall -Wextra -pedantic -Wunused -Ofast -fno-builtin -fPIC")

add_library(basic_operators SHARED BasicOperators/BasicOperatorProvider.cpp BasicOperators/BasicOperatorProvider.hpp
        BasicOperators/AdditionOperator.cpp BasicOperators/AdditionOperator.hpp BasicOperators/MultiplicationOperator.cpp
        BasicOperators/MultiplicationOperator.hpp BasicOperators/SubtractionOperator.cpp
        BasicOperators/SubtractionOperator.hpp BasicOperators/DivisionOperator.cpp BasicOperators/DivisionOperator.hpp
        BasicOperators/PowOperator.cpp BasicOperators/PowOperator.hpp)

add_library(basic_functions SHARED BasicFunctions/BasicFunctionProvider.cpp BasicFunctions/BasicFunctionProvider.hpp
        BasicFunctions/BasicFunctions.cpp BasicFunctions/BasicFunctions.hpp)

add_library(trigonometry_functions SHARED Trigonometry/TrigonometryFunctionsProvider.cpp Trigonometry/TrigonometryFunctionsProvider.hpp
        Trigonometry/TrigonometryFunctions.cpp Trigonometry/TrigonometryFunctions.hpp)

add_library(onp_parsers SHARED ONPParser/ONPParser.cpp ONPParser/ONPParser.hpp)

add_library(solver Solver/Solver.cpp Solver/Solver.hpp)

add_library(calculator SHARED Calculator/Calculator.cpp Calculator/Calculator.hpp)
target_link_libraries(calculator onp_parsers solver)

add_executable(calculus main.cpp Operator.hpp OperatorProvider.hpp Operand.cpp Operand.hpp Function.hpp FunctionProvider.hpp types.hpp)
target_link_libraries(${PROJECT_NAME} basic_operators basic_functions calculator stdc++fs m stdc++ dl)

file(COPY cmake-build-debug/libtrigonometry_functions.so DESTINATION plugins FOLLOW_SYMLINK_CHAIN)
