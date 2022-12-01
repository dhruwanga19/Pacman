#include "Ghost.h"

Ghost::Ghost(){

    //set the sprite
    // setSearch(search);
    // setPacman(pacman);
    // setChaseLocation();


}

Ghost::~Ghost(){

    //set the sprite
    // setSearch(search);
    // setPacman(pacman);
    // setChaseLocation();


}


void Ghost::setSearch(int search){

    this->search = search;

}

int Ghost::getSearch(){

    return this->search;

}

bool Ghost::isVulnerable(){

    return this->vulnerable;

}

void Ghost::setVulnerable(bool vulnerability){

    this->vulnerable = vulnerability;

}

void Ghost::setPacman(Pacman pacman){

    this->pacman = pacman;

}

Pacman Ghost::getPacman(){

    return this->pacman;

}

void Ghost::setChaseLocation(){

    Tile tile = this->pacman.getCurrentTile();
    this->chaseLocation = tile;

}

Tile Ghost::getChaseLocation(){
    
    return this->chaseLocation;

}


