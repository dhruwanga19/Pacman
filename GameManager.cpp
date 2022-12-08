/*****************************************************************//**
 * @file   GameManager.cpp
 * @brief  By Qiuhao part: Ghosts can randomly walk (function probing, sample direction); 
 * 		   			       Ghosts catch pacman, game over.
 * 		   			       pacman eat dot to earn score
 *         			       use keyboard to control the pacman
 * @date   29/11/2022
***********************************************************************/
#include "GameManager.h"
#define PACMAN_SPRITE_PATH "./assets/sprites/DEFAULT_PACMAN.png"
#define GHOST_SPRITE_PATH "./assets/sprites/DEFAULT_GHOST.png"


GameManager::GameManager(){
	/* find position of initial position of pac-man and ghosts 
				Loop over the whole maze first 			*/
	//num_ghosts = 4;
	//ghosts = std::vector<Ghost>(num_ghosts, Ghost());

	//	Initialize starting sprites for all characters
	pacman_sprite = Sprite(PACMAN_SPRITE_PATH, 14, 14, 1);
	red_ghost_sprite = Sprite(GHOST_SPRITE_PATH, 40, 8, 5);
	blue_ghost_sprite = Sprite(GHOST_SPRITE_PATH, 40, 8, 5);
	pink_ghost_sprite = Sprite(GHOST_SPRITE_PATH, 40, 8, 5);
	orange_ghost_sprite = Sprite(GHOST_SPRITE_PATH, 40, 8, 5);

	//	Change sprites to correct starting frame
	pacman_sprite.changeFrame(CLOSED);
	red_ghost_sprite.changeFrame(3);
	blue_ghost_sprite.changeFrame(20);
	pink_ghost_sprite.changeFrame(14);
	orange_ghost_sprite.changeFrame(28);

	// Set Pacman and Ghost sprites to respective objects
	pacman.setSprite(pacman_sprite);
	red_ghost.setSprite(red_ghost_sprite);
	blue_ghost.setSprite(blue_ghost_sprite);
	pink_ghost.setSprite(pink_ghost_sprite);
	orange_ghost.setSprite(orange_ghost_sprite);
	
	//	Check each tile for pacman and ghost starting positions. Set Pacman and Ghost coordinates accordingly.
	for (int i = 0; i < map.getRowLength(); i++)
	{
		for (int j = 0; j < map.getColLength(); j++)
		{
			Tile currentTile = this->map.getTile(i , j);

			if(currentTile.isPSpawn())	//	If tile is pacman spawn -> enter.
			{
				
				pacman.setX(j);
				pacman.setY(i);
				pacman.box = {float(i) * 8 * 4 - 16, float(j) * 8 * 4 - 16, 32, 32};
			}
			else if(currentTile.isGSpawn())	// If tile is ghost spawn -> enter switch statement.
			{
				switch (currentTile.isGSpawn())
				{
				case(1):
					red_ghost.setX(j);
					red_ghost.setY(i);
					red_ghost.box = {float(i) * 8 * 4 - 16, float(j) * 8 * 4 - 16, 32, 32};
					break;
				case(2):
					blue_ghost.setX(j);
					blue_ghost.setY(i);
					blue_ghost.box = {float(i) * 8 * 4 - 16, float(j) * 8 * 4 - 16, 32, 32};
					break;
				case(3):
					pink_ghost.setX(j);
					pink_ghost.setY(i);
					pink_ghost.box = {float(i) * 8 * 4 - 16, float(j) * 8 * 4 - 16, 32, 32};
					break;
				case(4):
					orange_ghost.setX(j);
					orange_ghost.setY(i);
					orange_ghost.box = {float(i) * 8 * 4 - 16, float(j) * 8 * 4 - 16, 32, 32};
					break;
				default:
					break;
					
				}
				
			}
		}
	}
}	

GameManager::~GameManager(){

}

// Draws pacman and the ghosts
void GameManager::displayFigures(){

	int posX = pacman.getX() * 8 * 4;
	int posY = pacman.getY() * 8 * 4;
	pac_man_sprite.drawSprite(posX, posY, pacman.getAng(), pacman.getScale(), WHITE);

	posX = red_ghost.getX() * 32;
	posY = red_ghost.getY() * 32;
	red_ghost.drawSprite(posX, posY);

	posX = blue_ghost.getX() * 32;
	posY = blue_ghost.getY() * 32;
	blue_ghost.drawSprite(posX, posY);

	posX = pink_ghost.getX() * 32;
	posY = pink_ghost.getY() * 32;
	pink_ghost.drawSprite(posX, posY);

	posX = orange_ghost.getX() * 32;
	posY = orange_ghost.getY() * 32;
	orange_ghost.drawSprite(posX, posY);

}

//	Draws the map by calling Map::drawMazeEx
void GameManager::drawMap(){

	map.drawMazeEX(map_sprites);
}

//	When called draws the map and displays pacman and ghosts
void GameManager::update(){

/*

	x is row-wise index
	y is column-wise index
	
	*/
	if(gameRun)
	{


		
		int x_round = round(pacman.getX());
		int y_round = round(pacman.getY());

		if (IsKeyPressed(KEY_SPACE))
		{
			float x = pacman.getX();
			float y = pacman.getY();
			std::cout<<"current"<<x<<","<<y<<std::endl;
			// loopDots();
			// Tile toTile = this->map.getTile(x_round,y_round);
			// std::cout<<map.getColLength()<<std::endl;
			// for(int i = 0; i < map.getColLength();i ++)
			// {
			// 	toTile = this->map.getTile(i,0);
			// 	std::cout<<toTile.isWall()<<std::endl;
			// }
			// Tile toTile = this->map.getTile(x_round-1,y_round);
			// std::cout<<!toTile.isWall()<<std::endl;

			// toTile = this->map.getTile(x_round+1,y_round);
			// std::cout<<!toTile.isWall()<<std::endl;

	
			// toTile = this->map.getTile(x_round,y_round-1);
			// std::cout<<!toTile.isWall()<<std::endl;

	
			// toTile = this->map.getTile(x_round,y_round+1);
			// std::cout<<!toTile.isWall()<<std::endl; 

			// std::cout<<y_round << ":" << pacman.getY()<<std::endl;
		}


		if (IsKeyDown(KEY_W) || IsKeyDown(KEY_UP))
		{
			if(map.checkInMaze(y_round-1,x_round))
			{
				Tile toTile = this->map.getTile(y_round-1,x_round);
				if (!toTile.isWall() || (toTile.isWall() && y_round<pacman.getY()))
				{
					float y = pacman.getY() - GetFrameTime() * 2.f;
					pacman.setY(y);
				}
			}
			

			// pac_man.setAng(270);

			// move forwards 
			
		}
		else if (IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN))
		{
			if(map.checkInMaze(y_round+1,x_round))
			{
				Tile toTile = this->map.getTile(y_round+1,x_round);
				if (!toTile.isWall() || (toTile.isWall() && y_round>pacman.getY()))
				{
					float y = pacman.getY() + GetFrameTime() * 2.f;
					pacman.setY(y);
				}
			}
			// pac_man.setAng(180);
			
		}
		else if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT) )
		{

			if(map.checkInMaze(y_round,x_round-1)){
				Tile toTile = this->map.getTile(y_round,x_round-1);
				if (!toTile.isWall() || (toTile.isWall() && x_round<pacman.getX()))
				{
					float x = pacman.getX() - GetFrameTime() * 2.f;
					pacman.setX(x);
				}
			}
		}
		else if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT))
		{
			// pac_man.setAng(90);
			if(map.checkInMaze(y_round,x_round+1))
			{
				Tile toTile = this->map.getTile(y_round,x_round+1);
				if (!toTile.isWall() || (toTile.isWall() && x_round>pacman.getX()))
				{
					float x = pacman.getX() + GetFrameTime() * 2.f;
					pacman.setX(x);
				}
			}
			// pac_man.setAng(0);

		}
		randomWalk(red_ghost);
		randomWalk(blue_ghost);
		randomWalk(pink_ghost);
		randomWalk(orange_ghost);
		loopDots();
		drawMap();
		displayFigures();
	}
	else{
			DrawText("GAME OVER! PRESS exit TO QUIT!", 60, GetScreenWidth()/2 - 10, 30, PURPLE);
	}

}

Sprite GameManager::getPacmanSprite() {

	return pacman.getSprite();


}

//Animates pacman eating
void GameManager::animateDown(int frame) {

	int currentFrame = frame;	// Get current index of frame used by pacman sprite

	currentFrame = currentFrame - 1;	// Increment frame index

	if (currentFrame == 0)	//	If index is now 2, set flag to 0 to change to decrementing (calling animateDown())
		setFlagUp();

	Sprite temp = pacman.getSprite();	//	Fetch and change sprite frame

	temp.changeFrame(currentFrame);

	pacman.setSprite(temp);
		

}

//Animates pacman eating
void GameManager::animateUp(int frame) {

	int currentFrame = frame;	// Get current index of frame used by pacman sprite

	currentFrame += 1;	// Increment frame index

	if (currentFrame == 2)	//	If index is now 2, set flag to 0 to change to decrementing (calling animateDown())
		setFlagDown();

	Sprite temp = pacman.getSprite();	//	Fetch and change sprite frame

	temp.changeFrame(currentFrame);

	pacman.setSprite(temp);


}

//Sets flag for animation
void GameManager::setFlagDown(){

	this->flag = 0;

}

//Sets flag for animation
void GameManager::setFlagUp(){

	this->flag = 1;

}

//Flag for animation
int GameManager::getFlag() {
	return this->flag;
}

void GameManager::catchPacman(Ghost ghost)
{
	if((fabs(ghost.getX()-pacman.getX())<0.3) && (fabs(ghost.getY()-pacman.getY())<0.3))
	{
		gameRun = false;
		DrawText("GAME OVER! PRESS exit TO QUIT!", GetScreenWidth()/2 - 100, GetScreenWidth()/2 - 10, 30, PURPLE);
	}
}

void GameManager::randomWalk(Ghost &ghost){
	// approximate the coordinate of the ghost to the nearest point
	catchPacman(ghost);
	int x_round = round(ghost.getX());
	int y_round = round(ghost.getY());

	// if (IsKeyPressed(KEY_SPACE))
	// {
	// 	std::cout<<"x: " <<ghost.getX()<<std::endl;
	// 	std::cout<<"y: " <<ghost.getY()<<std::endl;
	// }

	if (ghost.curDirection == 0)
	{
		if(map.checkInMaze(y_round-1,x_round))
		{
			Tile toTile = this->map.getTile(y_round-1,x_round);
			if (!toTile.isWall() || (toTile.isWall() && y_round<ghost.getY()))
			{
				float y = ghost.getY() - GetFrameTime() * 2.f;
				ghost.setY(y);
			}
			else
			{
				ghost.curDirection = sampleDirection(ghost);
			}
		}
		
		
		// pac_man.setAng(270);

		// move forwards 
		
	}
	else if (ghost.curDirection == 1)
	{
		if(map.checkInMaze(y_round+1,x_round))
		{
			Tile toTile = this->map.getTile(y_round+1,x_round);
			if (!toTile.isWall() || (toTile.isWall() && y_round>ghost.getY()))
			{
				float y = ghost.getY() + GetFrameTime() * 2.f;
				ghost.setY(y);
			}
			else
			{
				ghost.curDirection = sampleDirection(ghost);
			}
		}
		// pac_man.setAng(180);

	}
	else if (ghost.curDirection == 2 )
	{

		if(map.checkInMaze(y_round,x_round-1)){
			Tile toTile = this->map.getTile(y_round,x_round-1);
			if (!toTile.isWall() || (toTile.isWall() && x_round<ghost.getX()))
			{
				float x = ghost.getX() - GetFrameTime() * 2.f;
				ghost.setX(x);
			}
			else
			{
				ghost.curDirection = sampleDirection(ghost);
			}
		}
	}
	else if (ghost.curDirection == 3)
	{
		// pac_man.setAng(90);
		if(map.checkInMaze(y_round,x_round+1))
		{
			Tile toTile = this->map.getTile(y_round,x_round+1);
			if (!toTile.isWall() || (toTile.isWall() && x_round>ghost.getX()))
			{
				float x = ghost.getX() + GetFrameTime() * 2.f;
				ghost.setX(x);
			}
			else
			{
				ghost.curDirection = sampleDirection(ghost);
			}
		}
		// pac_man.setAng(0);

}
	std::vector<int> avaiDirectionList = probing(ghost);
	int avaiDirection = avaiDirectionList.size();
	if (avaiDirection > ghost.currentAvailDirection)
	{
		ghost.canChangeDir = true;
		ghost.currentAvailDirection = avaiDirection;
	}
	else if (avaiDirection < ghost.currentAvailDirection)
	{
		ghost.currentAvailDirection = avaiDirection;
	}
	// fabs for float version abs
	if(ghost.canChangeDir && (fabs(float(y_round)-ghost.getY())<0.01) && (fabs(float(x_round)-ghost.getX())<0.01))
	{
		ghost.canChangeDir = false;
		ghost.curDirection = sampleDirection(ghost);
	}
	if(fabs(ghost.getX())<0.5)
	{
		ghost.curDirection = 3;
	}
	if(fabs(ghost.getX()-map.getColLength()+1)<0.5)
	{
		ghost.curDirection = 2;
	}
}


int GameManager::sampleDirection(Ghost ghost){
	std::vector<int> available_direction = probing(ghost);
	int index = rand() % available_direction.size(); // pick a random index
	return available_direction[index]; // sample a new direction
}

std::vector<int> GameManager::probing(Ghost ghost){
	int x_round = round(ghost.getX());
	int y_round = round(ghost.getY());
	std::vector<int> available_direction;
	Tile upTile = this->map.getTile(y_round-1,x_round);
	if (!upTile.isWall())
	{
		available_direction.push_back(0);
	}

	Tile downTile = this->map.getTile(y_round+1,x_round);
	if (!downTile.isWall())
	{
		available_direction.push_back(1);
	}
	Tile leftTile = this->map.getTile(y_round,x_round-1);
	if (!leftTile.isWall())
	{
		available_direction.push_back(2);
	}
	Tile rightTile = this->map.getTile(y_round,x_round+1);
	if (!rightTile.isWall())
	{
		available_direction.push_back(3);
	}
	return available_direction;
}

void GameManager::loopDots(){
	float closest = 100;
	float cx = -1;
	float cy = -1;
	float x = pacman.getY();  // row
	float y = pacman.getX();
	for(int i = 0; i < map.dots.size(); i++)
	{
		// std::cout<<map.dots[i].getX()<<","<<map.dots[i].getY()<<std::endl;

		if(fabs(map.dots[i].getY()-y) + fabs(map.dots[i].getX()-x) < closest)
		{
			closest = fabs(map.dots[i].getY()-y) + fabs(map.dots[i].getX()-x);
			cx = map.dots[i].getX();
			cy = map.dots[i].getY();
		}
		if((fabs(map.dots[i].getY()-y)<0.3) && (fabs(map.dots[i].getX()-x)<0.3))
		{
			map.disableDot(map.dots[i].getX(),map.dots[i].getY());
			map.dots.erase(map.dots.begin() + i);
			this->score++;
			displayScore = true;
		}
	}
	// std::cout<<cx<<","<<cy<<std::endl;
	// std::cout<<"current"<<x<<","<<y<<std::endl;
	if (displayScore && score > 0)
	{
		displayTime += GetFrameTime();
		DrawText(TextFormat("Score: %i!", score), GetScreenWidth()/2 - 100, GetScreenWidth()/2 - 10, 20, YELLOW);
		if (displayTime >= 1)
		{
			displayTime = 0;
			displayScore = false;
		}
	}

}