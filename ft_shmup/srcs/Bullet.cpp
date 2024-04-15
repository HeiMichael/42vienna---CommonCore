#include "Bullet.hpp"

Bullet::Bullet()
{
	_sprite = "🍉";
	_destroyed = false;
	_speed = 30;
}

Bullet::~Bullet()
{

}

void	Bullet::draw(WINDOW* w)
{
	wattron(w, COLOR_PAIR(COLOR_YELLOW));
	wmove(w, _y, _x);
	//addch(_sprite);
	wprintw(w, "%s",_sprite);
	wattroff(w, COLOR_PAIR(COLOR_YELLOW));
	wrefresh(w);
}

void	Bullet::setAlign(Side s)
{
	_align = s;
	if (s == ENEMY)
		_sprite = "—";
}

Side	Bullet::getAlign() const
{
	return _align;
}

bool	Bullet::getDestroyed() const
{
	return _destroyed;
}

void	Bullet::update()
{
	_x += _speed * (1.0 / (float)TARGET_FPS);
}
