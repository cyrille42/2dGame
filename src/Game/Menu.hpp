#pragma once

#include "SDL/Image.hpp"

class Menu {
	public:

	Menu(Windows *window);
	~Menu();
	void Menu_start();
	void Menu_esc();
	void	arrow_pos(int x, int y, int Width, int Height);
	void 	setArrowy(int *a, int max);
	void 	choose_choice(int a, int max);
	void 	option_menu();
	private:
		Menu();
		Windows *_window;
		int _ScreenWidth;
		int _ScreenHeigth;
		int _gameStatus;
		SDL_Rect _pos_arrow;
};