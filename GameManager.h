/*****************************************************************//**
 * @file   GameManager.h
 * @brief  This class is used to deal with the handling of events and functions during the main game loop.
 *
 * @author Connor and Qiuhao
 * @date   29/11/2022
***********************************************************************/
#pragma once

#ifndef _GameManager_

#define _GameManager_


#include "raylib.h"
//#include <unistd.h>
#include <string>
#include <vector>
#include <cmath>
#include "Maze.h"
#include "Ghost.h"
#include "Tile.h"

//enum pacmanSprites : int { OPEN, CLOSING, CLOSED };

//enum arrowKeys : int {UP, DOWN, LEFT, RIGHT};


class GameManager {
	private:
		/**
		 * @brief Vector storing ghost instances.
		 */
		std::vector<Ghost> ghosts; 
		/**
		 * @brief Maze Map Instance.
		 */
		Maze map = Maze("DEFAULT_MAP.txt");
		/**
		 * @brief Path to map sprite.
		 */
    	Sprite map_sprites = Sprite("./assets/maps/textures/DEFAULT_TEXTURE.png");
		/**
		 * @brief Pacman Sprite.
		 */
		Sprite pacman_sprite;
		/**
		 * @brief Red Ghost Sprite.
		 */
		Sprite red_ghost_sprite;
		/**
		 * @brief Blue Ghost Sprite.
		 */
		Sprite blue_ghost_sprite;
		/**
		 * @brief Pink Ghost Sprite.
		 */
		Sprite pink_ghost_sprite;
		/**
		 * @brief Orange Ghost Sprite.
		 */
		Sprite orange_ghost_sprite;
		/**
		 * @brief Pacman Instance.
		 */
		Pacman pacman = Pacman();
		/**
		 * @brief Red Ghost Instance.
		 */
		Ghost red_ghost = Ghost();
		/**
		 * @brief Blue Ghost Instance.
		 */
		Ghost blue_ghost = Ghost();
		/**
		 * @brief Pink Ghost Instance.
		 */
		Ghost pink_ghost = Ghost();
		/**
		 * @brief Orange Ghost Instance.
		 */
		Ghost orange_ghost = Ghost();
		/**
		 * @brief enum describing direction.
		 */
		enum arrowKeys : int { UP, DOWN, LEFT, RIGHT };
		/**
		 * @brief enum describing pacman frame.
		 */
		enum pacmanSprites : int { OPEN, CLOSING, CLOSED };
		/**
		 * @brief Default pacman sprite.
		 */
		Sprite pac_man_sprite = Sprite("./assets/sprites/DEFAULT_PACMAN.png", 14, 14, 1);
		/**
		 * @brief Flag to show the game is paused
		 */
		bool pause_flag;
		/**
		 * @brief Player Score.
		 */
		int score;
		/**
		 * @brief Number of Ghosts on maze.
		 */
		int num_ghosts;
		/**
		 * @brief Path to intro audio.
		 */
		const char *audio_intro = "./assets/music/pacman_beginning.wav";
		/**
		* @brief Path to pacman chomp SFX.
		*/
		const char *audio_effect1 = "./assets/music/pacman_chomp.wav";
		/**
		* @brief Animation Flag (CONNOR HELP)
		*/
		int flag;

	public:
		/**
		 * @brief Default constructor.
		 */
		GameManager();
		/**
		 * @brief Destructor
		 */
		~GameManager();
		/**
		 * @brief Start the game.
		 */
		void startGame();
		/**
		 * @brief Event: Player collides with ghost and loses a life.
		 */
		void knockGhost();
		/**
		 * @brief Pause the game.
		 */
		void pauseGame(); 
		/**
		 * @brief End the game.
		 */
		void endGame();
		/**
		 * TBC.
		 * @brief Draw Pacman and the ghosts.
		 */
		void displayFigures();
		/**
		 * TBC.
		 * @brief Draw the map
		 */
		void drawMap();
		/**
		 * Udate all active variables and check if any functions need to be excuted. (Run every frame)
		 * @brief Update Game variables
		 */
		void update();
		/**
		 * @brief Getter Method: Pacman Sprite
		 * @return Sprite of Pacman
		 */
		Sprite getPacmanSprite();
		/**
		 * TBC.
		 * @brief Connor Please Describe this.
		 * @param frame
		 */
		void animateDown(int frame);
		/**
		 * TBC.
		 * @brief Connor Please Describe this.
		 * @param frame
		 */
		void animateUp(int frame);
		/**
		 * TBC.
		 * @brief Connor Please Describe this.
		 */
		void setFlagUp();
		/**
		 * TBC.
		 * @brief Connor Please Describe this.
		 */
		void setFlagDown();
		/**
		 * TBC.
		 * @brief Connor Please Describe this.
		 * @return 
		 */
		int  getFlag();
		void randomWalk(Ghost &ghost);
		int sampleDirection(Ghost ghost);
		std::vector<int> probing(Ghost ghost);
};

#endif
