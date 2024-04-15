#include "Backscroll.hpp"

Backscroll::Backscroll():place(1), _image(nullptr), _num_lines(0), _shift(0), _colpsec(SCROLL_SPEED)
{}

Backscroll::Backscroll(const std::string& path)
{
	place = 1;
	_image = load_ascii_art(path);
	_shift = 0;
	_colpsec = SCROLL_SPEED;
	halfWidth = 200;
}

Backscroll::~Backscroll()
{
	if (_image && _num_lines != 0)
	{
		for (size_t i = 0; i < _num_lines; i++)
			free(_image[i]);
		delete[] _image;
		_image = nullptr;
	}
}

int	Backscroll::getShift() const
{
	return (_shift);
}

int	Backscroll::getColpsec() const
{
	return (_colpsec);
}

void	Backscroll::setColpsec(int s) 
{
	_colpsec = s;
}

void Backscroll::update(WINDOW* w)
{
	int i = 0;
	_shift++;
	wbkgd(w, COLOR_PAIR(COLOR_BLUE));
	if (_shift == _colpsec * halfWidth) 
		_shift = 0;
	char formatString[20];
	snprintf(formatString, sizeof(formatString), "%%.%ds", COLS);
	while (i < (int)_num_lines && (i < LINES - 1 - INFOBOX_H))
	{
		if (place == 0)
			wmove(w, i, 0);
		else
			wmove(w, (LINES - _num_lines - INFOBOX_H) + i, 0);
		wprintw(w,formatString, &(_image[i][_shift/_colpsec]));
		// printw("%.80s", &(_image[i][_shift / _colpsec]));
		i++;
	}	
	// wrefresh(w);
}

char **Backscroll::load_ascii_art(const std::string& path)
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
