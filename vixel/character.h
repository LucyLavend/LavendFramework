/**
 * This file is part of the game Vixel in the RT2D framework.
 *
 * - Copyright 2019 Lucy Jongebloed
 *     - Initial commit
 */

#ifndef CHARACTER_H
#define CHARACTER_H

#include <vector>
#include <vectorx.h>

class Character
{
public:
	Character(int posX, int posY);
	virtual ~Character();

	Pointi position;
	Pointi initPosition;
	bool awake;
	bool home;
	int direction;
	int spriteW;
	int spriteH;
	int breath;
	int airTime;

	void init();
	void walk();
	void applyGravity();
	void switchDirection();
	void die();

private:
	
};

#endif /* CHARACTER_H */
