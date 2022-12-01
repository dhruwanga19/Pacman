/*****************************************************************//**
 * @file   Sprite.h
 * @brief  This class is used to deal with the importing of spritesheets and rendering of sprites/textures.
 *
 * @author Ali Mohamed
 * @date   29/11/2022
***********************************************************************/
#pragma once

// Checks if _SPRITE_ IF DECLARED
#ifndef _SPRITE_

// Defines _SPRITE_ if above
// conditions fails
#define _SPRITE_

#include <include/raylib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

/**
 * @brief Default location of where sprite assets are stored.
 */
const std::string SPRITE_PATH = "./assets/sprites/";

/**
 * @brief The type of sprites available based on standard layout of spritesheet, used for indicating frame from spritesheet.
 */
enum class spriteType : int { SINGLE, UP_END, RIGHT_END, TR_CORNER, LEFT_END, TL_CORNER, H_STRAIGHT, LDR_T, DOWN_END, V_STRAIGHT, BR_CORNER, ULD_T, BL_CORNER, DRU_T, RUL_T, INTERSECTION, PELLET, SUPER_PELLET, DOOR };

class Sprite {
    /**
     * @brief Texture object storing current texture of sprite.
     */
    Texture2D texture;
    /**
     * @brief Size of frame from spritesheet.
     */
    Vector2 frameSize;
    /**
     * @brief Number of frames in spritesheet.
     */
    int maxFrame;
    /**
     * @brief Number of frames per row.
     */
    int framesWide;
    /**
     * @brief Center of frame, this is also the pivot of rotation.
     */
    Vector2 origin;
    /**
     * @brief Frame Number of spritesheet..
     */
    int frame;

    /**
     * Create a sprite object using the default spritesheet.
     * @brief Default constructor.
     * @see Sprite(std::string Sprite)
     * @see Sprite(std::string Sprite, int numFrame, int framesWide, int framesTall)
     */
public:Sprite();

      /**
       * Create a sprite object using the supplied spritesheet.
       * @brief Constructor.
       * @param Sprite The path where the spritesheet is located.
       * @deprecated Only use for testing, may cause Memory Leaks.
       * @see Sprite()
       * @see Sprite(std::string Sprite, int numFrame, int framesWide, int framesTall)
       */
public:Sprite(std::string Sprite);

      /**
       * Create a sprite object using the supplied spritesheet, with adjustable dimensions.
       * @brief Constructor.
       * @param Sprite The path where the spritesheet is located
       * @see Sprite()
       * @see Sprite(std::string Sprite, int numFrame, int framesWide, int framesTall)
       */
public:Sprite(std::string Sprite, int numFrame, int framesWide, int framesTall);

      /* Destructor*/
public:~Sprite();

      /**
       * @brief Change the frame in spritesheet.
       * @param f The frame number, to change to.
       */
public:void changeFrame(int f);

      /**
       * @brief Get the current frame number.
       */
public: int getFrame();

      /**
       * @brief Draw the Sprite given position, angle, scale and color.
       * @param x Horizontal position of Sprite
       * @param y Vertical position of Sprite
       * @param ang Rotation angle of Sprite
       * @param scale The magnitude at which the sprite is drawn 
       * @param c Color option, set to WHITE for no tinting.
       */
public:void drawSprite(float x, float y, float ang, float scale, Color c);

};

#endif // _SPRITE_