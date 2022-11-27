#pragma once

// Checks if _MAZE IF DECLARED
#ifndef _MAZE_

// Defines _MAZE_ if above
// conditions fails
#define _MAZE_

#include <include/raylib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Tile.h"
#include <iterator>
#include "Sprite.h"

const std::string MAP_PATH = "../MyGame/assets/maps/";
const std::string MAP_TEXTURE = "../MyGame/assets/maps/textures/";
const int ROW_LENGTH = 22;
const int COLUMN_LENGTH = 21;

class Maze {
private:std::vector<std::vector<Tile>> tileBoard;

	   /* DEFAULT Constructor */
public:Maze();

	  /* Constructor */
public:Maze(std::string mapFileName);

	  /* Destructor */
public:~Maze();

	  /* drawMaze: Simple Draws the Maze using simple shapes */
public:void drawMaze();

	  /* drawMazeEX: Textured Map Drawing Function */
public:void drawMazeEX();

	  /* drawMazeEX: Textured Map Drawing Function + Texture */
public:void drawMazeEX(std::string textureFile);

	  /* drawMazeEX: Textured Map Drawing Function + Preloaded Texture*/
public:void drawMazeEX(Sprite map_sprites);

	  /* Getter Method: Tile from tileBoard */
public:Tile getTile(int x, int y);

	  /* Setter Method: Tile from tileBoard */
public:void setTile(int x, int y, TileType type);

};

#endif // _MAZE_