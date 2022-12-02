/*****************************************************************//**
 * @file   Pacman.h
 * @brief  This class is used for the creation and management of Pacman Instances.
 *
 * @author Qiuhao Zeng
 * @date   29/11/2022
***********************************************************************/

#ifndef PACMAN

#define PACMAN

#include "Entity.h"

class Pacman: public Entity{

    public:
        /**
        * Construct a Pacman object.
        * @brief Default Constructor.
        */
        Pacman();
        /* Destructor */
        ~Pacman();
        /**
         * Get the number of lives pacman has. 
         * @brief Getter Method: numLives.
         * @return Number of lives left for Pacman.
         */
        int getLives();
        /**
         * Change number of lives of pacman to specific number.
         * @brief Setter Method: numLives.
         * @param Number of lives for pacman.
         */
        void setLives(int lives);
        // void move();
        /**
         * Change orientation of Pacman.
         * @brief Setter Method: ang.
         * @param ang Angle of rotation for Pacman.
         */
        void setAng(float ang);
        /**
         * Get the current orientation of Pacman.
         * @brief Getter Method: ang.
         * @return Angle of orientation for Pacman.
         */
        float getAng();
        /**
         * Set the scaling for the Pacman Sprite.
         * @brief Setter Method: scale.
         * @param scale Scale factor of Pacman Sprite.
         */
        void setScale(float scale);
        /**
         * Get the current scaling factor the Pacman Sprite.
         * @brief Getter Method: scale.
         * @return Scale factor of Pacman Sprite.
         */
        float getScale();

    private:
        /**
         * @brief Number of lives.
         */
        int lives;
        /**
         * @brief Angle of orientation.
         */
        float ang;
        /**
         * @brief Scale factor of Pacman sprite.
         */
        float scale = 2;

};

#endif