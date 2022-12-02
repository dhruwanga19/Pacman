/*****************************************************************//**
 * @file   Entity.h
 * @brief  This class is an abstract class used to create the framework for entities in the game(Pacman/Ghost)
 *
 * @author Connor
 * @date   29/11/2022
***********************************************************************/
#pragma once

#ifndef ENTITY

#define ENTITY

#include "raylib.h"
#include "Sprite.h"
#include "Tile.h"

/**
 * @brief enum indicating status of entity.
 */
enum Status {ALIVE, DEAD};
/**
 * @brief enum indicating direction of entity.
 */
enum Direction {UP, DOWN, LEFT, RIGHT};

class Entity{

    public:
    
    /**
     * @brief CONNOR HELP
     */
    Rectangle box;
    /**
     * @brief Default Constructor
     */
    Entity();

    //virtual void move() = 0;

    //virtual void respawn() = 0;

    /**
     * Set the x position of the entity
     * @brief Set x position
     * @param x
     */
    void setX(float x){

        this->xPosition = x;

    }
    /**
     * Set the y position of the entity
     * @brief Set y position
     * @param y
     */
    void setY(float y){

        this->yPosition = y;

    }
    /**
     * Get the x position of the entity
     * @brief Get x position
     * @return x coordinate of entity
     */
    float getX(){

        return this->xPosition;

    }
    /**
     * Get the y position of the entity
     * @brief Get y position
     * @return y coordinate of entity
     */
    float getY(){

        return this->yPosition;

    }
    /**
     * Returns whether entity is alive or dead.
     * @brief Check if entity is alive or dead.
     * @return 0 if alive, 1 if dead.
     */
    bool isDead(){

        return this->status;

    }
    /**
     * Sets wheteher entity is alive or dead.
     * @brief Setter Method: Entity status
     * @param status 0 = alive, 1 = dead
     */
    void setStatus(Status status){

        this->status = status; 

    }
    /**
     * Set direction of movement.
     * @brief Setter Method: Entity direction
     * @param direction (up, down, left, right: 0, 1, 2, 3)
     */
    void setDirection(Direction direction){

        this->direction = direction;

    }
    /**
     * Get direction of movement.
     * @brief Getter Method: Entity direction
     * @return (up, down, left, right: 0, 1, 2, 3)
     */
    Direction getDirection(){

        return this->direction;

    }
    /**
     * Set sprite of entity, calls Sprite constructor.
     * @brief Setter Method: Entity Sprite
     * @param sprite
     */
    void setSprite(Sprite sprite){

        this->sprite =sprite;

    }
    /**
     * Set currentTile to tile the entity is currently in.
     * @brief Setter Method: Current Tile of Entity.
     * @param tile The tile the entity is/will currently be.
     */
    void setCurrentTile(Tile tile){

        this->currentTile = tile;

    }
    /**
     * Get currentTile of the tile the entity is currently in.
     * @brief Getter Method: Current Tile of Entity.
     * @return currentTile.
     */
    Tile getCurrentTile(){

        return this->currentTile;

    }
    /**
     * Draw entity sprite at position (x,y).
     * @brief Draw entity sprite at suppiled position.
     * @param x row-wise reference.
     * @param y column-wise reference.
     */
    void drawSprite(int x, int y) {
    
        this->sprite.drawSprite(x, y, 0, 2, WHITE);

    }
    /**
     * Get the Entity Sprite.
     * @brief Getter Method: Entity Sprite.
     * @return Entity Sprite
     */
    Sprite getSprite() {
    
        return this->sprite;

    }

    protected:
    /**
     * @brief x position of entity.
     */
    float xPosition;
    /**
     * @brief y position of entity.
     */
    float yPosition;
    /**
     * @brief Entity Status.
     */
    Status status;
    /**
     * @brief Entity Direction.
     */
    Direction direction;
    /**
     * @brief Entity Sprite.
     */
    Sprite sprite;
    /**
     * @brief Current tile of Entity.
     */
    Tile currentTile;
    
};

#endif