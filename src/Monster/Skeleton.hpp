#pragma once

#include "Pve/Entity_alive.hpp"
#include "Player/Weapon.hpp"
#include "Weapon/Bones.hpp"

class Skeleton : public Entity {
	public:
		Skeleton(SDL_Renderer	*gRenderer, int x, int y);
		~Skeleton();
		int 	getDammage(int amount);
		int 	mooving(SDL_Rect heros);
		int		getx();
		int testx;
	private:
		float _fireDelay;
		Skeleton();
};