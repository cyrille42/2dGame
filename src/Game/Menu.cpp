#include "Menu.hpp"

Menu::Menu(Windows *window)
{
	_window = window;
	_gameStatus = 1;
}

Menu::~Menu()
{

}

void Menu::arrow_pos(int x, int y, int Width, int Height)
{
	_pos_arrow.x = x;
	_pos_arrow.y = y;
	_pos_arrow.w = Width;
	_pos_arrow.h = Height;
}

void Menu::setArrowy(int *a, int max)
{
	if (*a > max)
		*a = 0;
	if (*a < 0)
		*a = max;
	_pos_arrow.y = (*a * 55) + 415;
}

void Menu::option_menu()
{
	std::cout << "Comming soon" << std::endl;
}

void Menu::choose_choice(int a, int max)
{
	if (a == 0)
		_gameStatus = 0;
	else if ((a == 1 && max == 2) || (a == 2 && max == 3))
		option_menu();
	// if (a == 2)
	// 	new_game();
	else if (a == max)
	{
		std::cout << GREEN << "Systeme have quit properly" << std::endl;//changer sa
		SDL_Quit();
		std::exit(0);
	}
}

void Menu::Menu_start()
{
	Image *menu = new Image(_window->getRenderer(), "ressource/menu.bmp");
	Image *arrow = new Image(_window->getRenderer(), "ressource/arrow.bmp");
	SDL_Event sdl_key;
	int a = 0;

	arrow_pos(620, 420, 80, 40);
	SDL_RenderClear(_window->getRenderer());
	SDL_RenderCopy(_window->getRenderer(), menu->getTexture(), NULL, NULL);
	SDL_RenderCopy(_window->getRenderer(), arrow->getTexture(), NULL, &_pos_arrow);
	SDL_RenderPresent(_window->getRenderer());
	while (_gameStatus == 1)
	{
		while (SDL_PollEvent(&sdl_key) != 0 )
		{
			if(sdl_key.type == SDL_QUIT)//croix rouge
				_gameStatus = 0;
			else if( sdl_key.type == SDL_KEYDOWN )
			{
				switch( sdl_key.key.keysym.sym )
				{
					case SDLK_UP:
					a--;
					break;

					case SDLK_DOWN:
					a++;
					break;

					case SDLK_KP_ENTER:
					choose_choice(a, 2);
					break;
				}
			}
			SDL_RenderClear(_window->getRenderer());
			SDL_RenderCopy(_window->getRenderer(), menu->getTexture(), NULL, NULL);
			setArrowy(&a, 2);
			SDL_RenderCopy(_window->getRenderer(), arrow->getTexture(), NULL, &_pos_arrow);
			SDL_RenderPresent(_window->getRenderer());
		}
	}
}

void Menu::Menu_esc()
{
	Image *menu = new Image(_window->getRenderer(), "ressource/menu2.bmp");
	Image *arrow = new Image(_window->getRenderer(), "ressource/arrow.bmp");
	SDL_Event sdl_key;
	int a = 0;

	_gameStatus = 1;
	arrow_pos(620, 420, 80, 40);
	SDL_RenderClear(_window->getRenderer());
	SDL_RenderCopy(_window->getRenderer(), menu->getTexture(), NULL, NULL);
	SDL_RenderCopy(_window->getRenderer(), arrow->getTexture(), NULL, &_pos_arrow);
	SDL_RenderPresent(_window->getRenderer());
	while (_gameStatus == 1)
	{
		while (SDL_PollEvent(&sdl_key) != 0 )
		{
			if(sdl_key.type == SDL_QUIT)//croix rouge
				_gameStatus = 0;
			else if( sdl_key.type == SDL_KEYDOWN )
			{
				switch( sdl_key.key.keysym.sym )
				{
					case SDLK_UP:
					a--;
					break;

					case SDLK_DOWN:
					a++;
					break;

					case SDLK_KP_ENTER:
					choose_choice(a, 3);
					break;
				}
			}
			SDL_RenderClear(_window->getRenderer());
			SDL_RenderCopy(_window->getRenderer(), menu->getTexture(), NULL, NULL);
			setArrowy(&a, 3);
			SDL_RenderCopy(_window->getRenderer(), arrow->getTexture(), NULL, &_pos_arrow);
			SDL_RenderPresent(_window->getRenderer());
		}
	}
}





