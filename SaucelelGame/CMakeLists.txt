add_executable(saucelel_game main.cpp SaucelelGameApp.h SaucelelGameApp.cpp Unit.h Unit.cpp)

target_link_libraries(saucelel_game nitroZ_lib)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/.. PROPERTY VS_STARTUP_PROJECT saucelel_game)

include_directories(../NitroZ)

file(COPY Assets DESTINATION ../SaucelelGame)
file(COPY Assets DESTINATION ${PROJECT_BINARY_DIR}/Debug)
file(COPY Assets DESTINATION ${PROJECT_BINARY_DIR}/Release)