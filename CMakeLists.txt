cmake_minimum_required(VERSION 3.4)

project(TestMath)

include_directories(userInput maths)

set(SOURCES maths/complex.cpp maths/matrix.cpp userInput/checkType.cpp userInput/getInput.cpp TestMaths/main.cpp)

add_executable(TestMath ${SOURCES})

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

