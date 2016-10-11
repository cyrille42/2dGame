#pragma once

#include "Player/Weapon.hpp"

class Bones : public Weapon {
	public:
		Bones(SDL_Renderer	*gRenderer, int x, int y, int moove);
		~Bones();
		int mooving();
	private:
		Bones();
};
