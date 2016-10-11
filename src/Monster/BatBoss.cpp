#include "BatBoss.hpp"

BatBoss::BatBoss(SDL_Renderer	*gRenderer, int x, int y)
{
	_picture = new Image(gRenderer, "ressource/batboss.bmp", 255,255,255);//blanc invisible
	_animationDelay = SDL_GetTicks();//envoyer ou recevoir le get tick ?
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
	_Camera.w = 300;
	_Camera.h = 300;
	_dammage = 30;
	_life = 500;
	_moov = -2;
	_moovingDelay = SDL_GetTicks();
	_spawnDelay = SDL_GetTicks();
	_drop = 3;
	_score = 1000;
}

BatBoss::~BatBoss()
{

}

int BatBoss::getDammage(int amount)
{
	_life -= amount;
	return (_life);
}

int BatBoss::mooving(SDL_Rect heros)
{
	if (_moovingDelay + 20 < SDL_GetTicks() && (_Camera.x - heros.x) < 1400)
	{
		_pos_x += _moov;
		_moovingDelay = SDL_GetTicks();
	}
	if (_spawnDelay + 3000 < SDL_GetTicks() && (_Camera.x - heros.x) < 1000)
	{
		_spawnDelay = SDL_GetTicks();
		return (1);
	}
	return (0);
}

int BatBoss::getx()//changer ya deja un getposx dans entity alive
{
	return(_pos_x);
}