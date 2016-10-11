#include "Windows.hpp"

/*
**si on agrandis la fenetre ou on la change , supprimer toute les image et relancer le programme
*/

Windows::Windows()
{
	SDL_Window		*window;
	window = NULL;

	this->_Width = 1480;
	this->_Height = 920;
	if( SDL_Init( SDL_INIT_VIDEO ) != 0 )
		ft_puterror("Can't init SDL: ", SDL_GetError());
	if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		ft_putwarning( "Warning: Linear texture filtering not enabled!" );
	window = SDL_CreateWindow("BLANK_GAME",SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1480, 920, SDL_WINDOW_RESIZABLE);//SDL_WINDOW_FULLSCREEN                                                                
	if(!window)
		ft_puterror("Can't set video mode: " , SDL_GetError());
	this->_window = window;
	std::cout << "[INFOS]: The windows have been initialised." << std::endl;

	SDL_Renderer* gRenderer = NULL;
	//Create renderer for window
	gRenderer = SDL_CreateRenderer( window , -1, SDL_RENDERER_ACCELERATED );
	if (gRenderer == NULL)
		ft_puterror("Renderer could not be created! SDL Error: ", SDL_GetError());
	this->_gRenderer = gRenderer;
}

Windows::~Windows()
{
	SDL_DestroyWindow(this->_window);
	std::cout << BLUE << "[QUIT]: The window have been closed." << RESET << std::endl;
}

void		Windows::ft_puterror(std::string s1, std::string s2)
{
	std::cout << RED << "[ERROR]: "; 
	std::cout << s1 << s2 << "." << RESET << std::endl;
	SDL_Quit();
	std::exit(EXIT_FAILURE);
}

void		Windows::ft_putwarning(std::string s1)
{
	std::cout << YELLOW << "[WARNING]: "; 
	std::cout << s1 << "." << RESET << std::endl;
}

SDL_Window *Windows::getWindow()
{
	return (this->_window);
}

void	Windows::Resize_window(int Width, int Height)
{
	//refaire le init renderer ?
	this->_Width = Width;
	this->_Height = Height;
	SDL_SetWindowSize(this->_window, Width, Height);
}

SDL_Renderer* Windows::getRenderer()
{
	return (this->_gRenderer);
}

int Windows::getWidth()
{
	return(this->_Width);
}

int Windows::getHeight()
{
	return(this->_Height);
}