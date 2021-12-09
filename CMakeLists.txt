cmake_minimum_required(VERSION 3.18)

project(saucelel_game)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

if(WIN32)
	add_definitions(-DNITROZ_WINDOWS)
elseif(APPLE)
	add_definitions(-DNITROZ_MAC)
elseif(UNIX)
	add_definitions(-DNITROZ_LINUX)
endif()

add_definitions(-DNITROZ_OPENGL)

add_subdirectory(SaucelelGame)
add_subdirectory(NitroZ)
add_subdirectory(glfw)
add_subdirectory(glad)
add_subdirectory(stbi)