#pragma once

#include "SDL/Image.hpp"
#include "Object/Block.hpp"
#include "Object/Background.hpp"
#include "Player/Player.hpp"

class Map {
	public:
		Map(SDL_Renderer	*gRenderer);
		void draw(float x, float y);
		void initMap();//a delete plus tard ?
		~Map();
		int hitMapDown(SDL_Rect _posHeros);
		int hitMapUp(SDL_Rect _posHeros);
		int hitMapRight(SDL_Rect _posHeros);
		int hitMapLeft(SDL_Rect _posHeros);
	private:
		Map();
		SDL_Renderer	*_gRenderer;
		std::vector<Block*> _Block;
		std::vector<Background*> _Background;
};