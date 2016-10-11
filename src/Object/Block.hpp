#pragma once

#include "SDL/Image.hpp"

class Block {
	public:
		Block(SDL_Renderer* gRenderer, std::string path, int x, int y, int Width, int Height);
		~Block();
		void draw(int _CameraX, int _CameraY);
		int getHitUp(SDL_Rect _posHeros);
		int getHitRight(SDL_Rect _posHeros);
		int getHitDown(SDL_Rect _posHeros);
		int getHitLeft(SDL_Rect _posHeros);
	private:
		Block();
		SDL_Renderer* _gRenderer;
		Image* _texture;
		SDL_Rect _Camera;
		SDL_Rect _crop;
		int _pos_x;
		int _pos_y;
};