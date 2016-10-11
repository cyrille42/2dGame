#pragma once

#include "Pve/Entity_alive.hpp"

class Bat : public Entity {
	public:
		Bat(SDL_Renderer	*gRenderer, int x, int y);
		Bat(SDL_Renderer	*gRenderer, int x, int y, int Width, int height);
		~Bat();
		int 	getDammage(int amount);
		void 	mooving();
		Bat(SDL_Renderer	*gRenderer, int x, int y, int dist);
	private:
		Bat();
		int _dist;
};