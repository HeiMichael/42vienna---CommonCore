#include "Boss.hpp"
#include "Game.hpp"

Boss::Boss()
{
	lives = BOSSLIVES;
	_cooldown_max = 0.5;
	_cooldown = 0.0;
	_isAlive = true;
}

Boss::Boss(const std::string& path)
{
	_sprite = load_ascii_art(path);
	lives = BOSSLIVES;
	_cooldown_max = 0.3;
	_cooldown = 0.0;
	_isAlive = true;
}

Boss::~Boss()
{

}

bool Boss::collides(int y, int x)
{
    if (x >= _x && y >= _y && y <= _y + _num_lines && _sprite[int(y - _y)][int(x - _x)] == 'u')
        return (true);
	else
        return (false);
}

void Boss::update()
{
	_cooldown -= (1.0 / TARGET_FPS);
	if (_cooldown < 0.0)
		_cooldown = 0.0;
}

void Boss::updater(double time)
{
		_y += 3.124 * sin(time * 2);
		if (_y < 0)
			_y = LINES - 1 - INFOBOX_H;
		if (_y > LINES - 1 - INFOBOX_H)
			_y = 0;	
}

char **Boss::load_ascii_art(const std::string& path)
{
	std::ifstream file(path);
	if (!file.is_open())
	{
		std::cerr << "Error: Unable to open file " << path << std::endl;
		return NULL;
	}
	file.seekg(0, std::ios::end);
	size_t file_size = file.tellg();
	file.seekg(0, std::ios::beg);

	std::vector<char> buffer(file_size + 1);
	file.read(buffer.data(), file_size);
	if (!file)
	{
		std::cerr << "Error: Unable to read file contents." << std::endl;
		file.close();
		return nullptr;
	}
	buffer[file_size] = '\0';
	file.close();
	std::vector<char *> lines;
	char *line = strtok(buffer.data(), "\n");
	while (line != NULL)
	{
		lines.push_back(strdup(line));
		line = strtok(NULL, "\n");
	}

	char **res = new char *[lines.size()];
	for (size_t i = 0; i < lines.size(); ++i)
	{
		res[i] = lines[i];
	}
	_num_lines = lines.size();
	return res;
}

void	Boss::draw(WINDOW* w)
{
	if (_isAlive)
	{
		attron(COLOR_PAIR(COLOR_YELLOW));
		for (int j = 0; j < _num_lines; j++)
		{
			int i = 0;
			while(_sprite[j][i])	
			{
				if (_sprite[j][i] != 'u')
				{
					wattron(w, COLOR_PAIR(COLOR_YELLOW));
					mvwprintw(w, _y + j, _x + i, "%c", _sprite[j][i]);
					// wrefresh(w);
					wattroff(w, COLOR_PAIR(COLOR_YELLOW));
					// mvwprintw(w, _y + j, _x + i, "%c", _sprite[j][i]);
					// wrefresh(w);
				}
				i++;
			}
		}
		attroff(COLOR_PAIR(COLOR_YELLOW));
	}
}

void	Boss::shoot()
{
	if(!(_cooldown > 0.0))
	{
		_game->createBullet(_y + 2, _x-1, -BULLET_VELOCITY , ENEMY);
		_game->createBullet(_y + 3, _x-1, -BULLET_VELOCITY, ENEMY);
		_game->createBullet(_y + 4, _x-1, -BULLET_VELOCITY , ENEMY);
		_game->createBullet(_y + 5, _x-1, -BULLET_VELOCITY , ENEMY);
		_game->createBullet(_y + 7, _x-1, -BULLET_VELOCITY , ENEMY);
		_game->createBullet(_y + 8, _x-1, -BULLET_VELOCITY, ENEMY);
		_game->createBullet(_y + 9, _x-1, -BULLET_VELOCITY, ENEMY);
		_game->createBullet(_y + 10, _x-1, -BULLET_VELOCITY, ENEMY);
		_game->createBullet(_y + 11, _x-1, -BULLET_VELOCITY, ENEMY);	
		_game->createBullet(_y + 12, _x-1, -BULLET_VELOCITY, ENEMY);	
		_game->createBullet(_y + 13, _x-1, -BULLET_VELOCITY, ENEMY);
		_game->createBullet(_y + 14, _x-1, -BULLET_VELOCITY, ENEMY);	
		_game->createBullet(_y + 15, _x-1, -BULLET_VELOCITY, ENEMY);	
		_cooldown = _cooldown_max;
	}
	
}