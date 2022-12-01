#include "Entity.h"

#ifndef PACMAN

#define PACMAN

class Pacman: public Entity{

    public:
        /* Default constructor  */
        Pacman();
        ~Pacman();
        int getLives();
        void setLives(int lives);
        // void move();
        
    private:

        int lives;

};

#endif