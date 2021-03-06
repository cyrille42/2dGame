#include "Basic.hpp"

Basic::Basic(SDL_Renderer	*gRenderer, int x, int y, int moove)
{
	this->_dammage = 10;
	this->_picture = new Image(gRenderer, "ressource/epee.bmp", 255,255,255);
	int a,b;
	SDL_QueryTexture(_picture->getTexture(),NULL,NULL,&a,&b);

	_crop_img.x = 0;
	_crop_img.y = 0;
	_crop_img.w = a;
	_crop_img.h = b;
	_gRenderer = gRenderer;
	_pos_img.x = x;
	_pos_img.y = y;
	_startx = x;
	_starty = y;
	_pos_img.w = 50;
	_pos_img.h = 25;
	if (moove == -1)
	{
		_moov = 5;
		_dist = 250;
	}
	else
	{
		_moov = -5;
		_dist = -250;
		_pos_img.x = x - 61;
		_pos_img.y = y;
		_startx = x - 61;
		_starty = y;
	}
	_moovingDelay = SDL_GetTicks();
	_fireRate = 500;
	_name = "basic";
}

int Basic::mooving(/*float camerax*/)
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
