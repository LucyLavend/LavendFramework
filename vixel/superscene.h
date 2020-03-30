/**
 * This file is part of the game Vixel in the RT2D framework.
 *
 * - Copyright 2019 Lucy Jongebloed
 *     - Initial commit
 */

#ifndef SUPERSCENE_H
#define SUPERSCENE_H

#include <vector>
#include <rt2d/scene.h>
#include <rt2d/text.h>
#include "basicentity.h"

class SuperScene: public Scene
{
public:
	SuperScene();
	virtual ~SuperScene();

	// must be explicitly called from subclass
	virtual void update(float deltaTime);

	static int activescene;

protected:
	unsigned int top_layer;
	std::vector<BasicEntity*> layers;
	std::vector<Text*> text;
	void moveCamera(float deltaTime);

private:
	Timer fpstimer;
};

#endif /* SUPERSCENE_H */
