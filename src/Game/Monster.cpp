#include "Monster.hpp"

//gesture of all monster

Monster::Monster(SDL_Renderer* gRenderer)
{
	this->_gRenderer = gRenderer;
	_batDelay = SDL_GetTicks();
}

Monster::~Monster()
{

}

void Monster::draw(float _CameraX, float _CameraY)
{
	size_t i = 0;

	while (i < _Bat.size())
	{
		_Bat[i]->draw(_CameraX, _CameraY);
		i++;
	}
	i = 0;
	while (i < _BatBoss.size())
	{
		_BatBoss[i]->draw(_CameraX, _CameraY);
		i++;
	}
	i = 0;
	while (i < _Skeleton.size())
	{
		_Skeleton[i]->draw(_CameraX, _CameraY);
		i++;
	}
}

void Monster::init()
{
	_Skeleton.push_back(new Skeleton(this->_gRenderer, 1800 , 750));
	_BatBoss.push_back(new BatBoss(this->_gRenderer, 6 * 1480 - 500, 600));
}

int Monster::hitMonster(SDL_Rect _posHeros)//si on touche un mob
{
	size_t i = 0;
	int dammage;
	while (i < _Bat.size())
	{
		dammage = _Bat[i]->getHit(_posHeros);
		if (dammage > 0)
			return (dammage);
		i++;
	}
	i = 0;
	while (i < _BatBoss.size())
	{
		dammage = _BatBoss[i]->getHit(_posHeros);
		if (dammage > 0)
			return (dammage);
		i++;
	}
	i = 0;
	while (i < _Skeleton.size())
	{
		dammage = _Skeleton[i]->getHit(_posHeros);
		if (dammage > 0)
			return (dammage);
		i++;
	}
	return (0);
}

/*
** compare les objet lancer avec la hitbox des monstre
*/

int Monster::attackMonster(std::vector<Weapon*>& _fireWeapon, Bonus *findBonus, int bonusdammage)//prend les bonus dammage du heros + les dammage du weapon
{
	size_t i = 0;
	int hit;
	int life = 1;
	size_t j = 0;
	int score = 0;

	while (j < _fireWeapon.size())
	{
		while (i < _Bat.size())
		{
			hit = _Bat[i]->getHit(_fireWeapon[j]->getPos());
			if (hit > 0)
			{
				life = _Bat[i]->getDammage(_fireWeapon[j]->getDammage() + bonusdammage);//dammage la bat avec les dammage du weapon + bonus dammage heros entre en parametre
				_fireWeapon.erase(_fireWeapon.begin() + j);
				if (life <= 0)
				{
					findBonus->creatBonus(_Bat[i]->getposx(), _Bat[i]->getposy(), _Bat[i]->getDrop());//creat bonus via bat name
					score += _Bat[i]->getScore();
					_Bat.erase(_Bat.begin() + i);
				}
				j = 0;
				i = 0;
				if (j >= _fireWeapon.size())
					return score;
			}
			i++;
		}
		i = 0;
		while (i < _BatBoss.size())
		{
			hit = _BatBoss[i]->getHit(_fireWeapon[j]->getPos());
			if (hit > 0)
			{
				life = _BatBoss[i]->getDammage(_fireWeapon[j]->getDammage() + bonusdammage);
				_fireWeapon.erase(_fireWeapon.begin() + j);
				if (life <= 0)
				{
					_Bat.push_back(new Bat(this->_gRenderer, _BatBoss[i]->getx(), 600, 250, 250));
					findBonus->creatBonus(_BatBoss[i]->getposx(), _BatBoss[i]->getposy(), _BatBoss[i]->getDrop());//creat bonus via bat name
					score += _BatBoss[i]->getScore();
					_BatBoss.erase(_BatBoss.begin() + i);
				}
				j = 0;
				i = 0;
				if (j >= _fireWeapon.size())
					return score;
			}
			i++;
		}
		i = 0;
		while (i < _Skeleton.size())
		{
			hit = _Skeleton[i]->getHit(_fireWeapon[j]->getPos());
			if (hit > 0)
			{
				life = _Skeleton[i]->getDammage(_fireWeapon[j]->getDammage() + bonusdammage);
				_fireWeapon.erase(_fireWeapon.begin() + j);
				if (life <= 0)
				{
					findBonus->creatBonus(_Skeleton[i]->getposx(), _Skeleton[i]->getposy(), _Skeleton[i]->getDrop());//creat bonus via Skeleton name
					score += _Skeleton[i]->getScore();
					_Skeleton.erase(_Skeleton.begin() + i);
				}
				j = 0;
				i = 0;
				if (j >= _fireWeapon.size())
					return score;
			}
			i++;
		}
		i = 0;
		j++;
	}
	return (score);
}

 void Monster::MoovingMonster(SDL_Rect heros)
 {
 	size_t i = 0;

	while (i < _Bat.size())
	{
		_Bat[i]->mooving();
		i++;
	}
	i = 0;
	int a;
	while (i < _BatBoss.size())//gere le bat boss
	{
		a = _BatBoss[i]->mooving(heros);
		if (a == 1)
		{
			_Bat.push_back(new Bat(this->_gRenderer, _BatBoss[i]->getx(), 750, 600));
		}
		i++;
	}
	i = 0;
	while (i < _Skeleton.size())
	{
		a = _Skeleton[i]->mooving(heros);
		if (a == 1)//sa a opti ?
		{
			//cree une fonction qui fasse sa tout seul (vur que x et y du weapon aurons toujorus la meme formule par rapport au coor du squelette)
			_Skeleton[i]->getWeapon()->setpos(_Skeleton[i]->getcamerax() - _Skeleton[i]->getcameraw(), _Skeleton[i]->getcameray() + (_Skeleton[i]->getcamerah() / 2));
			_monsterWeapon.push_back(_Skeleton[i]->getWeapon());
		}
		i++;
	}
	//ici on retourne les weapon des mob et on les push back dans une liste de weapon.
}

void Monster::deletingMonster()
{
	size_t i = 0;

	while (i < _Bat.size())
	{
		if (_Bat[i]->getcamerax() < 0)
		{
			_Bat.erase(_Bat.begin() + i);
			i--;
		}
		i++;
	}
}

void Monster::pop(int _CameraX, int y)
{
	static int a = 0;

	_CameraX *= -1;
	if (_batDelay + 5000 < SDL_GetTicks())//ppop bat toute les 5 s
	{
		_Bat.push_back(new Bat(_gRenderer, _CameraX + 1480, y + 25));
		_batDelay = SDL_GetTicks();
	}
	if (_CameraX > 780 && a == 0)//pop bat suivant la pos du joueurs
	{
		_Bat.push_back(new Bat(this->_gRenderer, _CameraX + 1480, y - 50, 150, 150));
		a++;
	}
}

void Monster::drawWeapon()
{
	size_t i = 0;
	int kill;

	while (i < _monsterWeapon.size())
	{
		kill = _monsterWeapon[i]->mooving();//la limite est a droite et pas a gauche faudra changer le draw + 0 tmp car sa influe aussi les mob weapon
		if (kill == 1)
		{
		 	_monsterWeapon.erase(_monsterWeapon.begin() + i);
		 	i--;
		}
		else
		{
			_monsterWeapon[i]->draw();
		}
		i++;
	}
}

int Monster::hitWeapon(SDL_Rect _posHeros)//si un mob nous touche avec sont arme
{//sa laisse pas passer du hit car meme si on ce fait hit on est immortel pendant  300ms
	size_t i = 0;
	int dammage;
	SDL_Rect weapon;
	while (i < _monsterWeapon.size())
	{
		weapon = _monsterWeapon[i]->getPos();//obliger de passer comme sa car on a pas acces au monstre qui a lance le weapon
		if(_posHeros.x + 10 < weapon.x + weapon.w &&  _posHeros.x  + _posHeros.w - 10 > weapon.x &&
	   _posHeros.y < weapon.y + weapon.h &&
	   _posHeros.h + _posHeros.y + 10 > weapon.y)
		{
			dammage = _monsterWeapon[i]->getDammage();
			_monsterWeapon.erase(_monsterWeapon.begin() + i);
			return (dammage);
		}
		i++;
	}
	return (0);
}