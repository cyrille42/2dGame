#include "Map.hpp"

Map::Map(SDL_Renderer* gRenderer)
{
	this->_gRenderer = gRenderer;
}

Map::~Map()
{

}

void Map::draw(float _CameraX, float _CameraY)//respecter l'ordre d affichage
{
	size_t i = 0;

	while (i < _Background.size())
	{
		_Background[i]->draw(_CameraX, _CameraY);
		i++;
	}
	i = 0;
	while( i < _Block.size())
	{
		_Block[i]->draw(_CameraX, _CameraY);
		i++;
	}
}

void Map::initMap()
{
	int i = 0;
	// while( i < 6)
	// {
		_Background.push_back(new Background(this->_gRenderer, "ressource/background00.bmp", 0, 0, 1480 * 6, 920));
	// 	i++;
	// }
	i = 0;
	while( i < 4)
	{
		_Block.push_back(new Block(this->_gRenderer, "ressource/block2.bmp", i * 1480 , 850, 1480, 200));
		i++;
	}
	i = 5;
	_Block.push_back(new Block(this->_gRenderer, "ressource/block2.bmp", i * 1480 , 850, 1480, 200));
	i = 0;
	while (i < 6)
	{
		_Block.push_back(new Block(this->_gRenderer, "ressource/block2.bmp", (4 * 1480) + (i * 250) , 850, 50, 50));
		i++;
	}
}

int Map::hitMapUp(SDL_Rect _posHeros)
{
	size_t i = 0;
	while (i < _Block.size())
	{
		if (_Block[i]->getHitUp(_posHeros) == 1)
			return (1);
		i++;
	}
	return (0);
}

int Map::hitMapDown(SDL_Rect _posHeros)
{
	size_t i = 0;
	while (i < _Block.size())
	{
		if (_Block[i]->getHitDown(_posHeros) == 1)
			return (1);
		i++;
	}
	return (0);
}

int Map::hitMapLeft(SDL_Rect _posHeros)
{
	size_t i = 0;
	while (i < _Block.size())
	{
		if (_Block[i]->getHitLeft(_posHeros) == 1)
			return (1);
		i++;
	}
	return (0);
}

int Map::hitMapRight(SDL_Rect _posHeros)
{
	size_t i = 0;
	while (i < _Block.size())
	{
		if (_Block[i]->getHitRight(_posHeros) == 1)
			return (1);
		i++;
	}
	return (0);
}
