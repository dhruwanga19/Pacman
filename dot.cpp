#include "dot.h"

dot::dot(){
	this->x = 0;
	this->y = 0;
	Sprite s = Sprite("./assets/maps/textures/DEFAULT_TEXTURE");
	s.changeFrame(static_cast<int>(spriteType::PELLET));
	this->dotSprite = s;
	this->super = false;
}

dot::dot(float x, float y, Sprite s){
	this->x = x;
	this->y = y;
	s.changeFrame(static_cast<int>(spriteType::PELLET));
	this->dotSprite = s;
	this->super = false;
}

dot::dot(float x, float y, Sprite s, bool Super){
	this->x = x;
	this->y = y;
	if (Super) {
		s.changeFrame(static_cast<int>(spriteType::SUPER_PELLET));
	}
	else {
		s.changeFrame(static_cast<int>(spriteType::PELLET));
	}
	this->dotSprite = s;
	this->super = Super;
}
