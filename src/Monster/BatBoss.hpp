#pragma once

#include "Pve/Entity_alive.hpp"

class BatBoss : public Entity {
	public:
		BatBoss(SDL_Renderer	*gRenderer, int x, int y);
		~BatBoss();
		int 	getDammage(int amount);
		int 	mooving(SDL_Rect heros);
		int		getx();
		int testx;
	private:
		float _spawnDelay;
		BatBoss();
};