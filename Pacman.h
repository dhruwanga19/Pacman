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
        void setAng(float ang);
        float getAng();
        void setScale(float scale);
        float getScale();
    private:

        int lives;
        float ang;
        float scale = 2;

};

#endif