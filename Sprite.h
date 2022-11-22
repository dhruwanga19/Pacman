#pragma once

// Checks if _SPRITE_ IF DECLARED
#ifndef _SPRITE_

// Defines _SPRITE_ if above
// conditions fails
#define _SPRITE_

#include <raylib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

const std::string SPRITE_PATH = "../MyGame/assets/sprites/";

enum class spriteType : int { SINGLE, UP_END, RIGHT_END, TR_CORNER, LEFT_END, TL_CORNER, H_STRAIGHT, LDR_T, DOWN_END, V_STRAIGHT, BR_CORNER, ULD_T, BL_CORNER, DRU_T, RUL_T, INTERSECTION, PELLET, SUPER_PELLET, DOOR };

class Sprite {
    Texture2D texture;
    Vector2 frameSize;
    int maxFrame;
    int framesWide;
    Vector2 origin;
    int frame;

/* Constructor */
public:Sprite(std::string Sprite);

/* Destructor*/
public:~Sprite();

/* Change the frame in spritesheet, to change which sprite it is targetting*/
public:void changeFrame(int f);

/* Draw the Sprite */
public:void drawSprite(float x, float y, float ang, float scale, Color c);

};

#endif // _SPRITE_