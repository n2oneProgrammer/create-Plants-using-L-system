cmake_minimum_required(VERSION 3.15)
project(Lsystem2dInterpreter)

set(CMAKE_CXX_STANDARD 14)

add_executable(Lsystem2dInterpreter main.cpp turtle.cpp turtle.h positionData.h)

# Detect and add SFML

set(SFML_INCLUDE_DIR "~/Downloads/SFML-2.5.1/include")
set(SFML_LIBRARY_DIR "~/Downloads/SFML-2.5.1/lib")
set(SFML_DIR "~/Downloads/SFML-2.5.1/lib/cmake/SFML")

find_package(SFML 2.5.1 REQUIRED system window graphics network audio)
include_directories(${SFML_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-window sfml-system)