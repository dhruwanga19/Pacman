#pragma once

#ifndef _GameManager_

#define _GameManager_


#include "include/raylib.h"
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
		std::vector<Ghost> ghosts;  // control all ghosts
		Maze map = Maze("DEFAULT_MAP.txt");
    	Sprite map_sprites = Sprite("./assets/maps/textures/DEFAULT_TEXTURE.png");
		Sprite pacman_sprite;
		Sprite red_ghost_sprite;
		Sprite blue_ghost_sprite;
		Sprite pink_ghost_sprite;
		Sprite orange_ghost_sprite;
		Pacman pacman = Pacman();
		Ghost red_ghost = Ghost();
		Ghost blue_ghost = Ghost();
		Ghost pink_ghost = Ghost();
		Ghost orange_ghost = Ghost();
		
		enum arrowKeys : int { UP, DOWN, LEFT, RIGHT };
		enum pacmanSprites : int { OPEN, CLOSING, CLOSED };
		Sprite pac_man_sprite = Sprite("./assets/sprites/DEFAULT_PACMAN.png", 14, 14, 1);
		bool pause_flag;  // flag to show the game is paused
		int score;
		int num_ghosts;
		const char *audio_intro = "./assets/music/pacman_beginning.wav";
		const char *audio_effect1 = "./assets/music/pacman_chomp.wav";
		int flag;

	public:
		GameManager();  // Default constructor
		~GameManager();  // Destructor
		void startGame();  // 
		void knockGhost(); // players encounters ghost and will be dead
		void pauseGame();  // 
		void endGame();  // 
		void displayFigures();  // draw figures: pacman and ghosts
		void drawMap();
		void update();
		Sprite getPacmanSprite();
		void animateDown(int frame);
		void animateUp(int frame);
		void setFlagUp();
		void setFlagDown();
		int  getFlag();
};

#endif
