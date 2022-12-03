#include "dot.h"

dot::dot(){
	this->x = 0;
	this->y = 0;
	Sprite s = Sprite("./assets/maps/textures/DEFAULT_TEXTURE");
	s.changeFrame(static_cast<int>(spriteType::PELLET));
	this->dotSprite = s;
	this->super = false;
}

dot::dot(float x, float y){
	this->x = x;
	this->y = y;
	Sprite s = Sprite("./assets/maps/textures/DEFAULT_TEXTURE");
	s.changeFrame(static_cast<int>(spriteType::PELLET));
	this->dotSprite = s;
	this->super = false;
}

dot::dot(float x, float y, bool Super){
	this->x = x;
	this->y = y;
	Sprite s = Sprite("./assets/maps/textures/DEFAULT_TEXTURE");
	if (Super) {
		s.changeFrame(static_cast<int>(spriteType::SUPER_PELLET));
	}
	else {
		s.changeFrame(static_cast<int>(spriteType::PELLET));
	}
	this->dotSprite = s;
	this->super = Super;
}
