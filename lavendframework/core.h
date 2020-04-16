#ifndef CORE_H
#define CORE_H

// Include standard headers
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>

#include <lavendframework/renderer.h>
//#include <lavendframework/input.h>
#include <lavendframework/entity.h>

/// @brief The Core class handles updating and rendering of your Entities.
class Core
{
public:
	Core(); ///< @brief Constructor of the Core
	virtual ~Core(); ///< @brief Destructor of the Core

	/// @brief runs a Scene (update/render)
	/// @param scene The scene that needs to 'run'.
	/// @return void
	void run();
	/// @brief clean up this session (everything except Shader)
	/// @return void
	void cleanup();
	/// @brief get deltaTime
	/// double internally, cast to float. glm and OpenGL expect floats.
	/// @return float deltaTime
	float deltaTime() { return (float)_deltaTime; };
	/// @brief prints the framerate to output every second
	/// @param numsecs print framerate every nth second.
	/// @return void
	void showFrameRate(float numsecs);

private:
	//Renderer _renderer; ///< @brief The Renderer member

	double _calculateDeltaTime(); ///< @brief updates deltaTime internally
	double _deltaTime; ///< @brief deltaTime member
};

#endif /* CORE_H */
