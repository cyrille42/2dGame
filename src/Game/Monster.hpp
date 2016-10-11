#pragma once

#include "Monster/Bat.hpp"
#include "Player/Weapon.hpp"
#include "Monster/BatBoss.hpp"
#include "Game/Bonus.hpp"
#include "Monster/Skeleton.hpp"

class Monster {
	public:
		Monster(SDL_Renderer* gRenderer);
		~Monster();
		void	draw(float _CameraX, float _CameraY);
		void	init();
		int 	hitMonster(SDL_Rect _posHeros);
		int attackMonster(std::vector<Weapon*>&, Bonus *findBonus, int bonusdammage);
		void MoovingMonster(SDL_Rect heros);
		void deletingMonster();
		void pop(int _CameraX, int y);//permet le pop de mob  peut etre aleatoire ou non
		void drawWeapon();
		int	hitWeapon(SDL_Rect _posHeros);
	private:
		std::vector<Bat*> _Bat;
		std::vector<BatBoss*> _BatBoss;
		std::vector<Skeleton*> _Skeleton;
		SDL_Renderer* _gRenderer;
		float _batDelay;
		std::vector<Weapon*> _monsterWeapon;
};