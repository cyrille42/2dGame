#include "Entity_alive.hpp"

Entity::Entity()
{
	this->_jumpDelay = SDL_GetTicks();
	this->_gravityDelay = SDL_GetTicks();
}

Entity::~Entity()
{

}


void Entity::initcrop()//init le decoupage de l image pour les animation // mais apparament sa ser a rien
{
	int a,b;

	SDL_QueryTexture(this->_picture->getTexture(),NULL,NULL,&a,&b);
	// SDL_Rect crop;

	// crop.x = x;//dist du depart de limage sera toujorus a 0 sauf cas particulier ?
	// crop.y = y;
	// crop.w = a;
	// crop.h = b;
	this->_crop_Width = a;
	this->_crop_Height = b;
	// this->_crop_entity = crop;
	this->_curentFrame = 0;
}

void Entity::PlayAnimation(int BeginFrame, int EndFrame, int Row, float speed)
{
	if (_animationDelay + speed < SDL_GetTicks())
	{
		if (EndFrame <= _curentFrame)
			_curentFrame = BeginFrame;
		else
			_curentFrame++;
		_crop_entity.x = _curentFrame * (_crop_Width / _frameX);
		_crop_entity.y = Row * (_crop_Height / _frameY);
		_crop_entity.w = _crop_Width / _frameX;
		_crop_entity.h = _crop_Height / _frameY;
		_animationDelay = SDL_GetTicks();
	}
}

SDL_Rect Entity::getCrop()
{
	return (_pos_entity);
}

float Entity::Gravity()//saplique aussi au mob ?//que au perso a changer
{//retourne une valeur de graviter a retirer de cameray
	if (_gravityDelay + 5 < SDL_GetTicks())
	{
		_gravityDelay = SDL_GetTicks();
		return (5);
	}
	return (0);
}

float Entity::Jump()//jump et gravity on un cd car ilsont dans la boucle rapide
{
	if (_jumpDelay + 5 < SDL_GetTicks())
	{
		_jumpDelay = SDL_GetTicks();
		return (5);
	}
	return (0);
}

void Entity::fireWeapon(int moove)//envoyer 	camera ici pour lenvoyer dans la creaiton des weapon
{
	if (_fireDelay + _weapon->getfireRate() < SDL_GetTicks())//c'est le setpos qui changer tout en pointeur , faut foutre les adress
	{
		//remplacer par un fmap
		if (_weapon->getName() == "basic")
		{
			//pos entity = pos personnage
			_fireWeapon.push_back(new Basic(_gRenderer, _pos_entity.x + _pos_entity.w - 20, _pos_entity.y + (_pos_entity.h / 2), moove));
		}
		else if (_weapon->getName() == "ham")
		{
			//pos entity = pos personnage
			_fireWeapon.push_back(new Ham(_gRenderer, _pos_entity.x + _pos_entity.w - 20, _pos_entity.y + (_pos_entity.h / 2) - 20, moove));
		}
		_fireDelay = SDL_GetTicks();
	}
}

std::vector<Weapon*>& Entity::getWeaponlist()//!!!!!!!!!!!!!!!!!!
{
	return (_fireWeapon);
}

void Entity::draw(float camerax, float cameray)
{
	this->_Camera.x = this->_pos_x + camerax;
	this->_Camera.y = this->_pos_y + cameray;
	SDL_RenderCopy( this->_gRenderer, this->_picture->getTexture(), &this->_crop_entity, &this->_Camera);
}


int Entity::getHit(SDL_Rect _posHeros)// watch if you get hit by monster crop
{//changer les valeur de it par autre chose de plus precis et apres avoir changer le heros crop
	if(_posHeros.x + 10 < this->_Camera.x + this->_Camera.w &&
   _posHeros.x  + _posHeros.w - 10 > this->_Camera.x &&
   _posHeros.y < this->_Camera.y + this->_Camera.h &&
   _posHeros.h + _posHeros.y + 10 > this->_Camera.y)
	{
		return (_dammage);
	}
	return (0);
}

int Entity::getposx()
{
	return (_pos_x);
}

int Entity::getposy()
{
	return (_pos_y);
}

int Entity::getcamerax()
{
	return (_Camera.x);
}

int Entity::getcameray()
{
	return (_Camera.y);
}

int Entity::getcamerah()
{
	return (_Camera.h);
}

int Entity::getcameraw()
{
	return (_Camera.w);
}

float Entity::getDrop()
{
	return(_drop);
}

int Entity::getScore()
{
	return (_score);
}

Weapon* Entity::getWeapon()
{
	return (_weapon);
}
