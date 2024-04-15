#include "Spaceship.hpp"

Spaceship::Spaceship(): Object(), 
	_cooldown(0.0), 
	_cooldown_max(),
	_can_shoot(true), 
	_align(NOSIDE),
	_hit_points(MAX_PLAYER_LIFES)
{}

Spaceship::~Spaceship()
{}

Spaceship::Spaceship(const Spaceship& rhs)
{
	*this = rhs;
}

Spaceship& Spaceship::operator=(const Spaceship& rhs)
{
	if (this != &rhs)
	{
	
	}
	return (*this);
}

double	Spaceship::getCooldown() const
{
	return (_cooldown);
}

void	Spaceship::setCooldown(double cool)
{
	_cooldown = cool; 
}

double	Spaceship::getCooldownMax() const
{
	return (_cooldown_max);
}

void	Spaceship::setCooldownMax(double cool)
{
	_cooldown_max = cool; 
}


const char*	Spaceship::getSprite() const
{
	return (_sprite);
}

void	Spaceship::setSprite(const char* sp)
{
	_sprite = sp;
}

bool	Spaceship::canShoot() const
{
	return _can_shoot;
}

int		Spaceship::getHP() const
{
	return _hit_points;
}

void	Spaceship::setHP(int hp)
{
	_hit_points = hp; 
}

Side	Spaceship::getAlign() const
{
	return _align;
}

void	Spaceship::setAlign(Side s)
{
	_align = s;
}

void	Spaceship::update()
{
	_cooldown -= (1.0 / TARGET_FPS);
	if (_cooldown < 0.0)
		_cooldown = 0.0;
}

void	Spaceship::shoot()
{}

// bool	Spaceship::isColliding(int y, int x)
// {
// 	if (y == _y && x == _x)
// 		return true;
// 	else
// 		return false;
// } 

void	Spaceship::draw(WINDOW* w)
{
	wmove(w, _y, _x);
	// addch(_sprite);
	wprintw(w, "%s",_sprite);
	// mvprintw(0, 15, "%d %d", _x, _y);
	wrefresh(w);
}