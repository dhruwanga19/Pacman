#pragma once

#ifndef ENTITY

#define ENTITY

#include "include\raylib.h"
#include "Sprite.h"
#include "Tile.h"

enum Status {ALIVE, DEAD};

enum Direction {UP, DOWN, LEFT, RIGHT};

class Entity{

    public:

    Entity();

    //virtual void move() = 0;

    //virtual void respawn() = 0;

    // Set x position
    void setX(int x){

        this->xPosition = x;

    }

    // Set y position
    void setY(int y){

        this->yPosition = y;

    }

    // Get x position
    int getX(){

        return this->xPosition;

    }

    //  Get y position
    int getY(){

        return this->yPosition;

    }

    //  Returns whether entity is alive or dead (0 = alive, 1 = dead)
    bool isDead(){

        return this->status;

    }

    //  Sets wheteher entity is alive or dead (0 = alive, 1 = dead)
    void setStatus(Status status){

        this->status = status; 

    }

    //  Set direction of movement (up, down, left, right: 0, 1, 2, 3)
    void setDirection(Direction direction){

        this->direction = direction;

    }

    // Get direction of movement (up, down, left, right: 0, 1, 2, 3)
    Direction getDirection(){

        return this->direction;

    }

    //  Set sprite, calls Sprite constructor
    void setSprite(Sprite sprite){

        this->sprite =sprite;

    }

    //  Set currentTile to tile the entity is currently in
    void setCurrentTile(Tile tile){

        this->currentTile = tile;

    }

    //  Get currentTile to tile the entity is currently in
    Tile getCurrentTile(){

        return this->currentTile;

    }

    void drawSprite(int x, int y) {
    
        this->sprite.drawSprite(x, y, 0, 2, WHITE);

    }

    Sprite getSprite() {
    
        return this->sprite;

    }

    protected:

    int xPosition;
    int yPosition;
    Status status;
    Direction direction;
    Sprite sprite;
    Tile currentTile;
    
};

#endif