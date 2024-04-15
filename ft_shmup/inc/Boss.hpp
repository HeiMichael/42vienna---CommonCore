#ifndef BOSS_HPP
#define BOSS_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <string>
#include "Object.hpp"
#include "shmup.hpp"

class Boss : public Object
{
	public:
						Boss();
						Boss(const std::string& path);
						~Boss();	
		bool			collides(int y, int x);
		char**			load_ascii_art(const std::string& path);
		void			draw(WINDOW* ) override;
		void			updater(double time);
		void			update() override;
		void			shoot();
		int				lives;
		bool			_isAlive;

	private:
		char**			_sprite;
		int 			_num_lines;
		double			_cooldown;
		double			_cooldown_max;

};

#endif