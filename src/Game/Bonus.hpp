#pragma once

#include "Player/Player.hpp"
#include "Object/Bonus_Entity.hpp"
#include <random>
#include <ctime>

class Bonus {
	public:
		Bonus(SDL_Renderer* gRenderer);
		~Bonus();
		int hitBonus(Player *heros);
		void draw(float _CameraX, float _CameraY);
		void creatBonus(int x, int y, float dropNumber);
	private:
		Bonus();
		std::vector<Bonus_Entity*> _Bonus;
		SDL_Renderer* _gRenderer;
};
