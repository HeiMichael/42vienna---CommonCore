#include "Menu.hpp"

Menu::Menu():_choice(0),_start(NULL),_exit(NULL)
{}

Menu::~Menu()
{
	delwin(_start);
	delwin(_exit);
}

int	Menu::getChoice() const
{
	return (_choice);
}

void	Menu::render()
{
	_start = newwin(3, 19, (LINES - MENU_ITEM_HEIGTH)/2 , (COLS - MENU_ITEM_WIDTH)/2);
	wbkgd(_start, COLOR_PAIR(COLOR_WHITE));
	box(_start, ACS_VLINE, ACS_HLINE);
	wmove(_start, MENU_ITEM_HEIGTH / 2, (MENU_ITEM_WIDTH - 6) / 2);
	wprintw(_start, "START");
	wrefresh(_start);
	_exit = newwin(3, 19, (LINES - MENU_ITEM_HEIGTH)/2 + MENU_ITEM_DIST, (COLS - MENU_ITEM_WIDTH)/2);
	wbkgd(_exit, COLOR_PAIR(COLOR_BLUE));
	box(_exit, ACS_VLINE, ACS_HLINE);
	wmove(_exit, MENU_ITEM_HEIGTH / 2, (MENU_ITEM_WIDTH - 6) / 2);
	wprintw(_exit, "EXIT");
	_select[0] = _start;
	_select[1] = _exit;
	wrefresh(_exit);
}

int	Menu::getChoice()
{
	int hei = 15 ;
  	int mid_pos = (COLS - 54) / 2 - DIS_LEFT; 
	mvprintw(LINES/2 - hei, mid_pos, "  __  _                 _                              ");
    mvprintw(LINES/2 - hei + 1, mid_pos, " / _|| |               | |                             ");
    mvprintw(LINES/2 - hei + 2, mid_pos, "| |_ | |_          ___ | |__   _ __ ___   _   _  _ __  ");
    mvprintw(LINES/2 - hei + 3, mid_pos, "|  _|| __|        / __|| '_ \\ | '_ ` _ \\ | | | || '_ \\ ");
    mvprintw(LINES/2 - hei + 4, mid_pos, "| |  | |_         \\__ \\| | | || | | | | || |_| || |_) |");
    mvprintw(LINES/2 - hei + 5, mid_pos, "|_|   \\__|        |___/|_| |_||_| |_| |_| \\__,_|| .__/ ");
    mvprintw(LINES/2 - hei + 6, mid_pos, "           ______                               | |    ");
    mvprintw(LINES/2 - hei + 7, mid_pos, "          |______|                              |_|    ");
	while (true)
	{
		int c = getch();
		if (c == KEY_DOWN)
		{
			wbkgd(_select[_choice], COLOR_PAIR(DESELECT_COLOR));
			wrefresh(_select[_choice]);
			_choice = (_choice + 1) % 2;
			wbkgd(_select[_choice], COLOR_PAIR(SELECT_COLOR));
			wrefresh(_select[_choice]);
		}	
		else if (c == KEY_UP)
		{
			wbkgd(_select[_choice], COLOR_PAIR(DESELECT_COLOR));
			wrefresh(_select[_choice]);
			if (_choice == 0)
				_choice = 1;
			else
				_choice -= 1;
			wbkgd(_select[_choice], COLOR_PAIR(SELECT_COLOR));
			wrefresh(_select[_choice]);
		}
		else if (c == 10)
			return _choice;
		else if (c == 27 || c == 410)
			return -1;
	}

}

