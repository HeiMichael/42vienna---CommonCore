#ifndef GAME_HPP
#define GAME_HPP

#include "shmup.hpp"
#include "Backscroll.hpp"
#include "Spaceship.hpp"
#include "Enemy.hpp"
#include "Bullet.hpp"
#include "Player.hpp"
#include "Boss.hpp"
#include <chrono>

#define KEY_ESC 27
#define KEY_SPC 32

class Game
{
	public:
									Game();
									~Game();
		void						update(GameState& state);
		void						init();
		
		void						setMaxY(int y);
		int							getMaxY() const;
		void						setMaxX(int x);
		int							getMaxX() const;
		void						setScore(int score);
		int							getScore() const;
		void						setLives(int lvs);
		int							getLives() const;
		void						setPlayer(Player* pl);
		Player*						getPlayer() const;
		void						setEnemyCreationWaitime(double wt);
		double						getEnemyCreationWaitime() const;
		void						handle_input(int c, GameState& state);
		void						createBullet(int y, int x, float speed, Side al);
		void						createEneny();
		void						eraseBullet(Bullet*);
		void						eraseEnemy(Enemy*);
		void						createEnemies();
		void						cleanBullets();
		void						cleanEnemies();
		void 						draw_infobox(int score, int life, int time);
		void						drawGameOver(int score);
		void						drawYouWin(int score);
		std::chrono::high_resolution_clock::time_point	time;

	private:
		WINDOW*						_wn;
		WINDOW*						_infobox;						
		Player*						_player;
		Boss*						_boss;
		std::vector<Enemy*>			_enemies;
		std::vector<Bullet*>		_bullets;
		Backscroll*					_bg;
		Backscroll*					_bg_up;
		Backscroll*					_bg_stars;
		void						_checkCollisions();
		double						_enemy_creation_waitime;
		double						_enemy_creation_cooldown;
		int 						_max_y;
		int 						_max_x;
		int 						_score;
		int 						_lives;
};

#endif