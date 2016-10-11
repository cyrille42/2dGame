#pragma once

#include "Windows.hpp"

class Image {
	public:
		Image(SDL_Renderer* gRenderer, std::string str);
		Image(SDL_Renderer* gRenderer, std::string str, int red, int green , int blue);
		~Image();
		void ft_puterror(std::string s1, std::string s2);
		SDL_Texture* getTexture();
	private:
		SDL_Texture* 	_texture;
		Image();
};
