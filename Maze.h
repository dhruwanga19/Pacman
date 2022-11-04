#pragma once

// Checks if _ANIMALS IF DECLARED
#ifndef _MAZE_

// Defines _ANIMALS_ if above
// conditions fails
#define _MAZE_

#include <raylib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Tile.h"
#include <iterator>

const std::string MAP_PATH = "/assets/maps";

class Maze {
	private:Tile tileBoard[28][31];

/* DEFAULT Constructor */
public:Maze();

/* Constructor */
public:Maze(std::string mapFileName);

/* Destructor */
public:~Maze();

/*Getter Method: Tile from tileBoard*/
public:Tile getTile(int x, int y);

/* Setter Method: Tile from tileBoard*/
public:void setTile(int x, int y, TileType type);

};

#endif // _MAZE_