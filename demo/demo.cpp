// Include GLEW
#include <GL/glew.h>

// Include GLFW
#include <GLFW/glfw3.h>

#include <vector>
//#include <demo/demo.h>
#include <lavendframework/core.h>
#include <lavendframework/renderer.h>
#include <lavendframework/camera.h>
#include <lavendframework/sprite.h>
#include <lavendframework/singleton.h>

int main( void )
{
	Renderer renderer(1280, 720);
	int w = 100;
	int h = 100;
	int gridSize = 16;
	int tileSize = 128;
	Input* _input = Singleton<Input>::instance();
	Sprite* gear = new Sprite("assets/gear.tga");
	std::vector<Sprite*> gearGrid(w * h, gear);

	do {
		// Update deltaTime
		float deltaTime = renderer.updateDeltaTime();

		// Compute the ViewMatrix from keyboard and mouse input (see: camera.h/cpp)
		computeMatricesFromInputs(renderer.window(), deltaTime);

		// Clear the screen
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glm::vec3 cursor = getCursorWorldPos(); // Mouse world position

		int cursorGridX = (cursor.x / gridSize);
		int cursorGridY = (cursor.y / gridSize);


		// Render all Sprites (Sprite*, xpos, ypos, xscale, yscale, rotation)
		static float rot_z = 0.0f;
		int dir = 1;
		for (int i = 0; i < 10; i++)
		{
			renderer.renderSprite(gear, 400 + 116*i, 100, 1.0f, 1.0f, dir * rot_z);
			if (dir == 1) dir = -1;
			else dir = 1;
		}
		renderer.renderSprite(gear, 810, 400, 1.0f, 1.0f, -rot_z);
		renderer.renderSprite(gear, renderer.width()/2, renderer.height()/2, 2.0f, 2.0f, rot_z / 2);
		renderer.renderSprite(gear, cursor.x, cursor.y, .5f, .5f, -rot_z * 1.5f);
		renderer.renderSprite(gear, cursorGridX, cursorGridY, .5f, .5f, -rot_z * 1.5f);
		renderer.renderSprite(gear, cursorGridX, cursorGridY, 4.4f, 4.4f, -rot_z * cursor.x * .1f);
		rot_z += 10.0f / 2 * deltaTime;

		// Swap buffers
		glfwSwapBuffers(renderer.window());
		glfwPollEvents();

	} // Check if the ESC key was pressed or the window was closed
	while( glfwGetKey(renderer.window(), GLFW_KEY_ESCAPE ) != GLFW_PRESS &&
		   glfwWindowShouldClose(renderer.window()) == 0 );

	if (_input()->getKeyDown(KeyCode(91))) {

	}

	delete gear;

	// Close OpenGL window and terminate GLFW
	glfwTerminate();

	return 0;
}


