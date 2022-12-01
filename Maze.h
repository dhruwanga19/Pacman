/*****************************************************************//**
 * @file   Maze.h
 * @brief  This class is used for the creation and management of the gameboard/maze.
 *
 * @author Ali Mohamed
 * @date   29/11/2022
***********************************************************************/
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

/**
 * @brief Default location of where map assets are stored.
 */
const std::string MAP_PATH = "./assets/maps/";
/**
 * @brief Default location of where map textures are stored.
 */
const std::string MAP_TEXTURE = "./assets/maps/textures/";
/**
 * @brief Row length of map, used when reading map file and initilizing tileBoard.
 */
const int ROW_LENGTH = 21;
/**
 * @brief Column length of map, used when reading map file and initilizing tileBoard.
 */
const int COLUMN_LENGTH = 21;

class Maze {
	/**
	 * @brief 2D Vector to store tiles.
     */
private:std::vector<std::vector<Tile>> tileBoard;
	/**
	 * @brief Number of dots in maze.
	 */
private:int numDots;

	   /**
	    * Construct a maze object using a hardcoded default map.
	    * @brief Default Constructor.
	    * @see Maze(std::string mapFileName)
	    */
public:Maze();

	  /**
	   * Construct a maze object using the supplied map.
	   * @brief Constructor.
	   * @param mapFileName The name of the MAP file you want to load.
	   * @see Maze()
	   */
public:Maze(std::string mapFileName);

	  /* Destructor*/
public:~Maze();
	  /**
	   * Draws the maze object using simple rectangles to represent the walls.
	   * @brief drawMaze: Simple Map Drawing Function.
	   * @see drawMazeEX()
	   */
public:void drawMaze();
	  /**
	   * Draws the maze object using the DEFAULT texture, using internal logic to determine what frame to render.
	   * @brief drawMazeEX: Textured Map Drawing Function
	   * @see drawMazeEX(Sprite map_sprites)
	   */
public:void drawMazeEX();
	  /**
	   * Draws the maze object using the texture file supplied, using internal logic to determine what frame to render.
	   * @brief drawMazeEX: Textured Map Drawing Function + Texture
	   * @param textureFile File for texture to be supplied
	   * @deprecated Only use for testing, may cause Memory Leaks.
	   * @see drawMazeEX()
	   * @see drawMazeEX(Sprite map_sprites)
	   */
public:void drawMazeEX(std::string textureFile);
	  /**
	   * Draws the maze object using preloaded textures, using internal logic to determine what frame to render.
	   * @brief drawMazeEX: Textured Map Drawing Function + Preloaded Texture
	   * @param map_sprites Pre-loaded textures to be used for drawing the map.
	   * @see drawMazeEX()
	   */
public:void drawMazeEX(Sprite map_sprites);
	  /**
	   * @brief Getter Method: Tile from tileBoard.
	   * @param x ROW-WISE Refrence (Horizontal)
	   * @param y COLUMN-WISE Reference (Vertical)
	   * @return Tile object at tileboard(x,y)
	   */
public:Tile getTile(int x, int y);
	  /**
	   * @brief Setter Method: Tile from tileBoard.
	   * @param x ROW-WISE Refrence (Horizontal)
	   * @param y COLUMN-WISE Reference (Vertical)
	   * @param type Tiletype of tile new tile
	   */
public:void setTile(int x, int y, TileType type);
	  /**
	   * @brief Getter Method: Tileboard.
	   * @return tileBoard data member, 2D vector containing tiles of the maze.
	   */
public:std::vector<std::vector<Tile>> getTileBoard();

public:int getColLength();

public:int getRowLength();

public:bool checkInMaze(int x, int y){
	return (x>0) and (y>0) and (x<COLUMN_LENGTH) and (y<ROW_LENGTH);

}
};

#endif // _MAZE_