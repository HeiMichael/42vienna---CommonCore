#include "Object.hpp"

Object::Object():_x(0), _y(0), _speed(0.0)
{}

Object::~Object()
{}

void	Object::setX(float x)
{
	_x = x;
}

float Object::getX() const
{
	return (_x);
}

void	Object::setY(float y)
{
	_y = y;
}

float	Object::getY() const
{
	return (_y);
}

int	Object::getColor() const
{
	return (_color);
}

void	Object::setColor(int color)
{
	_color = color; 
}

float	Object::getSpeed() const
{
	return (_speed);
}

void	Object::setSpeed(float sp)
{
	_speed = sp; 
}

void	Object::setGame(Game* game)
{
	_game = game;
}

