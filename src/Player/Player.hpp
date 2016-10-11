#pragma once

#include "Pve/Entity_alive.hpp"

class Player : public Entity {
	public:
		Player(SDL_Renderer	*gRenderer);
		~Player();
		void draw();
		int getDammage(int amount);
		int getPosCropx();
		int getPosCropy();
		int getPosCroph();
		int getPosCropw();
		// void setWeapon(Weapon weapon);
		void changePosx(int amount);
		void changePosy(int amount);
		void newBonus(std::string str);
		int getDist(SDL_Rect);
		int getLife();
		void addScore(int amount);
		int getBonusdammage();
		void drawWeapon();  
	private:
		Player();
		float _dammageDelay;
		int _max_life;
		int _bonus_dammage;
};
