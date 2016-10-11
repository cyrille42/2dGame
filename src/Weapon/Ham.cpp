#include "Ham.hpp"

Ham::Ham(SDL_Renderer	*gRenderer, int x, int y, int moove)
{
	this->_dammage = 20;
	this->_picture = new Image(gRenderer, "ressource/spear.bmp", 255,255,255);
	int a,b;
	SDL_QueryTexture(_picture->getTexture(),NULL,NULL,&a,&b);

	_name = "ham";
	_crop_img.x = 0;
	_crop_img.y = 0;
	_crop_img.w = a;
	_crop_img.h = b;
	_gRenderer = gRenderer;
	_pos_img.x = x;
	_pos_img.y = y;
	_pos_img.w = 40;
	_pos_img.h = 40;
	if (moove == -1)
	{
		_moov = 4;
		_dist = 200;
	}
	else
	{
		_moov = -4;
		_dist = -200;
		_pos_img.x = x - 81;
		_pos_img.y = y;
		_startx = x - 81;
		_starty = y;
	}
	_startx = x;
	_starty = y;

	_moovingDelay = SDL_GetTicks();
	_fireRate = 500;

}

int Ham::mooving()
{
	if (_moovingDelay + 5 < SDL_GetTicks())
	{
		_pos_img.x += _moov;
		if (_dist < 0)
		{
			if (_startx + _dist > _pos_img.x)
				return (1);
		}
		else
		{
			if (_startx + _dist < _pos_img.x)
				return (1);
		}
		_moovingDelay = SDL_GetTicks();
	}
	return (0);
}