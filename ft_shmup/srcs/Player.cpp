#include "Player.hpp"
#include "Game.hpp"

Player::Player():Spaceship()
{
	_sprite = "🛸";
	_y = LINES / 2;
	_x = 10;
	_isdead = false;
}

Player::~Player()
{}

void	Player::shoot()
{
	if(!(_cooldown > 0.0))
	{
		_game->createBullet(_y, _x+1, BULLET_VELOCITY , PLAYER);
		_cooldown = COOLDOWN_MAX;
	}
}

void	Player::setHP(int n)
{
	_game->setLives(n);
	_hit_points = n;
	if (_hit_points <= 0)
		_isdead = true;
}


void	Player::update()
{
	Spaceship::update();
}

bool	Player::isDead() const
{
	return _isdead;
}

void	Player::setDead(bool d)
{
	_isdead = d;
}
