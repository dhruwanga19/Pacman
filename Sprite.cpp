#include "Sprite.h"

Sprite::Sprite(){
	this->texture = LoadTexture("../MyGame/assets/maps/textures/DEFAULT_TEXTURE.png");
	this->frameSize = { 16, 16 };
	this->maxFrame = 19;
	this->framesWide = 16;
	this->origin = { 128, 16 };
	this->frame = 0;
}

Sprite::Sprite(std::string Sprite) {
	//std::string sPath;
	//sPath.append(SPRITE_PATH);
	//sPath.append(Sprite);
	//printf(sPath.c_str());
	this->texture = LoadTexture(Sprite.c_str());
	this->frameSize = { 16, 16 };
	this->maxFrame = 19;
	this->framesWide = 16;
	this->origin = { 128, 16 };
	this->frame = 0;
}

Sprite::Sprite(std::string Sprite, int numFrame, int framesWide, int framesTall){
	this->texture = LoadTexture(Sprite.c_str());
	this->frameSize = { 16, 16 };
	this->maxFrame = numFrame;
	this->framesWide = framesWide;
	//this->origin.x = (frameSize.x * framesWide) / 2;
	//this->origin.y = (frameSize.y * framesTall) / 2;
	this->origin = { 0,0 };
	this->frame = 0;
}

Sprite::~Sprite(){
	//UnloadTexture(this->texture);
}

void Sprite::changeFrame(int f){
	this->frame = f;
}

void Sprite::drawSprite(float x, float y, float ang, float scale, Color c) {
	// Determine origin
	float ox, oy;
	ox = (this->frame % this->framesWide) * this->frameSize.x;
	oy = (int)(this->frame / this->framesWide) * this->frameSize.y;
	// DrawTexture Variables
	Rectangle sourceRect = { ox, oy, this->frameSize.x, this->frameSize.y };
	Rectangle destRect = { x, y, this->frameSize.x * scale, this->frameSize.y * scale };
	Vector2 originV = { this->origin.x * scale, this->origin.y * scale };
	// Draw Texture
	DrawTexturePro(this->texture, sourceRect, destRect, originV, ang, c);
}
