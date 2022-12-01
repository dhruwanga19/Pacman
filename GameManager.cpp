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
	for (int i = 0; i < map.getColLength(); i++)
	{
		for (int j = 0; j < map.getRowLength(); j++)
		{
			Tile currentTile = this->map.getTile(i , j);

			if(currentTile.isPSpawn())	//	If tile is pacman spawn -> enter.
			{
				
				pacman.setX(j);
		
				pacman.setY(i);
			}
			else if(currentTile.isGSpawn())	// If tile is ghost spawn -> enter switch statement.
			{
				switch (currentTile.isGSpawn())
				{
				case(1):
					red_ghost.setX(j);
					red_ghost.setY(i);
					break;
				case(2):
					blue_ghost.setX(j);
					blue_ghost.setY(i);
					break;
				case(3):
					pink_ghost.setX(j);
					pink_ghost.setY(i);
					break;
				case(4):
					orange_ghost.setX(j);
					orange_ghost.setY(i);
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
	pacman.drawSprite(posX, posY);

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


