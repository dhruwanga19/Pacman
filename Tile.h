/*****************************************************************//**
 * @file   Tile.h
 * @brief  This class is used to deal with the tiles that form the game board/maze, and determine thier type as well other varaibles.
 *
 * @author Ali Mohamed
 * @date   29/11/2022
***********************************************************************/
#pragma once

// Checks if _MAP IF DECLARED
#ifndef _TILE_

// Defines _MAP_ if above
// conditions fails
#define _TILE_

#include <include/raylib.h>
#include <string>

/**
 * @brief The type of tiles available based on standard layout of spritesheet, used for indicating frame from map spritesheet.
 */
enum TileType {EMPTY, V_WALL, H_WALL, TL_CORNER, TR_CORNER, BL_CORNER, BR_CORNER, DOOR};

class Tile{
	//bool legalTile;
	private:TileType tileType; // Defines what type of tile it is.
	private:int pellet; // Defines if it contains PELLET
	private:bool superPellet; // Defines if it has a super pellet.
	private:bool wall; // Defines if it is a wall
	private:bool pSpawn; // Defines Pacman Spawn point
	private:int gSpawn; // Defines Ghost Spawn point, and which ghost spawns here
	//private:Texture2D tileTexture; //Define Tile Texture

/**
 * Create a Tile object using DEFAULT parameters. 
 * (Empty tile with no special properties) 
 * @brief Default Constructor.
 * @see Tile(TileType type)
 * @see Tile(TileType type, bool p, int g)
 */
public:Tile();

/**
 * Create a Tile object of given type. 
 * @brief Constructor.
 * @param type Type of tile to be created.
 * @see Tile()
 * @see Tile(TileType type, bool p, int g)
 */
public:Tile(TileType type);

/**
 * Create a Tile object of given type, while indicating if tile is a spawn point for ghost and/or Pacman. 
 * @brief Constructor.
 * @param type Type of tile to be created.
 * @param p True if Pacman spawns here, false otherwise.
 * @param g True if Ghosts can spawn here, false otherwise.
 * @see Tile()
 * @see Tile(TileType type)
 */
public:Tile(TileType type, bool p, int g);

/* Destructor */
public:~Tile();

/**
 * @brief Getter Method: pellet.
 * @return 1 if it has pellet, 2 if it has Super Pellet, 0 if it has no pellet.
 */
public:int hasPellet();

/**
 * @brief Setter Method: pellet.
 * @param pellet Indicates what type of pellet is at this tile.
 */
public:void setPellet(int pellet);

/**
 * @brief Getter Method: SuperPellet.
 * @return True if tile has super pellet.
 */
public:bool hasSuperPellet();

/**
 * @brief Setter Method: SuperPellet.
 * @param pellet True if pellet spawns here, false otherwise.
 */
public:void setSuperPellet(bool pellet);

/**
 * @brief Getter Method: wall.
 * @return True if tile is a wall, false otherwise.
 */
public:bool isWall();

/**
 * @brief Setter Method: wall.
 * @param wall Indicates if the tile is/isn't a wall.
 */
public:void set_Wall(bool wall);

/**
 * @brief Getter Method: tileType.
 * @return Type of tile.
 */
public:TileType get_tileType();

/**
 * @brief Setter Method: tileType.
 * @param type Indicates what the type of the tile.
 * @see set_tileTypeEx(TileType type, bool p, int g)
 */
public:void set_tileType(TileType type);

/**
 * Set the type of tile object, while indicating if tile is a spawn point for ghost and/or Pacman.
 * @brief Setter Method: tileType Extended.
 * @param type Indicates what the type of the tile.
 * @param p True if Pacman spawns here, false otherwise.
 * @param g True if Ghosts can spawn here, false otherwise.
 * @see set_tileTypeEx(TileType type)
 */
public:void set_tileTypeEx(TileType type, bool p, int g);

/**
 * @brief Getter Method: pSpawn.
 * @return True if tile is a pacman spawn point, false otherwise.
 */
public:bool isPSpawn();

/**
 * @brief Setter Method: pSpawn.
 * @param p Indicates if Pacman can spawn at this tile.
 */
public:void setPSpawn(bool p);

/**
 * @brief Getter Method: gSpawn.
 * @return True if tile is a Ghost spawn point, false otherwise.
 */
public:int isGSpawn();

/**
 * @brief Setter Method: gSpawn.
 * @param g Indicates if Ghosts can spawn at this tile.
 */
public:void setGSpawn(int g);

};

#endif // _TILE_