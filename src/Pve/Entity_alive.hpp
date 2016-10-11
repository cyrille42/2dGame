#pragma once

#include "SDL/Image.hpp"
#include "Weapon/Basic.hpp"
#include "Weapon/Ham.hpp"
#include "Player/Weapon.hpp"

class Entity {
	public:
		~Entity();
		void PlayAnimation(int BeginFrame, int EndFrame, int Row, float speed);
		void initcrop();
//		void draw();//trouver le remplacant du virtual
		Entity();
		SDL_Rect getCrop();
		float Gravity();
		float Jump();
		virtual int getDammage(int amount) = 0;
		void fireWeapon(int moove);

		std::vector<Weapon*>& getWeaponlist();
		void draw(float camerax, float cameray);//monster
		int getHit(SDL_Rect _posHeros);//monster car a use _Camera
		int getposx();
		int getposy();
		float getDrop();
		int getScore();
		int getcamerax();//monstre only !!!
		int getcameray();//monstre only !!!
		int getcamerah();//monstre only !!!
		int getcameraw();//monstre only !!!
		Weapon* getWeapon();
	protected:
		SDL_Rect _pos_entity;
		SDL_Rect _crop_entity;
		int _life;
		Image *_picture;
		int _dammage;
		int _crop_Width;
		int _crop_Height;
		int _curentFrame;
		int _animationDelay;
		int _frameX;
		int _frameY;
		SDL_Renderer* _gRenderer;
		float _gravityDelay;
		float _jumpDelay;
		SDL_Rect _Camera;//monstre
		int _pos_x;//monstre
		int _pos_y;//monstre
		int _startx;//monstre
		int _starty;//monstre
		int _moov;//monstre
		float _moovingDelay;
		std::vector<Weapon*> _fireWeapon;//les monstre on le leur dans monstre.cpp
		Weapon* _weapon;//a remplacer par juste un name
		float _fireDelay;
		float _drop;//monstre
		int _score;
};
