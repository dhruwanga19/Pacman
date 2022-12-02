#include "Entity.h"
#include "Pacman.h"

#ifndef GHOST

#define GHOST

class Ghost: public Entity{

public:
    Ghost();
    Ghost(int search, Pacman pacman);
    ~Ghost();
    int curDirection = 0;
    enum movingDirections : int { UP, DOWN, LEFT, RIGHT };
    void setSearch(int search);
    int getSearch();
    bool isVulnerable();
    void setVulnerable(bool vulnerability);
    void setPacman(Pacman pacman);
    Pacman getPacman();
    void setChaseLocation();
    Tile getChaseLocation();
    int currentAvailDirection = 2;
    bool canChangeDir = false;


private:
    int search; 
    bool vulnerable;    // Holds ghosts vulnerability state (can be eaten or not)
    Pacman pacman;  // Current Pacman
    Tile chaseLocation; // Stores current Pacman's location for chasing

};

#endif