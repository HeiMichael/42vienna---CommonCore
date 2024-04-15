#include "Game.hpp"

Game::Game()
{
	_bg = nullptr,
	_max_y = 0,
	_max_x = 0,
	_lives = 5;
	_score = 0;
	_enemy_creation_cooldown = 0.0;
	_enemy_creation_waitime = ENEMY_CREATION_RYTHM;
	getmaxyx(stdscr, _max_y, _max_x);
	refresh();
}

Game::~Game()
{
	if (_bg)
		delete _bg;
	if (_bg_up)
		delete _bg_up;
	if (_bg_stars)
		delete _bg_stars;
	if (_player)
		delete _player;
	if (_boss)
		delete _boss;
	cleanBullets();
	cleanEnemies();
}

void	Game::cleanBullets()
{
	std::vector<Bullet*>::iterator it;
	for (it = _bullets.begin(); it != _bullets.end(); it++)
	{
		delete *it;
	}
}

void	Game::cleanEnemies()
{
	std::vector<Enemy*>::iterator it;
	for (it = _enemies.begin(); it != _enemies.end(); it++)
	{
		delete *it;
	}
}

void	Game::setMaxY(int y)
{
	_max_y = y;
}

int		Game::getMaxY() const
{
	return _max_y;
}

void	Game::setMaxX(int x)
{
	_max_x = x;
}

int		Game::getMaxX() const
{
	return _max_x;
}

int		Game::getScore() const
{
	return _score;
}

void	Game::setScore(int v)
{
	_score = v;
}


int		Game::getLives() const
{
	return _lives;
}

void	Game::setLives(int v)
{
	_lives = v;
}

void	Game::setPlayer(Player* p)
{
	_player = p;
}

Player*	Game::getPlayer() const
{
	return _player;
}

void	Game::setEnemyCreationWaitime(double wt)
{
	_enemy_creation_waitime = wt;
}

double	Game::getEnemyCreationWaitime() const
{
	return _enemy_creation_waitime;
}

void	Game::init()
{
	if (_max_x < 100 || _max_y < 30)
	{
		endwin();
		std::cout << "Window too small. Minimum window size is 100x30" << std::endl;
		exit(1);
	}
	_bg = new Backscroll("images/back.ascii");
	_bg->halfWidth = 588;
	_bg_up = new Backscroll("images/clouds.ascii");
	_bg_up->halfWidth = 576;
	_bg_up->place = 0;
	_bg_stars = new Backscroll("images/stars.ascii");
	_bg_stars->halfWidth = 199;
	_bg_stars->place = 0;
	_bg_stars->setColpsec(20);
	_boss = new Boss("images/boss.ascii");
	_boss->setGame(this);
	_wn = newwin(LINES, COLS, 0, 0);
//	_infobox = newwin(INFOBOX_H , COLS, LINES - INFOBOX_H, 0);
	_player = new Player();
	_player->setGame(this);
}

void	Game::handle_input(int c, GameState& state)
{
	switch (c)
	{
		case KEY_DOWN:
			if (_player->getY() < _max_y - 1 - INFOBOX_H) 
				_player->setY(_player->getY()+1);
			break;
		case KEY_UP:
			if (_player->getY() > 0)
				_player->setY(_player->getY()-1);
			break;
		case KEY_LEFT:
			if (_player->getX() > 2)
				_player->setX(_player->getX()-2);
			break;
		case KEY_RIGHT:
			if (_player->getX() < _max_x - 4)
				_player->setX(_player->getX()+2);
			break;
		case KEY_SPC:
			_player->shoot();
			break;
		case KEY_ESC:
			state = EXIT;
			// _player->setDead(true);
		default:
			;
	}
}

void	Game::createBullet(int y, int x, float vel, Side al)
{
	Bullet *bullet = new Bullet();
	bullet->setX(x);
	bullet->setY(y);
	bullet->setSpeed(vel);
	bullet->setAlign(al);
	bullet->setGame(this);
	_bullets.push_back(bullet);
}

void	Game::eraseBullet(Bullet* bul)
{
	std::vector<Bullet*>::iterator it;
	it = std::find(_bullets.begin(), _bullets.end(), bul);
	if (it != _bullets.end())
	{
		_bullets.erase(it);
		delete bul;
	}
}

void	Game::eraseEnemy(Enemy* bul)
{
	std::vector<Enemy*>::iterator it;
	it = std::find(_enemies.begin(), _enemies.end(), bul);
	if (it != _enemies.end())
	{
		_enemies.erase(it);
		delete bul;
	}
}

void	Game::createEnemies()
{
	if (_enemy_creation_cooldown > 0.0)
		return;
	Enemy* em = new Enemy();
	int randomNumber;
	if (rand() % 2)
	{
 		randomNumber = rand() % (_max_y - INFOBOX_H - 1);
	}
	else
	{
		std::random_device rd;
		std::mt19937 generator(rd());
		std::normal_distribution<double> distribution(_player->getY(), 1.0);
		double randomDouble = distribution(generator);
		randomNumber = static_cast<int>(std::round(randomDouble));
		randomNumber = std::min(std::max(randomNumber, 0), _max_y - 1 - INFOBOX_H);
	}
	em->setY(randomNumber);
	em->setX(_max_x - 1);
	em->setGame(this);
 	em->setType(static_cast<EnemyType>(randomNumber = rand() % 4));
	// em->setType(LURKER);
	_enemies.push_back(em);
	_enemy_creation_cooldown = _enemy_creation_waitime; 
}


void	Game::update(GameState& state)
{
	// clock_t frame_start = clock();
	std::chrono::high_resolution_clock::time_point frame_start = std::chrono::high_resolution_clock::now();

	//wclear(_wn);
	_bg_stars->update(_wn);
	_bg_up->update(_wn);
	_bg->update(_wn);
	wrefresh(_wn);
	//update and draw player
	_player->update();
	_player->draw(_wn);
	//update enemy_creation_cooldown
	_enemy_creation_cooldown -= (1.0 / TARGET_FPS);
	if (_enemy_creation_cooldown < 0)
		_enemy_creation_cooldown = 0.0;
	////////create Enemies

	createEnemies();

	///////////////////////////// Update bullets
	std::vector<Bullet*>::iterator it;
	for (it = _bullets.begin(); it != _bullets.end(); )
	{
		(*it)->update();
		if ((*it)->getX() >= _max_x - 1 || (*it)->getX() <= 0)
		{
			it = _bullets.erase(it);
			continue;
			//eraseBullet(*it);		
		}
		else	
		{
			//(*it)->draw();
			it++;
		}
	}

	//////////////////////////// Player hit by bullet
	
	for (it = _bullets.begin(); it != _bullets.end(); )
	{
		if (std::abs((*it)->getX() - _player->getX()) < 0.8 && 
			std::abs((*it)->getY() - _player->getY()) < 0.8 &&
					(*it)->getAlign() == ENEMY)
		{
			it = _bullets.erase(it);
			_player->setHP(_player->getHP() - 1);
			continue;
		}
		else	
		{
			it++;
		}
	}

	///////////////////////////// draw bullets
	for (it = _bullets.begin(); it != _bullets.end(); it++)
	{
		(*it)->draw(_wn);
	}


	//////////////////////////////// Update Enemies
	std::vector<Enemy*>::iterator it_enemy;
	std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> duri = end - time;
	for (it_enemy = _enemies.begin(); it_enemy != _enemies.end(); )
	{
		
		(*it_enemy)->updater(duri.count());
		if ((*it_enemy)->getX() > _max_x - 1 || (*it_enemy)->getX() < 0)
		{
			it_enemy = _enemies.erase(it_enemy);
			continue;
		}
		it_enemy++;
	}

	///////////////////////////////// Collisions enemy with bullets 
	std::vector<Bullet*>::iterator it_bullet;
	for (it_enemy = _enemies.begin(); it_enemy != _enemies.end(); )
	{
		bool found = false;
		for (it_bullet = _bullets.begin(); it_bullet != _bullets.end(); it_bullet++)
		{
			if (std::abs((*it_bullet)->getX() - (*it_enemy)->getX()) < 1.8 && 
					 std::abs((*it_bullet)->getY() - (*it_enemy)->getY()) < 0.8 &&
					 (*it_bullet)->getAlign() == PLAYER)
			{
				it_enemy = _enemies.erase(it_enemy);
				it_bullet = _bullets.erase(it_bullet);
				_score++;
				found = true;	
				break;
			}
		}
		if (found == true)
			continue;
		it_enemy++;
	}

	//////////////////////////////////// shoot
	for (it_enemy = _enemies.begin(); it_enemy != _enemies.end(); it_enemy++)
	{
		(*it_enemy)->shoot();
	}
	// Collision enemy player
	for (it_enemy = _enemies.begin(); it_enemy != _enemies.end(); )
	{
		if (std::abs(_player->getX() - (*it_enemy)->getX()) < 0.8 && 
					std::abs(_player->getY() - (*it_enemy)->getY()) < 0.8)
		{
			it_enemy = _enemies.erase(it_enemy);
			_player->setHP(_player->getHP()-1);
			continue;
		}
		it_enemy++;
	}
	
	//////////////////////////////////// draw enemies
	for (it_enemy = _enemies.begin(); it_enemy != _enemies.end(); it_enemy++)
	{
		(*it_enemy)->draw(_wn);
	}

	//
	end = std::chrono::high_resolution_clock::now();
	draw_infobox(_score, _lives, std::chrono::duration<double>(end - time).count());


	std::chrono::duration<double> dur = end - time;
	if (dur.count() >= BOSSTIME)
	{
		_enemy_creation_waitime = 100000;
		// draw boss
		if (dur.count() >= 5.0 + 6.0)
		{
			_boss->setX(COLS-35);
			_boss->setY(LINES / 2 - 8);
			_boss->updater(dur.count());
			_boss->update();
			for (it_bullet = _bullets.begin(); it_bullet != _bullets.end();)
			{
				if (_boss->_isAlive && _boss->collides((*it_bullet)->getY(), (*it_bullet)->getX()) && 
					(*it_bullet)->getAlign() == PLAYER)
				{
					it_bullet = _bullets.erase(it_bullet);
					_boss->lives--;
					if (_boss->lives < 1)	
						_boss->_isAlive = false;
					break;
				}
				else
					it_bullet++;
			}
			if (_boss->_isAlive)
			{
				_boss->shoot();
				_boss->draw(_wn);
			}
		}
	}
	if (_player->isDead())
	{
		drawGameOver(_score);
		state = GAMEOVER;
	}
	if (!_boss->_isAlive)
	{
		drawYouWin(_score);
		state = GAMEOVER;
	}
	wnoutrefresh(_wn);
	doupdate();
	refresh();
	// clock_t	frame_end = clock();
	// double frame_time = static_cast<double>(frame_end - frame_start) / CLOCKS_PER_SEC;
	// double sleep_time = (1.0 / TARGET_FPS) - frame_time;
	end = std::chrono::high_resolution_clock::now();
	double sleep_time = (1.0 / TARGET_FPS) - std::chrono::duration<double>(frame_start - end).count();
	flushinp();
	if (sleep_time > 0)
	 	std::this_thread::sleep_for(std::chrono::duration<double>(sleep_time));
}

void Game::draw_infobox(int score, int life, int time)
{
    int left_pos = 2; // left alignment
    int middle_pos = (COLS - 6) / 2; // middle alignment
    int right_pos = COLS - 15;
	delwin(_infobox);
	_infobox = subwin(_wn, INFOBOX_H , COLS, LINES - INFOBOX_H, 0);
    wbkgd(_infobox, COLOR_PAIR(COLOR_MAGENTA)); // Set background color to white
    box(_infobox, ACS_VLINE, ACS_HLINE);
    mvwprintw(_infobox, INFOBOX_H / 2, left_pos, "SCORE: %d", score);
    mvwprintw(_infobox, INFOBOX_H / 2, middle_pos, "LIFE: %d", life);
    mvwprintw(_infobox, INFOBOX_H / 2, right_pos, "TIME: %d", time);
	wrefresh(_wn);
    wrefresh(_infobox);
}

void Game::drawGameOver(int score)
{
    int mid_pos = (COLS - 71) / 2 - DIS_LEFT;
    int middle_pos = (COLS - 4) / 2 - DIS_LEFT;
	int m_pos = (COLS - 19) / 2 - DIS_LEFT;
    WINDOW *gameover = subwin(_wn, LINES - 2 * DIS_UP, COLS - 2 * DIS_LEFT, DIS_UP, DIS_LEFT);
	wclear(_wn);
    wbkgd(gameover, COLOR_PAIR(11)); // Set background color to white
    box(gameover, ACS_VLINE, ACS_HLINE);
    mvwprintw(gameover, (LINES / 2) - 3 - (DIS_UP), mid_pos, " _______  _______  _______  _______   _______  ___ ___  _______  ______ ");
    mvwprintw(gameover, (LINES / 2) - 2 - (DIS_UP), mid_pos, "|     __||   _   ||   |   ||    ___| |       ||   |   ||    ___||   __ \\ ");
    mvwprintw(gameover, (LINES / 2) - 1 - (DIS_UP), mid_pos, "|    |  ||       ||       ||    ___| |   -   ||   |   ||    ___||      <");
    mvwprintw(gameover, (LINES / 2) - 0 - (DIS_UP), mid_pos, "|_______||___|___||__|_|__||_______| |_______| \\_____/ |_______||___|__|");
    mvwprintw(gameover, (LINES / 2) + 2 - (DIS_UP), middle_pos, "SCORE: %d ", score);
    wrefresh(gameover);
	std::this_thread::sleep_for(std::chrono::duration<double>(2.0));
	refresh();
	mvwprintw(gameover, (LINES / 2) + 2 - (DIS_UP), m_pos, "PRESS ANY KEY TO QUIT");
    // Refresh the infobox window to show the changes
	refresh();
	getch();
    delwin(gameover);
}

void Game::drawYouWin(int score)
{
    int mid_pos = (COLS - 56) / 2 - DIS_LEFT;
    int middle_pos = (COLS - 6) / 2 - DIS_LEFT;
	int m_pos = (COLS - 19) / 2 - DIS_LEFT;
    WINDOW *gameover = subwin(_wn, LINES - 2 * DIS_UP, COLS - 2 * DIS_LEFT, DIS_UP, DIS_LEFT);
	wclear(_wn);
    wbkgd(gameover, COLOR_PAIR(13)); // Set background color to white
    box(gameover, ACS_VLINE, ACS_HLINE);
	mvwprintw(gameover, (LINES / 2) - 3 - (DIS_UP), mid_pos, " ___ ___  _______  _______   ________  _______  _______ ");
    mvwprintw(gameover, (LINES / 2) - 2 - (DIS_UP), mid_pos, "|   |   ||       ||   |   | |  |  |  ||_     _||    |  |");
    mvwprintw(gameover, (LINES / 2) - 1 - (DIS_UP), mid_pos, " \\     / |   -   ||   |   | |  |  |  | _|   |_ |       |");
    mvwprintw(gameover, (LINES / 2) + 0 - (DIS_UP), mid_pos, "  |___|  |_______||_______| |________||_______||__|____|");
    mvwprintw(gameover, (LINES / 2) + 2 - (DIS_UP), middle_pos, "SCORE: %d ", score);
    wrefresh(gameover);
	std::this_thread::sleep_for(std::chrono::duration<double>(5.0));
	refresh();
	mvwprintw(gameover, (LINES / 2) + 2 - (DIS_UP), m_pos, "PRESS ANY KEY TO QUIT");
    // Refresh the infobox window to show the changes
	refresh();
	getch();
    delwin(gameover);
}