#include "Maze.h"


Maze::Maze(){
	// Create text string
	std::string map_buffer[] = { 
		" ################### ",
		" #........#........# ",
		" #o##.###.#.###.##o# ",
		" #.................# ",
		" #.##.#.#####.#.##.# ",
		" #....#...#...#....# ",
		" ####.### # ###.#### ",
		"    #.#   1   #.#    ",
		"#####.# ##=## #.#####",
		"     .  #234#  .     ",
		"#####.# ##### #.#####",
		"    #.#       #.#    ",
		" ####.# ##### #.#### ",
		" #........#........# ",
		" #.##.###.#.###.##.# ",
		" #o.#.....P.....#.o# ",
		" ##.#.#.#####.#.#.## ",
		" #....#...#...#....# ",
		" #.######.#.######.# ",
		" #.................# ",
		" ################### " 
	};
	for (int i = 0; i < 21; i++) {
		for (int j = 0; j < map_buffer[i].length(); j++) {
			Tile newTile;
			switch (map_buffer[i][j]){
			case '#':
				newTile.set_Wall(true);
			case '.':
				newTile.setPellet(1);
			case 'o':
				newTile.setPellet(2);
			case 'P':
				newTile.setPSpawn(true);
			case '1':
				newTile.setGSpawn(1);
			case '2':
				newTile.setGSpawn(2);
			case '3':
				newTile.setGSpawn(3);
			case '4':
				newTile.setGSpawn(4);
			default:
				break;
			}
		}
	}
}

Maze::Maze(std::string mapFileName){
	//To be done
}

Maze::~Maze(){
	//Insert Destructor Here
}

void Maze::setTile(int x, int y, TileType type) {
	this->tileBoard[x][y] = Tile(type);
}

Tile Maze::getTile(int x, int y){
	return tileBoard[x][y];
}
