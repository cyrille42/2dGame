#include "Run.hpp"

//get la size de la windows avec SDL_GetWindowSize()	Récupère la taille actuelle de la fenêtre

Run::Run()
{
 	this->_gameStatus = 1;
 	this->_CameraY = 0;
 	this->_CameraX = 0;
 	this->_jump = 0;
 	_moove = -1;
}

Run::~Run()
{
	SDL_DestroyRenderer( this->_gRenderer );
	delete this->_window;
}

void Run::Begin()
{
	SDL_RenderClear(this->_gRenderer);
}

void Run::End()
{
    SDL_RenderPresent(this->_gRenderer);
}

void Run::Moove()//fait les mouvement en simultaner
{
	int moove;

	moove  = _keyboard_input[SDLK_LEFT] - _keyboard_input[SDLK_RIGHT];
	if (moove == 1 && _map1->hitMapLeft(_heros->getCrop()) == 0)
	{
		_heros->PlayAnimation(0,2,1, 200);
		_CameraX += 3.0f;
		_moove = 1;
	}
	else if (moove == -1 && _map1->hitMapRight(_heros->getCrop()) == 0)
	{
		_heros->PlayAnimation(0,2,2, 200);
		_CameraX -= 3.0f;
		_moove = -1;
	}
	if (_keyboard_input[SDLK_SPACE] == 1)
	{
		if (_jump == 0)
		{
			_jump = 1;
		}
	}
	if (_keyboard_input[SDLK_e] == 1)//crée classe arme
	{
		_heros->fireWeapon(_moove);
	}
	if (_keyboard_input[SDLK_ESCAPE] == 1)
	{
		std::cout << "Your score: " << _heros->getScore() << std::endl;
		std::cout << "Your life: " << _heros->getLife() << std::endl;
		_game_menu->Menu_esc();
		_keyboard_input[SDLK_ESCAPE] = 0;
	}
}

void Run::running()
{
	Windows *window = new Windows();
	Menu *game_menu = new Menu(window);
	Player *heros = new Player(window->getRenderer());
	Map *map1 = new Map(window->getRenderer());//faire un int parametre pour genere un niveau different.
	Bonus *findBonus = new Bonus(window->getRenderer());
	Monster* monster = new Monster(window->getRenderer());//gere tout les monstres
//	Weapon weapon(window->getRenderer(), heros->getPosCropx() + heros->getPosCropw() - 20, heros->getPosCropy() + (heros->getPosCroph() / 2));//a delete ?
	//ussless x y weapon ?
//	heros->setWeapon(weapon);
	int dammage;
	int end;

	_gRenderer = window->getRenderer();
	_window = window;
	_heros = heros;
	_map1 = map1;
	_monster = monster;
	_game_menu = game_menu;
	game_menu->Menu_start();
	_map1->initMap();
	monster->init();
	heros->initcrop();
	heros->PlayAnimation(0, 3, 0, 200);
	Begin();
	_map1->draw(_CameraX, _CameraY);
	monster->draw(_CameraX, _CameraY);
	heros->draw();
	End();

	float _delay = SDL_GetTicks();
	float _exdelay = SDL_GetTicks();
	float delta;

	int i = 0;
	while (this->_gameStatus == 1)//fmap de jeux
	{
		if (_jump <= 0 && _map1->hitMapDown(heros->getCrop()) == 0)
			heros->changePosy(heros->Gravity() * -1);
		else if (_jump > 0 && _map1->hitMapUp(heros->getCrop()) == 0)//_jump temporaire faire avec un jumpDelay
		{
			i = _heros->Jump();
			if (i > 0 )
			{
				heros->changePosy(i);
				_jump++;
			}
			if (_jump == 50)
				_jump = -1;
		}
		else if (_map1->hitMapDown(heros->getCrop()) == 1)//permet de re_jump seulment apres avoir toucher le sol
			_jump = 0;
		while (SDL_PollEvent(&sdl_key) != 0 )
		{
			if(sdl_key.type == SDL_QUIT)//croix rouge
				this->_gameStatus = 0;
			if( sdl_key.type == SDL_KEYDOWN )
			{
				_keyboard_input[sdl_key.key.keysym.sym] = 1;
			}
			else if( sdl_key.type == SDL_KEYUP )
			{
				_keyboard_input[sdl_key.key.keysym.sym] = 0;
			}
		}
		Moove();
		/* on add le score*/
		heros->addScore(monster->attackMonster(_heros->getWeaponlist(), findBonus, heros->getBonusdammage()));
		monster->MoovingMonster(heros->getCrop());//bouge les monstre
		end = findBonus->hitBonus(heros);//regarder si on a hit un bonus et si on a hit la fin de la map
		monster->deletingMonster();//supprime les mob hors screen
		monster->pop(_CameraX, heros->getPosCropy());//crée des monstres
		Begin();
		_map1->draw(_CameraX, _CameraY);
		findBonus->draw(_CameraX, _CameraY);
		monster->draw(_CameraX, _CameraY);
		monster->drawWeapon();//draw les projectile des monstres
		heros->drawWeapon();//bouge et draw les armes
		heros->draw();
		End();
		dammage = monster->hitMonster(heros->getCrop());
		dammage += monster->hitWeapon(heros->getCrop());
		/*
		**death status
		*/
		if (dammage > 0)
		{
			//changer pour un skin dammage
			if (heros->getDammage(dammage) <= 0)
			{
				//gameOver();
				_gameStatus = 0;
			}
		}
		if (heros->getPosCropy() > 920)//920 = y fenetre
		{
			//gameOver();
			_gameStatus = 0;
		}

		/*
		**calcule et reinit de la map ect ... si on touche la fin
		*/
		if (end == 1)
		{
			//checkmap();
			//loadmap();
			_gameStatus = 0;
		}

		/*
		**calcule fps + cap fps
		*/
		_exdelay = SDL_GetTicks();
		delta = (_exdelay - _delay);
		delta = 1000 / delta;
		if (delta > 60)
			SDL_Delay(delta / 60);
		_delay = _exdelay;
	}
}
