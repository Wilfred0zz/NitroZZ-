#pragma once

#include "NitroZUtils.h"
#include "NitroApp.h"

#define START_NITROZ_GAME(classname) \
int main()\
{\
	classname _nitroZ_game;\
	_nitroZ_game.Run();\
}