#pragma once

#include <SDL2/SDL.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <cstdlib>//std exit
#include <vector>

# define CLEAR "\033[H\033[2J"
# define RESET "\033[0m"
# define BOLD "\033[1m"
# define REV "\033[7m"
# define RESET "\033[0m"
# define WHITE "\x1B[0m"
# define RED "\x1B[31m"
# define GREEN "\x1B[32m"
# define YELLOW "\x1B[33m"
# define BLUE "\x1B[34m"
# define MAGENTA "\x1B[35m"
# define CYAN "\x1B[36m"
# define GRAY "\033[22;37m"

class Windows {
	private:
		SDL_Window		*_window;
		SDL_Renderer	*_gRenderer;
		int _Width;
		int _Height;
	public:
		~Windows();
		Windows();
		int getWidth();
		int	getHeight();
		void		ft_puterror(std::string s1, std::string s2);
		SDL_Window* getWindow();
		void		color_screen();
		void		ft_putwarning(std::string s1);
		void		Resize_window(int Width, int Height);
		SDL_Renderer* getRenderer();
};