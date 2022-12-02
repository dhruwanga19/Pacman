/*****************************************************************//**
 * @file   Maze.h
 * @brief  This class is used for the creation and management of the gameboard/maze.
 *
 * @author Ali Mohamed
 * @date   29/11/2022
***********************************************************************/
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
	private:bool super; //Determines if dot is super
	private:Sprite dotSprite; // Spritesheet of Dot

/**
 * This constructor uses the default sprites and 0,0 to initilize dot.
 * @brief Default Constructor
 * @see dot(float x, float y, Sprite s)
 * @see dot(float x, float y, Sprite s, bool Super)
 */
public:dot();
/**
 * This constructor uses the position (x,y) to determine where dots spawn, and uses the supplied sprite.
 * @brief Constructor
 * @param x Row-wise position.
 * @param y Column-wise position.
 * @param s Dot Pellet Sprite.
 * @see dot()
 * @see dot(float x, float y, Sprite s, bool Super)
 */
public:dot(float x, float y, Sprite s);
/**
 * This constructor uses the position (x,y) to determine where dots spawn, and uses the supplied sprite, and a boolean value to determine if this dot is Super.
 * @brief Constructor
 * @param x Row-wise position.
 * @param y Column-wise position.
 * @param s Dot Pellet Sprite.
 * @param Super True if Super Pellet, False otherwise.
 * @see dot()
 * @see @see dot(float x, float y, Sprite s)
 */
public:dot(float x, float y, Sprite s, bool Super);

};

#endif //_dot_