#include "Entity.h"
#include "Pacman.h"

#ifndef GHOST

#define GHOST

class Ghost: public Entity{

public:
    Ghost();
    Ghost(int search, Pacman pacman);
    ~Ghost();
    void setSearch(int search);
    int getSearch();
    bool isVulnerable();
    void setVulnerable(bool vulnerability);
    void setPacman(Pacman pacman);
    Pacman getPacman();
    void setChaseLocation();
    Tile getChaseLocation();


private:
    int search; 
    bool vulnerable;    // Holds ghosts vulnerability state (can be eaten or not)
    Pacman pacman;  // Current Pacman
    Tile chaseLocation; // Stores current Pacman's location for chasing

};

#endif