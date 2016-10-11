#pragma once

#include "Player/Weapon.hpp"

class Basic : public Weapon {
	public:
		Basic(SDL_Renderer	*gRenderer, int x, int y, int moove);
		~Basic();
		int mooving();
	private:
		Basic();
};
