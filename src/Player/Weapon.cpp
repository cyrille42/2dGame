#include "Weapon.hpp"

Weapon::Weapon()
{
}//fmap de str pour cree les bonnes arme directement

Weapon::~Weapon()
{

}

int Weapon::getDammage()
{
	return (this->_dammage);
}

SDL_Rect Weapon::getPos()
{
	return (this->_pos_img);
}

int Weapon::getfireRate()
{
	return (this->_fireRate);
}

void Weapon::draw()
{
	SDL_RenderCopy( this->_gRenderer, this->_picture->getTexture(), &this->_crop_img, &this->_pos_img);
}

// Weapon  Weapon::newfire(int x, int y)//tire le weapon dans heros, faire calcule special pour armer special 
// {
// 	_pos_img.x = x;
// 	_pos_img.y = y;
// 	return (*this);
// }

void  Weapon::setpos(int x, int y)
{
	_pos_img.x = x;
	_pos_img.y = y;
	_startx = x;
	_starty = y;
}

std::string Weapon::getName()
{
	return (_name);
}

void Weapon::setMoove(int amount)
{
	_moov = amount;
}