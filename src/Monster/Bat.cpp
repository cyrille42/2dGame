#include "Bat.hpp"

//init crop + set animation + setposcrop

//cree classe monstre

Bat::Bat(SDL_Renderer	*gRenderer, int x, int y)// do a bat
{
	this->_picture = new Image(gRenderer, "ressource/bat.bmp", 255,255,255);//blanc invisible
	this->_animationDelay = SDL_GetTicks();//envoyer ou recevoir le get tick ?
 	this->_frameX = 0;
 	this->_frameY = 0;
 	this->_gRenderer = gRenderer;
	int a,b;
	SDL_QueryTexture(_picture->getTexture(),NULL,NULL,&a,&b);

	this->_crop_entity.x = 0;
	this->_crop_entity.y = 0;
	this->_crop_entity.w = a;
	this->_crop_entity.h = b;
	this->_pos_x = x;
	this->_pos_y = y;
	this->_startx = x;
	this->_starty = y;
	this->_Camera.w = 50;
	this->_Camera.h = 50;
	this->_dammage = 10;
	this->_life = 15;
	this->_moov = 3;
	this->_moovingDelay = SDL_GetTicks();
	_dist = 250;
	_drop = 0;
	_score = 100;
}

Bat::Bat(SDL_Renderer	*gRenderer, int x, int y, int dist)//do a speed bat
{
	this->_picture = new Image(gRenderer, "ressource/bat.bmp", 255,255,255);//blanc invisible
	this->_animationDelay = SDL_GetTicks();//envoyer ou recevoir le get tick ?
 	this->_frameX = 0;
 	this->_frameY = 0;
 	this->_gRenderer = gRenderer;
	int a,b;
	SDL_QueryTexture(_picture->getTexture(),NULL,NULL,&a,&b);

	this->_crop_entity.x = 0;
	this->_crop_entity.y = 0;
	this->_crop_entity.w = a;
	this->_crop_entity.h = b;
	this->_pos_x = x;
	this->_pos_y = y;
	this->_startx = x;
	this->_starty = y;
	this->_Camera.w = 50;
	this->_Camera.h = 50;
	this->_dammage = 10;
	this->_life = 15;
	this->_moov = 3;
	this->_moovingDelay = SDL_GetTicks();
	_dist = dist;
	_drop = 0;
	_score  = 0;
}


Bat::Bat(SDL_Renderer	*gRenderer, int x, int y, int Width, int height)/* do a powerful bat*/
{
	this->_picture = new Image(gRenderer, "ressource/bat.bmp", 255,255,255);//blanc invisible
	this->_animationDelay = SDL_GetTicks();//envoyer ou recevoir le get tick ?
 	this->_frameX = 0;
 	this->_frameY = 0;
 	this->_gRenderer = gRenderer;
	int a,b;
	SDL_QueryTexture(_picture->getTexture(),NULL,NULL,&a,&b);

	this->_crop_entity.x = 0;
	this->_crop_entity.y = 0;
	this->_crop_entity.w = a;
	this->_crop_entity.h = b;
	this->_pos_x = x;
	this->_pos_y = y;
	this->_startx = x;
	this->_starty = y;
	this->_Camera.w = Width;
	this->_Camera.h = height;
	this->_dammage = 25;
	this->_life = 40;
	this->_moov = 5;
	_dist = 250;
	_drop = 1;
	_score = 500;
}



Bat::~Bat()
{

}

int Bat::getDammage(int amount)// faire get dammage comun avec player et add delaydegat en param mettre a0 sauf pour les boss
{
	this->_life -= amount;
	return (this->_life);
}

void Bat::mooving()
{
	if (this->_moovingDelay + 5 < SDL_GetTicks())
	{
		_pos_x -= _moov;
		this->_moovingDelay = SDL_GetTicks();
	}
}