#include "Image.hpp"

Image::Image(SDL_Renderer* gRenderer, std::string str, int red, int green , int blue)
{
	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = SDL_LoadBMP( str.c_str() );//IMG_LoadTexture
	SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, red, green, blue));//turn one color to invisible
	if( loadedSurface == NULL )
		ft_puterror( "Unable to load image ! SDL_image Error: ", SDL_GetError() );
	//Create texture from surface pixels
	newTexture = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );
	if( newTexture == NULL )
		ft_puterror( "Unable to create texture from ! SDL Error: ", SDL_GetError() );

	//Get rid of old loaded surface
	SDL_FreeSurface( loadedSurface );
	//std::cout << "[INFOS]: The texture have been loaded." << std::endl;
	this->_texture = newTexture;
}

void		Image::ft_puterror(std::string s1, std::string s2)
{
	std::cout << RED << "[ERROR]: "; 
	std::cout << s1 << s2 << "." << RESET << std::endl;
	SDL_Quit();
	std::exit(EXIT_FAILURE);
}

Image::Image(SDL_Renderer* gRenderer, std::string str)
{
	SDL_Texture* newTexture = NULL;

	SDL_Surface* loadedSurface = SDL_LoadBMP( str.c_str() );//IMG_LoadTexture
	if( loadedSurface == NULL )
		ft_puterror( "Unable to load image ! SDL_image Error: ", SDL_GetError() );
	newTexture = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );
	if( newTexture == NULL )
		ft_puterror( "Unable to create texture from ! SDL Error: ", SDL_GetError() );

	SDL_FreeSurface( loadedSurface );
	this->_texture = newTexture;
}

SDL_Texture* Image::getTexture()
{
	return (this->_texture);
}
