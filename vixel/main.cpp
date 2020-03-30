/**
 * This file is part of the game Vixel in the RT2D framework.
 *
 * - Copyright 2019 Lucy Jongebloed
 *     - Initial commit
 */

#include <lavendframework/core.h>

#include "game.h"

int main( void )
{
	// Core instance
	Core core;

	// Create all scenes on the heap and keep a list
	std::vector<SuperScene*> scenes;
	scenes.push_back(new Game()); // canvas space invaders
	int s = scenes.size();

	// start running with the first Scene
	SuperScene* scene = scenes[0];
	int scenecounter = 0;
	int running = 1;
	while (running) {
		scenecounter = scene->activescene;
		if (scenecounter > s-1) { scenecounter = 0; scene->activescene = 0; }
		if (scenecounter < 0) { scenecounter = s-1; scene->activescene = s-1; }
		scene = scenes[scenecounter];
		core.run(scene); // update and render the current scene
		core.showFrameRate(5); // show framerate in output every n seconds
		if (!scene->isRunning()) { running = 0; } // check status of Scene every frame
	}

	// delete all scenes
	for (int i = 0; i < s; i++) {
		delete scenes[i];
		scenes[i] = nullptr;
	}
	scenes.clear();

	// No need to explicitly clean up the core.
	// As a local var, core will go out of scope and destroy Renderer->ResourceManager.
	// ResourceManager destructor also deletes Shaders.

	return 0;
}
