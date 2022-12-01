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
	pacman.drawSprite(posX, posY, pacman.getAng(), pacman.getScale(), WHITE);

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
	int x_round = round(pacman.getX());
	int y_round = round(pacman.getY());

	if (IsKeyPressed(KEY_SPACE))
	{
		// Tile toTile = this->map.getTile(y,x-1);
		// std::cout<<map.getColLength()<<std::endl;
		// for(int i = 0; i < map.getColLength();i ++)
		// {
		// 	toTile = this->map.getTile(i,y);
		// 	std::cout<<toTile.isWall()<<std::endl;
		// }
		Tile toTile = this->map.getTile(x_round-1,y_round);
		std::cout<<!toTile.isWall()<<std::endl;

		toTile = this->map.getTile(x_round+1,y_round);
		std::cout<<!toTile.isWall()<<std::endl;

		
		toTile = this->map.getTile(x_round,y_round-1);
		std::cout<<!toTile.isWall()<<std::endl;

		
		toTile = this->map.getTile(x_round,y_round+1);
		std::cout<<!toTile.isWall()<<std::endl;
	}


	if (IsKeyDown(KEY_W) or IsKeyDown(KEY_UP))
	{

		// pac_man.setAng(270);

		// move forwards 
		if(map.checkInMaze(x_round-1,y_round)){
			Tile toTile = this->map.getTile(x_round-1,y_round);
			if (!toTile.isWall() or (toTile.isWall() and x_round<pacman.getX()))
			{
				float x = pacman.getX() - GetFrameTime() * 1.f;
				pacman.setX(x);
			}
			// else if (toTile.isWall() and x_round>pac_man.getX())
			// {
			// 	// compensate 
			// 	pac_man.setX(x_round);
			// }
		}
	}
	else if (IsKeyDown(KEY_S) or IsKeyDown(KEY_DOWN))
	{
		// pac_man.setAng(90);
		if(map.checkInMaze(x_round+1,y_round))
		{
			Tile toTile = this->map.getTile(x_round+1,y_round);
			if (!toTile.isWall() or (toTile.isWall() and x_round>pacman.getX()))
			{
				float x = pacman.getX() + GetFrameTime() * 1.f;
				pacman.setX(x);
			}
		}

		
	}
	else if (IsKeyDown(KEY_A) or IsKeyDown(KEY_LEFT) )
	{
		// pac_man.setAng(180);
		if(map.checkInMaze(x_round,y_round-1))
		{
			Tile toTile = this->map.getTile(x_round,y_round-1);
			if (!toTile.isWall() or (toTile.isWall() and y_round<pacman.getY()))
			{
				float y = pacman.getY() - GetFrameTime() * 1.f;
				pacman.setY(y);
			}
		}

		
	}
	else if (IsKeyDown(KEY_D) or IsKeyDown(KEY_RIGHT))
	{
		// pac_man.setAng(0);
		if(map.checkInMaze(x_round,y_round+1))
		{
			Tile toTile = this->map.getTile(x_round,y_round+1);
			if (!toTile.isWall() or (toTile.isWall() and y_round>pacman.getY()))
			{
				float y = pacman.getY() + GetFrameTime() * 1.f;
				pacman.setY(y);
			}
		}
	}
	drawMap();
	displayFigures();

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


