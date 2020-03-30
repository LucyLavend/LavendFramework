/**
 * This file is part of the game Vixel in the RT2D framework.
 *
 * - Copyright 2019 Lucy Jongebloed
 *     - Initial commit
 */

#ifndef HOME_H
#define HOME_H

#include <vector>
#include <vectorx.h>

class Home
{
public:
	Home(int posX, int posY);
	virtual ~Home();

	Pointi position;
	Pointi initPosition;
	int direction;
	int spriteW;
	int spriteH;
	bool active;

	void init();

private:
	
};

#endif /* HOME_H */
