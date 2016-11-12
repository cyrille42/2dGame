#include "Background.hpp"

Background::Background(SDL_Renderer* gRenderer, std::string path, int x, int y, int Width, int Height)
{
	_gRenderer = gRenderer;
	_texture = new Image(_gRenderer, path.c_str());

	int a,b;

	SDL_QueryTexture(_texture->getTexture(),NULL,NULL,&a,&b);

	_crop.x = 0;
	_crop.y = 0;
	_crop.w = a;
	_crop.h = b;

	_pos_x = x;
	_pos_y = y;
	_Camera.w = Width;
	_Camera.h = Height;
}

Background::~Background()
{

}

void Background::draw(int camerax, int cameray)
{
	this->_Camera.x = this->_pos_x + camerax;
	this->_Camera.y = this->_pos_y + cameray;
	SDL_RenderCopy( this->_gRenderer, this->_texture->getTexture(), &this->_crop, &this->_Camera);
}
