#include "Sprite.h"

Sprite::Sprite(std::string sPath) {
	this->texture = LoadTexture(sPath.c_str());
	this->frameSize = { 16, 16 };
	this->maxFrame = 19;
	this->framesWide = 16;
	this->origin = { 128, 16 };
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
