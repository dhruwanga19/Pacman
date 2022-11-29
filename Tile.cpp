#include "Tile.h"

Tile::Tile(){
	this->tileType = EMPTY;
	this->pellet = false;
	this->superPellet = false;
	this->wall = false;
	this->pSpawn = false;
	this->gSpawn = false;
}

Tile::Tile(TileType type){
	this->tileType = type;
	this->pellet = false;
	this->superPellet = false;
	if (type != EMPTY) {
		this->wall = true;
	}
	else {
		this->wall = false;
	}
	this->pSpawn = false;
	this->gSpawn = false;
}

Tile::Tile(TileType type, bool p, int g){
	this->tileType = type;
	this->pellet = false;
	this->superPellet = false;
	if (type != EMPTY) {
		this->wall = true;
	}
	else {
		this->wall = false;
	}
	this->pSpawn = p;
	this->gSpawn = g;
}

Tile::~Tile(){
	//Insert Destructor Here
}

int Tile::hasPellet(){
	return this->pellet;
}

void Tile::setPellet(int pellet){
	this->pellet = pellet;
}

bool Tile::hasSuperPellet() {
	return this->superPellet;
}

void Tile::setSuperPellet(bool pellet) {
	this->superPellet = pellet;
}

bool Tile::isWall(){
	return this->wall;
}

void Tile::set_Wall(bool wall) {
	this->wall = wall;
}

TileType Tile::get_tileType(){
	return this->tileType;
}

void Tile::set_tileType(TileType type){
	this->tileType = type;
}

void Tile::set_tileTypeEx(TileType type, bool p, int g) {
	this->tileType = type;
	this->pSpawn = p;
	this->gSpawn = g;
}

bool Tile::isPSpawn(){
	return this->pSpawn;
}

void Tile::setPSpawn(bool p){
	this->pSpawn = p;
}

int Tile::isGSpawn(){
	return this->gSpawn;
}

void Tile::setGSpawn(int g){
	this->gSpawn = g;
}
