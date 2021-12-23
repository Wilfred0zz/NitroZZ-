set(SOURCE_FILES 
	NitroApp.cpp 
	GameWindow.cpp 
	GLFWImplementation/GLFWImplementation.cpp
	Renderer.cpp
	Shader.cpp
	Sprite.cpp
	Events.cpp
	OpenGLimpl/OpenGLRenderer.cpp
	OpenGLimpl/OpenGLShader.cpp
	OpenGLimpl/OpenGLSprite.cpp
)

set(HEADER_FILES 
	NitroZ.h 
	NitroApp.h 
	NitroZUtils.h 
	WindowImplementation.h 
	GameWindow.h 
	GLFWImplementation/GlFWImplementation.h
	Renderer.h
	RendererImplementation.h
	Shader.h
	ShaderImplementation.h
	Sprite.h
	SpriteImplementation.h
	Events.h
	KeyCodes.h
	OpenGLimpl/OpenGLRenderer.h
	OpenGLimpl/OpenGLShader.h
	OpenGLimpl/OpenGLSprite.h
)

add_library(nitroZ_lib SHARED ${SOURCE_FILES} ${HEADER_FILES})

target_precompile_headers(nitroZ_lib PRIVATE pch.h)

add_definitions(-DNITROZ_LIB)

target_link_libraries(nitroZ_lib glfw glad stbi)

include_directories(../glfw/include)
include_directories(../NitroZ)
include_directories(../glad/include)
include_directories(../stbi)