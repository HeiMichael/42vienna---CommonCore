#ifndef MENU_HPP
#define MENU_HPP

#include "shmup.hpp"

#define MENU_ITEM_WIDTH 21
#define MENU_ITEM_HEIGTH 3
#define MENU_ITEM_DIST 3

#define SELECT_COLOR COLOR_WHITE
#define DESELECT_COLOR COLOR_BLUE

class Menu
{
	public:
				Menu();
				~Menu();
		int		getChoice() const;
		int		getA() const;
		void	render();
		int 	getChoice();

	private:
		int		_choice;
		WINDOW	*_select[2];
		WINDOW	*_start;
		WINDOW	*_exit;
};

#endif

