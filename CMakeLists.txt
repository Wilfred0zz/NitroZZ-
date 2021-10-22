cmake_minimum_required(VERSION 3.20)

project(saucelel_game)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

add_subdirectory(SaucelelGame)
add_subdirectory(NitroZ)