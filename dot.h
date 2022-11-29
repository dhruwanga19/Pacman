#pragma once
// Checks if _MAZE IF DECLARED
#ifndef _dot_

#define _dot_

#include <raylib.h>
#include "Sprite.h"
#include "Maze.h"

class dot
{
	private:float x; // X position of dot
	private:float y; // Y position of dot
	private:Sprite dotSprite; // Spritesheet of Dot

/*! \brief Constructor.
 *
 * This constructor takes position x,y and sprites, and determines the position of the dot and its sprite.
 */
public:dot(float x, float y, Sprite s);

};

#endif //_dot_