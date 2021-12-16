#pragma once

#include "NitroZUtils.h"
#include "NitroApp.h"
#include "GameWindow.h"
#include "Sprite.h"
#include "Shader.h"
#include "Renderer.h"

#define START_NITROZ_GAME(classname) \
int main()\
{\
	classname _nitroZ_game;\
	_nitroZ_game.Run();\
}