#pragma once

#include "SDL/Image.hpp"

class Background {
	public:
		Background(SDL_Renderer* gRenderer, std::string path, int x, int y, int Width, int Height);
		~Background();
		void draw(int _CameraX, int _CameraY);
	private:
		Background();
		SDL_Renderer* _gRenderer;
		Image* _texture;
		SDL_Rect _Camera;
		SDL_Rect _crop;
		int _pos_x;
		int _pos_y;
};