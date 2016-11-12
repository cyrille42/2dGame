#include "Block.hpp"

Block::Block(SDL_Renderer* gRenderer, std::string path, int x, int y, int Width, int Height)
{
	this->_gRenderer = gRenderer;
	this->_texture = new Image(this->_gRenderer, path.c_str());

 int a,b;

 SDL_QueryTexture(_texture->getTexture(),NULL,NULL,&a,&b);

	this->_crop.x = 0;
	this->_crop.y = 0;
	this->_crop.w = a;
	this->_crop.h = b;

	this->_pos_x = x;
	this->_pos_y = y;
	this->_Camera.w = Width;
	this->_Camera.h = Height;
}

Block::~Block()
{

}

void Block::draw(int camerax, int cameray)
{

	this->_Camera.x = this->_pos_x + camerax;
	this->_Camera.y = this->_pos_y + cameray;
	SDL_RenderCopy( this->_gRenderer, this->_texture->getTexture(), &this->_crop, &this->_Camera);
}

int Block::getHitUp(SDL_Rect _posHeros)
{
	if(_posHeros.x < this->_Camera.x + this->_Camera.w &&
   _posHeros.x  + _posHeros.w > this->_Camera.x &&
   _posHeros.y - 3 < this->_Camera.y + this->_Camera.h &&
   _posHeros.h + _posHeros.y - 3 > this->_Camera.y)
	{
		return (1);
	}
	return (0);
}

int Block::getHitDown(SDL_Rect _posHeros)
{
	if(_posHeros.x < this->_Camera.x + this->_Camera.w &&
   _posHeros.x + _posHeros.w > this->_Camera.x &&
   _posHeros.y + 3 < this->_Camera.y + this->_Camera.h &&
   _posHeros.h + _posHeros.y + 3 > this->_Camera.y)
	{
		return (1);
	}
	return (0);
}

int Block::getHitRight(SDL_Rect _posHeros)
{
		if(_posHeros.x + 3 < this->_Camera.x + this->_Camera.w &&
   _posHeros.x + 3 + _posHeros.w > this->_Camera.x &&
   _posHeros.y < this->_Camera.y + this->_Camera.h &&
   _posHeros.h + _posHeros.y > this->_Camera.y)
	{
		return (1);
	}
	return (0);
}
int Block::getHitLeft(SDL_Rect _posHeros)
{
		if(_posHeros.x - 1 < this->_Camera.x + this->_Camera.w &&
   _posHeros.x - 1 + _posHeros.w > this->_Camera.x &&
   _posHeros.y < this->_Camera.y + this->_Camera.h &&
   _posHeros.h + _posHeros.y > this->_Camera.y)
	{
		return (1);
	}
	return (0);
}
