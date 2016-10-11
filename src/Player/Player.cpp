#include "Player.hpp"



Player::Player(SDL_Renderer	*gRenderer)
{
	_picture = new Image(gRenderer, "ressource/heros.bmp");
	_animationDelay = SDL_GetTicks();
	_dammageDelay = SDL_GetTicks();
 	_frameX = 4;
 	_frameY = 4;
 	_gRenderer = gRenderer;
 	SDL_Rect crop;

	crop.x = 700;
	crop.y = 700;
	crop.w = 50;
	crop.h = 100;
	_pos_entity = crop;
	_life = 100;
	_dammage = 0;
	_fireDelay = SDL_GetTicks();
	_max_life = 100;
	_score = 0; 
	Weapon *weapon = new Basic(_gRenderer, 700,700, 0);//init 700 car pos init du heros, 0 pour init
	_weapon  = weapon;
	_bonus_dammage = 0;
}

Player::~Player()
{

}

void Player::draw()
{
	SDL_RenderCopy( this->_gRenderer, this->_picture->getTexture(), &this->_crop_entity, &this->_pos_entity);
}

int Player::getDammage(int amount)// voir si y a pas mieux comme systeme de return life
{
	if (this->_dammageDelay + 500 < SDL_GetTicks())
	{
		this->_life -= amount;
		this->_dammageDelay = SDL_GetTicks();
		std::cout << _life << std::endl;
		return (this->_life);
	}
	return (this->_life);
}

// void Player::setWeapon(Weapon weapon)
// {
// 	_weapon = weapon;
// }

int Player::getPosCropx()
{
	return (this->_pos_entity.x);
}

int Player::getPosCropy()
{
	return (this->_pos_entity.y);
}

int Player::getPosCroph()
{
	return (this->_pos_entity.h);
}

int Player::getPosCropw()
{
	return (this->_pos_entity.w);
}

void Player::changePosx(int amount)
{
	_pos_entity.x += amount;
}

void Player::changePosy(int amount)
{
	_pos_entity.y -= amount;
}

void Player::newBonus(std::string str)/* gestion bonus faire en fmap ou autre*/
{
	if ( !strcmp(str.c_str(), "ham"))
	{
		_weapon = new Ham(_gRenderer, _pos_entity.x ,_pos_entity.y, 0);
	}
	if ( !strcmp(str.c_str(), "life"))
	{
		_life += 20;
		if (_life > _max_life)
			_life = _max_life;
	}
	else if ( !strcmp(str.c_str(), "500"))
	{
		_score += 500;
	}
	else if ( !strcmp(str.c_str(), "hp5"))
	{
		_max_life += 5;
		_life += 5;
		std::cout << "Your max hp is now " << _max_life << std::endl;//faire sa dans une interface
	}
	else if ( !strcmp(str.c_str(), "hp10"))
	{
		_max_life += 10;
		_life += 10;
		std::cout << "Your max hp is now " << _max_life << std::endl;
	}
}

int Player::getDist(SDL_Rect pos)
{
	return (pos.x - _pos_entity.x);
}

int Player::getLife()
{
	return (_life);
}

void Player::addScore(int amount)//gere aussi la monter de lvl peut ce foutre autre part
{
	static int a = 0;
	_score += amount;
	if (_score > 1000 && a == 0)
	{
		_bonus_dammage += 5;
		a++;
	}
	else if (_score > 2000 && a == 1)
	{
		_max_life += 5;
		_life += 5;
		a++;
	}
}

int Player::getBonusdammage()
{
	return (_bonus_dammage);
}

void Player::drawWeapon(/*float camerax*/)
{
	size_t i = 0;
	int kill;

	while (i < _fireWeapon.size())
	{
		kill = _fireWeapon[i]->mooving();
		if (kill == 1)
		{
		 	_fireWeapon.erase(_fireWeapon.begin() + i);//faire un  _dist parcouru dans weapon et le comparer avec dist max
		 	i--;
		}
		else
		{
			_fireWeapon[i]->draw();
		}
		i++;
	}
}
