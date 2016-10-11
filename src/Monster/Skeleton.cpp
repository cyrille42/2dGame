#include "Skeleton.hpp"

Skeleton::Skeleton(SDL_Renderer	*gRenderer, int x, int y)
{
	_picture = new Image(gRenderer, "ressource/skeleton.bmp", 255,255,255);
	_animationDelay = SDL_GetTicks();
 	_frameX = 0;
 	_frameY = 0;
 	_gRenderer = gRenderer;
	int a,b;
	SDL_QueryTexture(_picture->getTexture(),NULL,NULL,&a,&b);

	_crop_entity.x = 0;
	_crop_entity.y = 0;
	_crop_entity.w = a;
	_crop_entity.h = b;
	_pos_x = x;
	_pos_y = y;
	_startx = x;
	_starty = y;
	_Camera.w = 80;
	_Camera.h = 100;
	_dammage = 5;
	_life = 50;
	_moov = -2;
	_moovingDelay = SDL_GetTicks();
	_fireDelay = SDL_GetTicks();
	_drop = 0.5;
	_score = 400;
	Weapon *weapon = new Bones(_gRenderer, x, y, 1);
	_weapon = weapon;
	_weapon->setMoove(-5);
}

Skeleton::~Skeleton()
{

}

int Skeleton::getDammage(int amount)
{
	_life -= amount;
	return (_life);
}

int Skeleton::mooving(SDL_Rect heros)
{
	if (_moovingDelay + 20 < SDL_GetTicks() && (_Camera.x - heros.x) < 1400)
	{
		_pos_x += _moov;
		_moovingDelay = SDL_GetTicks();
	}
	if (_fireDelay + 3000 < SDL_GetTicks() && (_Camera.x - heros.x) < 1000)
	{
		_fireDelay = SDL_GetTicks();
		return (1);
	}
	return (0);
}


