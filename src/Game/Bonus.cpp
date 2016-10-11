#include "Bonus.hpp"

Bonus::Bonus(SDL_Renderer* gRenderer)
{
	_gRenderer = gRenderer;
	_Bonus.push_back(new Bonus_Entity(_gRenderer, "ressource/chest.bmp", 1500 , 800 , 50, 50, "chest"));
	_Bonus.push_back(new Bonus_Entity(_gRenderer, "ressource/end.bmp", 6 * 1480 - 80, 600 , 100, 250, "end"));
	_Bonus.push_back(new Bonus_Entity(_gRenderer, "ressource/spear.bmp", 5000 , 790 , 40, 40, "ham"));
	_Bonus.push_back(new Bonus_Entity(_gRenderer, "ressource/life.bmp", 3000 , 800 , 50, 50, "life"));
}

Bonus::~Bonus()
{

}

int Bonus::hitBonus(Player *heros)// si on marche dessus
{
	size_t i = 0;
	while (i < _Bonus.size())
	{
		if (_Bonus[i]->getHit(heros->getCrop()) == 1)
		{
			if (_Bonus[i]->getName() == "chest")
			{
				creatBonus(_Bonus[i]->getposx(),_Bonus[i]->getposy(), 6);
			}
			else if (_Bonus[i]->getName() == "end")
			{
				return (1);
			}
			else
			{
				heros->newBonus(_Bonus[i]->getName());//add le bonus au heros
			}
			_Bonus.erase(_Bonus.begin() + i);
		}
		i++;
	}
	return (0);
}
/* cree coffre qui font pop un objet a coter*/

void Bonus::creatBonus(int x, int y, float dropNumber)//7 =gros chest 6 = chest 5 = boss 4 = defi 3 = mini boss 2 = petyit defie 1 = gros mob 0.5 = monstre
{			
	std::random_device rd;//init a faire une foiss tocket dans bonus ?
	std::mt19937_64 gen(rd());//init

	std::uniform_int_distribution<unsigned char> dis;
	int rand = (int)dis(gen);//casdt prend plus de temps que creation d'un int ?

  	if(dropNumber == 0.5)
	{
		if (rand > 100)
			_Bonus.push_back(new Bonus_Entity(this->_gRenderer, "ressource/500.bmp", x , y , 50, 50, "500"));
	}
	else if(dropNumber == 1)
	{
		if (rand < 85)
			_Bonus.push_back(new Bonus_Entity(this->_gRenderer, "ressource/life.bmp", x , y , 50, 50, "life"));
		else if (rand > 200)
			_Bonus.push_back(new Bonus_Entity(this->_gRenderer, "ressource/spear.bmp", x - 30 , y , 40, 40, "ham"));
	}
	else if(dropNumber == 6)//coffre petit
	{
		if (rand < 60)
			_Bonus.push_back(new Bonus_Entity(this->_gRenderer, "ressource/hp5.bmp", x + 50 , y , 50, 50, "hp5"));
		else if (rand > 210)
			_Bonus.push_back(new Bonus_Entity(this->_gRenderer, "ressource/hp10.bmp", x + 50 , y , 50, 50, "hp10"));
		else
			_Bonus.push_back(new Bonus_Entity(this->_gRenderer, "ressource/500.bmp", x + 50 , y , 50, 50, "500"));
	}

}
	//_Bonus_Entity.push_back(new Bonus_Entity(this->_gRenderer, "ressource/ham.bmp", 1800 , 800 , 50, 50, "ham"));
	//_Bonus_Entity.push_back(new Bonus_Entity(this->_gRenderer, "ressource/cow.bmp", 4400 , 800 , 50, 50, "cow"));
	//temporaire
	//_Bonus_Entity.push_back(new Bonus_Entity(this->_gRenderer, "ressource/life.bmp", 4000 , 800 , 50, 50, "life"));

void Bonus::draw(float _CameraX, float _CameraY)
{
	size_t i = 0;

	while( i < _Bonus.size())
	{
		_Bonus[i]->draw(_CameraX, _CameraY);
		i++;
	}

}