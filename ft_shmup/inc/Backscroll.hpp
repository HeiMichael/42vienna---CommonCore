#ifndef BACKSCROLL_HPP
#define BACKSCROLL_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <string>
#include "shmup.hpp"

#define SCROLL_SPEED 10 

class Backscroll
{
	public:
				Backscroll();
				Backscroll(const std::string& path);
				~Backscroll();
		int		getShift() const;
		int		getColpsec() const;
		void	setColpsec(int);
		void	update(WINDOW *w);
		char**	load_ascii_art(const std::string& path);
		int		place;	
		int		halfWidth;

	private:
		char**	_image;
		size_t	_num_lines;
		int		_shift;
		int		_colpsec;
};

#endif

