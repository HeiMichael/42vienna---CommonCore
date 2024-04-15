#include "Enemy.hpp"
#include "Game.hpp"

Enemy::Enemy():_type(PHANTOM)
{
	_sprite =  "👾";
	_align = ENEMY;
	_cooldown = 0.0;
	switch(_type)
	{
		case PHANTOM:
			_hit_points = 1;
			_speed = 5 * PHANTOM_SPEED;
			_cooldown_max = 4;
		case LURKER:
			_hit_points = 1;
			_speed = 2 * PHANTOM_SPEED;
			_cooldown_max = 5;
		case BEE:
			_hit_points = 1;
			_speed = 1.2 * PHANTOM_SPEED;
			_cooldown_max = 3;
		case OKTO:
			_hit_points = 1;
			_speed = 1.2 * PHANTOM_SPEED;
			_cooldown_max = 3;
	}
}

Enemy::~Enemy()
{}

EnemyType	Enemy::getType() const
{
	return _type;
}

void		Enemy::setType(EnemyType tp)
{
	_type = tp;
	switch(tp)
	{
		case PHANTOM:
			_sprite =  "👾";
			break;
		case LURKER:
			_sprite =  "💀";
			break;
		case OKTO:
			_sprite =  "🐙";
			break;
		case BEE:
			_sprite =  "🥶";
			break;
		default:
			_sprite =  "👾";
	}
	offset = (rand() % 3000) / 1000.0;
}

void		Enemy::updater(double time)
{
	Spaceship::update();
	_x += _speed * (1.0 / (float)TARGET_FPS);
	if (_type == LURKER)
	{
		_y += 0.014 * sin(time + offset);
		if (_y < 0)
			_y = LINES - 1 - INFOBOX_H;
		if (_y > LINES - 1 - INFOBOX_H)
			_y = 0;
	}
	else if (_type == BEE)
	{
		_y += 0.02;
		if (_y < 0)
			_y = LINES - 1 - INFOBOX_H;
		if (_y > LINES - 1 - INFOBOX_H)
			_y = 0;
	}
	else if (_type == OKTO)
	{
		_y -= 0.02;
		if (_y < 0)
			_y = LINES - 1 - INFOBOX_H;
		if (_y > LINES - 1 - INFOBOX_H)
			_y = 0;
	}
	else
		_x += _speed * (1.0 / (float)TARGET_FPS);
}

void	Enemy::shoot()
{
	if(!(_cooldown > 0.0))
	{
		_game->createBullet(_y, _x-1, -BULLET_VELOCITY , ENEMY);
		_cooldown = _cooldown_max;
	}
}