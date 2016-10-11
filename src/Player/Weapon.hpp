#pragma once

#include "SDL/Image.hpp"

class Weapon {

public:
	Weapon();
	~Weapon();
	void draw();
	int getDammage();
	SDL_Rect getPos();
	int getfireRate();
	std::string getName();
	void setMoove(int amount);
	virtual int mooving() = 0;
	void setpos(int x, int y);
protected:
	int _dammage;
	Image *_picture;
	SDL_Rect _pos_img;
	SDL_Rect _crop_img;
	SDL_Renderer *_gRenderer;
	int _moov;
	int _dist;
	int _startx;
	int _starty;
	float _moovingDelay;
	int _fireRate;
	std::string _name;
	float _camerax_base;
};