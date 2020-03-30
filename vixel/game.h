/**
 * This file is part of the game Vixel in the RT2D framework.
 *
 * - Copyright 2019 Lucy Jongebloed
 *     - Initial commit
 */

#ifndef GAME_H
#define GAME_H

#include <vector>
#include <lavendframework/timer.h>
#include <lavendframework/vectorx.h>
#include <lavendframework/canvas.h>
#include "superscene.h"
#include "character.h"
#include "home.h"

#include "audio/audio.h"
#include "audio/sound.h"

class Game: public SuperScene
{
public:
	Game(); ///< @brief Constructor of the Game
	virtual ~Game(); ///< @brief Constructor of the Game

	virtual void update(float deltaTime);

private:
	inline int getIdFromPos(int x, int y) { 
		//check if x and y are inside the canvas bounds
		if (x > -1 && x < canvas->width() && y > -1 && y < canvas->height()) {
			return (y * canvas->width()) + x; 
		}
		else {
			return -1;
		}
	};

	int frameCount; ///< @brief Frames since the start of the game
	int currentMaterial; ///< @brief The currently selected material
	int useableMaterialsCap; ///< @brief Caps the materials the player can use
	int scrolledAmount; ///< @brief Scrolled amount
	int level; ///< @brief Currently selected level
	bool onLastLevel; ///< @brief Check if the player is on the last level
	bool hasClicked; ///< @brief Check if the player has held down the mouse button
	bool allMaterialsDisabled; ///< @brief Check for if all the materials available are disabled
	size_t pixelsize; ///< @brief Size of the games pixels the canvas will draw
	std::vector<Character> characters; ///< @brief A list with all the characters in the current level
	std::vector<Home> homes; ///< @brief A list with all the homes in the current level
	std::vector<int> current; ///< @brief A list with all the pixels in the current level
	std::vector<Sound*> music; ///< @brief A list with pointers to all the music files
	std::vector<Sound*> sfx; ///< @brief A list with pointers to all the sound effects files

	Sprite* levelImage; ///< @brief Loaded .tga level image

	/// @brief Draw the game UI
	/// @return void
	void drawUI();
	/// @brief Loop over the levels array to update what needs to be updated
	/// @return void
	void updateField();
	/// @brief Initialize the level: load the level image and reset all values to the default
	/// @return void
	void initLevel();
	/// @brief Move the next available material when scrolling
	/// @return void
	void moveToSelectableMat();
	/// @brief Check the levels.txt file if the current level has any materials disabled
	/// @return void
	void checkDisabledMaterials();
	/// @brief Loop over all the characters to see if all of them are home. If so, move to the next level
	/// @return void
	void checkLevelProgress();
	/// @brief Draw the pixels on the screen from the level array
	/// @return void
	void drawLevel();
	/// @brief Update the position of all the characters and check if they need to die
	/// @return void
	void updateCharacters();
	/// @brief Clear all the pixels of the characters
	/// @param c Character
	/// @param op Original position
	/// @return void
	void clearCharacter(Character c, Pointi op);
	/// @brief Draw all the pixels of the chracters
	/// @param c Character
	/// @param op Original position
	/// @return void
	void drawCharacter(Character c, Pointi op);
	/// @brief Update all the homes: check if theres enough wood around the home
	/// @return void
	void updateHomes();
	/// @brief Draw all pixels of the homes
	/// @param h Home
	/// @param active State of the home
	/// @return void
	void drawHome(Home h, bool active);
	/// @brief Place a pixel at the given location with a given material with size 1 or 2
	/// @param x X
	/// @param y Y
	/// @param mat Material
	/// @param size Brush size
	/// @return void
	void placePixel(int x, int y, int mat, int size = 1);
	/// @brief Creates an int array of a level loaded from an image
	/// @return std::vector<int> created level image
	std::vector<int> createMapFromImage();
	/// @brief Load all audio files
	/// @return void
	void loadAudio();

	Canvas* canvas; ///< @brief The canvas layer where the level is drawn on
	Canvas* uiCanvas; ///< @brief The canvas layer where the UI is drawn on
	Timer timer; ///< @brief A timer for updating frames

	std::vector<RGBAColor> materials;
	std::vector<int> disabledMaterials;
	RGBAColor air = RGBAColor(0, 0, 0, 0);
	RGBAColor dirt = RGBAColor(116, 63, 57, 255);
	RGBAColor wood = RGBAColor(230, 177, 133, 255);
	RGBAColor stone = RGBAColor(100, 100, 100, 255);
	RGBAColor fire = RGBAColor(228, 59, 68, 255);
	RGBAColor lava = RGBAColor(247, 118, 34, 255);
	RGBAColor water = RGBAColor(0, 149, 233, 255);
	RGBAColor acid = RGBAColor(99, 199, 77, 255);
	RGBAColor chara = RGBAColor(182, 83, 212, 255);
	RGBAColor grass = RGBAColor(62, 137, 72, 255);
	RGBAColor homeInactive = RGBAColor(102, 11, 111, 255);
	RGBAColor homeActive = RGBAColor(210, 66, 210, 255);
	RGBAColor darkStone = RGBAColor(84, 84, 84, 255);
	RGBAColor indistructable = RGBAColor(60, 60, 135, 255);
	
};

#endif /* GAME_H */
