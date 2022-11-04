#pragma once

// Checks if _MAP IF DECLARED
#ifndef _TILE_

// Defines _MAP_ if above
// conditions fails
#define _TILE_

#include <raylib.h>
#include <string>

enum TileType {EMPTY, V_WALL, H_WALL, TL_CORNER, TR_CORNER, BL_CORNER, BR_CORNER, DOOR};

class Tile{
	//bool legalTile;
	private:TileType tileType;
	private:int pellet; //Defines if it contains a Pellet or Super Pellet
	private:bool wall; //Defines if it is a wall
	private:bool pSpawn; // Defines Pacman Spawn point
	private:int gSpawn; // Defines Ghost Spawn point, and which ghost spawns here

/* DEFAULT Constructor */
public:Tile();

/* Detailed Constructor*/
public:Tile(TileType type);

/* More Detailed Constructor */
public:Tile(TileType type, bool p, int g);

/* Destructor */
public:~Tile();

/* Getter Method: pellet*/
public:int hasPellet();

/* Setter Method: pellet*/
public:void setPellet(int pellet);

/* Getter Method: wall */
public:bool isWall();

/* Setter Method: wall */
public:void set_Wall(bool wall);

/* Getter Method: tileType */
public:TileType get_tileType();

/* Setter Method: tileType */
public:void set_tileType(TileType type);

/* Setter Method: tileType Extended */
public:void set_tileTypeEx(TileType type, bool p, int g);

/* Getter Method: pSpawn */
public:bool isPSpawn();

/* Setter Method: pSpawn */
public:void setPSpawn(bool p);

/* Getter Method: gSpawn */
public:int isGSpawn();

/* Setter Method: gSpawn */
public:void setGSpawn(int g);

};

#endif // _TILE_