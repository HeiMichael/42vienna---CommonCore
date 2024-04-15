
#include "Game.hpp"
#include "Menu.hpp"
#include "shmup.hpp"
#include <chrono>
#include <signal.h>

static void handle_resize(int sig)
{
	(void)sig;
	endwin();
	std::cout << "Don't resize the window" << std::endl;
	exit(1);
}

static int	initGame()
{
	signal(SIGWINCH, handle_resize);
	std::srand(std::time(0));
	setlocale(LC_ALL, "");
	initscr();
	if (has_colors())
		start_color();
	else
	{
		std::cerr << "Error. Unfortunately your terminal can't handle colors" << std::endl;
		std::cerr << "Exiting" << std::endl;
		return -1;
	}
	init_pair(COLOR_BLACK, COLOR_BLACK, COLOR_BLACK);
	init_pair(COLOR_GREEN, COLOR_GREEN, COLOR_BLACK);
	init_pair(COLOR_RED, COLOR_RED, COLOR_BLACK);
	init_pair(COLOR_CYAN, COLOR_CYAN, COLOR_BLACK);
	init_pair(COLOR_WHITE, COLOR_WHITE, COLOR_BLACK);
	init_pair(COLOR_MAGENTA, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(COLOR_BLUE, COLOR_BLUE, COLOR_BLACK);
	init_pair(COLOR_YELLOW, COLOR_YELLOW, COLOR_BLACK);
    init_pair(11, COLOR_WHITE, COLOR_RED);
    init_pair(12, COLOR_RED, COLOR_RED);
    init_pair(13, COLOR_WHITE, COLOR_GREEN);
	keypad(stdscr, TRUE);
	nodelay(stdscr, TRUE);
	curs_set(0);
	noecho();
	return 0;
}

static void	renderMenu(Menu *menu)
{
	menu->render();
}

static void	updateGame(Game *game, GameState& state )
{
	game->update(state);
}

static void	renderGame()
{
}

static void	renderGameOver()
{

}



static void	handleInput(Game *game, GameState& state, Menu& menu)
{
	int c;

	c = getch();
	if (state == PLAYING)
	{
		game->handle_input(c, state);	
	}
	else if (state == MENU)
	{
		if (menu.getChoice() == 0)
		{
			state = PLAYING;
			touchwin(stdscr);
			game->time = std::chrono::high_resolution_clock::now();
		}
		else
			state = EXIT;
	}
	else if (state == GAMEOVER)
	{
		switch (c)
		{
			case KEY_DOWN:
				break;
			case KEY_UP:
				break;
			case 32: //SPACE
				break;
			default:
				;
		}
	}
}



int main()
{
	initGame();
	Menu menu;
	Game game;
	game.init();
	GameState state = MENU;
	//game loop
	while (true)
	{
		switch (state)
		{
			case MENU:
				renderMenu(&menu);
				handleInput(&game, state, menu);
				break;
			case PLAYING:
				updateGame(&game, state);
				renderGame();
				handleInput(&game, state, menu);
				break;
			case GAMEOVER:
				renderGameOver();
				getch();
				state = EXIT;
				break;
			case EXIT:
				break;
		}
		if (state == EXIT)
			break;
	}
	endwin();
	return 0;
}