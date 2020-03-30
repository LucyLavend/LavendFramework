/**
 * This file is part of the game Vixel in the RT2D framework.
 *
 * - Copyright 2019 Lucy Jongebloed
 *     - Initial commit
 */

#include "home.h"

Home::Home(int posX, int posY)
{
	initPosition.x = posX;
	initPosition.y = posY;

	spriteW = 3;
	spriteH = 5;

	active = false;

	init();
}

void Home::init() {

	position = initPosition;
}

Home::~Home()
{

}
