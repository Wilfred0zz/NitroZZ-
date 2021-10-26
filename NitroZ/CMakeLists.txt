set(SOURCE_FILES NitroApp.cpp GameWindow.cpp GLFWImplementation/GLFWImplementation.cpp)

set(HEADER_FILES NitroZ.h NitroApp.h NitroZUtils.h WindowImplementation.h GameWindow.h GLFWImplementation/GLFWImplementation.h)

add_library(nitroZ_lib SHARED ${SOURCE_FILES} ${HEADER_FILES})

target_precompile_headers(nitroZ_lib PRIVATE pch.h)

add_definitions(-DNITROZ_LIB)

target_link_libraries(nitroZ_lib glfw)

include_directories(../glfw/include)
include_directories(../NitroZ)