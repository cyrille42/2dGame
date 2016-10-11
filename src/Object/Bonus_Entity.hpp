#pragma once

#include "SDL/Image.hpp"

class Bonus_Entity {
	public:
		Bonus_Entity(SDL_Renderer* gRenderer, std::string path, int x, int y, int Width, int Height, std::string name);
		~Bonus_Entity();
		void draw(int _CameraX, int _CameraY);
		std::string getName();
		int getHit(SDL_Rect _posHeros);
		int getposx();
		int getposy();
	private:
		Bonus_Entity();
		SDL_Renderer* _gRenderer;
		Image* _texture;
		SDL_Rect _Camera;
		SDL_Rect _crop;
		int _pos_x;
		int _pos_y;
		std::string _name;
};