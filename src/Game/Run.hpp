#pragma once

#include "Game/Menu.hpp"
#include "Game/Map.hpp"
#include "Game/Monster.hpp"
#include "Game/Bonus.hpp"
#include <map>

class Run {
	public:
		Run();
		~Run();
		void running();
		void Begin();
		void End();
		void loadmap();
		void Moove();
	private:
		int _gameStatus;
		float _CameraX;
		float _CameraY;
		SDL_Renderer* _gRenderer;
		Windows *_window;
		Player *_heros;//on enregistre le joueurs
		Map *_map1;
		SDL_Event sdl_key;
		int _jump;
		std::map<int, bool> _keyboard_input;
		Monster* _monster;
		Weapon *_weapon;//a delete
		int _score;// a delete
		Menu *_game_menu;
		int _moove;
};