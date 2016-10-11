#pragma once

#include "Player/Weapon.hpp"

class Ham : public Weapon {
	public:
		Ham(SDL_Renderer	*gRenderer, int x, int y, int moove);
		~Ham();
		int mooving();
	private:
		Ham();
};
