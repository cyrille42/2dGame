#include "Bonus_Entity.hpp"

/*
** icone des arme
*/


Bonus_Entity::Bonus_Entity(SDL_Renderer* gRenderer,  std::string path, int x, int y, int Width, int Height, std::string name)
{/* verif si y a l'image pour eivter les segfault*/
	_gRenderer = gRenderer;
	_texture = new Image(_gRenderer, path.c_str(), 255,255,255);

	int a,b;

	SDL_QueryTexture(_texture->getTexture(),NULL,NULL,&a,&b);

	_crop.x = 0;
	_crop.y = 0;
	_crop.w = a;
	_crop.h = b;
	_name = name;
	_pos_x = x;
	_pos_y = y;
	_Camera.w = Width;
	_Camera.h = Height;
}

Bonus_Entity::~Bonus_Entity()
{

}

void Bonus_Entity::draw(int camerax, int cameray)
{
	this->_Camera.x = this->_pos_x + camerax;
	this->_Camera.y = this->_pos_y + cameray;
	SDL_RenderCopy( this->_gRenderer, this->_texture->getTexture(), &this->_crop, &this->_Camera);//crop = image couper , camera = pos image + camera
}

std::string Bonus_Entity::getName()
{
	return(_name);
}

int Bonus_Entity::getHit(SDL_Rect _posHeros)
{
	if(_posHeros.x < this->_Camera.x + this->_Camera.w &&
   _posHeros.x  + _posHeros.w > this->_Camera.x &&
   _posHeros.y  < this->_Camera.y + this->_Camera.h &&
   _posHeros.h + _posHeros.y  > this->_Camera.y)
	{
		return (1);
	}
	return (0);
}

int Bonus_Entity::getposx()
{
	return (_pos_x);
}

int Bonus_Entity::getposy()
{
	return (_pos_y);
}