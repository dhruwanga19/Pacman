#pragma once

// Checks if _MAZE IF DECLARED
#ifndef _MAZE_

// Defines _MAZE_ if above
// conditions fails
#define _MAZE_

#include <raylib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Tile.h"
#include <iterator>
#include "Sprite.h"

const std::string MAP_PATH = "./assets/maps/";
const std::string MAP_TEXTURE = "./assets/maps/textures/";
const int ROW_LENGTH = 22;
const int COLUMN_LENGTH = 21;

class Maze {
private:std::vector<std::vector<Tile>> tileBoard; // 2D Vector to store tiles
private:int numDots;

	   /*! \brief DEFAULT Constructor. 
	    *
		*  This MAZE constructor uses a hardcoded default map to construct a maze object.
	    */
public:Maze();

	  /*! \brief Constructor 
	   *
	   * This constructor takes in a textfile containing a map to construct a map object.
	   */
public:Maze(std::string mapFileName);

public:~Maze();

	  /*! \brief drawMaze: Simple Map Drawing Function. 
	   * 
	   * Draws the maze object using simple rectangles to represent the walls.
	   */
public:void drawMaze();

	  /*! \brief drawMazeEX: Textured Map Drawing Function 
	   *
	   * Draws the maze object using the DEFAULT texture, using internal logic to determine what frame to render.
	   * (ONLY FOR TESTING, MAY CAUSE MEMORY LEAK)
	   */
public:void drawMazeEX();

	  /*! \brief drawMazeEX: Textured Map Drawing Function + Texture 
	   *
	   * Draws the maze object using the texture file supplied, using internal logic to determine what frame to render.
	   * (ONLY FOR TESTING, MAY CAUSE MEMORY LEAK)
	  */
public:void drawMazeEX(std::string textureFile);

	  /*! \brief drawMazeEX: Textured Map Drawing Function + Preloaded Texture
	   *
	   * Draws the maze object using preloaded textures from main, using internal logic to determine what frame to render.
	   * (USE THIS IN FORMAL IMPLEMENTATION)
	  */
public:void drawMazeEX(Sprite map_sprites);

	  /*! \brief Getter Method: Tile from tileBoard */
public:Tile getTile(int x, int y);

	  /*! \brief Setter Method: Tile from tileBoard */
public:void setTile(int x, int y, TileType type);

	  /*! \brief Getter Method: Tile */
public:std::vector<std::vector<Tile>> getTileBoard();

};

#endif // _MAZE_