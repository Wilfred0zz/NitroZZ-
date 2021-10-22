set(SOURCE_FILES NitroApp.cpp)

set(HEADER_FILES NitroZ.h NitroApp.h NitroZUtils.h)

add_library(nitroZ_lib SHARED ${SOURCE_FILES} ${HEADER_FILES})

target_precompile_headers(nitroZ_lib PRIVATE pch.h)